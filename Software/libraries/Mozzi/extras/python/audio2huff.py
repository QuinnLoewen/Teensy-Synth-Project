#! /usr/bin/python
#
# Generator for compressed Arduino audio data
# Thomas Grill, 2011
# http://grrrr.org
#
# Modified by TIm Barrass 2013
# - changed PROGMEM to CONSTTABLE_STORAGE, to stop compiler warning
# - moved huffman table to progmem
# - added --name argument to give all constants specific names
# - changed all constant names to upper case
# - added include guards, Arduino and avr includes
#
# Dependencies:
# Numerical Python (numpy): http://numpy.scipy.org/
# scikits.audiolab: http://pypi.python.org/pypi/scikits.audiolab/
# purehuff: https://grrrr.org/data/dev/purehuff/
# pylab / matplotlib (only for plotting): http://matplotlib.sourceforge.net/
#
# NOTE: the scikits.audiolab dependency requires Python 2!
#       see https://github.com/Roger-random/mozzi_wilhelm/issues/1#issuecomment-770141226
# 
#For help on options invoke with:
# audio2huff --help

import sys,os.path
from itertools import imap,chain,izip

try:
    import numpy as N
except ImportError:
    print >>sys.stderr, "Error: Numerical Python not found"
    exit(-1)

try:
    from scikits.audiolab import Sndfile
except ImportError:
    print >>sys.stderr, "Error: scikits.audiolab not found"
    exit(-1)

try:
    import purehuff
except ImportError:
    print >>sys.stderr, "Error: purehuff module not found"
    exit(-1)

def grouper(n,seq):
    """group list elements"""
    it = iter(seq)
    while True:
        l = [v for _,v in izip(xrange(n),it)]
        if l:
            yield l
        if len(l) < n:
            break

def arrayformatter(seq,perline=40):
    """format list output linewise"""
    return ",\n".join(",".join(imap(str,s)) for s in grouper(perline,seq))

if __name__ == "__main__":
    from optparse import OptionParser
    parser = OptionParser()
    parser.add_option("--bits", type="int", default=8, dest="bits",help="bit resolution")
    parser.add_option("--sndfile", dest="sndfile",help="input sound file")
    parser.add_option("--hdrfile", dest="hdrfile",help="output C header file")
    parser.add_option("--name", dest="name",help="prefix for tables and constants in file")
    parser.add_option("--plothist", type="int", default=0, dest="plothist",help="plot histogram")
    (options, args) = parser.parse_args()

    if not options.sndfile:
        print >>sys.stderr,"Error: --sndfile argument required"
        exit(-1)

    sndf = Sndfile(options.sndfile,'r')
    sound = sndf.read_frames(sndf.nframes)
    fs = sndf.samplerate
    del sndf

    # mix down multi-channel audio
    if len(sound.shape) > 1:
        sound = N.mean(sound,axis=1)

    # convert to n bits (no dithering, except it has already been done with the same bit resolution for the soundfile)
    sound8 = N.clip((sound*(2**(options.bits-1))).astype(int),-2**(options.bits-1),2**(options.bits-1)-1)
    # the following mapping with int is necessary as numpy.int32 types are not digested well by the HuffmanTree class
    dsound8 = map(int,chain((sound8[0],),imap(lambda x: x[1]-x[0],izip(sound8[:-1],sound8[1:]))))

    print >>sys.stderr,"min/max: %i/%i"%(N.min(sound8),N.max(sound8))
    print >>sys.stderr,"data bits: %i"%(len(sound8)*options.bits)

    hist = purehuff.histogram(dsound8)

    if options.plothist:
        try:
            import pylab as P
        except ImportError:
            print >>sys.stderr, "Plotting needs pylab"

        from collections import defaultdict
        d = defaultdict(float)
        for n,v in hist:
            d[v] += n
        x = range(min(d.iterkeys()),max(d.iterkeys())+1)
        y = [d[xi] for xi in x]

        P.title("Histogram of sample differentials, file %s"%os.path.split(options.sndfile)[-1])
        P.plot(x,y,marker='x')
        P.show()

    hufftree = purehuff.HuffTree(hist)

    # get decoder instance
    decoder = hufftree.decoder()
    # get encoder instance
    encoder = hufftree.encoder()
    # encode data
    enc = encoder(dsound8)

    print >>sys.stderr,"encoded bits: %i"%len(enc)
    print >>sys.stderr,"ratio: %.0f%%"%((len(enc)*100.)/(len(sound8)*8))
    print >>sys.stderr,"decoder length: %.0f words"%(len(decoder.huff))

    if options.hdrfile:
        hdrf = file(options.hdrfile,'wt')
        print >>hdrf,"// generated by Mozzi/extras/python/audio2huff.py \n"
        print >>hdrf,"#ifndef " + options.name + "_H_"
        print >>hdrf,"#define " + options.name + "_H_\n"
        print >>hdrf,'#if ARDUINO >= 100'
        print >>hdrf,'#include <Arduino.h>\n'
        print >>hdrf,'#include "mozzi_pgmspace.h"\n \n'
        print >>hdrf,"#define " + options.name + "_SAMPLERATE %i"%fs
        print >>hdrf,"#define " + options.name + "_SAMPLE_BITS %i"%options.bits
        print >>hdrf,'CONSTTABLE_STORAGE(int) ' + options.name + '_HUFFMAN[%i] = {\n%s\n};'%(len(decoder.huff),arrayformatter(decoder.huff))
        print >>hdrf,'unsigned long const ' + options.name + '_SOUNDDATA_BITS = %iL;'%len(enc)
        print >>hdrf,'CONSTTABLE_STORAGE(unsigned char) ' + options.name + '_SOUNDDATA[] = {\n%s\n};'%arrayformatter(enc.data)
        print >>hdrf,"#endif /* " + options.name + "_H_ */"

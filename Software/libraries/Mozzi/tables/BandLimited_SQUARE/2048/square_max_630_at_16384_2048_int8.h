#ifndef SQUARE_MAX_630_AT_16384_2048INT8_H_
#define SQUARE_MAX_630_AT_16384_2048INT8_H_

#include <Arduino.h>
#include "mozzi_pgmspace.h"


#define SQUARE_MAX_630_AT_16384_2048_NUM_CELLS 2048
#define SQUARE_MAX_630_AT_16384_2048_SAMPLERATE 2048

CONSTTABLE_STORAGE(int8_t) SQUARE_MAX_630_AT_16384_2048_DATA [] = 
{
0, 2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 34, 37, 40, 43, 46, 48, 51, 54, 56, 59, 61, 64, 66, 69, 71, 74, 76, 78, 80, 83, 85, 
87, 89, 91, 93, 95, 96, 98, 100, 102, 103, 105, 106, 108, 109, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 122, 123, 124, 124, 125, 125, 
126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 126, 126, 126, 126, 125, 125, 124, 124, 124, 123, 123, 122, 122, 121, 121, 120, 119, 119, 
118, 118, 117, 116, 116, 115, 114, 114, 113, 112, 112, 111, 110, 110, 109, 109, 108, 107, 107, 106, 106, 105, 104, 104, 103, 103, 102, 102, 101, 101, 101, 100, 
100, 99, 99, 99, 99, 98, 98, 98, 98, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 98, 98, 98, 98, 98, 
99, 99, 99, 100, 100, 100, 100, 101, 101, 102, 102, 102, 103, 103, 103, 104, 104, 105, 105, 105, 106, 106, 107, 107, 107, 108, 108, 109, 109, 109, 110, 110, 
110, 111, 111, 111, 112, 112, 112, 112, 113, 113, 113, 113, 114, 114, 114, 114, 114, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 
115, 115, 115, 115, 115, 114, 114, 114, 114, 114, 114, 113, 113, 113, 113, 112, 112, 112, 112, 111, 111, 111, 111, 110, 110, 110, 109, 109, 109, 109, 108, 108, 
108, 107, 107, 107, 106, 106, 106, 106, 105, 105, 105, 105, 104, 104, 104, 104, 103, 103, 103, 103, 103, 102, 102, 102, 102, 102, 102, 102, 102, 102, 101, 101, 
101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 102, 102, 102, 102, 102, 102, 102, 102, 102, 103, 103, 103, 103, 103, 103, 104, 104, 104, 104, 105, 105, 105, 
105, 105, 106, 106, 106, 106, 107, 107, 107, 107, 108, 108, 108, 108, 109, 109, 109, 109, 110, 110, 110, 110, 110, 111, 111, 111, 111, 111, 112, 112, 112, 112, 
112, 112, 112, 112, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 112, 112, 112, 112, 112, 112, 112, 112, 111, 111, 
111, 111, 111, 111, 110, 110, 110, 110, 110, 109, 109, 109, 109, 109, 108, 108, 108, 108, 107, 107, 107, 107, 107, 106, 106, 106, 106, 106, 105, 105, 105, 105, 
105, 104, 104, 104, 104, 104, 104, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 102, 102, 102, 102, 103, 103, 103, 103, 103, 103, 103, 103, 
103, 103, 103, 103, 103, 104, 104, 104, 104, 104, 104, 104, 105, 105, 105, 105, 105, 105, 106, 106, 106, 106, 107, 107, 107, 107, 107, 108, 108, 108, 108, 108, 
109, 109, 109, 109, 109, 110, 110, 110, 110, 110, 111, 111, 111, 111, 111, 111, 111, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 
112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 111, 111, 111, 111, 111, 111, 111, 110, 110, 110, 110, 110, 109, 109, 109, 109, 109, 108, 
108, 108, 108, 108, 107, 107, 107, 107, 107, 106, 106, 106, 106, 105, 105, 105, 105, 105, 105, 104, 104, 104, 104, 104, 104, 104, 103, 103, 103, 103, 103, 103, 
103, 103, 103, 103, 103, 103, 103, 102, 102, 102, 102, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 104, 104, 104, 104, 104, 104, 105, 105, 
105, 105, 105, 106, 106, 106, 106, 106, 107, 107, 107, 107, 107, 108, 108, 108, 108, 109, 109, 109, 109, 109, 110, 110, 110, 110, 110, 111, 111, 111, 111, 111, 
111, 112, 112, 112, 112, 112, 112, 112, 112, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 112, 112, 112, 112, 112, 
112, 112, 112, 111, 111, 111, 111, 111, 110, 110, 110, 110, 110, 109, 109, 109, 109, 108, 108, 108, 108, 107, 107, 107, 107, 106, 106, 106, 106, 105, 105, 105, 
105, 105, 104, 104, 104, 104, 103, 103, 103, 103, 103, 103, 102, 102, 102, 102, 102, 102, 102, 102, 102, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 
101, 102, 102, 102, 102, 102, 102, 102, 102, 102, 103, 103, 103, 103, 103, 104, 104, 104, 104, 105, 105, 105, 105, 106, 106, 106, 106, 107, 107, 107, 108, 108, 
108, 109, 109, 109, 109, 110, 110, 110, 111, 111, 111, 111, 112, 112, 112, 112, 113, 113, 113, 113, 114, 114, 114, 114, 114, 114, 115, 115, 115, 115, 115, 115, 
115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 114, 114, 114, 114, 114, 113, 113, 113, 113, 112, 112, 112, 112, 111, 111, 111, 110, 110, 
110, 109, 109, 109, 108, 108, 107, 107, 107, 106, 106, 105, 105, 105, 104, 104, 103, 103, 103, 102, 102, 102, 101, 101, 100, 100, 100, 100, 99, 99, 99, 98, 
98, 98, 98, 98, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 98, 98, 98, 98, 99, 99, 99, 99, 100, 100, 
101, 101, 101, 102, 102, 103, 103, 104, 104, 105, 106, 106, 107, 107, 108, 109, 109, 110, 110, 111, 112, 112, 113, 114, 114, 115, 116, 116, 117, 118, 118, 119, 
119, 120, 121, 121, 122, 122, 123, 123, 124, 124, 124, 125, 125, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 126, 126, 126, 126, 125, 
125, 124, 124, 123, 122, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 109, 108, 106, 105, 103, 102, 100, 98, 96, 95, 93, 91, 89, 87, 85, 
83, 80, 78, 76, 74, 71, 69, 66, 64, 61, 59, 56, 54, 51, 48, 46, 43, 40, 37, 34, 32, 29, 26, 23, 20, 17, 14, 11, 8, 5, 2, 0, 
-2, -5, -8, -11, -14, -17, -20, -23, -26, -29, -32, -34, -37, -40, -43, -46, -48, -51, -54, -56, -59, -61, -64, -66, -69, -71, -74, -76, -78, -80, -83, -85, 
-87, -89, -91, -93, -95, -96, -98, -100, -102, -103, -105, -106, -108, -109, -111, -112, -113, -114, -115, -116, -117, -118, -119, -120, -121, -122, -122, -123, -124, -124, -125, -125, 
-126, -126, -126, -126, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -125, -125, -124, -124, -124, -123, -123, -122, -122, -121, -121, -120, -119, -119, 
-118, -118, -117, -116, -116, -115, -114, -114, -113, -112, -112, -111, -110, -110, -109, -109, -108, -107, -107, -106, -106, -105, -104, -104, -103, -103, -102, -102, -101, -101, -101, -100, 
-100, -99, -99, -99, -99, -98, -98, -98, -98, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -98, -98, -98, -98, -98, 
-99, -99, -99, -100, -100, -100, -100, -101, -101, -102, -102, -102, -103, -103, -103, -104, -104, -105, -105, -105, -106, -106, -107, -107, -107, -108, -108, -109, -109, -109, -110, -110, 
-110, -111, -111, -111, -112, -112, -112, -112, -113, -113, -113, -113, -114, -114, -114, -114, -114, -115, -115, -115, -115, -115, -115, -115, -115, -115, -115, -115, -115, -115, -115, -115, 
-115, -115, -115, -115, -115, -114, -114, -114, -114, -114, -114, -113, -113, -113, -113, -112, -112, -112, -112, -111, -111, -111, -111, -110, -110, -110, -109, -109, -109, -109, -108, -108, 
-108, -107, -107, -107, -106, -106, -106, -106, -105, -105, -105, -105, -104, -104, -104, -104, -103, -103, -103, -103, -103, -102, -102, -102, -102, -102, -102, -102, -102, -102, -101, -101, 
-101, -101, -101, -101, -101, -101, -101, -101, -101, -101, -102, -102, -102, -102, -102, -102, -102, -102, -102, -103, -103, -103, -103, -103, -103, -104, -104, -104, -104, -105, -105, -105, 
-105, -105, -106, -106, -106, -106, -107, -107, -107, -107, -108, -108, -108, -108, -109, -109, -109, -109, -110, -110, -110, -110, -110, -111, -111, -111, -111, -111, -112, -112, -112, -112, 
-112, -112, -112, -112, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -112, -112, -112, -112, -112, -112, -112, -112, -111, -111, 
-111, -111, -111, -111, -110, -110, -110, -110, -110, -109, -109, -109, -109, -109, -108, -108, -108, -108, -107, -107, -107, -107, -107, -106, -106, -106, -106, -106, -105, -105, -105, -105, 
-105, -104, -104, -104, -104, -104, -104, -103, -103, -103, -103, -103, -103, -103, -103, -103, -103, -103, -103, -103, -102, -102, -102, -102, -103, -103, -103, -103, -103, -103, -103, -103, 
-103, -103, -103, -103, -103, -104, -104, -104, -104, -104, -104, -104, -105, -105, -105, -105, -105, -105, -106, -106, -106, -106, -107, -107, -107, -107, -107, -108, -108, -108, -108, -108, 
-109, -109, -109, -109, -109, -110, -110, -110, -110, -110, -111, -111, -111, -111, -111, -111, -111, -112, -112, -112, -112, -112, -112, -112, -112, -112, -112, -112, -112, -112, -112, -112, 
-112, -112, -112, -112, -112, -112, -112, -112, -112, -112, -112, -112, -112, -112, -111, -111, -111, -111, -111, -111, -111, -110, -110, -110, -110, -110, -109, -109, -109, -109, -109, -108, 
-108, -108, -108, -108, -107, -107, -107, -107, -107, -106, -106, -106, -106, -105, -105, -105, -105, -105, -105, -104, -104, -104, -104, -104, -104, -104, -103, -103, -103, -103, -103, -103, 
-103, -103, -103, -103, -103, -103, -103, -102, -102, -102, -102, -103, -103, -103, -103, -103, -103, -103, -103, -103, -103, -103, -103, -103, -104, -104, -104, -104, -104, -104, -105, -105, 
-105, -105, -105, -106, -106, -106, -106, -106, -107, -107, -107, -107, -107, -108, -108, -108, -108, -109, -109, -109, -109, -109, -110, -110, -110, -110, -110, -111, -111, -111, -111, -111, 
-111, -112, -112, -112, -112, -112, -112, -112, -112, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -113, -112, -112, -112, -112, -112, 
-112, -112, -112, -111, -111, -111, -111, -111, -110, -110, -110, -110, -110, -109, -109, -109, -109, -108, -108, -108, -108, -107, -107, -107, -107, -106, -106, -106, -106, -105, -105, -105, 
-105, -105, -104, -104, -104, -104, -103, -103, -103, -103, -103, -103, -102, -102, -102, -102, -102, -102, -102, -102, -102, -101, -101, -101, -101, -101, -101, -101, -101, -101, -101, -101, 
-101, -102, -102, -102, -102, -102, -102, -102, -102, -102, -103, -103, -103, -103, -103, -104, -104, -104, -104, -105, -105, -105, -105, -106, -106, -106, -106, -107, -107, -107, -108, -108, 
-108, -109, -109, -109, -109, -110, -110, -110, -111, -111, -111, -111, -112, -112, -112, -112, -113, -113, -113, -113, -114, -114, -114, -114, -114, -114, -115, -115, -115, -115, -115, -115, 
-115, -115, -115, -115, -115, -115, -115, -115, -115, -115, -115, -115, -115, -115, -114, -114, -114, -114, -114, -113, -113, -113, -113, -112, -112, -112, -112, -111, -111, -111, -110, -110, 
-110, -109, -109, -109, -108, -108, -107, -107, -107, -106, -106, -105, -105, -105, -104, -104, -103, -103, -103, -102, -102, -102, -101, -101, -100, -100, -100, -100, -99, -99, -99, -98, 
-98, -98, -98, -98, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -97, -98, -98, -98, -98, -99, -99, -99, -99, -100, -100, 
-101, -101, -101, -102, -102, -103, -103, -104, -104, -105, -106, -106, -107, -107, -108, -109, -109, -110, -110, -111, -112, -112, -113, -114, -114, -115, -116, -116, -117, -118, -118, -119, 
-119, -120, -121, -121, -122, -122, -123, -123, -124, -124, -124, -125, -125, -126, -126, -126, -126, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -125, 
-125, -124, -124, -123, -122, -122, -121, -120, -119, -118, -117, -116, -115, -114, -113, -112, -111, -109, -108, -106, -105, -103, -102, -100, -98, -96, -95, -93, -91, -89, -87, -85, 
-83, -80, -78, -76, -74, -71, -69, -66, -64, -61, -59, -56, -54, -51, -48, -46, -43, -40, -37, -34, -32, -29, -26, -23, -20, -17, -14, -11, -8, -5, -2, 
 };

#endif
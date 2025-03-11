#ifndef SQUARE_MAX_1170_AT_16384_2048INT8_H_
#define SQUARE_MAX_1170_AT_16384_2048INT8_H_

#include <Arduino.h>
#include "mozzi_pgmspace.h"


#define SQUARE_MAX_1170_AT_16384_2048_NUM_CELLS 2048
#define SQUARE_MAX_1170_AT_16384_2048_SAMPLERATE 2048

CONSTTABLE_STORAGE(int8_t) SQUARE_MAX_1170_AT_16384_2048_DATA [] = 
{
0, 1, 3, 5, 6, 8, 10, 11, 13, 15, 16, 18, 20, 21, 23, 25, 26, 28, 29, 31, 33, 34, 36, 38, 39, 41, 42, 44, 45, 47, 48, 50, 52, 
53, 55, 56, 58, 59, 60, 62, 63, 65, 66, 68, 69, 70, 72, 73, 74, 76, 77, 78, 80, 81, 82, 83, 84, 86, 87, 88, 89, 90, 91, 93, 94, 
95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 104, 105, 106, 107, 108, 109, 109, 110, 111, 112, 112, 113, 114, 115, 115, 116, 116, 117, 118, 118, 119, 119, 
120, 120, 121, 121, 122, 122, 122, 123, 123, 123, 124, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 
127, 127, 127, 127, 127, 127, 127, 127, 126, 126, 126, 126, 126, 126, 126, 125, 125, 125, 125, 125, 124, 124, 124, 124, 123, 123, 123, 123, 122, 122, 122, 121, 
121, 121, 120, 120, 120, 119, 119, 119, 118, 118, 118, 117, 117, 116, 116, 116, 115, 115, 115, 114, 114, 113, 113, 113, 112, 112, 111, 111, 111, 110, 110, 110, 
109, 109, 108, 108, 108, 107, 107, 107, 106, 106, 106, 105, 105, 105, 104, 104, 104, 103, 103, 103, 102, 102, 102, 101, 101, 101, 101, 100, 100, 100, 100, 99, 
99, 99, 99, 98, 98, 98, 98, 98, 97, 97, 97, 97, 97, 97, 97, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 
96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 97, 97, 97, 97, 97, 97, 97, 97, 98, 98, 98, 98, 98, 98, 99, 99, 
99, 99, 99, 100, 100, 100, 100, 101, 101, 101, 101, 101, 102, 102, 102, 102, 103, 103, 103, 103, 104, 104, 104, 104, 105, 105, 105, 105, 106, 106, 106, 106, 
107, 107, 107, 107, 108, 108, 108, 108, 109, 109, 109, 109, 110, 110, 110, 110, 110, 111, 111, 111, 111, 112, 112, 112, 112, 112, 113, 113, 113, 113, 113, 113, 
114, 114, 114, 114, 114, 114, 115, 115, 115, 115, 115, 115, 115, 115, 115, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 
116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 115, 115, 115, 115, 115, 115, 115, 115, 115, 114, 114, 114, 114, 114, 114, 114, 
113, 113, 113, 113, 113, 113, 112, 112, 112, 112, 112, 112, 111, 111, 111, 111, 111, 110, 110, 110, 110, 109, 109, 109, 109, 109, 108, 108, 108, 108, 108, 107, 
107, 107, 107, 107, 106, 106, 106, 106, 105, 105, 105, 105, 105, 104, 104, 104, 104, 104, 103, 103, 103, 103, 103, 103, 102, 102, 102, 102, 102, 102, 101, 101, 
101, 101, 101, 101, 101, 100, 100, 100, 100, 100, 100, 100, 100, 100, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 
99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 100, 100, 100, 100, 100, 100, 100, 100, 100, 101, 101, 101, 101, 101, 101, 
101, 102, 102, 102, 102, 102, 102, 103, 103, 103, 103, 103, 103, 104, 104, 104, 104, 104, 105, 105, 105, 105, 105, 106, 106, 106, 106, 107, 107, 107, 107, 107, 
108, 108, 108, 108, 108, 109, 109, 109, 109, 109, 110, 110, 110, 110, 111, 111, 111, 111, 111, 112, 112, 112, 112, 112, 112, 113, 113, 113, 113, 113, 113, 114, 
114, 114, 114, 114, 114, 114, 115, 115, 115, 115, 115, 115, 115, 115, 115, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 
116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 115, 115, 115, 115, 115, 115, 115, 115, 115, 114, 114, 114, 114, 114, 114, 113, 
113, 113, 113, 113, 113, 112, 112, 112, 112, 112, 111, 111, 111, 111, 110, 110, 110, 110, 110, 109, 109, 109, 109, 108, 108, 108, 108, 107, 107, 107, 107, 106, 
106, 106, 106, 105, 105, 105, 105, 104, 104, 104, 104, 103, 103, 103, 103, 102, 102, 102, 102, 101, 101, 101, 101, 101, 100, 100, 100, 100, 99, 99, 99, 99, 
99, 98, 98, 98, 98, 98, 98, 97, 97, 97, 97, 97, 97, 97, 97, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 
96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 97, 97, 97, 97, 97, 97, 97, 98, 98, 98, 98, 98, 99, 99, 99, 99, 
100, 100, 100, 100, 101, 101, 101, 101, 102, 102, 102, 103, 103, 103, 104, 104, 104, 105, 105, 105, 106, 106, 106, 107, 107, 107, 108, 108, 108, 109, 109, 110, 
110, 110, 111, 111, 111, 112, 112, 113, 113, 113, 114, 114, 115, 115, 115, 116, 116, 116, 117, 117, 118, 118, 118, 119, 119, 119, 120, 120, 120, 121, 121, 121, 
122, 122, 122, 123, 123, 123, 123, 124, 124, 124, 124, 125, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 
127, 127, 127, 127, 127, 127, 127, 127, 126, 126, 126, 126, 126, 126, 125, 125, 125, 125, 124, 124, 124, 123, 123, 123, 122, 122, 122, 121, 121, 120, 120, 119, 
119, 118, 118, 117, 116, 116, 115, 115, 114, 113, 112, 112, 111, 110, 109, 109, 108, 107, 106, 105, 104, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 
93, 91, 90, 89, 88, 87, 86, 84, 83, 82, 81, 80, 78, 77, 76, 74, 73, 72, 70, 69, 68, 66, 65, 63, 62, 60, 59, 58, 56, 55, 53, 52, 
50, 48, 47, 45, 44, 42, 41, 39, 38, 36, 34, 33, 31, 29, 28, 26, 25, 23, 21, 20, 18, 16, 15, 13, 11, 10, 8, 6, 5, 3, 1, 0, 
-1, -3, -5, -6, -8, -10, -11, -13, -15, -16, -18, -20, -21, -23, -25, -26, -28, -29, -31, -33, -34, -36, -38, -39, -41, -42, -44, -45, -47, -48, -50, -52, 
-53, -55, -56, -58, -59, -60, -62, -63, -65, -66, -68, -69, -70, -72, -73, -74, -76, -77, -78, -80, -81, -82, -83, -84, -86, -87, -88, -89, -90, -91, -93, -94, 
-95, -96, -97, -98, -99, -100, -101, -102, -103, -104, -104, -105, -106, -107, -108, -109, -109, -110, -111, -112, -112, -113, -114, -115, -115, -116, -116, -117, -118, -118, -119, -119, 
-120, -120, -121, -121, -122, -122, -122, -123, -123, -123, -124, -124, -124, -125, -125, -125, -125, -126, -126, -126, -126, -126, -126, -127, -127, -127, -127, -127, -127, -127, -127, -127, 
-127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -124, -124, -124, -124, -123, -123, -123, -123, -122, -122, -122, -121, 
-121, -121, -120, -120, -120, -119, -119, -119, -118, -118, -118, -117, -117, -116, -116, -116, -115, -115, -115, -114, -114, -113, -113, -113, -112, -112, -111, -111, -111, -110, -110, -110, 
-109, -109, -108, -108, -108, -107, -107, -107, -106, -106, -106, -105, -105, -105, -104, -104, -104, -103, -103, -103, -102, -102, -102, -101, -101, -101, -101, -100, -100, -100, -100, -99, 
-99, -99, -99, -98, -98, -98, -98, -98, -97, -97, -97, -97, -97, -97, -97, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, 
-96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -97, -97, -97, -97, -97, -97, -97, -97, -98, -98, -98, -98, -98, -98, -99, -99, 
-99, -99, -99, -100, -100, -100, -100, -101, -101, -101, -101, -101, -102, -102, -102, -102, -103, -103, -103, -103, -104, -104, -104, -104, -105, -105, -105, -105, -106, -106, -106, -106, 
-107, -107, -107, -107, -108, -108, -108, -108, -109, -109, -109, -109, -110, -110, -110, -110, -110, -111, -111, -111, -111, -112, -112, -112, -112, -112, -113, -113, -113, -113, -113, -113, 
-114, -114, -114, -114, -114, -114, -115, -115, -115, -115, -115, -115, -115, -115, -115, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, 
-116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -115, -115, -115, -115, -115, -115, -115, -115, -115, -114, -114, -114, -114, -114, -114, -114, 
-113, -113, -113, -113, -113, -113, -112, -112, -112, -112, -112, -112, -111, -111, -111, -111, -111, -110, -110, -110, -110, -109, -109, -109, -109, -109, -108, -108, -108, -108, -108, -107, 
-107, -107, -107, -107, -106, -106, -106, -106, -105, -105, -105, -105, -105, -104, -104, -104, -104, -104, -103, -103, -103, -103, -103, -103, -102, -102, -102, -102, -102, -102, -101, -101, 
-101, -101, -101, -101, -101, -100, -100, -100, -100, -100, -100, -100, -100, -100, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, 
-99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -100, -100, -100, -100, -100, -100, -100, -100, -100, -101, -101, -101, -101, -101, -101, 
-101, -102, -102, -102, -102, -102, -102, -103, -103, -103, -103, -103, -103, -104, -104, -104, -104, -104, -105, -105, -105, -105, -105, -106, -106, -106, -106, -107, -107, -107, -107, -107, 
-108, -108, -108, -108, -108, -109, -109, -109, -109, -109, -110, -110, -110, -110, -111, -111, -111, -111, -111, -112, -112, -112, -112, -112, -112, -113, -113, -113, -113, -113, -113, -114, 
-114, -114, -114, -114, -114, -114, -115, -115, -115, -115, -115, -115, -115, -115, -115, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, 
-116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -116, -115, -115, -115, -115, -115, -115, -115, -115, -115, -114, -114, -114, -114, -114, -114, -113, 
-113, -113, -113, -113, -113, -112, -112, -112, -112, -112, -111, -111, -111, -111, -110, -110, -110, -110, -110, -109, -109, -109, -109, -108, -108, -108, -108, -107, -107, -107, -107, -106, 
-106, -106, -106, -105, -105, -105, -105, -104, -104, -104, -104, -103, -103, -103, -103, -102, -102, -102, -102, -101, -101, -101, -101, -101, -100, -100, -100, -100, -99, -99, -99, -99, 
-99, -98, -98, -98, -98, -98, -98, -97, -97, -97, -97, -97, -97, -97, -97, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, 
-96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -96, -97, -97, -97, -97, -97, -97, -97, -98, -98, -98, -98, -98, -99, -99, -99, -99, 
-100, -100, -100, -100, -101, -101, -101, -101, -102, -102, -102, -103, -103, -103, -104, -104, -104, -105, -105, -105, -106, -106, -106, -107, -107, -107, -108, -108, -108, -109, -109, -110, 
-110, -110, -111, -111, -111, -112, -112, -113, -113, -113, -114, -114, -115, -115, -115, -116, -116, -116, -117, -117, -118, -118, -118, -119, -119, -119, -120, -120, -120, -121, -121, -121, 
-122, -122, -122, -123, -123, -123, -123, -124, -124, -124, -124, -125, -125, -125, -125, -125, -126, -126, -126, -126, -126, -126, -126, -127, -127, -127, -127, -127, -127, -127, -127, -127, 
-127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -124, -124, -124, -123, -123, -123, -122, -122, -122, -121, -121, -120, -120, -119, 
-119, -118, -118, -117, -116, -116, -115, -115, -114, -113, -112, -112, -111, -110, -109, -109, -108, -107, -106, -105, -104, -104, -103, -102, -101, -100, -99, -98, -97, -96, -95, -94, 
-93, -91, -90, -89, -88, -87, -86, -84, -83, -82, -81, -80, -78, -77, -76, -74, -73, -72, -70, -69, -68, -66, -65, -63, -62, -60, -59, -58, -56, -55, -53, -52, 
-50, -48, -47, -45, -44, -42, -41, -39, -38, -36, -34, -33, -31, -29, -28, -26, -25, -23, -21, -20, -18, -16, -15, -13, -11, -10, -8, -6, -5, -3, -1, 
 };

#endif
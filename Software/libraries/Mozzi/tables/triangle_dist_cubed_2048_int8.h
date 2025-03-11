#ifndef TRIANGLE_DIST_CUBED_2048_H_
#define TRIANGLE_DIST_CUBED_2048_H_

#include <Arduino.h>
#include "mozzi_pgmspace.h"

/* triangle wave with distortion from Audacity
*/

#define TRIANGLE_DIST_CUBED_2048_NUM_CELLS 2048
#define TRIANGLE_DIST_CUBED_2048_SAMPLERATE 2048

CONSTTABLE_STORAGE(int8_t) TRIANGLE_DIST_CUBED_2048_DATA []  =
        {
                38, 39, 39, 38, 38, 38,
                38, 38, 37, 38, 38, 37, 37, 37, 37, 37, 36, 37, 37, 36, 36, 36, 36, 36, 35, 36,
                36, 35, 35, 34, 35, 35, 34, 34, 34, 35, 34, 35, 35, 34, 33, 34, 34, 33, 33, 34,
                34, 33, 33, 32, 33, 33, 32, 33, 33, 32, 32, 31, 32, 32, 31, 32, 32, 31, 31, 32,
                32, 31, 30, 31, 31, 30, 30, 31, 31, 30, 30, 30, 30, 30, 29, 29, 29, 29, 29, 28,
                29, 29, 28, 28, 29, 29, 28, 27, 28, 28, 28, 27, 28, 28, 27, 27, 27, 27, 27, 28,
                28, 27, 26, 27, 27, 27, 26, 27, 27, 26, 26, 26, 26, 26, 25, 26, 26, 25, 25, 26,
                26, 25, 25, 25, 25, 25, 24, 25, 25, 24, 24, 24, 25, 24, 23, 23, 24, 24, 23, 24,
                24, 23, 23, 23, 24, 23, 22, 23, 23, 23, 22, 23, 23, 22, 22, 22, 23, 22, 21, 22,
                22, 21, 21, 22, 22, 21, 21, 20, 21, 21, 20, 20, 21, 21, 20, 20, 20, 20, 20, 20,
                21, 20, 20, 20, 20, 20, 19, 20, 20, 19, 19, 20, 20, 19, 19, 19, 19, 19, 18, 19,
                19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 18, 18, 18, 17, 17, 17, 17, 17, 18,
                18, 17, 17, 16, 17, 17, 16, 17, 17, 17, 16, 16, 16, 16, 16, 17, 17, 16, 16, 16,
                16, 16, 15, 16, 16, 15, 15, 15, 15, 15, 15, 16, 16, 15, 15, 14, 15, 15, 14, 14,
                15, 15, 14, 15, 15, 14, 14, 13, 14, 14, 14, 13, 14, 14, 13, 14, 14, 14, 13, 14,
                14, 13, 13, 14, 14, 13, 13, 13, 14, 13, 13, 13, 13, 13, 12, 13, 13, 13, 12, 12,
                12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 11, 12, 12, 11, 11,
                11, 11, 11, 12, 12, 11, 11, 11, 12, 11, 11, 10, 11, 11, 10, 11, 11, 11, 10, 11,
                11, 10, 10, 11, 11, 10, 10, 9, 10, 10, 10, 9, 10, 10, 10, 10, 10, 10, 9, 9, 10,
                10, 9, 10, 10, 9, 9, 10, 10, 9, 9, 10, 10, 9, 9, 8, 9, 9, 9, 9, 9, 9, 8, 9, 9,
                9, 8, 8, 9, 9, 8, 9, 9, 8, 8, 9, 9, 8, 8, 8, 9, 8, 8, 7, 8, 8, 8, 8, 8, 8, 7, 7,
                8, 8, 7, 7, 8, 8, 7, 7, 7, 8, 7, 8, 8, 7, 7, 7, 7, 7, 7, 6, 7, 7, 7, 7, 7, 7, 7,
                7, 7, 7, 6, 7, 7, 7, 6, 7, 7, 7, 6, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 6, 6,
                6, 5, 6, 6, 6, 5, 6, 6, 6, 5, 6, 6, 5, 6, 6, 6, 5, 6, 6, 6, 5, 5, 6, 6, 5, 6, 6,
                5, 5, 6, 6, 5, 5, 6, 6, 5, 5, 5, 6, 5, 5, 4, 5, 5, 5, 5, 5, 5, 5, 4, 4, 3, 2, 1,
                1, 0, 0, -2, -3, -3, -3, -5, -6, -6, -7, -9, -10, -10, -11, -12, -14, -14, -14,
                -16, -17, -17, -18, -20, -21, -21, -22, -24, -25, -25, -26, -28, -29, -29, -30,
                -32, -33, -33, -34, -36, -37, -37, -37, -39, -41, -41, -41, -43, -44, -44, -46,
                -47, -47, -47, -49, -50, -50, -50, -52, -53, -53, -53, -54, -55, -55, -55, -56,
                -57, -57, -57, -57, -58, -59, -58, -58, -59, -60, -60, -60, -61, -61, -61, -61,
                -62, -61, -61, -62, -62, -62, -61, -61, -62, -62, -61, -62, -62, -61, -61, -61,
                -61, -61, -61, -60, -60, -60, -60, -60, -60, -59, -59, -59, -59, -59, -58, -58,
                -58, -58, -57, -57, -57, -57, -56, -56, -56, -56, -55, -55, -55, -54, -54, -54,
                -54, -53, -53, -53, -53, -52, -52, -52, -52, -51, -51, -51, -51, -50, -50, -50,
                -50, -49, -49, -49, -49, -49, -48, -48, -48, -48, -48, -47, -47, -47, -47, -47,
                -47, -47, -46, -46, -46, -46, -46, -46, -46, -46, -45, -45, -45, -45, -45, -45,
                -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -44,
                -45, -45, -45, -44, -45, -45, -45, -44, -45, -45, -45, -46, -46, -45, -45, -45,
                -46, -46, -45, -45, -46, -46, -46, -45, -46, -47, -46, -46, -47, -47, -46, -47,
                -48, -47, -47, -46, -47, -48, -47, -47, -48, -48, -47, -47, -48, -49, -48, -49,
                -50, -49, -48, -48, -49, -49, -49, -50, -50, -50, -49, -49, -50, -50, -50, -49,
                -50, -51, -50, -51, -52, -51, -50, -50, -51, -52, -51, -50, -51, -52, -51, -51,
                -52, -52, -51, -53, -53, -52, -52, -51, -52, -53, -52, -51, -53, -53, -52, -52,
                -53, -53, -52, -52, -53, -54, -53, -54, -54, -53, -53, -54, -54, -54, -53, -52,
                -54, -54, -53, -52, -54, -54, -53, -54, -55, -54, -53, -54, -55, -54, -53, -53,
                -54, -54, -53, -53, -54, -54, -53, -54, -55, -54, -53, -54, -55, -54, -53, -54,
                -55, -54, -53, -52, -53, -54, -53, -52, -53, -54, -53, -54, -54, -53, -53, -52,
                -53, -53, -52, -54, -54, -53, -52, -51, -53, -53, -52, -53, -53, -52, -52, -53,
                -53, -52, -51, -51, -52, -52, -51, -51, -52, -52, -51, -50, -51, -52, -51, -50,
                -51, -51, -50, -50, -51, -51, -50, -51, -51, -50, -50, -49, -50, -50, -49, -50,
                -50, -50, -49, -48, -49, -49, -48, -48, -49, -49, -48, -48, -48, -49, -48, -47,
                -48, -48, -47, -47, -48, -48, -47, -48, -48, -47, -47, -46, -47, -47, -46, -46,
                -47, -47, -46, -47, -47, -46, -45, -45, -46, -46, -45, -44, -45, -45, -44, -44,
                -45, -45, -44, -43, -44, -44, -44, -43, -44, -44, -43, -43, -43, -44, -43, -42,
                -43, -43, -42, -42, -43, -43, -42, -41, -42, -42, -41, -42, -42, -42, -41, -42,
                -42, -41, -41, -40, -41, -41, -40, -39, -40, -40, -40, -39, -40, -40, -39, -40,
                -40, -39, -39, -38, -39, -39, -38, -38, -38, -39, -38, -39, -39, -38, -37, -38,
                -38, -37, -37, -38, -38, -37, -36, -37, -37, -37, -36, -37, -37, -36, -36, -35,
                -36, -36, -35, -36, -36, -35, -35, -34, -35, -35, -34, -34, -34, -34, -34, -35,
                -35, -34, -33, -34, -34, -33, -33, -32, -33, -33, -32, -32, -33, -33, -32, -33,
                -33, -32, -32, -31, -32, -32, -31, -31, -31, -31, -31, -32, -32, -31, -30, -31,
                -31, -30, -30, -29, -30, -30, -30, -30, -30, -30, -29, -29, -29, -29, -29, -28,
                -29, -29, -28, -28, -29, -29, -28, -29, -29, -28, -28, -27, -28, -28, -27, -27,
                -27, -27, -27, -28, -28, -27, -27, -27, -27, -27, -26, -26, -26, -26, -26, -26,
                -26, -26, -25, -26, -26, -25, -25, -24, -25, -25, -25, -24, -25, -25, -24, -25,
                -25, -24, -24, -25, -25, -24, -24, -23, -24, -24, -23, -24, -24, -23, -23, -24,
                -24, -23, -23, -23, -23, -23, -22, -22, -22, -23, -22, -21, -22, -22, -22, -22,
                -22, -22, -21, -22, -22, -21, -21, -22, -22, -21, -21, -21, -21, -21, -20, -21,
                -21, -20, -20, -21, -21, -20, -20, -19, -20, -20, -19, -19, -20, -20, -19, -19,
                -19, -19, -19, -18, -19, -19, -19, -19, -19, -19, -18, -19, -19, -18, -18, -19,
                -19, -18, -18, -18, -18, -18, -17, -18, -18, -18, -17, -18, -18, -17, -17, -18,
                -18, -17, -17, -17, -17, -17, -16, -16, -17, -17, -16, -16, -16, -16, -16, -17,
                -17, -16, -16, -15, -16, -16, -15, -15, -16, -16, -15, -15, -15, -16, -15, -16,
                -16, -15, -15, -14, -15, -15, -14, -14, -15, -15, -14, -14, -14, -15, -14, -14,
                -14, -14, -14, -13, -14, -14, -14, -13, -14, -14, -13, -13, -14, -14, -13, -13,
                -13, -14, -13, -13, -13, -13, -13, -12, -13, -13, -13, -12, -13, -13, -12, -12,
                -13, -13, -12, -12, -13, -13, -12, -12, -12, -12, -12, -13, -13, -12, -12, -11,
                -12, -12, -12, -11, -12, -12, -11, -12, -12, -12, -11, -12, -12, -11, -11, -12,
                -12, -11, -11, -11, -12, -11, -11, -11, -11, -11, -10, -10, -11, -11, -10, -11,
                -11, -11, -10, -10, -10, -10, -10, -11, -11, -10, -10, -10, -11, -10, -10, -10,
                -10, -10, -10, -9, -10, -10, -9, -9, -10, -10, -9, -9, -9, -10, -9, -9, -9, -9,
                -9, -9, -9, -9, -9, -8, -9, -9, -9, -8, -9, -9, -8, -8, -9, -9, -8, -9, -9, -9,
                -8, -9, -9, -9, -8, -8, -8, -9, -8, -8, -8, -8, -8, -9, -9, -8, -8, -8, -9, -8,
                -8, -7, -8, -8, -7, -7, -8, -8, -7, -7, -8, -8, -7, -8, -8, -8, -7, -7, -7, -8,
                -7, -7, -7, -7, -7, -8, -8, -7, -7, -7, -8, -7, -7, -7, -7, -7, -7, -7, -7, -7,
                -6, -6, -7, -7, -6, -6, -7, -7, -6, -7, -7, -7, -6, -6, -6, -7, -6, -6, -6, -6,
                -6, -6, -6, -6, -6, -7, -7, -6, -6, -6, -7, -6, -6, -5, -6, -6, -6, -5, -5, -4,
                -4, -4, -2, -1, -1, 0, 0, 2, 3, 3, 5, 6, 6, 6, 7, 9, 10, 10, 12, 13, 13, 14, 16,
                17, 17, 17, 20, 21, 21, 21, 22, 24, 25, 25, 26, 28, 29, 29, 31, 33, 33, 32, 33,
                35, 37, 37, 39, 40, 40, 40, 42, 44, 43, 44, 44, 46, 47, 47, 47, 49, 50, 50, 51,
                52, 52, 52, 54, 55, 54, 54, 56, 57, 56, 56, 58, 58, 58, 58, 59, 59, 59, 59, 60,
                60, 60, 60, 60, 61, 60, 60, 61, 61, 61, 60, 60, 60, 61, 60, 61, 61, 60, 60, 60,
                60, 60, 59, 59, 59, 59, 59, 59, 59, 58, 58, 58, 58, 57, 57, 57, 57, 56, 56, 56,
                56, 55, 55, 55, 55, 54, 54, 54, 53, 53, 53, 53, 52, 52, 52, 52, 51, 51, 51, 51,
                50, 50, 50, 50, 49, 49, 49, 49, 48, 48, 48, 48, 48, 47, 47, 47, 47, 47, 46, 46,
                46, 46, 46, 46, 46, 45, 45, 45, 45, 45, 45, 45, 45, 45, 44, 44, 44, 44, 44, 44,
                44, 44, 44, 43, 44, 44, 44, 43, 44, 44, 43, 44, 44, 44, 43, 44, 44, 44, 44, 43,
                44, 44, 44, 43, 44, 44, 44, 45, 45, 44, 44, 45, 45, 45, 44, 44, 45, 45, 45, 44,
                45, 45, 45, 46, 46, 46, 45, 46, 47, 46, 46, 47, 47, 46, 46, 47, 48, 47, 47, 48,
                48, 47, 47, 48, 48, 48, 47, 47, 48, 48, 48, 49, 49, 49, 48, 48, 49, 49, 49, 50,
                50, 49, 49, 48, 50, 50, 49, 49, 50, 50, 50, 51, 51, 51, 50, 51, 52, 51, 50, 50,
                51, 51, 51, 50, 51, 52, 51, 50, 52, 52, 51, 51, 52, 52, 51, 53, 53, 52, 52, 51,
                52, 53, 52, 51, 52, 53, 52, 51, 53, 53, 52, 53, 54, 53, 52, 51, 53, 53, 52, 53,
                54, 53, 52, 53, 54, 53, 52, 51, 53, 53, 52, 51, 53, 53, 52, 51, 53, 53, 52, 51,
                53, 53, 52, 53, 53, 52, 52, 53, 53, 52, 52, 51, 52, 52, 51, 51, 52, 52, 51, 52,
                53, 52, 51, 50, 52, 52, 51, 50, 51, 51, 51, 52, 52, 51, 50, 50, 51, 51, 50, 51,
                51, 50, 50, 51, 51, 50, 50, 49, 50, 50, 49, 50, 50, 49, 49, 50, 50, 49, 49, 48,
                49, 49, 48, 48, 48, 49, 48, 47, 48, 48, 47, 48, 49, 48, 47, 48, 48, 47, 47, 46,
                47, 47, 46, 47, 47, 46, 46, 47, 47, 46, 45, 46, 47, 46, 45, 44, 45, 45, 45, 46,
                46, 45, 44, 45, 45, 44, 44, 45, 45, 44, 43, 44, 44, 43, 43, 44, 44, 43, 42, 42,
                43, 43, 42, 43, 43, 42, 42, 41, 42, 42, 41, 42, 42, 41, 41, 41, 42, 41, 40, 41,
                41, 40, 40, 41, 41, 40, 39, 40, 40, 39, 39, 38, 39, 39, 38, 39, 39, 38,
        };

#endif /* TRIANGLE_DIST_CUBED_2048_H_ */

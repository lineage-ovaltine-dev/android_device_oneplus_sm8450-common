/*
 * Copyright (c) 2020, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

static const int8_t effect_1[] = {
        1,    1,    1,    1,    1,    1,    2,    2,    2,    3,    3,    4,    4,    5,    6,
        7,    8,    9,    10,   11,   13,   15,   17,   20,   22,   26,   29,   33,   38,   43,
        49,   56,   64,   71,   76,   81,   85,   88,   90,   92,   93,   93,   93,   92,   91,
        90,   88,   86,   84,   81,   78,   75,   72,   68,   65,   61,   57,   53,   49,   44,
        40,   36,   31,   27,   22,   17,   12,   7,    2,    -3,   -9,   -15,  -21,  -28,  -35,
        -43,  -51,  -60,  -71,  -82,  -94,  -103, -112, -118, -123, -126, -127, -127, -127, -127,
        -124, -121, -117, -112, -107, -101, -94,  -87,  -80,  -72,  -64,  -55,  -47,  -38,  -30,
        -21,  -12,  -4,   5,    13,   21,   29,   37,   44,   51,   57,   63,   68,   73,   77,
        81,   84,   86,   88,   89,   89,   88,   86,   84,   81,   78,   75,   72,   68,   64,
        59,   54,   49,   44,   38,   32,   25,   19,   12,   5,    -2,   -9,   -17,  -24,  -32,
        -40,  -47,  -55,  -62,  -69,  -76,  -83,  -89,  -95,  -101, -106, -111, -115, -119, -122,
        -124, -125, -125, -125, -123, -120, -116, -111, -104, -95,  -85,  -74,  -65,  -56,  -49,
        -42,  -35,  -30,  -24,  -19,  -15,  -10,  -6,   -3,   1,    5,    8,    11,   15,   18,
        21,   24,   26,   29,   32,   34,   37,   39,   41,   43,   45,   47,   49,   50,   51,
        52,   53,   54,   54,   54,   54,   53,   52,   50,   48,   45,
};

static const int8_t effect_2[] = {
        1,    1,    1,    1,    1,    1,    2,    2,    2,    3,    3,    4,    4,    5,    6,
        7,    8,    9,    10,   12,   13,   14,   16,   19,   22,   25,   28,   32,   36,   42,
        48,   54,   61,   69,   78,   85,   92,   97,   102,  106,  110,  113,  115,  117,  119,
        121,  121,  123,  123,  123,  124,  124,  124,  123,  123,  123,  122,  121,  121,  120,
        119,  118,  117,  115,  114,  113,  112,  111,  109,  108,  106,  105,  103,  101,  99,
        97,   95,   93,   91,   89,   86,   83,   80,   77,   73,   69,   64,   60,   54,   48,
        41,   34,   25,   15,   4,    -7,   -22,  -37,  -51,  -64,  -74,  -83,  -91,  -99,  -104,
        -109, -112, -115, -119, -120, -122, -122, -123, -122, -122, -122, -120, -120, -118, -116,
        -114, -112, -110, -107, -105, -103, -99,  -97,  -95,  -91,  -89,  -86,  -83,  -80,  -77,
        -74,  -71,  -68,  -64,  -61,  -58,  -55,  -52,  -49,  -46,  -43,  -40,  -36,  -33,  -29,
        -26,  -22,  -18,  -14,  -10,  -5,   0,    6,    12,   19,   27,   35,   42,   47,   52,
        57,   60,   63,   65,   66,   67,   68,   68,   67,   67,   66,   64,   62,   61,   58,
        56,   53,   51,   49,   45,   43,   39,   35,   33,   29,   26,   22,   19,   15,   12,
        8,    5,    1,    -2,   -5,   -9,   -12,  -14,  -17,  -20,  -22,  -25,  -27,  -28,  -30,
        -32,  -32,  -34,  -34,  -34,
};
static const int8_t effect_3[] = {
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    2,    2,
        3,    4,    6,    7,    9,    11,   14,   16,   19,   22,   26,   29,   33,   37,   41,
        45,   49,   54,   58,   62,   66,   70,   74,   78,   81,   85,   88,   91,   94,   97,
        99,   101,  103,  105,  106,  108,  108,  109,  110,  110,  110,  109,  109,  108,  107,
        105,  104,  102,  100,  98,   96,   93,   90,   87,   84,   81,   78,   74,   70,   67,
        63,   59,   54,   50,   46,   41,   37,   32,   28,   23,   18,   13,   9,    4,    -1,
        -6,   -11,  -15,  -20,  -25,  -29,  -34,  -39,  -43,  -47,  -52,  -56,  -60,  -64,  -68,
        -71,  -75,  -78,  -82,  -85,  -88,  -90,  -93,  -95,  -97,  -99,  -101, -103, -104, -106,
        -107, -107, -108, -108, -108, -108, -108, -107, -107, -106, -105, -103, -102, -100, -98,
        -96,  -94,  -91,  -88,  -86,  -83,  -79,  -76,  -72,  -69,  -65,  -61,  -57,  -53,  -49,
        -44,  -40,  -35,  -31,  -26,  -21,  -17,  -12,  -7,   -2,   3,    7,    12,   17,   22,
        27,   31,   36,   40,   45,   49,   53,   57,   61,   65,   69,   73,   76,   80,   83,
        86,   89,   91,   94,   96,   98,   100,  102,  104,  105,  106,  107,  108,  108,  108,
        108,  108,  108,  107,  106,  105,  104,  103,  101,  99,   97,   95,   93,   90,   87,
        84,   81,   75,   72,   68,   65,   61,
};
static const int8_t effect_4[] = {
        0,    0,    0,    0,    0,    1,    1,    1,    1,    1,    1,    2,    2,    2,    3,
        3,    4,    4,    5,    6,    7,    8,    9,    10,   12,   13,   15,   17,   19,   22,
        25,   28,   32,   37,   42,   48,   55,   62,   70,   79,   86,   92,   97,   102,  107,
        110,  113,  115,  117,  119,  121,  121,  123,  123,  123,  124,  124,  124,  123,  123,
        123,  121,  121,  121,  119,  119,  118,  117,  115,  114,  113,  112,  110,  109,  107,
        106,  105,  102,  101,  99,   97,   95,   93,   91,   89,   86,   83,   80,   77,   73,
        69,   64,   60,   54,   48,   41,   33,   24,   14,   3,    -9,   -23,  -38,  -52,  -65,
        -75,  -84,  -92,  -99,  -104, -109, -113, -115, -119, -120, -122, -122, -123, -122, -122,
        -121, -120, -119, -118, -116, -114, -112, -110, -107, -105, -102, -99,  -97,  -94,  -91,
        -88,  -85,  -82,  -79,  -76,  -74,  -70,  -68,  -64,  -61,  -58,  -55,  -52,  -49,  -46,
        -43,  -39,  -36,  -33,  -29,  -26,  -22,  -18,  -14,  -10,  -5,   0,    7,    13,   20,
        28,   35,   42,   48,   53,   58,   60,   63,   65,   66,   67,   68,   68,   67,   67,
        66,   64,   62,   61,   58,   56,   53,   51,   48,   45,   42,   38,   35,   33,   28,
        26,   22,   19,   15,   12,   8,    5,    1,    -2,   -5,   -9,   -12,  -14,  -17,  -20,
        -22,  -25,  -28,  -29,  -30,  -32,  -32,
};

static const struct effect_stream effects[] = {
        {
                /* CLICK */
                .effect_id = 0,
                .data = effect_0,
                .length = ARRAY_SIZE(effect_0),
                .play_rate_hz = 24000,
        },

        {
                /* DOUBLE_CLICK */
                .effect_id = 1,
                .data = effect_1,
                .length = ARRAY_SIZE(effect_1),
                .play_rate_hz = 24000,
        },

        {
                /* TICK */
                .effect_id = 2,
                .data = effect_2,
                .length = ARRAY_SIZE(effect_2),
                .play_rate_hz = 24000,
        },

        {
                /* THUD */
                .effect_id = 3,
                .data = effect_3,
                .length = ARRAY_SIZE(effect_3),
                .play_rate_hz = 24000,
        },

        {
                /* POP */
                .effect_id = 4,
                .data = effect_4,
                .length = ARRAY_SIZE(effect_4),
                .play_rate_hz = 24000,
        },

        {
                /* HEAVY_CLICK */
                .effect_id = 5,
                .data = effect_3,
                .length = ARRAY_SIZE(effect_3),
                .play_rate_hz = 24000,
        },
};

#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.13.2                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_3060945647413172151) {
   out_3060945647413172151[0] = delta_x[0] + nom_x[0];
   out_3060945647413172151[1] = delta_x[1] + nom_x[1];
   out_3060945647413172151[2] = delta_x[2] + nom_x[2];
   out_3060945647413172151[3] = delta_x[3] + nom_x[3];
   out_3060945647413172151[4] = delta_x[4] + nom_x[4];
   out_3060945647413172151[5] = delta_x[5] + nom_x[5];
   out_3060945647413172151[6] = delta_x[6] + nom_x[6];
   out_3060945647413172151[7] = delta_x[7] + nom_x[7];
   out_3060945647413172151[8] = delta_x[8] + nom_x[8];
   out_3060945647413172151[9] = delta_x[9] + nom_x[9];
   out_3060945647413172151[10] = delta_x[10] + nom_x[10];
   out_3060945647413172151[11] = delta_x[11] + nom_x[11];
   out_3060945647413172151[12] = delta_x[12] + nom_x[12];
   out_3060945647413172151[13] = delta_x[13] + nom_x[13];
   out_3060945647413172151[14] = delta_x[14] + nom_x[14];
   out_3060945647413172151[15] = delta_x[15] + nom_x[15];
   out_3060945647413172151[16] = delta_x[16] + nom_x[16];
   out_3060945647413172151[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1090212893188142520) {
   out_1090212893188142520[0] = -nom_x[0] + true_x[0];
   out_1090212893188142520[1] = -nom_x[1] + true_x[1];
   out_1090212893188142520[2] = -nom_x[2] + true_x[2];
   out_1090212893188142520[3] = -nom_x[3] + true_x[3];
   out_1090212893188142520[4] = -nom_x[4] + true_x[4];
   out_1090212893188142520[5] = -nom_x[5] + true_x[5];
   out_1090212893188142520[6] = -nom_x[6] + true_x[6];
   out_1090212893188142520[7] = -nom_x[7] + true_x[7];
   out_1090212893188142520[8] = -nom_x[8] + true_x[8];
   out_1090212893188142520[9] = -nom_x[9] + true_x[9];
   out_1090212893188142520[10] = -nom_x[10] + true_x[10];
   out_1090212893188142520[11] = -nom_x[11] + true_x[11];
   out_1090212893188142520[12] = -nom_x[12] + true_x[12];
   out_1090212893188142520[13] = -nom_x[13] + true_x[13];
   out_1090212893188142520[14] = -nom_x[14] + true_x[14];
   out_1090212893188142520[15] = -nom_x[15] + true_x[15];
   out_1090212893188142520[16] = -nom_x[16] + true_x[16];
   out_1090212893188142520[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5258459091887351789) {
   out_5258459091887351789[0] = 1.0;
   out_5258459091887351789[1] = 0.0;
   out_5258459091887351789[2] = 0.0;
   out_5258459091887351789[3] = 0.0;
   out_5258459091887351789[4] = 0.0;
   out_5258459091887351789[5] = 0.0;
   out_5258459091887351789[6] = 0.0;
   out_5258459091887351789[7] = 0.0;
   out_5258459091887351789[8] = 0.0;
   out_5258459091887351789[9] = 0.0;
   out_5258459091887351789[10] = 0.0;
   out_5258459091887351789[11] = 0.0;
   out_5258459091887351789[12] = 0.0;
   out_5258459091887351789[13] = 0.0;
   out_5258459091887351789[14] = 0.0;
   out_5258459091887351789[15] = 0.0;
   out_5258459091887351789[16] = 0.0;
   out_5258459091887351789[17] = 0.0;
   out_5258459091887351789[18] = 0.0;
   out_5258459091887351789[19] = 1.0;
   out_5258459091887351789[20] = 0.0;
   out_5258459091887351789[21] = 0.0;
   out_5258459091887351789[22] = 0.0;
   out_5258459091887351789[23] = 0.0;
   out_5258459091887351789[24] = 0.0;
   out_5258459091887351789[25] = 0.0;
   out_5258459091887351789[26] = 0.0;
   out_5258459091887351789[27] = 0.0;
   out_5258459091887351789[28] = 0.0;
   out_5258459091887351789[29] = 0.0;
   out_5258459091887351789[30] = 0.0;
   out_5258459091887351789[31] = 0.0;
   out_5258459091887351789[32] = 0.0;
   out_5258459091887351789[33] = 0.0;
   out_5258459091887351789[34] = 0.0;
   out_5258459091887351789[35] = 0.0;
   out_5258459091887351789[36] = 0.0;
   out_5258459091887351789[37] = 0.0;
   out_5258459091887351789[38] = 1.0;
   out_5258459091887351789[39] = 0.0;
   out_5258459091887351789[40] = 0.0;
   out_5258459091887351789[41] = 0.0;
   out_5258459091887351789[42] = 0.0;
   out_5258459091887351789[43] = 0.0;
   out_5258459091887351789[44] = 0.0;
   out_5258459091887351789[45] = 0.0;
   out_5258459091887351789[46] = 0.0;
   out_5258459091887351789[47] = 0.0;
   out_5258459091887351789[48] = 0.0;
   out_5258459091887351789[49] = 0.0;
   out_5258459091887351789[50] = 0.0;
   out_5258459091887351789[51] = 0.0;
   out_5258459091887351789[52] = 0.0;
   out_5258459091887351789[53] = 0.0;
   out_5258459091887351789[54] = 0.0;
   out_5258459091887351789[55] = 0.0;
   out_5258459091887351789[56] = 0.0;
   out_5258459091887351789[57] = 1.0;
   out_5258459091887351789[58] = 0.0;
   out_5258459091887351789[59] = 0.0;
   out_5258459091887351789[60] = 0.0;
   out_5258459091887351789[61] = 0.0;
   out_5258459091887351789[62] = 0.0;
   out_5258459091887351789[63] = 0.0;
   out_5258459091887351789[64] = 0.0;
   out_5258459091887351789[65] = 0.0;
   out_5258459091887351789[66] = 0.0;
   out_5258459091887351789[67] = 0.0;
   out_5258459091887351789[68] = 0.0;
   out_5258459091887351789[69] = 0.0;
   out_5258459091887351789[70] = 0.0;
   out_5258459091887351789[71] = 0.0;
   out_5258459091887351789[72] = 0.0;
   out_5258459091887351789[73] = 0.0;
   out_5258459091887351789[74] = 0.0;
   out_5258459091887351789[75] = 0.0;
   out_5258459091887351789[76] = 1.0;
   out_5258459091887351789[77] = 0.0;
   out_5258459091887351789[78] = 0.0;
   out_5258459091887351789[79] = 0.0;
   out_5258459091887351789[80] = 0.0;
   out_5258459091887351789[81] = 0.0;
   out_5258459091887351789[82] = 0.0;
   out_5258459091887351789[83] = 0.0;
   out_5258459091887351789[84] = 0.0;
   out_5258459091887351789[85] = 0.0;
   out_5258459091887351789[86] = 0.0;
   out_5258459091887351789[87] = 0.0;
   out_5258459091887351789[88] = 0.0;
   out_5258459091887351789[89] = 0.0;
   out_5258459091887351789[90] = 0.0;
   out_5258459091887351789[91] = 0.0;
   out_5258459091887351789[92] = 0.0;
   out_5258459091887351789[93] = 0.0;
   out_5258459091887351789[94] = 0.0;
   out_5258459091887351789[95] = 1.0;
   out_5258459091887351789[96] = 0.0;
   out_5258459091887351789[97] = 0.0;
   out_5258459091887351789[98] = 0.0;
   out_5258459091887351789[99] = 0.0;
   out_5258459091887351789[100] = 0.0;
   out_5258459091887351789[101] = 0.0;
   out_5258459091887351789[102] = 0.0;
   out_5258459091887351789[103] = 0.0;
   out_5258459091887351789[104] = 0.0;
   out_5258459091887351789[105] = 0.0;
   out_5258459091887351789[106] = 0.0;
   out_5258459091887351789[107] = 0.0;
   out_5258459091887351789[108] = 0.0;
   out_5258459091887351789[109] = 0.0;
   out_5258459091887351789[110] = 0.0;
   out_5258459091887351789[111] = 0.0;
   out_5258459091887351789[112] = 0.0;
   out_5258459091887351789[113] = 0.0;
   out_5258459091887351789[114] = 1.0;
   out_5258459091887351789[115] = 0.0;
   out_5258459091887351789[116] = 0.0;
   out_5258459091887351789[117] = 0.0;
   out_5258459091887351789[118] = 0.0;
   out_5258459091887351789[119] = 0.0;
   out_5258459091887351789[120] = 0.0;
   out_5258459091887351789[121] = 0.0;
   out_5258459091887351789[122] = 0.0;
   out_5258459091887351789[123] = 0.0;
   out_5258459091887351789[124] = 0.0;
   out_5258459091887351789[125] = 0.0;
   out_5258459091887351789[126] = 0.0;
   out_5258459091887351789[127] = 0.0;
   out_5258459091887351789[128] = 0.0;
   out_5258459091887351789[129] = 0.0;
   out_5258459091887351789[130] = 0.0;
   out_5258459091887351789[131] = 0.0;
   out_5258459091887351789[132] = 0.0;
   out_5258459091887351789[133] = 1.0;
   out_5258459091887351789[134] = 0.0;
   out_5258459091887351789[135] = 0.0;
   out_5258459091887351789[136] = 0.0;
   out_5258459091887351789[137] = 0.0;
   out_5258459091887351789[138] = 0.0;
   out_5258459091887351789[139] = 0.0;
   out_5258459091887351789[140] = 0.0;
   out_5258459091887351789[141] = 0.0;
   out_5258459091887351789[142] = 0.0;
   out_5258459091887351789[143] = 0.0;
   out_5258459091887351789[144] = 0.0;
   out_5258459091887351789[145] = 0.0;
   out_5258459091887351789[146] = 0.0;
   out_5258459091887351789[147] = 0.0;
   out_5258459091887351789[148] = 0.0;
   out_5258459091887351789[149] = 0.0;
   out_5258459091887351789[150] = 0.0;
   out_5258459091887351789[151] = 0.0;
   out_5258459091887351789[152] = 1.0;
   out_5258459091887351789[153] = 0.0;
   out_5258459091887351789[154] = 0.0;
   out_5258459091887351789[155] = 0.0;
   out_5258459091887351789[156] = 0.0;
   out_5258459091887351789[157] = 0.0;
   out_5258459091887351789[158] = 0.0;
   out_5258459091887351789[159] = 0.0;
   out_5258459091887351789[160] = 0.0;
   out_5258459091887351789[161] = 0.0;
   out_5258459091887351789[162] = 0.0;
   out_5258459091887351789[163] = 0.0;
   out_5258459091887351789[164] = 0.0;
   out_5258459091887351789[165] = 0.0;
   out_5258459091887351789[166] = 0.0;
   out_5258459091887351789[167] = 0.0;
   out_5258459091887351789[168] = 0.0;
   out_5258459091887351789[169] = 0.0;
   out_5258459091887351789[170] = 0.0;
   out_5258459091887351789[171] = 1.0;
   out_5258459091887351789[172] = 0.0;
   out_5258459091887351789[173] = 0.0;
   out_5258459091887351789[174] = 0.0;
   out_5258459091887351789[175] = 0.0;
   out_5258459091887351789[176] = 0.0;
   out_5258459091887351789[177] = 0.0;
   out_5258459091887351789[178] = 0.0;
   out_5258459091887351789[179] = 0.0;
   out_5258459091887351789[180] = 0.0;
   out_5258459091887351789[181] = 0.0;
   out_5258459091887351789[182] = 0.0;
   out_5258459091887351789[183] = 0.0;
   out_5258459091887351789[184] = 0.0;
   out_5258459091887351789[185] = 0.0;
   out_5258459091887351789[186] = 0.0;
   out_5258459091887351789[187] = 0.0;
   out_5258459091887351789[188] = 0.0;
   out_5258459091887351789[189] = 0.0;
   out_5258459091887351789[190] = 1.0;
   out_5258459091887351789[191] = 0.0;
   out_5258459091887351789[192] = 0.0;
   out_5258459091887351789[193] = 0.0;
   out_5258459091887351789[194] = 0.0;
   out_5258459091887351789[195] = 0.0;
   out_5258459091887351789[196] = 0.0;
   out_5258459091887351789[197] = 0.0;
   out_5258459091887351789[198] = 0.0;
   out_5258459091887351789[199] = 0.0;
   out_5258459091887351789[200] = 0.0;
   out_5258459091887351789[201] = 0.0;
   out_5258459091887351789[202] = 0.0;
   out_5258459091887351789[203] = 0.0;
   out_5258459091887351789[204] = 0.0;
   out_5258459091887351789[205] = 0.0;
   out_5258459091887351789[206] = 0.0;
   out_5258459091887351789[207] = 0.0;
   out_5258459091887351789[208] = 0.0;
   out_5258459091887351789[209] = 1.0;
   out_5258459091887351789[210] = 0.0;
   out_5258459091887351789[211] = 0.0;
   out_5258459091887351789[212] = 0.0;
   out_5258459091887351789[213] = 0.0;
   out_5258459091887351789[214] = 0.0;
   out_5258459091887351789[215] = 0.0;
   out_5258459091887351789[216] = 0.0;
   out_5258459091887351789[217] = 0.0;
   out_5258459091887351789[218] = 0.0;
   out_5258459091887351789[219] = 0.0;
   out_5258459091887351789[220] = 0.0;
   out_5258459091887351789[221] = 0.0;
   out_5258459091887351789[222] = 0.0;
   out_5258459091887351789[223] = 0.0;
   out_5258459091887351789[224] = 0.0;
   out_5258459091887351789[225] = 0.0;
   out_5258459091887351789[226] = 0.0;
   out_5258459091887351789[227] = 0.0;
   out_5258459091887351789[228] = 1.0;
   out_5258459091887351789[229] = 0.0;
   out_5258459091887351789[230] = 0.0;
   out_5258459091887351789[231] = 0.0;
   out_5258459091887351789[232] = 0.0;
   out_5258459091887351789[233] = 0.0;
   out_5258459091887351789[234] = 0.0;
   out_5258459091887351789[235] = 0.0;
   out_5258459091887351789[236] = 0.0;
   out_5258459091887351789[237] = 0.0;
   out_5258459091887351789[238] = 0.0;
   out_5258459091887351789[239] = 0.0;
   out_5258459091887351789[240] = 0.0;
   out_5258459091887351789[241] = 0.0;
   out_5258459091887351789[242] = 0.0;
   out_5258459091887351789[243] = 0.0;
   out_5258459091887351789[244] = 0.0;
   out_5258459091887351789[245] = 0.0;
   out_5258459091887351789[246] = 0.0;
   out_5258459091887351789[247] = 1.0;
   out_5258459091887351789[248] = 0.0;
   out_5258459091887351789[249] = 0.0;
   out_5258459091887351789[250] = 0.0;
   out_5258459091887351789[251] = 0.0;
   out_5258459091887351789[252] = 0.0;
   out_5258459091887351789[253] = 0.0;
   out_5258459091887351789[254] = 0.0;
   out_5258459091887351789[255] = 0.0;
   out_5258459091887351789[256] = 0.0;
   out_5258459091887351789[257] = 0.0;
   out_5258459091887351789[258] = 0.0;
   out_5258459091887351789[259] = 0.0;
   out_5258459091887351789[260] = 0.0;
   out_5258459091887351789[261] = 0.0;
   out_5258459091887351789[262] = 0.0;
   out_5258459091887351789[263] = 0.0;
   out_5258459091887351789[264] = 0.0;
   out_5258459091887351789[265] = 0.0;
   out_5258459091887351789[266] = 1.0;
   out_5258459091887351789[267] = 0.0;
   out_5258459091887351789[268] = 0.0;
   out_5258459091887351789[269] = 0.0;
   out_5258459091887351789[270] = 0.0;
   out_5258459091887351789[271] = 0.0;
   out_5258459091887351789[272] = 0.0;
   out_5258459091887351789[273] = 0.0;
   out_5258459091887351789[274] = 0.0;
   out_5258459091887351789[275] = 0.0;
   out_5258459091887351789[276] = 0.0;
   out_5258459091887351789[277] = 0.0;
   out_5258459091887351789[278] = 0.0;
   out_5258459091887351789[279] = 0.0;
   out_5258459091887351789[280] = 0.0;
   out_5258459091887351789[281] = 0.0;
   out_5258459091887351789[282] = 0.0;
   out_5258459091887351789[283] = 0.0;
   out_5258459091887351789[284] = 0.0;
   out_5258459091887351789[285] = 1.0;
   out_5258459091887351789[286] = 0.0;
   out_5258459091887351789[287] = 0.0;
   out_5258459091887351789[288] = 0.0;
   out_5258459091887351789[289] = 0.0;
   out_5258459091887351789[290] = 0.0;
   out_5258459091887351789[291] = 0.0;
   out_5258459091887351789[292] = 0.0;
   out_5258459091887351789[293] = 0.0;
   out_5258459091887351789[294] = 0.0;
   out_5258459091887351789[295] = 0.0;
   out_5258459091887351789[296] = 0.0;
   out_5258459091887351789[297] = 0.0;
   out_5258459091887351789[298] = 0.0;
   out_5258459091887351789[299] = 0.0;
   out_5258459091887351789[300] = 0.0;
   out_5258459091887351789[301] = 0.0;
   out_5258459091887351789[302] = 0.0;
   out_5258459091887351789[303] = 0.0;
   out_5258459091887351789[304] = 1.0;
   out_5258459091887351789[305] = 0.0;
   out_5258459091887351789[306] = 0.0;
   out_5258459091887351789[307] = 0.0;
   out_5258459091887351789[308] = 0.0;
   out_5258459091887351789[309] = 0.0;
   out_5258459091887351789[310] = 0.0;
   out_5258459091887351789[311] = 0.0;
   out_5258459091887351789[312] = 0.0;
   out_5258459091887351789[313] = 0.0;
   out_5258459091887351789[314] = 0.0;
   out_5258459091887351789[315] = 0.0;
   out_5258459091887351789[316] = 0.0;
   out_5258459091887351789[317] = 0.0;
   out_5258459091887351789[318] = 0.0;
   out_5258459091887351789[319] = 0.0;
   out_5258459091887351789[320] = 0.0;
   out_5258459091887351789[321] = 0.0;
   out_5258459091887351789[322] = 0.0;
   out_5258459091887351789[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_6465054850404689745) {
   out_6465054850404689745[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_6465054850404689745[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_6465054850404689745[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_6465054850404689745[3] = dt*state[12] + state[3];
   out_6465054850404689745[4] = dt*state[13] + state[4];
   out_6465054850404689745[5] = dt*state[14] + state[5];
   out_6465054850404689745[6] = state[6];
   out_6465054850404689745[7] = state[7];
   out_6465054850404689745[8] = state[8];
   out_6465054850404689745[9] = state[9];
   out_6465054850404689745[10] = state[10];
   out_6465054850404689745[11] = state[11];
   out_6465054850404689745[12] = state[12];
   out_6465054850404689745[13] = state[13];
   out_6465054850404689745[14] = state[14];
   out_6465054850404689745[15] = state[15];
   out_6465054850404689745[16] = state[16];
   out_6465054850404689745[17] = state[17];
}
void F_fun(double *state, double dt, double *out_7787636662603076404) {
   out_7787636662603076404[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7787636662603076404[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7787636662603076404[2] = 0;
   out_7787636662603076404[3] = 0;
   out_7787636662603076404[4] = 0;
   out_7787636662603076404[5] = 0;
   out_7787636662603076404[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7787636662603076404[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7787636662603076404[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7787636662603076404[9] = 0;
   out_7787636662603076404[10] = 0;
   out_7787636662603076404[11] = 0;
   out_7787636662603076404[12] = 0;
   out_7787636662603076404[13] = 0;
   out_7787636662603076404[14] = 0;
   out_7787636662603076404[15] = 0;
   out_7787636662603076404[16] = 0;
   out_7787636662603076404[17] = 0;
   out_7787636662603076404[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7787636662603076404[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7787636662603076404[20] = 0;
   out_7787636662603076404[21] = 0;
   out_7787636662603076404[22] = 0;
   out_7787636662603076404[23] = 0;
   out_7787636662603076404[24] = 0;
   out_7787636662603076404[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7787636662603076404[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7787636662603076404[27] = 0;
   out_7787636662603076404[28] = 0;
   out_7787636662603076404[29] = 0;
   out_7787636662603076404[30] = 0;
   out_7787636662603076404[31] = 0;
   out_7787636662603076404[32] = 0;
   out_7787636662603076404[33] = 0;
   out_7787636662603076404[34] = 0;
   out_7787636662603076404[35] = 0;
   out_7787636662603076404[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7787636662603076404[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7787636662603076404[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7787636662603076404[39] = 0;
   out_7787636662603076404[40] = 0;
   out_7787636662603076404[41] = 0;
   out_7787636662603076404[42] = 0;
   out_7787636662603076404[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7787636662603076404[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7787636662603076404[45] = 0;
   out_7787636662603076404[46] = 0;
   out_7787636662603076404[47] = 0;
   out_7787636662603076404[48] = 0;
   out_7787636662603076404[49] = 0;
   out_7787636662603076404[50] = 0;
   out_7787636662603076404[51] = 0;
   out_7787636662603076404[52] = 0;
   out_7787636662603076404[53] = 0;
   out_7787636662603076404[54] = 0;
   out_7787636662603076404[55] = 0;
   out_7787636662603076404[56] = 0;
   out_7787636662603076404[57] = 1;
   out_7787636662603076404[58] = 0;
   out_7787636662603076404[59] = 0;
   out_7787636662603076404[60] = 0;
   out_7787636662603076404[61] = 0;
   out_7787636662603076404[62] = 0;
   out_7787636662603076404[63] = 0;
   out_7787636662603076404[64] = 0;
   out_7787636662603076404[65] = 0;
   out_7787636662603076404[66] = dt;
   out_7787636662603076404[67] = 0;
   out_7787636662603076404[68] = 0;
   out_7787636662603076404[69] = 0;
   out_7787636662603076404[70] = 0;
   out_7787636662603076404[71] = 0;
   out_7787636662603076404[72] = 0;
   out_7787636662603076404[73] = 0;
   out_7787636662603076404[74] = 0;
   out_7787636662603076404[75] = 0;
   out_7787636662603076404[76] = 1;
   out_7787636662603076404[77] = 0;
   out_7787636662603076404[78] = 0;
   out_7787636662603076404[79] = 0;
   out_7787636662603076404[80] = 0;
   out_7787636662603076404[81] = 0;
   out_7787636662603076404[82] = 0;
   out_7787636662603076404[83] = 0;
   out_7787636662603076404[84] = 0;
   out_7787636662603076404[85] = dt;
   out_7787636662603076404[86] = 0;
   out_7787636662603076404[87] = 0;
   out_7787636662603076404[88] = 0;
   out_7787636662603076404[89] = 0;
   out_7787636662603076404[90] = 0;
   out_7787636662603076404[91] = 0;
   out_7787636662603076404[92] = 0;
   out_7787636662603076404[93] = 0;
   out_7787636662603076404[94] = 0;
   out_7787636662603076404[95] = 1;
   out_7787636662603076404[96] = 0;
   out_7787636662603076404[97] = 0;
   out_7787636662603076404[98] = 0;
   out_7787636662603076404[99] = 0;
   out_7787636662603076404[100] = 0;
   out_7787636662603076404[101] = 0;
   out_7787636662603076404[102] = 0;
   out_7787636662603076404[103] = 0;
   out_7787636662603076404[104] = dt;
   out_7787636662603076404[105] = 0;
   out_7787636662603076404[106] = 0;
   out_7787636662603076404[107] = 0;
   out_7787636662603076404[108] = 0;
   out_7787636662603076404[109] = 0;
   out_7787636662603076404[110] = 0;
   out_7787636662603076404[111] = 0;
   out_7787636662603076404[112] = 0;
   out_7787636662603076404[113] = 0;
   out_7787636662603076404[114] = 1;
   out_7787636662603076404[115] = 0;
   out_7787636662603076404[116] = 0;
   out_7787636662603076404[117] = 0;
   out_7787636662603076404[118] = 0;
   out_7787636662603076404[119] = 0;
   out_7787636662603076404[120] = 0;
   out_7787636662603076404[121] = 0;
   out_7787636662603076404[122] = 0;
   out_7787636662603076404[123] = 0;
   out_7787636662603076404[124] = 0;
   out_7787636662603076404[125] = 0;
   out_7787636662603076404[126] = 0;
   out_7787636662603076404[127] = 0;
   out_7787636662603076404[128] = 0;
   out_7787636662603076404[129] = 0;
   out_7787636662603076404[130] = 0;
   out_7787636662603076404[131] = 0;
   out_7787636662603076404[132] = 0;
   out_7787636662603076404[133] = 1;
   out_7787636662603076404[134] = 0;
   out_7787636662603076404[135] = 0;
   out_7787636662603076404[136] = 0;
   out_7787636662603076404[137] = 0;
   out_7787636662603076404[138] = 0;
   out_7787636662603076404[139] = 0;
   out_7787636662603076404[140] = 0;
   out_7787636662603076404[141] = 0;
   out_7787636662603076404[142] = 0;
   out_7787636662603076404[143] = 0;
   out_7787636662603076404[144] = 0;
   out_7787636662603076404[145] = 0;
   out_7787636662603076404[146] = 0;
   out_7787636662603076404[147] = 0;
   out_7787636662603076404[148] = 0;
   out_7787636662603076404[149] = 0;
   out_7787636662603076404[150] = 0;
   out_7787636662603076404[151] = 0;
   out_7787636662603076404[152] = 1;
   out_7787636662603076404[153] = 0;
   out_7787636662603076404[154] = 0;
   out_7787636662603076404[155] = 0;
   out_7787636662603076404[156] = 0;
   out_7787636662603076404[157] = 0;
   out_7787636662603076404[158] = 0;
   out_7787636662603076404[159] = 0;
   out_7787636662603076404[160] = 0;
   out_7787636662603076404[161] = 0;
   out_7787636662603076404[162] = 0;
   out_7787636662603076404[163] = 0;
   out_7787636662603076404[164] = 0;
   out_7787636662603076404[165] = 0;
   out_7787636662603076404[166] = 0;
   out_7787636662603076404[167] = 0;
   out_7787636662603076404[168] = 0;
   out_7787636662603076404[169] = 0;
   out_7787636662603076404[170] = 0;
   out_7787636662603076404[171] = 1;
   out_7787636662603076404[172] = 0;
   out_7787636662603076404[173] = 0;
   out_7787636662603076404[174] = 0;
   out_7787636662603076404[175] = 0;
   out_7787636662603076404[176] = 0;
   out_7787636662603076404[177] = 0;
   out_7787636662603076404[178] = 0;
   out_7787636662603076404[179] = 0;
   out_7787636662603076404[180] = 0;
   out_7787636662603076404[181] = 0;
   out_7787636662603076404[182] = 0;
   out_7787636662603076404[183] = 0;
   out_7787636662603076404[184] = 0;
   out_7787636662603076404[185] = 0;
   out_7787636662603076404[186] = 0;
   out_7787636662603076404[187] = 0;
   out_7787636662603076404[188] = 0;
   out_7787636662603076404[189] = 0;
   out_7787636662603076404[190] = 1;
   out_7787636662603076404[191] = 0;
   out_7787636662603076404[192] = 0;
   out_7787636662603076404[193] = 0;
   out_7787636662603076404[194] = 0;
   out_7787636662603076404[195] = 0;
   out_7787636662603076404[196] = 0;
   out_7787636662603076404[197] = 0;
   out_7787636662603076404[198] = 0;
   out_7787636662603076404[199] = 0;
   out_7787636662603076404[200] = 0;
   out_7787636662603076404[201] = 0;
   out_7787636662603076404[202] = 0;
   out_7787636662603076404[203] = 0;
   out_7787636662603076404[204] = 0;
   out_7787636662603076404[205] = 0;
   out_7787636662603076404[206] = 0;
   out_7787636662603076404[207] = 0;
   out_7787636662603076404[208] = 0;
   out_7787636662603076404[209] = 1;
   out_7787636662603076404[210] = 0;
   out_7787636662603076404[211] = 0;
   out_7787636662603076404[212] = 0;
   out_7787636662603076404[213] = 0;
   out_7787636662603076404[214] = 0;
   out_7787636662603076404[215] = 0;
   out_7787636662603076404[216] = 0;
   out_7787636662603076404[217] = 0;
   out_7787636662603076404[218] = 0;
   out_7787636662603076404[219] = 0;
   out_7787636662603076404[220] = 0;
   out_7787636662603076404[221] = 0;
   out_7787636662603076404[222] = 0;
   out_7787636662603076404[223] = 0;
   out_7787636662603076404[224] = 0;
   out_7787636662603076404[225] = 0;
   out_7787636662603076404[226] = 0;
   out_7787636662603076404[227] = 0;
   out_7787636662603076404[228] = 1;
   out_7787636662603076404[229] = 0;
   out_7787636662603076404[230] = 0;
   out_7787636662603076404[231] = 0;
   out_7787636662603076404[232] = 0;
   out_7787636662603076404[233] = 0;
   out_7787636662603076404[234] = 0;
   out_7787636662603076404[235] = 0;
   out_7787636662603076404[236] = 0;
   out_7787636662603076404[237] = 0;
   out_7787636662603076404[238] = 0;
   out_7787636662603076404[239] = 0;
   out_7787636662603076404[240] = 0;
   out_7787636662603076404[241] = 0;
   out_7787636662603076404[242] = 0;
   out_7787636662603076404[243] = 0;
   out_7787636662603076404[244] = 0;
   out_7787636662603076404[245] = 0;
   out_7787636662603076404[246] = 0;
   out_7787636662603076404[247] = 1;
   out_7787636662603076404[248] = 0;
   out_7787636662603076404[249] = 0;
   out_7787636662603076404[250] = 0;
   out_7787636662603076404[251] = 0;
   out_7787636662603076404[252] = 0;
   out_7787636662603076404[253] = 0;
   out_7787636662603076404[254] = 0;
   out_7787636662603076404[255] = 0;
   out_7787636662603076404[256] = 0;
   out_7787636662603076404[257] = 0;
   out_7787636662603076404[258] = 0;
   out_7787636662603076404[259] = 0;
   out_7787636662603076404[260] = 0;
   out_7787636662603076404[261] = 0;
   out_7787636662603076404[262] = 0;
   out_7787636662603076404[263] = 0;
   out_7787636662603076404[264] = 0;
   out_7787636662603076404[265] = 0;
   out_7787636662603076404[266] = 1;
   out_7787636662603076404[267] = 0;
   out_7787636662603076404[268] = 0;
   out_7787636662603076404[269] = 0;
   out_7787636662603076404[270] = 0;
   out_7787636662603076404[271] = 0;
   out_7787636662603076404[272] = 0;
   out_7787636662603076404[273] = 0;
   out_7787636662603076404[274] = 0;
   out_7787636662603076404[275] = 0;
   out_7787636662603076404[276] = 0;
   out_7787636662603076404[277] = 0;
   out_7787636662603076404[278] = 0;
   out_7787636662603076404[279] = 0;
   out_7787636662603076404[280] = 0;
   out_7787636662603076404[281] = 0;
   out_7787636662603076404[282] = 0;
   out_7787636662603076404[283] = 0;
   out_7787636662603076404[284] = 0;
   out_7787636662603076404[285] = 1;
   out_7787636662603076404[286] = 0;
   out_7787636662603076404[287] = 0;
   out_7787636662603076404[288] = 0;
   out_7787636662603076404[289] = 0;
   out_7787636662603076404[290] = 0;
   out_7787636662603076404[291] = 0;
   out_7787636662603076404[292] = 0;
   out_7787636662603076404[293] = 0;
   out_7787636662603076404[294] = 0;
   out_7787636662603076404[295] = 0;
   out_7787636662603076404[296] = 0;
   out_7787636662603076404[297] = 0;
   out_7787636662603076404[298] = 0;
   out_7787636662603076404[299] = 0;
   out_7787636662603076404[300] = 0;
   out_7787636662603076404[301] = 0;
   out_7787636662603076404[302] = 0;
   out_7787636662603076404[303] = 0;
   out_7787636662603076404[304] = 1;
   out_7787636662603076404[305] = 0;
   out_7787636662603076404[306] = 0;
   out_7787636662603076404[307] = 0;
   out_7787636662603076404[308] = 0;
   out_7787636662603076404[309] = 0;
   out_7787636662603076404[310] = 0;
   out_7787636662603076404[311] = 0;
   out_7787636662603076404[312] = 0;
   out_7787636662603076404[313] = 0;
   out_7787636662603076404[314] = 0;
   out_7787636662603076404[315] = 0;
   out_7787636662603076404[316] = 0;
   out_7787636662603076404[317] = 0;
   out_7787636662603076404[318] = 0;
   out_7787636662603076404[319] = 0;
   out_7787636662603076404[320] = 0;
   out_7787636662603076404[321] = 0;
   out_7787636662603076404[322] = 0;
   out_7787636662603076404[323] = 1;
}
void h_4(double *state, double *unused, double *out_6388124336911847205) {
   out_6388124336911847205[0] = state[6] + state[9];
   out_6388124336911847205[1] = state[7] + state[10];
   out_6388124336911847205[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4504298089832639182) {
   out_4504298089832639182[0] = 0;
   out_4504298089832639182[1] = 0;
   out_4504298089832639182[2] = 0;
   out_4504298089832639182[3] = 0;
   out_4504298089832639182[4] = 0;
   out_4504298089832639182[5] = 0;
   out_4504298089832639182[6] = 1;
   out_4504298089832639182[7] = 0;
   out_4504298089832639182[8] = 0;
   out_4504298089832639182[9] = 1;
   out_4504298089832639182[10] = 0;
   out_4504298089832639182[11] = 0;
   out_4504298089832639182[12] = 0;
   out_4504298089832639182[13] = 0;
   out_4504298089832639182[14] = 0;
   out_4504298089832639182[15] = 0;
   out_4504298089832639182[16] = 0;
   out_4504298089832639182[17] = 0;
   out_4504298089832639182[18] = 0;
   out_4504298089832639182[19] = 0;
   out_4504298089832639182[20] = 0;
   out_4504298089832639182[21] = 0;
   out_4504298089832639182[22] = 0;
   out_4504298089832639182[23] = 0;
   out_4504298089832639182[24] = 0;
   out_4504298089832639182[25] = 1;
   out_4504298089832639182[26] = 0;
   out_4504298089832639182[27] = 0;
   out_4504298089832639182[28] = 1;
   out_4504298089832639182[29] = 0;
   out_4504298089832639182[30] = 0;
   out_4504298089832639182[31] = 0;
   out_4504298089832639182[32] = 0;
   out_4504298089832639182[33] = 0;
   out_4504298089832639182[34] = 0;
   out_4504298089832639182[35] = 0;
   out_4504298089832639182[36] = 0;
   out_4504298089832639182[37] = 0;
   out_4504298089832639182[38] = 0;
   out_4504298089832639182[39] = 0;
   out_4504298089832639182[40] = 0;
   out_4504298089832639182[41] = 0;
   out_4504298089832639182[42] = 0;
   out_4504298089832639182[43] = 0;
   out_4504298089832639182[44] = 1;
   out_4504298089832639182[45] = 0;
   out_4504298089832639182[46] = 0;
   out_4504298089832639182[47] = 1;
   out_4504298089832639182[48] = 0;
   out_4504298089832639182[49] = 0;
   out_4504298089832639182[50] = 0;
   out_4504298089832639182[51] = 0;
   out_4504298089832639182[52] = 0;
   out_4504298089832639182[53] = 0;
}
void h_10(double *state, double *unused, double *out_8654929017072647193) {
   out_8654929017072647193[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_8654929017072647193[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_8654929017072647193[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_1603686663542064732) {
   out_1603686663542064732[0] = 0;
   out_1603686663542064732[1] = 9.8100000000000005*cos(state[1]);
   out_1603686663542064732[2] = 0;
   out_1603686663542064732[3] = 0;
   out_1603686663542064732[4] = -state[8];
   out_1603686663542064732[5] = state[7];
   out_1603686663542064732[6] = 0;
   out_1603686663542064732[7] = state[5];
   out_1603686663542064732[8] = -state[4];
   out_1603686663542064732[9] = 0;
   out_1603686663542064732[10] = 0;
   out_1603686663542064732[11] = 0;
   out_1603686663542064732[12] = 1;
   out_1603686663542064732[13] = 0;
   out_1603686663542064732[14] = 0;
   out_1603686663542064732[15] = 1;
   out_1603686663542064732[16] = 0;
   out_1603686663542064732[17] = 0;
   out_1603686663542064732[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_1603686663542064732[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_1603686663542064732[20] = 0;
   out_1603686663542064732[21] = state[8];
   out_1603686663542064732[22] = 0;
   out_1603686663542064732[23] = -state[6];
   out_1603686663542064732[24] = -state[5];
   out_1603686663542064732[25] = 0;
   out_1603686663542064732[26] = state[3];
   out_1603686663542064732[27] = 0;
   out_1603686663542064732[28] = 0;
   out_1603686663542064732[29] = 0;
   out_1603686663542064732[30] = 0;
   out_1603686663542064732[31] = 1;
   out_1603686663542064732[32] = 0;
   out_1603686663542064732[33] = 0;
   out_1603686663542064732[34] = 1;
   out_1603686663542064732[35] = 0;
   out_1603686663542064732[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_1603686663542064732[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_1603686663542064732[38] = 0;
   out_1603686663542064732[39] = -state[7];
   out_1603686663542064732[40] = state[6];
   out_1603686663542064732[41] = 0;
   out_1603686663542064732[42] = state[4];
   out_1603686663542064732[43] = -state[3];
   out_1603686663542064732[44] = 0;
   out_1603686663542064732[45] = 0;
   out_1603686663542064732[46] = 0;
   out_1603686663542064732[47] = 0;
   out_1603686663542064732[48] = 0;
   out_1603686663542064732[49] = 0;
   out_1603686663542064732[50] = 1;
   out_1603686663542064732[51] = 0;
   out_1603686663542064732[52] = 0;
   out_1603686663542064732[53] = 1;
}
void h_13(double *state, double *unused, double *out_3810489520400261458) {
   out_3810489520400261458[0] = state[3];
   out_3810489520400261458[1] = state[4];
   out_3810489520400261458[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1292024264500306381) {
   out_1292024264500306381[0] = 0;
   out_1292024264500306381[1] = 0;
   out_1292024264500306381[2] = 0;
   out_1292024264500306381[3] = 1;
   out_1292024264500306381[4] = 0;
   out_1292024264500306381[5] = 0;
   out_1292024264500306381[6] = 0;
   out_1292024264500306381[7] = 0;
   out_1292024264500306381[8] = 0;
   out_1292024264500306381[9] = 0;
   out_1292024264500306381[10] = 0;
   out_1292024264500306381[11] = 0;
   out_1292024264500306381[12] = 0;
   out_1292024264500306381[13] = 0;
   out_1292024264500306381[14] = 0;
   out_1292024264500306381[15] = 0;
   out_1292024264500306381[16] = 0;
   out_1292024264500306381[17] = 0;
   out_1292024264500306381[18] = 0;
   out_1292024264500306381[19] = 0;
   out_1292024264500306381[20] = 0;
   out_1292024264500306381[21] = 0;
   out_1292024264500306381[22] = 1;
   out_1292024264500306381[23] = 0;
   out_1292024264500306381[24] = 0;
   out_1292024264500306381[25] = 0;
   out_1292024264500306381[26] = 0;
   out_1292024264500306381[27] = 0;
   out_1292024264500306381[28] = 0;
   out_1292024264500306381[29] = 0;
   out_1292024264500306381[30] = 0;
   out_1292024264500306381[31] = 0;
   out_1292024264500306381[32] = 0;
   out_1292024264500306381[33] = 0;
   out_1292024264500306381[34] = 0;
   out_1292024264500306381[35] = 0;
   out_1292024264500306381[36] = 0;
   out_1292024264500306381[37] = 0;
   out_1292024264500306381[38] = 0;
   out_1292024264500306381[39] = 0;
   out_1292024264500306381[40] = 0;
   out_1292024264500306381[41] = 1;
   out_1292024264500306381[42] = 0;
   out_1292024264500306381[43] = 0;
   out_1292024264500306381[44] = 0;
   out_1292024264500306381[45] = 0;
   out_1292024264500306381[46] = 0;
   out_1292024264500306381[47] = 0;
   out_1292024264500306381[48] = 0;
   out_1292024264500306381[49] = 0;
   out_1292024264500306381[50] = 0;
   out_1292024264500306381[51] = 0;
   out_1292024264500306381[52] = 0;
   out_1292024264500306381[53] = 0;
}
void h_14(double *state, double *unused, double *out_5932475143850498249) {
   out_5932475143850498249[0] = state[6];
   out_5932475143850498249[1] = state[7];
   out_5932475143850498249[2] = state[8];
}
void H_14(double *state, double *unused, double *out_541057233493154653) {
   out_541057233493154653[0] = 0;
   out_541057233493154653[1] = 0;
   out_541057233493154653[2] = 0;
   out_541057233493154653[3] = 0;
   out_541057233493154653[4] = 0;
   out_541057233493154653[5] = 0;
   out_541057233493154653[6] = 1;
   out_541057233493154653[7] = 0;
   out_541057233493154653[8] = 0;
   out_541057233493154653[9] = 0;
   out_541057233493154653[10] = 0;
   out_541057233493154653[11] = 0;
   out_541057233493154653[12] = 0;
   out_541057233493154653[13] = 0;
   out_541057233493154653[14] = 0;
   out_541057233493154653[15] = 0;
   out_541057233493154653[16] = 0;
   out_541057233493154653[17] = 0;
   out_541057233493154653[18] = 0;
   out_541057233493154653[19] = 0;
   out_541057233493154653[20] = 0;
   out_541057233493154653[21] = 0;
   out_541057233493154653[22] = 0;
   out_541057233493154653[23] = 0;
   out_541057233493154653[24] = 0;
   out_541057233493154653[25] = 1;
   out_541057233493154653[26] = 0;
   out_541057233493154653[27] = 0;
   out_541057233493154653[28] = 0;
   out_541057233493154653[29] = 0;
   out_541057233493154653[30] = 0;
   out_541057233493154653[31] = 0;
   out_541057233493154653[32] = 0;
   out_541057233493154653[33] = 0;
   out_541057233493154653[34] = 0;
   out_541057233493154653[35] = 0;
   out_541057233493154653[36] = 0;
   out_541057233493154653[37] = 0;
   out_541057233493154653[38] = 0;
   out_541057233493154653[39] = 0;
   out_541057233493154653[40] = 0;
   out_541057233493154653[41] = 0;
   out_541057233493154653[42] = 0;
   out_541057233493154653[43] = 0;
   out_541057233493154653[44] = 1;
   out_541057233493154653[45] = 0;
   out_541057233493154653[46] = 0;
   out_541057233493154653[47] = 0;
   out_541057233493154653[48] = 0;
   out_541057233493154653[49] = 0;
   out_541057233493154653[50] = 0;
   out_541057233493154653[51] = 0;
   out_541057233493154653[52] = 0;
   out_541057233493154653[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_3060945647413172151) {
  err_fun(nom_x, delta_x, out_3060945647413172151);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_1090212893188142520) {
  inv_err_fun(nom_x, true_x, out_1090212893188142520);
}
void pose_H_mod_fun(double *state, double *out_5258459091887351789) {
  H_mod_fun(state, out_5258459091887351789);
}
void pose_f_fun(double *state, double dt, double *out_6465054850404689745) {
  f_fun(state,  dt, out_6465054850404689745);
}
void pose_F_fun(double *state, double dt, double *out_7787636662603076404) {
  F_fun(state,  dt, out_7787636662603076404);
}
void pose_h_4(double *state, double *unused, double *out_6388124336911847205) {
  h_4(state, unused, out_6388124336911847205);
}
void pose_H_4(double *state, double *unused, double *out_4504298089832639182) {
  H_4(state, unused, out_4504298089832639182);
}
void pose_h_10(double *state, double *unused, double *out_8654929017072647193) {
  h_10(state, unused, out_8654929017072647193);
}
void pose_H_10(double *state, double *unused, double *out_1603686663542064732) {
  H_10(state, unused, out_1603686663542064732);
}
void pose_h_13(double *state, double *unused, double *out_3810489520400261458) {
  h_13(state, unused, out_3810489520400261458);
}
void pose_H_13(double *state, double *unused, double *out_1292024264500306381) {
  H_13(state, unused, out_1292024264500306381);
}
void pose_h_14(double *state, double *unused, double *out_5932475143850498249) {
  h_14(state, unused, out_5932475143850498249);
}
void pose_H_14(double *state, double *unused, double *out_541057233493154653) {
  H_14(state, unused, out_541057233493154653);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)

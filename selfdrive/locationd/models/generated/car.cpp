#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.13.2                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4236733633335182969) {
   out_4236733633335182969[0] = delta_x[0] + nom_x[0];
   out_4236733633335182969[1] = delta_x[1] + nom_x[1];
   out_4236733633335182969[2] = delta_x[2] + nom_x[2];
   out_4236733633335182969[3] = delta_x[3] + nom_x[3];
   out_4236733633335182969[4] = delta_x[4] + nom_x[4];
   out_4236733633335182969[5] = delta_x[5] + nom_x[5];
   out_4236733633335182969[6] = delta_x[6] + nom_x[6];
   out_4236733633335182969[7] = delta_x[7] + nom_x[7];
   out_4236733633335182969[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1312881399455535811) {
   out_1312881399455535811[0] = -nom_x[0] + true_x[0];
   out_1312881399455535811[1] = -nom_x[1] + true_x[1];
   out_1312881399455535811[2] = -nom_x[2] + true_x[2];
   out_1312881399455535811[3] = -nom_x[3] + true_x[3];
   out_1312881399455535811[4] = -nom_x[4] + true_x[4];
   out_1312881399455535811[5] = -nom_x[5] + true_x[5];
   out_1312881399455535811[6] = -nom_x[6] + true_x[6];
   out_1312881399455535811[7] = -nom_x[7] + true_x[7];
   out_1312881399455535811[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8580061836990555726) {
   out_8580061836990555726[0] = 1.0;
   out_8580061836990555726[1] = 0.0;
   out_8580061836990555726[2] = 0.0;
   out_8580061836990555726[3] = 0.0;
   out_8580061836990555726[4] = 0.0;
   out_8580061836990555726[5] = 0.0;
   out_8580061836990555726[6] = 0.0;
   out_8580061836990555726[7] = 0.0;
   out_8580061836990555726[8] = 0.0;
   out_8580061836990555726[9] = 0.0;
   out_8580061836990555726[10] = 1.0;
   out_8580061836990555726[11] = 0.0;
   out_8580061836990555726[12] = 0.0;
   out_8580061836990555726[13] = 0.0;
   out_8580061836990555726[14] = 0.0;
   out_8580061836990555726[15] = 0.0;
   out_8580061836990555726[16] = 0.0;
   out_8580061836990555726[17] = 0.0;
   out_8580061836990555726[18] = 0.0;
   out_8580061836990555726[19] = 0.0;
   out_8580061836990555726[20] = 1.0;
   out_8580061836990555726[21] = 0.0;
   out_8580061836990555726[22] = 0.0;
   out_8580061836990555726[23] = 0.0;
   out_8580061836990555726[24] = 0.0;
   out_8580061836990555726[25] = 0.0;
   out_8580061836990555726[26] = 0.0;
   out_8580061836990555726[27] = 0.0;
   out_8580061836990555726[28] = 0.0;
   out_8580061836990555726[29] = 0.0;
   out_8580061836990555726[30] = 1.0;
   out_8580061836990555726[31] = 0.0;
   out_8580061836990555726[32] = 0.0;
   out_8580061836990555726[33] = 0.0;
   out_8580061836990555726[34] = 0.0;
   out_8580061836990555726[35] = 0.0;
   out_8580061836990555726[36] = 0.0;
   out_8580061836990555726[37] = 0.0;
   out_8580061836990555726[38] = 0.0;
   out_8580061836990555726[39] = 0.0;
   out_8580061836990555726[40] = 1.0;
   out_8580061836990555726[41] = 0.0;
   out_8580061836990555726[42] = 0.0;
   out_8580061836990555726[43] = 0.0;
   out_8580061836990555726[44] = 0.0;
   out_8580061836990555726[45] = 0.0;
   out_8580061836990555726[46] = 0.0;
   out_8580061836990555726[47] = 0.0;
   out_8580061836990555726[48] = 0.0;
   out_8580061836990555726[49] = 0.0;
   out_8580061836990555726[50] = 1.0;
   out_8580061836990555726[51] = 0.0;
   out_8580061836990555726[52] = 0.0;
   out_8580061836990555726[53] = 0.0;
   out_8580061836990555726[54] = 0.0;
   out_8580061836990555726[55] = 0.0;
   out_8580061836990555726[56] = 0.0;
   out_8580061836990555726[57] = 0.0;
   out_8580061836990555726[58] = 0.0;
   out_8580061836990555726[59] = 0.0;
   out_8580061836990555726[60] = 1.0;
   out_8580061836990555726[61] = 0.0;
   out_8580061836990555726[62] = 0.0;
   out_8580061836990555726[63] = 0.0;
   out_8580061836990555726[64] = 0.0;
   out_8580061836990555726[65] = 0.0;
   out_8580061836990555726[66] = 0.0;
   out_8580061836990555726[67] = 0.0;
   out_8580061836990555726[68] = 0.0;
   out_8580061836990555726[69] = 0.0;
   out_8580061836990555726[70] = 1.0;
   out_8580061836990555726[71] = 0.0;
   out_8580061836990555726[72] = 0.0;
   out_8580061836990555726[73] = 0.0;
   out_8580061836990555726[74] = 0.0;
   out_8580061836990555726[75] = 0.0;
   out_8580061836990555726[76] = 0.0;
   out_8580061836990555726[77] = 0.0;
   out_8580061836990555726[78] = 0.0;
   out_8580061836990555726[79] = 0.0;
   out_8580061836990555726[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8484422586595881408) {
   out_8484422586595881408[0] = state[0];
   out_8484422586595881408[1] = state[1];
   out_8484422586595881408[2] = state[2];
   out_8484422586595881408[3] = state[3];
   out_8484422586595881408[4] = state[4];
   out_8484422586595881408[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8484422586595881408[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8484422586595881408[7] = state[7];
   out_8484422586595881408[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7473343249845780073) {
   out_7473343249845780073[0] = 1;
   out_7473343249845780073[1] = 0;
   out_7473343249845780073[2] = 0;
   out_7473343249845780073[3] = 0;
   out_7473343249845780073[4] = 0;
   out_7473343249845780073[5] = 0;
   out_7473343249845780073[6] = 0;
   out_7473343249845780073[7] = 0;
   out_7473343249845780073[8] = 0;
   out_7473343249845780073[9] = 0;
   out_7473343249845780073[10] = 1;
   out_7473343249845780073[11] = 0;
   out_7473343249845780073[12] = 0;
   out_7473343249845780073[13] = 0;
   out_7473343249845780073[14] = 0;
   out_7473343249845780073[15] = 0;
   out_7473343249845780073[16] = 0;
   out_7473343249845780073[17] = 0;
   out_7473343249845780073[18] = 0;
   out_7473343249845780073[19] = 0;
   out_7473343249845780073[20] = 1;
   out_7473343249845780073[21] = 0;
   out_7473343249845780073[22] = 0;
   out_7473343249845780073[23] = 0;
   out_7473343249845780073[24] = 0;
   out_7473343249845780073[25] = 0;
   out_7473343249845780073[26] = 0;
   out_7473343249845780073[27] = 0;
   out_7473343249845780073[28] = 0;
   out_7473343249845780073[29] = 0;
   out_7473343249845780073[30] = 1;
   out_7473343249845780073[31] = 0;
   out_7473343249845780073[32] = 0;
   out_7473343249845780073[33] = 0;
   out_7473343249845780073[34] = 0;
   out_7473343249845780073[35] = 0;
   out_7473343249845780073[36] = 0;
   out_7473343249845780073[37] = 0;
   out_7473343249845780073[38] = 0;
   out_7473343249845780073[39] = 0;
   out_7473343249845780073[40] = 1;
   out_7473343249845780073[41] = 0;
   out_7473343249845780073[42] = 0;
   out_7473343249845780073[43] = 0;
   out_7473343249845780073[44] = 0;
   out_7473343249845780073[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7473343249845780073[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7473343249845780073[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7473343249845780073[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7473343249845780073[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7473343249845780073[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7473343249845780073[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7473343249845780073[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7473343249845780073[53] = -9.8000000000000007*dt;
   out_7473343249845780073[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7473343249845780073[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7473343249845780073[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7473343249845780073[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7473343249845780073[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7473343249845780073[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7473343249845780073[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7473343249845780073[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7473343249845780073[62] = 0;
   out_7473343249845780073[63] = 0;
   out_7473343249845780073[64] = 0;
   out_7473343249845780073[65] = 0;
   out_7473343249845780073[66] = 0;
   out_7473343249845780073[67] = 0;
   out_7473343249845780073[68] = 0;
   out_7473343249845780073[69] = 0;
   out_7473343249845780073[70] = 1;
   out_7473343249845780073[71] = 0;
   out_7473343249845780073[72] = 0;
   out_7473343249845780073[73] = 0;
   out_7473343249845780073[74] = 0;
   out_7473343249845780073[75] = 0;
   out_7473343249845780073[76] = 0;
   out_7473343249845780073[77] = 0;
   out_7473343249845780073[78] = 0;
   out_7473343249845780073[79] = 0;
   out_7473343249845780073[80] = 1;
}
void h_25(double *state, double *unused, double *out_7026256022894968781) {
   out_7026256022894968781[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3785230994062686617) {
   out_3785230994062686617[0] = 0;
   out_3785230994062686617[1] = 0;
   out_3785230994062686617[2] = 0;
   out_3785230994062686617[3] = 0;
   out_3785230994062686617[4] = 0;
   out_3785230994062686617[5] = 0;
   out_3785230994062686617[6] = 1;
   out_3785230994062686617[7] = 0;
   out_3785230994062686617[8] = 0;
}
void h_24(double *state, double *unused, double *out_3957020047654824958) {
   out_3957020047654824958[0] = state[4];
   out_3957020047654824958[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5433447893577669774) {
   out_5433447893577669774[0] = 0;
   out_5433447893577669774[1] = 0;
   out_5433447893577669774[2] = 0;
   out_5433447893577669774[3] = 0;
   out_5433447893577669774[4] = 1;
   out_5433447893577669774[5] = 0;
   out_5433447893577669774[6] = 0;
   out_5433447893577669774[7] = 0;
   out_5433447893577669774[8] = 0;
   out_5433447893577669774[9] = 0;
   out_5433447893577669774[10] = 0;
   out_5433447893577669774[11] = 0;
   out_5433447893577669774[12] = 0;
   out_5433447893577669774[13] = 0;
   out_5433447893577669774[14] = 1;
   out_5433447893577669774[15] = 0;
   out_5433447893577669774[16] = 0;
   out_5433447893577669774[17] = 0;
}
void h_30(double *state, double *unused, double *out_4453172886133550341) {
   out_4453172886133550341[0] = state[4];
}
void H_30(double *state, double *unused, double *out_742465336064921581) {
   out_742465336064921581[0] = 0;
   out_742465336064921581[1] = 0;
   out_742465336064921581[2] = 0;
   out_742465336064921581[3] = 0;
   out_742465336064921581[4] = 1;
   out_742465336064921581[5] = 0;
   out_742465336064921581[6] = 0;
   out_742465336064921581[7] = 0;
   out_742465336064921581[8] = 0;
}
void h_26(double *state, double *unused, double *out_2595705547158871215) {
   out_2595705547158871215[0] = state[7];
}
void H_26(double *state, double *unused, double *out_43727675188630393) {
   out_43727675188630393[0] = 0;
   out_43727675188630393[1] = 0;
   out_43727675188630393[2] = 0;
   out_43727675188630393[3] = 0;
   out_43727675188630393[4] = 0;
   out_43727675188630393[5] = 0;
   out_43727675188630393[6] = 0;
   out_43727675188630393[7] = 1;
   out_43727675188630393[8] = 0;
}
void h_27(double *state, double *unused, double *out_6418814783153737190) {
   out_6418814783153737190[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2917228647865346492) {
   out_2917228647865346492[0] = 0;
   out_2917228647865346492[1] = 0;
   out_2917228647865346492[2] = 0;
   out_2917228647865346492[3] = 1;
   out_2917228647865346492[4] = 0;
   out_2917228647865346492[5] = 0;
   out_2917228647865346492[6] = 0;
   out_2917228647865346492[7] = 0;
   out_2917228647865346492[8] = 0;
}
void h_29(double *state, double *unused, double *out_4264664033735141985) {
   out_4264664033735141985[0] = state[1];
}
void H_29(double *state, double *unused, double *out_232233991750529397) {
   out_232233991750529397[0] = 0;
   out_232233991750529397[1] = 1;
   out_232233991750529397[2] = 0;
   out_232233991750529397[3] = 0;
   out_232233991750529397[4] = 0;
   out_232233991750529397[5] = 0;
   out_232233991750529397[6] = 0;
   out_232233991750529397[7] = 0;
   out_232233991750529397[8] = 0;
}
void h_28(double *state, double *unused, double *out_5628887773141965280) {
   out_5628887773141965280[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5314633008820059971) {
   out_5314633008820059971[0] = 1;
   out_5314633008820059971[1] = 0;
   out_5314633008820059971[2] = 0;
   out_5314633008820059971[3] = 0;
   out_5314633008820059971[4] = 0;
   out_5314633008820059971[5] = 0;
   out_5314633008820059971[6] = 0;
   out_5314633008820059971[7] = 0;
   out_5314633008820059971[8] = 0;
}
void h_31(double *state, double *unused, double *out_3164572546466467129) {
   out_3164572546466467129[0] = state[8];
}
void H_31(double *state, double *unused, double *out_582480427044721083) {
   out_582480427044721083[0] = 0;
   out_582480427044721083[1] = 0;
   out_582480427044721083[2] = 0;
   out_582480427044721083[3] = 0;
   out_582480427044721083[4] = 0;
   out_582480427044721083[5] = 0;
   out_582480427044721083[6] = 0;
   out_582480427044721083[7] = 0;
   out_582480427044721083[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_4236733633335182969) {
  err_fun(nom_x, delta_x, out_4236733633335182969);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1312881399455535811) {
  inv_err_fun(nom_x, true_x, out_1312881399455535811);
}
void car_H_mod_fun(double *state, double *out_8580061836990555726) {
  H_mod_fun(state, out_8580061836990555726);
}
void car_f_fun(double *state, double dt, double *out_8484422586595881408) {
  f_fun(state,  dt, out_8484422586595881408);
}
void car_F_fun(double *state, double dt, double *out_7473343249845780073) {
  F_fun(state,  dt, out_7473343249845780073);
}
void car_h_25(double *state, double *unused, double *out_7026256022894968781) {
  h_25(state, unused, out_7026256022894968781);
}
void car_H_25(double *state, double *unused, double *out_3785230994062686617) {
  H_25(state, unused, out_3785230994062686617);
}
void car_h_24(double *state, double *unused, double *out_3957020047654824958) {
  h_24(state, unused, out_3957020047654824958);
}
void car_H_24(double *state, double *unused, double *out_5433447893577669774) {
  H_24(state, unused, out_5433447893577669774);
}
void car_h_30(double *state, double *unused, double *out_4453172886133550341) {
  h_30(state, unused, out_4453172886133550341);
}
void car_H_30(double *state, double *unused, double *out_742465336064921581) {
  H_30(state, unused, out_742465336064921581);
}
void car_h_26(double *state, double *unused, double *out_2595705547158871215) {
  h_26(state, unused, out_2595705547158871215);
}
void car_H_26(double *state, double *unused, double *out_43727675188630393) {
  H_26(state, unused, out_43727675188630393);
}
void car_h_27(double *state, double *unused, double *out_6418814783153737190) {
  h_27(state, unused, out_6418814783153737190);
}
void car_H_27(double *state, double *unused, double *out_2917228647865346492) {
  H_27(state, unused, out_2917228647865346492);
}
void car_h_29(double *state, double *unused, double *out_4264664033735141985) {
  h_29(state, unused, out_4264664033735141985);
}
void car_H_29(double *state, double *unused, double *out_232233991750529397) {
  H_29(state, unused, out_232233991750529397);
}
void car_h_28(double *state, double *unused, double *out_5628887773141965280) {
  h_28(state, unused, out_5628887773141965280);
}
void car_H_28(double *state, double *unused, double *out_5314633008820059971) {
  H_28(state, unused, out_5314633008820059971);
}
void car_h_31(double *state, double *unused, double *out_3164572546466467129) {
  h_31(state, unused, out_3164572546466467129);
}
void car_H_31(double *state, double *unused, double *out_582480427044721083) {
  H_31(state, unused, out_582480427044721083);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)

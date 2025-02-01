#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_4236733633335182969);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1312881399455535811);
void car_H_mod_fun(double *state, double *out_8580061836990555726);
void car_f_fun(double *state, double dt, double *out_8484422586595881408);
void car_F_fun(double *state, double dt, double *out_7473343249845780073);
void car_h_25(double *state, double *unused, double *out_7026256022894968781);
void car_H_25(double *state, double *unused, double *out_3785230994062686617);
void car_h_24(double *state, double *unused, double *out_3957020047654824958);
void car_H_24(double *state, double *unused, double *out_5433447893577669774);
void car_h_30(double *state, double *unused, double *out_4453172886133550341);
void car_H_30(double *state, double *unused, double *out_742465336064921581);
void car_h_26(double *state, double *unused, double *out_2595705547158871215);
void car_H_26(double *state, double *unused, double *out_43727675188630393);
void car_h_27(double *state, double *unused, double *out_6418814783153737190);
void car_H_27(double *state, double *unused, double *out_2917228647865346492);
void car_h_29(double *state, double *unused, double *out_4264664033735141985);
void car_H_29(double *state, double *unused, double *out_232233991750529397);
void car_h_28(double *state, double *unused, double *out_5628887773141965280);
void car_H_28(double *state, double *unused, double *out_5314633008820059971);
void car_h_31(double *state, double *unused, double *out_3164572546466467129);
void car_H_31(double *state, double *unused, double *out_582480427044721083);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}
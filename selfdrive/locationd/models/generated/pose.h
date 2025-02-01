#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_3060945647413172151);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_1090212893188142520);
void pose_H_mod_fun(double *state, double *out_5258459091887351789);
void pose_f_fun(double *state, double dt, double *out_6465054850404689745);
void pose_F_fun(double *state, double dt, double *out_7787636662603076404);
void pose_h_4(double *state, double *unused, double *out_6388124336911847205);
void pose_H_4(double *state, double *unused, double *out_4504298089832639182);
void pose_h_10(double *state, double *unused, double *out_8654929017072647193);
void pose_H_10(double *state, double *unused, double *out_1603686663542064732);
void pose_h_13(double *state, double *unused, double *out_3810489520400261458);
void pose_H_13(double *state, double *unused, double *out_1292024264500306381);
void pose_h_14(double *state, double *unused, double *out_5932475143850498249);
void pose_H_14(double *state, double *unused, double *out_541057233493154653);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}
/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * inpolygon.h
 *
 * Code generation for function 'inpolygon'
 *
 */

#pragma once

/* Include files */
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "generatePOG_Reference_types.h"

/* Function Declarations */
void b_inpolygon(const emlrtStack *sp, const real_T x[5], const real_T y[5],
                 const real_T xv[5], const real_T yv[5], boolean_T in[5]);
void inpolygon(const emlrtStack *sp, const emxArray_real_T *x, const
               emxArray_real_T *y, const real_T xv[5], const real_T yv[5],
               emxArray_boolean_T *in);

/* End of code generation (inpolygon.h) */

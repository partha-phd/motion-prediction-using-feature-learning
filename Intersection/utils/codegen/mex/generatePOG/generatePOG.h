/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generatePOG.h
 *
 * Code generation for function 'generatePOG'
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
#include "generatePOG_types.h"

/* Function Declarations */
CODEGEN_EXPORT_SYM void generatePOG(generatePOGStackData *SD, const emlrtStack
  *sp, const emxArray_real_T *x_Road, const emxArray_real_T *y_Road, const
  emxArray_struct0_T *vehicleDatabase, real_T n, real_T predictedOccupancyGrid
  [16000]);

/* End of code generation (generatePOG.h) */

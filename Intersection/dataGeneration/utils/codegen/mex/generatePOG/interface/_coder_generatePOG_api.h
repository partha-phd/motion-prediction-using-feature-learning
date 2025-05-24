/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_generatePOG_api.h
 *
 * Code generation for function '_coder_generatePOG_api'
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
void generatePOG_api(generatePOGStackData *SD, const mxArray * const prhs[4],
                     int32_T nlhs, const mxArray *plhs[1]);

/* End of code generation (_coder_generatePOG_api.h) */

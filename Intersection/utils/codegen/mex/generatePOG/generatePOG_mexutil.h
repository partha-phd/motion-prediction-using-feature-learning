/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generatePOG_mexutil.h
 *
 * Code generation for function 'generatePOG_mexutil'
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
CODEGEN_EXPORT_SYM emlrtCTX emlrtGetRootTLSGlobal();
CODEGEN_EXPORT_SYM void emlrtLockerFunction(EmlrtLockeeFunction aLockee, const
  emlrtConstCTX aTLS, void *aData);

/* End of code generation (generatePOG_mexutil.h) */

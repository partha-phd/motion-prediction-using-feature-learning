/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generatePOG_Reference_data.cpp
 *
 * Code generation for function 'generatePOG_Reference_data'
 *
 */

/* Include files */
#include "generatePOG_Reference_data.h"
#include "generatePOG_Reference.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131483U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "generatePOG_Reference",             /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo l_emlrtRSI = { 21,         /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRTEInfo emlrtRTEI = { 47,         /* lineNo */
  19,                                  /* colNo */
  "allOrAny",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pName */
};

/* End of code generation (generatePOG_Reference_data.cpp) */

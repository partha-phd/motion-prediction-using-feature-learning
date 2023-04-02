/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generatePOG_Reference_emxutil.h
 *
 * Code generation for function 'generatePOG_Reference_emxutil'
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
CODEGEN_EXPORT_SYM void emxEnsureCapacity_boolean_T(const emlrtStack *sp,
  emxArray_boolean_T *emxArray, int32_T oldNumel, const emlrtRTEInfo
  *srcLocation);
CODEGEN_EXPORT_SYM void emxEnsureCapacity_real_T(const emlrtStack *sp,
  emxArray_real_T *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
CODEGEN_EXPORT_SYM void emxEnsureCapacity_struct0_T(const emlrtStack *sp,
  emxArray_struct0_T *emxArray, int32_T oldNumel, const emlrtRTEInfo
  *srcLocation);
CODEGEN_EXPORT_SYM void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
CODEGEN_EXPORT_SYM void emxFree_real_T(emxArray_real_T **pEmxArray);
CODEGEN_EXPORT_SYM void emxFree_struct0_T(emxArray_struct0_T **pEmxArray);
CODEGEN_EXPORT_SYM void emxInit_boolean_T(const emlrtStack *sp,
  emxArray_boolean_T **pEmxArray, int32_T numDimensions, const emlrtRTEInfo
  *srcLocation, boolean_T doPush);
CODEGEN_EXPORT_SYM void emxInit_real_T(const emlrtStack *sp, emxArray_real_T
  **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
CODEGEN_EXPORT_SYM void emxInit_struct0_T(const emlrtStack *sp,
  emxArray_struct0_T **pEmxArray, int32_T numDimensions, const emlrtRTEInfo
  *srcLocation, boolean_T doPush);

/* End of code generation (generatePOG_Reference_emxutil.h) */

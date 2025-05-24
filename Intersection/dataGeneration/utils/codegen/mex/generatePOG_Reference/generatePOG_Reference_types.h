/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generatePOG_Reference_types.h
 *
 * Code generation for function 'generatePOG_Reference_types'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

struct struct0_T
{
  emxArray_real_T *bboxX;
  emxArray_real_T *bboxY;
  emxArray_real_T *posX;
  emxArray_real_T *posY;
  emxArray_real_T *psi;
  emxArray_real_T *v;
  emxArray_real_T *aX;
  emxArray_real_T *aY;
  emxArray_real_T *time;
};

struct emxArray_struct0_T
{
  struct0_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

struct generatePOG_ReferenceStackData
{
  struct {
    real_T gridNew[64000];
  } f0;
};

/* End of code generation (generatePOG_Reference_types.h) */

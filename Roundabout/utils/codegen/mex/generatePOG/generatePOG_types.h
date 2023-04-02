/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generatePOG_types.h
 *
 * Code generation for function 'generatePOG_types'
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
  emxArray_real_T *xCoordinates;
  emxArray_real_T *yCoordinates;
  emxArray_real_T *minProb;
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

struct generatePOGStackData
{
  struct {
    real_T occupancyGrid[252000000];
    real_T gridNew[100800];
    real_T b_occupancyGrid[25200];
  } f0;
};

/* End of code generation (generatePOG_types.h) */

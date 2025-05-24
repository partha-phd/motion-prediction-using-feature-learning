/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generatePOG_Reference.cpp
 *
 * Code generation for function 'generatePOG_Reference'
 *
 */

/* Include files */
#include "generatePOG_Reference.h"
#include "eml_int_forloop_overflow_check.h"
#include "generatePOG_Reference_data.h"
#include "generatePOG_Reference_emxutil.h"
#include "inpolygon.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 31,    /* lineNo */
  "generatePOG_Reference",             /* fcnName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Roundabout\\utils\\generatePOG_Reference.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 50,  /* lineNo */
  "generatePOG_Reference",             /* fcnName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Roundabout\\utils\\generatePOG_Reference.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 51,  /* lineNo */
  "generatePOG_Reference",             /* fcnName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Roundabout\\utils\\generatePOG_Reference.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 13,  /* lineNo */
  "any",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\any.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 143, /* lineNo */
  "allOrAny",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pathName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  29,                                  /* colNo */
  "vehicle",                           /* aName */
  "generatePOG_Reference",             /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Roundabout\\utils\\generatePOG_Reference.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 46,    /* lineNo */
  38,                                  /* colNo */
  "generatePOG_Reference",             /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Roundabout\\utils\\generatePOG_Reference.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  38,                                  /* colNo */
  "vehicle(i).bboxX",                  /* aName */
  "generatePOG_Reference",             /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Roundabout\\utils\\generatePOG_Reference.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  21,                                  /* colNo */
  "vehicle",                           /* aName */
  "generatePOG_Reference",             /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Roundabout\\utils\\generatePOG_Reference.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  29,                                  /* colNo */
  "vehicle",                           /* aName */
  "generatePOG_Reference",             /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Roundabout\\utils\\generatePOG_Reference.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  38,                                  /* colNo */
  "vehicle(i).bboxY",                  /* aName */
  "generatePOG_Reference",             /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Roundabout\\utils\\generatePOG_Reference.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  21,                                  /* colNo */
  "vehicle",                           /* aName */
  "generatePOG_Reference",             /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Roundabout\\utils\\generatePOG_Reference.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  25200,                               /* iLast */
  12,                                  /* lineNo */
  21,                                  /* colNo */
  "gridNew",                           /* aName */
  "generatePOG_Reference",             /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Roundabout\\utils\\generatePOG_Reference.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  13,                                  /* colNo */
  "vehicle(i).bboxX",                  /* aName */
  "generatePOG_Reference",             /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Roundabout\\utils\\generatePOG_Reference.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 47,  /* lineNo */
  13,                                  /* colNo */
  "generatePOG_Reference",             /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Roundabout\\utils\\generatePOG_Reference.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  13,                                  /* colNo */
  "vehicle(i).bboxY",                  /* aName */
  "generatePOG_Reference",             /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Roundabout\\utils\\generatePOG_Reference.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo f_emlrtRTEI = { 31,/* lineNo */
  12,                                  /* colNo */
  "generatePOG_Reference",             /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Roundabout\\utils\\generatePOG_Reference.m"/* pName */
};

/* Function Definitions */
void generatePOG_Reference(generatePOG_ReferenceStackData *SD, const emlrtStack *
  sp, const emxArray_real_T *x_Road, const emxArray_real_T *y_Road, const
  emxArray_struct0_T *vehicle, real_T n, real_T POG[25200])
{
  int32_T k;
  int32_T i;
  int32_T j;
  int8_T occupancyGrid[25200];
  int32_T gridNew_tmp;
  emxArray_boolean_T *x;
  int32_T m;
  real_T xv[5];
  real_T d;
  int32_T b_i;
  int32_T i1;
  real_T yv[5];
  int32_T i2;
  int32_T xVehicle_tmp;
  real_T d1;
  int32_T i3;
  int32_T i4;
  boolean_T y;
  boolean_T exitg1;
  real_T xVehicle[5];
  real_T yVehicle[5];
  boolean_T b_x[5];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Generation of Predicted Occupancy Grids (Reference) */
  /*  Construction of grids 0.5m x 0.5m */
  k = 1;
  memset(&SD->f0.gridNew[0], 0, 100800U * sizeof(real_T));
  for (i = 0; i < 140; i++) {
    for (j = 0; j < 180; j++) {
      if (k > 25200) {
        emlrtDynamicBoundsCheckR2012b(25201, 1, 25200, &g_emlrtBCI, sp);
      }

      gridNew_tmp = (k - 1) << 2;
      SD->f0.gridNew[gridNew_tmp] = 0.5 * static_cast<real_T>(j) + 20.0;
      SD->f0.gridNew[gridNew_tmp + 2] = 0.5 * (static_cast<real_T>(j) + 1.0) +
        20.0;
      SD->f0.gridNew[gridNew_tmp + 1] = 0.5 * static_cast<real_T>(i) + -35.1;
      SD->f0.gridNew[gridNew_tmp + 3] = 0.5 * (static_cast<real_T>(i) + 1.0) +
        -35.1;
      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  Initialisation */
  memset(&occupancyGrid[0], 0, 25200U * sizeof(int8_T));

  /*  Vectorize the road points */
  /*  Probability to road points */
  /*  START loop over the grids */
  emxInit_boolean_T(sp, &x, 1, &f_emlrtRTEI, true);
  for (m = 0; m < 25200; m++) {
    st.site = &emlrtRSI;
    gridNew_tmp = m << 2;
    xv[0] = SD->f0.gridNew[gridNew_tmp];
    d = SD->f0.gridNew[gridNew_tmp + 2];
    xv[1] = d;
    xv[2] = d;
    xv[3] = SD->f0.gridNew[gridNew_tmp];
    xv[4] = SD->f0.gridNew[gridNew_tmp];
    d = SD->f0.gridNew[gridNew_tmp + 1];
    yv[0] = d;
    yv[1] = d;
    d1 = SD->f0.gridNew[gridNew_tmp + 3];
    yv[2] = d1;
    yv[3] = d1;
    yv[4] = d;
    b_st.site = &emlrtRSI;
    inpolygon(&b_st, x_Road, y_Road, xv, yv, x);
    b_st.site = &w_emlrtRSI;
    y = false;
    c_st.site = &x_emlrtRSI;
    if ((1 <= x->size[0]) && (x->size[0] > 2147483646)) {
      d_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    j = 1;
    exitg1 = false;
    while ((!exitg1) && (j <= x->size[0])) {
      if (!x->data[j - 1]) {
        j++;
      } else {
        y = true;
        exitg1 = true;
      }
    }

    if (y) {
      occupancyGrid[m] = 1;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_boolean_T(&x);

  /*  END loop over the grids */
  /*  Probability to target */
  /*  START loop over the target */
  gridNew_tmp = vehicle->size[1];
  for (i = 0; i < gridNew_tmp; i++) {
    /*  START loop over the grids */
    b_i = i + 1;
    i1 = i + 1;
    i2 = static_cast<int32_T>(muDoubleScalarFloor(n));
    xVehicle_tmp = static_cast<int32_T>(n) - 1;
    i3 = i + 1;
    i4 = i + 1;
    for (m = 0; m < 25200; m++) {
      j = m << 2;
      xv[0] = SD->f0.gridNew[j];
      d = SD->f0.gridNew[j + 2];
      xv[1] = d;
      xv[2] = d;
      xv[3] = SD->f0.gridNew[j];
      xv[4] = SD->f0.gridNew[j];
      d = SD->f0.gridNew[j + 1];
      yv[0] = d;
      yv[1] = d;
      d1 = SD->f0.gridNew[j + 3];
      yv[2] = d1;
      yv[3] = d1;
      yv[4] = d;
      if ((b_i < 1) || (b_i > vehicle->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i, 1, vehicle->size[1], &emlrtBCI, sp);
      }

      if ((i1 < 1) || (i1 > vehicle->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, vehicle->size[1], &c_emlrtBCI, sp);
      }

      if (n != i2) {
        emlrtIntegerCheckR2012b(n, &emlrtDCI, sp);
      }

      if ((static_cast<int32_T>(n) < 1) || (static_cast<int32_T>(n) >
           vehicle->data[i].bboxX->size[0])) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1, vehicle->
          data[i].bboxX->size[0], &b_emlrtBCI, sp);
      }

      xVehicle[0] = vehicle->data[i].bboxX->data[xVehicle_tmp];
      xVehicle[1] = vehicle->data[i].bboxX->data[xVehicle_tmp + vehicle->data[i]
        .bboxX->size[0]];
      xVehicle[2] = vehicle->data[i].bboxX->data[xVehicle_tmp + vehicle->data[i]
        .bboxX->size[0] * 2];
      xVehicle[3] = vehicle->data[i].bboxX->data[xVehicle_tmp + vehicle->data[i]
        .bboxX->size[0] * 3];
      if (static_cast<int32_T>(n) != i2) {
        emlrtIntegerCheckR2012b(n, &b_emlrtDCI, sp);
      }

      if (static_cast<int32_T>(n) > vehicle->data[i].bboxX->size[0]) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1, vehicle->
          data[i].bboxX->size[0], &h_emlrtBCI, sp);
      }

      xVehicle[4] = vehicle->data[i].bboxX->data[static_cast<int32_T>(n) - 1];
      if ((i3 < 1) || (i3 > vehicle->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, vehicle->size[1], &d_emlrtBCI, sp);
      }

      if ((i4 < 1) || (i4 > vehicle->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, vehicle->size[1], &f_emlrtBCI, sp);
      }

      if (static_cast<int32_T>(n) > vehicle->data[i].bboxY->size[0]) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1, vehicle->
          data[i].bboxY->size[0], &e_emlrtBCI, sp);
      }

      yVehicle[0] = vehicle->data[i].bboxY->data[xVehicle_tmp];
      yVehicle[1] = vehicle->data[i].bboxY->data[xVehicle_tmp + vehicle->data[i]
        .bboxY->size[0]];
      yVehicle[2] = vehicle->data[i].bboxY->data[xVehicle_tmp + vehicle->data[i]
        .bboxY->size[0] * 2];
      yVehicle[3] = vehicle->data[i].bboxY->data[xVehicle_tmp + vehicle->data[i]
        .bboxY->size[0] * 3];
      if (static_cast<int32_T>(n) > vehicle->data[i].bboxY->size[0]) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1, vehicle->
          data[i].bboxY->size[0], &i_emlrtBCI, sp);
      }

      yVehicle[4] = vehicle->data[i].bboxY->data[static_cast<int32_T>(n) - 1];
      st.site = &b_emlrtRSI;
      b_inpolygon(&st, xVehicle, yVehicle, xv, yv, b_x);
      y = false;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 5)) {
        if (b_x[k]) {
          y = true;
          exitg1 = true;
        } else {
          k++;
        }
      }

      if (y) {
        occupancyGrid[m] = 1;
      } else {
        st.site = &c_emlrtRSI;
        b_inpolygon(&st, xv, yv, xVehicle, yVehicle, b_x);
        y = false;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 5)) {
          if (b_x[k]) {
            y = true;
            exitg1 = true;
          } else {
            k++;
          }
        }

        if (y) {
          occupancyGrid[m] = 1;
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  END loop over the grids */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  END loop over the targets */
  for (i = 0; i < 140; i++) {
    for (j = 0; j < 180; j++) {
      POG[i + 140 * j] = occupancyGrid[j + 180 * (139 - i)];
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (generatePOG_Reference.cpp) */

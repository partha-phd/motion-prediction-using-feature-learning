/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generatePOG.cpp
 *
 * Code generation for function 'generatePOG'
 *
 */

/* Include files */
#include "generatePOG.h"
#include "eml_int_forloop_overflow_check.h"
#include "generatePOG_data.h"
#include "generatePOG_emxutil.h"
#include "inpolygon.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 32,    /* lineNo */
  "generatePOG",                       /* fcnName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 65,  /* lineNo */
  "generatePOG",                       /* fcnName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 66,  /* lineNo */
  "generatePOG",                       /* fcnName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m"/* pathName */
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
  47,                                  /* lineNo */
  41,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  43,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  45,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  49,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  51,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  53,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  71,                                  /* colNo */
  "vehicleDatabase(i,j,k).xCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  41,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  43,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  45,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  63,                                  /* colNo */
  "vehicleDatabase(i,j,k).xCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  41,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  43,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  45,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  63,                                  /* colNo */
  "vehicleDatabase(i,j,k).xCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  41,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  43,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  45,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  63,                                  /* colNo */
  "vehicleDatabase(i,j,k).xCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  41,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  43,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  45,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  63,                                  /* colNo */
  "vehicleDatabase(i,j,k).xCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  49,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  51,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  53,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  71,                                  /* colNo */
  "vehicleDatabase(i,j,k).yCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  41,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  43,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  45,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  63,                                  /* colNo */
  "vehicleDatabase(i,j,k).yCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  41,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  43,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  45,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  63,                                  /* colNo */
  "vehicleDatabase(i,j,k).yCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  41,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  43,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  45,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  63,                                  /* colNo */
  "vehicleDatabase(i,j,k).yCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  41,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  43,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  45,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  63,                                  /* colNo */
  "vehicleDatabase(i,j,k).yCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  45,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  47,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  49,                                  /* colNo */
  "vehicleDatabase",                   /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { 1,  /* iFirst */
  10000,                               /* iLast */
  70,                                  /* lineNo */
  39,                                  /* colNo */
  "occupancyGrid",                     /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { 1,  /* iFirst */
  16000,                               /* iLast */
  13,                                  /* lineNo */
  21,                                  /* colNo */
  "gridNew",                           /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  33,                                  /* colNo */
  "vehicleDatabase(i,j,k).xCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 55,    /* lineNo */
  33,                                  /* colNo */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  25,                                  /* colNo */
  "vehicleDatabase(i,j,k).xCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 56,  /* lineNo */
  25,                                  /* colNo */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  25,                                  /* colNo */
  "vehicleDatabase(i,j,k).xCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 57,  /* lineNo */
  25,                                  /* colNo */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  25,                                  /* colNo */
  "vehicleDatabase(i,j,k).xCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 58,  /* lineNo */
  25,                                  /* colNo */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  25,                                  /* colNo */
  "vehicleDatabase(i,j,k).xCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 59,  /* lineNo */
  25,                                  /* colNo */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  33,                                  /* colNo */
  "vehicleDatabase(i,j,k).yCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  25,                                  /* colNo */
  "vehicleDatabase(i,j,k).yCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  25,                                  /* colNo */
  "vehicleDatabase(i,j,k).yCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  25,                                  /* colNo */
  "vehicleDatabase(i,j,k).yCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  25,                                  /* colNo */
  "vehicleDatabase(i,j,k).yCoordinates",/* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  29,                                  /* colNo */
  "vehicleDatabase(i,j,k).minProb",    /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { 1,  /* iFirst */
  10000,                               /* iLast */
  67,                                  /* lineNo */
  25,                                  /* colNo */
  "occupancyGrid",                     /* aName */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m",/* pName */
  3                                    /* checkKind */
};

static emlrtRTEInfo f_emlrtRTEI = { 32,/* lineNo */
  12,                                  /* colNo */
  "generatePOG",                       /* fName */
  "C:\\Users\\nadarajan\\Documents\\PredictedOccupancyGrid\\Intersection\\utils\\generatePOG.m"/* pName */
};

/* Function Definitions */
void generatePOG(generatePOGStackData *SD, const emlrtStack *sp, const
                 emxArray_real_T *x_Road, const emxArray_real_T *y_Road, const
                 emxArray_struct0_T *vehicleDatabase, real_T n, real_T
                 predictedOccupancyGrid[16000])
{
  int32_T k;
  int32_T i;
  int32_T j;
  int32_T xpageoffset;
  emxArray_boolean_T *x;
  int32_T m;
  int32_T b_i;
  real_T counter;
  real_T xv[5];
  real_T d;
  int32_T i1;
  real_T yv[5];
  real_T d1;
  int32_T i2;
  real_T occupancyGrid[16000];
  int32_T i3;
  boolean_T y;
  boolean_T exitg1;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  int32_T i8;
  int32_T i9;
  int32_T i10;
  int32_T i11;
  int32_T i12;
  int32_T i13;
  int32_T i14;
  int32_T i15;
  int32_T i16;
  int32_T i17;
  int32_T i18;
  int32_T i19;
  int32_T i20;
  int32_T i21;
  int32_T i22;
  int32_T i23;
  int32_T i24;
  int32_T i25;
  int32_T i26;
  int32_T i27;
  int32_T i28;
  int32_T i29;
  int32_T i30;
  int32_T i31;
  int32_T i32;
  int32_T i33;
  real_T xVehicle[5];
  real_T yVehicle[5];
  boolean_T b_x[5];
  boolean_T guard1 = false;
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

  /*  Generation of Predicted Occupancy Grids */
  /*  Construction of grids 1m x 0.5m */
  k = 1;
  memset(&SD->f0.gridNew[0], 0, 64000U * sizeof(real_T));
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 160; j++) {
      if (k > 16000) {
        emlrtDynamicBoundsCheckR2012b(16001, 1, 16000, &wb_emlrtBCI, sp);
      }

      xpageoffset = (k - 1) << 2;
      SD->f0.gridNew[xpageoffset] = 0.5 * static_cast<real_T>(j);
      SD->f0.gridNew[xpageoffset + 2] = 0.5 * (static_cast<real_T>(j) + 1.0);
      SD->f0.gridNew[xpageoffset + 1] = 0.5 * static_cast<real_T>(i) + -40.1;
      SD->f0.gridNew[xpageoffset + 3] = 0.5 * (static_cast<real_T>(i) + 1.0) +
        -40.1;
      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  Vectorize the road points */
  /*  Initialisation */
  memset(&SD->f0.occupancyGrid[0], 0, 160000000U * sizeof(real_T));

  /*  Probability to road points */
  /*  START loop over the grids */
  emxInit_boolean_T(sp, &x, 1, &f_emlrtRTEI, true);
  for (m = 0; m < 16000; m++) {
    st.site = &emlrtRSI;
    b_i = m << 2;
    xv[0] = SD->f0.gridNew[b_i];
    d = SD->f0.gridNew[b_i + 2];
    xv[1] = d;
    xv[2] = d;
    xv[3] = SD->f0.gridNew[b_i];
    xv[4] = SD->f0.gridNew[b_i];
    d = SD->f0.gridNew[b_i + 1];
    yv[0] = d;
    yv[1] = d;
    d1 = SD->f0.gridNew[b_i + 3];
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

    xpageoffset = 1;
    exitg1 = false;
    while ((!exitg1) && (xpageoffset <= x->size[0])) {
      if (!x->data[xpageoffset - 1]) {
        xpageoffset++;
      } else {
        y = true;
        exitg1 = true;
      }
    }

    if (y) {
      for (b_i = 0; b_i < 10000; b_i++) {
        SD->f0.occupancyGrid[b_i + 10000 * m] = 1.0;
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_boolean_T(&x);

  /*  END loop over the grids */
  counter = 0.0;

  /*  Probability to target */
  /*  START loop over the target */
  b_i = vehicleDatabase->size[0];
  for (i = 0; i < b_i; i++) {
    /*  START loop over the multiple hypotheses (lateral) */
    i1 = vehicleDatabase->size[1];
    for (j = 0; j < i1; j++) {
      /*  START loop over the multiple hypotheses(longitudinal) */
      i2 = vehicleDatabase->size[2];
      for (k = 0; k < i2; k++) {
        i3 = i + 1;
        if ((i3 < 1) || (i3 > vehicleDatabase->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, vehicleDatabase->size[0],
            &emlrtBCI, sp);
        }

        i3 = j + 1;
        if ((i3 < 1) || (i3 > vehicleDatabase->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, vehicleDatabase->size[1],
            &b_emlrtBCI, sp);
        }

        i3 = k + 1;
        if ((i3 < 1) || (i3 > vehicleDatabase->size[2])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, vehicleDatabase->size[2],
            &c_emlrtBCI, sp);
        }

        if ((vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
             vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
             xCoordinates->size[0] != 0) && (vehicleDatabase->data[(i +
              vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
             vehicleDatabase->size[1] * k].xCoordinates->size[1] != 0)) {
          counter++;

          /*  START loop over the grids */
          i3 = i + 1;
          i4 = j + 1;
          i5 = k + 1;
          i6 = i + 1;
          i7 = j + 1;
          i8 = k + 1;
          i9 = i + 1;
          i10 = j + 1;
          i11 = k + 1;
          i12 = i + 1;
          i13 = j + 1;
          i14 = k + 1;
          i15 = i + 1;
          i16 = j + 1;
          i17 = k + 1;
          i18 = static_cast<int32_T>(muDoubleScalarFloor(n));
          i19 = i + 1;
          i20 = j + 1;
          i21 = k + 1;
          i22 = i + 1;
          i23 = j + 1;
          i24 = k + 1;
          i25 = i + 1;
          i26 = j + 1;
          i27 = k + 1;
          i28 = i + 1;
          i29 = j + 1;
          i30 = k + 1;
          i31 = i + 1;
          i32 = j + 1;
          i33 = k + 1;
          for (m = 0; m < 16000; m++) {
            xpageoffset = m << 2;
            xv[0] = SD->f0.gridNew[xpageoffset];
            d = SD->f0.gridNew[xpageoffset + 2];
            xv[1] = d;
            xv[2] = d;
            xv[3] = SD->f0.gridNew[xpageoffset];
            xv[4] = SD->f0.gridNew[xpageoffset];
            d = SD->f0.gridNew[xpageoffset + 1];
            yv[0] = d;
            yv[1] = d;
            d1 = SD->f0.gridNew[xpageoffset + 3];
            yv[2] = d1;
            yv[3] = d1;
            yv[4] = d;
            if ((i3 < 1) || (i3 > vehicleDatabase->size[0])) {
              emlrtDynamicBoundsCheckR2012b(i3, 1, vehicleDatabase->size[0],
                &d_emlrtBCI, sp);
            }

            if ((i4 < 1) || (i4 > vehicleDatabase->size[1])) {
              emlrtDynamicBoundsCheckR2012b(i4, 1, vehicleDatabase->size[1],
                &e_emlrtBCI, sp);
            }

            if ((i5 < 1) || (i5 > vehicleDatabase->size[2])) {
              emlrtDynamicBoundsCheckR2012b(i5, 1, vehicleDatabase->size[2],
                &f_emlrtBCI, sp);
            }

            if ((i6 < 1) || (i6 > vehicleDatabase->size[0])) {
              emlrtDynamicBoundsCheckR2012b(i6, 1, vehicleDatabase->size[0],
                &h_emlrtBCI, sp);
            }

            if ((i7 < 1) || (i7 > vehicleDatabase->size[1])) {
              emlrtDynamicBoundsCheckR2012b(i7, 1, vehicleDatabase->size[1],
                &i_emlrtBCI, sp);
            }

            if ((i8 < 1) || (i8 > vehicleDatabase->size[2])) {
              emlrtDynamicBoundsCheckR2012b(i8, 1, vehicleDatabase->size[2],
                &j_emlrtBCI, sp);
            }

            if ((i9 < 1) || (i9 > vehicleDatabase->size[0])) {
              emlrtDynamicBoundsCheckR2012b(i9, 1, vehicleDatabase->size[0],
                &l_emlrtBCI, sp);
            }

            if ((i10 < 1) || (i10 > vehicleDatabase->size[1])) {
              emlrtDynamicBoundsCheckR2012b(i10, 1, vehicleDatabase->size[1],
                &m_emlrtBCI, sp);
            }

            if ((i11 < 1) || (i11 > vehicleDatabase->size[2])) {
              emlrtDynamicBoundsCheckR2012b(i11, 1, vehicleDatabase->size[2],
                &n_emlrtBCI, sp);
            }

            if ((i12 < 1) || (i12 > vehicleDatabase->size[0])) {
              emlrtDynamicBoundsCheckR2012b(i12, 1, vehicleDatabase->size[0],
                &p_emlrtBCI, sp);
            }

            if ((i13 < 1) || (i13 > vehicleDatabase->size[1])) {
              emlrtDynamicBoundsCheckR2012b(i13, 1, vehicleDatabase->size[1],
                &q_emlrtBCI, sp);
            }

            if ((i14 < 1) || (i14 > vehicleDatabase->size[2])) {
              emlrtDynamicBoundsCheckR2012b(i14, 1, vehicleDatabase->size[2],
                &r_emlrtBCI, sp);
            }

            if ((i15 < 1) || (i15 > vehicleDatabase->size[0])) {
              emlrtDynamicBoundsCheckR2012b(i15, 1, vehicleDatabase->size[0],
                &t_emlrtBCI, sp);
            }

            if ((i16 < 1) || (i16 > vehicleDatabase->size[1])) {
              emlrtDynamicBoundsCheckR2012b(i16, 1, vehicleDatabase->size[1],
                &u_emlrtBCI, sp);
            }

            if ((i17 < 1) || (i17 > vehicleDatabase->size[2])) {
              emlrtDynamicBoundsCheckR2012b(i17, 1, vehicleDatabase->size[2],
                &v_emlrtBCI, sp);
            }

            if (1 > vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                xCoordinates->size[1]) {
              emlrtDynamicBoundsCheckR2012b(1, 1, vehicleDatabase->data[(i +
                vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].xCoordinates->size[1], &g_emlrtBCI,
                sp);
            }

            if (2 > vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                xCoordinates->size[1]) {
              emlrtDynamicBoundsCheckR2012b(2, 1, vehicleDatabase->data[(i +
                vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].xCoordinates->size[1], &k_emlrtBCI,
                sp);
            }

            if (3 > vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                xCoordinates->size[1]) {
              emlrtDynamicBoundsCheckR2012b(3, 1, vehicleDatabase->data[(i +
                vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].xCoordinates->size[1], &o_emlrtBCI,
                sp);
            }

            if (4 > vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                xCoordinates->size[1]) {
              emlrtDynamicBoundsCheckR2012b(4, 1, vehicleDatabase->data[(i +
                vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].xCoordinates->size[1], &s_emlrtBCI,
                sp);
            }

            if (1 > vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                xCoordinates->size[1]) {
              emlrtDynamicBoundsCheckR2012b(1, 1, vehicleDatabase->data[(i +
                vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].xCoordinates->size[1], &w_emlrtBCI,
                sp);
            }

            if (n != i18) {
              emlrtIntegerCheckR2012b(n, &emlrtDCI, sp);
            }

            if ((static_cast<int32_T>(n) < 1) || (static_cast<int32_T>(n) >
                 vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                 vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                 xCoordinates->size[0])) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1,
                vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                xCoordinates->size[0], &xb_emlrtBCI, sp);
            }

            xVehicle[0] = vehicleDatabase->data[(i + vehicleDatabase->size[0] *
              j) + vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
              xCoordinates->data[static_cast<int32_T>(n) - 1];
            if (static_cast<int32_T>(n) != i18) {
              emlrtIntegerCheckR2012b(n, &b_emlrtDCI, sp);
            }

            if (static_cast<int32_T>(n) > vehicleDatabase->data[(i +
                 vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].xCoordinates->size[0]) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1,
                vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                xCoordinates->size[0], &yb_emlrtBCI, sp);
            }

            xVehicle[1] = vehicleDatabase->data[(i + vehicleDatabase->size[0] *
              j) + vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
              xCoordinates->data[(static_cast<int32_T>(n) +
                                  vehicleDatabase->data[(i +
              vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                                  vehicleDatabase->size[1] * k]
                                  .xCoordinates->size[0]) - 1];
            if (static_cast<int32_T>(n) != i18) {
              emlrtIntegerCheckR2012b(n, &c_emlrtDCI, sp);
            }

            if (static_cast<int32_T>(n) > vehicleDatabase->data[(i +
                 vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].xCoordinates->size[0]) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1,
                vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                xCoordinates->size[0], &ac_emlrtBCI, sp);
            }

            xVehicle[2] = vehicleDatabase->data[(i + vehicleDatabase->size[0] *
              j) + vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
              xCoordinates->data[(static_cast<int32_T>(n) +
                                  vehicleDatabase->data[(i +
              vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                                  vehicleDatabase->size[1] * k]
                                  .xCoordinates->size[0] * 2) - 1];
            if (static_cast<int32_T>(n) != i18) {
              emlrtIntegerCheckR2012b(n, &d_emlrtDCI, sp);
            }

            if (static_cast<int32_T>(n) > vehicleDatabase->data[(i +
                 vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].xCoordinates->size[0]) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1,
                vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                xCoordinates->size[0], &bc_emlrtBCI, sp);
            }

            xVehicle[3] = vehicleDatabase->data[(i + vehicleDatabase->size[0] *
              j) + vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
              xCoordinates->data[(static_cast<int32_T>(n) +
                                  vehicleDatabase->data[(i +
              vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                                  vehicleDatabase->size[1] * k]
                                  .xCoordinates->size[0] * 3) - 1];
            if (static_cast<int32_T>(n) != i18) {
              emlrtIntegerCheckR2012b(n, &e_emlrtDCI, sp);
            }

            if (static_cast<int32_T>(n) > vehicleDatabase->data[(i +
                 vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].xCoordinates->size[0]) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1,
                vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                xCoordinates->size[0], &cc_emlrtBCI, sp);
            }

            xVehicle[4] = vehicleDatabase->data[(i + vehicleDatabase->size[0] *
              j) + vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
              xCoordinates->data[static_cast<int32_T>(n) - 1];
            if ((i19 < 1) || (i19 > vehicleDatabase->size[0])) {
              emlrtDynamicBoundsCheckR2012b(i19, 1, vehicleDatabase->size[0],
                &x_emlrtBCI, sp);
            }

            if ((i20 < 1) || (i20 > vehicleDatabase->size[1])) {
              emlrtDynamicBoundsCheckR2012b(i20, 1, vehicleDatabase->size[1],
                &y_emlrtBCI, sp);
            }

            if ((i21 < 1) || (i21 > vehicleDatabase->size[2])) {
              emlrtDynamicBoundsCheckR2012b(i21, 1, vehicleDatabase->size[2],
                &ab_emlrtBCI, sp);
            }

            if ((i22 < 1) || (i22 > vehicleDatabase->size[0])) {
              emlrtDynamicBoundsCheckR2012b(i22, 1, vehicleDatabase->size[0],
                &cb_emlrtBCI, sp);
            }

            if ((i23 < 1) || (i23 > vehicleDatabase->size[1])) {
              emlrtDynamicBoundsCheckR2012b(i23, 1, vehicleDatabase->size[1],
                &db_emlrtBCI, sp);
            }

            if ((i24 < 1) || (i24 > vehicleDatabase->size[2])) {
              emlrtDynamicBoundsCheckR2012b(i24, 1, vehicleDatabase->size[2],
                &eb_emlrtBCI, sp);
            }

            if ((i25 < 1) || (i25 > vehicleDatabase->size[0])) {
              emlrtDynamicBoundsCheckR2012b(i25, 1, vehicleDatabase->size[0],
                &gb_emlrtBCI, sp);
            }

            if ((i26 < 1) || (i26 > vehicleDatabase->size[1])) {
              emlrtDynamicBoundsCheckR2012b(i26, 1, vehicleDatabase->size[1],
                &hb_emlrtBCI, sp);
            }

            if ((i27 < 1) || (i27 > vehicleDatabase->size[2])) {
              emlrtDynamicBoundsCheckR2012b(i27, 1, vehicleDatabase->size[2],
                &ib_emlrtBCI, sp);
            }

            if ((i28 < 1) || (i28 > vehicleDatabase->size[0])) {
              emlrtDynamicBoundsCheckR2012b(i28, 1, vehicleDatabase->size[0],
                &kb_emlrtBCI, sp);
            }

            if ((i29 < 1) || (i29 > vehicleDatabase->size[1])) {
              emlrtDynamicBoundsCheckR2012b(i29, 1, vehicleDatabase->size[1],
                &lb_emlrtBCI, sp);
            }

            if ((i30 < 1) || (i30 > vehicleDatabase->size[2])) {
              emlrtDynamicBoundsCheckR2012b(i30, 1, vehicleDatabase->size[2],
                &mb_emlrtBCI, sp);
            }

            if ((i31 < 1) || (i31 > vehicleDatabase->size[0])) {
              emlrtDynamicBoundsCheckR2012b(i31, 1, vehicleDatabase->size[0],
                &ob_emlrtBCI, sp);
            }

            if ((i32 < 1) || (i32 > vehicleDatabase->size[1])) {
              emlrtDynamicBoundsCheckR2012b(i32, 1, vehicleDatabase->size[1],
                &pb_emlrtBCI, sp);
            }

            if ((i33 < 1) || (i33 > vehicleDatabase->size[2])) {
              emlrtDynamicBoundsCheckR2012b(i33, 1, vehicleDatabase->size[2],
                &qb_emlrtBCI, sp);
            }

            if (1 > vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                yCoordinates->size[1]) {
              emlrtDynamicBoundsCheckR2012b(1, 1, vehicleDatabase->data[(i +
                vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].yCoordinates->size[1],
                &bb_emlrtBCI, sp);
            }

            if (2 > vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                yCoordinates->size[1]) {
              emlrtDynamicBoundsCheckR2012b(2, 1, vehicleDatabase->data[(i +
                vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].yCoordinates->size[1],
                &fb_emlrtBCI, sp);
            }

            if (3 > vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                yCoordinates->size[1]) {
              emlrtDynamicBoundsCheckR2012b(3, 1, vehicleDatabase->data[(i +
                vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].yCoordinates->size[1],
                &jb_emlrtBCI, sp);
            }

            if (4 > vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                yCoordinates->size[1]) {
              emlrtDynamicBoundsCheckR2012b(4, 1, vehicleDatabase->data[(i +
                vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].yCoordinates->size[1],
                &nb_emlrtBCI, sp);
            }

            if (1 > vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                yCoordinates->size[1]) {
              emlrtDynamicBoundsCheckR2012b(1, 1, vehicleDatabase->data[(i +
                vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].yCoordinates->size[1],
                &rb_emlrtBCI, sp);
            }

            if (static_cast<int32_T>(n) > vehicleDatabase->data[(i +
                 vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].yCoordinates->size[0]) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1,
                vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                yCoordinates->size[0], &dc_emlrtBCI, sp);
            }

            yVehicle[0] = vehicleDatabase->data[(i + vehicleDatabase->size[0] *
              j) + vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
              yCoordinates->data[static_cast<int32_T>(n) - 1];
            if (static_cast<int32_T>(n) > vehicleDatabase->data[(i +
                 vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].yCoordinates->size[0]) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1,
                vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                yCoordinates->size[0], &ec_emlrtBCI, sp);
            }

            yVehicle[1] = vehicleDatabase->data[(i + vehicleDatabase->size[0] *
              j) + vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
              yCoordinates->data[(static_cast<int32_T>(n) +
                                  vehicleDatabase->data[(i +
              vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                                  vehicleDatabase->size[1] * k]
                                  .yCoordinates->size[0]) - 1];
            if (static_cast<int32_T>(n) > vehicleDatabase->data[(i +
                 vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].yCoordinates->size[0]) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1,
                vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                yCoordinates->size[0], &fc_emlrtBCI, sp);
            }

            yVehicle[2] = vehicleDatabase->data[(i + vehicleDatabase->size[0] *
              j) + vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
              yCoordinates->data[(static_cast<int32_T>(n) +
                                  vehicleDatabase->data[(i +
              vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                                  vehicleDatabase->size[1] * k]
                                  .yCoordinates->size[0] * 2) - 1];
            if (static_cast<int32_T>(n) > vehicleDatabase->data[(i +
                 vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].yCoordinates->size[0]) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1,
                vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                yCoordinates->size[0], &gc_emlrtBCI, sp);
            }

            yVehicle[3] = vehicleDatabase->data[(i + vehicleDatabase->size[0] *
              j) + vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
              yCoordinates->data[(static_cast<int32_T>(n) +
                                  vehicleDatabase->data[(i +
              vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                                  vehicleDatabase->size[1] * k]
                                  .yCoordinates->size[0] * 3) - 1];
            if (static_cast<int32_T>(n) > vehicleDatabase->data[(i +
                 vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                vehicleDatabase->size[1] * k].yCoordinates->size[0]) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1,
                vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                yCoordinates->size[0], &hc_emlrtBCI, sp);
            }

            yVehicle[4] = vehicleDatabase->data[(i + vehicleDatabase->size[0] *
              j) + vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
              yCoordinates->data[static_cast<int32_T>(n) - 1];
            st.site = &b_emlrtRSI;
            b_inpolygon(&st, xVehicle, yVehicle, xv, yv, b_x);
            y = false;
            xpageoffset = 0;
            exitg1 = false;
            while ((!exitg1) && (xpageoffset < 5)) {
              if (b_x[xpageoffset]) {
                y = true;
                exitg1 = true;
              } else {
                xpageoffset++;
              }
            }

            guard1 = false;
            if (y) {
              guard1 = true;
            } else {
              st.site = &c_emlrtRSI;
              b_inpolygon(&st, xv, yv, xVehicle, yVehicle, b_x);
              y = false;
              xpageoffset = 0;
              exitg1 = false;
              while ((!exitg1) && (xpageoffset < 5)) {
                if (b_x[xpageoffset]) {
                  y = true;
                  exitg1 = true;
                } else {
                  xpageoffset++;
                }
              }

              if (y) {
                guard1 = true;
              } else {
                xpageoffset = static_cast<int32_T>(counter);
                if ((xpageoffset < 1) || (xpageoffset > 10000)) {
                  emlrtDynamicBoundsCheckR2012b(xpageoffset, 1, 10000,
                    &vb_emlrtBCI, sp);
                }

                SD->f0.occupancyGrid[(xpageoffset + 10000 * m) - 1] = 0.0;
              }
            }

            if (guard1) {
              xpageoffset = i + 1;
              if ((xpageoffset < 1) || (xpageoffset > vehicleDatabase->size[0]))
              {
                emlrtDynamicBoundsCheckR2012b(xpageoffset, 1,
                  vehicleDatabase->size[0], &sb_emlrtBCI, sp);
              }

              xpageoffset = j + 1;
              if ((xpageoffset < 1) || (xpageoffset > vehicleDatabase->size[1]))
              {
                emlrtDynamicBoundsCheckR2012b(xpageoffset, 1,
                  vehicleDatabase->size[1], &tb_emlrtBCI, sp);
              }

              xpageoffset = k + 1;
              if ((xpageoffset < 1) || (xpageoffset > vehicleDatabase->size[2]))
              {
                emlrtDynamicBoundsCheckR2012b(xpageoffset, 1,
                  vehicleDatabase->size[2], &ub_emlrtBCI, sp);
              }

              if (static_cast<int32_T>(n) > vehicleDatabase->data[(i +
                   vehicleDatabase->size[0] * j) + vehicleDatabase->size[0] *
                  vehicleDatabase->size[1] * k].minProb->size[1]) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n), 1,
                  vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                  vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                  minProb->size[1], &ic_emlrtBCI, sp);
              }

              xpageoffset = static_cast<int32_T>(counter);
              if ((xpageoffset < 1) || (xpageoffset > 10000)) {
                emlrtDynamicBoundsCheckR2012b(xpageoffset, 1, 10000,
                  &jc_emlrtBCI, sp);
              }

              SD->f0.occupancyGrid[(xpageoffset + 10000 * m) - 1] =
                vehicleDatabase->data[(i + vehicleDatabase->size[0] * j) +
                vehicleDatabase->size[0] * vehicleDatabase->size[1] * k].
                minProb->data[static_cast<int32_T>(n) - 1];
            }

            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(sp);
            }
          }

          /*  END loop over the grids */
        }

        /*  END loop over the multiple hypotheses (longitudinal) */
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  END loop over the multiple hypotheses (lateral) */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  END loop over the targets */
  /*  Calculating the predicted occupancy grid */
  for (i = 0; i < 16000; i++) {
    xpageoffset = i * 10000;
    d = SD->f0.occupancyGrid[xpageoffset];
    for (k = 0; k < 9999; k++) {
      d += SD->f0.occupancyGrid[(xpageoffset + k) + 1];
    }

    occupancyGrid[i] = d;
    if (d > 1.0) {
      occupancyGrid[i] = 1.0;
    }
  }

  for (i = 0; i < 100; i++) {
    for (j = 0; j < 160; j++) {
      predictedOccupancyGrid[i + 100 * j] = occupancyGrid[j + 160 * (99 - i)];
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (generatePOG.cpp) */

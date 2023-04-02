/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * inpolygon.cpp
 *
 * Code generation for function 'inpolygon'
 *
 */

/* Include files */
#include "inpolygon.h"
#include "eml_int_forloop_overflow_check.h"
#include "generatePOG_Reference.h"
#include "generatePOG_Reference_data.h"
#include "generatePOG_Reference_emxutil.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "warning.h"

/* Variable Definitions */
static emlrtRSInfo d_emlrtRSI = { 31,  /* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 32,  /* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 33,  /* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 35,  /* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 45,  /* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 46,  /* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 329, /* lineNo */
  "computeRange",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 330, /* lineNo */
  "computeRange",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 316, /* lineNo */
  "checkRange",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 319, /* lineNo */
  "checkRange",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 192, /* lineNo */
  "computeScaleFactors",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 193, /* lineNo */
  "computeScaleFactors",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 92,  /* lineNo */
  "scalarInpolygon",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 99,  /* lineNo */
  "scalarInpolygon",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 58,  /* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 26,  /* lineNo */
  "inpolygon",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 233, /* lineNo */
  "countLoops",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 238, /* lineNo */
  "countLoops",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 250, /* lineNo */
  "countLoops",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pathName */
};

static emlrtRTEInfo b_emlrtRTEI = { 13,/* lineNo */
  23,                                  /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 262,/* lineNo */
  27,                                  /* colNo */
  "skipNaNs",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 281,/* lineNo */
  31,                                  /* colNo */
  "findLast",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 16,/* lineNo */
  1,                                   /* colNo */
  "inpolygon",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\polyfun\\inpolygon.m"/* pName */
};

/* Function Declarations */
static void checkRange(const emlrtStack *sp, real_T minxv, real_T maxxv, real_T
  minyv, real_T maxyv);
static void computeRange(const emlrtStack *sp, const real_T xv[5], int32_T
  nloops, const int32_T first[5], const int32_T last[5], real_T *minxv, real_T
  *maxxv);
static void computeScaleFactors(const emlrtStack *sp, const real_T xv[5], const
  real_T yv[5], int32_T nloops, const int32_T first[5], const int32_T last[5],
  real_T scale[5]);
static void contrib(real_T x1, real_T b_y1, real_T x2, real_T y2, int8_T quad1,
                    int8_T quad2, real_T scale, int8_T *diffQuad, boolean_T *onj);
static void countLoops(const real_T xv[5], const real_T yv[5], int32_T *nloops,
  int32_T first[5], int32_T last[5]);
static boolean_T scalarInpolygon(const emlrtStack *sp, real_T xj, real_T yj,
  const real_T xv[5], const real_T yv[5], int32_T nloops, const int32_T first[5],
  const int32_T last[5], real_T minxv, real_T maxxv, real_T minyv, real_T maxyv,
  const real_T scale[5]);

/* Function Definitions */
static void checkRange(const emlrtStack *sp, real_T minxv, real_T maxxv, real_T
  minyv, real_T maxyv)
{
  real_T xrange;
  real_T yrange;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  xrange = maxxv - minxv;
  yrange = maxyv - minyv;
  if ((!(xrange >= 1.0E-15)) || (!(yrange >= 1.0E-15))) {
    st.site = &m_emlrtRSI;
    warning(&st);
  }

  if ((!(xrange <= 1.0E+150)) || (!(yrange <= 1.0E+150))) {
    st.site = &n_emlrtRSI;
    b_warning(&st);
  }
}

static void computeRange(const emlrtStack *sp, const real_T xv[5], int32_T
  nloops, const int32_T first[5], const int32_T last[5], real_T *minxv, real_T
  *maxxv)
{
  int32_T k;
  int32_T a;
  int32_T b;
  int32_T j;
  real_T d;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  *minxv = xv[first[0] - 1];
  *maxxv = *minxv;
  st.site = &j_emlrtRSI;
  if (nloops > 2147483646) {
    b_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (k = 0; k < nloops; k++) {
    a = first[k];
    b = last[k];
    st.site = &k_emlrtRSI;
    if ((first[k] <= last[k]) && (last[k] > 2147483646)) {
      b_st.site = &l_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (j = a; j <= b; j++) {
      d = xv[j - 1];
      if (d < *minxv) {
        *minxv = d;
      } else {
        if (d > *maxxv) {
          *maxxv = d;
        }
      }
    }
  }
}

static void computeScaleFactors(const emlrtStack *sp, const real_T xv[5], const
  real_T yv[5], int32_T nloops, const int32_T first[5], const int32_T last[5],
  real_T scale[5])
{
  int32_T i;
  int32_T j;
  int32_T a;
  int32_T b;
  real_T b_a;
  real_T b_b;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i = 0; i < 5; i++) {
    scale[i] = 0.0;
  }

  st.site = &o_emlrtRSI;
  if (nloops > 2147483646) {
    b_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (j = 0; j < nloops; j++) {
    a = first[j];
    b = last[j] - 1;
    st.site = &p_emlrtRSI;
    if ((first[j] <= last[j] - 1) && (last[j] - 1 > 2147483646)) {
      b_st.site = &l_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (i = a; i <= b; i++) {
      b_a = muDoubleScalarAbs(0.5 * (xv[i - 1] + xv[i]));
      b_b = muDoubleScalarAbs(0.5 * (yv[i - 1] + yv[i]));
      if ((b_a > 1.0) && (b_b > 1.0)) {
        b_a *= b_b;
      } else {
        if ((b_b > b_a) || muDoubleScalarIsNaN(b_a)) {
          b_a = b_b;
        }
      }

      scale[i - 1] = b_a * 6.6613381477509392E-16;
    }

    b_a = muDoubleScalarAbs(0.5 * (xv[last[j] - 1] + xv[first[j] - 1]));
    b_b = muDoubleScalarAbs(0.5 * (yv[last[j] - 1] + yv[first[j] - 1]));
    if ((b_a > 1.0) && (b_b > 1.0)) {
      b_a *= b_b;
    } else {
      if ((b_b > b_a) || muDoubleScalarIsNaN(b_a)) {
        b_a = b_b;
      }
    }

    scale[last[j] - 1] = b_a * 6.6613381477509392E-16;
  }
}

static void contrib(real_T x1, real_T b_y1, real_T x2, real_T y2, int8_T quad1,
                    int8_T quad2, real_T scale, int8_T *diffQuad, boolean_T *onj)
{
  real_T cp;
  *onj = false;
  *diffQuad = static_cast<int8_T>((quad2 - quad1));
  cp = x1 * y2 - x2 * b_y1;
  if (muDoubleScalarAbs(cp) < scale) {
    *onj = (x1 * x2 + b_y1 * y2 <= 0.0);
    if ((*diffQuad == 2) || (*diffQuad == -2)) {
      *diffQuad = 0;
    } else if (*diffQuad == -3) {
      *diffQuad = 1;
    } else {
      if (*diffQuad == 3) {
        *diffQuad = -1;
      }
    }
  } else if (cp < 0.0) {
    if (*diffQuad == 2) {
      *diffQuad = -2;
    } else if (*diffQuad == -3) {
      *diffQuad = 1;
    } else {
      if (*diffQuad == 3) {
        *diffQuad = -1;
      }
    }
  } else if (*diffQuad == -2) {
    *diffQuad = 2;
  } else if (*diffQuad == -3) {
    *diffQuad = 1;
  } else {
    if (*diffQuad == 3) {
      *diffQuad = -1;
    }
  }
}

static void countLoops(const real_T xv[5], const real_T yv[5], int32_T *nloops,
  int32_T first[5], int32_T last[5])
{
  int32_T i;
  for (i = 0; i < 5; i++) {
    first[i] = 0;
    last[i] = 0;
  }

  *nloops = 1;
  first[0] = 1;
  if ((xv[4] == xv[0]) && (yv[4] == yv[0])) {
    last[0] = 4;
  } else {
    last[0] = 5;
  }
}

static boolean_T scalarInpolygon(const emlrtStack *sp, real_T xj, real_T yj,
  const real_T xv[5], const real_T yv[5], int32_T nloops, const int32_T first[5],
  const int32_T last[5], real_T minxv, real_T maxxv, real_T minyv, real_T maxyv,
  const real_T scale[5])
{
  boolean_T inj;
  int8_T sdq;
  int32_T k;
  int32_T exitg2;
  real_T xvFirst;
  real_T yvFirst;
  int8_T quadFirst;
  real_T xv2;
  real_T yv2;
  int8_T quad2;
  int32_T i;
  int32_T exitg1;
  int8_T dquad;
  boolean_T onj;
  real_T xv1;
  real_T yv1;
  int8_T quad1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  inj = false;
  if ((xj >= minxv) && (xj <= maxxv) && (yj >= minyv) && (yj <= maxyv)) {
    sdq = 0;
    st.site = &q_emlrtRSI;
    if (nloops > 2147483646) {
      b_st.site = &l_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    k = 0;
    do {
      exitg2 = 0;
      if (k <= nloops - 1) {
        xvFirst = xv[first[k] - 1] - xj;
        yvFirst = yv[first[k] - 1] - yj;
        if (xvFirst > 0.0) {
          if (yvFirst > 0.0) {
            quadFirst = 0;
          } else {
            quadFirst = 3;
          }
        } else if (yvFirst > 0.0) {
          quadFirst = 1;
        } else {
          quadFirst = 2;
        }

        xv2 = xvFirst;
        yv2 = yvFirst;
        quad2 = quadFirst;
        st.site = &r_emlrtRSI;
        if ((first[k] <= last[k] - 1) && (last[k] - 1 > 2147483646)) {
          b_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        i = first[k];
        do {
          exitg1 = 0;
          if (i <= last[k] - 1) {
            xv1 = xv2;
            yv1 = yv2;
            xv2 = xv[i] - xj;
            yv2 = yv[i] - yj;
            quad1 = quad2;
            if (xv2 > 0.0) {
              if (yv2 > 0.0) {
                quad2 = 0;
              } else {
                quad2 = 3;
              }
            } else if (yv2 > 0.0) {
              quad2 = 1;
            } else {
              quad2 = 2;
            }

            contrib(xv1, yv1, xv2, yv2, quad1, quad2, scale[i - 1], &dquad, &onj);
            if (onj) {
              inj = true;
              exitg1 = 1;
            } else {
              sdq = static_cast<int8_T>((sdq + dquad));
              i++;
            }
          } else {
            contrib(xv2, yv2, xvFirst, yvFirst, quad2, quadFirst, scale[last[k]
                    - 1], &dquad, &onj);
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = 1;
        } else if (onj) {
          inj = true;
          exitg2 = 1;
        } else {
          sdq = static_cast<int8_T>((sdq + dquad));
          k++;
        }
      } else {
        inj = (sdq != 0);
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }

  return inj;
}

void b_inpolygon(const emlrtStack *sp, const real_T x[5], const real_T y[5],
                 const real_T xv[5], const real_T yv[5], boolean_T in[5])
{
  int32_T i;
  int32_T first[5];
  int32_T last[5];
  real_T minxv;
  real_T maxxv;
  real_T minyv;
  real_T maxyv;
  real_T scale[5];
  int32_T j;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i = 0; i < 5; i++) {
    in[i] = false;
  }

  countLoops(xv, yv, &i, first, last);
  if (i != 0) {
    st.site = &d_emlrtRSI;
    computeRange(&st, xv, i, first, last, &minxv, &maxxv);
    st.site = &e_emlrtRSI;
    computeRange(&st, yv, i, first, last, &minyv, &maxyv);
    st.site = &f_emlrtRSI;
    checkRange(&st, minxv, maxxv, minyv, maxyv);
    st.site = &g_emlrtRSI;
    computeScaleFactors(&st, xv, yv, i, first, last, scale);
    for (j = 0; j < 5; j++) {
      st.site = &u_emlrtRSI;
      in[j] = scalarInpolygon(&st, x[j], y[j], xv, yv, i, first, last, minxv,
        maxxv, minyv, maxyv, scale);
    }
  }
}

void c_inpolygon(const emlrtStack *sp, const real_T x[5], const real_T y[5],
                 const real_T xv[5], const real_T yv[5], boolean_T in[5])
{
  int32_T kfirst;
  int32_T nloops;
  int32_T i;
  int32_T first[5];
  int32_T k;
  int32_T last[5];
  boolean_T exitg1;
  boolean_T isnanxv;
  real_T minxv;
  real_T maxxv;
  real_T minyv;
  real_T maxyv;
  real_T scale[5];
  boolean_T isnanyv;
  int32_T j;
  real_T a;
  real_T b;
  int8_T sdq;
  int32_T exitg3;
  real_T xvFirst;
  real_T yvFirst;
  int8_T quadFirst;
  real_T xv2;
  real_T yv2;
  int8_T quad2;
  int32_T exitg2;
  int8_T dquad;
  real_T xv1;
  real_T yv1;
  int8_T quad1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  for (kfirst = 0; kfirst < 5; kfirst++) {
    in[kfirst] = false;
  }

  st.site = &v_emlrtRSI;
  nloops = -1;
  for (i = 0; i < 5; i++) {
    first[i] = 0;
    last[i] = 0;
  }

  b_st.site = &w_emlrtRSI;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k + 1 <= 5)) {
    isnanxv = muDoubleScalarIsNaN(xv[k]);
    if (isnanxv != muDoubleScalarIsNaN(yv[k])) {
      emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI,
        "MATLAB:inpolygon:InvalidLoopDef", "MATLAB:inpolygon:InvalidLoopDef", 0);
    }

    if (!isnanxv) {
      exitg1 = true;
    } else {
      k++;
    }
  }

  while (k + 1 <= 5) {
    nloops++;
    kfirst = k;
    first[nloops] = k + 1;
    b_st.site = &x_emlrtRSI;
    exitg1 = false;
    while ((!exitg1) && (k + 1 < 5)) {
      k++;
      isnanxv = muDoubleScalarIsNaN(xv[k]);
      isnanyv = muDoubleScalarIsNaN(yv[k]);
      if (isnanxv || isnanyv) {
        if (isnanxv != isnanyv) {
          emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
            "MATLAB:inpolygon:InvalidLoopDef", "MATLAB:inpolygon:InvalidLoopDef",
            0);
        }

        k--;
        exitg1 = true;
      }
    }

    if ((xv[k] == xv[kfirst]) && (yv[k] == yv[kfirst])) {
      last[nloops] = k;
    } else {
      last[nloops] = k + 1;
    }

    k += 2;
    b_st.site = &y_emlrtRSI;
    exitg1 = false;
    while ((!exitg1) && (k + 1 <= 5)) {
      isnanxv = muDoubleScalarIsNaN(xv[k]);
      if (isnanxv != muDoubleScalarIsNaN(yv[k])) {
        emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI,
          "MATLAB:inpolygon:InvalidLoopDef", "MATLAB:inpolygon:InvalidLoopDef",
          0);
      }

      if (!isnanxv) {
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (nloops + 1 != 0) {
    st.site = &d_emlrtRSI;
    computeRange(&st, xv, nloops + 1, first, last, &minxv, &maxxv);
    st.site = &e_emlrtRSI;
    computeRange(&st, yv, nloops + 1, first, last, &minyv, &maxyv);
    st.site = &f_emlrtRSI;
    checkRange(&st, minxv, maxxv, minyv, maxyv);
    st.site = &g_emlrtRSI;
    for (i = 0; i < 5; i++) {
      scale[i] = 0.0;
    }

    b_st.site = &o_emlrtRSI;
    if (nloops + 1 > 2147483646) {
      c_st.site = &l_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (j = 0; j <= nloops; j++) {
      kfirst = first[j];
      k = last[j] - 1;
      b_st.site = &p_emlrtRSI;
      if ((first[j] <= last[j] - 1) && (last[j] - 1 > 2147483646)) {
        c_st.site = &l_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (i = kfirst; i <= k; i++) {
        a = muDoubleScalarAbs(0.5 * (xv[i - 1] + xv[i]));
        b = muDoubleScalarAbs(0.5 * (yv[i - 1] + yv[i]));
        if ((a > 1.0) && (b > 1.0)) {
          a *= b;
        } else {
          if ((b > a) || muDoubleScalarIsNaN(a)) {
            a = b;
          }
        }

        scale[i - 1] = a * 6.6613381477509392E-16;
      }

      a = muDoubleScalarAbs(0.5 * (xv[last[j] - 1] + xv[first[j] - 1]));
      b = muDoubleScalarAbs(0.5 * (yv[last[j] - 1] + yv[first[j] - 1]));
      if ((a > 1.0) && (b > 1.0)) {
        a *= b;
      } else {
        if ((b > a) || muDoubleScalarIsNaN(a)) {
          a = b;
        }
      }

      scale[last[j] - 1] = a * 6.6613381477509392E-16;
    }

    for (j = 0; j < 5; j++) {
      st.site = &u_emlrtRSI;
      a = x[j];
      b = y[j];
      in[j] = false;
      if ((a >= minxv) && (a <= maxxv) && (b >= minyv) && (b <= maxyv)) {
        sdq = 0;
        b_st.site = &q_emlrtRSI;
        k = 0;
        do {
          exitg3 = 0;
          if (k <= nloops) {
            xvFirst = xv[first[k] - 1] - a;
            yvFirst = yv[first[k] - 1] - b;
            if (xvFirst > 0.0) {
              if (yvFirst > 0.0) {
                quadFirst = 0;
              } else {
                quadFirst = 3;
              }
            } else if (yvFirst > 0.0) {
              quadFirst = 1;
            } else {
              quadFirst = 2;
            }

            xv2 = xvFirst;
            yv2 = yvFirst;
            quad2 = quadFirst;
            b_st.site = &r_emlrtRSI;
            if ((first[k] <= last[k] - 1) && (last[k] - 1 > 2147483646)) {
              c_st.site = &l_emlrtRSI;
              check_forloop_overflow_error(&c_st);
            }

            i = first[k];
            do {
              exitg2 = 0;
              if (i <= last[k] - 1) {
                xv1 = xv2;
                yv1 = yv2;
                xv2 = xv[i] - a;
                yv2 = yv[i] - b;
                quad1 = quad2;
                if (xv2 > 0.0) {
                  if (yv2 > 0.0) {
                    quad2 = 0;
                  } else {
                    quad2 = 3;
                  }
                } else if (yv2 > 0.0) {
                  quad2 = 1;
                } else {
                  quad2 = 2;
                }

                contrib(xv1, yv1, xv2, yv2, quad1, quad2, scale[i - 1], &dquad,
                        &isnanxv);
                if (isnanxv) {
                  in[j] = true;
                  exitg2 = 1;
                } else {
                  sdq = static_cast<int8_T>((sdq + dquad));
                  i++;
                }
              } else {
                contrib(xv2, yv2, xvFirst, yvFirst, quad2, quadFirst,
                        scale[last[k] - 1], &dquad, &isnanxv);
                exitg2 = 2;
              }
            } while (exitg2 == 0);

            if (exitg2 == 1) {
              exitg3 = 1;
            } else if (isnanxv) {
              in[j] = true;
              exitg3 = 1;
            } else {
              sdq = static_cast<int8_T>((sdq + dquad));
              k++;
            }
          } else {
            in[j] = (sdq != 0);
            exitg3 = 1;
          }
        } while (exitg3 == 0);
      }
    }
  }
}

void inpolygon(const emlrtStack *sp, const emxArray_real_T *x, const
               emxArray_real_T *y, const real_T xv[5], const real_T yv[5],
               emxArray_boolean_T *in)
{
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T p;
  int32_T nloops;
  boolean_T exitg1;
  boolean_T b_p;
  int32_T loop_ub;
  int32_T first[5];
  int32_T last[5];
  real_T minxv;
  real_T maxxv;
  real_T minyv;
  real_T maxyv;
  real_T scale[5];
  int32_T j;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  boolean_T emlrtHadParallelError = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  varargin_1[0] = static_cast<uint32_T>(x->size[0]);
  varargin_1[1] = 1U;
  varargin_2[0] = static_cast<uint32_T>(y->size[0]);
  varargin_2[1] = 1U;
  p = true;
  nloops = 0;
  exitg1 = false;
  while ((!exitg1) && (nloops < 2)) {
    if (static_cast<int32_T>(varargin_1[nloops]) != static_cast<int32_T>
        (varargin_2[nloops])) {
      p = false;
      exitg1 = true;
    } else {
      nloops++;
    }
  }

  b_p = p;
  if (!b_p) {
    emlrtErrorWithMessageIdR2018a(sp, &b_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  nloops = in->size[0];
  in->size[0] = x->size[0];
  emxEnsureCapacity_boolean_T(sp, in, nloops, &g_emlrtRTEI);
  loop_ub = x->size[0];
  for (nloops = 0; nloops < loop_ub; nloops++) {
    in->data[nloops] = false;
  }

  if (x->size[0] != 0) {
    countLoops(xv, yv, &nloops, first, last);
    if (nloops != 0) {
      st.site = &d_emlrtRSI;
      computeRange(&st, xv, nloops, first, last, &minxv, &maxxv);
      st.site = &e_emlrtRSI;
      computeRange(&st, yv, nloops, first, last, &minyv, &maxyv);
      st.site = &f_emlrtRSI;
      checkRange(&st, minxv, maxxv, minyv, maxyv);
      st.site = &g_emlrtRSI;
      computeScaleFactors(&st, xv, yv, nloops, first, last, scale);
      st.site = &h_emlrtRSI;
      if (x->size[0] > 2147483646) {
        b_st.site = &l_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      loop_ub = x->size[0] - 1;
      emlrtEnterParallelRegion(sp, omp_in_parallel());

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(d_st) \
 firstprivate(c_st,emlrtHadParallelError)

      {
        try {
          c_st.prev = sp;
          c_st.tls = emlrtAllocTLS((emlrtStack *)sp, omp_get_thread_num());
          c_st.site = NULL;
          d_st.prev = &c_st;
          d_st.tls = c_st.tls;
        } catch (...) {
          emlrtHadParallelError = true;
        }

#pragma omp for nowait

        for (j = 0; j <= loop_ub; j++) {
          if (emlrtHadParallelError)
            continue;
          try {
            d_st.site = &i_emlrtRSI;
            in->data[j] = scalarInpolygon(&d_st, x->data[j], y->data[j], xv, yv,
              nloops, first, last, minxv, maxxv, minyv, maxyv, scale);
          } catch (...) {
            emlrtHadParallelError = true;
          }
        }
      }

      emlrtExitParallelRegion(sp, omp_in_parallel());
    }
  }
}

/* End of code generation (inpolygon.cpp) */

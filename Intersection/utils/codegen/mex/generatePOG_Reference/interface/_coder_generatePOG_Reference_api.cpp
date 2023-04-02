/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_generatePOG_Reference_api.cpp
 *
 * Code generation for function '_coder_generatePOG_Reference_api'
 *
 */

/* Include files */
#include "_coder_generatePOG_Reference_api.h"
#include "generatePOG_Reference.h"
#include "generatePOG_Reference_data.h"
#include "generatePOG_Reference_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo h_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_generatePOG_Reference_api",  /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *vehicle,
  const char_T *identifier, emxArray_struct0_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_struct0_T *y);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *x_Road, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const real_T u[16000]);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *n, const
  char_T *identifier);
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *vehicle,
  const char_T *identifier, emxArray_struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(vehicle), &thisId, y);
  emlrtDestroyArray(&vehicle);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[9] = { "bboxX", "bboxY", "posX", "posY", "psi",
    "v", "aX", "aY", "time" };

  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv[2] = { false, true };

  int32_T sizes[2];
  int32_T i;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckVsStructR2012b(sp, parentId, u, 9, fieldNames, 2U, dims, &bv[0],
    sizes);
  i = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_struct0_T(sp, y, i, (emlrtRTEInfo *)NULL);
  for (i = 0; i < sizes[1]; i++) {
    thisId.fIdentifier = "bboxX";
    e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i, 0, "bboxX")),
                       &thisId, y->data[i].bboxX);
    thisId.fIdentifier = "bboxY";
    e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i, 1, "bboxY")),
                       &thisId, y->data[i].bboxY);
    thisId.fIdentifier = "posX";
    f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i, 2, "posX")),
                       &thisId, y->data[i].posX);
    thisId.fIdentifier = "posY";
    f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i, 3, "posY")),
                       &thisId, y->data[i].posY);
    thisId.fIdentifier = "psi";
    f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i, 4, "psi")),
                       &thisId, y->data[i].psi);
    thisId.fIdentifier = "v";
    f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i, 5, "v")),
                       &thisId, y->data[i].v);
    thisId.fIdentifier = "aX";
    f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i, 6, "aX")),
                       &thisId, y->data[i].aX);
    thisId.fIdentifier = "aY";
    f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i, 7, "aY")),
                       &thisId, y->data[i].aY);
    thisId.fIdentifier = "time";
    f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, i, 8, "time")),
                       &thisId, y->data[i].time);
  }

  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  j_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *x_Road, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(x_Road), &thisId, y);
  emlrtDestroyArray(&x_Road);
}

static const mxArray *emlrt_marshallOut(const real_T u[16000])
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 0, 0 };

  static const int32_T iv1[2] = { 100, 160 };

  y = NULL;
  m = emlrtCreateNumericArray(2, iv, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, *(int32_T (*)[2])&iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *n, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(n), &thisId);
  emlrtDestroyArray(&n);
  return y;
}

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[1] = { -1 };

  const boolean_T bv[1] = { true };

  int32_T iv[1];
  int32_T i;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv[0],
    iv);
  ret->allocatedSize = iv[0];
  i = ret->size[0];
  ret->size[0] = iv[0];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 4, -1 };

  const boolean_T bv[2] = { false, true };

  int32_T iv[2];
  int32_T i;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv[2] = { false, true };

  int32_T iv[2];
  int32_T i;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void generatePOG_Reference_api(generatePOG_ReferenceStackData *SD, const mxArray
  * const prhs[5], int32_T, const mxArray *plhs[1])
{
  real_T (*POG)[16000];
  emxArray_real_T *x_Road;
  emxArray_real_T *y_Road;
  emxArray_struct0_T *vehicle;
  const mxArray *prhs_copy_idx_0;
  const mxArray *prhs_copy_idx_1;
  real_T n;
  real_T initialID;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  POG = (real_T (*)[16000])mxMalloc(sizeof(real_T [16000]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &x_Road, 1, &h_emlrtRTEI, true);
  emxInit_real_T(&st, &y_Road, 1, &h_emlrtRTEI, true);
  emxInit_struct0_T(&st, &vehicle, 2, &h_emlrtRTEI, true);
  prhs_copy_idx_0 = emlrtProtectR2012b(prhs[0], 0, false, -1);
  prhs_copy_idx_1 = emlrtProtectR2012b(prhs[1], 1, false, -1);

  /* Marshall function inputs */
  x_Road->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "x_Road", x_Road);
  y_Road->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_1), "y_Road", y_Road);
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "vehicle", vehicle);
  n = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "n");
  initialID = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "initialID");

  /* Invoke the target function */
  generatePOG_Reference(SD, &st, x_Road, y_Road, vehicle, n, initialID, *POG);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*POG);
  emxFree_struct0_T(&vehicle);
  emxFree_real_T(&y_Road);
  emxFree_real_T(&x_Road);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_generatePOG_Reference_api.cpp) */

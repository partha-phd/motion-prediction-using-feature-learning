/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generatePOG_Reference_initialize.cpp
 *
 * Code generation for function 'generatePOG_Reference_initialize'
 *
 */

/* Include files */
#include "generatePOG_Reference_initialize.h"
#include "_coder_generatePOG_Reference_mex.h"
#include "generatePOG_Reference.h"
#include "generatePOG_Reference_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void generatePOG_Reference_initialize()
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (generatePOG_Reference_initialize.cpp) */

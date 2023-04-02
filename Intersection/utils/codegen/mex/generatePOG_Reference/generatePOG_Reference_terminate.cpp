/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generatePOG_Reference_terminate.cpp
 *
 * Code generation for function 'generatePOG_Reference_terminate'
 *
 */

/* Include files */
#include "generatePOG_Reference_terminate.h"
#include "_coder_generatePOG_Reference_mex.h"
#include "generatePOG_Reference.h"
#include "generatePOG_Reference_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void generatePOG_Reference_atexit()
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void generatePOG_Reference_terminate()
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (generatePOG_Reference_terminate.cpp) */

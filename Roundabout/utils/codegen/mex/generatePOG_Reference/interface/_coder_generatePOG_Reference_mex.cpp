/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_generatePOG_Reference_mex.cpp
 *
 * Code generation for function '_coder_generatePOG_Reference_mex'
 *
 */

/* Include files */
#include "_coder_generatePOG_Reference_mex.h"
#include "_coder_generatePOG_Reference_api.h"
#include "generatePOG_Reference.h"
#include "generatePOG_Reference_data.h"
#include "generatePOG_Reference_initialize.h"
#include "generatePOG_Reference_mexutil.h"
#include "generatePOG_Reference_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void c_generatePOG_Reference_mexFunc
  (generatePOG_ReferenceStackData *SD, int32_T nlhs, mxArray *plhs[1], int32_T
   nrhs, const mxArray *prhs[4]);

/* Function Definitions */
void c_generatePOG_Reference_mexFunc(generatePOG_ReferenceStackData *SD, int32_T
  nlhs, mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[4])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        21, "generatePOG_Reference");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 21,
                        "generatePOG_Reference");
  }

  /* Call the function. */
  generatePOG_Reference_api(SD, prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  generatePOG_ReferenceStackData *c_generatePOG_ReferenceStackDat = NULL;
  c_generatePOG_ReferenceStackDat = (generatePOG_ReferenceStackData *)
    emlrtMxCalloc(1, (size_t)1U * sizeof(generatePOG_ReferenceStackData));
  mexAtExit(generatePOG_Reference_atexit);
  emlrtLoadLibrary("C:\\ProgramData\\MATLAB\\SupportPackages\\R2019b\\3P.instrset\\mingw_w64.instrset\\bin\\libgomp-1.dll");

  /* Initialize the memory manager. */
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&emlrtNestLockGlobal);

  /* Module initialization. */
  generatePOG_Reference_initialize();
  st.tls = emlrtRootTLSGlobal;
  try {
    /* Dispatch the entry-point. */
    c_generatePOG_Reference_mexFunc(c_generatePOG_ReferenceStackDat, nlhs, plhs,
      nrhs, prhs);

    /* Module termination. */
    generatePOG_Reference_terminate();
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
  } catch (...) {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
  }

  emlrtMxFree(c_generatePOG_ReferenceStackDat);
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                     emlrtLockerFunction, omp_get_num_procs());
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_generatePOG_Reference_mex.cpp) */

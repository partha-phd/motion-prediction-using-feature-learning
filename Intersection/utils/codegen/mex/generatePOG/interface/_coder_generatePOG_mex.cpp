/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_generatePOG_mex.cpp
 *
 * Code generation for function '_coder_generatePOG_mex'
 *
 */

/* Include files */
#include "_coder_generatePOG_mex.h"
#include "_coder_generatePOG_api.h"
#include "generatePOG.h"
#include "generatePOG_data.h"
#include "generatePOG_initialize.h"
#include "generatePOG_mexutil.h"
#include "generatePOG_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void generatePOG_mexFunction(generatePOGStackData *SD,
  int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[4]);

/* Function Definitions */
void generatePOG_mexFunction(generatePOGStackData *SD, int32_T nlhs, mxArray
  *plhs[1], int32_T nrhs, const mxArray *prhs[4])
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
                        11, "generatePOG");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "generatePOG");
  }

  /* Call the function. */
  generatePOG_api(SD, prhs, nlhs, outputs);

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

  generatePOGStackData *generatePOGStackDataGlobal = NULL;
  generatePOGStackDataGlobal = (generatePOGStackData *)emlrtMxCalloc(1, (size_t)
    1U * sizeof(generatePOGStackData));
  mexAtExit(generatePOG_atexit);
  emlrtLoadLibrary("C:\\ProgramData\\MATLAB\\SupportPackages\\R2019b\\3P.instrset\\mingw_w64.instrset\\bin\\libgomp-1.dll");

  /* Initialize the memory manager. */
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&emlrtNestLockGlobal);

  /* Module initialization. */
  generatePOG_initialize();
  st.tls = emlrtRootTLSGlobal;
  try {
    /* Dispatch the entry-point. */
    generatePOG_mexFunction(generatePOGStackDataGlobal, nlhs, plhs, nrhs, prhs);

    /* Module termination. */
    generatePOG_terminate();
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
  } catch (...) {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
  }

  emlrtMxFree(generatePOGStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                     emlrtLockerFunction, omp_get_num_procs());
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_generatePOG_mex.cpp) */

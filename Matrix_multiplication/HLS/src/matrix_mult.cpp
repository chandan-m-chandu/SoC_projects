/*
// matrix_multiplier.cpp
#include "matrix_mult.h"

void matrix_multiply(int A[N][N], int B[N][N], int C[N][N]) {

    for (int i = 0; i < N; i++) {
        #pragma HLS PIPELINE II=2
        for (int j = 0; j < N; j++) {
            #pragma HLS UNROLL
            int sum = 0;
            for (int k = 0; k < N; k++) {
                
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}
*/
//##################################################################################

/*
// matrix_multiplier.cpp
#include "matrix_mult.h"

void matrix_multiply(int *A, int *B, int *C) {
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE m_axi port=B offset=slave bundle=gmem
    #pragma HLS INTERFACE m_axi port=C offset=slave bundle=gmem

    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE s_axilite port=B bundle=control
    #pragma HLS INTERFACE s_axilite port=C bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control

// Tell HLS these arrays don't have inter-iteration dependencies
    #pragma HLS DEPENDENCE variable=A inter false
    #pragma HLS DEPENDENCE variable=B inter false
    #pragma HLS DEPENDENCE variable=C inter false

    for (int i = 0; i < N; i++) {
        #pragma HLS UNROLL
        for (int j = 0; j < N; j++) {
            #pragma HLS UNROLL
             int sum  = 0;
            for (int k = 0; k < N; k++) {
                #pragma HLS UNROLL
                sum  += A[i * N + k] * B[k * N + j];
            }
           C[i * N + j] = sum;
        }
    }
}
*/
//####################################################################################################################

// matrix_multiplier.cpp
#include "matrix_mult.h"

void matrix_multiply(int *A, int *B, int *C) {
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE m_axi port=B offset=slave bundle=gmem
    #pragma HLS INTERFACE m_axi port=C offset=slave bundle=gmem

    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE s_axilite port=B bundle=control
    #pragma HLS INTERFACE s_axilite port=C bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control

/*// Tell HLS these arrays don't have inter-iteration dependencies
    #pragma HLS DEPENDENCE variable=A inter false
    #pragma HLS DEPENDENCE variable=B inter false
    #pragma HLS DEPENDENCE variable=C inter false
*/
    for (int i = 0; i < N; i++) {
        #pragma HLS PIPELINE II=3
        //#pragma HLS UNROLL
        for (int j = 0; j < N; j++) {
            #pragma HLS PIPELINE II=1
              C[i * N + j]  = 0;
            for (int k = 0; k < N; k++) {
                #pragma HLS PIPELINE II=1
                C[i * N + j]  += A[i * N + k] * B[k * N + j];
            }
           //C[i * N + j] = sum;
        }
    }
}
/*
 * processing.c
 *
 *  Created on: 29.02.2016.
 *      Author: Dejan Bokan (dejan.bokan@rt-rk.com)
 */

#include "processing.h"
#include "filter_coeff.h"
#include "fir.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void downsample(Int16 *input, Int16 *output, int M, int N)
{
	int i, j;
	/*Moze i do j=N/M*/
	for(i = 0, j = 0; i<N; i += M, j++)
	{
		output[j] = input[i];
	}
}

void decimate(Int16 *input, Int16 *output, int M, int N)
{
	Int16 his[N_COEFF];
	memset(his, 0, sizeof(his));
	int i;

	for(i=0; i < N; i++)
	{
		input[i] = fir_basic(input[i], lp_filter, his, N_COEFF);
	}

	downsample(input, output, M, N);

}

void upsample(Int16 *input, Int16 *output, int L, int N)
{
	int i;
	memset(output, 0, sizeof(Int16)* N*L);
	for(i=0; i<N; i++)
	{
		output[i*L]= input[i];
	}
}

void interpolate(Int16 *input, Int16 *output, int L, int N)
{
	upsample(input, output, L, N);

	Int16 his[N_COEFF];
	memset(his, 0, sizeof(his));
	int i;

	for(i=0; i<N*L; i++)
	{
		output[i] = fir_basic(output[i], lp_filter, his, N_COEFF);
	}
}

void resample(Int16 *input, Int16 *output, int L, int M, int N)
{
	upsample(input, output, L, N);

	Int16 his[N_COEFF];
	memset(his, 0, sizeof(his));
	int i;

	for(i=0; i<N*L; i++)
	{
		output[i] = fir_basic(output[i], lp_filter, his, N_COEFF);
	}

	downsample(input, output, M, N*L);

}

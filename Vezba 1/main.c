//////////////////////////////////////////////////////////////////////////////
// * File name: main.c
// *
// * Description:  Vezba 1 - Interpolacija i decimacija
// *
// * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
// * Copyright (C) 2011 Spectrum Digital, Incorporated
// *
//////////////////////////////////////////////////////////////////////////////

#include "tistdtypes.h"
#include <cstdio>
#include "ezdsp5535.h"
#include "math.h"
#include "signal.h"
#include "filter_coeff.h"
#include "processing.h"


Int16 OutputBuffer1[SIGNAL1_LENGTH];
Int16 OutputBuffer2[SIGNAL2_LENGTH];
Int16 OutputBufferResapmep[SIGNAL3_LENGTH];
int M = 4;
int L = 3;


void main( void )
{
/* signal1 ulaz u 1. i 2. zad
 * a za ostale signal2       */
	printf("\n Vezba 1 - Interpolacija i decimacija \n");

	//downsample(signal1, OutputBuffer1, M, SIGNAL1_LENGTH);
	//decimate(signal1, OutputBuffer1, M, SIGNAL1_LENGTH);

	//upsample(signal2, OutputBuffer2, L, SIGNAL2_LENGTH);
	//interpolate(signal2, OutputBuffer1, L, SIGNAL2_LENGTH);

	resample(signal2, OutputBufferResapmep, L, M, SIGNAL2_LENGTH);

	printf( "\n***Program has Terminated***\n" );
	SW_BREAKPOINT;
}


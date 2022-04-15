#ifndef _UPLEARN_H_
#define _UPLEARN_H_

#include<stdio.h>
#include<stdlib.h>

constexpr auto NumSizeofMax = 50;

namespace UpLearn {

	typedef struct {
		int *data;
		int numLength;
	}StructMyArray1;

	void funcCreat1(StructMyArray1& L) {
		L.data = (int*)malloc(sizeof(int) * NumSizeofMax);
	}

	typedef struct {
		int data[NumSizeofMax];
		int numMaxSize;
		int numArrLen;
	}StructMyArray2;

	void funcCreat2(StructMyArray2* L) {
		L = (StructMyArray2*)malloc(sizeof(StructMyArray2));
	}
}

#endif
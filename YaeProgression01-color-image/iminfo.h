#pragma once
#include "pch.h"
void printType(Mat &mat) {
	if (mat.depth() == CV_8U)  printf("unsigned char(%d)", mat.channels());
	else if (mat.depth() == CV_8S)  printf("signed char(%d)", mat.channels());
	else if (mat.depth() == CV_16U) printf("unsigned short(%d)", mat.channels());
	else if (mat.depth() == CV_16S) printf("signed short(%d)", mat.channels());
	else if (mat.depth() == CV_32S) printf("signed int(%d)", mat.channels());
	else if (mat.depth() == CV_32F) printf("float(%d)", mat.channels());
	else if (mat.depth() == CV_64F) printf("double(%d)", mat.channels());
	else                           printf("unknown(%d)", mat.channels());
}

void printInfo(const char *prefix, Mat &mat) {
	printf("%s: ", prefix);
	printf("dim(%d, %d)", mat.rows, mat.cols);
	printType(mat);
	printf("\n");
}

void printInfo(Mat &mat) {
	printf("dim(%d, %d)", mat.rows, mat.cols);
	printType(mat);
	printf("\n");
}
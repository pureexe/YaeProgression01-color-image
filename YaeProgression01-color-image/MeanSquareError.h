#pragma once
#include "pch.h"
double MeanSquareError(Mat input, Mat reference) {
	double sumSquareError = 0.0;
	Mat sumDiff;
	absdiff(input, reference, sumDiff);
	sumDiff = sumDiff.mul(sumDiff);
	int channel = input.channels();
	int totalPixel = input.rows * input.cols * channel;
	int i = 0;
	Scalar channelSum = sum(sumDiff);
	for (i = 0; i < channel; i++) {
		sumSquareError += channelSum[i];
	}
	return  sumSquareError / totalPixel;
}
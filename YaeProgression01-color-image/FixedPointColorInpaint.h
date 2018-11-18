#pragma once
#include"pch.h"
#include"FixedPointInpaint.h"
Mat FixedPointColorInpaint(Mat toinpaint_image, Mat inpaint_domain, double lambda, double beta, int gaussseidel_iteration, double tolerent, double max_iteration) {
	int i;
	int channel = toinpaint_image.channels();
	Mat toInpaints[4], results[4], result;
	split(toinpaint_image, toInpaints);
	for (i = 0; i < channel; i++) {
		results[i] = FixedPointInpaint(toInpaints[i],inpaint_domain, lambda, beta, gaussseidel_iteration, tolerent, max_iteration);
	}
	merge(results, channel, result);
	return result;
}
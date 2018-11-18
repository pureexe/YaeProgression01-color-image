#pragma once
#include "pch.h"
#include "LinearLizeInpaint.h"
Mat LinearLizeColorInpaint(Mat toinpaint_image, Mat inpaint_domain, double lambda, double theta, double tolerant, int max_gauss_seidel, int max_iteration, int depth = 1)
{
	int i;
	int channel = toinpaint_image.channels();
	Mat toInpaints[4], results[4], result;
	split(toinpaint_image, toInpaints);
	for (i = 0; i < 3; i++) {
		results[i] = LinearLizeInpaint(toInpaints[i], inpaint_domain, lambda, theta, tolerant, max_gauss_seidel, max_iteration, depth);
	}
	merge(results, 3, result);
	return result;
}
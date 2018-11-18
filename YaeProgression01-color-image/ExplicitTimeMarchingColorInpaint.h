#pragma once
#include"pch.h"
#include"ExplicitTimeMarchingInpaint.h"
Mat ExplicitTimeMarchingColorInpaint(Mat toinpaint_image, Mat inpaint_domain, double lambda, double beta, double tau, double tolerent, double max_iteration) {
	int i;
	int channel = toinpaint_image.channels();
	Mat toInpaints[4], results[4], result;
	split(toinpaint_image, toInpaints);
	for (i = 0; i < channel; i++) {
		results[i] = ExplicitTimeMarchingInpaint(toInpaints[i], inpaint_domain, lambda, beta, tau, tolerent, max_iteration);
	}
	merge(results, channel, result);
	return result;
}
#pragma once
#include "pch.h"
#include "Divergence.h"
#include "Gradient.h"
Mat TotalVariation(Mat image, double beta) {
	int width, height;
	width = image.cols;
	height = image.rows;
	Mat Ux, Uy, normU, toDivergence,grad;
	grad = Gradient(image);
	Ux = grad(Rect(0, 0, width, height));
	Uy = grad(Rect(0, height, width, height));
	normU = Ux.mul(Ux) + Uy.mul(Uy) + beta;
	divide(Ux, normU, Ux);
	divide(Uy, normU, Uy);
	toDivergence = Mat::zeros(Size(width, height * 2), CV_64F);
	Ux.copyTo(toDivergence(Rect(0, 0, width, height)));
	Uy.copyTo(toDivergence(Rect(0, height, width, height)));
	return Divergence(toDivergence);
}

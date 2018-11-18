#pragma once
#include "pch.h"
#include "Gradient.h"
Mat DcoefficientInnerFixedPoint(Mat image,double beta)
{
	int height, width;
	Mat grad,Ux,Uy,D;
	height = image.rows;
	width = image.cols;
	grad = Gradient(image);
	Ux = grad(Rect(0, 0, height, width));
	Uy = grad(Rect(0, height, height, width));
	D = (Ux.mul(Ux) + Uy.mul(Uy) + beta);
	sqrt(D, D);
	divide(1, D, D);
	return D;
}
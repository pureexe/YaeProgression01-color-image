#pragma once
#include "pch.h"
#include "DcoefficientInnerFixedPoint.h"

Mat InnerFixedPointInpaint(Mat u, Mat z,Mat lambda_mat, double beta,int gausseidel_iteration)
{
	int iter,i,j,height,width;
	double h,omega;
	Mat D,G, lambda,result;
	omega = 1.0;
	h = 1.0;
	height = u.rows;
	width = u.cols;
	D = DcoefficientInnerFixedPoint(u, beta);
	G = z;
	copyMakeBorder(D, D, 1, 1, 1, 1, BORDER_REFLECT);
	copyMakeBorder(G, G, 1, 1, 1, 1, BORDER_REFLECT);
	copyMakeBorder(u, u, 1, 1, 1, 1, BORDER_REFLECT);
	copyMakeBorder(lambda_mat, lambda, 1, 1, 1, 1, BORDER_REFLECT);
	for (iter = 0; iter < gausseidel_iteration; iter++) {
		for (i = 1; i <= height; i++) {
			for (j = 1; j <= width; j++) {
				u.at<double>(i, j) = (1 - omega) * u.at<double>(i, j) + omega * (lambda.at<double>(i, j)*G.at<double>(i, j) + (1 / h * h)
					* (D.at<double>(i, j)*(u.at<double>(i + 1, j) + u.at<double>(i, j + 1)) + D.at<double>(i - 1, j)*u.at<double>(i - 1, j) + D.at<double>(i, j - 1)*u.at<double>(i, j - 1)))
					/ (lambda.at<double>(i, j) + (1 / h* h)*(2 * D.at<double>(i, j) + D.at<double>(i - 1, j) + D.at<double>(i, j - 1)));
			}
		}
	}
	result = u(Rect(1, 1, width, height));
	return result;
}
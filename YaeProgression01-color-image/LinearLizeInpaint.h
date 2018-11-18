#pragma once
#include "pch.h"
#include "Gradient.h"
#include "wSubproblemSolver.h"
#include "uSubproblemSolver.h"
#include "CreateLambdaMatrix.h"

Mat LinearLizeInpaint(Mat original_image, Mat inpaint_domain, double lambda_value, double theta, double tolerant, int max_gauss_seidel, int max_iteration, int depth = 1) {
	double image_norm = 9999999;
	int i = 1;
	Mat lambda = CreateLambdaMatrix(inpaint_domain, lambda_value);
	Mat last_image;
	Mat u = original_image.clone();
	int height = original_image.rows;
	int width = original_image.cols;
	Mat b = Mat::zeros(Size(width, height * 2), CV_64F);
	Mat w = Mat::zeros(Size(width, height * 2), CV_64F);
	while (image_norm > tolerant && i < max_iteration) {
		last_image = u.clone();
		w = wSubproblemSolver(u, b, theta, depth);
		u = uSubproblemSolver(u, w, original_image, b, lambda, theta, depth, max_gauss_seidel);
		b = b + Gradient(u, depth) - w;
		image_norm = norm(u - last_image) / norm(u);
		i++;
	}
	return u;
}
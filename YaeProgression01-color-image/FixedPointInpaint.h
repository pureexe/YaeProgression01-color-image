#pragma once
#include "pch.h"
#include "CreateLambdaMatrix.h"
#include "TotalVariation.h"
#include "InnerFixedPointInpaint.h"
Mat FixedPointInpaint(Mat original_image, Mat inpaint_domain, double lambda, double beta, int gaussseidel_iteration, double tolerent, double max_iteration) {
	int i;
	double image_norm;
	Mat image,lambda_mat, original_res, last_image, res;
	i = 0;
	image_norm = 999999;
	image = original_image;
	lambda_mat = CreateLambdaMatrix(inpaint_domain, lambda);
	while (i < max_iteration && image_norm > tolerent)
	{
		last_image = image.clone();
		image = InnerFixedPointInpaint(image, original_image, lambda_mat, beta, gaussseidel_iteration);
		//res = TotalVariation(image, beta) + (original_image - image);
		image_norm = norm(last_image - image, NORM_L2);
		i++;
	}
	return image;
}
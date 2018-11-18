#pragma once
#include "pch.h"
#include "CreateLambdaMatrix.h"
#include "TotalVariation.h"
Mat ExplicitTimeMarchingInpaint(Mat original_image,Mat inpaint_domain,double lambda,double beta,double tau,double tolerent,double max_iteration) {
	Mat lambda_mat, image, res, last_image;
	double image_norm, res_norm;
	int i;
	image_norm  = 999999;
	res_norm = 999999;
	i = 0;
	lambda_mat = CreateLambdaMatrix(inpaint_domain, lambda);
	
	image = original_image;
	Mat diff_image;
	while (i < max_iteration && image_norm > tolerent) {
		last_image = image.clone();
		diff_image = (image - original_image);
		res = TotalVariation(image, beta) + (lambda_mat.mul(image - original_image));
		image = image + res.mul(tau);
		image_norm = norm(last_image - image, NORM_L2);
		i++;
	}

	return image;
}
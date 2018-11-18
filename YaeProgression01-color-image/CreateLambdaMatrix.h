#pragma once
#include "pch.h"
#include "toDoubleBand.h"
Mat CreateLambdaMatrix(Mat inpaint_domain,double lambda)
{
	Mat inpainted_lambda = (inpaint_domain == 0);
	inpainted_lambda = toDoubleBand(inpainted_lambda);
	return inpainted_lambda.mul(lambda);
}
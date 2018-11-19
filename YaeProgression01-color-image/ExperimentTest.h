#pragma once
#include "pch.h"
#include "MultiColorSplitBergman.h"
#include "Synthetic.h"
#include "toUcharBand.h"
#include "iminfo.h"

void ExperimentTest()
{
	double lambda = 750;
	double beta = 1e-6;
	double tau = 1e-5;
	double tolerent = 1e-4;
	int max_gaussseidel = 3;
	double theta = 0.01;
	int totalCase = 5;
	int i = 0, j = 0;
	int max_iteration = 10000;
	int cases = 2;
	Mat toInpaint = toDoubleBand(getSyntheticToInpaint(cases));
	Mat inpaintDomain = toDoubleBand(getSyntheticDomain(cases));
	Mat result;
	//result = SplitBergmanColorInpaint(toInpaint, inpaintDomain, lambda, theta, tolerent, max_gaussseidel, max_iteration);
	result = MultiColorSplitBergman(toInpaint, inpaintDomain, lambda, theta, tolerent, max_gaussseidel,10,10,100,4,1);
	//result = toUcharBand(result);
	imwrite("../only100time.png", result.mul(255.0));
	printInfo(result);
	printType(result);
	imshow("d", result);
	cout << result.at<double>(0, 0, 0);
	waitKey(0);

	
}
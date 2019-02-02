#pragma once
#include "pch.h"
#include "MultiColorSplitBergman.h"
#include "Synthetic.h"
#include "toUcharBand.h"
#include "iminfo.h"

void ExperimentTest()
{
	double lambda = 250;
	double beta = 1e-5;
	double tau = 1e-5;
	double tolerent = 1e-4;
	int max_gaussseidel = 1;
	int max_iteration = 10000;
	double theta = 5;
	int totalCase = 5;

	int i = 0, j = 0;
	string outputFile;
	int multi_coarse, multi_mid, multi_fine, max_step, current_step;

	Mat toInpaintImage, originalImage, inpaintDomain, result;
	high_resolution_clock::time_point t1, t2;
	int duration;
	double timeMeasure, PSNR, SSIM;
	Scalar SSIMs;

	multi_coarse = 10;
	multi_mid = 3;
	max_step = 4;
	multi_fine = 5;
	current_step = 1;
	i = 2;
	toInpaintImage = toDoubleBand(getSyntheticToInpaint(i));
	originalImage = toDoubleBand(getSyntheticOriginal(i));
	inpaintDomain = getSyntheticDomain(i);
	t1 = high_resolution_clock::now();
	result = MultiColorSplitBergman(toInpaintImage, inpaintDomain, lambda, theta, tolerent, max_gaussseidel, multi_coarse, multi_mid, multi_fine, max_step, current_step);
	t2 = high_resolution_clock::now();
	outputFile = "../only10/only5time.png";
	imwrite(outputFile, result.mul(255));
	
}
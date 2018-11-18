#pragma once
#include "pch.h"
#include "SplitBergmanColorInpaint.h"
#include "LinearLizeColorInpaint.h"
#include "Synthetic.h"
#include "PeakSignalToNoiseRatio.h"
#include "StructuralSimilarity.h"

void Experiment02() {
	double lambda = 250;
	double beta = 1e-6;
	double tau = 1e-5;
	double tolerent = 1e-4;
	int max_gaussseidel = 3;
	int max_iteration = 10000;
	double theta = 0.01;
	int totalCase = 5;
	int i = 0;


	Mat toInpaintImage, originalImage, inpaintDomain, result;
	high_resolution_clock::time_point t1, t2;
	int duration;
	double timeMeasure, PSNR, SSIM;
	Scalar SSIMs;

	cout << "SplitBergmanColorInpaint" << endl;
	for (i = 1; i <= totalCase; i++) {
		cout << "CASE: " << i << endl;
		toInpaintImage = toDoubleBand(getSyntheticToInpaint(i));
		originalImage = toDoubleBand(getSyntheticOriginal(i));
		inpaintDomain = getSyntheticDomain(i);;
		t1 = high_resolution_clock::now();
		result = SplitBergmanColorInpaint(toInpaintImage, inpaintDomain, lambda, theta, tolerent, max_gaussseidel, max_iteration);
		t2 = high_resolution_clock::now();
		duration = duration_cast<microseconds>(t2 - t1).count();
		timeMeasure = duration / 1000000.0;
		PSNR = PeakSignalToNoiseRatio(result, originalImage);
		SSIMs = StructuralSimilarity(result, originalImage);
		SSIM = (SSIMs[0] + SSIMs[1] + SSIMs[2]) / 3.0;
		cout << "PSNR: " << PSNR << endl;
		cout << "SSIM: " << SSIM << endl;
		cout << "TIME: " << timeMeasure << endl;
	}
	cout << "Linearlize" << endl;
	for (i = 1; i <= totalCase; i++) {
		cout << "CASE: " << i << endl;
		toInpaintImage = toDoubleBand(getSyntheticToInpaint(i));
		originalImage = toDoubleBand(getSyntheticOriginal(i));
		inpaintDomain = getSyntheticDomain(i);;
		t1 = high_resolution_clock::now();
		result = LinearLizeColorInpaint(toInpaintImage, inpaintDomain, lambda, theta, tolerent, max_gaussseidel, max_iteration);
		t2 = high_resolution_clock::now();
		duration = duration_cast<microseconds>(t2 - t1).count();
		timeMeasure = duration / 1000000.0;
		PSNR = PeakSignalToNoiseRatio(result, originalImage);
		SSIMs = StructuralSimilarity(result, originalImage);
		SSIM = (SSIMs[0] + SSIMs[1] + SSIMs[2]) / 3.0;
		cout << "PSNR: " << PSNR << endl;
		cout << "SSIM: " << SSIM << endl;
		cout << "TIME: " << timeMeasure << endl;
	}
}
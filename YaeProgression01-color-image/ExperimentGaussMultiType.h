#pragma once
#include "pch.h"
#include "Synthetic.h"
#include "toDoubleBand.h"
#include "MultiColorSplitBergman.h"
#include "PeakSignalToNoiseRatio.h"
#include "StructuralSimilarity.h"
void Experiment02() {
	double lambda = 250;
	double beta = 1e-6;
	double tau = 1e-5;
	double tolerent = 1e-4;
	int max_gaussseidel = 1;
	int max_iteration = 10;
	double theta = 5;
	int totalCase = 5;
	int i = 0,j=0;
	int multi_coarse, multi_mid, multi_fine, max_step, current_step;
	// depth,coarse, mid, fine
	int pattern[8][4] = { {1,1,1,10}, {4,10,1,10}, {4,10,3,10}, {4,10,3,10}, {4,10,10,10}, {4,100,1,10}, {4,100,3,10}, {4,100,10,10} };

	Mat toInpaintImage, originalImage, inpaintDomain, result;
	high_resolution_clock::time_point t1, t2;
	int duration;
	double timeMeasure, PSNR, SSIM;
	Scalar SSIMs;

	cout << "SplitBergman Inpaint" << endl;
	for (j = 0; j < 8; j++) {
		cout << "===========" << endl;
		cout << "LOOP: "<< pattern[j][1] << "/";
		for (i = 1; i < pattern[j][0]-1; i++) {
			cout << pattern[j][2] << "/";
		}
		cout << pattern[j][3] <<endl;
		for (i = 1; i <= totalCase; i++) {
			cout << "---------" << endl;
			cout << "CASE: " << i << endl;
			multi_coarse = pattern[j][1];
			multi_mid = pattern[j][2];
			max_step = pattern[j][0];
			multi_fine = pattern[j][3];
			current_step = 1;
			toInpaintImage = toDoubleBand(getSyntheticToInpaint(i));
			originalImage = toDoubleBand(getSyntheticOriginal(i));
			inpaintDomain = getSyntheticDomain(i);
			t1 = high_resolution_clock::now();
			result = MultiColorSplitBergman(toInpaintImage, inpaintDomain, lambda, theta, tolerent, max_gaussseidel, multi_coarse, multi_mid, multi_fine, max_step, current_step);
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

}
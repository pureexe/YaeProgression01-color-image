#pragma once
#include "pch.h"
#include "ThaiArt.h"
#include "Synthetic.h"
#include "toDoubleBand.h"
#include "MultiColorLinearLize.h"
#include "FastMarchingInpaint.h"
#include "PeakSignalToNoiseRatio.h"
#include "StructuralSimilarity.h"
#include "MultiColorSplitBergman.h"
void Experiment05() {
	double lambda = 250;
	double beta = 1e-5;
	double tau = 1e-5;
	double tolerent = 1e-4;
	int max_gaussseidel = 1;
	int max_iteration = 10000;
	double theta = 5;
	string outputFile;

	int totalCase = 5;
	int i = 0, j = 0;
	int multi_coarse, multi_mid, multi_fine, max_step, current_step;
	// depth,coarse, mid, fine

	Mat toInpaintImage, originalImage, inpaintDomain, result;
	high_resolution_clock::time_point t1, t2;
	int duration;
	double timeMeasure, PSNR, SSIM;
	Scalar SSIMs;

	multi_coarse = 10;
	multi_mid = 3;
	max_step = 4;
	multi_fine = 10;
	current_step = 1;


	cout << "===========" << endl;
	cout << "FastMarching" << endl;
	for (i = 1; i <= totalCase; i++) {
		cout << "---------" << endl;
		cout << "CASE: " << i << endl;
		current_step = 1;
		toInpaintImage = toDoubleBand(getThaiArtToInpaint(i));
		originalImage = toDoubleBand(getThaiArtOriginal(i));
		inpaintDomain = getThaiArtDomain();
		t1 = high_resolution_clock::now();
		result = FastMarchingInpaint(toInpaintImage, inpaintDomain);
		t2 = high_resolution_clock::now();
		duration = duration_cast<microseconds>(t2 - t1).count();
		timeMeasure = duration / 1000000.0;
		PSNR = PeakSignalToNoiseRatio(result, originalImage);
		SSIMs = StructuralSimilarity(result, originalImage);
		SSIM = (SSIMs[0] + SSIMs[1] + SSIMs[2]) / 3.0;
		cout << "TIME: " << timeMeasure << endl;
		cout << "PSNR: " << PSNR << endl;
		cout << "SSIM: " << SSIM << endl;
		outputFile = "../images_result_ex4/fastMarching_case0" + to_string(i) + ".png";
		imwrite(outputFile, result.mul(255));
	}
	cout << "===========" << endl;
	cout << "Multi-res Splitbergman" << endl;
	for (i = 1; i <= totalCase; i++) {
		cout << "---------" << endl;
		cout << "CASE: " << i << endl;		
		current_step = 1;
		toInpaintImage = toDoubleBand(getThaiArtToInpaint(i));
		originalImage = toDoubleBand(getThaiArtOriginal(i));
		inpaintDomain = getThaiArtDomain();
		t1 = high_resolution_clock::now();
		result = MultiColorSplitBergman(toInpaintImage, inpaintDomain, lambda, theta, tolerent, max_gaussseidel, multi_coarse, multi_mid, multi_fine, max_step, current_step);
		t2 = high_resolution_clock::now();
		duration = duration_cast<microseconds>(t2 - t1).count();
		timeMeasure = duration / 1000000.0;
		PSNR = PeakSignalToNoiseRatio(result, originalImage);
		SSIMs = StructuralSimilarity(result, originalImage);
		SSIM = (SSIMs[0] + SSIMs[1] + SSIMs[2]) / 3.0;
		cout << "TIME: " << timeMeasure << endl;
		cout << "PSNR: " << PSNR << endl;
		cout << "SSIM: " << SSIM << endl;
		outputFile = "../images_result_ex4/multisplitbergman_case0" + to_string(i) + ".png";
		imwrite(outputFile, result.mul(255));
	}
	cout << "===========" << endl;
	cout << "Splitbergman Original" << endl;
	for (i = 1; i <= totalCase; i++) {
		cout << "---------" << endl;
		cout << "CASE: " << i << endl;
		current_step = 1;
		toInpaintImage = toDoubleBand(getThaiArtToInpaint(i));
		originalImage = toDoubleBand(getThaiArtOriginal(i));
		inpaintDomain = getThaiArtDomain();
		t1 = high_resolution_clock::now();
		result = SplitBergmanColorInpaint(toInpaintImage, inpaintDomain, lambda, theta, tolerent, max_gaussseidel,max_iteration);
		t2 = high_resolution_clock::now();
		duration = duration_cast<microseconds>(t2 - t1).count();
		timeMeasure = duration / 1000000.0;
		PSNR = PeakSignalToNoiseRatio(result, originalImage);
		SSIMs = StructuralSimilarity(result, originalImage);
		SSIM = (SSIMs[0] + SSIMs[1] + SSIMs[2]) / 3.0;
		cout << "TIME: " << timeMeasure << endl;
		cout << "PSNR: " << PSNR << endl;
		cout << "SSIM: " << SSIM << endl;
		outputFile = "../images_result_ex4/splitbergman_case0" + to_string(i) + ".png";
		imwrite(outputFile, result.mul(255));
	}
}
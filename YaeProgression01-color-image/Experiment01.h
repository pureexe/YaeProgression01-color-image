#pragma once
/***
* This is experiment runner file
**/
#include "Synthetic.h"
#include "ThaiArt.h"
#include "toDoubleBand.h"
#include "ExplicitTimeMarchingColorInpaint.h"
#include "FixedPointColorInpaint.h"
#include "SplitBergmanColorInpaint.h"
#include "PeakSignalToNoiseRatio.h"
#include "StructuralSimilarity.h"
#include "FastMarchingInpaint.h"
#include <string>
void Experiment01() {
	//variable defination
	double lambda = 250;
	double beta = 1e-5;
	double tau = 1e-5*5.0; //plz try 2.5
	double tolerent = 1e-4;
	int max_gaussseidel = 1;
	int max_iteration = 10000;
	double theta = 5;
	int totalCase = 5;
	int i = 0;
	
	Mat toInpaintImage, originalImage, inpaintDomain, result;
	high_resolution_clock::time_point t1, t2;
	int duration;
	double timeMeasure, PSNR, SSIM;
	Scalar SSIMs;

	/*
	i = 4;
	toInpaintImage = toDoubleBand(getSyntheticToInpaint(i));
	originalImage = toDoubleBand(getSyntheticOriginal(i));
	inpaintDomain = getSyntheticDomain(i);
	result = result = FixedPointColorInpaint(toInpaintImage, inpaintDomain, lambda, beta, max_gaussseidel, tolerent, max_iteration);
	imshow("result", result);
	waitKey(0);
	*/ 
	string outputFile;
	/*
	cout << "ExplicitTimeMarchingColorInpaint" << endl;
	for (i = 1; i <= totalCase; i++) {
		cout << "CASE: " << i << endl;
		toInpaintImage = toDoubleBand(getSyntheticToInpaint(i));
		originalImage = toDoubleBand(getSyntheticOriginal(i));
		inpaintDomain = getSyntheticDomain(i);
		t1 = high_resolution_clock::now();
		result = ExplicitTimeMarchingColorInpaint(toInpaintImage, inpaintDomain, lambda, beta, tau, tolerent, max_iteration);
		t2 = high_resolution_clock::now();
		duration = duration_cast<microseconds>(t2 - t1).count();
		timeMeasure = duration / 1000000.0;
		PSNR = PeakSignalToNoiseRatio(result, originalImage);
		SSIMs = StructuralSimilarity(result, originalImage);
		SSIM = (SSIMs[0] + SSIMs[1] + SSIMs[2]) / 3.0;
		cout << "TIME: " << timeMeasure << endl;
		cout << "PSNR: " << PSNR << endl;
		cout << "SSIM: " << SSIM << endl;
		outputFile = "../images_result_ex1/timemarch0"+to_string(i)+".png";
		imwrite(outputFile, result.mul(255));
	}
	*/
	
	cout << "FixedPointColorInpaint" << endl;
	for (i = 1; i <= totalCase; i++) {
		cout << "CASE: " << i << endl;
		toInpaintImage = toDoubleBand(getSyntheticToInpaint(i));
		originalImage = toDoubleBand(getSyntheticOriginal(i));
		inpaintDomain = getSyntheticDomain(i);
		t1 = high_resolution_clock::now();
		result = FixedPointColorInpaint(toInpaintImage, inpaintDomain, lambda, beta, max_gaussseidel, tolerent, max_iteration);
		t2 = high_resolution_clock::now();
		duration = duration_cast<microseconds>(t2 - t1).count();
		timeMeasure = duration / 1000000.0;
		PSNR = PeakSignalToNoiseRatio(result, originalImage);
		SSIMs = StructuralSimilarity(result, originalImage);
		SSIM = (SSIMs[0] + SSIMs[1] + SSIMs[2]) / 3.0;
		cout << "TIME: " << timeMeasure << endl;
		cout << "PSNR: " << PSNR << endl;
		cout << "SSIM: " << SSIM << endl;
		outputFile = "../images_result_ex1/fixpoint0" + to_string(i) + ".png";
		imwrite(outputFile, result.mul(255));
	}
	/*
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
		cout << "TIME: " << timeMeasure << endl;
		cout << "PSNR: " << PSNR << endl;
		cout << "SSIM: " << SSIM << endl;
		outputFile = "../images_result_ex1/splitbergman0" + to_string(i) + ".png";
		imwrite(outputFile, result.mul(255));
	}	*/
}

/*double lambda = 250;
	double beta = 1e-6;
	double tau = 1e-5;
	double tolerent = 1e-4;
	int max_gaussseidel = 3;
	int max_iteration = 10000;
	double theta = 10;
	int totalCase = 5;
	int i = 0;
*/
#pragma once
#include "pch.h"
#include"toDoubleBand.h"
#include "ThaiArt.h"
#include "MultiColorSplitBergman.h"


void ExperimentStepingImage()
{
	Mat toInpaintImage, originalImage, inpaintDomain;
	double lambda = 250;
	double beta = 1e-5;
	double tau = 1e-5;
	double tolerent = 1e-4;
	int max_gaussseidel = 1;
	int max_iteration = 10000;
	double theta = 5;
	toInpaintImage = toDoubleBand(getThaiArtToInpaint(1));
	originalImage = toDoubleBand(getThaiArtOriginal(1));
	inpaintDomain = getThaiArtDomain();
	MultiColorSplitBergman(toInpaintImage, inpaintDomain, lambda, theta, tolerent, max_gaussseidel, 10, 3, 10000, 1, 1);
	cout << "finished";
}
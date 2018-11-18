#pragma once
#include "pch.h"
#include "Signnum.h"

//w = max(abs(gradU + b) - (1 / theta), 0) * signnum(gradU+b);

Mat wSubproblemSolver(Mat u, Mat b, double theta, int depth) {
	Mat gradU = Gradient(u, depth);
	Mat gradB = gradU + b;
	Mat w;
	w = max(abs(gradB) - (1 / theta), 0);
	return w.mul(Signnum(gradB));
}


#pragma once
#include "pch.h"
Mat toDoubleBand(Mat uCharImage) {
	Mat doubleImage;
	uCharImage.convertTo(doubleImage, CV_64FC3, 1.0 / 255.0, 0);
	return doubleImage;
}
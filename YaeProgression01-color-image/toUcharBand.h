#pragma once
#include "pch.h"
Mat toUcharBand(Mat doubleImage) {
	Mat uCharImage;
	doubleImage.convertTo(uCharImage, CV_8UC3, 255.0);
	return uCharImage;
}
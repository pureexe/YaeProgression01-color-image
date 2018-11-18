#pragma once
#include "pch.h"
#include "toDoubleBand.h"
#include "toUcharBand.h"
Mat FastMarchingInpaint(Mat toInpaint, Mat inpaintDomain)
{
	Mat result;
	toInpaint = toUcharBand(toInpaint);
	inpaint(toInpaint, inpaintDomain, result, 3, CV_INPAINT_TELEA);
	result = toDoubleBand(result);
	return result;
}
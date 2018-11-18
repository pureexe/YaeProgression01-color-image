#pragma once
#include "pch.h"
#include <opencv2/core.hpp>
#include <opencv2/photo.hpp>

using namespace cv;

Mat getThaiArtOriginal(int id) {
	switch (id)
	{
	case 1:
		return imread("../images/thaiart/case01-original.png");
	case 2:
		return imread("../images/thaiart/case02-original.png");
	case 3:
		return imread("../images/thaiart/case03-original.png");
	case 4:
		return imread("../images/thaiart/case04-original.png");
	case 5:
		return imread("../images/thaiart/case05-original.png");
	}
}

Mat getThaiArtToInpaint(int id) {
	switch (id)
	{
		case 1:
			return imread("../images/thaiart/case01-toinpaint.png");
		case 2:
			return imread("../images/thaiart/case02-toinpaint.png");
		case 3:
			return imread("../images/thaiart/case03-toinpaint.png");
		case 4:
			return imread("../images/thaiart/case04-toinpaint.png");
		case 5:
			return imread("../images/thaiart/case05-toinpaint.png");		
	}
}
	

Mat getThaiArtDomain() {
	return imread("../images/thaiart/inpaint-domain.png", CV_LOAD_IMAGE_GRAYSCALE);
}
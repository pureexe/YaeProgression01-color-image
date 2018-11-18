#pragma once
#pragma once
#include "pch.h"


Mat getSyntheticOriginal(int id) {
	switch (id)
	{
	case 1:
		return imread("../images/synthetic/case01-original.png");
	case 2:
		return imread("../images/synthetic/case02-original.png");
	case 3:
		return imread("../images/synthetic/case03-original.png");
	case 4:
		return imread("../images/synthetic/case04-original.png");
	case 5:
		return imread("../images/synthetic/case05-original.png");
	}
}

Mat getSyntheticToInpaint(int id) {
	switch (id)
	{
	case 1:
		return imread("../images/synthetic/case01-toinpaint.png");
	case 2:
		return imread("../images/synthetic/case02-toinpaint.png");
	case 3:
		return imread("../images/synthetic/case03-toinpaint.png");
	case 4:
		return imread("../images/synthetic/case04-toinpaint.png");
	case 5:
		return imread("../images/synthetic/case05-toinpaint.png");
	}
}


Mat  getSyntheticDomain(int id) {
	switch (id)
	{
	case 1:
		return imread("../images/synthetic/case01-inpaintdomain.png", CV_LOAD_IMAGE_GRAYSCALE);
	case 2:
		return imread("../images/synthetic/case02-inpaintdomain.png", CV_LOAD_IMAGE_GRAYSCALE);
	case 3:
		return imread("../images/synthetic/case03-inpaintdomain.png", CV_LOAD_IMAGE_GRAYSCALE);
	case 4:
		return imread("../images/synthetic/case04-inpaintdomain.png", CV_LOAD_IMAGE_GRAYSCALE);
	case 5:
		return imread("../images/synthetic/case05-inpaintdomain.png", CV_LOAD_IMAGE_GRAYSCALE);
	}
}
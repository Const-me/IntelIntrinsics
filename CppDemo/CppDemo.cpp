#include "stdafx.h"
#include "quaternionMul.h"
#include "intDivide.h"
#include "compare.h"
#include "brightness.h"

int main()
{
	testImageBrightness();
	// return 0;
	testQuaternionMultuply();
	testIntDivide();
	testCompare();
	return 0;
}
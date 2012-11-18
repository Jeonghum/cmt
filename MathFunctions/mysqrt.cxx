
#include "mysqrt.h"
#include <cmath>

double mysqrt(double arg)
{
	double result;

#if defined (HAVE_LOG) && defined (HAVE_EXP)
	// if we have both log and exp then use them
	result = std::exp(std::log(arg)*0.5);
#else
	// otherwise use an iterative approach
	result = std::sqrt(arg);
#endif

	return result;
}


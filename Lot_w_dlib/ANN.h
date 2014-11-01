#pragma once

#include "iostream"
#include <dlib/mlp.h>

typedef dlib::matrix<double, 2, 1> sample_type;

class ANN {
private:

public:
	void classify();
};
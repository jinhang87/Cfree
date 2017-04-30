#include <iostream>

struct ColorVector{
	double r;
	double g;
	double b;
	double a;
};


void test_alignof()
{
	std::cout << "test_alignof : " << std::endl;
	std::cout << "alignof : " << alignof(ColorVector) << std::endl;
	std::cout << "sizeof : " << sizeof(ColorVector) << std::endl;
	std::cout << "offsetof : " << offsetof(ColorVector,b) << std::endl;
}
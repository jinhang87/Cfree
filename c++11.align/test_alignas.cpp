#include <iostream>

struct alignas(32) ColorVector{
	double r;
	double g;
	double b;
	double a;
};


void test_alignas()
{
	std::cout << "test_alignas : " << std::endl;
	std::cout << "alignof : " << alignof(ColorVector) << std::endl;
	std::cout << "sizeof : " << sizeof(ColorVector) << std::endl;
	std::cout << "offsetof : " << offsetof(ColorVector,b) << std::endl;
}
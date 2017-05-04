
#include <iostream>
#include <thread>

void test_hardware_concurrency()
{
	std::cout << "hardware_concurrency: " << std::thread::hardware_concurrency()<<std::endl;
}
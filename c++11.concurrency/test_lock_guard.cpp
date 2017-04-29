#include <iostream>
#include <list>
#include <mutex>
#include <algorithm>

std::list<int> some_list; // 1
std::mutex some_mutex; // 2

void add_to_list(int new_value)
{
	std::lock_guard<std::mutex> guard(some_mutex); // 3
	some_list.push_back(new_value);
} 

bool list_contains(int value_to_find)
{
	std::lock_guard<std::mutex> guard(some_mutex); // 4
	return std::find(some_list.begin(),some_list.end(),value_to_find) != some_list.end();
}

void test_lock_guard()
{
	add_to_list(1);
	add_to_list(2);
	add_to_list(3);
	std::cout << list_contains(2) << std::endl;
	std::cout << list_contains(4) << std::endl;
}
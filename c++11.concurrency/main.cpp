#include <iostream>

using namespace std;

extern void test_lock_guard();
extern void test_hierarchical_mutex();
extern void test_unique_lock();
extern void test_future();
extern void test_async();
extern void test_hardware_concurrency();
extern void test_promise();
extern void test_promise_cin();

int main(int argc, char *argv[])
{
	//test_lock_guard();
	//test_hierarchical_mutex();
	//test_unique_lock();
	//test_future();
	//test_async();
	//test_hardware_concurrency();
	//test_promise();
	test_promise_cin();
	cout<<"Hello C-Free!"<<endl;
	return 0;
}

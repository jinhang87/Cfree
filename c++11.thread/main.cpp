#include <iostream>
#include <thread> 

using namespace std;


extern int test_basic();
extern int test_producer_consumer();
extern void test_native_handle();
extern void test_yield();

int main(int argc, char *argv[])
{
	//test_basic();
	//test_producer_consumer();
	test_native_handle();
	//test_yield();
	cout<<"Hello C-Free!"<<endl;
	return 0;
}

#include <iostream>
#include <thread> 

using namespace std;


extern int test_basic();
extern int test_producer_consumer();

int main(int argc, char *argv[])
{
	//test_basic();
	test_producer_consumer();
	cout<<"Hello C-Free!"<<endl;
	return 0;
}

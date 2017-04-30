#include <iostream>

using namespace std;
extern void test_alignof();
extern void test_alignas();

int main(int argc, char *argv[])
{
	test_alignof();
	test_alignas();
	cout<<"Hello C-Free!"<<endl;
	return 0;
}

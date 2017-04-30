#include <iostream>

using namespace std;
extern void test_trivial();
extern void test_standard_layout();

int main(int argc, char *argv[])
{
	test_trivial();
	test_standard_layout();
	cout<<"Hello C-Free!"<<endl;
	return 0;
}

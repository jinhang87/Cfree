#include <iostream>

using namespace std;


extern void test1();


/*
	C++ 11����������̳п��ƹؼ��֣�override��final��
	overrideȷ���������������������غ�����������麯������ͬ��ǩ����
	final��ֹ��Ľ�һ���������麯���Ľ�һ�����ء�
*/

int main(int argc, char *argv[])
{
	test1();
	cout<<"Hello C-Free!"<<endl;
	return 0;
}

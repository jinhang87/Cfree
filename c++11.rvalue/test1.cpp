#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

//��ֵ���ö���������� 
void test1()
{
	string str = "Hello";
    vector<std::string> v;

    v.push_back(str);
    cout << "After copy, str is \"" << str << "\"\n";    

	//str������������ݱ�"�ƶ�"���µĶ����в����뵽����֮����,ͬʱstr������ˡ�����һ��ʡȥ�˶��󿽱��Ĺ��̡�
    v.push_back(std::move(str));
    cout << "After move, str is \"" << str << "\"\n";
    
	cout << "The contents of the vector are \"" << v[0]
		<< "\", \"" << v[1] << "\"\n";	
}


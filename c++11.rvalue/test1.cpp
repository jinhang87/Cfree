#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

//右值引用对象插入容器 
void test1()
{
	string str = "Hello";
    vector<std::string> v;

    v.push_back(str);
    cout << "After copy, str is \"" << str << "\"\n";    

	//str对象里面的内容被"移动"到新的对象中并插入到数组之中了,同时str被清空了。这样一来省去了对象拷贝的过程。
    v.push_back(std::move(str));
    cout << "After move, str is \"" << str << "\"\n";
    
	cout << "The contents of the vector are \"" << v[0]
		<< "\", \"" << v[1] << "\"\n";	
}


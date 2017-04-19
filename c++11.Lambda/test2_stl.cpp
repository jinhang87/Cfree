#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

//查找多个符合的条件 
void v_find_if()
{
	vector<int> v = { 1,2,3,4,5,6,7,8 };
	vector<int>::iterator iter = v.begin();
	std::cout << "v_find_if: ";	
	while(true) 
	{
		iter = find_if(iter, v.end(), [](int x){return ((x%2)==1);});   
		if ( iter != v.end() ){
 			cout << *iter << ' ';
 			iter++;			
		}
		else
		{ 
			break;
		} 
	}
 	std::cout << '\n';		
}
//删除多个符合的条件 
void v_remove_if()
{
 	std::vector<int> c { 1,2,3,4,5,6,7 };
    int x = 5;
    c.erase(std::remove_if(c.begin(), c.end(), [x](int n) { return n < x; } ), c.end());
 
    std::cout << "v_remove_if: ";
    for (auto i: c) {
        std::cout << i << ' ';
    }
    std::cout << '\n';	
}

void test2()
{
	v_find_if();
	v_remove_if();
}
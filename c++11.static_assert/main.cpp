#include <iostream>

using namespace std;

extern void test1();

/*

我们知道，C++现有的标准中，就有assert、#error两个设施，也是用来检查错误的，
	
还有一些第三方的静态断言实现。assert是运行期断言，它用来发现运行期间的错误，
	
不能提前到编译期发现错误，也不具有强制性，也谈不上改善编译信息的可读性，
	
既然是运行期检查，对性能当然是有影响的，所以经常在发行版本中，assert都会被关掉；

#error可看做预编译期断言，甚至都算不上断言，仅仅能在预编译时显示一个错误信息，

它能做的不多，可以参与预编译的条件检查，由于它无法获得编译信息，

当然就做不了更进一步分析了。

那么，在stastic_assert提交到C++0x标准之前，为了弥补assert和#error的不足，

出现了一些第三方解决方案，可以作编译期的静态检查，

例如BOOST_STATIC_ASSERT和LOKI_STATIC_CHECK，

但由于它们都是利用了一些编译器的隐晦特性实现的trick，可移植性、简便性都不是太好，

还会降低编译速度，而且功能也不够完善，

例如BOOST_STATIC_ASSERT就不能定义错误提示文字，

而LOKI_STATIC_CHECK则要求提示文字满足C++类型定义的语法。

*/


int main(int argc, char *argv[])
{
	cout<<"Hello C-Free!"<<endl;
	return 0;
}

#include <iostream>

using namespace std;
/*
变长参数打印方案一：
推荐这种方法，虽然写起来麻烦一点，但是它在运行期的效率比较高
（没有递归，顺序搞定，DummyWrapper的参数传递会被编译器优化掉），
而且编译期的代价也不是很高
（对于相同类型的子元素，unpacker<T>只需要特化出一份即可，
但DummyWrapper需要根据参数类型特化很多版本）。	
*/

template <typename ... T>
void DummyWrapper(T... t){};

template <class T>
T unpacker(const T& t){
	cout<<','<<t;
	return t;
}

template <typename T, typename... Args>//防止0个参数类型 
void write_line(const T& t, const Args& ... data){
	cout << t;
	DummyWrapper(unpacker(data)...);//直接用unpacker(data)...是非法的，（可以认为直接逗号并列一堆结果没有意义），需要包裹一下，好像这些结果还有用
	cout << '\n';
}

/*
变长参数打印方案二：
这种方法思路直观，书写便捷。但是运行时有递归，效率有所下降。
编译时也需要生成不少版本的_write。
*/
template <typename T>
void _write(const T& t){
	cout << t << '\n';
}

template <typename T, typename ... Args>
void _write(const T& t, Args ... args){
	cout << t << ',';
	_write(args...);//递归解决，利用模板推导机制，每次取出第一个，缩短参数包的大小。
}

template <typename T, typename... Args>
inline void write_line_2(const T& t, const Args& ... data){
	_write(t, data...);
}

void test2()
{
	int a = 3;
	double b= 3.1;
	write_line(a, b);
	write_line_2(a, b);
}
#include <iostream>

using namespace std;
/*
�䳤������ӡ����һ��
�Ƽ����ַ�������Ȼд�����鷳һ�㣬�������������ڵ�Ч�ʱȽϸ�
��û�еݹ飬˳��㶨��DummyWrapper�Ĳ������ݻᱻ�������Ż�������
���ұ����ڵĴ���Ҳ���Ǻܸ�
��������ͬ���͵���Ԫ�أ�unpacker<T>ֻ��Ҫ�ػ���һ�ݼ��ɣ�
��DummyWrapper��Ҫ���ݲ��������ػ��ܶ�汾����	
*/

template <typename ... T>
void DummyWrapper(T... t){};

template <class T>
T unpacker(const T& t){
	cout<<','<<t;
	return t;
}

template <typename T, typename... Args>//��ֹ0���������� 
void write_line(const T& t, const Args& ... data){
	cout << t;
	DummyWrapper(unpacker(data)...);//ֱ����unpacker(data)...�ǷǷ��ģ���������Ϊֱ�Ӷ��Ų���һ�ѽ��û�����壩����Ҫ����һ�£�������Щ���������
	cout << '\n';
}

/*
�䳤������ӡ��������
���ַ���˼·ֱ�ۣ���д��ݡ���������ʱ�еݹ飬Ч�������½���
����ʱҲ��Ҫ���ɲ��ٰ汾��_write��
*/
template <typename T>
void _write(const T& t){
	cout << t << '\n';
}

template <typename T, typename ... Args>
void _write(const T& t, Args ... args){
	cout << t << ',';
	_write(args...);//�ݹ���������ģ���Ƶ����ƣ�ÿ��ȡ����һ�������̲������Ĵ�С��
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
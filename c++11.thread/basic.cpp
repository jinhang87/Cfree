/*
	����һ���̲߳��ȴ������н��� 
*/

#include <iostream>
#include <thread> 

void my_thread()
{
	auto i = 10;
	while(--i!=0)
	{
		puts("hello, world");
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}	
}

int test_basic()
{
	std::thread t(my_thread);
	t.join();
	return 0;
}

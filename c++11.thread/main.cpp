#include <iostream>
#include <thread> 
#include <unistd.h>

//#if defined(WIN32) || defined(WIN64)
#include <windows.h>
#define sleep(n) Sleep(1000 * (n))
//#else
//#include <unistd.h>
//#endif

using namespace std;

void my_thread()
{
	auto i = 10;
	while(--i!=0)
	{
		puts("hello, world");
		sleep(1);
	}	
}


int main(int argc, char *argv[])
{
	thread t(my_thread);
	t.join();
	
	cout<<"Hello C-Free!"<<endl;
	return 0;
}

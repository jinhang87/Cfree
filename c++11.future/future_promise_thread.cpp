#include <functional> //std::ref
#include <thread>	//std::thread
#include <future>	//std::future, std::promise
#include <iostream>

int print_int(std::future<int> &future){
	int x = future.get();// 和promise同步 
	std::cout << "value : " << x << std::endl;
}

void test(){
	std::promise<int> promise;
	std::future<int> future = promise.get_future();
	std::thread thread(print_int , std::ref(future));
	promise.set_value(10); // 和future同步 
	thread.join();
}
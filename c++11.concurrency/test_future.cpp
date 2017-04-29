#include <future>
#include <iostream>

int find_the_answer_to_ltuae()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	return 33; 
}
void do_other_stuff()
{
	std::cout << "do_other_stuff" << std::endl;
}

void test_future()
{
	std::future<int> the_answer=std::async(find_the_answer_to_ltuae);
	do_other_stuff();
	std::cout<<"The answer is "<<the_answer.get()<<std::endl;
}
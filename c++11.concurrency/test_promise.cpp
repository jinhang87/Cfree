#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <thread>         // std::thread
#include <future>         // std::promise, std::future

static void print_int(std::future<int>& fut) {
    int x = fut.get(); // ��ȡ����״̬��ֵ.
    std::cout << "value: " << x << '\n'; // ��ӡ value: 10.
}

void test_promise ()
{
    std::promise<int> prom; // ����һ�� std::promise<int> ����.
    std::future<int> fut = prom.get_future(); // �� future ����.
    std::thread t(print_int, std::ref(fut)); // �� future ��������һ���߳�t.
    std::this_thread::sleep_for(std::chrono::seconds(5)); 
    prom.set_value(10); // ���ù���״̬��ֵ, �˴����߳�t����ͬ��.
    t.join();
}
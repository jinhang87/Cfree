/*
	生产者消费者问题 
*/
#include <iostream>           
#include <queue>
#include <thread>             
#include <mutex>              
#include <condition_variable> 

using namespace std;

mutex mtx;
condition_variable isNotFull, isNotEmpty;

queue<int> q;     // shared value by producers and consumers, which is the critical section
int maxSize = 20;

void consumer() 
{
    while (true)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));

        unique_lock<mutex> lck(mtx);                        // RAII，程序运行到此block的外面（进入下一个while循环之前），资源（内存）自动释放
        isNotEmpty.wait(lck, [] {return q.size() != 0; });     // wait(block) consumer when q.size() == 0

        cout << "consumer " << this_thread::get_id() << ": ";
        q.pop();
        cout << q.size() << '\n';

        isNotFull.notify_all();                               // nodity(wake up) producer when q.size() != maxSize
    }
}

void producer(int id)
{
    while (true)
    {
        this_thread::sleep_for(chrono::milliseconds(900));      // producer is a little faster than consumer  

        unique_lock<mutex> lck(mtx);
        isNotFull.wait(lck, [] {return q.size() != maxSize; });   // wait(block) producer when q.size() == maxSize 

        cout << "-> producer " << this_thread::get_id() << ": ";
        q.push(id);
        cout << q.size() << '\n';

        isNotEmpty.notify_all();                                   // notify(wake up) consumer when q.size() != 0    
    }
}

int test_producer_consumer()
{
    thread consumers[2], producers[2];

    // spawn 2 consumers and 2 producers:
    for (int i = 0; i < 2; ++i)
    {
        consumers[i] = thread(consumer);
        producers[i] = thread(producer, i + 1);
    }

    // join them back: (in this program, never join...)
    for (int i = 0; i < 2; ++i)
    {
        producers[i].join();
        consumers[i].join();
    }

    system("pause");
    return 0;
}

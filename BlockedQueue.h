#pragma once
#include <iostream>
#include<queue>
#include<future>
#include<condition_variable>
#include<mutex>


template<class T> class BlockedQueue 
{
public:
    void push(T& item);
    void pop(T& item);
    bool fast_pop(T& item); 

private:
    std::mutex m_locker; 
    std::queue<T> m_task_queue;
    std::condition_variable m_notifier; 
    //std::mutex m;
    //int count1 = 0;
};

#include"BlockedQueue.cpp"

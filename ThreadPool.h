#pragma once
#include <iostream>
#include<vector>
#include"BlockedQueue.h"

void taskFunc(std::shared_ptr<int[]> arr, long id, long delay);
typedef std::function<void()> task_type;
typedef void (*FuncType) (std::shared_ptr<int[]>, long, long);


class ThreadPool 
{
public:
    ThreadPool(); 
    ~ThreadPool();
    void start();
    void stop();
    void push_task(FuncType f, std::shared_ptr<int[]> arr, long id, long arg); 
    void threadFunc(int qindex/*, std::promise<void> p*/);
    
private:    
    int m_thread_count; 
    std::vector<std::thread> m_threads;
    std::vector<BlockedQueue<task_type>> m_thread_queues; 
    int m_index;
};




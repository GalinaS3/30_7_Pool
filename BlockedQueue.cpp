#include"BlockedQueue.h"


template <typename T> void BlockedQueue<T>::push(T& item)
{
    
    std::lock_guard<std::mutex> l(m_locker);    
    m_task_queue.push(item);    
    m_notifier.notify_one();
   
}

template <typename T> void BlockedQueue<T>::pop(T& item)
{
    std::unique_lock<std::mutex> l(m_locker);
    if (m_task_queue.empty())
       
        m_notifier.wait(l, [this] {return !m_task_queue.empty(); });
    item = m_task_queue.front();
    m_task_queue.pop();
}

template <typename T> bool BlockedQueue<T>::fast_pop(T& item) {
    std::lock_guard<std::mutex> l(m_locker);
    if (m_task_queue.empty())        
        return false;    
    item = m_task_queue.front();
    m_task_queue.pop();   
    return true;
}




#pragma once
#include"ThreadPool.h"

class RequestHandler
{
public:
    RequestHandler();
    ~RequestHandler();
    void pushRequest(FuncType f, std::shared_ptr<int[]>, long id, long arg);
private:

    ThreadPool m_tpool;
};
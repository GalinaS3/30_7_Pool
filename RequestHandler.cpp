#include"RequestHandler.h"

RequestHandler::RequestHandler()
{
    m_tpool.start();
}
RequestHandler::~RequestHandler()
{
    m_tpool.stop();
}
void RequestHandler::pushRequest(FuncType f, std::shared_ptr<int[]>arr, long id, long arg)
{
    m_tpool.push_task(f, arr, id, arg);
}
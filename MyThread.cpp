#include <thread>
#include "MyThread.h"
#include "MyThreadPool.h"
#include <iostream>
using namespace std;

int MyThread::s_threadnumber = 0;

MyThread::MyThread(MyThreadPool* pool)
{
    //pool->idle_thread_container_.push(this);
    //set thread id?
    mythreadpool_ = pool; 
    //thread count ++
    s_threadnumber += 1;

    //thread_ = this;

    threadid_ = s_threadnumber;
}

void MyThread::Assign(Task* Task)
{
    //if(task_ != NULL)
    //{
        task_ = Task;
    //}
}

int MyThread::getthreadid()
{
    return threadid_;
}

void MyThread::setisdetach(bool isdetach)
{
    isdetach_ = isdetach;
}

void MyThread::Run()
{
    cout << "Thread:" << threadid_ << " run ";
    task_->Run();
    mythreadpool_->RemoveThreadFromBusy(this);
}

void MyThread::StartThread()
{
    thread_ = thread(&MyThread::Run, this);
    if(isdetach_ == true)
        thread_.detach();
    else
        thread_.join();
}

bool operator==(MyThread my1, MyThread my2)
{
    return my1.threadid_ == my2.threadid_;
}

bool operator!=(MyThread my1, MyThread my2)
{
    return !(my1.threadid_ == my2.threadid_);
}

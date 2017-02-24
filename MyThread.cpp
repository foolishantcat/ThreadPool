#include "MyThread.h"

void MyThread::Run()
{
    cout << "Thread:" << threadid_ << " run ";
    task_->Run();
    mythreadpool_->RemoveThreadFromBusy(this);
}

void MyThread::StartThread()
{
    thread_ = thread(&Mythread::Run, this);
    if(isdetach_ == true)
        thread_.detach();
    else
        thread_.join();
}


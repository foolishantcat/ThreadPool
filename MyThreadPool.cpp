#include "MyThreadPool.h"

void MyThreadPool::RemoveThreadFromBusy(MyThread* myThread)
{
    busy_mutex_.lock();
    cout << "Thread:" << myThread->getthreadid() << " remove from busy list"
        << endl;
    busy_thread_container_.erase(myThread);
    busy_mutex_.unlock();

    idle_mutex_.lock();
    idle_thread_container_.push(myThread);
    idle_mutex_.unlock();
}

MythreadPool::MyThreadPool(int number)
{
    issurvive_ = true;
    number_of_thread = number;
    idle_thread_container_.assign(number, this);
    thread_this_ = thread(&MyThreadPool::Start, this);
    thread_this_.detach();
}

void MyThreadPool::Start()
{
    while(true)
    {
        if(issurvive_ == false)
        {
            busy_mutex_.lock();
            if(busy_thread_container_.size() != 0)
            {
                busy_mutex_.unlock();
                continue;
            }
            busy_mutex_,unlock();
            break;
        }
        idle_mutex_.lock();
        if(idle_thread_container_.size() == 0)
        {
            idle_mutex_.unlock();
            continue;
        }
        idle_mutex_.unlock();
        task_mutex_.lock();
        if(task_container_.size() == 0)
        {
            task_mutex_.unlock();
            continue;
        }
        Task* b = task_container_.pop();
        task_container_.pop();
        task_mutex_.unlock();

        idle_mutex_.lock();
        MyThread* mythread = idle_thread_container_.pop();
        idle_thread_container_.pop();
        mythread->Assign(b);
        idle_mutex_.unlock();

        busy_mutex_.lock();
        busy_thread_container_.push(mythread);
        busy_mutex_.unlock();
        mythread->StartThread();
    }
}

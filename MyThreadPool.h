#ifndef _MY_THREAD_POOL_H_
#define _MY_THREAD_POOL_H_

class MyThreadPool
{
public:
    MyThreadPool(){}
    MyThreadPool(int number);
    ~MyThreadPool();
    void AddTask(Task* Task, int priority);
    void AddIdleThread(int n);
    void RemoveThreadFromBusy(MyThread* myThread);
    void Start();
    void EndMyThreadPool();
private:
    BusyThreadContainer busy_thread_container_;
    IdleThreadContainer idle_thread_container_;
    bool issurvive_;
    TaskContainer task_container_;
    std::thread thread_this_;
    std::mutex busy_mutex_;
    std::mutex idle_muetx_;

};


#endif
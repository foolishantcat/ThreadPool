#ifndef _IDLE_THREAD_CONTAINER_H_
#define _IDLE_THREAD_CONTAINER_H_

class IdleThreadContainer
{

public:
    IdleThreadContainer();
    ~IdleThreadContainer();
    std::vector<Mythread*>::size_type size();
    void push(MyThread* m);
    void assign(int n, MyThreadPool* m);
    MyThread* top();
    void pop();
    void erase(MyThread* m);
private:
    std::vector<MyThread*> idle_thread_container_;
    typedef std::vector<MyThread*> Container;
    typedef Container::iterator Iterator;
};


#endif

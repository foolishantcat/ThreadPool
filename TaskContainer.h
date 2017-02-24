#ifndef _TASK_CONTAINER_H_
#define _TASK_CONTAINER_H_

class TaskContainer
{
public:
    TaskContainer();
    ~TaskContainer();
    void push(Task*);
    Task* top();
    void pop();
    std::priority_queue<Task*>::size_type size();
private:
    std::priority_queue<Task*> task_container_;
};


#endif

#ifndef _TASK_H_
#define _TASK_H_

namespace 
{
    enum PRIORITY
    {
        MIN = 1, 
        NORMAL = 25,
        MAX = 50
    };
}

class Task
{
public:
    Task()
    {
    
    }
    void SetPriority(int priority)
    {
        if(priority > (PRIORITY::MAX))
        {
            priority_ = (PRIORITY::MAX);
        }
        else if(priority < (PRIORITY::MIN))
        {
            priority_ = (PRIORITY::MIN);
        }

        priority_ = priority;
    }
    virtual void Run() = 0;
protected:
    int priority_;
};

#endif

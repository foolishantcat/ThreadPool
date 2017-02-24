#include "MyTask.h"

MyTask::MyTask()
{

}
MyTask::~MyTask()
{

}
void MyTask::setdata(int d)
{
    data_ = d;
}

void MyTask::Run()
{
    std::cout << "Hello I am" << data_ << std::endl;
    std::this_thread::sleep_for(std::chrono::second(1));
}

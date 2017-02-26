#include "MyTask.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

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
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

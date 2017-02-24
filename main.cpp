#include "MyTask.h"
#include "MyThreadPool.h"
#include "MyThread.h"

int main()
{
    MyThreadPool myThreadPool(10);

    MyTask j[50];

    for(int i = 0; i < 50; i++)
    {
        j[i].setdata(i);
    }
    for(int i = 0; i < 50; i++)
    {
        myThreadPool.AddTask(&j[i], i);
    }

    int i;

    while(true)
    {
        cin >> i;
        if(i == 100)
        {
            MyTask j;
            j.setdata(i);
            myThreadPool.AddTask(&j, i);
        }
        if(i == -1)
        {
            myThreadPool.EndMyThreadPool();
            break;
        }
    }
    system("pause");
}

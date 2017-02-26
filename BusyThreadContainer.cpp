#include "BusyThreadContainer.h"
#include "MyThread.h"

BusyThreadContainer::BusyThreadContainer()
{

}

BusyThreadContainer::~BusyThreadContainer()
{

}

void BusyThreadContainer::push(MyThread* m)
{
    busy_thread_container_.push_front(m);
}

std::list<MyThread*>::size_type BusyThreadContainer::size()
{
    return busy_thread_container_.size();
}

void BusyThreadContainer::erase(MyThread* m)
{
    busy_thread_container_.remove(m);
}


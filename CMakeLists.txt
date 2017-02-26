PROJECT(ThreadPool)
cmake_minimum_required(VERSION 3.5)
SET(CMAKE_C_COMPILER g++)
add_compile_options(-std=c++11 -g)
#add_compile_options(-lpthread)
ADD_EXECUTABLE(ThreadPool MyThread.cpp BusyThreadContainer.cpp
        IdleThreadContainer.cpp TaskContainer.cpp 
        MyThreadPool.cpp MyTask.cpp main.cpp)

target_link_libraries(ThreadPool pthread)

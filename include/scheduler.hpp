#pragma once

#include <iostream>
#include <cstring>
#include <pthread.h>
#include <unistd.h>
#include "queue.hpp"
#include "vector.hpp"

using namespace std;

template <typename T>
class Job {
private:
    int id;
    void (*job_func)(T*, void*);    // job function
    void* args;            // arguments for job function

public:
    Job(int job_id, char* function, void* arguments);
    ~Job();
    int get_id();
    void (*get_job_func())(void*);
    void* get_args();
    void execute();
};

template <typename T>
class Job_Scheduler {
private:
    int execution_threads;      // number of execution threads
    Queue<Job<T>>* jobs;                // a queue that holds submitted jobs
    pthread_t* tids;           // execution threads
    pthread_mutex_t mutex;     
    pthread_cond_t condition;

public:
    Job_Scheduler(int exec_threads);
    ~Job_Scheduler();
    int get_execution_threads();
    Queue<Job<T>>* get_jobs();
    pthread_t* get_tids();
    pthread_mutex_t& get_mutex();
    pthread_cond_t& get_condition();
    int submit_job(Job<T> *job);
    int start_execute();
    int wait_all_tasks_finish();
};

template <typename T>
void* worker_thread(void* arg); 

#include "../templates/scheduler.tpp"
#include "scheduler.hpp"

template <typename T>
Job<T>::Job(int job_id, char* function) : id(job_id) {
    if (strcmp(function, "calc_point_norm") == 0) {
        job = nullptr;
    }
    else if (strcmp(function, "update_fifo") == 0) {
        job = nullptr;
    }
    else if (strcmp(function, "create_random_projection_trees") == 0) {
        job = nullptr;
    }
    else if (strcmp(function, "calc_local_join") == 0) {
        job = nullptr;
    }
    else {
        cout << "Invalid function name" << endl;
        exit(1);
    }
}

template <typename T>
Job<T>::~Job() {

}

template <typename T>
int Job<T>::get_id() {
    return id;
}


template <typename T>
Job_Scheduler<T>::Job_Scheduler(int exec_threads) : execution_threads(exec_threads) {
    jobs = new Queue<Job<T>>();
    tids = new pthread_t[execution_threads];
}

template <typename T>
Job_Scheduler<T>::~Job_Scheduler() {
    delete jobs;
    delete[] tids;
}

template <typename T>
int Job_Scheduler<T>::get_execution_threads() {
    return execution_threads;
}

template <typename T>
Queue<Job<T>>* Job_Scheduler<T>::get_jobs() {
    return jobs;
}

template <typename T>
pthread_t* Job_Scheduler<T>::get_tids() {
    return tids;
}

template <typename T>
void Job_Scheduler<T>::submit_job(Job<T> *job) {
    jobs->enqueue(job);
}

template <typename T>
void Job_Scheduler<T>::start_execute() {
    
}

template <typename T>
void Job_Scheduler<T>::wait_all_tasks_finish() {
    
}
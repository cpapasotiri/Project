#include "scheduler.hpp"

template <typename T>
Job<T>::Job(int job_id, char* function, void* arguments) {
    id = job_id;
    if (strcmp(function, "calc_point_norm") == 0) {
        job_func = nullptr;
    }
    else if (strcmp(function, "update_fifo") == 0) {
        job_func = nullptr;
    }
    else if (strcmp(function, "create_random_projection_trees") == 0) {
        job_func = nullptr;
    }
    else if (strcmp(function, "calc_local_join") == 0) {
        job_func = nullptr;
    }
    else {
        cout << "Invalid function name" << endl;
        exit(1);
    }
    args = arguments;
}

template <typename T>
Job<T>::~Job() {

}

template <typename T>
int Job<T>::get_id() {
    return id;
}

template <typename T>
void (*Job<T>::get_job_func())(void*) { 
    return job_func;
}

template <typename T>
void* Job<T>::get_args() {
    return args;
}

template <typename T>
void Job<T>::execute() {
    if (job_func != nullptr) {
        job_func(args);
    }
    else {
        cout << "There is no job function" << endl;
    }
}


template <typename T>
Job_Scheduler<T>::Job_Scheduler(int exec_threads) : execution_threads(exec_threads) {
    jobs = new Queue<Job<T>>();
    tids = new pthread_t[execution_threads];
    pthread_mutex_init(&mutex, nullptr);
    pthread_cond_init(&condition, nullptr);
}

template <typename T>
Job_Scheduler<T>::~Job_Scheduler() {
    delete jobs;
    delete[] tids;
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition);
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
pthread_mutex_t& Job_Scheduler<T>::get_mutex() {
    return mutex;
}
template <typename T>
pthread_cond_t& Job_Scheduler<T>::get_condition() {
    return condition;
}

template <typename T>
int Job_Scheduler<T>::submit_job(Job<T> *job) {
    pthread_mutex_lock(&mutex);
    jobs->enqueue(job);
    pthread_cond_signal(&condition);
    pthread_mutex_unlock(&mutex);
    return 0;
}

template <typename T>
int Job_Scheduler<T>::start_execute() {
    for (int i = 0; i < execution_threads; i++) {
        pthread_create(&tids[i], nullptr, &worker_thread<T>, static_cast<void*>(this));
    }
    return 0;
}

template <typename T>
int Job_Scheduler<T>::wait_all_tasks_finish() {
    for (int i = 0; i < execution_threads; i++) {
        pthread_join(tids[i], nullptr);
    }
    return 0;
}

template <typename T>
void* worker_thread(void* arg) {
    Job_Scheduler<T>* sch = static_cast<Job_Scheduler<T>*>(arg);
    
    while (true) {
        pthread_mutex_lock(&sch->get_mutex());

        // Wait for a job if the queue is empty
        while (sch->get_jobs()->is_empty()) {
            pthread_cond_wait(&sch->get_condition(), &sch->get_mutex());

            // Check if there are no more jobs, exit condition
            if (sch->get_jobs()->is_empty()) {
                pthread_mutex_unlock(&sch->get_mutex());
                pthread_exit(nullptr);
                return nullptr;
            }
        }

        // Dequeue a job and release the lock
        Job<T>* job = sch->get_jobs()->dequeue();
        pthread_mutex_unlock(&sch->get_mutex());

        // Execute the job
        // void* arg = job->get_args();
        // void (*func)(void*) = job->get_job_func();
        // func(arg);        
        job->execute();

        // Clean up the job
        delete job;
    }
    return nullptr;
}
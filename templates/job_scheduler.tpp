#include "job_scheduler.hpp"

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
        job->execute();

        // Clean up the job
        delete job;
    }
    return nullptr;
}

template <typename T>
float parallel_eucleidean_point_norm(Job_Scheduler<T> &scheduler, const Vector<T> &point1, const Vector<T> &point2)
{
    if (point1.get_size() != point2.get_size())
    {
        throw invalid_argument("Points should have the same dimensions.");
    }

    int number_of_dimensions = static_cast<int>(point2.get_size());
    float result = 0.0;

    // Submit job for each dimension
    for (int i = 0; i < number_of_dimensions; i++)
    { 
        Job<double>* job = new Point_Norm_Job<double>(i, point1, point2);
        scheduler.submit_job(job);
    }

    // Wait for all jobs to complete
    scheduler.wait_all_tasks_finish();

    return sqrt(result);
}
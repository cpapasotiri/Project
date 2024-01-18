#include "job.hpp"

template <typename T>
Job<T>::Job(int job_id) : id(job_id) {}

template <typename T>
Job<T>::~Job() {}

template <typename T>
int Job<T>::get_id() {
    return id;
}

template <typename T>
void Job<T>::execute(){}
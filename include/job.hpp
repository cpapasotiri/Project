#pragma once

#include <iostream>
#include "vector.hpp"

using namespace std;

template <typename T>
class Job {
private:
    int id;
public:
    Job(int job_id);
    ~Job();
    int get_id();
};

#include "../templates/job.tpp"
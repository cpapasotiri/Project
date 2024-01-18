#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Job {
private:
    int id;
public:
    Job(int job_id);
    ~Job();
    int get_id();
    virtual void execute();
};

#include "../templates/job.tpp"
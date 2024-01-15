#pragma once

#include <iostream>
#include "job_scheduler.hpp"
#include "job.hpp"
#include "vector.hpp"

using namespace std;

template <typename T>
class Point_Norm_Job : public Job<T> {
private:
    Vector<T> point1;
    Vector<T> point2;
    float result;
public:
    Point_Norm_Job(int job_id, const Vector<T> &p1, const Vector<T> &p2);
    ~Point_Norm_Job();
    void execute();
    void print();
}; 

#include "../templates/point_norm_job.tpp"
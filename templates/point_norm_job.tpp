#include "point_norm_job.hpp"

template <typename T>
Point_Norm_Job<T>::Point_Norm_Job(int job_id, const Vector<T> &p1, const Vector<T> &p2) : Job<T>(job_id), point1(p1), point2(p2) 
{
    result = 0.0;
}

template <typename T>
Point_Norm_Job<T>::~Point_Norm_Job() {}

template <typename T>
void Point_Norm_Job<T>::execute()
{
    
}

template <typename T>
void Point_Norm_Job<T>::print()
{
    
}
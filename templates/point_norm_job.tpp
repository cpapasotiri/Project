#include "point_norm_job.hpp"

template <typename T>
Point_Norm_Job<T>::Point_Norm_Job(int job_id, const Vector<T> &p1, const Vector<T> &p2) : Job<T>(job_id), point1(p1), point2(p2) 
{
    result = 0.0;
}

template <typename T>
Point_Norm_Job<T>::~Point_Norm_Job() {}

template <typename T>
float Point_Norm_Job<T>::get_result()
{
    return result;
}

template <typename T>
void Point_Norm_Job<T>::execute()
{
    for (int i = 0; i < (int)point1.get_size(); i++)
    {
        float dim_diff = point1.euclidean_dimesion(i, point2);
        result += dim_diff;
    }
}

template <typename T>
void Point_Norm_Job<T>::print()
{
    
}
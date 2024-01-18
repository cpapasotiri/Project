#include "catch.hpp"
#include "point_norm_job.hpp"

TEST_CASE("Point Norm Job functionality tests", "[Point Norm Jod]")
{
    SECTION("Initialize the job")
    {
        Vector<float> v1;
        v1.push_back(1.0);
        v1.push_back(2.0);
        Vector<float> v2;
        v2.push_back(4.0);
        v2.push_back(6.0);
        Point_Norm_Job<float> job(0, v1, v2);
        REQUIRE(job.get_id() == 0);
        REQUIRE(job.get_result() == 0.0);
    }

    SECTION("Execute the job")
    {
        Vector<float> v1;
        v1.push_back(1.0);
        v1.push_back(2.0);
        Vector<float> v2;
        v2.push_back(4.0);
        v2.push_back(6.0);
        Point_Norm_Job<float> job(0, v1, v2);
        job.execute();
        float result = ((4.0 - 1.0) * (4.0 - 1.0)) + ((6.0 - 2.0) * (6.0 - 2.0));
        REQUIRE(job.get_result() == result);
    }
}
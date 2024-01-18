#include "catch.hpp"
#include "job_scheduler.hpp"

TEST_CASE("Job Scheduler functionality tests", "[Jod Scheduler]")
{   
    int number_of_cores = sysconf(_SC_NPROCESSORS_CONF);

    SECTION("Initialize the scheduler")
    {
        Job_Scheduler<int> scheduler(number_of_cores);
        REQUIRE(scheduler.get_number_of_threads() == number_of_cores);
        REQUIRE(scheduler.get_jobs()->get_size() == 0);
    }

    Vector<float> v1;
    v1.push_back(1.0);
    v1.push_back(2.0);
    Vector<float> v2;
    v2.push_back(4.0);
    v2.push_back(6.0);

    SECTION("Submit a job")
    {
        Job_Scheduler<float> scheduler(number_of_cores);
        Point_Norm_Job<float> job(0, v1, v2);
        scheduler.submit_job(&job);
        REQUIRE(scheduler.get_jobs()->get_size() == 1);
    }

    SECTION("Submit multiple jobs")
    {
        Job_Scheduler<float> scheduler(number_of_cores);
        for (int i = 0; i < number_of_cores; i++)
        {
            Point_Norm_Job<float> job(0, v1, v2);
            scheduler.submit_job(&job);
        }
        REQUIRE(scheduler.get_jobs()->get_size() == (size_t)number_of_cores);
    }

    // SECTION("Start the execution & Wait for all tasks to finish")
    // {
        // Job_Scheduler<float> scheduler(number_of_cores);
        // for (int i = 0; i < number_of_cores; i++)
        // {
            // Job<float> *job = new Point_Norm_Job<float>(i, v1, v2);
            // scheduler.submit_job(job);
        // }
        // REQUIRE(scheduler.get_jobs()->get_size() == (size_t)number_of_cores);
        // scheduler.start_execute();
        // scheduler.wait_all_tasks_finish();
        // REQUIRE(scheduler.get_jobs()->get_size() == (size_t)0);
    // }
}
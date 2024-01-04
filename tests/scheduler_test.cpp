#include "catch.hpp"
#include "scheduler.hpp"

TEST_CASE("Job Scheduler functionality tests", "[Jod Scheduler]")
{   
    char function[20] = "calc_point_norm"; // Dummy function name
    SECTION("Initialize the scheduler")
    {
        int number_of_cores = sysconf(_SC_NPROCESSORS_CONF);
        Job_Scheduler<int> scheduler(number_of_cores);
        REQUIRE(scheduler.get_execution_threads() == number_of_cores);
        REQUIRE(scheduler.get_jobs()->get_size() == 0);
        REQUIRE(scheduler.get_tids() != NULL);
    }

    SECTION("Submit a job")
    {
        int number_of_cores = sysconf(_SC_NPROCESSORS_CONF);
        Job_Scheduler<int> scheduler(number_of_cores);
        Job<int> job(0, function);
        scheduler.submit_job(&job);
        REQUIRE(scheduler.get_jobs()->get_size() == 1);
    }

    SECTION("Submit multiple jobs")
    {
        int number_of_cores = sysconf(_SC_NPROCESSORS_CONF);
        Job_Scheduler<int> scheduler(number_of_cores);
        for (int i = 0; i < number_of_cores; i++)
        {
            Job<int> *job = new Job<int>(i, function);
            scheduler.submit_job(job);
        }
        REQUIRE(scheduler.get_jobs()->get_size() == (size_t)number_of_cores);
    }

    SECTION("Start execution")
    {
        int number_of_cores = sysconf(_SC_NPROCESSORS_CONF);
        Job_Scheduler<int> scheduler(number_of_cores);
        for (int i = 0; i < number_of_cores; i++)
        {
            Job<int> *job = new Job<int>(i, function);
            scheduler.submit_job(job);
        }
        scheduler.start_execute();
        REQUIRE(scheduler.get_jobs()->get_size() == (size_t)number_of_cores);
    }

    SECTION("Wait for all tasks to finish")
    {
        int number_of_cores = sysconf(_SC_NPROCESSORS_CONF);
        Job_Scheduler<int> scheduler(number_of_cores);
        for (int i = 0; i < number_of_cores; i++)
        {
            Job<int> *job = new Job<int>(i, function);
            scheduler.submit_job(job);
        }
        scheduler.start_execute();
        scheduler.wait_all_tasks_finish();
        REQUIRE(scheduler.get_jobs()->get_size() == (size_t)number_of_cores);
    }

    SECTION("Submit multiple jobs and wait for all tasks to finish")
    {
        int number_of_cores = sysconf(_SC_NPROCESSORS_CONF);
        Job_Scheduler<int> scheduler(number_of_cores);
        for (int i = 0; i < number_of_cores; i++)
        {
            Job<int> *job = new Job<int>(i, function);
            scheduler.submit_job(job);
        }
        scheduler.start_execute();
        scheduler.wait_all_tasks_finish();
        REQUIRE(scheduler.get_jobs()->get_size() == (size_t)number_of_cores);
    }
}
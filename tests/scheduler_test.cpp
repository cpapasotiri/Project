#include "catch.hpp"
#include "scheduler.hpp"

TEST_CASE("Job Scheduler functionality tests", "[Jod Scheduler]")
{   
    int number_of_cores = sysconf(_SC_NPROCESSORS_CONF);

    SECTION("Initialize the scheduler")
    {
        
        Job_Scheduler<int> scheduler(number_of_cores);
        REQUIRE(scheduler.get_execution_threads() == number_of_cores);
        REQUIRE(scheduler.get_jobs()->get_size() == 0);
        REQUIRE(scheduler.get_tids() != NULL);
    }

    // int arg_1 = 45;
    int arg_2[2] = {65, 100};
    // int arg_3[3] = {65, 100, 1000};

    // SECTION("Submit a job")
    // {
    //     Job_Scheduler<int> scheduler(number_of_cores);
    //     Job<int> job(0, function, arg_2);
    //     scheduler.submit_job(&job);
    //     REQUIRE(scheduler.get_jobs()->get_size() == 1);
    // }

    char calculate_norm[20] = "point_norm";
    SECTION("Submit calculate point norm as parallel job")
    {
        Job_Scheduler<int> scheduler(number_of_cores);
        for (int i = 0; i < number_of_cores; i++)
        {
            Job<int> *job = new Job<int>(i, calculate_norm, arg_2);
            scheduler.submit_job(job);
        }
        REQUIRE(scheduler.get_jobs()->get_size() == (size_t)1);
    }

    // SECTION("Submit multiple jobs")
    // {
    //     Job_Scheduler<int> scheduler(number_of_cores);
    //     for (int i = 0; i < number_of_cores; i++)
    //     {
    //         Job<int> *job = new Job<int>(i, function, arg_3);
    //         scheduler.submit_job(job);
    //     }
    //     REQUIRE(scheduler.get_jobs()->get_size() == (size_t)number_of_cores);
    // }

    // SECTION("Start execution")
    // {
    //     Job_Scheduler<int> scheduler(number_of_cores);
    //     for (int i = 0; i < number_of_cores; i++)
    //     {
    //         Job<int> *job = new Job<int>(i, function, arg_2);
    //         scheduler.submit_job(job);
    //     }
    //     scheduler.start_execute();
    //     scheduler.wait_all_tasks_finish();
    //     REQUIRE(scheduler.get_jobs()->get_size() == (size_t)number_of_cores);
    // }

    // SECTION("Wait for all tasks to finish")
    // {
    //     Job_Scheduler<int> scheduler(number_of_cores);
    //     for (int i = 0; i < number_of_cores; i++)
    //     {
    //         Job<int> *job = new Job<int>(i, function, arg_2);
    //         scheduler.submit_job(job);
    //     }
    //     scheduler.start_execute();
    //     REQUIRE(scheduler.get_jobs()->get_size() == (size_t)number_of_cores);
    //     scheduler.wait_all_tasks_finish();
    //     REQUIRE(scheduler.get_jobs()->get_size() == (size_t)0);
    // }

    // SECTION("Submit multiple jobs and wait for all tasks to finish")
    // {
    //     Job_Scheduler<int> scheduler(number_of_cores);
    //     for (int i = 0; i < number_of_cores; i++)
    //     {
    //         Job<int> *job = new Job<int>(i, function, arg_2);
    //         scheduler.submit_job(job);
    //     }
    //     scheduler.start_execute();
    //     scheduler.wait_all_tasks_finish();
    //     REQUIRE(scheduler.get_jobs()->get_size() == (size_t)number_of_cores);
    // }
}
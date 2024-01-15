#include "catch.hpp"
#include "job_scheduler.hpp"

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

    // float arg_1 = 45.5;
    // float arg_2[2] = {65.5, 100.5};
    // float arg_3[3] = {65.5, 100.5, 1000.5};

    // char norm[11] = "point_norm";

    // SECTION("Submit a job")
    // {
    //     Job_Scheduler<int> scheduler(number_of_cores);
    //     Job<int> job(0, norm, NULL);
    //     scheduler.submit_job(&job);
    //     REQUIRE(scheduler.get_jobs()->get_size() == 1);
    // }

    // SECTION("Submit calculate point norm as parallel job")
    // {
    //     Job_Scheduler<int> scheduler(number_of_cores);
    //     for (int i = 0; i < number_of_cores; i++)
    //     {
    //         Job<Vector<int>> job(i, &Vector<int>::parallel_eucleidean_point_norm, arg_2);
    //         scheduler.submit_job(&job);
    //     }
    //     REQUIRE(scheduler.get_jobs()->get_size() == (size_t)1);
    // }

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


    SECTION("Testing point norm calculation")
    {
        Job_Scheduler<double> scheduler(number_of_cores);
        Vector<double> v1;
        v1.push_back(1.0);
        v1.push_back(2.0);
        Vector<double> v2;
        v2.push_back(4.0);
        v2.push_back(6.0);
        double dist = parallel_eucleidean_point_norm(scheduler, v1, v2);
        REQUIRE(dist == Approx(5.0)); // Approx is used for floating-point comparison
    }
}
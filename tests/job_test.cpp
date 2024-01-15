#include "catch.hpp"
#include "job.hpp"

TEST_CASE("Job functionality tests", "[Jod]")
{
    SECTION("Job creation")
    {
        Job<int> job(1);
        REQUIRE(job.get_id() == 1);
    }
}
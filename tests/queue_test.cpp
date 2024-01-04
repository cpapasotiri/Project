#include "catch.hpp"
#include "queue.hpp"
#include "string_util.hpp"
#include "scheduler.hpp"
#include <sstream>


TEST_CASE("Queue functionality tests", "[FIFO]")
{      
    SECTION("Construct an empty queue") {
        Queue<int> queue;
        REQUIRE(queue.get_size() == 0);
        REQUIRE(queue.is_empty());
    }

    SECTION("Destruct an empty queue") {
        {
            Queue<int> queue;
            // Queue goes out of scope and should be destructed here
        }
    }

    int value_1 = 1;
    int value_2 = 2;
    int value_3 = 3;

    SECTION("Enqueue and dequeue") 
    {
        Queue<int> queue;

        REQUIRE(queue.is_empty());

        queue.enqueue(&value_1);
        queue.enqueue(&value_2);

        REQUIRE(queue.get_size() == 2);
        REQUIRE(queue.front_value() == &value_1);

        queue.dequeue();

        REQUIRE(queue.get_size() == 1);
        REQUIRE(queue.front_value() == &value_2);

        queue.dequeue();

        REQUIRE(queue.is_empty());
    }

    SECTION("Copy constructor") 
    {
        Queue<int> originalQueue;
        originalQueue.enqueue(&value_1);
        originalQueue.enqueue(&value_2);

        Queue<int> copiedQueue(originalQueue);

        REQUIRE(originalQueue.get_size() == copiedQueue.get_size());
        REQUIRE(originalQueue.front_value() == copiedQueue.front_value());
    }

    SECTION("Peek") 
    {
        Queue<int> queue;
        queue.enqueue(&value_1);
        queue.enqueue(&value_2);
        queue.enqueue(&value_3);

        REQUIRE(queue.peek(0) == &value_1);
        REQUIRE(queue.peek(1) == &value_2);
        REQUIRE(queue.peek(2) == &value_3);
        REQUIRE(queue.peek(3) == nullptr); // Out of bounds
    }

    SECTION("Print") {
        Queue<Job<int>> queue;
        char function[20] = "calc_point_norm"; // Dummy function name
        Job<int> job1(1, function);
        Job<int> job2(2, function);
        Job<int> job3(3, function);
        queue.enqueue(&job1);
        queue.enqueue(&job2);
        queue.enqueue(&job3);

        cout << "HERE " << endl;
        // Redirect cout to a stringstream to capture the output
        ostringstream oss;
        streambuf* coutBuffer = cout.rdbuf();
        cout.rdbuf(oss.rdbuf());

        queue.print();

        // Reset cout to the original buffer
        cout.rdbuf(coutBuffer);

        REQUIRE(oss.str() == trim("1 2 3 \n"));
    }

    SECTION("Clear") {
        Queue<int> queue;
        queue.enqueue(&value_1);
        queue.enqueue(&value_2);
        queue.enqueue(&value_3);

        queue.clear();

        REQUIRE(queue.is_empty());
    }
}
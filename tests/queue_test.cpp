#include "catch.hpp"
#include "queue.hpp"
#include "string_util.hpp"
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

    SECTION("Enqueue and dequeue") 
    {
        Queue<int> queue;

        REQUIRE(queue.is_empty());

        queue.enqueue(1);
        queue.enqueue(2);

        REQUIRE(queue.get_size() == 2);
        REQUIRE(queue.front_value() == 1);

        queue.dequeue();

        REQUIRE(queue.get_size() == 1);
        REQUIRE(queue.front_value() == 2);

        queue.dequeue();

        REQUIRE(queue.is_empty());
    }

    SECTION("Copy constructor") 
    {
        Queue<int> originalQueue;
        originalQueue.enqueue(1);
        originalQueue.enqueue(2);

        Queue<int> copiedQueue(originalQueue);

        REQUIRE(originalQueue.get_size() == copiedQueue.get_size());
        REQUIRE(originalQueue.front_value() == copiedQueue.front_value());
    }

    SECTION("Peek") 
    {
        Queue<int> queue;
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);

        REQUIRE(queue.peek(0) == 1);
        REQUIRE(queue.peek(1) == 2);
        REQUIRE(queue.peek(2) == 3);
        REQUIRE(queue.peek(3) == false); // Out of bounds
    }

    SECTION("Print") {
        Queue<int> queue;
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);

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
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);

        queue.clear();

        REQUIRE(queue.is_empty());
    }
}
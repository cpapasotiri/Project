#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "vector.hpp"

TEST_CASE("Vector operations work as expected", "[vector]")
{
    SECTION("Testing push_back and operator[]")
    {
        Vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        REQUIRE(v[0] == 10);
        REQUIRE(v[1] == 20);
        REQUIRE(v[2] == 30);
    }

    SECTION("Testing operator[] and operator==")
    {
        Vector<float> v1;
        v1.push_back(1.1);
        v1.push_back(1.2);
        v1.push_back(1.3);

        Vector<float> v2;
        v2.push_back(2.1);
        v2.push_back(2.2);
        v2.push_back(2.3);

        REQUIRE((v1 == v1) == true);
        REQUIRE((v1 == v2) == false);
    }

    SECTION("Testing copy constructor and distructor")
    {
        Vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);

        Vector<int> *v = new Vector<int>(v1);
        REQUIRE(v->get_size() == 3);
        REQUIRE(v->operator[](0) == v1[0]);
        REQUIRE(v->operator[](1) == v1[1]);
        REQUIRE(v->operator[](2) == v1[2]);

        delete v;
    }

    SECTION("Testing get_capacity and get_size")
    {
        Vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        REQUIRE(v.get_size() == 3);
        REQUIRE(v.get_capacity() == 10); // initial capacity is 10
    }

    SECTION("Testing euclidean distance")
    {
        Vector<double> v1;
        v1.push_back(1.0);
        v1.push_back(2.0);
        Vector<double> v2;
        v2.push_back(4.0);
        v2.push_back(6.0);
        double dist = v1.euclideanDistance(v2);
        REQUIRE(dist == Approx(5.0)); // Approx is used for floating-point comparison
    }

    SECTION("Testing manhattan distance")
    {
        Vector<double> v1;
        v1.push_back(1.0);
        v1.push_back(2.0);
        Vector<double> v2;
        v2.push_back(4.0);
        v2.push_back(6.0);
        double dist = v1.manhattanDistance(v2);
        REQUIRE(dist == Approx(7.0)); // Approx is used for floating-point comparison
    }

}

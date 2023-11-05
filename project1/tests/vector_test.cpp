#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "vector.hpp"

TEST_CASE("Vector operations work as expected", "[vector]") {
    SECTION("Testing push_back and operator[]") {
        Vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        REQUIRE(v[0] == 10);
        REQUIRE(v[1] == 20);
        REQUIRE(v[2] == 30);
    }

    SECTION("Testing get_capacity and get_size") {
        Vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        REQUIRE(v.get_size() == 3);
        REQUIRE(v.get_capacity() == 10); // initial capacity is 10
    }

    SECTION("Testing euclidean distance") {
        Vector<double> v1;
        v1.push_back(1.0);
        v1.push_back(2.0);
        Vector<double> v2;
        v2.push_back(4.0);
        v2.push_back(6.0);
        double dist = v1.euclideanDistance(v2);
        REQUIRE(dist == Approx(5.0)); // Approx is used for floating-point comparison
    }

    SECTION("Testing manhattan distance") {
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

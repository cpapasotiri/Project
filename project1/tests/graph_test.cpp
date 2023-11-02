#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "graph.hpp"


// 
TEST_CASE(" ", "") {
  REQUIRE(0);      
}

TEST_CASE("Euclidean distance test case 1", "[euclidean_distance]") {
    Vector<double> point1;
    point1.push_back(1.0);
    point1.push_back(2.0);
    point1.push_back(3.0);

    Vector<double> point2;
    point2.push_back(4.0);
    point2.push_back(5.0);
    point2.push_back(6.0);

    REQUIRE(euclideanDistance(point1, point2) == Approx(sqrt(27.0)));
}

TEST_CASE("Euclidean distance test case 2", "[euclidean_distance]") {
    Vector<int> point1;
    point1.push_back(1);
    point1.push_back(2);
    point1.push_back(3);
  

    Vector<int> point2;
    point2.push_back(4);
    point2.push_back(6);
    point2.push_back(8);

    REQUIRE(euclideanDistance(point1, point2) == Approx(sqrt(14.0)));
}
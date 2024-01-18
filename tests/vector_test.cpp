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

    SECTION("Testing copy constructor and destructor")
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

    SECTION("Testing get_dimensions_value") 
    {
        Vector<double> v;
        v.push_back(10.5);
        v.push_back(20.5);
        v.push_back(30.5);
        REQUIRE(v.get_dimension_value(0) == 10.5);
        REQUIRE(v.get_dimension_value(1) == 20.5);
        REQUIRE(v.get_dimension_value(2) == 30.5);

        REQUIRE_THROWS_AS(v.get_dimension_value(-1), invalid_argument);
        REQUIRE_THROWS_AS(v.get_dimension_value(3), invalid_argument);
    }

    // SECTION("Valid dimensions and same size") 
    // {
    //     Vector<double> v1;
    //     v1.push_back(1.0);
    //     Vector<double> v2;
    //     v2.push_back(4.0);

    //     REQUIRE(v1.get_size() == v2.get_size());

    //     int dim = 1;

    //     float expected_result = ((v1.get_dimension_value(dim) - v2.get_dimension_value(dim)) * (v1.get_dimension_value(dim) - v2.get_dimension_value(dim)));

    //     float result = v1.euclidean_dimesion(dim, v2);

    //     REQUIRE(result == expected_result);
    // }


}

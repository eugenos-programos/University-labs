#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "polynomial.h"

TEST_CASE("Testing comparison operators"){
    Polynomial* first_test_polynomial = new Polynomial(2,std::vector<short> {1,2,3});
    Polynomial* second_test_polynomial = new Polynomial(2,std::vector<short> {1,2,3});
    REQUIRE(*first_test_polynomial == second_test_polynomial);
    REQUIRE(!(*first_test_polynomial != second_test_polynomial));
}

TEST_CASE("Testing input and output operators"){
    Polynomial* first_test_polynomial = new Polynomial(3,std::vector<short> {1,2,3,4});
    Polynomial* second_typed_test_polynomial = new Polynomial();
    std::cout << "power - 3, vector - {1,2,3,4}\n";
    std::cin >> *second_typed_test_polynomial;
    REQUIRE(*second_typed_test_polynomial == first_test_polynomial);
}

TEST_CASE("Testing [] and () operators"){
    Polynomial* test_polynomial = new Polynomial(2,std::vector<short> {1,2,3});
    short number = 3;
    REQUIRE(3 == (*test_polynomial)[2]);
    REQUIRE(6 == (*test_polynomial)(1));
}

TEST_CASE("Testing sum and difference operators"){
    Polynomial* first_test_polynomial = new Polynomial(4,std::vector<short> {1,3,0,5,7});
    Polynomial* second_test_polynomial = new Polynomial(2,std::vector<short> {2,5,3});
    Polynomial* result_test_polynomial = new Polynomial(4,std::vector<short> {3,8,3,5,7});
    REQUIRE(*result_test_polynomial == *second_test_polynomial + first_test_polynomial);
    *first_test_polynomial += second_test_polynomial;
    REQUIRE(*first_test_polynomial == result_test_polynomial);
    REQUIRE(*(*first_test_polynomial - second_test_polynomial) == (*result_test_polynomial - second_test_polynomial));
    *first_test_polynomial -= second_test_polynomial;
    REQUIRE(*result_test_polynomial == *second_test_polynomial + first_test_polynomial);
}

TEST_CASE("Testing mulitiplication operator"){
    Polynomial* first_test_polynomial = new Polynomial(2,std::vector<short> {1,3,0});
    Polynomial* second_test_polynomial = new Polynomial(2,std::vector<short> {2,5,3});
    Polynomial* result_test_polynomial = new Polynomial(4,std::vector<short> {2,11,18,9,0});
    REQUIRE(*result_test_polynomial == (*first_test_polynomial)*second_test_polynomial);
    *first_test_polynomial *= second_test_polynomial;
    REQUIRE(*result_test_polynomial == first_test_polynomial);
}

TEST_CASE("Testing division operator"){
    Polynomial* first_test_polynomial = new Polynomial(2,std::vector<short> {-3,10,8});
    Polynomial* second_test_polynomial = new Polynomial(1,std::vector<short> {3,2});
    Polynomial* result_test_polynomial = new Polynomial(1,std::vector<short> {-1,4});
    REQUIRE(*result_test_polynomial == ((*first_test_polynomial) / second_test_polynomial));
    first_test_polynomial = new Polynomial(2,std::vector<short> {-3,10,8});
    *first_test_polynomial /= second_test_polynomial;
    REQUIRE(*first_test_polynomial == result_test_polynomial);
}

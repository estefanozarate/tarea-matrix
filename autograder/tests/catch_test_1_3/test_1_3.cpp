//
// Created by rudri on 9/12/2020.
//
#include "catch/catch.hpp"
#include "redirect_io.h"
#include "matrix.h"
#include <iostream>
#include <random>
using namespace std;

static void question_1_3() {
    random_device rd;
    utec::matrix m1(8, 9);
    utec::matrix m2(4, 5);
    uniform_int_distribution<int> dis(0, 100);
    for (size_t i = 0; i < m1.rows(); ++i)
        for (size_t j = 0; j < m1.cols(); ++j)
            m1(i, j) = dis(rd);
    // Copia
    utec::matrix m3 = m1;
    for (size_t i = 0; i < m2.rows(); ++i)
        for (size_t j = 0; j < m2.cols(); ++j)
            m2(i, j) = dis(rd);
    // Comparando matrices
    cout << boolalpha << (m1 == m2) << endl;
    cout << boolalpha << (m3 == m1) << endl;
    cout << boolalpha << (m2 != m3) << endl;
}

TEST_CASE("Question #1_3") {
    execute_test("test_1_3.in", question_1_3);
}
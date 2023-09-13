//
// Created by rudri on 9/12/2020.
//
#include "catch/catch.hpp"
#include "redirect_io.h"
#include "matrix.h"
#include <iostream>
using namespace std;

static void question_1_4() {
    SIZE_TYPE rows = 0, cols = 0;
    cin >> rows >> cols;
    utec::matrix m1(rows, cols);
    for (size_t i = 0; i < m1.rows(); ++i)
        for (size_t j = 0; j < m1.cols(); ++j)
            cin >> m1(i, j);
    cin >> rows >> cols;
    utec::matrix m2(rows, cols);
    for (size_t i = 0; i < m2.rows(); ++i)
        for (size_t j = 0; j < m2.cols(); ++j)
            cin >> m2(i, j);
    cin >> rows >> cols;
    utec::matrix m3(rows, cols);
    for (size_t i = 0; i < m3.rows(); ++i)
        for (size_t j = 0; j < m3.cols(); ++j)
            cin >> m3(i, j);
    cout << m2 * m3 << endl;
    auto m4 = m1 + m2;
    cout << m4 << endl;
    m1 *= 5;
    cout << m1 << endl;
    auto m5 = 4 * m1 * 2 + m4;
    cout << m5 << endl;
}

TEST_CASE("Question #1_4") {
    execute_test("test_1_4.in", question_1_4);
}
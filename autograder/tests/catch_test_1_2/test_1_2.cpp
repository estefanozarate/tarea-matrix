//
// Created by rudri on 9/12/2020.
//
#include "catch/catch.hpp"
#include "redirect_io.h"
#include "matrix.h"
#include <iostream>
using namespace std;

static void question_1_2() {
    size_t rows = 0, cols = 0;
    cin >> rows >> cols;
    utec::matrix m1(rows, cols);
    for (size_t i = 0; i < m1.rows(); ++i) {
        for (size_t j = 0; j < m1.cols(); ++j) {
            cin >> m1(i, j);
        }
    }
    cin >> rows >> cols;
    utec::matrix m2(rows, cols);
    for (size_t i = 0; i < m2.rows(); ++i) {
        for (size_t j = 0; j < m2.cols(); ++j)
            cin >> m2(i, j);
    }
    utec::matrix m3 = m1;
    cout << m1.rows() << " " << m1.cols() << endl;
    cout << m2.rows() << " " << m2.cols() << endl;
    std::swap(m1, m2);
    m2(0, 0) = 99;
    cout << m1.rows() << " " << m1.cols() << endl;
    cout << m2.rows() << " " << m2.cols() << endl;
    cout << m1 << endl << m2 << endl << m3 <<endl;
}

TEST_CASE("Question #1_2") {
    execute_test("test_1_2.in", question_1_2);
}
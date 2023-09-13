//
// Created by rudri on 9/12/2020.
//
#include "catch/catch.hpp"
#include "redirect_io.h"
#include "matrix.h"
#include <random>
#include <iostream>
using namespace std;

static void question_1_1() {
    random_device rd;
    utec::matrix m1(10, 20);
    utec::matrix m2(30, 40);
    uniform_int_distribution<int> dis(0, 100);
    for (size_t i = 0; i < m1.rows(); ++i) {
        for (size_t j = 0; j < m1.cols(); ++j)
            m1(i, j) = dis(rd);
    }
    utec::matrix m3 = m1;
    for (size_t i = 0; i < m2.rows(); ++i) {
        for (size_t j = 0; j < m2.cols(); ++j)
            m2(i, j) = dis(rd);
    }
    cout << m1.rows() << " " << m1.cols() << endl;
    cout << m2.rows() << " " << m2.cols() << endl;
    swap(m1, m2);
    cout << m1.rows() << " " << m1.cols() << endl;
    cout << m2.rows() << " " << m2.cols() << endl;
}

TEST_CASE("Question #1_1") {
    execute_test("test_1_1.in", question_1_1);
}
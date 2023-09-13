[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/sFeKPPMI)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=11647325&assignment_repo_type=AssignmentRepo)
# Task #1: Tarea Introductoria - Matriz
**course:** Programación III  
**unit:** 1  
**cmake project:** prog3_unit1_tarea_introductoria_v2023_0
## Instructions
Subir a gradescope los siguientes archivos:

- **`matrix.h` y `matrix.cpp`**, contienen la declaración (.h) y definición (.cpp) de la clase **`matrix`**

## Question #1 - Matriz (20 points)

Desarrollar una matriz que permita realizar las siguientes operaciones:

#### **NOTA:** <u>No utilizar vectores</u> para su implementación, solo usar memoria dinámica y punteros.

- **Construcción, Ingreso e impresión de valores**  
  Use Case #1:
```cpp
    // Constructor por parametros
    utec::matrix m1(4, 5);
    // Ingreso de datos
    for (int i = 0; i < m1.rows(); ++i) {
        for (int j = 0; j < m1.cols(); ++j) {
            m1(i, j) = rand() % 100;
        }
    }
    // Impresion de libreria
    std::cout << m1;
    
    
```
- **Construcción copia y move**  
  Use Case #2:
```cpp
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
    cout << m1.rows() << " " << m1.cols() << endl;
    cout << m2.rows() << " " << m2.cols() << endl;
    cout << m1 << endl << m2 << endl;
    // Move
    std::swap(m1, m2);
    m2(0, 0) = 100;
    cout << m1.rows() << " " << m1.cols() << endl;
    cout << m2.rows() << " " << m2.cols() << endl;
    cout << m1 << endl << m2 << endl << m3 <<endl;
```
- **Comparar matrices**  
  Use Case #3:
```cpp
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
```

- **Operaciones entre matrices**  
  Use Case #4:
```cpp
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
    // Multiplicación entre matrices
    cout << m2 * m3 << endl;
    // Suma de matrices
    auto m4 = m1 + m2;
    cout << m4 << endl;
    // Autoincremento
    m1 *= 5;
    cout << m1 << endl;
    // Multiplicación escalar
    auto m5 = 4 * m1 * 2 + m4;
    cout << m5 << endl;
```
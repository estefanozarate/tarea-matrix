
#include "matrix.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
#include <ostream>
#include <random>
#include <iomanip>
#include <fstream>
#include <queue>
#include <ostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <stdexcept>

using namespace std;


Matrix::Matrix() {}

Matrix::Matrix(int filas, int columnas, const int setteandoMatrix){ //constructor utilizado para setear la matriz con un valor 0 
    this->x = filas;
    this->y = columnas;
    this->pMatrix= new int*[x];
    for(int i = 0; i < x; i++)
        pMatrix[i] = new int[y];
    // asignando valores dentro de la matrix
    for(int i = 0; i < x; i++){
        for(int j = 0 ; j < y; j++ )
            pMatrix[i][j] = setteandoMatrix;
    }
}

Matrix::Matrix(int filas, int columnas){
    this->x = filas;
    this->y = columnas;
    // generando matrix
    this->pMatrix= new int*[x];
    for(int i = 0; i < x; i++){
        pMatrix[i] = new int[y];
    }
    // asignando valores dentro de la matrix
    for(int i = 0; i < x; i++){
        for(int j = 0 ; j < y; j++ ){
            *(*(pMatrix + i ) + j) = rand() %100;
        }
    }
}

Matrix::Matrix(const Matrix&otra){ //copy constructor
  this->x = otra.x;
  this->y = otra.y;
  // Creando la nueva matriz
  this->pMatrix = new int*[x];
    for (int i = 0; i < x; i++)
        pMatrix[i] = new int[y];
    // Copiando los valores desde la matriz original
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++)
            *(*(pMatrix + i) + j) = *(*(otra.pMatrix + i) + j);
    }
}

void Matrix::swap(Matrix&otra){
    // Intercambia los tamaños de las matrices
    using std::swap;
    std::swap(this->x, otra.x);
    std::swap(this->y, otra.y);
    // Intercambia los punteros a las matrices
    std::swap(this->pMatrix, otra.pMatrix);
}

Matrix::Matrix(Matrix&& otra) noexcept{
    this->x = otra.x;
    this->y = otra.y;
    this->pMatrix =otra.pMatrix;
    otra.x = otra.y = 0; //dejando en un estado donde sea seguro eliminar el objeto que se uso para robar sus recursos...
    otra.pMatrix = nullptr; //igual...
}

Matrix::~Matrix(){
    for(int i =0; i < x; i++)
        delete [] this->pMatrix[i]; //liberando columnas
delete [] pMatrix;   
}

Matrix Matrix::operator+(Matrix& otra){
    if(this->x == otra.x && this->y == otra.y){
        Matrix nueva(this->x, this->y);
    for(int i = 0; i < otra.x; i++){
        for(int j = 0; j <otra.y; j++){
            nueva.pMatrix[i][j] = this->pMatrix[i][j] + otra.pMatrix[i][j];
        }
     }
     return nueva;
    }
    else
       {throw std::runtime_error("Matrices de diferentes dimensiones, no esta permtida la suma");}
}

Matrix Matrix::operator*(const int escalar){
Matrix resultado(this->x, this->y); // Crear una nueva matriz para almacenar el resultado
            for (int i = 0; i < this->x; i++) {
                for (int j = 0; j < this->y; j++) {
                    resultado.pMatrix[i][j] = this->pMatrix[i][j] * escalar;
                 }
             }    return resultado; // Devolver la nueva matriz con el resultado
}

Matrix Matrix::operator*(const Matrix& B){
        //sobrecargando operator * 1era es con int y la 2da es con Matrix. 
        //C++ eligira a cual invocar en funcion del tipo utilizado.
        //matrix (this) represatada por la matrix A
        //entonces: A x B = C
          if (this->y == B.x) {
            Matrix resultado(this->x, B.y, 0); // Crear una nueva matriz para almacenar el resultado y setteandola en 0 todos sus valores C[i][j] = 0
              for (int i = 0; i < this->x; i++) {
                  for (int j = 0; j < B.y; j++) {
                      for (int k = 0; k < this->y; k++)
                           resultado.pMatrix[i][j] += this->pMatrix[i][k] * B.pMatrix[k][j];
                  }
               } return resultado; // Devolver la matrix por valor para usar auto Matrix_C = Matrix_A * Matrix_B
          }  else{
               throw std::runtime_error("Las dimensiones de las matrices no son compatibles para la multiplicación");
            }
}

bool Matrix::operator==(const Matrix& B){
        // "==" -> retorna true si todos los elementos,filas y columnas son iguales.
        int filasA = this->x; int columnasA = this->y; int filasB = B.x; int columnasB = B.y;
        if((filasA != filasB) || (columnasA != columnasB)){return false;}
            for(int i = 0; i <  filasA; i++){
               for(int j = 0; j < filasB; j++){
                  if(this->pMatrix[i][j] != B.pMatrix[i][j])
                     return false;
                }
            } return true;
}

bool Matrix::operator!=(const Matrix& B){//tecnicamente es el inverso al operador "!="
        int filasA = this->x; int columnasA = this->y; int filasB = B.x; int columnasB = B.y;
        if((filasA != filasB) || (columnasA != columnasB)){return true;}
        for(int i = 0; i <  filasA; i++){
               for(int j = 0; j < filasB; j++){
                  if(this->pMatrix[i][j] != B.pMatrix[i][j])
                     return true;
               }
        }  return false;
}

Matrix Matrix::operator *=(const int NUMERO){ //sobrecaga del operador autoincremento "MatrixA*=5" es lo mismo que "MatrixA * 5 "
    int filas = this->x;
    int columnas = this->y;
    if(NUMERO == 0){
        Matrix RETORNAR(filas, columnas, 0);
        return RETORNAR;
    }
    else{
        Matrix matrixMultiplicada(filas, columnas,0);
        for (int i = 0; i < this->x; i++) {
            for (int j = 0; j < this->y; j++) {
                matrixMultiplicada.pMatrix[i][j] = this->pMatrix[i][j] * NUMERO;
            }
        }   return matrixMultiplicada; // Devolver la nueva matriz con el resultado    
    }
}

std::ostream& operator<<(std::ostream& COUT, const Matrix& matriz) {
    int f = matriz.x;
    int c = matriz.y;
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            COUT << matriz.pMatrix[i][j] << " ";
        }
        COUT << std::endl;
    }
    return COUT;
}
Matrix Matrix::operator+ (const int escalar){
    if(escalar == 0){return *this;}
    else{
        Matrix resultado(this->x, this->y,0);
        for(int i =0; i < this->x; i++){
            for(int j = 0; j < this->y; j++){
                resultado.pMatrix[i][j] = this->pMatrix[i][j] + escalar;
            }
        }
        return resultado;
    }
}

int main(){
    // creando matrices
    Matrix matriz1(3, 3, 0); 
    Matrix matriz2(2, 2);
    // matrix * escalar
    Matrix resultadoProductoEscalar = matriz1 * 8;
     // matrix * matrix
     Matrix matrizA(2, 3);
     Matrix matrizB(3, 4);
     Matrix MatrixC = matrizA * matrizB;

     // comprobando la igualdad
     if(matriz1 == matriz2){
        cout << "Son iguales" << endl;
     } else if( matriz1 != matriz2){
        cout << "Son diferentes" << endl;
     }
     // probando el contructor copia y el contructor de movimiento
     Matrix copiaMiMatrix(matriz1); 
     Matrix movidaMiMatrix(std::move(matriz1)); 
     // print matrix usando la sobrecarga <<
     Matrix matrixCerosToPrint(4,4,0);
     cout << "Imprimiendo los valores de la matrixdeceros" << endl << endl;
     cout << matrixCerosToPrint << endl; 
     // suma escalar a matrix
     cout << "Creando matriz de puros 0"<< endl;
     Matrix matrizsumaescalar(3,3,0);
     Matrix resultadosuma(matrizsumaescalar + 10); // la magia del copy constructor trabajando...
     cout << "Imprimiendo matriz de suma de escalar" << endl;
     cout << resultadosuma << endl;





    return EXIT_SUCCESS;
}


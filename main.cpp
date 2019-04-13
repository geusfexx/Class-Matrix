#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix
{
public:
    Matrix(){}
    Matrix(const int & a, const int & b)
    {

    }

    int & at(const int & a, const int & b)
    {

    }



private:

};

istream & operator>>(istream& input,Matrix & m)
{
    return input;
}

ostream & operator<<(ostream& output,Matrix & m)
{
    return output;
}

Matrix & operator+(const Matrix& m1, const Matrix & m2)
{
    Matrix result;
    return result;
}

bool operator==(const Matrix& m1, const Matrix & m2)
{
    return true;
}

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}

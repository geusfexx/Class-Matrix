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
    Matrix() : Data(nullptr), num_rows(0), num_cols(0), size(0){}

    Matrix(const int & num_rows, const int & num_cols)
    {
        if ((num_cols == 0)||(num_rows == 0))
        {
            Data = nullptr;
            size = 0;
        }
        else if ((num_cols > 0)&&(num_rows > 0))
        {
            this->size = num_rows * num_cols;

            //we allocate an unfragmented two-dimensional array in dynamic memory
            //WARNING! allocate by new [];

            this->Data = new int * [num_rows];
            Data[0] = new int [this->size];
            for (int i(1); i < num_rows; ++i)
            {
                Data[i] = Data[i - 1] + num_cols;
            }

            //so we have:
            //[0] -> [] -> ***** -> ***** -> ***** -> *****
        }

    }

    const int & at(const int & rows, const int & cols) const
    {
        if ((rows > this->num_rows)||(rows < 0)) throw out_of_range("Invalid parametr rows");
        else if ((cols > this->num_cols)||(cols < 0)) throw out_of_range("Invalid parametr cols");
        else return Data[rows][cols];
    }

    int & at(const int & rows, const int & cols)
    {
        if ((rows > this->num_rows)||(rows < 0)) throw out_of_range("Invalid parametr rows");
        else if ((cols > this->num_cols)||(cols < 0)) throw out_of_range("Invalid parametr cols");
        else return Data[rows][cols];
    }

    ~Matrix()
    {
        /*for (int i(1); i < this->num_rows; ++i)
        {
            delete [] this->Data[i];
        }*/
        delete [] this->Data;
        this->Data = nullptr;
    }

    const int & GetNumRows() const
    {
        return this->num_rows;
    }

    const int & GetNumColumns() const
    {
        return this->num_cols;
    }

private:

    int ** Data;
    int num_rows;
    int num_cols;
    int size;

};

istream & operator>>(istream& input,Matrix & m)
{
    int rows(0), cols(0);
    if (input >> rows >> cols)
    {
        if ((rows != m.GetNumRows())||(rows < 0)) throw out_of_range("Invalid parametr rows");
        else if ((cols != m.GetNumColumns())||(cols < 0)) throw out_of_range("Invalid parametr cols");
        else
        {
            for (int i(0); i < rows; ++i)
            {
                for (int j(0); j < cols; ++j)
                {
                    int tmp(0);
                    if (!input >> tmp) throw invalid_argument("Wrong data format");
                    else m.at(i, j) = tmp;
                }
            }
        }
    }
    else throw invalid_argument("Wrong type for rows/cols");
    return input;
}

ostream & operator<<(ostream& output,Matrix & m)
{
    int rows(m.GetNumRows()), cols(m.GetNumColumns());
    output << rows << " " << cols << endl;
    for (int i(0); i < rows; ++i)
    {
        for (int j(0); j < cols; ++j)
        {
            output << m.at(i, j) << " ";
        }
        output << endl;
    }
    output << endl;
    return output;
}

Matrix & operator+(const Matrix& m1, const Matrix & m2)
{
    Matrix result;
    return result;
}

bool operator==(const Matrix& m1, const Matrix & m2)
{
    if ((m1.GetNumColumns() != m2.GetNumColumns())||(m1.GetNumRows() != m2.GetNumRows()))
    {
        return false;
    }
    else
    {
        int rows(m1.GetNumRows()), cols(m1.GetNumColumns());
        for (int i(0); i < rows; ++i)
        {
            for (int j(0); j < cols; ++j)
            {
                if (m1.at(i, j) != m2.at(i, j)) return false;
            }
        }
    }
    //if both arrays are verified
    return true;
}


int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}

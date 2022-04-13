#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

namespace zich
{
    class Matrix
    {
    private:
        
        int _row;
        
        int _col;

        vector<double> _data;
    
    public:

        int getRow()const{ return this->_row; } 
        
        int getCol()const{ return this->_col; }
        
        vector<double> getData()const{ return this->_data; }
        
        void check(const Matrix mat)const;
        
        Matrix operator+(Matrix const &mat);
        
        Matrix& operator++();
        
        Matrix(const vector<double> &data, const int row, const int col);
        
        Matrix operator++(const int num);
       
        Matrix& operator+=(const Matrix &mat);

        vector<double> resize(vector<double> &mat);

        Matrix operator-(const Matrix &mat);
        
        Matrix& operator--();
        
        Matrix();

        Matrix operator--(const int num);
        
        Matrix& operator-=(const Matrix &mat);
        
        vector<double> resize2(const Matrix &mat, vector<double> &mat2);

        Matrix operator*(const Matrix &mat);
        
        Matrix& operator*=(const Matrix &mat);

        void setMatrix(vector<double> data, int row, int col);

        Matrix operator*(const double scalar);
        
        Matrix& operator*=(const double scalar);

        bool operator>(Matrix &mat);
        
        bool operator>=(Matrix &mat);
        
        ~Matrix();

        bool operator<(Matrix &mat);
        
        bool operator<=(Matrix &mat);

        void check2(vector<double> data, int row, int col)const;

        bool operator!=(Matrix &mat);
        
        double mul(const Matrix &mat, const int tempRow, const int tempCol);

        void check3(const Matrix &mat);

        friend ostream & operator << (ostream &out,  Matrix &mat);
        
        friend istream& operator>> (istream &input , Matrix& mat);
        
        void setRow(int row){ this->_row = row; }
        
        void setCol(int col){ this->_col = col; }
        
        void setData(vector<double> data){ this->_data = data; }
        
        friend Matrix operator-(Matrix &mat);
        
        friend Matrix operator+(Matrix &mat);
        
        friend Matrix operator*(const double scalar, Matrix &mat);
        
        vector<string> split(string str, char seperator);

        friend bool operator==(Matrix const &mat1,Matrix const &mat2);
    };
}
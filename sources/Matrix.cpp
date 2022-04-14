#include "Matrix.hpp"
namespace zich{
    void Matrix::setMatrix(vector<double> data, int row, int col){
        this->setRow(row);this->setCol(col);this->setData(data);}
    bool operator ==(Matrix const &mat1,Matrix const &mat2){
        if (mat1.getRow() != mat2.getRow() || mat1.getCol() != mat2.getCol()){throw invalid_argument("row and cols must be equals");}        
        for (int i = 0; i < mat1.getRow(); i++){for (int j = 0; j < mat1.getCol(); j++){if (mat1.getData()[(unsigned int)(i * mat1.getCol() + j)] != mat2.getData()[(unsigned int)(i * mat2.getCol() + j)]){return false;}}}return true;}
    Matrix Matrix::operator*(const Matrix &mat){
        check3(mat);vector<double> mat3_data;resize2(mat,mat3_data);
        for (int i = 0; i < getRow(); i++){for (int j = 0; j < mat.getCol(); j++){mat3_data[(unsigned int)(i * mat.getCol() + j)] = mul(mat, i, j);}}
        Matrix mat3(mat3_data, getRow(), mat.getCol());
        return mat3;} 
    Matrix::Matrix(const vector<double> &data, const int row, const int col){
        check2(data,row,col);setMatrix(data,row,col);}
    Matrix Matrix::operator*(const double scalar){
        vector<double> mat3_data;resize(mat3_data);
        for (int i = 0; i < getRow(); i++){for (int j = 0; j < getCol(); j++){if (getData()[(unsigned int)(i * getCol() + j)] == 0){continue;}mat3_data[(unsigned int)(i * getCol() + j)] = getData()[(unsigned int)(i * getCol() + j)] * scalar;}}
        Matrix mat3(mat3_data, getRow(), getCol());
        return mat3;}
    inline vector<double> Matrix::resize(vector<double> &mat){
        mat.resize((unsigned int)(_row * _col));
        return mat;}
    Matrix operator*(const double scalar, Matrix &mat){
        vector<double> mat3_data;mat3_data.resize((unsigned int)(mat.getRow() * mat.getCol()));
        for (int i = 0; i < mat.getRow(); i++){for (int j = 0; j < mat.getCol(); j++){if (mat._data[(unsigned int)(i * mat.getCol() + j)] == 0){continue;}mat3_data[(unsigned int)(i * mat.getCol() + j)] = scalar * mat.getData()[(unsigned int)(i * mat.getCol() + j)];}}
        Matrix mat3(mat3_data, mat.getRow(), mat.getCol());
        return mat3;}
    Matrix Matrix::operator+(Matrix const &mat){
        check(mat);vector<double> mat3_data;resize(mat3_data);
        for (int i = 0; i < _row; i++){for (int j = 0; j < _col; j++){mat3_data[(unsigned int)(i * _col + j)] = getData()[(unsigned int)(i * _col + j)] + mat.getData()[(unsigned int)(i * _col + j)];}}
        Matrix mat3(mat3_data, getRow(), mat.getCol());
        return mat3;}
    Matrix operator+(Matrix &mat){
        vector<double> mat3_data;mat3_data.resize((unsigned int)(mat.getRow() * mat.getCol()));
        for (int i = 0; i < mat.getRow(); i++){for (int j = 0; j < mat.getCol(); j++){if (mat.getData()[(unsigned int)(i * mat.getCol() + j)] == 0){continue;}mat3_data[(unsigned int)(i * mat.getCol() + j)] = mat.getData()[(unsigned int)(i * mat.getCol() + j)];}}
        Matrix mat3(mat3_data, mat.getRow(), mat.getCol());
        return mat3;}
    inline vector<double> Matrix::resize2(const Matrix &mat, vector<double> &mat2){
        mat2.resize((unsigned int)(this->_row * mat._col));
        return mat2; }
    Matrix &Matrix::operator++(){
        for (int i = 0; i < getRow(); i++){for (int j = 0; j < getCol(); j++){this->_data[(unsigned int)(i * _col + j)] += 1;}}
        return *this;}
    Matrix &Matrix::operator*=(const Matrix &mat){
        check3(mat);vector<double> mat3_data;resize2(mat,mat3_data);
        for (int i = 0; i < getRow(); i++){for (int j = 0; j < mat.getCol(); j++){mat3_data[(unsigned int)(i * mat.getCol() + j)] = mul(mat, i, j);}}
        setCol(mat.getCol());setData(mat3_data);
        return *this;}
    Matrix Matrix::operator++(const int num){
        Matrix copy = *this;
        for (int i = 0; i < getRow(); i++){for (int j = 0; j < getCol(); j++){this->_data[(unsigned int)(i * _col + j)] += 1;}}
        return copy;}
    double Matrix::mul(const Matrix &mat, const int tempRow, const int tempCol){
        double sum = 0;
        for (int i = 0; i < getCol(); i++){sum += getData()[(unsigned int)(getCol() * tempRow + i)] * mat.getData()[(unsigned int)(mat.getCol() * i + tempCol)];}
        return sum;}
    Matrix &Matrix::operator*=(const double scalar){
        for (int i = 0; i < getRow(); i++){for (int j = 0; j < getCol(); j++){if (getData()[(unsigned int)(i * getCol() + j)] == 0){continue;}this->_data[(unsigned int)(i * getCol() + j)] *= scalar;}}
        return *this;}
    Matrix Matrix::operator-(const Matrix &mat){
        check(mat);vector<double> mat3_data;resize(mat3_data);
        for (int i = 0; i < _row; i++){for (int j = 0; j < _col; j++){mat3_data[(unsigned int)(i * _col + j)] = getData()[(unsigned int)(i * _col + j)] - mat.getData()[(unsigned int)(i * _col + j)];}}
        Matrix mat3(mat3_data, getRow(), mat.getCol());
        return mat3;}
    vector<string> split(string str, char seperator){
        int len = str.length();string temp = "";vector<string> vec;
        for (int i = 0; i < len; i++){if (str[(unsigned int)i] == seperator && !temp.empty()){vec.push_back(temp);temp = "";}else{if (str[(unsigned int)i] == '[' || str[(unsigned int)i] == ']'){continue;}temp += str[(unsigned int)i];}}
        vec.push_back(temp);
        return vec;}
    Matrix operator-(Matrix &mat){
        vector<double> mat3_data;mat3_data.resize((unsigned int)(mat.getRow() * mat.getCol()));
        for (int i = 0; i < mat.getRow(); i++){for (int j = 0; j < mat.getCol(); j++){if (mat.getData()[(unsigned int)(i * mat.getCol() + j)] == 0){continue;}mat3_data[(unsigned int)(i * mat.getCol() + j)] = (-1) * mat.getData()[(unsigned int)(i * mat.getCol() + j)];}}
        Matrix mat3(mat3_data, mat.getRow(), mat.getCol());
        return mat3;}
    Matrix &Matrix::operator+=(const Matrix &mat){
        check(mat);
        for (int i = 0; i < getRow(); i++){for (int j = 0; j < getCol(); j++){this->_data[(unsigned int)(i * _col + j)] += mat.getData()[(unsigned int)(i * _col + j)];}}
        return *this;}
    ostream &operator<<(ostream &out, Matrix &mat){
        int k = 0;
        for (int i = 0; i < mat.getRow(); i++){
            int p = 1;
            out << '[';
            for (int j = 0; j < mat.getCol(); j++){
                int f = 2;
                if (j != mat.getCol() - 1){
                    int d = 3;
                    out << mat.getData()[(unsigned int)(i * mat.getCol() + j)] << ' ';}
                    else{out << mat.getData()[(unsigned int)(i * mat.getCol() + j)];}}
                    int e = 4;
                    if (i != mat.getRow() - 1){
                        int w = 5;
                        out << ']' << '\n';}
                    else{out << ']';}}
        int t = 6;
        return out;}
    Matrix &Matrix::operator--(){
        for (int i = 0; i < getRow(); i++){for (int j = 0; j < getCol(); j++){this->_data[(unsigned int)(i * _col + j)] -= 1;}}
        return *this;}
    bool Matrix::operator>=(Matrix &mat){
        check(mat);double sum1 = 0;
        for (int i = 0; i < getRow(); i++){for (int j = 0; j < getCol(); j++){sum1 += getData()[(unsigned int)(i * _col + j)];}}
        double sum2 = 0;
        for (int i = 0; i < mat.getRow(); i++){for (int j = 0; j < mat.getCol(); j++){sum2 += mat.getData()[(unsigned int)(i * _col + j)];}}
        return sum1 >= sum2;}
    Matrix Matrix::operator--(const int num){
        Matrix copy = *this;
        for (int i = 0; i < getRow(); i++){for (int j = 0; j < getCol(); j++){this->_data[(unsigned int)(i * _col + j)] -= 1;}}
        return copy;}
    inline void Matrix::check(const Matrix mat)const{
        if (getRow() != mat.getRow() || getCol() != mat.getCol()){throw runtime_error("row and col must be equal");}}
    istream &operator>>(istream &input, Matrix &mat){
        string s = "";char ch = 0;
        while (ch != '\n'){ch = input.get();s += ch;}
        s.pop_back();
        for (unsigned int i = 0; i < s.length()-1; i++){if (s.at(i) == ',' && s.at(i+1) != ' '){throw invalid_argument("String worng");}}
        vector<string> vs = split(s, ',');int col = 0;int row = vs.size();int flag = 1;int len1 = vs.size();
        vector<double> vd;vector<string> vs2;
        for (int i = 0; i < len1; i++){vs2 = split(vs[(unsigned int)i], ' ');int len2 = vs2.size();if (flag == 1){flag = 0;col = len2;}if (col != len2){throw invalid_argument("String worng");}for (int j = 0; j < len2; j++){vd.push_back(stod(vs2[(unsigned int)j]));}}
        mat.setMatrix(vd,row,col);
        return input;}
    Matrix &Matrix::operator-=(const Matrix &mat){
        check(mat);
        for (int i = 0; i < getRow(); i++){for (int j = 0; j < getCol(); j++){this->_data[(unsigned int)(i * _col + j)] -= mat.getData()[(unsigned int)(i * _col + j)];}}
        return *this;}
    bool Matrix::operator!=(Matrix &mat){
        check(mat);
        for (int i = 0; i < getRow(); i++){for (int j = 0; j < getCol(); j++){if (getData()[(unsigned int)(i * _col + j)] != mat.getData()[(unsigned int)(i * _col + j)]){return true;}}}
        return false;}
    bool Matrix::operator>(Matrix &mat){
        check(mat);double sum1 = 0;
        for (int i = 0; i < getRow(); i++){for (int j = 0; j < getCol(); j++){sum1 += getData()[(unsigned int)(i * _col + j)];}}
        double sum2 = 0;
        for (int i = 0; i < mat.getRow(); i++){for (int j = 0; j < mat.getCol(); j++){sum2 += mat.getData()[(unsigned int)(i * _col + j)];}}
        return sum1 > sum2;}
    inline void Matrix::check2(vector<double> data, int row, int col)const{
        if (row <= 0 || col <= 0){throw runtime_error("row or col can't be negative");}
        if (data.size() != row * col){throw runtime_error("the array must be equal to the size of the matrix");}
    }
    bool Matrix::operator<(Matrix &mat){
        check(mat);double sum1 = 0;
        for (int i = 0; i < getRow(); i++){for (int j = 0; j < getCol(); j++){sum1 += getData()[(unsigned int)(i * _col + j)];}}
        double sum2 = 0;
        for (int i = 0; i < mat.getRow(); i++){for (int j = 0; j < mat.getCol(); j++){sum2 += mat.getData()[(unsigned int)(i * _col + j)];}}
        return sum1 < sum2;}
    inline void Matrix::check3(const Matrix &mat){
        if (this->_col != mat._row){throw runtime_error("Cols not equal");}}
    bool Matrix::operator<=(Matrix &mat){
        check(mat);double sum1 = 0;
        for (int i = 0; i < getRow(); i++){for (int j = 0; j < getCol(); j++){sum1 += getData()[(unsigned int)(i * _col + j)];}}
        double sum2 = 0;
        for (int i = 0; i < mat.getRow(); i++){for (int j = 0; j < mat.getCol(); j++){sum2 += mat.getData()[(unsigned int)(i * _col + j)];}}
        return sum1 <= sum2;}
    Matrix::~Matrix(){}   
}
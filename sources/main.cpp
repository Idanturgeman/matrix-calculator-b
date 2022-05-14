#include "Matrix.cpp"

using namespace zich;

int main(int argc, char const *argv[])
{
    vector<double> vector1;
    vector<double> vector2;
    for (double i = 0; i < 25; ++i){ vector1.push_back(i); }
    for (double i = 0; i < 36; ++i){ vector2.push_back(i); }
    Matrix a{vector1, 5, 5};
    Matrix b{vector2, 6, 6};
    try
    {
        b *= a;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        a *= b;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        a += b;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        b += a;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    cout<<"\n"<<endl;

    vector<double> vector3;
    vector<double> vector4;
        
    for (double i = 0; i < 16; ++i){ vector3.push_back(i); }
    for (double i = 0; i < 16; ++i){ vector4.push_back(i); }
        
    Matrix c{vector3, 4, 4};
    Matrix d{vector4, 4, 4};

    c *= d;

    cout<<c<<endl;

    cout<<"\n"<<endl;


    vector<double> vector5;
    vector<double> vector6;
        
    for (double i = 0; i < 16; ++i){ vector5.push_back(i); }
    for (double i = 0; i < 16; ++i){ vector6.push_back(i); }
        
    Matrix e{vector5, 4, 4};
    Matrix g{vector6, 4, 4};

    e += g;

    cout<<e<<endl;

    cout<<"\n"<<endl;


    vector<double> vector7;
    vector<double> vector8;
        
    for (double i = 0; i < 16; ++i){ vector7.push_back(i); }
    for (double i = 0; i < 16; ++i){ vector8.push_back(i); }
        
    Matrix h{vector7, 4, 4};
    Matrix k{vector8, 4, 4};

    h -= k;

    cout<<h<<endl;


    cout<<"\n"<<endl;


    vector<double> vector9;
    
        
    for (double i = 0; i < 16; ++i){ vector9.push_back(i); }
        
    Matrix l{vector9, 4, 4};

    l *= 3;

    cout<<l<<endl;


    
}


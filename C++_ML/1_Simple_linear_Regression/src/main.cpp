#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main()
{
    plt::plot({1, 3, 2, 4});
    plt::show();
}
// g++ main.cpp -std=c++11 -I/usr/include/python2.7 -lpython2.7
// D:\Learning\venv3.9\Scripts\python.exe

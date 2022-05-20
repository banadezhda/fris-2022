#ifndef __CORE_H__
#define __CORE_H__

#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Matrix {
public:
    Matrix() {};
    Matrix(size_t rows, size_t cols);
    double& operator()(size_t i, size_t j);
    double operator()(size_t i, size_t j) const;
    void print(ostream& o);

private:
    size_t mRows;
    size_t mCols;
    vector<double> mData;
};

class FRIS {
public:
    FRIS() {};
    bool loadData(string filename);
    bool outResult(ostream& stream);
    bool calculate();
    void printFrame(ostream& out);
protected:
    bool calcdiss();
private:
    // vector<double> m_v;
    vector<vector<double>> m_frame;
    Matrix * m_diss = nullptr;
public:
    ~FRIS();
private:
    size_t h=0, w=0;
private:
    // By definition it is Euler distance
    virtual double diss(vector<double> o1, vector<double> o2);
};

#endif // __CORE_H__
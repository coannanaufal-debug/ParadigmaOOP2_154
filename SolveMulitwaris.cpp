#include<iostream>
using namespace std;

class orang {
public:
int umur;
orang(int Pumur) 
    umur(Pumur)
    { cout << "orang dibuat dengan umur " << umur <<  "\n" << endl; }
};

class pekerja : public orang {
public:
    pekerja(int pUmur) :
        orang(pUmur)
    {
        cout << "pekerja dibuat\n" << endl;
    }
};

class pelajar : public orang {
public:
    pelajar(int pUmur) :
        orang(pUmur)
    {
        cout << "pelajar dibuat\n" << endl;
    }
};


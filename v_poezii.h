
#include "volum.h"
#pragma once

class Poezii:public Volum{
private:
    int nrPoezii;
public:
    Poezii();
    Poezii(char* a,char* t, int p);
    ~Poezii();

    int getNrPoezii();
    void setNrPoezii(int p);

    int equals(Volum *);
    string toString();
};

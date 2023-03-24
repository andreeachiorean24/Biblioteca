#include "volum.h"

#pragma once
class Nuvela:public Volum{
private:
    char* editura;
public:
    Nuvela();
    ~Nuvela();
    Nuvela(char*a, char*t, char* e);

    void setEditura(char* e);
    char* getEditura();

    int equals(Volum *);
    string toString();

};

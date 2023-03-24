#include <cstring>
#include "volum.h"

using namespace std;

#pragma once

class ValidatorVolum{
protected:
    int err;
    string mesaj;
public:
    ValidatorVolum();
    ~ValidatorVolum();

    virtual int validate(Volum *);

    string getMesaj();
    int getErr();


};

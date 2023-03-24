#include <vector>
#include "volum.h"
#include "validator_volum.h"
#pragma once
using namespace std;

class Repository{
private:
    vector <Volum*> elems;
    ValidatorVolum* validator;
public:
    Repository();
    Repository(ValidatorVolum*);
    void add(Volum*);
    int del(Volum*);
    int search(Volum* );
    vector<Volum*> get_all();
    int size();
    int update(Volum*,Volum*);
    ~Repository();
};

#include "repo.h"
#include "v_nuvela.h"
#include "v_poezii.h"
#pragma once

class Service{
private:
    Repository poezii;
    Repository nuvele;
public:
    Service();
    Service(Repository &, Repository &);
    void adauga_nuvela(char*, char*, char*);
    void adauga_poezii(char*, char*, int);
    int imprumut_nuvela(char*, char*, char*);
    int imprumut_poezie(char*, char*, int);
    int retur_nuvela(char*, char*, char*);
    int retur_poezie(char*, char*, int);
    int cautare_nuvela(char*, char*, char*);
    int cautare_poezie(char*, char*, int);

    vector<Volum*> get_nuvele();
    vector<Volum*> get_poezii();

    ~Service();

    vector<Volum*> sortare_autor();


};


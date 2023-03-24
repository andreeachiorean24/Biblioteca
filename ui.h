#include "service.h"
#pragma once

class Ui{
private:
    Service service;
public:
    Ui(Service&);
    Ui();

    void show_menu();
    ~Ui();

    void adaugare_volum();
    void imprumutare_volum();
    void returnare_volum();
    void cautare_volume();
    void show_volume();
    void sort_volume();


};



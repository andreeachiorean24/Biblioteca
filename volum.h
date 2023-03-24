#include <string>

using namespace std;

#pragma once


class Volum{
protected:
    char* titlu;
    char* autor;
    bool  disponibil;

public:

    Volum();
    Volum(char* t, char* a);

    virtual ~Volum();
    virtual int equals(Volum *);
    virtual string toString();

    void setTitlu(char* t);
    void setAutor(char* a);
    void setDisponibil(bool d);

    char* getTitlu();
    char* getAutor();
    bool esteDisponibil();

};

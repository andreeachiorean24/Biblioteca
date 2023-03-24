#include "volum.h"
#include <cstring>
#include <iostream>

using namespace std;

Volum::~Volum(){
    if(this->autor) delete[] this->autor;
    if(this->titlu) delete[] this->titlu;

}

Volum::Volum(){
    this->titlu = 0;
    this->autor = 0;
    this->disponibil= false;
}

Volum::Volum(char* t, char * a){
    this->titlu = new char[strlen(t)+1];
    strcpy(this->titlu, t);

    this->autor = new char[strlen(a)+1];
    strcpy(this->autor, a);

    this->disponibil = true;
}

int Volum::equals(Volum * v){
    return (strcmp(this->titlu,v->titlu)==0 && strcmp(this->autor,v->autor)==0);
}

string Volum::toString(){
    string a;
    a+=(string)this->autor;
    a+=" ";
    a+=(string)this->titlu;

    return a;
}

void Volum::setAutor(char *a){
    if(this->autor!=0)
        delete[] this->autor;

    this->autor = new char[strlen(a)+1];
    strcpy(this->autor, a);

}

void Volum::setTitlu(char * t){

    if(this->titlu!=0)
        delete[] this->titlu;

    this->titlu = new char[strlen(t)+1];
    strcpy(this->titlu, t);

}

void Volum::setDisponibil(bool d){

    this->disponibil = d;
}

char * Volum::getAutor(){

    return this->autor;
}

char* Volum::getTitlu(){

    return this->titlu;
}

bool Volum::esteDisponibil(){

    return this->disponibil;
}

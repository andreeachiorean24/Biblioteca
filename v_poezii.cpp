#include "v_poezii.h"
#include <cstring>
#include <cstdlib>

using namespace std;

Poezii::~Poezii(){
;
}

Poezii::Poezii():Volum(){
    this->nrPoezii = 0;
}

Poezii::Poezii(char*a, char*t, int p):Volum(a,t){

    this->nrPoezii = p;

}

int Poezii::getNrPoezii(){

    return this->nrPoezii;
}

void Poezii::setNrPoezii(int p){

    this->nrPoezii = p;
}

int Poezii::equals(Volum* v){
    Poezii *p = (Poezii*) v;

    return (Volum::equals(v)&& this->nrPoezii == p->nrPoezii);
}

string Poezii::toString(){
    string p=Volum::toString();
    p+=" ";
    char* intStr= new char[5];
    itoa(this->nrPoezii,intStr,10);
    p+= (string) intStr;

    return p;

}


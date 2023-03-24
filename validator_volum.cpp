#include "validator_volum.h"

using namespace std;

ValidatorVolum::ValidatorVolum(){
    this->err = 0;
    this->mesaj = "";
}

ValidatorVolum::~ValidatorVolum(){
    ;

}

int ValidatorVolum::validate(Volum* v){
    this->err = 0;
    this->mesaj = "";
    if(strlen(v->getAutor())==0) {
        this->err++;
        this->mesaj+="Volumul nu are autor!";
    }
    if(strlen(v->getTitlu())==0){
        this->err++;
        this->mesaj+=" ";
        this->mesaj+="Volumul nu are titlu!";
    }

    for(int i=0;i<strlen(v->getAutor());i++){
        if(!isalpha(v->getAutor()[i])){
            this->err++;
            this->mesaj+="Autorul contine caractere nepermise!";
        }
    }
    return this->err;
}

int ValidatorVolum::getErr(){

    return this->err;
}

string ValidatorVolum::getMesaj(){

    return this->mesaj;
}

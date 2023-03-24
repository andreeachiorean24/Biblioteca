#include "repo.h"
#include "validation_exception.h"

Repository::Repository(){

}

Repository::Repository(ValidatorVolum* valid){

    this->validator = valid;
}
void Repository::add(Volum* v){

    if(this->validator->validate(v)==0)
        this->elems.push_back(v);
    else{
        throw ValidationException(this->validator->getMesaj().c_str());
    }
}

int Repository::del(Volum* v){
    for(int i=0;i<this->elems.size();i++)
    if(v->equals(elems[i])){
            elems[i]=elems[elems.size()-1];
            this->elems.pop_back();
            return 1;
    }
    return 0;

}

int Repository::search(Volum* v){
    for(int i=0;i<this->elems.size();i++)
        if(v->equals(elems[i])) return 1;

    return 0;
}

vector<Volum*>Repository::get_all(){
    return this->elems;
}

int Repository::size(){
    return this->elems.size();
}

int Repository::update(Volum* a, Volum *b){
    for(int i=0;i<this->elems.size();i++)
        if(a->equals(elems[i])){
                elems[i]=b;
                return 1;
    }
    return 0;

}

Repository::~Repository(){
    ;
}


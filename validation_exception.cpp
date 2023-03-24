#include "validation_exception.h"
#include <cstring>

using namespace std;

ValidationException::ValidationException(const char* m){

    this->mesaj = new char[strlen(m)+1];
    strcpy(this->mesaj, m);

}

ValidationException::~ValidationException() throw(){
    if(this->mesaj) delete[]this->mesaj;
}

const char * ValidationException::what() const throw(){

    return this->mesaj;

}

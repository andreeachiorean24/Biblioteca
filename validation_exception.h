#include <exception>
using namespace std;
#pragma once

class ValidationException:public exception{
    char* mesaj;
public:
    ValidationException(const char* m);
    ~ValidationException() throw();

    const char*what() const throw();

};

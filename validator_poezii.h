#include "validator_volum.h"
#pragma once

class ValidatorPoezii:public ValidatorVolum{

public:
    ValidatorPoezii();
    ~ValidatorPoezii();

    int validate(Volum* );
};

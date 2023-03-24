#include "validator_volum.h"
#pragma once

class ValidatorNuvela:public ValidatorVolum{

public:
    ValidatorNuvela();
    ~ValidatorNuvela();

    int validate(Volum* );

};

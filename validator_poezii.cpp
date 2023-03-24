#include "validator_poezii.h"
#include "v_poezii.h"

ValidatorPoezii::ValidatorPoezii():ValidatorVolum(){

}

ValidatorPoezii::~ValidatorPoezii(){

;
}

int ValidatorPoezii::validate(Volum* v){
    Poezii *p = (Poezii*) v;
    ValidatorVolum::validate(v);

    if(p->getNrPoezii()==0){
        this->err++;
        this->mesaj+="Nu exista poezii!";
    }

    return this->err;

}

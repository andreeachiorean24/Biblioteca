#include "validator_nuvela.h"
#include "v_nuvela.h"

ValidatorNuvela::ValidatorNuvela():ValidatorVolum(){


}

ValidatorNuvela::~ValidatorNuvela(){

;
}

int ValidatorNuvela::validate(Volum* v){
    Nuvela * p =(Nuvela* )v;
    ValidatorVolum::validate(v);

    if(strlen(p->getEditura())==0){
        this->err++;
        this->mesaj+="Nuvela nu are editura!";
    }
    for(int i=0;i<strlen(p->getEditura());i++){
        if(!isalpha(p->getEditura()[i])){
            this->err++;
            this->mesaj+=" ";
            this->mesaj+="Editura contine caractere nepermise!";
        }
    }
    return this->err;

}

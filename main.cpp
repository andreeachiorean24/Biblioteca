#include <iostream>
#include "repo.h"
#include "service.h"
#include "ui.h"
#include "validator_poezii.h"
#include "validator_volum.h"
#include "validator_nuvela.h"

using namespace std;

int main()
{



    ValidatorVolum*vn = new ValidatorNuvela();
    ValidatorVolum* vv = new ValidatorPoezii();
    Repository nuvele(vn);
    Repository poezii(vv);

    Service service(nuvele,poezii);

    Ui ui(service);
    ui.show_menu();

    return 0;
}

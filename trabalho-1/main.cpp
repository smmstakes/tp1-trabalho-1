#include <iostream>
#include "tests/utils/executor_de_testes.hpp"
#include <iostream>
#include "./src/apresentacao/MACarteira/CntrlIACarteira.hpp" 
#include "./libs/comandoSQL/comandoSQL.hpp"


int main() {
    try {
        ComandoSQL comando;
        comando.inicializarBanco();

        CntrlIACarteira controladorCarteira;
        controladorCarteira.executar();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}


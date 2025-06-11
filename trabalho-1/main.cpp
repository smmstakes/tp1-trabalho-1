#include <iostream>
#include "tests/utils/executor_de_testes.hpp"
#include <iostream>
#include "./src/servico/MSInvestimentos/MSInvestimentos.hpp" 
#include "./src/apresentacao/MAInvestimentos/CntrlIAInvestimentos.hpp" 


int main() {
    try {
        CntrlIAInvestimentos controladorInvestimentos;
        controladorInvestimentos.executar();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}


#include <iostream>
#include "tests/utils/executor_de_testes.hpp"
#include <iostream>
// #include "./src/servico/MSInvestimentos/MSInvestimentos.hpp" 
#include "./src/apresentacao/MACarteira/CntrlIACarteira.hpp" 


int main() {
    try {
        CntrlIACarteira controladorCarteira;
        controladorCarteira.executar();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}


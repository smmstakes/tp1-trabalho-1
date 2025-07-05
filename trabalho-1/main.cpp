#include <iostream>
#include "./apresentacao/aplicacao_controlador.hpp"

int main() {
    std::cout << "Inicializando sistema..." << std::endl;

    try {
        CntrlIAAplicacao sistema;
        sistema.inicializar();
        sistema.executar();
    } catch (const std::exception& e) {
        std::cerr << "\nErro fatal: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\nEncerrando o programa..." << std::endl;
    return 0;
}

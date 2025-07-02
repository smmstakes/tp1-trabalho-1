#include <iostream>
#include "./apresentacao/gerenciador.hpp" // ou o nome correto do seu arquivo .hpp

int main() {
    std::cout << "Inicializando sistema..." << std::endl;

    try {
        GerenciadorSistema sistema;
        sistema.inicializar();
        sistema.executar();
    } catch (const std::exception& e) {
        std::cerr << "\nErro fatal: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\nEncerrando o programa..." << std::endl;
    return 0;
}

#include <iostream>

#include "./utils/executor_de_testes.hpp"

int main() {
    try {
        ExecutorDeTestes::executarTodos();
    } catch (const std::string& nomeTipo) {
        std::cerr << "Erro: teste '" << nomeTipo << "' falhou. Encerrando execução." << std::endl;
        return 1;
    }

    return 0;
}

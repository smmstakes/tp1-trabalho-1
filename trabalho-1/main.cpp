#include <iostream>
#include "tests/utils/executor_de_testes.hpp"

#include "db/banco_de_dados.hpp"

int main() {
    BancoDeDados bd;

    if (bd.conectar("./db/sistema.db")) {
        if (bd.criarTabelas()) {
            std::cout << "Tabelas criadas com sucesso!" << std::endl;
        } else {
            std::cerr << "Erro ao criar tabelas." << std::endl;
        }
        bd.desconectar();
    }

    return 0;
}

// int main() {
//     try {
//         ExecutorDeTestes::executarTodos();
//     } catch (const std::string& nomeTipo) {
//         std::cerr << "Erro: teste '" << nomeTipo << "' falhou. Encerrando execução." << std::endl;
//         return 1;
//     }

//     return 0;
// }

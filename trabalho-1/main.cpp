#include <iostream>
#include "tests/utils/executor_de_testes.hpp"
#include <iostream>
#include "./src/servico/MSInvestimentos/MSInvestimentos.hpp"  // Classe de serviço que implementa a lógica de negócios
#include "./src/apresentacao/MAInvestimentos/CntrlIAInvestimentos.hpp"  // Controlador de interface de usuário para investimentos

int main() {
    MSInvestimentos servicoInvestimentos;

    std::string codigo = "00001";
    std::string nome = "Carteira T2";
    std::string perfil = "Moderado";

    try {
        CntrlIAInvestimentos controladorInvestimentos;
        controladorInvestimentos.executar();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
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

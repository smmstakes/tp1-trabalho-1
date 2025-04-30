#include <iostream>
#include "./tests/tests.hpp"
#include "./tests/dominios/cpf_test.hpp"
#include "./tests/dominios/nome_test.hpp"
#include "./tests/dominios/data_test.hpp"
#include "./tests/dominios/senha_test.hpp"
#include "./tests/dominios/codigo_test.hpp"
#include "./tests/dominios/perfil_test.hpp"
#include "./tests/dominios/dominios_test.hpp"
#include "./tests/dominios/dinheiro_test.hpp"
#include "./tests/dominios/quantidade_test.hpp"
#include "./tests/dominios/codigo_negociacao_test.hpp"

#include "./tests/entidades/ordem_test.hpp"

int main() {
    try {
        ExecutorDeTestes::executar(new TUCPF(), "TUCPF");
        ExecutorDeTestes::executar(new TUData(), "TUData");
        ExecutorDeTestes::executar(new TUNome(), "TUNome");
        ExecutorDeTestes::executar(new TUSenha(), "TUSenha");
        ExecutorDeTestes::executar(new TUPerfil(), "TUPerfil");
        ExecutorDeTestes::executar(new TUCodigo(), "TUCodigo"); 
        ExecutorDeTestes::executar(new TUDinheiro(), "TUDinheiro");
        ExecutorDeTestes::executar(new TUQuantidade(), "TUQuantidade");
        ExecutorDeTestes::executar(new TUCodigoNegociacao, "TUCodigoNegociacao");

        ExecutorDeTestes::executar(new TUOrdem, "TUOrdem");
        
    } catch (const std::string& nomeTipo) {
        std::cerr << "Erro: teste '" << nomeTipo << "' falhou. Encerrando execução." << std::endl;
        return 1;
    }

    return 0;
}

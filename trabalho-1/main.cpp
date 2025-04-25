#include <iostream>
#include "./tests/tests.hpp"
#include "./tests/dominios/cpf_test.hpp"
#include "./tests/dominios/cpf_test.hpp"
#include "./tests/dominios/data_test.hpp"
#include "./tests/dominios/codigo_test.hpp"
#include "./tests/dominios/dominios_test.hpp"
#include "./tests/dominios/codigo_negociacao_test.hpp"

int main() {
    try {
        GerenciadorDeTestes::executar(new TUCodigo(), "TUCodigo");
        GerenciadorDeTestes::executar(new TUCodigoNegociacao(), "TUCodigoNegociacao");
        GerenciadorDeTestes::executar(new TUCPF(), "TUCPF");
        GerenciadorDeTestes::executar(new TUData(), "TUData");
        GerenciadorDeTestes::executar(new TUSenha(), "TUSenha");
    } catch (const std::string& nomeTipo) {
        std::cerr << "Erro: teste '" << nomeTipo << "' falhou. Encerrando execução." << std::endl;
        return 1;
    }

    return 0;
}

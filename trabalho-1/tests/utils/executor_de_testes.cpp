#include <iostream>

#include "executor_de_testes.hpp"

#include "../dominios/cpf_test.hpp"
#include "../dominios/nome_test.hpp"
#include "../dominios/data_test.hpp"
#include "../dominios/senha_test.hpp"
#include "../dominios/codigo_test.hpp"
#include "../dominios/perfil_test.hpp"
#include "../dominios/dominios_test.hpp"
#include "../dominios/dinheiro_test.hpp"
#include "../dominios/quantidade_test.hpp"
#include "../dominios/dominios_test.hpp"
#include "../dominios/codigo_negociacao_test.hpp"

#include "../entidades/ordem_test.hpp"
#include "../entidades/conta_test.hpp"
#include "../entidades/carteira_test.hpp"

template<typename Teste>
void ExecutorDeTestes::executarTU(Teste* teste, const std::string& nomeTipo) {
    bool sucesso = teste->run() == Teste::SUCESSO;
    std::cout << "---------- " << nomeTipo << " -> "
            << (sucesso ? COR_SUCESSO : COR_FALHA)
            << (sucesso ? "SUCESSO" : "FALHA") 
            << COR_RESET << std::endl;
    if (!sucesso) throw nomeTipo;
}

void ExecutorDeTestes::executarTodos() {
    executarTU(new TUCPF(), "TUCPF");
    executarTU(new TUData(), "TUData");
    executarTU(new TUNome(), "TUNome");
    executarTU(new TUSenha(), "TUSenha");
    executarTU(new TUPerfil(), "TUPerfil");
    executarTU(new TUCodigo(), "TUCodigo");
    executarTU(new TUDinheiro(), "TUDinheiro");
    executarTU(new TUQuantidade(), "TUQuantidade");
    executarTU(new TUCodigoNegociacao(), "TUCodigoNegociacao");

    executarTU(new TUOrdem(), "TUOrdem");
    executarTU(new TUConta(), "TUConta");
    executarTU(new TUCarteira(), "TUCarteira");
}

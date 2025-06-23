#include <memory>
#include <iostream>

#include "src/persistencia/gerenciador_bd.hpp"
#include "src/servicos/carteira/carteira_servico.hpp"
#include "src/apresentacao/carteira/carteira_controlador.hpp"
#include "src/persistencia/carteira/carteira_repositorio.hpp"

using namespace std;

void simularLogin() {
    SessaoUsuario& sessao = SessaoUsuario::getInstance();
    if (!sessao.estaLogado()) {
        try {
            // Crie uma conta de teste para que as operações possam ser realizadas
            Conta contaTeste("123.456.789-00", "Usuario Teste", "A1b2#c");
            sessao.login(contaTeste);
            cout << "Login simulado com sucesso para o CPF: " << contaTeste.getCpf() << endl;

        } catch (const invalid_argument& e) {
            cerr << "Erro ao criar conta de teste para login: " << e.what() << endl;
            throw;
        }
    }
}


int main() {
    cout << "Inicializando sistema..." << endl;

    try {
        // 1. Inicializando o banco de dados
        if (!GerenciadorBD::getInstance().inicializarBanco()) {
            cerr << "Nao foi possivel inicializar o banco de dados. Encerrando." << endl;
            return 1;
        }
        cout << "Banco de dados inicializado." << endl;

        // 2. Criando as instâncias das camadas, de baixo para cima
        // unique_ptr gerencia a memória automaticamente
        auto repoCarteira = make_unique<RepositorioIPCarteira>();
        cout << "Repositorio de Carteira criado." << endl;

        // 3. Injetando  dependências.
        auto servicoCarteira = make_unique<ServicoICarteira>(repoCarteira.get());
        cout << "Servico de Carteira criado e injetado." << endl;

        auto ctrlCarteira = make_unique<CntrlIACarteira>();
        ctrlCarteira->setCntrlISCarteira(servicoCarteira.get());
        cout << "Controlador de Carteira criado e injetado." << endl;
        
        // Simula um usuário logado para que as funcionalidades de carteira possam ser usadas
        simularLogin();

        cout << "\nSistema pronto. Iniciando menu de carteiras...\n" << endl;
        ctrlCarteira->executar();

    } catch (const exception& e) {
        cerr << "\nOcorreu um erro fatal nao tratado: " << e.what() << endl;
        return 1;
    }

    cout << "\nEncerrando o programa..." << endl;

    return 0;
}


#include "gerenciador.hpp"

void GerenciadorSistema::simularLogin() {
    SessaoUsuario& sessao = SessaoUsuario::getInstance();
    if (!sessao.estaLogado()) {
        try {
            // Crie uma conta de teste para que as operações possam ser realizadas
            Conta contaTeste("123.456.789-00", "Usuario Teste", "A1b2#c");
            sessao.login(contaTeste);
            std::cout << "Login simulado com sucesso para o CPF: " << contaTeste.getCpf() << std::endl;

        } catch (const std::invalid_argument& e) {
            std::cerr << "Erro ao criar conta de teste para login: " << e.what() << std::endl;
            throw;
        }
    }
}

void GerenciadorSistema::inicializar() {
    if (!GerenciadorBD::getInstance().inicializarBanco()) {
        throw std::runtime_error("Falha ao inicializar banco de dados.");
    };
   std::cout << "Banco de dados inicializado.\n";

    simularLogin(); // TODO: Trocar isso pela autenticação real do usuário

    inicializarCarteira();
    // inicializarConta();
};

void GerenciadorSistema::inicializarCarteira() {
    repoCarteira = std::make_unique<RepositorioIPCarteira>();
    std::cout << "Repositorio de Carteira criado.\n";

    servicoCarteira = std::make_unique<ServicoICarteira>(repoCarteira.get());
    std::cout << "Servico de Carteira criado e injetado.\n";

    ctrlCarteira =std::make_unique<CntrlIACarteira>();
    ctrlCarteira->setCntrlISCarteira(servicoCarteira.get());
    std::cout << "Controlador de Carteira criado e injetado.\n";
};

void GerenciadorSistema::executar() {
    int opcao = 0;
    do {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Carteiras\n";
        std::cout << "2. Contas\n";
        std::cout << "3. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                ctrlCarteira->executar();
                break;
            case 2:
                // ctrlConta->executar();
                break;
            case 3:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
        }
    } while (opcao != 3);
}


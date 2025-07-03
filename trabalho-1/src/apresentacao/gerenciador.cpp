#include "gerenciador.hpp"


void GerenciadorSistema::inicializar() {
    if (!GerenciadorBD::getInstance().inicializarBanco()) {
        throw std::runtime_error("Falha ao inicializar banco de dados.");
    };
   std::cout << "Banco de dados inicializado.\n";

    inicializarDadosHistoricos();
    inicializarAutenticacao();
    inicializarCarteira();
    inicializarOrdem();
};

void GerenciadorSistema::inicializarAutenticacao() {
    repoAutenticacao = std::make_unique<RepositorioIPAutenticacao>();

    servicoAutenticacao = std::make_unique<ServicoIAutenticacao>(repoAutenticacao.get());

    ctrlAutenticacao =std::make_unique<CntrlIAAutenticacao>();
    ctrlAutenticacao->setCntrlISAutenticacao(servicoAutenticacao.get());
};


void GerenciadorSistema::inicializarCarteira() {
    repoCarteira = std::make_unique<RepositorioIPCarteira>();
    // DEBUG: std::cout << "Repositorio de Carteira criado.\n";

    servicoCarteira = std::make_unique<ServicoICarteira>(repoCarteira.get());
    // DEBUG: std::cout << "Servico de Carteira criado e injetado.\n";

    ctrlCarteira =std::make_unique<CntrlIACarteira>();
    ctrlCarteira->setCntrlISCarteira(servicoCarteira.get());
    // DEBUG: std::cout << "Controlador de Carteira criado e injetado.\n";
};

void GerenciadorSistema::inicializarDadosHistoricos() {
    servicoDadosHistoricos = std::make_unique<ServicoDadosHistoricos>();
    // DEBUG: std::cout << "Serviço de Dados Históricos criado.\n";
}

void GerenciadorSistema::inicializarOrdem() {
    repoOrdem = std::make_unique<RepositorioIPOrdem>();
    // DEBUG: std::cout << "Repositorio de Ordem criado.\n";

    servicoOrdem = std::make_unique<ServicoIOrdem>(
        repoOrdem.get(),
        repoCarteira.get(),
        servicoDadosHistoricos.get()
    );
    // DEBUG: std::cout << "Servico de Ordem criado e injetado.\n";

    ctrlOrdem =std::make_unique<CntrlIAOrdem>();
    ctrlOrdem->setCntrlISOrdem(servicoOrdem.get());
    // DEBUG: std::cout << "Controlador de Ordem criado e injetado.\n";
};

void GerenciadorSistema::executar() {
    std::string usuario, senha;

    ctrlAutenticacao->executar();
    std::cout << "Autenticacao bem-sucedida.\n";

    int opcao = 0;
    do {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Carteiras\n";
        std::cout << "2. Ordens\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                ctrlCarteira->executar();
                break;
            case 2:
                ctrlOrdem->executar();
                break;
            case 0:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
        }
    } while (opcao != 3);
}



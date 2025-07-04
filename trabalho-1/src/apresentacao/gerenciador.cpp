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
    inicializarConta();
};

void GerenciadorSistema::inicializarAutenticacao() {
    repoAutenticacao = std::make_unique<RepositorioIPAutenticacao>();

    servicoAutenticacao = std::make_unique<ServicoIAutenticacao>(repoAutenticacao.get());

    ctrlAutenticacao =std::make_unique<CntrlIAAutenticacao>();
    ctrlAutenticacao->setCntrlISAutenticacao(servicoAutenticacao.get());
};


void GerenciadorSistema::inicializarCarteira() {
    repoCarteira = std::make_unique<RepositorioIPCarteira>();

    servicoCarteira = std::make_unique<ServicoICarteira>(repoCarteira.get());

    ctrlCarteira =std::make_unique<CntrlIACarteira>();
    ctrlCarteira->setCntrlISCarteira(servicoCarteira.get());
};

void GerenciadorSistema::inicializarDadosHistoricos() {
    servicoDadosHistoricos = std::make_unique<ServicoDadosHistoricos>();
}

void GerenciadorSistema::inicializarOrdem() {
    repoOrdem = std::make_unique<RepositorioIPOrdem>();

    servicoOrdem = std::make_unique<ServicoIOrdem>(
        repoOrdem.get(),
        repoCarteira.get(),
        servicoDadosHistoricos.get()
    );

    ctrlOrdem =std::make_unique<CntrlIAOrdem>();
    ctrlOrdem->setCntrlISOrdem(servicoOrdem.get());
};

void GerenciadorSistema::inicializarConta() {
    repoConta = std::make_unique<RepositorioIPConta>();

    servicoConta = std::make_unique<ServicoIConta>(repoConta.get());

    ctrlConta =std::make_unique<CntrlIAConta>();
    ctrlConta->setCntrlISConta(servicoConta.get());
};

void GerenciadorSistema::executar() {
    if (!ctrlAutenticacao->executar()) {
        return;
    }

    int opcao = 0;
    do {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Carteiras\n";
        std::cout << "2. Ordens\n";
        std::cout << "3. Conta\n";
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
            case 3:
                try {
                    ctrlConta->executar();
                } catch (const ContaExcluida& e) {
                    std::cout << "\n" << e.what() << "\n";
                    ctrlAutenticacao->executar(); 
                }
                break;
            case 0:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
        }

    } while (opcao != 0);
}




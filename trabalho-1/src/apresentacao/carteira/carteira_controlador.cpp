#include "carteira_controlador.hpp"

void CntrlIACarteira::mostrarOpcoes() {
    std::cout << "----------- Menu de Carteiras -----------\n";
    std::cout << "Selecione uma opção: \n";

    std::cout << CRIAR_CARTEIRA << ". Criar nova carteira de investimentos\n";
    std::cout << LER_CARTEIRA << ". Ler uma carteira de investimentos\n";
    std::cout << EDITAR_CARTEIRA << ". Editar uma carteira de investimentos\n";
    std::cout << EXCLUIR_CARTEIRA << ". Excluir uma carteira de investimentos\n";
    std::cout << LISTAR_CARTEIRAS << ". Listar carteiras de investimentos\n";

    std::cout << VOLTAR << ". Voltar ao menu principal\n";
    std::cout << "-------------------------------------------\n";
    std::cout << "Sua escolha: ";
}

bool CntrlIACarteira::escolherOpcao(int entrada) {
    switch (entrada) {
        case CRIAR_CARTEIRA:
            criarCarteira();
            break;

        case LER_CARTEIRA:
            lerCarteira();
            // cntrlISInvestimento->lerCarteira(cpf);
            break;
        
        case EDITAR_CARTEIRA:
            editarCarteira();
            // cntrlISInvestimento->editarCarteira(cpf);
            break;

        case EXCLUIR_CARTEIRA:
            excluirCarteira();
            // cntrlISInvestimento->excluirCarteira(cpf);
            break;

        case LISTAR_CARTEIRAS:
            listarCarteiras();
            break;

        case VOLTAR: 
            std::cout << "Voltando ao menu principal..." << std::endl;
            return false;

        default:
            std::cout << "Opção inválida. Tente novamente." << std::endl;
            break;
    }

    return true;
}

void CntrlIACarteira::executar() {
    int entrada;

    while (true) {
        CLR_SCR();
        mostrarOpcoes(); 

        std::cin >> entrada;

        if (std::cin.fail()) {
            std::cout << "Erro: Entrada inválida. Por favor, digite um número!\n";
            std::cin.clear();   // Limpa o estado de erro do cin.

            // Remove entradas indesejadas do buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Pressione Enter para continuar...\n";
            std::cin.get();
            continue; 
        }

        if (!escolherOpcao(entrada))
            break;  // Sai do menu caso tenha escolhido VOLTAR

        // Pausa para o usuário poder ler a saída antes de limpar a tela novamente.
        std::cout << "\nPressione Enter para continuar...\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     // Limpa buffer 
        std::cin.get();
    }
}

void CntrlIACarteira::criarCarteira() {
    std::string nome_inpt;
    std::string perfil_inpt;

    std::cout << "----------- Criar uma Carteira de Investimento -----------\n";
    std::cout << "Informe o nome da carteira: ";
    std::cin >> nome_inpt;

    std::cout << "Perfis de Investidor: Conservador, Moderado, Agressivo\n";
    std::cout << "Informe o seu perfil de investidor: ";
    std::cin >> perfil_inpt;

    try {
        Nome nome;
        nome.set(nome_inpt);

        Perfil perfil;
        perfil.set(perfil_inpt);

        servicoCarteira->criarCarteira(nome, perfil);
    
    } catch (const std::invalid_argument &e) {
        std::cout << "\nErro de validação: " << e.what() << std::endl;
        std::cout << "Por favor, tente novamente com dados válidos." << std::endl;
    }
}

void CntrlIACarteira::lerCarteira() {
    // TODO
}

void CntrlIACarteira::editarCarteira() {
    // TODO
}

void CntrlIACarteira::excluirCarteira() {
    std::string codigo_inpt;
    Codigo codigo;

    CntrlIACarteira::listarCarteiras();

    std::cout << "Informe o código da carteira a ser excluida (ou 0 para voltar): ";
    std::cin >> codigo_inpt;

    if (codigo_inpt == "0") {
        std::cout << "Voltando para o menu de carteiras.\n";
        return;
    }

    try {
        codigo.set(codigo_inpt);

        char confirmacao;
        std::cout << "Você tem certeza que deseja excluir a carteira de código " 
                  << codigo.get() << "? (S/N): ";
        std::cin >> confirmacao;

        if (toupper(confirmacao) == 'S') {
            servicoCarteira->excluirCarteira(codigo.get());
            std::cout << "Sua carteira foi excluída com sucesso.\n";
        } else {
            std::cout << "Exclusão cancelada pelo usuário.\n";
        }
        
    } catch(const std::exception& e) {
        std::cerr << "Ocorreu um erro ao excluir a carteira: " << e.what() << '\n';
    }
}

void CntrlIACarteira::listarCarteiras() {
    std::vector<Carteira> carteiras;

    try {
        carteiras = servicoCarteira->listarCarteiras();

        std::cout << "\n----------- Suas Carteiras de Investimento -----------\n";
        
        if (carteiras.empty()) {
            std::cout << "Você ainda não possui carteiras cadastradas.\n";
        } else {
            for(const auto& carteira : carteiras) {
                std::cout << "Código: " << carteira.getCodigo() 
                          << ", Nome: " << carteira.getNome() 
                          << ", Perfil: " << carteira.getPerfil() << "\n";
            }
        }

        std::cout << "-----------------------------------------------------\n";

    } catch (const std::exception& e) {
        std::cerr << "Ocorreu um erro ao buscar suas carteiras: " << e.what() << '\n';
    }
}

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
            CLR_SCR();
            criarCarteira();
            break;

        case LER_CARTEIRA:
            CLR_SCR();
            lerCarteira();
            break;
        
        case EDITAR_CARTEIRA:
            CLR_SCR();
            editarCarteira();
            break;

        case EXCLUIR_CARTEIRA:
            CLR_SCR();
            excluirCarteira();
            break;

        case LISTAR_CARTEIRAS:
            CLR_SCR();
            listarCarteiras();
            break;

        case VOLTAR: 
            std::cout << "\nVoltando ao menu principal..." << std::endl;
            return false;

        default:
            std::cout << "\nOpção inválida. Tente novamente." << std::endl;
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
    std::cout << "Informe o nome da carteira (ou 0 para voltar): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer antes de ler a linha
    std::getline(std::cin, nome_inpt);

    std::cout << "Perfis de Investidor: Conservador, Moderado, Agressivo\n";
    std::cout << "Informe o seu perfil de investidor: ";
    std::cin >> perfil_inpt;

    if (nome_inpt == "0" || perfil_inpt == "0"){
        std::cout << "Voltando para o menu de carteiras.\n";
        return;
    }

    try {
        Nome nome;
        nome.set(nome_inpt);

        Perfil perfil;
        perfil.set(perfil_inpt);

        servicoCarteira->criarCarteira(nome, perfil);
    
    } catch (const std::exception &e) { 
        std::cout << "\nErro ao criar carteira: " << e.what() << std::endl;
        std::cout << "Por favor, tente novamente com dados válidos." << std::endl;
    }
}

void CntrlIACarteira::lerCarteira() {
    std::vector<CarteiraComValor> carteiras;
    try {
        carteiras = servicoCarteira->getCarteiras();
    } catch (const std::exception& e) {
        std::cerr << "Ocorreu um erro ao buscar suas carteiras: " << e.what() << '\n';
        return; 
    }

    std::cout << "\n----------- Suas Carteiras de Investimento -----------\n";
    if (carteiras.empty()) {
        std::cout << "Você ainda não possui carteiras cadastradas.\n";
        std::cout << "-----------------------------------------------------\n";
        return;
    } else {
        int id = 1;
        for(const auto& carteira : carteiras) {
            std::cout << id++ << ". Nome: " << carteira.carteira.getNome() << " (Código: " << carteira.carteira.getCodigo() << ")\n";
        }
    }
    std::cout << "-----------------------------------------------------\n";

    int num_carteira;
    std::cout << "Informe o número da carteira que deseja ver (ou 0 para voltar): ";
    std::cin >> num_carteira;

    if (num_carteira == 0) {
        std::cout << "Voltando para o menu de carteiras.\n";
        return;
    }   

    try {
        if (num_carteira < 1 || num_carteira > carteiras.size()) {
            throw std::invalid_argument("Número de carteira inválido.");
        }

        const CarteiraComValor& carteiraEscolhida = carteiras[num_carteira - 1];      

        std::cout << "\n------ Detalhes da Carteira '" << carteiraEscolhida.carteira.getNome() << "' ------\n";
        std::cout << "Código de Identificação: " << carteiraEscolhida.carteira.getCodigo() << "\n";
        std::cout << "Perfil da Carteira: " << carteiraEscolhida.carteira.getPerfil() << "\n";
        std::cout << "Valor Total: R$ " << std::fixed << std::setprecision(2) << carteiraEscolhida.valorTotal << "\n";
        std::cout << "-----------------------------------------------------\n";

    } catch (const std::exception& e) {
        std::cerr << "Ocorreu um erro ao ler a carteira: " << e.what() << "\n";
    }
}

void CntrlIACarteira::editarCarteira() {
    std::vector<CarteiraComValor> carteiras;
    try {
        carteiras = servicoCarteira->getCarteiras();

        if (carteiras.empty()) {
            std::cout << "Você não possui carteiras para editar.\n";
            return;
        }
        listarCarteiras();

    } catch (const std::exception& e) {
        std::cerr << "Ocorreu um erro ao buscar suas carteiras: " << e.what() << '\n';
        return;
    }

    std::string codigo_inpt;
    std::cout << "Informe o código da carteira a ser editada (ou 0 para voltar): ";
    std::cin >> codigo_inpt;

    if (codigo_inpt == "0") return;

    try {
        Codigo codigo_valido;
        codigo_valido.set(codigo_inpt);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Formato de código inválido: " << e.what() << '\n';
        return;
    }

    int escolha = -1;
    while (escolha != 0) {
        std::cout << "\n--- Editando Carteira: " << codigo_inpt << " ---\n";
        std::cout << "1. Editar Nome\n";
        std::cout << "2. Editar Perfil\n";
        std::cout << "0. Voltar ao menu de carteiras\n";
        std::cout << "Sua escolha: ";
        std::cin >> escolha;

        try {
            switch (escolha) {
                case 1: { // Editar Nome
                    CLR_SCR();
                    std::string novo_nome_inpt;
                    std::cout << "Digite o novo nome para a carteira: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, novo_nome_inpt);

                    Nome nome_valido;
                    nome_valido.set(novo_nome_inpt);

                    servicoCarteira->editarNomeCarteira(codigo_inpt, nome_valido);
                    std::cout << "Nome da carteira atualizado com sucesso!\n";
                    break;
                }

                case 2: { // Editar Perfil
                    CLR_SCR();
                    std::string novo_perfil_inpt;
                    std::cout << "Perfis: Conservador, Moderado, Agressivo\n";
                    std::cout << "Digite o novo perfil da carteira: ";
                    std::cin >> novo_perfil_inpt;

                    Perfil perfil_valido;
                    perfil_valido.set(novo_perfil_inpt);

                    servicoCarteira->editarPerfilCarteira(codigo_inpt, perfil_valido);
                    std::cout << "Perfil da carteira atualizado com sucesso!\n";
                    break;
                }

                case 0:
                    std::cout << "Voltando...\n";
                    break;

                default:
                    std::cout << "Opção inválida. Tente novamente.\n";
                    break;
            }

        } catch (const std::exception& e) {
            std::cerr << "Ocorreu um erro ao editar a carteira: " << e.what() << '\n';

            std::cout << "Pressione Enter para continuar...";
            std::cin.get();
        }
    }
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
    int id = 1;
    std::vector<CarteiraComValor> carteiras;

    try {
        carteiras = servicoCarteira->getCarteiras();

        std::cout << "\n----------- Suas Carteiras de Investimento -----------\n";
        
        if (carteiras.empty()) {
            std::cout << "Você ainda não possui carteiras cadastradas.\n";
        } else {
            for(const auto& item : carteiras) {
                std::cout << id << ". Nome: " << item.carteira.getNome() 
                          << ", Código: " << item.carteira.getCodigo() 
                          << ", Perfil: " << item.carteira.getPerfil() 
                          << ", Valor Total: R$ " << item.valorTotal << "\n";
                ++id;
            }
        }

        std::cout << "-----------------------------------------------------\n";

    } catch (const std::exception& e) {
        std::cerr << "Ocorreu um erro ao buscar suas carteiras: " << e.what() << '\n';
    }
}

void CntrlIACarteira::excluirCarteirasUsuario() {
    std::cout << "Excluindo suas carteiras...\n";

    try {
        servicoCarteira->excluirCarteirasUsuario();
        std::cout << "Todas as suas carteiras foram excluídas com sucesso.\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro ao excluir carteiras: " << e.what() << '\n';
    }
}


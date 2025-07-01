#include "ordem_controlador.hpp"

void CntrlIAOrdem::mostrarOpcoes() {
    std::cout << "----------- Menu de Ordens da Carteira " << this->codigoCarteira.get() << " -----------\n";
    std::cout << "Selecione uma opção: \n";

    std::cout << CRIAR_ORDEM << ". Criar nova ordem\n";
    std::cout << EXCLUIR_ORDEM << ". Excluir uma ordem\n";
    std::cout << LISTAR_ORDENS << ". Listar todas as ordens\n";
    std::cout << VOLTAR << ". Voltar ao menu de carteiras\n";
    std::cout << "--------------------------------------------------------\n";
    std::cout << "Sua escolha: ";
}

bool CntrlIAOrdem::escolherOpcao(int entrada) {
    switch (entrada) {
        case CRIAR_ORDEM:   
            CLR_SCR(); criarOrdem();   
            break;

        case EXCLUIR_ORDEM: 
            CLR_SCR(); excluirOrdem(); 
            break;

        case LISTAR_ORDENS: 
            CLR_SCR(); 
            listarOrdens(); 
            break;

        case VOLTAR: 
            std::cout << "\nVoltando ao menu de carteiras..." << std::endl;
            return false;

        default:
            std::cout << "\nOpção inválida. Tente novamente." << std::endl;
            break;
    }
    return true;
}

void CntrlIAOrdem::executar(const Codigo& codigoCarteira) {
    this->codigoCarteira = codigoCarteira;
    int entrada;

    while (true) {
        CLR_SCR();
        mostrarOpcoes(); 
        std::cin >> entrada;

        if (std::cin.fail()) {
            std::cout << "Erro: Entrada inválida. Por favor, digite um número!\n";
            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Pressione Enter para continuar...\n";
            std::cin.get();
            continue; 
        }

        if (!escolherOpcao(entrada))
            break;

        std::cout << "\nPressione Enter para continuar...\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
}

void CntrlIAOrdem::criarOrdem() {
    std::string cod_neg_inpt, data_inpt;
    int qtd_inpt;

    std::cout << "----------- Criar uma Nova Ordem -----------\n";
    std::cout << "Informe o código de negociação (ex: PETR4): ";
    std::cin >> cod_neg_inpt;

    std::cout << "Informe a quantidade de papéis: ";
    std::cin >> qtd_inpt;

    std::cout << "Informe a data da operação (formato AAAAMMDD): ";
    std::cin >> data_inpt;

    try {
        CodigoNegociacao codNegociacao;
        codNegociacao.set(cod_neg_inpt);
        Quantidade quantidade;
        quantidade.set(qtd_inpt);
        Data data;
        data.set(data_inpt);

        servicoOrdem->criarOrdem(codNegociacao, quantidade, data, this->codigoCarteira);
        std::cout << "\nOrdem criada com sucesso!" << std::endl;
    
    } catch (const std::exception &e) { 
        std::cout << "\nErro ao criar ordem: " << e.what() << std::endl;
    }
}

void CntrlIAOrdem::excluirOrdem() {
    listarOrdens(); 

    std::vector<Ordem> ordens;
    try {
        ordens = servicoOrdem->listarOrdens(this->codigoCarteira);
        if (ordens.empty()) return;
    } catch(...) {}

    std::string codigo_inpt;
    std::cout << "Informe o código da ordem a ser excluida (ou 0 para voltar): ";
    std::cin >> codigo_inpt;

    if (codigo_inpt == "0") return;

    try {
        Codigo codigo;
        codigo.set(codigo_inpt);

        char confirmacao;
        std::cout << "Você tem certeza que deseja excluir a ordem " << codigo.get() << "? (S/N): ";
        std::cin >> confirmacao;

        if (toupper(confirmacao) == 'S') {
            servicoOrdem->excluirOrdem(codigo, this->codigoCarteira);
            std::cout << "Ordem excluída com sucesso.\n";
        } else {
            std::cout << "Exclusão cancelada.\n";
        }
    } catch(const std::exception& e) {
        std::cerr << "Ocorreu um erro ao excluir a ordem: " << e.what() << '\n';
    }
}

void CntrlIAOrdem::listarOrdens() {
    std::vector<Ordem> ordens;

    try {
        ordens = servicoOrdem->listarOrdens(this->codigoCarteira);

        std::cout << "\n----------- Ordens da Carteira " << this->codigoCarteira.get() << " -----------\n";
        
        if (ordens.empty()) {
            std::cout << "Nenhuma ordem encontrada para esta carteira.\n";
        } else {
            int id = 1; 
            for(const auto& ordem : ordens) {
                std::cout << id << ". " 
                          << "Código: " << ordem.getCodigo()
                          << ", Ativo: " << ordem.getCodNegociacao()
                          << ", Data: " << ordem.getData()
                          << ", Qtd: " << ordem.getQuantidade()
                          << ", Preço: R$ " << std::fixed << std::setprecision(2) << ordem.getDinheiro() << "\n";
                ++id; 
            }
        }

        std::cout << "--------------------------------------------------------\n";

    } catch (const std::exception& e) {
        std::cerr << "Ocorreu um erro ao buscar as ordens: " << e.what() << '\n';
    }
}
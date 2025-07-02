#include "autenticacao_controlador.hpp"

void CntrlIAAutenticacao::mostrarOpcoes() {
    std::cout << "----------- Menu inicial -----------\n";
    std::cout << "Selecione uma opção: \n";

    std::cout << ACESSAR_CONTA << ". Insira os seus dados para acessar a sua conta\n";
    std::cout << REGISTRAR_CONTA << ". Criar uma conta caso não possua uma ainda\n";

    std::cout << SAIR << ". Sair do programa\n";
    std::cout << "-------------------------------------------\n";
    std::cout << "Sua escolha: ";
}

bool CntrlIAAutenticacao::escolherOpcao(int entrada) {
    switch (entrada) {
        case ACESSAR_CONTA:
            CLR_SCR();
            if (acessarConta()) {
                return false; // Login deu certo, sair do menu de autenticação
            }
            break;

        case REGISTRAR_CONTA:
            CLR_SCR();
            registrarConta();
            break;

        case SAIR: 
            std::cout << "\nVoltando ao menu principal..." << std::endl;
            return false;

        default:
            std::cout << "\nOpção inválida. Tente novamente." << std::endl;
            break;
    }

    return true;
}


void CntrlIAAutenticacao::executar() {
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
        std::cin.get();
    }
}

void CntrlIAAutenticacao::registrarConta() {
    std::string cpf_inpt;
    std::string nome_inpt;
    std::string senha_inpt;

    // Limpa um \n pendente de entrada anterior (ex: std::cin >> algo)
    if (std::cin.peek() == '\n') std::cin.ignore();

    while (true) {
        std::cout << "----------- Criar uma Conta -----------\n";
        try {
            std::cout << "Informe o seu CPF com pontos e traço (ou 0 para voltar): \n";
            std::getline(std::cin, cpf_inpt);

            if (cpf_inpt == "0") return;
            if (cpf_inpt.empty()) {
                std::cout << "CPF não pode ser vazio.\n";
                continue;
            }

            CPF cpf;
            cpf.set(cpf_inpt);

            std::cout << "Informe o seu nome (ou 0 para voltar): ";
            std::getline(std::cin, nome_inpt);

            if (nome_inpt == "0") return;
            if (nome_inpt.empty()) {
                std::cout << "Nome não pode ser vazio.\n";
                continue;
            }

            Nome nome;
            nome.set(nome_inpt); 

            std::cout << "Informe a sua senha (ou 0 para voltar): ";
            std::getline(std::cin, senha_inpt);

            if (senha_inpt == "0") return;
            if (senha_inpt.empty()) {
                std::cout << "Senha não pode ser vazia.\n";
                continue;
            }

            Senha senha;
            senha.set(senha_inpt);

            servicoAutenticacao->registrarConta(cpf, nome, senha);

            std::cout << "Conta criada com sucesso!\n";
            return;
            
        } catch (const std::exception& e) {
            std::cout << "\nErro ao criar conta: " << e.what() << std::endl;
            std::cout << "Por favor, tente novamente com dados válidos.\n\n";
        }
    }
}

bool CntrlIAAutenticacao::acessarConta() {
    std::string cpf_inpt;
    std::string senha_inpt;

    std::cout << "----------- Acessar a conta -----------\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Informe o seu CPF (ou 0 para voltar): ";
    std::getline(std::cin, cpf_inpt);

    std::cout << "Informe a sua senha (ou 0 para voltar): ";
    std::getline(std::cin, senha_inpt);

    if (cpf_inpt == "0" || senha_inpt == "0") {
        std::cout << "Voltando para o menu inicial.\n";
        return false;
    }

    try {
        CPF cpf;
        cpf.set(cpf_inpt);

        Senha senha;
        senha.set(senha_inpt);

        servicoAutenticacao->acessarConta(cpf, senha);

        std::cout << "Login realizado com sucesso!" << std::endl;
        return true;

    } catch (const std::exception &e) { 
        std::cout << "\nErro ao acessar conta: " << e.what() << std::endl;
        std::cout << "Por favor, tente novamente com dados válidos." << std::endl;
        return false;
    }
}


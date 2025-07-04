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
            return acessarConta();

        case REGISTRAR_CONTA:
            CLR_SCR();
            return registrarConta();

        case SAIR:
            std::exit(0);

        default:
            std::cout << "\nOpção inválida. Tente novamente.\n";
            return false;
    }
}


bool CntrlIAAutenticacao::executar() {
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

        if (escolherOpcao(entrada)) {
            std::cout << "\nPressione Enter para continuar...\n";
            std::cin.get();
            return true;
        }

        if (entrada == SAIR) {
            return false;
        }

        std::cout << "\nPressione Enter para voltar ao menu inicial\n";
        std::cin.get();
    }
}


bool CntrlIAAutenticacao::registrarConta() {
    std::string cpf_inpt, nome_inpt, senha_inpt;
    if (std::cin.peek() == '\n') std::cin.ignore();

    while (true) {
        std::cout << "----------- Criar uma Conta -----------\n";
        try {
            std::cout << "Informe o seu CPF (ou 0 para voltar): ";
            std::getline(std::cin, cpf_inpt);
            if (cpf_inpt == "0") return false;
            if (cpf_inpt.empty()) continue;

            CPF cpf;
            cpf.set(cpf_inpt);

            std::cout << "Informe o seu nome (ou 0 para voltar): ";
            std::getline(std::cin, nome_inpt);
            if (nome_inpt == "0") return false;
            if (nome_inpt.empty()) continue;

            Nome nome;
            nome.set(nome_inpt);

            std::cout << "Informe a sua senha (ou 0 para voltar): ";
            std::getline(std::cin, senha_inpt);
            if (senha_inpt == "0") return false;
            if (senha_inpt.empty()) continue;

            Senha senha;
            senha.set(senha_inpt);

            servicoAutenticacao->registrarConta(cpf, nome, senha);

            std::cout << "Conta criada com sucesso!\n";
            return true;

        } catch (const std::exception& e) {
            std::cout << "Erro: " << e.what() << "\n";
            return false;
        }
    }
}


bool CntrlIAAutenticacao::acessarConta() {
    std::string cpf_inpt, senha_inpt;

    std::cout << "----------- Acessar a conta -----------\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Informe o seu CPF (ou 0 para voltar): ";
    std::getline(std::cin, cpf_inpt);
    if (cpf_inpt == "0") return false;

    std::cout << "Informe a sua senha (ou 0 para voltar): ";
    std::getline(std::cin, senha_inpt);
    if (senha_inpt == "0") return false;

    try {
        CPF cpf;
        cpf.set(cpf_inpt);

        Senha senha;
        senha.set(senha_inpt);

        servicoAutenticacao->acessarConta(cpf, senha);

        std::cout << "Login realizado com sucesso!\n";
        return true;

    } catch (const std::exception& e) {
        std::cout << "Erro ao acessar conta: " << e.what() << "\n";
        return false;
    }
}


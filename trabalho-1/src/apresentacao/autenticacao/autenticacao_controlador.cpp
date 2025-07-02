#include "autenticacao_controlador.hpp"

void CntrlIAautenticacao::mostrarOpcoes() {
    std::cout << "----------- Menu inicial -----------\n";
    std::cout << "Selecione uma opção: \n";

    std::cout << ACESSAR_CONTA << ". Insira os seus dados para acessar a sua conta\n";
    std::cout << REGISTRAR_CONTA << ". Criar uma conta caso não possua uma ainda\n";

    std::cout << SAIR << ". Sair do programa\n";
    std::cout << "-------------------------------------------\n";
    std::cout << "Sua escolha: ";
}

bool CntrlIAautenticacao::escolherOpcao(int entrada) {
    switch (entrada) {
        case ACESSAR_CONTA:
            CLR_SCR();
            acessarConta();
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

void CntrlIAautenticacao::executar() {
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

void CntrlIAautenticacao::registrarConta() {
    std::string cpf_inpt;
    std::string nome_inpt;
    std::string senha_inpt;

    while(true) {
        std::cout << "----------- Criar uma Conta -----------\n";
        std::cout << "Informe o seu CPF (ou 0 para voltar): \n";
        std::cout << "**insira apenas numeros, sem pontos e hifens**";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer antes de ler a linha
        std::getline(std::cin, cpf_inpt);

        //funcao pra buscar o cpf no banco de dados e ver se ja existe
        //se ja existir avisar que ja existe e pedir pra dar enter pra ir pra tela de login

        std::cout << "----------- Criar uma Conta -----------\n";
        std::cout << "Informe o seu nome (ou 0 para voltar): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer antes de ler a linha
        std::getline(std::cin, nome_inpt);

        std::cout << "----------- Criar uma Conta -----------\n";
        std::cout << "Informe a sua senha (ou 0 para voltar): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer antes de ler a linha
        std::getline(std::cin, senha_inpt);


        if (cpf_inpt == "0" || nome_inpt == "0" || senha_inpt == "0"){
            std::cout << "Voltando para o menu inicial.\n";
            return;
        }

        try {
            CPF cpf;
            cpf.set(cpf_inpt);

            Nome nome;
            nome.set(nome_inpt);

            Senha senha;
            senha.set(senha_inpt);

            servicoAutenticacao->registrarConta(cpf, nome, senha);
        
        } catch (const std::exception &e) { 
            std::cout << "\nErro ao criar conta: " << e.what() << std::endl;
            std::cout << "Por favor, tente novamente com dados válidos." << std::endl;
        }
        return;
    }
}

void CntrlIAautenticacao::acessarConta() {
    std::string cpf_inpt;
    std::string senha_inpt;

    std::cout << "----------- Acessar a conta -----------\n";
    std::cout << "Informe o seu CPF (ou 0 para voltar): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer antes de ler a linha
    std::getline(std::cin, cpf_inpt);

    std::cout << "----------- Criar uma Conta -----------\n";
    std::cout << "Informe a sua senha (ou 0 para voltar): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer antes de ler a linha
    std::getline(std::cin, senha_inpt);

    if (cpf_inpt == "0" || senha_inpt == "0"){
        std::cout << "Voltando para o menu inicial.\n";
        return;
    }

    try {
        CPF cpf;
        cpf.set(cpf_inpt);

        Senha senha;
        senha.set(senha_inpt);

        servicoAutenticacao->acessarConta(cpf, senha);
    
    } catch (const std::exception &e) { 
        std::cout << "\nErro ao acessar conta: " << e.what() << std::endl;
        std::cout << "Por favor, tente novamente com dados válidos." << std::endl;
    }

}
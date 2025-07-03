#include "conta_controlador.hpp"

void CntrlIAConta::mostrarOpcoes() {
    std::cout << "----------- Menu da Conta -----------\n";
    std::cout << "Selecione uma opção: \n";

    std::cout << LER_CONTA << ". Ler uma conta de investimentos\n";
    std::cout << EDITAR_CONTA << ". Editar uma conta de investimentos\n";
    std::cout << EXCLUIR_CONTA << ". Excluir uma conta de investimentos\n";

    std::cout << VOLTAR << ". Voltar ao menu principal\n";
    std::cout << "-------------------------------------------\n";
    std::cout << "Sua escolha: ";
}

bool CntrlIAConta::escolherOpcao(int entrada) {
    switch (entrada) {
        case LER_CONTA:
            CLR_SCR();
            lerConta();
            break;
        
        case EDITAR_CONTA:
            CLR_SCR();
            editarConta();
            break;

        case EXCLUIR_CONTA:
            CLR_SCR();
            excluirConta();
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

void CntrlIAConta::executar() {
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

void CntrlIAConta::lerConta(){
    Conta conta = servicoConta->lerConta();

    std::cout << "-----------------------------------------------------\n";
    std::cout << "\n------ Detalhes da Conta  ------\n";
    std::cout << "CPF : " << conta.getCpf() << "\n";
    std::cout << "Nome : " << conta.getNome() << "\n";
    std::cout << "-----------------------------------------------------\n";
}


void CntrlIAConta::editarConta(){

int escolha = -1;
    while (escolha != 0) {
        std::cout << "\n--- Editando Conta: ---\n";
        std::cout << "1. Editar Nome\n";
        std::cout << "2. Editar Senha\n";
        std::cout << "0. Voltar ao menu de Conta\n";
        std::cout << "Sua escolha: ";
        std::cin >> escolha;

        try {
            switch (escolha) {
                case 1: { // Editar Nome
                    CLR_SCR();
                    std::string novo_nome_inpt;
                    std::cout << "Digite o novo nome para a conta: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, novo_nome_inpt);

                    Nome nome_valido;
                    nome_valido.set(novo_nome_inpt);

                    servicoConta->editarNomeConta(nome_valido);
                    std::cout << "Nome da conta atualizado com sucesso!\n";
                    break;
                }

                case 2: { // Editar senha
                    CLR_SCR();
                    std::string nova_senha_inpt;
                    std::cout << "Digite a nova senha para a conta: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, nova_senha_inpt);

                    Senha senha_valida;
                    senha_valida.set(nova_senha_inpt);

                    servicoConta->editarSenhaConta(senha_valida);
                    std::cout << "Senha da conta atualizado com sucesso!\n";
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
            std::cerr << "Ocorreu um erro ao editar a conta: " << e.what() << '\n';

            std::cout << "Pressione Enter para continuar...";
            std::cin.get();
        }
    }
}



void CntrlIAConta::excluirConta() {
    Conta conta = servicoConta->lerConta();

    try {
        char confirmacao;
        std::cout << "Você tem certeza que deseja excluir a conta do CPF: " 
                  << conta.getCpf() << "? (S/N): ";
        std::cin >> confirmacao;

        if (toupper(confirmacao) == 'S') {
            servicoConta->excluirContaLogada();
            std::cout << "Sua conta foi excluída com sucesso.\n";
        } 
        else if (toupper(confirmacao) == 'N'){
            std::cout << "Exclusão cancelada pelo usuário.\n";
        }
        else{
            std::cout << "Termo Inválido. \n";
        }
        
    } catch(const std::exception& e) {
        std::cerr << "Ocorreu um erro ao excluir a conta: " << e.what() << '\n';
    }
}
#include "CntrlIACarteira.hpp"
#include "../../dominios/dominios.hpp"
#include "../../servico/MSCarteira/MSCarteira.hpp"

void CntrlIACarteira::mostrarOpcoes() {
    std::cout << "----------- Menu de Investimentos -----------\n";
    std::cout << "Selecione uma opção: \n";

    std::cout << CRIAR_CARTEIRA << ". Criar nova carteira de investimentos\n";
    std::cout << LER_CARTEIRA << ". Ler uma carteira de investimentos\n";
    std::cout << EDITAR_CARTEIRA << ". Editar uma carteira de investimentos\n";
    std::cout << EXCLUIR_CARTEIRA << ". Excluir uma carteira de investimentos\n";
    std::cout << LISTAR_CARTEIRA << ". Listar carteiras de investimentos\n";

    std::cout << CRIAR_ORDEM << ". Criar nova ordem de investimento\n";
    std::cout << LER_ORDEM << ". Ler uma ordem de investimentos\n";
    std::cout << EXCLUIR_ORDEM << ". Excluir uma ordem de investimentos\n";
    std::cout << LISTAR_ORDEM << ". Listar ordens de investimentos\n";


    std::cout << VOLTAR << ". Voltar ao menu principal\n";
    std::cout << "-------------------------------------------\n";
    std::cout << "Sua escolha: ";
}

bool CntrlIACarteira::escolherOpcao(int entrada) {
    MSCarteira* servicoCarteira = MSCarteira::getInstancia();

    switch (entrada) {
        case CRIAR_CARTEIRA: {
            // TODO: Aqui tem que ser alterado para pegar o input do user
            std::string perfil = "Agressivo";
            std::string nome = "Carteira de Suyanne";

            servicoCarteira->criarCarteira(nome, perfil);

            break;
        } 

        case LER_CARTEIRA:
            // cntrlISInvestimento->lerCarteira(cpf);
            break;
        
        case EDITAR_CARTEIRA:
            // cntrlISInvestimento->editarCarteira(cpf);
            break;

        case EXCLUIR_CARTEIRA:
            // cntrlISInvestimento->excluirCarteira(cpf);
            break;

        case LISTAR_CARTEIRA:
            // cntrlISInvestimento->listarCarteiras(cpf);
            break;
        
        case CRIAR_ORDEM:
            // cntrlISInvestimento->criarOrdem(cpf);
            break;
        
        case LER_ORDEM:
            // cntrlISInvestimento->lerOrdem(cpf);
            break;
        
        case EXCLUIR_ORDEM:
            // cntrlISInvestimento->excluirOrdem(cpf);
            break;

        case LISTAR_ORDEM:
            // cntrlISInvestimento->listarOrdens(cpf);
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

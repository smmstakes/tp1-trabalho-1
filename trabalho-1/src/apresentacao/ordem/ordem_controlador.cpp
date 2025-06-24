#include "ordem_controlador.hpp" 
#include "../../libs/dominios/dominios.hpp"
#include "../../src/servicos/ordem/ordem_servico.hpp" // Ainda nao tem o servico de ordem

void CntrlIAOrdem::mostrarOpcoes() {
    std::cout << "----------- Menu de Ordens -----------\n";
    std::cout << "Selecione uma opção: \n";

    std::cout << CRIAR_ORDEM << ". Criar uma nova ordem de investimentos\n";
    std::cout << LER_ORDEM << ". Ler uma ordem de investimentos\n";
    std::cout << EXCLUIR_ORDEM << ". Excluir uma ordem de investimentos\n";
    std::cout << LISTAR_ORDEM << ". Listar ordens de investimentos\n";

    std::cout << VOLTAR << ". Voltar ao menu principal\n";
    std::cout << "-------------------------------------------\n";
    std::cout << "Sua escolha: ";
}

bool CntrlIAOrdem::escolherOpcao(int entrada) {
    switch (entrada) {
        case CRIAR_ORDEM:
            criarOrdem();
            break;

        case LER_ORDEM:
            lerOrdem();
            
            break;
        
        case EXCLUIR_ORDEM:
            excluirOrdem();
            
            break;

        case LISTAR_ORDEM:
            listarOrdem();
            
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

void CntrlIAOrdem::executar() {
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





#include "tu_utils.hpp"

void TUUtils::assertExcecao(std::function<void()> lambda, const std::string& nomeMetodo, const std::string& nomeClasse, int& estado) {
    try {
        lambda();
        std::cout << nomeClasse << ": " << nomeMetodo << " -> FALHA\n";
        estado = FALHA;
    } catch (std::invalid_argument&) {
        std::cout << nomeClasse << ": " << nomeMetodo << " -> SUCESSO\n";
    }
}
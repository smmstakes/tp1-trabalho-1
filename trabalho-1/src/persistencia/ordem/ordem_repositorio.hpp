#ifndef ORDEM_REPOSITORIO_HPP_INCLUDED
#define ORDEM_REPOSITORIO_HPP_INCLUDED

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>

#include "../../../libs/sqlite/sqlite3.h"
#include "../../../libs/comandoSQL/comandoSQL.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

#include "../gerenciador_bd.hpp"

#include "interface_repositorio_ordem.hpp"

class RepositorioIPOrdem : public IPOrdem {
private:
    GerenciadorBD& gerenciadorBD;

public:
    RepositorioIPOrdem();

    int contarOrdensUsuario(const std::string& cpfUsuario) override;
    std::string obterUltimoCodigoOrdemInserido() override;
    std::vector<Ordem> getOrdensPorCarteira(const std::string& codCarteira) override;

    void criarOrdem(const std::string& cod, const std::string& codNeg, const std::string& data, double preco, 
    int qtd, const std::string& codigoCarteira) override;
    bool excluirOrdem(const std::string& codOrdem, const std::string& codCarteira) override;
};

#endif  // ORDEM_REPOSITORIO_HPP_INCLUDED
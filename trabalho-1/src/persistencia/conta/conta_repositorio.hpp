#ifndef CONTA_REPOSITORIO_HPP_INCLUDED
#define CONTA_REPOSITORIO_HPP_INCLUDED

#include <string>

#include "../gerenciador_bd.hpp"
#include "interface_repositorio_conta.hpp"


class RepositorioIPConta : public IPConta {
private:
    GerenciadorBD& gerenciadorBD;
    RepositorioIPConta();    

public:
    RepositorioIPConta(const RepositorioIPConta&) = delete;
    RepositorioIPConta& operator=(const RepositorioIPConta&) = delete;

    static RepositorioIPConta& getInstancia();
    void criarConta(const std::string& cpf, const std::string& nome, const std::string& senha) override;
    std::string obterUltimoCPFContaInserido() override;
};

#endif  // CONTA_REPOSITORIO_HPP_INCLUDED
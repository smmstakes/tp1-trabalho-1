#ifndef CONTA_REPOSITORIO_HPP_INCLUDED
#define CONTA_REPOSITORIO_HPP_INCLUDED

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>

#include "../../../libs/sqlite/sqlite3.h"
#include "../../../libs/comandoSQL/comandoSQL.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

#include "../gerenciador_bd.hpp"

#include "interface_repositorio_conta.hpp"

class RepositorioIPConta : public IPConta {
private:
    GerenciadorBD& gerenciadorBD;
      
public:
    RepositorioIPConta();  
    
    bool editarNomeConta(const std::string& cpf, const std::string& nomeNome) override;
    bool editarSenhaConta(const std::string& cpf ,const std::string& novaSenha) override;
    bool excluirConta(const std::string& cpf ) override;
    std::string getConta(const std::string& cpf) override;

};

#endif  // CONTA_REPOSITORIO_HPP_INCLUDED

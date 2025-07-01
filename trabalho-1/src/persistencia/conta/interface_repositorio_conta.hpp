#ifndef INTERFACE_REPOSITORIO_CONTA_HPP_INCLUDED
#define INTERFACE_REPOSITORIO_CONTA_HPP_INCLUDED

#include <string>

#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"

class IPConta {
public:
    virtual ~IPConta() = default;

    virtual bool editarNomeConta(const std::string& cpf ,const std::string& novoNome) = 0;
    virtual bool editarSenhaConta(const std::string& cpf,const std::string& novaSenha) = 0;
    virtual bool excluirConta(const std::string& cpf) = 0;
    virtual bool getConta(const std::string& cpf)= 0 ;
};

#endif  // INTERFACE_REPOSITORIO_CONTA_HPP_INCLUDED

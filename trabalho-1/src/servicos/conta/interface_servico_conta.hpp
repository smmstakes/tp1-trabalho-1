#ifndef INTERFACE_SERVICO_CONTA_HPP_INCLUDED
#define INTERFACE_SERVICO_CONTA_HPP_INCLUDED

#include <string>

#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

class ISConta {
public:
    virtual ~ISConta() = default;
    
    virtual void editarNomeConta(Nome& novoNome) = 0;
    virtual void editarSenhaConta(Senha& novaSenha) = 0;
    virtual void excluirContaLogada() = 0;
    virtual Conta lerConta()= 0;

};

#endif // INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED
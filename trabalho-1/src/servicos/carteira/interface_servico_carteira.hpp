#ifndef INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED
#define INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED

#include <string>
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

class ISCarteira {
public:
    virtual void verificarSessao(SessaoUsuario& sessao) = 0;

    virtual void criarCarteira(const Nome& nome, const Perfil& perfil) = 0;
    virtual void excluirCarteira(const std::string& codigo) = 0;
    virtual std::vector<Carteira> listarCarteiras() = 0;
};

#endif // INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED

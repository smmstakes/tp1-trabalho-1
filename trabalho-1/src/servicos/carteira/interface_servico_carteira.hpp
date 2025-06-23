#ifndef INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED
#define INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED

#include <string>

#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

class ISCarteira {
public:
    virtual ~ISCarteira() = default;
    
    virtual void criarCarteira(const Nome& nome, const Perfil& perfil) = 0;
    virtual void editarNomeCarteira(const std::string& codigo, const Nome& novoNome) = 0;
    virtual void editarPerfilCarteira(const std::string& codigo, const Perfil& novoPerfil) = 0;
    virtual void excluirCarteira(const std::string& codigo) = 0;
    virtual std::vector<CarteiraComValor> getCarteiras() = 0;
};

#endif // INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED

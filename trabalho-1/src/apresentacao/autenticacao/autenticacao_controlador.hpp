#ifndef AUTENTICACAO_CONTROLADOR_HPP_INCLUDED
#define AUTENTICACAO_CONTROLADOR_HPP_INCLUDED

#include <ios>
#include <limits>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"
#include "../../../libs/apresentacao_utils/apresentacao_utils.hpp"

#include "../../servicos/autenticacao/autenticacao_servico.hpp"

#include "interface_apresentacao_autenticacao.hpp"

class CntrlIAautenticacao : public IAAutenticacao {
private:
    // Códigos de serviços
    const static int SAIR = 0;
    const static int ACESSAR_CONTA = 1;
    const static int REGISTRAR_CONTA = 2;
    
    ISAutenticacao *servicoAutenticacao;

    void mostrarOpcoes() override;
    bool escolherOpcao(int) override;

    void acessarConta() override;
    void registrarConta() override;

public:
    void executar() override;
    void setCntrlISAutenticacao(ISAutenticacao* servicoAutenticacao) override {
        this->servicoAutenticacao = servicoAutenticacao;
    };
};

#endif  // AUTENTICACAO_CONTROLADOR_HPP_INCLUDED

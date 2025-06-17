#ifndef CARTEIRA_SERVICO_HPP_INCLUDED
#define CARTEIRA_SERVICO_HPP_INCLUDED

#include <string>
#include <sstream>
#include <iomanip>

#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

#include "../../persistencia/carteira/carteira_repositorio.hpp"

#include "interface_servico_carteira.hpp"

class ServicoICarteira : public ISCarteira { 
private:
    IPCarteira* persistencia;
    ServicoICarteira();

public:
    ServicoICarteira(const ServicoICarteira&) = delete;
    ServicoICarteira& operator=(const ServicoICarteira&) = delete;

    static ServicoICarteira& getInstancia();
    void criarCarteira(const Nome& nome, const Perfil& perfil) override;
    std::vector<Carteira> listarCarteiras() override;
};

#endif  // CARTEIRA_SERVICO_HPP_INCLUDED

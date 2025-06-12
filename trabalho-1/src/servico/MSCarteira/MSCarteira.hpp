#ifndef MSCARTEIRA_HPP
#define MSCARTEIRA_HPP

#include "ISCarteira.hpp"
#include "../../persistencia/MPCarteira/IPCarteira.hpp"
#include "../../persistencia/MPCarteira/MPCarteira.hpp"

class MSCarteira : public ISCarteira {
private:
    static MSCarteira* instancia;
    IPCarteira* persistencia;

    MSCarteira();

public:
    static MSCarteira* getInstancia();

    void criarCarteira(std::string& nome, const std::string& perfil) override;
};

#endif


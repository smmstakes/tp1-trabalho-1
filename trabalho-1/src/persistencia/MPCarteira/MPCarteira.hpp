#include "IPCarteira.hpp"
#include "../../../libs/comandoSQL/comandoSQL.hpp"

class MPCarteira: public IPCarteira {
    private:
        ComandoSQL comandoSQL;
    public:
        void criarCarteira(const std::string& codigo, const std::string& nome, const std::string& perfil) override;
        std::string obterUltimoCodigoCarteiraInserido() override;

};

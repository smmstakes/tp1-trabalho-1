#include "ISInvestimentos.hpp"

class MSInvestimentos : public ISInvestimentos {
    public:
        void criarCarteira(const Nome& nome, const Perfil& perfil) override;
};
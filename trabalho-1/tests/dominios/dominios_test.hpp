#ifndef DOMINIO_TEST_HPP_INCLUDED
#define DOMINIO_TEST_HPP_INCLUDED

#include <string>

template<typename Dominio>
class TUDominio {
    protected:
        Dominio *valor;
        int estado;

        void setUp() {
            valor = new Dominio();
            estado = SUCESSO;
        };
        void tearDown() { delete valor ;};
        virtual void testarCenarioValido() = 0;

    public:
        const static int SUCESSO = 1;
        const static int FALHA = -1;

        virtual int run() = 0;
        virtual ~TUDominio() = default;
};

#endif // DOMINIO_TEST_HPP_INCLUDED
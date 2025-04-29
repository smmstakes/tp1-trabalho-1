#ifndef ENTIDADES_TEST_HPP_INCLUDED
#define ENTIDADES_TEST_HPP_INCLUDED

template<typename Entidade>
class TUEntidade {
    protected:
        Entidade *entidade;
        int estado;

        virtual void setUp() = 0;
        void tearDown() {delete entidade;}
        virtual void testarCenarioValido() = 0;

    public:
        const static int SUCESSO = 1;
        const static int FALHA = -1;

        virtual int run() = 0;
        virtual ~TUEntidade() = default;
};

#endif // ENTIDADES_TEST_HPP_INCLUDED

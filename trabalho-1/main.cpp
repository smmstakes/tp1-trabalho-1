#include <iostream>
#include "./tests/dominios/data_test.hpp"
#include "./tests/dominios/codigo_test.hpp"
#include "./tests/dominios/codigo_negociacao_test.hpp"
#include "./tests/dominios/cpf_test.hpp"

using namespace std;

int main() {
    TUCodigo tCodigo;
    tCodigo.run();

    TUCodigoNegociacao tCodigoNegociacao;
    tCodigoNegociacao.run();

    TUCPF tCPF;
    tCPF.run();

    TUData tData;
    tData.run();

    return 0;
}

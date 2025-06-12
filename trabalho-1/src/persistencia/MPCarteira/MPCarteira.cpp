#include "MPCarteira.hpp"

void MPCarteira::criarCarteira(const std::string& codigo, const std::string& nome, const std::string& perfil) {
    try {
        ComandoSQL comandoSQL;
        comandoSQL.setComandoSQL(
            "INSERT INTO Carteira (codigo, nome, perfil) VALUES ('" 
            + codigo + "', '" 
            + nome + "', '" 
            + perfil + "');"
        );
        comandoSQL.executar();

        std::cout << "Carteira criada com sucesso. Código: " << codigo << std::endl;
    } catch (const EErroPersistencia& e) {
        throw;
    }
}


std::string MPCarteira::obterUltimoCodigoCarteiraInserido() {
    ComandoSQL comandoSQL;
    comandoSQL.setComandoSQL("SELECT codigo FROM Carteira ORDER BY codigo DESC LIMIT 1;");
    comandoSQL.executar();

    auto resultados = comandoSQL.getResultado();

    if (resultados.empty()) {
        throw EErroPersistencia("Nenhum código encontrado na tabela Carteira.");
    }

    return resultados.front().getValorColuna();
}


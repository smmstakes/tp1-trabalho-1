#include "carteira_repositorio.hpp"

RepositorioIPCarteira::RepositorioIPCarteira() : gerenciadorBD(GerenciadorBD::getInstance()) {}

std::string RepositorioIPCarteira::obterUltimoCodigoCarteiraInserido() {
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "SELECT codigo FROM Carteira ORDER BY codigo DESC LIMIT 1;";
    
    ComandoSQL comando(db, sql);
    
    if (comando.step()) {
        return comando.getColumnString(0); // Pega o resultado da coluna 0
    }

    return "";
}

std::vector<Ordem> RepositorioIPCarteira::getOrdensCarteira(const std::string codCarteira) {
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "SELECT codigo, codNegociacao, data, preco, quantidade FROM Ordem WHERE cod_carteira = ?;";
    
    ComandoSQL comando(db, sql);
    comando.bind(1, codCarteira);

    std::vector<Ordem> ordens;

    while (comando.step()) {
        std::string codigo = comando.getColumnString(0);
        std::string codNegociacao = comando.getColumnString(1);
        std::string data = comando.getColumnString(2);
        double preco = comando.getColumnDouble(3);
        int qtd = comando.getColumnInt(4);

        Ordem ordem(codigo, codNegociacao, data, preco, qtd);

        ordens.push_back(ordem);
    }

    return ordens;
}

int RepositorioIPCarteira::contarCarteirasUsuario(const std::string& cpfUsuario) {
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "SELECT COUNT(*) AS qtd_carteiras FROM Carteira WHERE cpf_conta= ?;";

    ComandoSQL comando(db, sql);
    comando.bind(1, cpfUsuario);

    comando.execute();
    return comando.getColumnInt(0);
}

void RepositorioIPCarteira::criarCarteira(const std::string& codigo, const std::string& nome, const std::string& perfil, const std::string& cpfUsuario) {
    sqlite3* db = gerenciadorBD.getDB();
    
    // SQL com placeholders (?) para segurança
    std::string sql = "INSERT INTO Carteira (codigo, nome, perfil, cpf_conta) VALUES (?, ?, ?, ?);";
    
    // Cria, usa e destrói o comando preparado
    ComandoSQL comando(db, sql);
    
    // Vincula os parâmetros de forma segura
    comando.bind(1, codigo);
    comando.bind(2, nome);
    comando.bind(3, perfil);
    comando.bind(4, cpfUsuario);
    
    // Executa o comando
    comando.execute(); 
}

bool RepositorioIPCarteira::editarNomeCarteira(const std::string& codigo, const std::string& cpfUsuario, const std::string& novoNome) {
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "UPDATE Carteira SET nome = ? WHERE codigo = ? AND cpf_conta = ?;";

    ComandoSQL comando(db, sql);
    comando.bind(1, novoNome);
    comando.bind(2, codigo);
    comando.bind(3, cpfUsuario);

    comando.execute();

    // Retorna true se uma linha foi afetada, indicando que a edição ocorreu.
    return sqlite3_changes(db) > 0;
}


bool RepositorioIPCarteira::editarPerfilCarteira(const std::string& codigo, const std::string& cpfUsuario, const std::string& novoPerfil) {
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "UPDATE Carteira SET perfil = ? WHERE codigo = ? AND cpf_conta = ?;";

    ComandoSQL comando(db, sql);
    comando.bind(1, novoPerfil);
    comando.bind(2, codigo);
    comando.bind(3, cpfUsuario);

    comando.execute();

    return sqlite3_changes(db) > 0;
}

bool RepositorioIPCarteira::excluirCarteira(const std::string& codigo, const std::string& cpfUsuario) {
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "DELETE FROM Carteira WHERE codigo = ? AND cpf_conta = ?;";

    ComandoSQL comando(db, sql);
    comando.bind(1, codigo);
    comando.bind(2, cpfUsuario);
    
    comando.execute();

    return sqlite3_changes(db) > 0;
}

std::vector<CarteiraComValor> RepositorioIPCarteira::getCarteiras(const std::string& cpf) {
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "SELECT c.codigo, c.nome, c.perfil, COALESCE(SUM(o.preco * o.quantidade), 0.0) as valor_total FROM Carteira c LEFT JOIN Ordem o ON c.codigo = o.cod_carteira WHERE c.cpf_conta = ? GROUP BY c.codigo, c.nome, c.perfil;";

    ComandoSQL comando(db, sql);
    comando.bind(1, cpf);

    std::vector<CarteiraComValor> carteiras;

    while (comando.step()) {
        std::string codigo = comando.getColumnString(0);
        std::string nome = comando.getColumnString(1);
        std::string perfil = comando.getColumnString(2);
        double valorTotal = comando.getColumnDouble(3);

        Carteira carteira(codigo, nome, perfil);

        CarteiraComValor item = {carteira, valorTotal};

        carteiras.push_back(item);
    }

    return carteiras;
}

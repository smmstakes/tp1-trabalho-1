#include "conta_repositorio.hpp"

RepositorioIPConta::RepositorioIPConta() : gerenciadorBD(GerenciadorBD::getInstance()) {}

// Nao sei se precisa dessa funcao...
std::string RepositorioIPConta::getConta(const std::string& cpfUsuario) {
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "SELECT cpf FROM Conta WHERE cpf = ?;";
    
    ComandoSQL comando(db, sql);
    comando.bind(1, cpfUsuario);

    if (comando.step()) {
        return comando.getColumnString(0); // Pega o resultado da coluna 0
    }

    return "";
}

bool RepositorioIPConta::editarNomeConta(const std::string& cpfUsuario ,const std::string& novoNome) {
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "UPDATE Conta SET nome = ? WHERE cpf= ? ;";

    ComandoSQL comando(db, sql);
    comando.bind(1, novoNome);
    comando.bind(2, cpfUsuario);

    comando.execute();

    // Retorna true se uma linha foi afetada, indicando que a edição ocorreu.
    return sqlite3_changes(db) > 0;
}

bool RepositorioIPConta::editarSenhaConta(const std::string& cpfUsuario, const std::string& novaSenha){
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "UPDATE Conta SET senha = ? WHERE cpf= ? ;";

    ComandoSQL comando(db, sql);
    comando.bind(1, novaSenha);
    comando.bind(2, cpfUsuario);

    comando.execute();

    // Retorna true se uma linha foi afetada, indicando que a edição ocorreu.
    return sqlite3_changes(db) > 0;
}

bool RepositorioIPConta::excluirConta(const std::string& cpfUsuario ){
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "DELETE FROM Conta WHERE cpf = ? ;";

    ComandoSQL comando(db, sql);
    comando.bind(1, cpfUsuario);
    
    comando.execute();

    return sqlite3_changes(db) > 0;
}
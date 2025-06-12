#include "comandoSQL.hpp"

list<ElementoResultado> ComandoSQL::listaResultado;

void ElementoResultado::setNomeColuna(const string& nomeColuna) {
        this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna){
        this->valorColuna = valorColuna;
}

string ElementoResultado::getNomeColuna() const {
    return nomeColuna;
}

string ElementoResultado::getValorColuna() const {
    return valorColuna;
}


void ComandoSQL::conectar() {
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ComandoSQL::desconectar() {
      rc =  sqlite3_close(bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na desconexao ao banco de dados");
}

void ComandoSQL::executar() {
        conectar();
        rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
        if(rc != SQLITE_OK){
                sqlite3_free(mensagem);
                desconectar();
                throw EErroPersistencia("Erro na execucao do comando SQL");
        }
        desconectar();
}

void ComandoSQL::inicializarBanco() {
    const char* sqls[] = {
        "CREATE TABLE IF NOT EXISTS Conta (cpf TEXT PRIMARY KEY, nome TEXT NOT NULL, senha TEXT NOT NULL);",
        "CREATE TABLE IF NOT EXISTS Carteira (codigo TEXT PRIMARY KEY, nome TEXT NOT NULL, perfil TEXT NOT NULL);",
        "CREATE TABLE IF NOT EXISTS Ordem (codigo TEXT PRIMARY KEY, codNegociacao TEXT, data TEXT, preco REAL, quantidade INTEGER);"
    };

    conectar();
    for (auto& sql : sqls) {
        rc = sqlite3_exec(bd, sql, nullptr, nullptr, &mensagem);
        if (rc != SQLITE_OK) {
            sqlite3_free(mensagem);
            desconectar();
            throw EErroPersistencia("Erro ao criar tabela no banco de dados");
        }
    }
    desconectar();
};


int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
      NotUsed=0;
      ElementoResultado elemento;
      int i;
      for(i=0; i<argc; i++){
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
      }
      return 0;
}

void ComandoSQL::setComandoSQL(const string& comando) {
    this->comandoSQL = comando;
}

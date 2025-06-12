#ifndef COMANDOSQL_HPP
#define COMANDOSQL_HPP

#include <list>

#include <iostream>
#include <string>
#include <stdio.h>

#include "sqlite3.h"      

using namespace std;

class EErroPersistencia {
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what();
};

class ElementoResultado {
        private:
                string nomeColuna;
                string valorColuna;
        public:
                void setNomeColuna(const string&);
                string getNomeColuna() const;
                void setValorColuna(const string&);
                string getValorColuna() const;
};

class ComandoSQL {
private:
        const char *nomeBancoDados;
        sqlite3 *bd;
        char *mensagem;
        int rc;
        void conectar();
        void desconectar();
        static int callback(void *, int, char **, char **);

protected:
        static list<ElementoResultado> listaResultado;
        string comandoSQL;
public:
        ComandoSQL() {
            nomeBancoDados = "../../db/sistema.db";
        }
        void setComandoSQL(const string& comando);
        void executar();
        list<ElementoResultado> getResultado() {
                return listaResultado;
        }

};

#endif
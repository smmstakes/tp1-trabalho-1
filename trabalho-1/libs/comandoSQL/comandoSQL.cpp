#include "comandoSQL.hpp"

ComandoSQL::ComandoSQL(sqlite3* db, const std::string& sql) : stmt_ptr(nullptr, &sqlite3_finalize) {
    sqlite3_stmt* raw_stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &raw_stmt, nullptr);
    
    if (rc != SQLITE_OK) {
        throw EErroPersistencia("Erro ao preparar comando: " + std::string(sqlite3_errmsg(db)));
    }

    stmt_ptr.reset(raw_stmt);
}

void ComandoSQL::bind(int index, int value) {
    sqlite3_bind_int(stmt_ptr.get(), index, value);
}

void ComandoSQL::bind(int index, double value) {
    sqlite3_bind_double(stmt_ptr.get(), index, value);
}

void ComandoSQL::bind(int index, const std::string& value) {
    sqlite3_bind_text(stmt_ptr.get(), index, value.c_str(), -1, SQLITE_TRANSIENT);
}

bool ComandoSQL::step() {
    int rc = sqlite3_step(stmt_ptr.get());
    if (rc == SQLITE_ROW) {
        return true; // Há uma linha de resultado
    }

    if (rc == SQLITE_DONE) {
        return false; // Execução terminada
    }

    // Se chegou aqui, houve um erro
    throw EErroPersistencia("Erro ao executar step: " + std::string(sqlite3_errmsg(sqlite3_db_handle(stmt_ptr.get()))));
}

void ComandoSQL::execute() {
    if (step()) {
        // Retornou uma linha (SELECT)
    }
     // Ação completa com sucesso (INSERT, DROP, UPDATE)
}

std::string ComandoSQL::getColumnString(int index) {
    return reinterpret_cast<const char*>(sqlite3_column_text(stmt_ptr.get(), index));
}

int ComandoSQL::getColumnInt(int index) {
    return sqlite3_column_int(stmt_ptr.get(), index);
}

double ComandoSQL::getColumnDouble(int index) {
    return sqlite3_column_double(stmt_ptr.get(), index);
}

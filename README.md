# tp1-trabalho-1

# COMPILAR
``` 
g++ main.cpp $(find ./src/ -name "*.cpp") db/sqlite/sqlite3.c -o main -lsqlite3
```

# COMO RODAR O DB
1. Ter o sqlite instalado no seu pc
2. Rode no seu terminal:
```bash
sqlite3 sistema.db
```
3. Alguns comandos uteis:
```bash
.tables        -- lista as tabelas
.schema nome_da_tabela  -- mostra o esquema de uma tabela
SELECT * FROM nome_da_tabela;  -- mostra o conteúdo da tabela
.quit -- sai do modo interativo
```


# Sistema de Aprendizado de Investimentos

Este projeto, desenvolvido para a disciplina de Técnicas de Programação 1, é um sistema de software para promover o aprendizado sobre investimentos financeiros. 
Ele permite que os usuários criem contas, gerenciem carteiras de investimento e registrem ordens de compra de papéis,
 utilizando uma arquitetura robusta em camadas e persistência de dados com SQLite.

## Autores

| Nome Completo | Matrícula |
| :------------ | :-------- |
| Gabriel Francisco de Oliveira Castro | 202066571 |
| José Artur Nordestino Aguiar de Oliveira | 180020439 |
| Matheus Duarte da Silva | 211062277 |
| Pedro Vale de Souza | 231038733 |
| Suyanne Sara Miranda Silva | 222006445 |

## Características

O sistema implementa um conjunto completo de funcionalidades para simulação de uma plataforma de investimentos:

- **Autenticação de Usuário**
    - Criação de conta de usuário
    - Autenticação segura via CPF e senha
- **Gerenciamento de Conta**
    - Leitura dos dados da conta (CPF, nome) e do saldo total
    - Edição dos dados da conta (nome, senha)
    - Exclusão da conta de usuário
- **Gerenciamento de Carteiras**
    - Criação de múltiplas carteiras de investimento por usuário
    - Leitura dos dados da carteira (código, nome, perfil) e do seu saldo individual
    - Edição dos dados da carteira
    - Exclusão de carteiras
    - Listagem de todas as carteiras associadas à conta do usuário
- **Gerenciamento de Ordens**
    - Criação de ordens de compra, com preço calculado com base em dados históricos
    - Leitura dos detalhes de uma ordem (código, papel, data, preço, quantidade)
    - Exclusão de ordens
    - Listagem de todas as ordens associadas a uma carteira específica

## Arquitetura

O software foi construído seguindo um estilo de **arquitetura em camadas**, visando alta coesão, baixo acoplamento e manutenibilidade.
- **Camada de Apresentação:** Responsável por toda a interação com o usuário (via console `cin`/`cout`) e pela validação sintática dos dados de entrada.
- **Camada de Serviço:** Contém toda a lógica de negócio do sistema. Ela orquestra as operações, aplica as regras (como o cálculo de saldos) e se comunica com a camada de persistência.
- **Módulos de Persistência:** Responsáveis por armazenar e recuperar os dados de Contas, Carteiras e Ordens em um banco de dados **SQLite**.
- **Interfaces e Domínios:** A comunicação entre os módulos é feita por meio de interfaces (classes abstratas com métodos virtuais puros), garantindo o desacoplamento. Classes de Domínio asseguram a integridade dos dados, validando formatos de CPF, senhas, códigos, etc..

> **OBS:** O diagrama de módulos e as suas especificações estão disponíveis em `diagrama/`.

## Tecnologias e Dependências

  * **Linguagem:** C++ (padrão C++17)
  * **Banco de Dados:** SQLite 3
  * **Compatibilidade:** O projeto é compatível com o ambiente de desenvolvimento **Code::Blocks**

Para compilar e executar o projeto, você precisará ter o `g++`, `gcc` e as bibliotecas de desenvolvimento do `sqlite3` instaladas no seu sistema.

## Compilação e Execução

A maneira mais robusta e recomendada de compilar este projeto é usando o próprio projeto `Code Blocks` fornecido,
porém se não for possível utilizar o mesmo a sua compilação pelo método manual.

> **OBS:** Ao utilizar o `Code::Blocks`, certifique-se de que em `Project -> Build Options -> Linker Settings -> Other linker options` tenha a seguinte *flag*: `-sqlite3`.

### Método Manual (via g++)

Se preferir compilar manualmente, os comandos abaixo podem ser usados, deve ser executado na pasta `trabalho-1`.

```bash
# Compilação do programa principal
g++ main.cpp \
    $(find ./src -name "*.cpp") \
    $(find ./libs -name "*.cpp") \
    -I./src \
    -I./libs \
    -o main \
    -lsqlite3 -lpthread -ldl

# Compilação dos testes
g++ $(find ./tests -name "*.cpp") \
    $(find ./src -name "*.cpp") \
    $(find ./libs -name "*.cpp") \
    -I./tests \
    -I./src \
    -I./libs \
    -o tests \
    -lsqlite3 -lpthread -ldl
```

### Como Executar o Programa

Após a compilação, o executável estará na pasta `trabalho-1`. Para rodar:

```bash
# Para compilação manual
./main

# Para compilação via Code::Blocks
./bin/Debug/trabalho-1
```

## Interagindo com o Banco de Dados

O projeto utiliza um banco de dados SQLite chamado `sistema_de_investimentos.db`. Você pode inspecioná-lo diretamente pelo terminal.

1.  **Pré-requisito:** Ter o cliente de linha de comando do SQLite instalado.
2.  **Abra o banco de dados:**
    ```sql
    sqlite3 sistema_de_investimentos.db
    ```
3.  **Comandos Úteis:**
    ```sql
    -- Lista todas as tabelas no banco de dados
    .tables

    -- Mostra o esquema de criação de uma tabela específica
    .schema Conta

    -- Seleciona e exibe todos os registros de uma tabela
    SELECT * FROM Carteira;

    -- Sai do cliente SQLite
    .quit
    ```

##### Palavras-chave
- C++
- SQLite
- Arquitetura em Camadas
- Universidade de Brasília (UnB)
- Técnicas de Programação 1 (TP1)

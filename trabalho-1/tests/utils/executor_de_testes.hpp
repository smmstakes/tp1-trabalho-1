#ifndef EXECUTOR_DE_TESTES_HPP_INCLUDED
#define EXECUTOR_DE_TESTES_HPP_INCLUDED


class ExecutorDeTestes {
    private:
        static constexpr const char* COR_SUCESSO = "\033[32m";
        static constexpr const char* COR_FALHA   = "\033[31m";
        static constexpr const char* COR_RESET   = "\033[0m";

        template<typename Teste>
        static void executarTU(Teste* teste, const std::string& nomeTipo);

    public:
        static void executarTodos();
};
#endif // EXECUTOR_DE_TESTES_HPP_INCLUDED
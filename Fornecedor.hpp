#ifndef FORNECEDOR_HPP
#define FORNECEDOR_HPP

#include <string>
#include <vector>
#include "utils.hpp"
#include <algorithm>
class Fornecedor {
public:
    struct Info {
        std::string nome;
        std::string produto;
        std::string endereco;
        std::string telefone;
    };

    Fornecedor();
    void cadastrarFornecedor(const std::string& nome, const std::string& produto, const std::string& endereco, const std::string& telefone);
    void editarFornecedorPorIndice(int indice);
    void excluirFornecedor(const std::string& nome);
    void exibirFornecedores() const;

private:
    std::vector<Info> fornecedores;
};

#endif // FORNECEDOR_HPP

#ifndef CARDAPIO_HPP
#define CARDAPIO_HPP

#include <vector>
#include <string>
#include "utils.hpp"

class Cardapio {
public:
    struct Item {
        std::string nome;
        std::string descricao;
        double preco;
    };

    Cardapio();
    void adicionarItem(const std::string& nome, const std::string& descricao, double preco);
    void removerItem(const std::string& nome);
    void editarPrecoItem(const std::string& nome, double novoPreco);
    void exibirCardapio() const;
    const std::vector<Item>& getItens() const;

private:
    std::vector<Item> itens;
};

#endif // CARDAPIO_HPP

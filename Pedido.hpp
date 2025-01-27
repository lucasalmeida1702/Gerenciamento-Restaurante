#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <string>
#include <vector>
#include "Cardapio.hpp"
#include "utils.hpp"

class Pedido {
private:
    struct ItemPedido {
        std::string nome;
        double preco;
        int quantidade;
    };

    std::string cliente;
    std::string endereco;
    std::vector<ItemPedido> itens;
    std::string status;

public:
    Pedido(const std::string& cli, const std::string& end);
    void addItem(const Cardapio::Item& item, int quantidade);
    void setEndereco(const std::string& end);
    void cancelaPedido();
    void atualizarStatus(const std::string& novoStatus);
    const std::string& getStatus() const;
    const std::string& getCliente() const;
    const std::string& getEndereco() const;
    const std::vector<ItemPedido>& getItens() const;
    void exibirResumo() const;
    void exibirDetalhes() const;
};

#endif // PEDIDO_HPP

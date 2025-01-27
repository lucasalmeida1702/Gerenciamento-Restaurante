#include "Pedido.hpp"

Pedido::Pedido(const std::string& cli, const std::string& end) : cliente(cli), endereco(end), status("Pedido feito") {}
void Pedido::addItem(const Cardapio::Item& item, int quantidade) {
    itens.push_back({ item.nome, item.preco, quantidade });
}

void Pedido::setEndereco(const std::string& end) {
    endereco = end;
}

void Pedido::cancelaPedido() {
    status = "Cancelado";
}

void Pedido::atualizarStatus(const std::string& novoStatus) {
    status = novoStatus;
}

const std::string& Pedido::getStatus() const {
    return status;
}

const std::string& Pedido::getCliente() const {
    return cliente;
}

const std::string& Pedido::getEndereco() const {
    return endereco;
}

const std::vector<Pedido::ItemPedido>& Pedido::getItens() const {
    return itens;
}

void Pedido::exibirResumo() const {
    double total = 0;
    printLine();
    std::cout << FG_CIANO << "Confirmacao do pedido:" << RESET << std::endl;
    std::cout << FG_CIANO << "Cliente: " << FG_BRANCO << cliente << RESET << std::endl;
    std::cout << FG_CIANO << "Pedido:" << RESET << std::endl;
    for (const auto& item : itens) {
        std::cout << FG_BRANCO << item.quantidade << "x " << item.nome
            << " - " << FG_VERDE << "R$" << item.preco * item.quantidade << RESET << std::endl;
        total += item.preco * item.quantidade;
    }
    std::cout << FG_CIANO << "Endereco: " << FG_BRANCO << endereco << RESET << std::endl;
    std::cout << FG_CIANO << "Total a pagar: " << FG_VERDE << "R$" << total << RESET << std::endl;
    printLine();
}

void Pedido::exibirDetalhes() const {
    std::cout << FG_CIANO << "Cliente: " << FG_BRANCO << cliente << RESET << std::endl;
    for (const auto& item : itens) {
        std::cout << FG_BRANCO << item.quantidade << "x " << item.nome << RESET << std::endl;
    }
    std::cout << FG_CIANO << "Status: " << FG_BRANCO << status << RESET << std::endl;
}

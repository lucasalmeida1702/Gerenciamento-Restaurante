#include "Cardapio.hpp"
#include <algorithm>
Cardapio::Cardapio() {}

void Cardapio::adicionarItem(const std::string& nome, const std::string& descricao, double preco) {
    itens.push_back({ nome, descricao, preco });
}

void Cardapio::removerItem(const std::string& nome) {
    auto it = std::remove_if(itens.begin(), itens.end(), [&](const Item& item) { return item.nome == nome; });

    if (it != itens.end()) {
        itens.erase(it, itens.end());
        std::cout << FG_VERDE << "Item removido com sucesso." << RESET << std::endl;
    }
    else {
        std::cout << FG_VERMELHO << "Item nao encontrado." << RESET << std::endl;
    }
}

void Cardapio::editarPrecoItem(const std::string& nome, double novoPreco) {
    for (auto& item : itens) {
        if (item.nome == nome) {
            item.preco = novoPreco;
            std::cout << FG_VERDE << "Preco atualizado com sucesso!" << RESET << std::endl;
            return;
        }
    }
    std::cout << FG_VERMELHO << "Item nao encontrado." << RESET << std::endl;
}

void Cardapio::exibirCardapio() const {
    printLine();
    std::cout << BOLD << FG_CIANO << "             CARDAPIO" << RESET << std::endl;
    printLine();
    for (size_t i = 0; i < itens.size(); ++i) {
        std::cout << FG_BRANCO << i + 1 << ". " << RESET
            << itens[i].nome << " - "
            << itens[i].descricao << " - R$"
            << itens[i].preco << "\n";
    }
    printLine();
}

const std::vector<Cardapio::Item>& Cardapio::getItens() const {
    return itens;
}

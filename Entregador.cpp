#include "Entregador.hpp"
#include <iostream>

Entregador::Entregador(std::vector<Pedido*>* pedidosRef) : pedidos(pedidosRef) {}

void Entregador::exibirPedidosProntos() const {
    printLine();
    std::cout << BOLD << FG_CIANO << "Pedidos prontos:" << RESET << std::endl;
    int count = 1;
    for (auto& pedido : *pedidos) {
        if (pedido->getStatus() == "Pedido pronto") {
            std::cout << FG_BRANCO << count++ << ". "
                << pedido->getCliente() << ". " << pedido->getEndereco() << RESET << "\n";
        }
    }
    if (count == 1) std::cout << FG_VERMELHO << "Nenhum pedido pronto." << RESET << std::endl;
    printLine();
}

void Entregador::marcarPedidoEntregue(const std::string& nomeCliente) {
    for (auto& pedido : *pedidos) {
        if (pedido->getStatus() == "Pedido pronto" && pedido->getCliente() == nomeCliente) {
            pedido->atualizarStatus("Entregue");
            std::cout << FG_VERDE << "Pedido para " << nomeCliente << " entregue!" << RESET << std::endl;
            return;
        }
    }
    std::cout << FG_VERMELHO << "Pedido nao encontrado para o cliente " << nomeCliente << RESET << std::endl;
}

void Entregador::actions_entregador() {
    int opcao;
    do {
        printLine();
        std::cout << BOLD << FG_CIANO << "Bem vindo Entregador" << RESET << std::endl;
        std::cout << FG_BRANCO << "1. Ver pedidos prontos" << RESET << std::endl;
        std::cout << FG_BRANCO << "2. Marcar pedido como entregue" << RESET << std::endl;
        std::cout << FG_BRANCO << "3. Sair" << RESET << std::endl;
        printLine();
        opcao = validarEntradaNumerica();
        if (opcao == 1) {
            exibirPedidosProntos();
        }
        else if (opcao == 2) {
            std::cout << FG_CIANO << "Digite o nome do cliente: " << RESET;
            std::string nome;
            std::getline(std::cin, nome);
            marcarPedidoEntregue(nome);
        }
    } while (opcao != 3);
}

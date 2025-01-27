#include "Cozinheiro.hpp"
#include "Utils.hpp"

Cozinheiro::Cozinheiro(std::vector<Pedido*>* pedidosRef) : pedidos(pedidosRef) {}

void Cozinheiro::exibirPedidosPendentes() const {
    printLine();
    std::cout << BOLD << FG_CIANO << "Lista de pedidos pendentes:" << RESET << std::endl;
    int count = 1;
    for (auto& pedido : *pedidos) {
        if (pedido->getStatus() == "Pedido feito") {
            std::cout << FG_BRANCO << count++ << ". Pedido de "
                << pedido->getCliente() << " - Itens: ";
            for (const auto& item : pedido->getItens()) {
                std::cout << item.quantidade << "x " << item.nome << ", ";
            }
            std::cout << RESET << "\n";
        }
    }
    if (count == 1) std::cout << FG_VERMELHO << "Nenhum pedido pendente." << RESET << std::endl;
    printLine();
}

void Cozinheiro::marcarPedidoPreparado(int indicePedido) {
    int count = 0;
    for (auto& pedido : *pedidos) {
        if (pedido->getStatus() == "Pedido feito") {
            count++;
            if (count == indicePedido) {
                pedido->atualizarStatus("Pedido pronto");
                std::cout << FG_VERDE << "Preparado: ";
                for (const auto& item : pedido->getItens()) {
                    std::cout << item.quantidade << "x " << item.nome << ", ";
                }
                std::cout << "para " << pedido->getCliente() << RESET << std::endl;
                return;
            }
        }
    }
    std::cout << FG_VERMELHO << "Pedido nao encontrado." << RESET << std::endl;
}

void Cozinheiro::actions_cozinheiro() {
    int opcao;
    do {
        printLine();
        std::cout << BOLD << FG_CIANO << "Bem vindo Cozinheiro" << RESET << std::endl;
        std::cout << FG_BRANCO << "1. Ver pedidos pendentes" << RESET << std::endl;
        std::cout << FG_BRANCO << "2. Marcar pedido como pronto" << RESET << std::endl;
        std::cout << FG_BRANCO << "3. Sair" << RESET << std::endl;
        printLine();

        opcao = validarEntradaNumerica();

        if (opcao == 1) {
            exibirPedidosPendentes();
        }
        else if (opcao == 2) {
            std::cout << FG_CIANO << "Digite o numero do pedido que estiver pronto: " << RESET;
            int num = validarEntradaNumerica();
            marcarPedidoPreparado(num);
        }
    } while (opcao != 3);
}

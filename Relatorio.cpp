
Relatorio::Relatorio(const std::vector<Pedido*>& pedidos) : pedidos(pedidos) {}

void Relatorio::exibirItensMaisVendidos() const {
    std::unordered_map<std::string, int> contagem;
    for (const auto& pedido : pedidos) {
        for (const auto& item : pedido->getItens()) {
            contagem[item.nome] += item.quantidade;
        }
    }

    std::vector<std::pair<std::string, int>> ordenado(contagem.begin(), contagem.end());
    std::sort(ordenado.begin(), ordenado.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    printLine();
    std::cout << BOLD << FG_VERDE << "Itens mais vendidos:" << RESET << std::endl;
    for (size_t i = 0; i < ordenado.size(); ++i) {
        std::cout << i + 1 << "o " << FG_BRANCO << ordenado[i].first << " (" << ordenado[i].second << " unidades)" << RESET << std::endl;
    }
    printLine();
}

void Relatorio::exibirClientesCadastrados(const std::map<std::string, std::string>& clientes) const {
    printLine();
    std::cout << BOLD << FG_VERDE << "Clientes cadastrados:" << RESET << std::endl;
    std::cout << FG_BRANCO << "Total: " << clientes.size() << RESET << std::endl;
    for (const auto& cliente : clientes) {
        std::cout << FG_BRANCO << "- " << cliente.first << RESET << std::endl;
    }
    printLine();
}

void Relatorio::calcularLucroTotal() const {
    double total = 0;
    for (const auto& pedido : pedidos) {
        for (const auto& item : pedido->getItens()) {
            total += item.preco * item.quantidade;
        }
    }
    printLine();
    std::cout << BOLD << FG_VERDE << "Lucro total: R$" << FG_BRANCO << total << RESET << std::endl;
    printLine();
}

void Relatorio::calcularLucroPorItem() const {
    std::unordered_map<std::string, double> ganhos;
    for (const auto& pedido : pedidos) {
        for (const auto& item : pedido->getItens()) {
            ganhos[item.nome] += item.preco * item.quantidade;
        }
    }
    printLine();
    std::cout << BOLD << FG_VERDE << "Lucro com cada item:" << RESET << std::endl;
    for (const auto& par : ganhos) {
        std::cout << FG_BRANCO << par.first << ": R$" << par.second << RESET << std::endl;
    }
    printLine();
}

void Relatorio::exibirPedidosPorCliente() const {
    std::unordered_map<std::string, int> pedidosPorCliente;
    for (const auto& pedido : pedidos) {
        pedidosPorCliente[pedido->getCliente()]++;
    }
    printLine();
    std::cout << BOLD << FG_VERDE << "Quantidade de pedidos por cliente:" << RESET << std::endl;
    for (const auto& par : pedidosPorCliente) {
        std::cout << FG_BRANCO << par.first << ": " << par.second << RESET << std::endl;
    }
    printLine();
}

void Relatorio::exibirGastosPorCliente() const {
    std::unordered_map<std::string, double> gastosPorCliente;
    for (const auto& pedido : pedidos) {
        for (const auto& item : pedido->getItens()) {
            gastosPorCliente[pedido->getCliente()] += item.preco * item.quantidade;
        }
    }
    printLine();
    std::cout << BOLD << FG_VERDE << "Gastos totais por cliente:" << RESET << std::endl;
    for (const auto& par : gastosPorCliente) {
        std::cout << FG_BRANCO << par.first << ": R$" << par.second << RESET << std::endl;
    }
    printLine();
}

void Relatorio::exibirStatusPedidos() const {
    int preparados = 0, entregues = 0;
    for (const auto& pedido : pedidos) {
        if (pedido->getStatus() == "Pedido pronto") {
            preparados++;
        }
        else if (pedido->getStatus() == "Entregue") {
            entregues++;
        }
    }
    printLine();
    std::cout << BOLD << FG_VERDE << "Pedidos preparados: " << FG_BRANCO << preparados << RESET << std::endl;
    std::cout << BOLD << FG_VERDE << "Pedidos entregues: " << FG_BRANCO << entregues << RESET << std::endl;
    printLine();
}

void Relatorio::menuRelatorio(const std::map<std::string, std::string>& clientes) const {
    int opcao;
    do {
        printLine();
        std::cout << BOLD << FG_CIANO << "Menu de Relatorios:" << RESET << std::endl;
        std::cout << FG_BRANCO << "1. Ver itens mais vendidos" << RESET << std::endl;
        std::cout << FG_BRANCO << "2. Ver clientes cadastrados" << RESET << std::endl;
        std::cout << FG_BRANCO << "3. Ver lucro total" << RESET << std::endl;
        std::cout << FG_BRANCO << "4. Ver lucro por item" << RESET << std::endl;
        std::cout << FG_BRANCO << "5. Ver pedidos por cliente" << RESET << std::endl;
        std::cout << FG_BRANCO << "6. Ver gastos por cliente" << RESET << std::endl;
        std::cout << FG_BRANCO << "7. Ver status de pedidos" << RESET << std::endl;
        std::cout << FG_BRANCO << "8. Voltar" << RESET << std::endl;
        printLine();

        opcao = validarEntradaNumerica();

        switch (opcao) {
        case 1: exibirItensMaisVendidos(); break;
        case 2: exibirClientesCadastrados(clientes); break;
        case 3: calcularLucroTotal(); break;
        case 4: calcularLucroPorItem(); break;
        case 5: exibirPedidosPorCliente(); break;
        case 6: exibirGastosPorCliente(); break;
        case 7: exibirStatusPedidos(); break;
        case 8:
            std::cout << FG_VERDE << "Voltando ao menu principal..." << RESET << std::endl;
            break;
        default:
            std::cout << FG_VERMELHO << "Opcao invalida. Tente novamente." << RESET << std::endl;
            break;
        }
    } while (opcao != 8);
}

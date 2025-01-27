#include <iostream>
#include <vector>
#include "Cardapio.hpp"
#include "Pedido.hpp"
#include "DonoRestaurante.hpp"
#include "Cliente.hpp"
#include "Cozinheiro.hpp"
#include "Entregador.hpp"
#include "utils.hpp"

int main() {
    Cardapio cardapio;
    std::vector<Pedido*> listaPedidos;
    DonoRestaurante dono(&cardapio, listaPedidos);

    // Populando cardápio com alguns itens iniciais
    cardapio.adicionarItem("Pizza", "Pizza de mussarela", 40.0);
    cardapio.adicionarItem("Macarrao", "Macarrao ao sugo", 25.0);
    cardapio.adicionarItem("Feijoada", "Feijoada completa", 35.0);
    cardapio.adicionarItem("Batata frita", "Batata frita crocante", 15.0);

    int usuario;
    do {
        printLine();
        std::cout << BOLD << FG_CIANO << "QUEM E VOCE:" << RESET << std::endl;
        std::cout << BOLD << FG_CIANO << "- Digite um numero (1, 2, 3 ou 4) para selecionar" << RESET << std::endl;
        std::cout << FG_BRANCO << "1. Dono" << RESET << std::endl;
        std::cout << FG_BRANCO << "2. Cliente" << RESET << std::endl;
        std::cout << FG_BRANCO << "3. Cozinheiro" << RESET << std::endl;
        std::cout << FG_BRANCO << "4. Entregador" << RESET << std::endl;
        std::cout << " " << std::endl;
        std::cout << BOLD << FG_VERMELHO << "Para fechar o programa, digite 5" << RESET << std::endl;
        printLine();

        usuario = validarEntradaNumerica();

        if (usuario == 1) {
            dono.actions_dono(Cliente::getClientes());
        }
        else if (usuario == 2) {
            Cliente::menuInicial(&cardapio, &listaPedidos);
        }
        else if (usuario == 3) {
            Cozinheiro cozinheiro(&listaPedidos);
            cozinheiro.actions_cozinheiro();
        }
        else if (usuario == 4) {
            Entregador entregador(&listaPedidos);
            entregador.actions_entregador();
        }
        else if (usuario != 5) {
            std::cout << FG_VERMELHO << "Opcao invalida. Tente novamente." << RESET << std::endl;
        }
    } while (usuario != 5);

    // Limpeza de memória
    for (auto p : listaPedidos) {
        delete p;
    }

    return 0;
}

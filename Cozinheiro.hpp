#ifndef COZINHEIRO_HPP
#define COZINHEIRO_HPP

#include <vector>
#include "Pedido.hpp"
#include "utils.hpp"

class Cozinheiro {
private:
    std::vector<Pedido*>* pedidos;

public:
    Cozinheiro(std::vector<Pedido*>* pedidosRef);
    void exibirPedidosPendentes() const;
    void marcarPedidoPreparado(int indicePedido);
    void actions_cozinheiro();
};

#endif // COZINHEIRO_HPP

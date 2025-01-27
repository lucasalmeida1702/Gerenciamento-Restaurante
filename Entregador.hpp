#ifndef ENTREGADOR_HPP
#define ENTREGADOR_HPP

#include <vector>
#include <string>
#include "Pedido.hpp"
#include "utils.hpp"

class Entregador {
private:
    std::vector<Pedido*>* pedidos;

public:
    Entregador(std::vector<Pedido*>* pedidosRef);
    void exibirPedidosProntos() const;
    void marcarPedidoEntregue(const std::string& nomeCliente);
    void actions_entregador();
};

#endif // ENTREGADOR_HPP

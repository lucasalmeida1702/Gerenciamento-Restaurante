#ifndef RELATORIO_HPP
#define RELATORIO_HPP

#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include "Pedido.hpp"
#include "utils.hpp"
#include <algorithm>
class Relatorio {
private:
    const std::vector<Pedido*>& pedidos;

public:
    Relatorio(const std::vector<Pedido*>& pedidos);
    void exibirItensMaisVendidos() const;
    void exibirClientesCadastrados(const std::map<std::string, std::string>& clientes) const;
    void calcularLucroTotal() const;
    void calcularLucroPorItem() const;
    void exibirPedidosPorCliente() const;
    void exibirGastosPorCliente() const;
    void exibirStatusPedidos() const;
    void menuRelatorio(const std::map<std::string, std::string>& clientes) const;
};

#endif // RELATORIO_HPP

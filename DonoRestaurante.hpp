#ifndef DONORESTAURANTE_HPP
#define DONORESTAURANTE_HPP

#include <string>
#include <vector>
#include <map>
#include "Cardapio.hpp"
#include "Fornecedor.hpp"
#include "Pedido.hpp"
#include "Relatorio.hpp"
#include "utils.hpp"

class DonoRestaurante {
private:
    Cardapio* cardapio;
    Fornecedor fornecedor;
    std::vector<Pedido*>& pedidos;
    std::string senha;
    Relatorio relatorio;

    bool verificarSenha();

public:
    DonoRestaurante(Cardapio* card, std::vector<Pedido*>& pedidosRef);
    void mudarSenha();
    void actions_dono(const std::map<std::string, std::string>& clientes);
};

#endif // DONORESTAURANTE_HPP

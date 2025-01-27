#include "Cliente.hpp"
#include <iostream>
#include <limits>

std::map<std::string, std::string> Cliente::clientes;

Cliente::Cliente(Cardapio* cardapioRef, std::vector<Pedido*>* pedidosRef)
    : cardapio(cardapioRef), listaPedidos(pedidosRef) {
}

bool Cliente::autenticar(const std::string& user, const std::string& pass) {
    auto it = clientes.find(user);
    return it != clientes.end() && it->second == pass;
}

void Cliente::criarConta() {
    std::string user, pass;
    while (true) {
        std::cout << FG_CIANO << "Escolha um nome de usuario: " << RESET;
        std::getline(std::cin, user);
        if (clientes.find(user) != clientes.end()) {
            std::cout << FG_VERMELHO << "Nome de usuario indisponivel." << RESET << std::endl;
        }
        else {
            break;
        }
    }
    std::cout << FG_CIANO << "Escolha uma senha: " << RESET;
    std::getline(std::cin, pass);
    clientes[user] = pass;
    std::cout << FG_VERDE << "Conta criada com sucesso!" << RESET << std::endl;
}

bool Cliente::entrar() {
    std::string user, pass;
    std::cout << FG_CIANO << "Nome de usuario: " << RESET;
    std::getline(std::cin, user);
    std::cout << FG_CIANO << "Senha: " << RESET;
    std::getline(std::cin, pass);
    if (autenticar(user, pass)) {
        username = user;
        senha = pass;
        std::cout << FG_VERDE << "Login bem-sucedido!" << RESET << std::endl;
        return true;
    }
    else {
        std::cout << FG_VERMELHO << "Credenciais invalidas." << RESET << std::endl;
        return false;
    }
}

void Cliente::alterarSenha() {
    std::string senhaAtual, novaSenha;
    std::cout << FG_CIANO << "Digite a senha atual: " << RESET;
    std::getline(std::cin, senhaAtual);
    if (senhaAtual == senha) {
        std::cout << FG_CIANO << "Digite a nova senha: " << RESET;
        std::getline(std::cin, novaSenha);
        senha = novaSenha;
        clientes[username] = novaSenha; // Atualiza o banco de dados est�tico
        std::cout << FG_VERDE << "Senha alterada com sucesso!" << RESET << std::endl;
    }
    else {
        std::cout << FG_VERMELHO << "Senha atual incorreta." << RESET << std::endl;
    }
}

void Cliente::realizarPedido() {
    Pedido* novoPedido = new Pedido(username, "");
    std::string mais;
    do {
        cardapio->exibirCardapio();
        std::cout << FG_CIANO << "Escolha o numero do item para adicionar ao pedido: " << RESET;
        int escolha = validarEntradaNumerica();
        const auto& itens = cardapio->getItens();
        if (escolha > 0 && escolha <= (int)itens.size()) {
            std::cout << FG_BRANCO << "Voce escolheu: " << FG_CIANO << itens[escolha - 1].nome << RESET << std::endl;
            std::cout << FG_CIANO << "Quantas unidades? " << RESET;
            int quantidade = validarEntradaNumerica();
            novoPedido->addItem(itens[escolha - 1], quantidade);
        }
        else {
            std::cout << FG_VERMELHO << "Opcao invalida." << RESET << std::endl;
        }
        do {
            std::cout << FG_CIANO << "Deseja adicionar mais itens? (s/n): " << RESET;
            std::cin >> mais;
            std::cin.ignore();
            if (!validarEntradaSimNao(mais)) {
                std::cout << FG_VERMELHO << "Entrada invalida. Digite 's' para Sim ou 'n' para Nao." << RESET << std::endl;
            }
        } while (!validarEntradaSimNao(mais));
    } while (mais == "s" || mais == "S");

    std::cout << FG_CIANO << "Digite o endereco de entrega: " << RESET;
    std::string endereco;
    std::getline(std::cin, endereco);
    novoPedido->setEndereco(endereco);

    printLine();
    std::cout << FG_CIANO << "Confirmacao do pedido:" << RESET << std::endl;
    novoPedido->exibirResumo();
    printLine();

    std::string confirmar;
    do {
        std::cout << FG_CIANO << "Confirmar pedido? (s/n): " << RESET;
        std::cin >> confirmar;
        std::cin.ignore();
        if (!validarEntradaSimNao(confirmar)) {
            std::cout << FG_VERMELHO << "Entrada invalida. Digite 's' para Sim ou 'n' para Nao." << RESET << std::endl;
        }
    } while (!validarEntradaSimNao(confirmar));

    if (confirmar == "s" || confirmar == "S") {
        listaPedidos->push_back(novoPedido);
        std::cout << FG_VERDE << "Pedido realizado com sucesso!" << RESET << std::endl;
    }
    else {
        delete novoPedido;
        std::cout << FG_VERMELHO << "Pedido cancelado." << RESET << std::endl;
    }
}

void Cliente::exibirStatusPedido() {
    for (size_t i = 0; i < listaPedidos->size(); ++i) {
        const auto& pedido = (*listaPedidos)[i];
        if (pedido->getCliente() == username) {
            std::cout << FG_CIANO << "Pedido " << i + 1 << FG_BRANCO << " de " << pedido->getCliente() << RESET << std::endl;
            pedido->exibirDetalhes();
            std::cout << " " << std::endl;
        }
    }
}

void Cliente::actions_cliente() {
    int opcao;
    do {
        printLine();
        std::cout << BOLD << FG_CIANO << "USUARIO: " << username << RESET << std::endl;
        std::cout << FG_BRANCO << "1. Ver cardapio" << RESET << std::endl;
        std::cout << FG_BRANCO << "2. Realizar pedido" << RESET << std::endl;
        std::cout << FG_BRANCO << "3. Ver status do pedido" << RESET << std::endl;
        std::cout << FG_BRANCO << "4. Alterar senha" << RESET << std::endl;
        std::cout << FG_VERMELHO << "5. Sair" << RESET << std::endl;
        printLine();
        opcao = validarEntradaNumerica();
        if (opcao == 1) {
            cardapio->exibirCardapio();
        }
        else if (opcao == 2) {
            realizarPedido();
        }
        else if (opcao == 3) {
            exibirStatusPedido();
        }
        else if (opcao == 4) {
            alterarSenha();
        }
    } while (opcao != 5);
}

void Cliente::menuInicial(Cardapio* cardapio, std::vector<Pedido*>* listaPedidos) {
    int opcao;
    do {
        printLine();
        std::cout << FG_CIANO << "BEM VINDO!" << RESET << std::endl;
        std::cout << FG_CIANO << "Selecione uma opcao:" << RESET << std::endl;
        std::cout << FG_BRANCO << "1. Entrar" << RESET << std::endl;
        std::cout << FG_VERDE << "2. Criar conta" << RESET << std::endl;
        std::cout << FG_BRANCO << "3. Voltar" << RESET << std::endl;
        printLine();
        opcao = validarEntradaNumerica();
        if (opcao == 1) {
            Cliente cliente(cardapio, listaPedidos);
            if (cliente.entrar()) {
                cliente.actions_cliente();
            }
        }
        else if (opcao == 2) {
            criarConta();
        }
    } while (opcao != 3);
}

const std::map<std::string, std::string>& Cliente::getClientes() {
    return clientes;
}

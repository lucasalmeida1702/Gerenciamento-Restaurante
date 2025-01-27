#include "DonoRestaurante.hpp"
#include <iostream>

DonoRestaurante::DonoRestaurante(Cardapio* card, std::vector<Pedido*>& pedidosRef)
    : cardapio(card), pedidos(pedidosRef), senha("0000"), relatorio(pedidosRef) {
}

bool DonoRestaurante::verificarSenha() {
    std::string entrada;
    std::cout << FG_CIANO << "Digite a senha atual: " << RESET;
    std::getline(std::cin, entrada);
    return entrada == senha;
}

void DonoRestaurante::mudarSenha() {
    if (!verificarSenha()) {
        std::cout << FG_VERMELHO << "Senha incorreta." << RESET << std::endl;
        return;
    }
    std::string novaSenha;

    while(1){
    std::cout << FG_CIANO << "Digite a nova senha: " << RESET;
    std::getline(std::cin, novaSenha);
    if(validarSenha(novaSenha)){
      std::cout << FG_VERMELHO << "Senha invalida! " << RESET;  
    }
    else break;
    }

    senha = novaSenha;
    std::cout << FG_VERDE << "Senha alterada com sucesso!" << RESET << std::endl;
}

void DonoRestaurante::actions_dono(const std::map<std::string, std::string>& clientes) {
    if (!verificarSenha()) {
        std::cout << FG_VERMELHO << "Acesso negado. Senha incorreta." << RESET << std::endl;
        return;
    }

    int opcao;
    do {
        printLine();
        std::cout << BOLD << FG_CIANO << "O que deseja fazer:" << RESET << std::endl;
        std::cout << FG_BRANCO << "1. Ver lista de fornecedores" << RESET << std::endl;
        std::cout << FG_BRANCO << "2. Ver relatorio" << RESET << std::endl;
        std::cout << FG_BRANCO << "3. Editar lista de fornecedores" << RESET << std::endl;
        std::cout << FG_BRANCO << "4. Editar cardapio" << RESET << std::endl;
        std::cout << FG_BRANCO << "5. Mudar senha" << RESET << std::endl;
        std::cout << FG_BRANCO << "6. Sair" << RESET << std::endl;
        printLine();
        opcao = validarEntradaNumerica();

        if (opcao == 1) {
            fornecedor.exibirFornecedores();
        }
        else if (opcao == 2) {
            relatorio.menuRelatorio(clientes);
        }
        else if (opcao == 3) {
            int sub;
            std::cout << "\n" << BOLD << FG_CIANO << "Voce deseja:" << RESET << std::endl;
            std::cout << FG_BRANCO << "1. Cadastrar fornecedor" << RESET << std::endl;
            std::cout << FG_BRANCO << "2. Editar fornecedor" << RESET << std::endl;
            std::cout << FG_BRANCO << "3. Excluir fornecedor" << RESET << std::endl;
            std::cout << FG_BRANCO << "4. Voltar" << RESET << std::endl;
            printLine();
            sub = validarEntradaNumerica();
            if (sub == 1) {
                std::string nome, produto, endereco, telefone;
                std::cout << FG_CIANO << "Nome do fornecedor: " << RESET;
                std::getline(std::cin, nome);
                std::cout << FG_CIANO << "Produto fornecido: " << RESET;
                std::getline(std::cin, produto);
                std::cout << FG_CIANO << "Endereco: " << RESET;
                std::getline(std::cin, endereco);
                std::cout << FG_CIANO << "Telefone: " << RESET;
                std::getline(std::cin, telefone);
                fornecedor.cadastrarFornecedor(nome, produto, endereco, telefone);
            }
            else if (sub == 2) {
                int indice;
                fornecedor.exibirFornecedores();
                std::cout << FG_CIANO << "Digite o indice do fornecedor a editar: " << RESET;
                indice = validarEntradaNumerica();
                fornecedor.editarFornecedorPorIndice(indice);
            }
            else if (sub == 3) {
                std::string nome;
                std::cout << FG_CIANO << "Nome do fornecedor a excluir: " << RESET;
                std::getline(std::cin, nome);
                fornecedor.excluirFornecedor(nome);
            }
        }
        else if (opcao == 4) {
            int sub;
            cardapio->exibirCardapio();
            std::cout << "\n" << BOLD << FG_CIANO << "Voce deseja:" << RESET << std::endl;
            std::cout << FG_BRANCO << "1. Editar preco de item" << RESET << std::endl;
            std::cout << FG_BRANCO << "2. Adicionar novo item" << RESET << std::endl;
            std::cout << FG_BRANCO << "3. Remover item" << RESET << std::endl;
            std::cout << FG_BRANCO << "4. Voltar" << RESET << std::endl;
            printLine();
            sub = validarEntradaNumerica();
            if (sub == 1) {
                std::string nome;
                double novoPreco;
                std::cout << FG_CIANO << "Nome do item: " << RESET;
                std::getline(std::cin, nome);
                std::cout << FG_CIANO << "Novo preco: " << RESET;
                novoPreco = validarEntradaNumerica();
                cardapio->editarPrecoItem(nome, novoPreco);
            }
            else if (sub == 2) {
                std::string nome, descricao;
                double preco;
                std::cout << FG_CIANO << "Insira o nome do novo item: " << RESET;
                std::getline(std::cin, nome);
                std::cout << FG_CIANO << "Insira a descricao: " << RESET;
                std::getline(std::cin, descricao);
                std::cout << FG_CIANO << "Insira o preco: " << RESET;
                preco = validarEntradaNumerica();
                cardapio->adicionarItem(nome, descricao, preco);
            }
            else if (sub == 3) {
                std::string nome;
                std::cout << FG_CIANO << "Nome do item a remover: " << RESET;
                std::getline(std::cin, nome);
                cardapio->removerItem(nome);
            }
        }
        else if (opcao == 5) {
            mudarSenha();
        }
    } while (opcao != 6);
}

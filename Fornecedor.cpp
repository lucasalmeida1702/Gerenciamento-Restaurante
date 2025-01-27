#include "Fornecedor.hpp"

Fornecedor::Fornecedor() {
    fornecedores.push_back({ "Granja do Paulo", "Ovos", "Rua do Galo, Bairro California", "(13) 1313-1313" });
    fornecedores.push_back({ "Feira dos Agricultores", "Cebola", "Rua Luz, Bairro Serra", "(13) 2323-1222" });
    fornecedores.push_back({ "Vinicula R10", "Vinho", "Rua do Bruxo, Bairro Independencia", "(49) 1049-2013" });
}

void Fornecedor::cadastrarFornecedor(const std::string& nome, const std::string& produto, const std::string& endereco, const std::string& telefone) {
    fornecedores.push_back({ nome, produto, endereco, telefone });
    std::cout << FG_VERDE << "Fornecedor cadastrado." << RESET << std::endl;
}

void Fornecedor::editarFornecedorPorIndice(int indice) {
    if (indice < 1 || indice >(int)fornecedores.size()) {
        std::cout << FG_VERMELHO << "Indice invalido." << RESET << std::endl;
        return;
    }

    Info& f = fornecedores[indice - 1];
    std::string novoProduto, novoEndereco, novoTelefone;

    std::cout << FG_BRANCO << "Para manter o valor atual, digite " << FG_VERDE << "manter" << RESET << FG_BRANCO << "." << RESET << std::endl;

    std::cout << FG_CIANO << "Produto atual: " << FG_BRANCO << f.produto << RESET << std::endl;
    std::cout << FG_CIANO << "Digite o novo produto: " << RESET;
    std::getline(std::cin, novoProduto);
    if (novoProduto != "manter") f.produto = novoProduto;

    std::cout << FG_CIANO << "Endereco atual: " << FG_BRANCO << f.endereco << RESET << std::endl;
    std::cout << FG_CIANO << "Digite o novo endereco: " << RESET;
    std::getline(std::cin, novoEndereco);
    if (novoEndereco != "manter") f.endereco = novoEndereco;

    std::cout << FG_CIANO << "Telefone atual: " << FG_BRANCO << f.telefone << RESET << std::endl;
    std::cout << FG_CIANO << "Digite o novo telefone: " << RESET;
    std::getline(std::cin, novoTelefone);
    if (novoTelefone != "manter") f.telefone = novoTelefone;

    std::cout << FG_VERDE << "Fornecedor editado." << RESET << std::endl;
}

void Fornecedor::excluirFornecedor(const std::string& nome) {
    auto it = std::remove_if(fornecedores.begin(), fornecedores.end(), [&](const Info& f) { return f.nome == nome; });
    if (it != fornecedores.end()) {
        fornecedores.erase(it, fornecedores.end());
        std::cout << FG_VERDE << "Fornecedor excluido." << RESET << std::endl;
    }
    else {
        std::cout << FG_VERMELHO << "Fornecedor nao encontrado." << RESET << std::endl;
    }
}

void Fornecedor::exibirFornecedores() const {
    printLine();
    std::cout << BOLD << FG_CIANO << "Lista de fornecedores:" << RESET << std::endl;
    for (size_t i = 0; i < fornecedores.size(); ++i) {
        const auto& f = fornecedores[i];
        std::cout << FG_AZUL << i + 1 << ". Fornecedor de: " << BOLD << f.produto << RESET << std::endl;
        std::cout << FG_BRANCO << "Nome: " << f.nome << std::endl;
        std::cout << FG_BRANCO << "Produto: " << f.produto << std::endl;
        std::cout << FG_BRANCO << "Endereco: " << f.endereco << std::endl;
        std::cout << FG_BRANCO << "Telefone: " << f.telefone << RESET << std::endl;
        std::cout << " " << std::endl;
    }
}

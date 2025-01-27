#include "utils.hpp"

void printLine() {
    std::cout << FG_AZUL << "========================================" << RESET << std::endl;
}

int validarEntradaNumerica() {
    int valor;
    while (true) {
        std::cin >> valor;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << FG_VERMELHO << "Entrada invalida. Por favor, insira um numero: " << RESET;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }
    }
}

bool validarEntradaSimNao(const std::string& entrada) {
    return (entrada == "s" || entrada == "S" || entrada == "n" || entrada == "N");
}

bool validarSenha(const std::string& SenhaNova) {
    if(SenhaNova=="") return true;
    // Retorna falso se a string não for vazia e contiver apenas espaços
    else return !SenhaNova.empty() && std::all_of(SenhaNova.begin(), SenhaNova.end(), [](char c) { return std::isspace(c); });
}

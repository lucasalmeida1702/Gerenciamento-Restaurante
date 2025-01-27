#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>

// C�digos ANSI para cores e estilos
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"
#define FG_CIANO "\033[36m"
#define FG_VERDE "\033[32m"
#define FG_BRANCO "\033[37m"
#define FG_VERMELHO "\033[31m"
#define FG_AZUL "\033[34m"

// Fun��o auxiliar para imprimir linhas decorativas
void printLine();

// Fun��o auxiliar para validar entradas num�ricas
int validarEntradaNumerica();

// Fun��o auxiliar para validar entradas "Sim" ou "N�o"
bool validarEntradaSimNao(const std::string& entrada);

// Fun��o auxiliar para validar senhas nulas(Somente espaço ou apenas enter)"
bool validarSenha(const std::string& SenhaNova);
#endif // UTILS_HPP

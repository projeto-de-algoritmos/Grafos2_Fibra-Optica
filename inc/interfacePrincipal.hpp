#ifndef INTERFACEPRINCIPAL_HPP
#define INTERFACEPRINCIPAL_HPP

#include "grafo.hpp"

class InterfacePrincipal {
private:
    Grafo grafo;
    double custoFibra;
public:
    InterfacePrincipal();
    void menuPrincipal();
    void menuCidades();
    void menuAnalise();
    void cadastroCidade();
    void conectarCidades();
    void desconectarCidades();
    void menuInstalacao();
    void custoTotal();
    void custoUnico();
    bool verificaCidade(string nome);
    void alterarCusto();
};

#endif

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
    void menuInstalacao();
    void custoTotal();
};

#endif

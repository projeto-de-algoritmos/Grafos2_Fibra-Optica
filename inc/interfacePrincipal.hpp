#ifndef INTERFACEPRINCIPAL_HPP
#define INTERFACEPRINCIPAL_HPP

#include "grafo.hpp"

class InterfacePrincipal {
private:
    Grafo grafo;
public:
    void menuPrincipal();
    void menuCidades();
    void menuAnalise();
    void cadastroCidade();
    void conectarCidades();
};

#endif

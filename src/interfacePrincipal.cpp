#include "interfacePrincipal.hpp"

#include <iostream>

using namespace std;

InterfacePrincipal::InterfacePrincipal() {
    menuPrincipal();
}

void InterfacePrincipal::menuPrincipal() {
    while(true) {
        cout << "(1) Gerenciamento de cidades" << endl;
        cout << "(2) Menu de análise" << endl;
        cout << "(0) Finalizar o programa" << endl;
        int opcao;
        cin >> opcao;
        if(opcao == 1)
            menuCidades();
        else if(opcao == 2)
            menuAnalise();
        else
            return;
    }
}

void InterfacePrincipal::menuCidades() {
    while(true) {
        cout << "(1) Cadastrar cidade" << endl;
        cout << "(2) Conectar cidades" << endl;
        cout << "(3) Desconectar cidades" << endl;
        cout << "(0) Voltar" << endl;
        int opcao;
        cin >> opcao;
    }
}

void InterfacePrincipal::menuAnalise() {
    while(true) {
        cout << "(1) Calcular custo total para instalação" << endl; //MST
        cout << "(2) Calcular manutenção" << endl; //Dijkstra
        cout << "(0) Voltar" << endl;
        int opcao;
        cin >> opcao;
    }
}

#include "interfacePrincipal.hpp"

#include <iostream>

using namespace std;

string getString(string mensagem) {
    string entrada;
    cout << mensagem;
    getline(cin, entrada);
    return entrada;
}

int getInt(string mensagem) {
    int entrada;
    bool loop = true;
    while(loop) {
        cout << mensagem;
        loop = false;
        cin >> entrada; 
        if(cin.fail()) {
            cin.clear();
            cout << "Entrada inválida." << endl;
            loop = true;
        }
        cin.ignore(32767, '\n');
    }
    return entrada;
}

void InterfacePrincipal::menuPrincipal() {
    while(true) {
        cout << endl;
        cout << "(1) Gerenciamento de cidades" << endl;
        cout << "(2) Menu de análise" << endl;
        cout << "(0) Finalizar o programa" << endl;
        int opcao = getInt("");
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
        cout << endl;
        cout << "(1) Cadastrar cidade" << endl;
        cout << "(2) Conectar cidades" << endl;
        cout << "(3) Desconectar cidades" << endl;
        cout << "(4) Ver cidades" << endl;
        cout << "(0) Voltar" << endl;
        int opcao = getInt("");
        if(opcao == 1)
            cadastroCidade();
        else if(opcao == 2)
            conectarCidades();
        else if(opcao == 4)
            grafo.imprimirCidades();
        else
            return;
    }
}

void InterfacePrincipal::cadastroCidade() {
    string nome = getString("Nome da cidade: ");
    grafo.novoVertice(nome);
}

void InterfacePrincipal::conectarCidades() {
    string cidade1 = getString("Nome da cidade 1: ");
    string cidade2 = getString("Nome da cidade 2: ");
    int custo = getInt("Distância entre as cidades: ");
    grafo.conectar(cidade1, cidade2, custo);
}

void InterfacePrincipal::menuAnalise() {
    while(true) {
        cout << endl;
        cout << "(1) Calcular custo total para instalação" << endl; //MST
        cout << "(2) Calcular manutenção" << endl; //Dijkstra
        cout << "(0) Voltar" << endl;
        int opcao = getInt("");
    }
}

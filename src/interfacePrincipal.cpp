#include "interfacePrincipal.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

string getString(string mensagem) {
    string entrada;
    cout << mensagem;
    getline(cin, entrada);
    return entrada;
}

template <typename T>
T getInput(string mensagem) {
    T entrada;
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

InterfacePrincipal::InterfacePrincipal() {
    custoFibra = 500;
}

void InterfacePrincipal::menuPrincipal() {
    while(true) {
        cout << endl;
        cout << "(1) Gerenciamento de cidades" << endl;
        cout << "(2) Menu de análise" << endl;
        cout << "(0) Finalizar o programa" << endl;
        int opcao = getInput<int>("");
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
        cout << "(5) Alterar status de instalação" << endl;
        cout << "(6) Deletar todas as cidades" << endl;
        cout << "(0) Voltar" << endl;
        int opcao = getInput<int>("");
        if(opcao == 1)
            cadastroCidade();
        else if(opcao == 2)
            conectarCidades();
        else if(opcao == 3)
            desconectarCidades();
        else if(opcao == 4)
            grafo.imprimirCidades();
        else if(opcao == 5) {
            string nome = getString("Nome de cidade: ");
            if(verificaCidade(nome))
                grafo.inverterStatus(nome);
        } else if(opcao == 6) {
            grafo.reset();
            cout << "Todas as cidades foram excluídas." << endl;
        } else
            return;
    }
}

void InterfacePrincipal::cadastroCidade() {
    string nome = getString("Nome da cidade: ");
    if(!verificaCidade(nome)) {
        string resp = getString("Possui instalação? (S) sim (N) não: ");
        bool instalada; 
        resp[0] = toupper(resp[0]);
        if(resp[0] == 'S')
            instalada = true;
        else
            instalada = false; 
        
        grafo.novoVertice(nome,instalada);
    }
    else
        cout << "Cidade já cadastrada" << endl;
}

bool InterfacePrincipal::verificaCidade(string nome){
    int existe = grafo.buscarCidade(nome);
    if(existe == -1)
        return false;
    return true; 
}


void InterfacePrincipal::conectarCidades() {
    string cidade1 = getString("Nome da cidade 1: ");
    string cidade2 = getString("Nome da cidade 2: ");
    if(verificaCidade(cidade1) && verificaCidade(cidade2)){
        if(cidade1 != cidade2){
            int custo = getInput<int>("Distância entre as cidades (km): ");
            grafo.conectar(cidade1, cidade2, custo);
        }
        else
            cout << "Não pode conectar a mesma cidade" << endl;
    }
    else 
        cout << "Pelo menos uma das cidades ainda não foi cadastrada. Cadastre-a e tente novamente!" << endl; 
}

void InterfacePrincipal::desconectarCidades() {
    string cidade1 = getString("Nome da cidade 1: ");
    string cidade2 = getString("Nome da cidade 2: ");
    grafo.desconectar(cidade1, cidade2);
}

void InterfacePrincipal::menuAnalise() {
    if(grafo.getTamanho() < 2) {
        cout << "É necessário cadastrar no mínimo duas cidades" << endl;
        return;
    }
    while(true) {
        cout << endl;
        cout << "(1) Calcular custo total para instalação" << endl; //MST
        cout << "(2) Calcular custo para uma instalação" << endl; //Dijkstra
        cout << "(3) Alterar custo da fibra óptica" << endl;
        cout << "(0) Voltar" << endl;
        int opcao = getInput<int>("");
        if(opcao == 1)
            custoTotal();
        else if(opcao == 2)
            custoUnico();
        else if(opcao == 3)
            custoFibra = getInput<double>("Custo da fibra óptica por km: ");
        else
            return;
    }
}

void InterfacePrincipal::custoTotal() {
    string nome = getString("Nome da cidade inicial: ");
    int total = grafo.prim(nome);
    cout << fixed << setprecision(2) << "Custo total: R$" << total * custoFibra << endl;
}

void InterfacePrincipal::custoUnico(){
    string cidade = getString("Nome da cidade: "); 
    if(verificaCidade(cidade)){
        int menorDist = grafo.dijkstra(grafo.buscarCidade(cidade));
        if(menorDist != -1)
            cout << fixed << setprecision(2) << "Custo de instalação: R$" << menorDist * custoFibra << endl;
        else 
            cout << "Não foi possível encontrar um caminho para cidades com instalação. Por favor, verifique as conexões da cidade" << endl;
    }
    else
        cout << "Cidade não encontrada" << endl;
}
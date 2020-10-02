#include "interfacePrincipal.hpp"

#include <iomanip>

using namespace std;

string getString(string mensagem) {
    string entrada;
    while(true) {
        cout << mensagem;
        getline(cin, entrada);
        if(entrada.empty() || entrada[0] == ' ')
            cout << endl << "Entrada inválida" << endl; 
        else
            break; 
    }
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
            cout << endl << "Entrada inválida." << endl;
            loop = true;
        }
        cin.ignore(32767, '\n');
    }
    return entrada;
}

InterfacePrincipal::InterfacePrincipal() {
    custoFibra = 500;
    cout << fixed << setprecision(2);
    system("clear||cls");
}

void InterfacePrincipal::menuPrincipal() {
    while(true) {
        cout << "(1) Gerenciamento de cidades" << endl;
        cout << "(2) Menu de análise" << endl;
        cout << "(0) Finalizar o programa" << endl;
        int opcao = getInput<int>("");
        system("clear||cls");
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
        cout << "(4) Ver cidades" << endl;
        cout << "(5) Alterar status de instalação" << endl;
        cout << "(6) Deletar todas as cidades" << endl;
        cout << "(0) Voltar" << endl;
        int opcao = getInput<int>("");
        system("clear||cls");
        if(opcao == 1)
            cadastroCidade();
        else if(opcao == 2)
            conectarCidades();
        else if(opcao == 3)
            desconectarCidades();
        else if(opcao == 4)
            grafo.imprimirCidades();
        else if(opcao == 5)
            menuInstalacao();
        else if(opcao == 6)
            grafo.reset();
        else
            return;
    }
}

void InterfacePrincipal::menuInstalacao() {
    string nome = getString("Nome de cidade: ");
    system("clear||cls");
    if(verificaCidade(nome))
        grafo.inverterStatus(nome);
    else
        cout << "Cidade não encontrada" << endl << endl;
}

void InterfacePrincipal::cadastroCidade() {
    string nome = getString("Nome da cidade: ");
    if(!verificaCidade(nome)) {
        string resp = getString("Possui instalação? (S) sim (N) não: ");
        system("clear||cls");
        bool instalada; 
        resp[0] = toupper(resp[0]);
        cout << nome << " foi cadastrada como cidade ";
        if(resp[0] == 'S') {
            instalada = true;
            cout << "com instalação" << endl;
        } else {
            instalada = false; 
            cout << "sem instalação" << endl;
        }
        grafo.novoVertice(nome,instalada);
    }
    else {
        system("clear||cls");
        cout << "Cidade já cadastrada" << endl;
    }
    cout << endl;
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
    if(cidade1 != cidade2) {
        double custo = 0;
        while(custo <= 0) {
            custo = getInput<double>("Distância entre as cidades (km): ");
            if(custo <= 0)
                cout << endl << "Custo inválido" << endl;
        }
        system("clear||cls");
        grafo.conectar(cidade1, cidade2, custo);
    } else {
        system("clear||cls");
        cout << "Não pode conectar a mesma cidade" << endl << endl;
    }
}

void InterfacePrincipal::desconectarCidades() {
    string cidade1 = getString("Nome da cidade 1: ");
    string cidade2 = getString("Nome da cidade 2: ");
    system("clear||cls");
    grafo.desconectar(cidade1, cidade2);
}

void InterfacePrincipal::menuAnalise() {
    if(!grafo.temConexao()) {
        cout << "Para acessar esse menu é necessário que exista no mínimo uma conexão" << endl << endl;
        return;
    }
    while(true) {
        cout << "(1) Calcular custo total para instalação" << endl; //MST
        cout << "(2) Calcular custo para uma instalação" << endl; //Dijkstra
        cout << "(3) Alterar custo da fibra óptica (Atual: R$ " << custoFibra << ")" << endl;
        cout << "(0) Voltar" << endl;
        int opcao = getInput<int>("");
        system("clear||cls");
        if(opcao == 1)
            custoTotal();
        else if(opcao == 2)
            custoUnico();
        else if(opcao == 3) {
            alterarCusto();
        } else
            return;
    }
}

void InterfacePrincipal::alterarCusto() {
    custoFibra = 0;
    while(custoFibra <= 0) {
        custoFibra = getInput<double>("Custo da fibra óptica por km: ");
        if(custoFibra <= 0)
            cout << endl << "Valor inválido" << endl;
    }
    system("clear||cls");
    cout << "O custo do km da fibra óptica agora é R$ " << custoFibra << endl << endl;
}

void InterfacePrincipal::custoTotal() {
    string nome = getString("Nome da cidade inicial: ");
    system("clear||cls");
    double total = grafo.prim(nome);
    if(total == -1)
        cout<< "A cidade precisa estar conectada" << endl;
    else if(total == 0)
        cout << "A cidade deve existir" << endl;
    else
        cout << "Custo total: R$" << total * custoFibra << endl;
    cout << endl;
}

void InterfacePrincipal::custoUnico(){
    string cidade = getString("Nome da cidade: "); 
    system("clear||cls");
    if(verificaCidade(cidade)){
        double menorDist = grafo.dijkstra(grafo.buscarCidade(cidade));
        if(menorDist != -1)
            cout << "Custo de instalação: R$" << menorDist * custoFibra << endl;
        else 
            cout << "Não foi possível encontrar um caminho para cidades com instalação. Por favor, verifique as conexões da cidade" << endl;
    }
    else
        cout << "Cidade não encontrada" << endl;
    cout << endl;
}

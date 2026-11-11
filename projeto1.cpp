#include <iostream>
#include <string>
using namespace std;

// Definir a struct do Cliente
struct Cliente {
    int Id;
    string nome;
    string telefone;
};

// Definir a struct do filme
struct Filme {
    int codigo;
    string titulo;
    string genero;
    int ano;
    int idcliente;
};

// Procedimento para exibir um mernu de opções
void mostrarMenu() {
    cout << "################### MENU ###################\n";
    cout << "1 - para cadastrar um cliente.\n";
    cout << "2 - para cadastrar fime.\n";
    cout << "3 - para listar os clientes.\n";
    cout << "4 - para listar os fimes.\n";
    cout << "5 - Buscar filmes por cliente.\n";
    cout << "6 - Relatorio geral.\n";
    cout << "7 - sair.\n";
    cout << "##########################################\n\n";
    cout << "Digite sua opcao: ";
}

// procedimento para cadastrar novo cliente
void cadastrarClientes(Cliente vet[], int i) {
    vet[i].Id = i + 1;
    cout << "Id gerado para o cliente: " << vet[i].Id << endl;

    cout << " Digite o nome: ";
    cin.ignore();
    getline(cin, vet[i].nome);
    cout << "Digite o telefone: ";
    cin >> vet[i].telefone;
}

// Procedimento para cadastrar um filme
bool cadastrarFilme(Filme vet[], int i, Cliente clientes[], int totalClientes) {

    if (totalClientes == 0) {
        cout << "Cadastre um cliente antes de cadastrar um filme.\n";
        return false;
    }

    cout << "Digite o codigo: ";
    cin >> vet[i].codigo;

    cout << "Digite o titulo do filme: ";
    cin.ignore();
    getline(cin, vet[i].titulo);

    cout << "Digite o genero do filme: ";
    getline(cin, vet[i].genero);

    cout << "Digite o ano do filme: ";
    cin >> vet[i].ano;

    int id;
    bool encontrou = false;

    cout << "Digite o ID do cliente: ";
    cin >> id;

    for (int j = 0; j < totalClientes; j++) {
        if (clientes[j].Id == id) {
            encontrou = true;
        }
    }

    if (encontrou == true) {
        vet[i].idcliente = id;
        cout << "Filme associado ao cliente com sucesso!\n";
        return true;
    } else {
        cout << "Cliente nao encontrado. Filme nao cadastrado.\n";
        return false;
    }
}

// Procedimento para listar os clientes cadastrados
void mostrarClientes(Cliente vet[], int n) {
    cout << "Clientes cadastrados: \n";

    for(int i=0; i<n; i++) {
        cout << "------------------------------------\n";
        cout << "Id: " << vet[i].Id << endl;
        cout << "Nome: " << vet[i].nome << endl;
        cout << "Telefone: " << vet[i].telefone << endl;
    }

    cout << "--------------------------------------------\n";
}

// procedimento para listar os filmes cadastrados
void mostrarFilmes(Filme vet[], int n, Cliente clientes[], int totalClientes) {
    cout << "Filmes cadastrados: \n";

    for(int i=0; i<n; i++) {
        cout << "------------------------------------\n";
        cout << "Codigo: " << vet[i].codigo << endl;
        cout << "Titulo: " << vet[i].titulo << endl;
        cout << "Genero: " << vet[i].genero << endl;
        cout << "Ano: " << vet[i].ano << endl;

        for (int j = 0; j < totalClientes; j++) {
            if (clientes[j].Id == vet[i].idcliente) {
                cout << "Alugado para: " << clientes[j].nome << endl;
            }
        }
    }

    cout << "--------------------------------------------\n";
}

// Procedimento para buscar filmes por cliente
void buscarFilmePorCliente(Filme vet[], int n, int Id) {
    cout << "Filmes alugados pelo cliente Id: " << Id << endl;

    for(int i = 0; i < n; i++) {
        if(vet[i].idcliente == Id) {
            cout << "Titulo: " << vet[i].titulo << endl;
            cout << "genero: " << vet[i].genero << endl;
            cout << "Ano: " << vet[i].ano << endl;
            cout << "-------------------------" << endl;
        }
    }
}

// Procedimento para exibir o relatorio geral
void relatorioGeral(Cliente clientes[], int totalClientes, Filme filmes[], int totalFilmes) {
    cout << "RELATORIO GERAL\n";

    for (int i = 0; i < totalClientes; i++) {
        int quantidade = 0;

        for (int j = 0; j < totalFilmes; j++) {
            if (filmes[j].idcliente == clientes[i].Id) {
                quantidade++;
            }
        }

        cout << "-------------------------" << endl;
        cout << "Cliente: " << clientes[i].nome << endl;
        cout << "Quantidade de filmes alugados: " << quantidade << endl;
    }

    cout << "-------------------------\n";
}

int main() {
    // Declarar um vetor de Cliente
    Cliente listaCliente [50];
    // Declarar um vetor de Filme
    Filme listaFilme [50];

    // Contador de Cliente
    int contCliente = 0;
    int contFilme = 0;
    int opcao = 0;

    while(opcao != 7) {
        mostrarMenu();
        cin >> opcao;

        if(opcao == 1) {
            if (contCliente < 50) {
                cadastrarClientes(listaCliente, contCliente);
                contCliente++;
            } else {
                cout << "Limite de clientes atingido.\n";
            }
        }

        if(opcao == 2) {
            if (contFilme < 50) {
                if (cadastrarFilme(listaFilme, contFilme, listaCliente, contCliente)) {
                    contFilme++;
                }
            } else {
                cout << "Limite de filmes atingido.\n";
            }
        }

        if(opcao == 3) {
            mostrarClientes(listaCliente, contCliente);
        }

        if(opcao == 4) {
            mostrarFilmes(listaFilme, contFilme, listaCliente, contCliente);
        }

        if(opcao == 5) {
            int id;
            cout << "Digite o ID do cliente: ";
            cin >> id;
            buscarFilmePorCliente(listaFilme, contFilme, id);
        }

        if(opcao == 6) {
            relatorioGeral(listaCliente, contCliente, listaFilme, contFilme);
        }

        if(opcao < 1 || opcao > 7) {
            cout << "Opcao invalida!\n";
        }
    }

    cout << "Programa encerrado.\n";

    return 0;
}

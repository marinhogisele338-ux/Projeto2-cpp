#include <iostream>
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
    cout << "6 - Relatório geral.\n";
    cout << "7 - sair.\n";
    cout << "##########################################\n\n";
    cout << "Digite sua opcao: ";
}

// procedimento para cadastrar novo cliente
void cadastrarClientes(Cliente vet[], int i) {
    cout << "Digite o Id: ";
    cin.ignore();

    cout << " Digite o nome: ";
    getline(cin, vet[i].nome);
    cout << "Digite o telefone: ";
    cin >> vet[i].telefone;
}

// Procedimento para cadastrar um filme
void cadastrarFilme(Filme vet[], int i) {
    cout << "Digite o codigo: ";
    cout << "Digite o titulo do filme: ";
    cout << "Digite o genero do filme: ";
    cout << "Digite o ano do filme: ";
    cout << "Digite seu id: ";
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
void mostrarFilmes (Filme vet[], int n) {
    cout << "Filmes cadastrados: \n";
    for(int i=0; i<n; i++) {
            cout << "------------------------------------\n";
            cout << "Codigo: " << vet[i].codigo << endl;
            cout << "Titulo: " << vet[i].titulo << endl;
            cout << "Genero: " << vet[i].genero << endl;
            cout << "Ano: " << vet[i].ano << endl;
    }
    cout << "--------------------------------------------\n";
}
// Procedimento para buscar filmes por cliente
void




int main() {





}

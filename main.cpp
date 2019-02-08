#include <iostream>
#include <string>

using namespace std;

/*©2019 Leonardo Sander Paschoal. Todos os direitos reservados.
  Esse programa permite criar, visualizar, alterar e deletar cadastros de nome e email. Cada contato é um struct de nome cad. O número
  de contatos disponíveis para cadastro é definido pelo tamanho do array carastro[], na linha 16.Todos os métodos que verificam o
  tamanho desse array utilizam métodos qe calculam em tempo real. Assim, é possível alterar o código fonte para permitir a quantidade
  desejada de contatos no cadastro, sem necessidade de alterar os métodos que utilizam esse dado.*/

//////////////////////////////////////////////////////////////Definição do tipo struct cad
typedef struct cad {
	string nome, email;
}cad;

//////////////////////////////////////////////////////////////Definição do array cadastro
cad cadastro[5];

//////////////////////////////////////////////////////////////Método que retorna o índice disponível para armazenamento
int cadDisponivel() {
	for (int i = 0; i < sizeof(cadastro) / sizeof(cad); i++) {
		if (cadastro[i].nome == "")return i;
	}
	return -1;
}

//////////////////////////////////////////////////////////////Método que conta o número de contatos cadastrados
int contaItens() {
	int total = 0;
	for (int i = 0; i < sizeof(cadastro) / sizeof(cad); i++) {
		if (cadastro[i].nome != "")total++;
	}
	return total;
}

//////////////////////////////////////////////////////////////Método para cadastrar
void cadastrar(int i) {
	system("cls");
	cout << "< Cadastro de novo contato >" << endl;
	cout << "Nome: ";
	cin.ignore();
	getline(cin, cadastro[i].nome);
	cout << "E-mail: ";
	getline(cin, cadastro[i].email);

}

//////////////////////////////////////////////////////////////Método para exibir
void exibir() {
	system("cls");
	int n = 1;
	cout << "< Contatos cadastrados >" << endl;
	for (int i = 0; i < sizeof(cadastro) / sizeof(cad); i++) {
		if (cadastro[i].nome != "") {
			cout << " " << n << ". " << cadastro[i].nome << ": " << cadastro[i].email << endl;
			n++;
		}
	}
}

//////////////////////////////////////////////////////////////Método para modificar
void modificar() {
	system("cls");
	exibir();
	//cria array dos índices existentes
	int n = 1, ind[sizeof(cadastro) / sizeof(cad)], op = 0;
	for (int i = 0; i < sizeof(cadastro) / sizeof(cad); i++) {
		if (cadastro[i].nome != "") {
			ind[i] = n;
			n++;
		}
	}

	cout << "------------------------------------------------" << endl << endl;
	//procura o numero digitado no array de índices e retorma o índice no item escolhido no array cadastro
	n = -1;
	while (n == -1) {
		cout << "Digite o n\x00A3mero do item que deseja modificar: ";
		cin >> op;
		for (int i = 0; i < sizeof(ind) / sizeof(int); i++) {
			if (ind[i] == op) {
				n = i;
				break;
			}
		}
		if (n == -1) {
			system("cls");
			exibir();
			cout << "------------------------------------------------" << endl << endl;
			cout << "ERRO: O n\x00A3mero digitado n\x00C6o \x0082 um item v\x00A0lido!" << endl;;
		}
		else {
			system("cls");
			cout << "Nome: " << cadastro[n].nome << endl;
			cout << "Email: " << cadastro[n].email << endl << endl;
			cout << "O que deseja modificar?" << endl;
			cout << " 1. nome" << endl;
			cout << " 2. email" << endl;
			cout << " 3. ambos" << endl << endl;
			op = 0;
			while (op < 1 || op > 3) {
				cout << "Digite sua escolha: ";
				cin >> op;
				if (op == 1) {
					cout << "Digite o novo nome: ";
					cin.ignore();
					getline(cin, cadastro[n].nome);
					system("cls");
					cout << "Cadastro modificado com sucesso!" << endl << endl;
					cout << "Nome: " << cadastro[n].nome << endl;
					cout << "Email: " << cadastro[n].email << endl << endl;
				}
				else if (op == 2) {
					cout << "Digite o novo email: ";
					cin.ignore();
					getline(cin, cadastro[n].email);
					system("cls");
					cout << "Cadastro modificado com sucesso!" << endl << endl;
					cout << "Nome: " << cadastro[n].nome << endl;
					cout << "Email: " << cadastro[n].email << endl << endl;
				}
				else if (op == 3) {
					cout << "Digite o novo nome: ";
					cin.ignore();
					getline(cin, cadastro[n].nome);
					cout << "Digite o novo email: ";
					getline(cin, cadastro[n].email);
					system("cls");
					cout << "Cadastro modificado com sucesso!" << endl << endl;
					cout << "Nome: " << cadastro[n].nome << endl;
					cout << "Email: " << cadastro[n].email << endl << endl;
				}
				else {
					system("cls");
					cout << "Nome: " << cadastro[n].nome << endl;
					cout << "Email: " << cadastro[n].email << endl << endl;
					cout << "O que deseja modificar?" << endl;
					cout << " 1. nome" << endl;
					cout << " 2. email" << endl;
					cout << " 3. ambos" << endl << endl;
					cout << "ERRO: Op\x0087\x00C6o inv\x00A0lida!" << endl;
				}
			}


		}
	}
}

//////////////////////////////////////////////////////////////Método para apagar
void apagar() {
	system("cls");
	exibir();
	//cria array dos índices existentes
	int n = 1, ind[sizeof(cadastro) / sizeof(cad)], op = 0;
	for (int i = 0; i < sizeof(cadastro) / sizeof(cad); i++) {
		if (cadastro[i].nome != "") {
			ind[i] = n;
			n++;
		}
	}

	cout << endl << endl << endl;
	cout << "------------------------------------------------" << endl << endl;

	//procura o numero digitado no array de índices
	n = -1;
	while (n == -1) {
		cout << "Digite o n\x00A3mero do item que deseja apagar: ";
		cin >> op;
		for (int i = 0; i < sizeof(ind) / sizeof(int); i++) {
			if (ind[i] == op) {
				n = i;
				break;
			}
		}
		if (n == -1) {
			system("cls");
			exibir();
			cout << "------------------------------------------------" << endl << endl;
			cout << "ERRO: O n\x00A3mero digitado n\x00C6o \x0082 um item v\x00A0lido!" << endl;;
		}
		else {
			system("cls");
			cout << "Nome: " << cadastro[n].nome << endl;
			cout << "Email: " << cadastro[n].email << endl << endl;
			cout << "Tem certeza de que deseja apagar esse contato?" << endl;
			cout << " 1. sim" << endl;
			cout << " 2. n\x00C6o" << endl;
			op = 0;
			while (op < 1 || op > 2) {
				cout << "Digite sua escolha: ";
				cin >> op;
				if (op == 1) {
					cadastro[n].nome = "";
					system("cls");
					cout << "Cadastro apagado com sucesso!" << endl << endl;
				}
				else if (op == 2) {
					cout << "Exclus\x00C6o cancelada!";
				}
				else {
					system("cls");
					cout << "Nome: " << cadastro[n].nome << endl;
					cout << "Email: " << cadastro[n].email << endl << endl;
					cout << "O que deseja modificar?" << endl;
					cout << " 1. nome" << endl;
					cout << " 2. email" << endl;
					cout << " 3. ambos" << endl << endl;
					cout << "ERRO: Op\x0087\x00C6o inv\x00A0lida!" << endl;
				}
			}


		}
	}
}

//////////////////////////////////////////////////////////////Menu principal
void menuInicial() {
	char opcao;
	system("cls");
	cout << "-= Menu Inicial =-" << endl;
	cout << " 1.Cadastar novo contato" << endl;
	cout << " 2.Exibir contatos cadastrados" << endl;
	cout << " 3.Modificar contato" << endl;
	cout << " 4.Apagar contato" << endl;
	cout << " 5.Sair do programa" << endl << endl;
	do {
		cout << "Digite a op\x0087\x00C6o desejada: ";
		cin >> opcao;
		if (opcao == '1') {
			//cadastrar
			if (cadDisponivel() == -1) {
				system("cls");
				cout << "-= Menu Inicial =-" << endl;
				cout << " 1.Cadastar novo contato" << endl;
				cout << " 2.Exibir contatos cadastrados" << endl;
				cout << " 3.Modificar contato" << endl;
				cout << " 4.Apagar contato" << endl;
				cout << " 5.Sair do programa" << endl << endl;
				cout << "ERRO: O cadastro est\x00A0 cheio! Apague algum contato antes de continuar." << endl;
				opcao = '0';
			}
			else {
				cadastrar(cadDisponivel());
				cout << endl << endl << endl;
				system("pause");
				menuInicial();
			}
		}
		else if (opcao == '2') {
			//exibir
			if (contaItens() == 0) {
				system("cls");
				cout << "-= Menu Inicial =-" << endl;
				cout << " 1.Cadastar novo contato" << endl;
				cout << " 2.Exibir contatos cadastrados" << endl;
				cout << " 3.Modificar contato" << endl;
				cout << " 4.Apagar contato" << endl;
				cout << " 5.Sair do programa" << endl << endl;
				cout << "ERRO: O cadastro est\x00A0 vazio!" << endl;
				opcao = '0';
			}
			else {
				exibir();
				cout << endl << endl << endl;
				system("pause");
				menuInicial();
			}
		}
		else if (opcao == '3') {
			//modificar
			if (contaItens() == 0) {
				system("cls");
				cout << "-= Menu Inicial =-" << endl;
				cout << " 1.Cadastar novo contato" << endl;
				cout << " 2.Exibir contatos cadastrados" << endl;
				cout << " 3.Modificar contato" << endl;
				cout << " 4.Apagar contato" << endl;
				cout << " 5.Sair do programa" << endl << endl;
				cout << "ERRO: O cadastro est\x00A0 vazio!" << endl;
				opcao = '0';
			}
			else {
				modificar();
				cout << endl << endl << endl;
				system("pause");
				menuInicial();
			}
		}
		else if (opcao == '4') {
			//deletar
			if (contaItens() == 0) {
				system("cls");
				cout << "-= Menu Inicial =-" << endl;
				cout << " 1.Cadastar novo contato" << endl;
				cout << " 2.Exibir contatos cadastrados" << endl;
				cout << " 3.Modificar contato" << endl;
				cout << " 4.Apagar contato" << endl;
				cout << " 5.Sair do programa" << endl << endl;
				cout << "ERRO: O cadastro est\x00A0 vazio!" << endl;
				opcao = '0';
			}
			else {
				apagar();
				cout << endl << endl << endl;
				system("pause");
				menuInicial();
			}
		}
		else if (opcao == '5') {
			cout << "Programa encerrado pelo usu\x00A0rio. At\x0082 logo!";
				exit(0);
		}
		else {
			system("cls");
			cout << "-= Menu Inicial =-" << endl;
			cout << " 1.Cadastar novo contato" << endl;
			cout << " 2.Exibir contatos cadastrados" << endl;
			cout << " 3.Modificar contato" << endl;
			cout << " 4.Apagar contato" << endl;
			cout << " 5.Sair do programa" << endl << endl;
			cout << "ERRO: Op\x0087\x00C6o inv\x00A0lida!" << endl;
			opcao = '0';
		}
	} while (opcao != '1' && opcao != '2' && opcao != '3' && opcao != '4' && opcao != '5');
}

//////////////////////////////////////////////////////////////Método main
int main() {
	menuInicial();
	return 0;
}

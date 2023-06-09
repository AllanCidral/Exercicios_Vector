//FUNCAO:
// remover as duplicatas de um vetor, utilizando vector.
// o tamanho do vetor e definido pelo usuario.
// os elementos do vetor sao definidos pelo usuario.
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#define TMAX 100 // tamanho maximo do vetor
using namespace std;

int leiaN(); // le e valida o tamanho do vetor
vector<int> leiaVetor(int n); // le e valida os elementos do vetor
vector<int> remove_duplicates(vector<int> a); // remove as duplicatas
void relatorio(vector<int> a, vector<int> uniqueA); // relatorio final

int main()
{
	vector<int> a;
	vector<int> uniqueA;
	int n = 0;

	n = leiaN();
	system("CLS");
	a.reserve(n);
	a.resize(n);
	a = leiaVetor(n);
	system("CLS");
	uniqueA = remove_duplicates(a);
	relatorio(a, uniqueA);
	return 0;
}
int leiaN() {
	string info = "";
	bool validado;
	int n = 0;
	do {
		do {
			validado = true;
			cout << "Informe o tamanho do vetor (1-" << TMAX << "): ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			else
				for (int i = 0; i < info.size(); i++) // verifica posicao a posicao
					if (!isdigit(info.at(i))) { // se nao for digito
						validado = false;
						break;
					}
			if (!validado)
				cout << "Tamanho invalido, tente novamente." << endl;
		} while (!validado);
		n = stoi(info.c_str()); // converte string para inteiro
		if (n == 0 or n > TMAX)
			cout << "Tamanho invalido, tente novamente." << endl;
	} while (n == 0 or n > TMAX);
	return n;
}
vector<int> leiaVetor(int n) {
	vector<int> aux;
	aux.reserve(n);
	aux.resize(n);
	string info = "";
	bool validado;
	for (int i = 0; i < aux.size(); i++) {
		do {
			validado = true;
			cout << "Informe o " << i + 1 << " elemento do vetor: ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			else
				if (!isdigit(info.at(0)) and info.at(0) != '-') // se nao for digito ou sinal negativo
					validado = false;
				else
					for (int j = 1; j < info.size(); j++) // verifica posicao a posicao
						if (!isdigit(info.at(j))) { // se nao for digito
							validado = false;
							break;
						}
			if (!validado)
				cout << "Elemento invalido, tente novamente." << endl;
		} while (!validado);
		aux[i] = stoi(info.c_str()); // converte string para inteiro
	}
	return aux;
}
vector<int> remove_duplicates(vector<int> a) {
	vector<int>::iterator aux = unique(a.begin(), a.end());
	a.erase(aux, a.end());
	return a;
}
void relatorio(vector<int> a, vector<int> uniqueA) {
	cout << "Vetor original:\n";
	for (vector<int>::iterator i = a.begin(); i != a.end(); i++)
		cout << "[" << *i << "]";
	cout << endl;
	cout << "Vetor sem duplicatas:\n";
	for (vector<int>::iterator j = uniqueA.begin(); j != uniqueA.end(); j++)
		cout << "[" << *j << "]";
	cout << endl;
}
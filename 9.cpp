//FUNCAO:
// verificar se dois vetores A/B possuem os mesmos elementos em alguma ordem, considerando multiplicidades, utilizando vector.
// o tamanho dos vetores sao definidos pelo usuario.
// os elementos dos vetores sao definidos pelo usuario.
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#define TMAX 100 // tamanho maximo dos vetores
using namespace std;

int leiaN(); // le e valida o tamanho dos vetores
vector<int> leiaVetores(char l, vector<int>& aux); // le e valida os vetores
bool same_elements(vector<int> a, vector<int> b); // verifica se os vetores possuem os mesmos elementos em alguma ordem
void relatorio(bool x, vector<int> a, vector<int> b); // relatorio final

int main()
{
	vector<int> a;
	vector<int> b;
	vector<int> aux;
	int n = 0;
	char l = ' ';
	bool x = false;

	n = leiaN();
	system("CLS");
	a.reserve(n);
	b.reserve(n);
	a.resize(n);
	b.resize(n);
	aux.reserve(n);
	aux.resize(n);
	l = 'A';
	a = leiaVetores(l, aux);
	system("CLS");
	l = 'B';
	b = leiaVetores(l, aux);
	system("CLS");
	aux.clear();
	x = same_elements(a, b);
	relatorio(x, a, b);
	return 0;
}
int leiaN() {
	string info = "";
	bool validado;
	int n = 0;
	do {
		do {
			validado = true;
			cout << "Informe o tamanho dos vetores (1-" << TMAX << "): ";
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
vector<int> leiaVetores(char l, vector<int>& aux) {
	string info = "";
	bool validado;
	for (int i = 0; i < aux.size(); i++) {
		do {
			validado = true;
			cout << "Informe o " << i + 1 << " elemento do vetor " << l << ": ";
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
bool same_elements(vector<int> a, vector<int> b) {
	vector<bool> aux;
	aux.reserve(a.size());
	aux.resize(a.size());
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			if (a[i] == b[j]) {
				if (b[i] == a[j]) {
					aux[i] = true;
					break;
				}
			}
	for (int k = 0; k < aux.size(); k++)
		if (!aux[k])
			return false;
	aux.clear();
	return true;
}
void relatorio(bool x, vector<int> a, vector<int> b) {
	cout << "Vetor A:\n";
	for (vector<int>::iterator i = a.begin(); i != a.end(); i++)
		cout << "[" << *i << "]";
	cout << endl;
	cout << "Vetor B:\n";
	for (vector<int>::iterator j = b.begin(); j != b.end(); j++)
		cout << "[" << *j << "]";
	cout << endl;
	if (x)
		cout << "Os vetores possuem os mesmos elementos em alguma ordem." << endl;
	else
		cout << "Os vetores nao possuem os mesmos elementos em qualquer ordem." << endl;
}
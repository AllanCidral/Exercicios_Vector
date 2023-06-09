//FUNCAO:
// concatenar dois vetores A/B, utilizando vector.
// os tamanhos dos vetores sao definidos pelo usuario.
// os elementos dos vetores sao gerados aleatoriamente (0-99).
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#define TMAX 100 // tamanho maximo dos vetores
using namespace std;

int leiaN(); // le e valida o tamanho do vetor
vector<int> merge(vector<int> a, vector<int> b); // concatena A/B
void relatorio(vector<int> a, vector<int> b, vector<int> x); // relatorio final

int main()
{
	vector<int> a;
	vector<int> b;
	vector<int> x;
	int n = 0;

	n = leiaN();
	system("CLS");
	a.reserve(n);
	b.reserve(n);
	a.resize(n);
	b.resize(n);
	srand(time(NULL));
	for (int i = 0; i != a.size(); i++) {
		a[i] = rand() % 100;
		b[i] = rand() % 100;
	}
	x.reserve(a.size() + b.size());
	x.resize(a.size() + b.size());
	x = merge(a, b);
	relatorio(a, b, x);
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
vector<int> merge(vector<int> a, vector<int> b) {
	vector<int> x;
	x.insert(x.begin(), a.begin(), a.end());
	x.insert(x.end(), b.begin(), b.end());
	return x;
}
void relatorio(vector<int> a, vector<int> b, vector<int> x) {
	cout << "Vetor A:\n";
	for (vector<int>::iterator i = a.begin(); i != a.end(); i++)
		cout << "[" << *i << "]";
	cout << endl;
	cout << "Vetor B:\n";
	for (vector<int>::iterator j = b.begin(); j != b.end(); j++)
		cout << "[" << *j << "]";
	cout << endl;
	cout << "Vetor AB concatenado:\n";
	for (vector<int>::iterator k = x.begin(); k != x.end(); k++)
		cout << "[" << *k << "]";
	cout << endl;
}

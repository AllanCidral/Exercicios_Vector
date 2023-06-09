//FUNCAO:
// verificar se dois vetores A/B possuem os mesmos elementos na mesma ordem, utilizando vector.
// os tamanhos dos vetores sao definidos pelo usuario.
// os elementos dos vetores sao gerados aleatoriamente (0-99).
// L33 - A != B.
// L37 - A == B.
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#define TMAX 100 // tamanho maximo dos vetores
using namespace std;

int leiaN(); // le e valida o tamanho dos vetores
bool equals(vector<int> a, vector<int> b); // verifica a igualdade entre os vetores A/B
void relatorio(vector<int> a, vector<int> b, bool x); // relatorio final

int main()
{
	vector<int> a;
	vector<int> b;
	int n = 0;
	bool x = false;

	n = leiaN();
	system("CLS");
	a.reserve(n);
	b.reserve(n);
	a.resize(n);
	b.resize(n);
	srand(time(NULL));
	//for (int i = 0; i != a.size(); i++) { // gerador A != B
		//a[i] = rand() % 100;
		//b[i] = rand() % 100;
	//}
	for (int i = 0; i < n; i++) { // gerador A == B
		a[i] = rand() % 100;
		b[i] = a[i];
	}
	x = equals(a, b);
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
bool equals(vector<int> a, vector<int> b) {
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i])
			return false;
	return true;
}
void relatorio(vector<int> a, vector<int> b, bool x) {
	cout << "Vetor A:\n";
	for (vector<int>::iterator i = a.begin(); i != a.end(); i++)
		cout << "[" << *i << "]";
	cout << endl;
	cout << "Vetor B:\n";
	for (vector<int>::iterator j = b.begin(); j != b.end(); j++)
		cout << "[" << *j << "]";
	cout << endl;
	if (x)
		cout << "Os vetores tem os mesmos elementos na mesma ordem." << endl;
	else
		cout << "Os vetores nao tem os mesmos elementos na mesma ordem." << endl;
}
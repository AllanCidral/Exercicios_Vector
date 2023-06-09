// FUNCAO:
// inverter os elementos de um vetor, utilizando vector.
// o tamanho do vetor e definido pelo usuario.
// os elementos do vetor sao gerados aleatoriamente (0-99).
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#define TMAX 100 // tamanho maximo do vetor
using namespace std;

int leiaN(); // le e valida o tamanho do vetor
void relatorio(vector<int> x); // mostra o vetor original, inverte e mostra o invertido

int main()
{
	vector<int> x;
	int n = 0;

	n = leiaN();
	system("CLS");
	x.reserve(n);
	x.resize(n);
	srand(time(NULL));
	for (int i = 0; i != x.size(); i++)
		x[i] = rand() % 100;
	relatorio(x);
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
void relatorio(vector<int> x) {
	cout << "Vetor original:\n";
	for (vector<int>::iterator i = x.begin(); i != x.end(); i++)
		cout << "[" << *i << "]";
	cout << endl;
	reverse(x.begin(), x.end());
	cout << "Vetor invertido:\n";
	for (vector<int>::iterator i = x.begin(); i != x.end(); i++)
		cout << "[" << *i << "]";
	cout << endl;
}

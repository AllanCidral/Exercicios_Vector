//FUNCAO
// gerar a soma alternada (i0 - i1 + i2 - i3 + i4...) de um vetor, utilizando vector.
// o tamanho do vetor e definido pelo usuario.
// os elementos do vetor sao gerados aleatoriamente (0-99).
#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <cstdlib>
#define TMAX 100 // tamanho maximo do vetor
using namespace std;

int leiaN(); // le e valida o tamanho do vetor
int gerarSomaAlternada(vector<int> x); // gera a soma alternada
void relatorio(vector<int> x, int somaAlt); // relatorio final

int main()
{
    vector<int> x;
	int n = 0, somaAlt = 0;

	n = leiaN();
	system("CLS");
	x.reserve(n);
	x.resize(n);
	srand(time(NULL));
	for (int i = 0; i != x.size(); i++)
		x[i] = rand() % 100;
	somaAlt = gerarSomaAlternada(x);
	relatorio(x, somaAlt);
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
int gerarSomaAlternada(vector<int> x) {
	int aux = 0;
	for (int i = 0; i != x.size(); i++)
		if (i % 2 == 0)
			aux += x[i];
		else
			aux -= x[i];
	return aux;
}
void relatorio(vector<int> x, int somaAlt) {
	cout << "Soma alternada do vetor com " << x.size() << " elementos: " << endl;
	for (int i = 0; i != x.size(); i++) {
		cout << x[i] << " ";
		if (i != x.size() - 1) {
			if (i % 2 == 0)
				cout << "- ";
			else
				cout << "+ ";
		}
	}
	cout << "= " << somaAlt << endl;
}
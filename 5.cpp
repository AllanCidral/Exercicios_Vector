//FUNCAO:
// intercalar dois vetores A/B alternando elementos dos dois vetores, utilizando vector.
// se um vetor e mais curto do que o outro, entao alterna enquanto puder e depois acrescenta os elementos restantes do vetor mais longo.
// os tamanhos dos vetores sao definidos pelo usuario.
// os elementos dos vetores sao gerados aleatoriamente (0-99).
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#define TMAX 100 // tamanho maximo do vetor
using namespace std;

int leiaT(char l);
vector<int> merge(vector<int> a, vector<int> b);
void relatorio(vector<int> a, vector<int> b, vector<int> x);

int main()
{
	vector<int> a;
	vector<int> b;
	vector<int> x;
	int n = 0, m = 0;
	char l = ' ';

	l = 'A';
	n = leiaT(l);
	system("CLS");
	l = 'B';
	m = leiaT(l);
	system("CLS");
	a.reserve(n);
	b.reserve(m);
	a.resize(n);
	b.resize(m);
	srand(time(NULL));
	for (int i = 0; i != a.size(); i++)
		a[i] = rand() % 100;
	for (int j = 0; j != b.size(); j++)
		b[j] = rand() % 100;
	x.reserve(a.size() + b.size());
	x.resize(a.size() + b.size());
	x = merge(a, b);
	relatorio(a, b, x);
}
int leiaT(char l) {
	int t = 0;
	string info = "";
	bool validado;
	do {
		do {
			validado = true;
			cout << "Informe o tamanho do vetor " << l << " (1-" << TMAX << "): ";
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
		t = stoi(info.c_str()); // converte string para inteiro
		if (t == 0 or t > TMAX)
			cout << "Tamanho invalido, tente novamente." << endl;
	} while (t == 0 or t > TMAX);
	return t;
}
vector<int> merge(vector<int> a, vector<int> b) {
	vector<int> intercalado;
	if (a.size() == b.size()) {
		for (int i = 0; i != a.size(); i++) {
			intercalado.push_back(a[i]);
			intercalado.push_back(b[i]);
		}
	}
	else
		if (a.size() < b.size()) {
			for (int i = 0; i != a.size(); i++) {
				intercalado.push_back(a[i]);
				intercalado.push_back(b[i]);
			}
			intercalado.insert(intercalado.end(), b.begin() + a.size(), b.end());
		}
		else {
			for (int i = 0; i != b.size(); i++) {
				intercalado.push_back(a[i]);
				intercalado.push_back(b[i]);
			}
			intercalado.insert(intercalado.end(), a.begin() + b.size(), a.end());
		}
	return intercalado;
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
	cout << "Vetor AB intercalado:\n";
	for (vector<int>::iterator k = x.begin(); k != x.end(); k++)
		cout << "[" << *k << "]";
	cout << endl;
}

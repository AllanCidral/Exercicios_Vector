//FUNCAO:
// gerar o produto escalar de dois vetores A/B, utilizando vector.
// o tamanho do vetor e definido pelo usuario.
// os elementos do vetor sao gerados aleatoriamente (1-64).
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#define TMAX 100 // tamanho maximo do vetor
using namespace std;

int leiaN(); // le e valida o tamanho do vetor
double escalar(vector<double> a, vector<double> b); // gera o produto escalar
void relatorio(vector<double> a, vector<double> b, double x); // relatorio final

int main()
{
    vector<double> a;
    vector<double> b;
    double x = 0.0;
    int n = 0;

    n = leiaN();
    system("CLS");
    a.reserve(n);
    b.reserve(n);
    a.resize(n);
    b.resize(n);
    srand(time(NULL));
    for (int i = 0; i != a.size(); i++) {
        a[i] = 1 + ((float)rand() / RAND_MAX) * 63;
        b[i] = 1 + ((float)rand() / RAND_MAX) * 63;
    }
    x = escalar(a, b);
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
double escalar(vector<double> a, vector<double> b) {
    double aux = 0.0;
    for (int i = 0; i < a.size(); i++)
        aux += a[i] * b[i];
    return aux;
}
void relatorio(vector<double> a, vector<double> b, double x) {
    cout << "Vetor A:\n";
    for (vector<double>::iterator i = a.begin(); i != a.end(); i++)
        cout << "[" << *i << "]";
    cout << endl;
    cout << "Vetor B:\n";
    for (vector<double>::iterator j = b.begin(); j != b.end(); j++)
        cout << "[" << *j << "]";
    cout << endl;
    cout << "Produto escalar: " << fixed << setprecision(4) << x << endl;
}
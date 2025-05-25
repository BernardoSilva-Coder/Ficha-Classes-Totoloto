#ifndef CHAVE_H
#define CHAVE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cstdlib> // Para rand() e srand()

using namespace std;

class Chave
{
public:
    static void GerarChaveAleatoria(int *chavePremiada);
    static void OrdenarChave(int *chavePremiada, int *chaveUtilizador);
    static void ImprimirChave(int *chave, int tamanho);
    static void LerChave(int *chave);
    static int VerificaPremio(int *chave, int *chavePremiada);

private:
};

#endif
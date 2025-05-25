#include "Chave.h"

void Chave::GerarChaveAleatoria(int *chavePremiada)
{
    // Definindo o tamanho da chave
    int tamanho = 0;
    // Inicializando o gerador de números aleatórios
    srand(time(0));
    while (tamanho < 5)
    {
        int num = rand() % 49 + 1; // Números Aleatorios entre 1 e 49
        bool repetido = false;
        // Inicializando o gerador de números aleatórios
        for (int i = 0; i < tamanho; i++)
        {
            if (chavePremiada[i] == num)
            {
                repetido = true;
                break;
            }
        }
        if (!repetido)
        {
            chavePremiada[tamanho] = num;
            tamanho++;
        }
    }
}

void Chave::OrdenarChave(int *chavePremiada, int *chaveUtilizador)
{
    // Ordenando a chave usando o algoritmo de ordenação padrão
    sort(chavePremiada, chavePremiada + 5);
    sort(chaveUtilizador, chaveUtilizador + 5);
}

void Chave::ImprimirChave(int *chave, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        // Imprimindo cada número da chave
        cout << chave[i] << " ";
    }
}
void Chave::LerChave(int *chaveUtilizador)
{
    int tamanho = 0; // tamanho da chave do utilizador
    cout << "Faca uma Chave de 5 Numeros + 1 Numero Extra!" << endl;
    cout << "=============================================" << endl;
    cout << endl;

    while (tamanho < 6)
    {
        int numero;
        string input;
        bool entradaValida = false;

        while (!entradaValida)
        {
            cout << "Digite o numero " << (tamanho + 1) << " da chave (entre 1 e 49): ";
            cin >> input;

            try
            {
                numero = stoi(input);

                if (numero < 1 || numero > 49)
                {
                    cout << "Numero invalido. Deve estar entre 1 e 49." << endl;
                }
                else
                {
                    entradaValida = true;
                }
            }
            catch (...)
            {
                cout << "Entrada invalida. Insira um numero inteiro." << endl;
            }
        }

        // Verifica se o número já foi introduzido
        bool repetido = false;
        for (int i = 0; i < tamanho; i++)
        {
            if (chaveUtilizador[i] == numero)
            {
                repetido = true;
                cout << "A chave nao pode conter numeros repetidos!" << endl;
                break;
            }
        }

        if (!repetido)
        {
            chaveUtilizador[tamanho] = numero;
            tamanho++;
        }
    }
}

int Chave::VerificaPremio(int *chaveUtilizador, int *chavePremiada)
{
    int acertos = 0;
    // Verifica quantos números acertou
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (chaveUtilizador[i] == chavePremiada[j])
            {
                acertos++;
                break; // Para evitar contar o mesmo número mais de uma vez
            }
            else
            {
                continue; // Continua verificando os outros números
            }
        }
    }
    return acertos;
}

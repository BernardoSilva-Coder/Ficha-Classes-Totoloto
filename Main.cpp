#include "Chave.h"

int main()
{
    system("color 27");
    int *chavePremiada = new int[5];   // Tamanho da chave premiada
    int *chaveUtilizador = new int[6]; // Tamanho da chave do utilizador
    Chave::GerarChaveAleatoria(chavePremiada);
    int op;
    string input;
    do
    {
        system("CLS");
        cout << "==========================================" << endl;
        cout << "   Bem-vindo a Lotaria SolVerde O Belo!         " << endl;
        cout << "==========================================" << endl;
        cout << "                  MENU                    " << endl;
        cout << "==========================================" << endl;
        cout << "  1. Introduzir Chave                     " << endl;
        cout << "  2. Imprimir Chave Introduzida           " << endl;
        cout << "  3. Verificar Premio                     " << endl;
        cout << "  4. Sair                                 " << endl;
        cout << "==========================================" << endl;
        cout << "Escolha uma opcao (1-4): ";
        cin >> input;
        try // Verificacao para so a aceitar numeros de 1 a 4
        {
            op = stoi(input);
        }
        catch (...)
        {
            cout << endl;
            op = -1; // opcao invalida
        }
        switch (op)
        {
        case 1:
            system("CLS");
            Chave::LerChave(chaveUtilizador);
            Chave::OrdenarChave(chaveUtilizador, chavePremiada);
            break;
        case 2:
            system("CLS");
            Chave::OrdenarChave(chaveUtilizador, chavePremiada);
            cout << "\n==================================" << endl;
            cout << "      Chave Introduzida           " << endl;
            cout << "----------------------------------" << endl;
            cout << "  ";
            Chave::ImprimirChave(chaveUtilizador, 6);
            cout << endl;
            cout << "==================================" << endl;
            break;
        case 3:
            system("CLS");
            {
                Chave::OrdenarChave(chaveUtilizador, chaveUtilizador);
                cout << "\n==================================" << endl;
                cout << "      Chave de Utilizador         " << endl;
                cout << "----------------------------------" << endl;
                cout << "  ";
                Chave::ImprimirChave(chaveUtilizador, 6);
                cout << endl;
                cout << "==================================" << endl;

                cout << "\n==================================" << endl;
                cout << "         Chave Premiada           " << endl;
                cout << "----------------------------------" << endl;
                cout << "  ";
                Chave::ImprimirChave(chavePremiada, 5);
                cout << endl;
                cout << "==================================" << endl;

                int acertos = Chave::VerificaPremio(chaveUtilizador, chavePremiada);
                cout << endl;
                if (acertos > 0)
                {
                    cout << "Parabens! Ganhou " << acertos << " EUR! A SolVerde O Belo vai ter de lhe pagar! " << endl;
                }
                else
                {
                    cout << "Teve azar, A SolVerde O Belo esta invejosa, nao ganhou nada!" << endl;
                }
                break;
            }
        case 4:
            system("CLS");
            cout << "A sair...." << endl;
            break;
        default:
            cout << "Opcao invalida.Por favor, escreva um numero inteiro de 1 a 4. Tente novamente." << endl;
            break;
        }
        if (op != 4)
        {
            cout << endl;
            cout << "Pressione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (op != 4);
    return 0;
}

#include <iostream>
#include "lista_fisica.hpp"
#include "lista_encadeada_simples.hpp"
#include "lista_duplamente_ligada.hpp"
using namespace std;

int main()
{
    ListaEncadeadaSimples LES;
    ListaDuplamenteLigada LDL;
    int option;
    int tipoLista;
    while (tipoLista != 4)
    {
        cout << "+--------------------------------------------+\n"
             << "1: Lista por contiguidade fisica;\n"
             << "2: Lista simplesmente encadeada;\n"
             << "3: Lista duplamente encadeada;\n"
             << "4: Sair;\n\n"
             << "5: Escolha a opcao: ";
        cin >> tipoLista;
        cout << "\n+--------------------------------------------+\n";
        if (tipoLista == 4)
        {
            cout << "+--------------------------------------------+\n"
                 << "Saindo...\n"
                 << "+--------------------------------------------+\n";
            return;
        }
        while (option != 9)
        {
            cout << "+--------------------------------------------+\n"
                 << "1: ler uma lista de inteiros e armazena-la;\n"
                 << "2: gerar uma lista aleatoria;\n"
                 << "3: inserir um valor em uma posicao especifica;\n"
                 << "4: fazer a transposicao de duas posicoes;\n"
                 << "5: procurar um valor dado;\n"
                 << "6: procurar o menor valor;\n"
                 << "7: mostrar lista;\n"
                 << "8: mostrar lista em ordem inversa;\n"
                 << "9: sair;\n\n"
                 << "Escolha a opcao: ";
            cin >> option;
            cout << "\n+--------------------------------------------+\n";

            switch (option)
            {
            case 1:
                switch (tipoLista)
                {
                case 1:
                    break;
                case 2:
                    LES.leitura();
                    break;
                case 3:
                    LDL.leitura();
                    break;
                default:
                    break;
                }
                break;
            case 2:
                int tamanhoLista, inicio, fim;
                cout << "Insira o tamanho da lista: ";
                cin >> tamanhoLista;
                cout << "Insira o inicio e fim do intervalo: ";
                cin >> inicio;
                cin >> fim;
                switch (tipoLista)
                {
                case 1:
                    break;
                case 2:
                    LES.geraListaAleatoria(tamanhoLista, inicio, fim);
                    break;
                case 3:
                    LDL.geraListaAleatoria(tamanhoLista, inicio, fim);
                    break;
                default:
                    break;
                }
                break;
            case 3:
                int valorInserir, posicao;
                cout << "Insira o valor: ";
                cin >> valorInserir;
                cout << "Insira a posicao: ";
                cin >> posicao;
                switch (tipoLista)
                {
                case 1:
                    break;
                case 2:
                    LES.inserePosicao(valorInserir, posicao);
                    break;
                case 3:
                    LDL.inserePosicao(valorInserir, posicao);
                    break;
                default:
                    break;
                }
                break;
            case 4:
                int primPos, segPos;
                cout << "Insira a primeira posicao: ";
                cin >> primPos;
                cout << "Insira a segunda posicao: ";
                cin >> segPos;
                switch (tipoLista)
                {
                case 1:
                    break;
                case 2:
                    LES.transposicao(primPos, segPos);
                    break;
                case 3:
                    LDL.transposicao(primPos, segPos);
                    break;
                default:
                    break;
                }
                break;
            case 5:
                int valorBuscar, quantAcessosBusca;
                cout << "Insira o valor a ser buscado: ";
                cin >> valorBuscar;
                switch (tipoLista)
                {
                case 1:
                    break;
                case 2:
                    No *noBusca;
                    LES.busca(valorBuscar, &noBusca, quantAcessosBusca);
                    break;
                case 3:
                    No2 *noBusca;
                    LDL.busca(valorBuscar, &noBusca, quantAcessosBusca);
                    break;
                default:
                    break;
                }
                if (noBusca == nullptr)
                    cout << "Nao encontrado!";
                else
                    cout << "O valor " << valorBuscar << " (" << noBusca->valor << ") foi encontrado!";
                cout << "\nQuantidade de acessos necessarios: " << quantAcessosBusca << endl;
                break;
            case 6:
                int menor, quantAcessosMenor;
                No *noMenor;
                LES.buscaMenor(menor, &noMenor, quantAcessosMenor);
                cout << "O menor valor e: " << menor << " (" << noMenor->valor << ")";
                cout << "\nQuantidade de acessos necessarios: " << quantAcessosMenor << endl;
                break;
            case 7:
                LES.mostrar();
                break;
            case 8:
                LES.mostrarInvertida();
                break;
            default:
                cout << "+--------------------------------------------+\n"
                     << "Saindo...\n"
                     << "+--------------------------------------------+\n";
                option = 9;
                break;
            }
        }
    }
}
#include <iostream>
#include "lista_fisica.hpp"
#include "lista_encadeada_simples.hpp"
#include "lista_duplamente_ligada.hpp"
using namespace std;

int main()
{
    ListaEncadeadaSimples LES;
    ListaDuplamenteLigada LDL;
    ListaContiguidadeFisica LCF;
    int option;
    int tipoLista;
    while (tipoLista != 4)
    {
        cout << "+--------------------------------------------+\n"
             << "1: Lista por contiguidade fisica;\n"
             << "2: Lista simplesmente encadeada;\n"
             << "3: Lista duplamente encadeada;\n"
             << "4: Sair;\n\n"
             << "Escolha a opcao: ";
        cin >> tipoLista;
        cout << "+--------------------------------------------+\n";
        if (tipoLista == 4)
        {
            cout
                << "Saindo...\n"
                << "+--------------------------------------------+\n";
            return 0;
        }
        option = 0;
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
            cout << "+--------------------------------------------+\n";

            switch (option)
            {
            case 1:
                switch (tipoLista)
                {
                case 1:
                    LCF.leitura();
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
                    LCF.geraListaAleatoria(tamanhoLista, inicio, fim);
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
                    LCF.inserirPosicao(valorInserir, posicao);
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
                    LCF.transposicao(primPos, segPos);
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
                    int posicao;
                    LCF.busca(valorBuscar, posicao, quantAcessosBusca);
                    if (posicao == -1)
                        cout << "Nao encontrado!\n";
                    else
                    {
                        cout << "O valor " << valorBuscar << " (" << LCF.lista[posicao] << ") foi encontrado!";
                        cout << "\nQuantidade de acessos necessarios: " << quantAcessosBusca << endl;
                    }
                    break;
                case 2:
                    No *noBusca;
                    LES.busca(valorBuscar, &noBusca, quantAcessosBusca);
                    if (noBusca == nullptr)
                        cout << "Nao encontrado!\n";
                    else
                    {
                        cout << "O valor " << valorBuscar << " (" << noBusca->valor << ") foi encontrado!";
                        cout << "\nQuantidade de acessos necessarios: " << quantAcessosBusca << endl;
                    }
                    break;
                case 3:
                    No2 *noBusca1;
                    LDL.busca(valorBuscar, &noBusca1, quantAcessosBusca);
                    if (noBusca1 == nullptr)
                        cout << "Nao encontrado!\n";
                    else
                    {
                        cout << "O valor " << valorBuscar << " (" << noBusca1->valor << ") foi encontrado!";
                        cout << "\nQuantidade de acessos necessarios: " << quantAcessosBusca << endl;
                    }
                    break;
                default:
                    break;
                }
                break;
            case 6:
                int menor, quantAcessosMenor;
                switch (tipoLista)
                {
                case 1:
                    int posicao;
                    LCF.buscaMenor(menor, posicao, quantAcessosMenor);
                    cout << "O menor valor e: " << menor << " (" << LCF.lista[posicao] << ")";
                    cout << "\nQuantidade de acessos necessarios: " << quantAcessosMenor << endl;
                    break;
                case 2:
                    No *noMenor;
                    LES.buscaMenor(menor, &noMenor, quantAcessosMenor);
                    cout << "O menor valor e: " << menor << " (" << noMenor->valor << ")";
                    cout << "\nQuantidade de acessos necessarios: " << quantAcessosMenor << endl;
                    break;
                case 3:
                    No2 *noMenor1;
                    LDL.buscaMenor(menor, &noMenor1, quantAcessosMenor);
                    cout << "O menor valor e: " << menor << " (" << noMenor1->valor << ")";
                    cout << "\nQuantidade de acessos necessarios: " << quantAcessosMenor << endl;
                    break;
                default:
                    break;
                }
                break;
            case 7:
                switch (tipoLista)
                {
                case 1:
                    LCF.mostrar();
                    break;
                case 2:
                    LES.mostrar();
                    break;
                case 3:
                    LDL.mostrar();
                    break;
                default:
                    break;
                }
                break;
            case 8:
                switch (tipoLista)
                {
                case 1:
                    LCF.mostrarInvertida();
                    break;
                case 2:
                    LES.mostrarInvertida();
                    break;
                case 3:
                    LDL.mostrarInvertida();
                default:
                    break;
                }
                break;
            default:
                cout
                    << "Saindo...\n"
                    << "+--------------------------------------------+\n";
                option = 9;
                break;
            }
        }
    }
    return 0;
}
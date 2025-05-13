#include <iostream>
#include "lista_fisica.hpp"
#include "lista_encadeada_simples.hpp"
#include "lista_duplamente_ligada.hpp"
#include "settings.cpp"
using namespace std;

int main()
{
    int option;
    int tipoLista = 0;
    ListaEncadeadaSimples LES;
    ListaDuplamenteLigada LDL;
    ListaContiguidadeFisica LCF;
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
            LES.libera();
            LDL.libera();
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
                    LCF.inserePosicao(valorInserir, posicao);
                    break;
                case 2:
                    No *noAnterior;
                    noAnterior = LES.buscaPtr(posicao);
                    LES.inserePosicao(valorInserir, noAnterior);
                    break;
                case 3:
                    No2 *noAnterior1;
                    noAnterior1 = LDL.buscaPtr(posicao);
                    LDL.inserePosicao(valorInserir, noAnterior1);
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
                int valorBuscar;
                cout << "Insira o valor a ser buscado: ";
                cin >> valorBuscar;
                switch (tipoLista)
                {
                case 1:
                    int posicao;
                    posicao = LCF.busca(valorBuscar);
                    if (posicao == -1){
                        cout << "Nao encontrado!\n";
                        cout << "Quantidade de acessos necessarios: " << quantAcessosBusca << endl;
                    }
                    else
                    {
                        cout << "O valor " << valorBuscar << " foi encontrado!";
                        cout << "\nQuantidade de acessos necessarios: " << quantAcessosBusca << endl;
                    }
                    break;
                case 2:
                    No *noBusca;
                    noBusca = LES.busca(valorBuscar);
                    if (noBusca == nullptr){
                        cout << "Nao encontrado!\n";
                        cout << "\nQuantidade de acessos necessarios: " << quantAcessosBusca << endl;
                    }
                    else
                    {
                        cout << "O valor " << valorBuscar << " foi encontrado!";
                        cout << "\nQuantidade de acessos necessarios: " << quantAcessosBusca << endl;
                    }
                    break;
                case 3:
                    No2 *noBusca1;
                    noBusca1 = LDL.busca(valorBuscar);
                    if (noBusca1 == nullptr)
                        cout << "Nao encontrado!\n";
                    else
                    {
                        cout << "O valor " << valorBuscar << " foi encontrado!";
                        cout << "\nQuantidade de acessos necessarios: " << quantAcessosBusca << endl;
                    }
                    break;
                default:
                    break;
                }
                break;
            case 6:
                switch (tipoLista)
                {
                case 1:
                    int posicao, menor;
                    posicao = LCF.buscaMenor();
                    menor = LCF.lista[posicao];
                    cout << "O menor valor e: " << menor << ";\n";
                    cout << "Quantidade de acessos necessarios: " << quantAcessosMenor << endl;
                    break;
                case 2:
                    No *noAntMenor;
                    noAntMenor = LES.buscaMenor();
                    cout << "O menor valor e: " << noAntMenor->prox->valor << ";\n";
                    cout << "O valor antecessor ao menor valor e: " << noAntMenor->valor << ";\n";
                    cout << "Quantidade de acessos necessarios: " << quantAcessosMenor << endl;
                    break;
                case 3:
                    No2 *noAntMenor1;
                    noAntMenor1 = LDL.buscaMenor();
                    cout << "O menor valor e: " << noAntMenor1->prox->valor << ";\n";
                    cout << "O valor antecessor ao menor valor e: " << noAntMenor1->valor << ";\n";
                    cout << "Quantidade de acessos necessarios: " << quantAcessosMenor << endl;
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
                break;
            }
        }
    }
    return 0;
}
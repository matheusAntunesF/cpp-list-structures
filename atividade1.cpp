#include <iostream>
#include "lista_fisica.hpp"
#include "lista_encadeada_simples.hpp"
#include "lista_duplamente_ligada.hpp"
using namespace std;

int main()
{
    ListaEncadeadaSimples LES;
    int option;
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
            LES.leitura();
            break;
        case 2:
            int tamanhoLista, inicio, fim;
            cout << "Insira o tamanho da lista: ";
            cin >> tamanhoLista;
            cout << "Insira o inicio e fim do intervalo: ";
            cin >> inicio;
            cin >> fim;
            LES.geraListaAleatoria(tamanhoLista, inicio, fim); 
            break;
        case 3:
            int valorInserir, posicao;
            cout << "Insira o valor: ";
            cin >> valorInserir;
            cout << "Insira a posicao: ";
            cin >> posicao;
            LES.inserePosicao(valorInserir, posicao);
            break;
        case 4:
            int primPos, segPos;
            cout << "Insira a primeira posicao: ";
            cin >> primPos;
            cout << "Insira a segunda posicao: ";
            cin >> segPos;
            LES.transposicao(primPos, segPos);
            break;
        case 5:
            int valorBuscar, quantAcessosBusca;
            No *noBusca;
            cout << "Insira o valor a ser buscado: ";
            cin >> valorBuscar;
            LES.busca(valorBuscar, &noBusca, quantAcessosBusca);
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
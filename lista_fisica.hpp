#pragma once
#include <iostream>
#include <random>
#include "settings.cpp"
using namespace std;
class ListaContiguidadeFisica
{
public:
    vector<int> lista;

    void iniciaLista(int tamanho)
    {
        lista.reserve(tamanho * 100);
        lista.resize(tamanho);
    }

    void leitura()
    {
        int tamanho, valor;
        cin >> tamanho;
        iniciaLista(tamanho);
        for (int &posicao : lista)
        {
            cin >> valor;
            posicao = valor;
        }
    }

    void geraListaAleatoria(int tamanho, int inicio, int fim)
    {
        int numAleatorio;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(inicio, fim);
        iniciaLista(tamanho);
        for (int &posicao : lista)
        {
            numAleatorio = dist(gen);
            posicao = numAleatorio;
        }
    }

    void inserePosicao(int valor, int posicao)
    {
        lista.insert(lista.begin() + posicao, valor);
    }

    void transposicao(int primPos, int segPos)
    {
        int cache = lista[primPos];
        lista[primPos] = lista[segPos];
        lista[segPos] = cache;
    }

    int busca(int valor)
    {
        int posicao;
        quantAcessosBusca = 0;
        for (posicao = 0; posicao < static_cast<int>(lista.size()); posicao++)
        {
            quantAcessosBusca = quantAcessosBusca + 2;
            if (lista[posicao] == valor)
            {
                return posicao;
            }
        }
        posicao = -1;
        return posicao;
    }

    int buscaMenor()
    {
        int menor = lista[0];
        int posicaoMenor = 0;
        quantAcessosMenor = 0;
        for (int posicao = 0; posicao < static_cast<int>(lista.size()); posicao++)
        {
            quantAcessosMenor = quantAcessosMenor + 2;
            if (lista[posicao] < menor)
            {
                menor = lista[posicao];
                posicaoMenor = posicao;
                quantAcessosMenor++;
            }
        }
        return posicaoMenor;
    }

    void mostrar()
    {
        for (int posicao : lista)
        {
            cout << posicao << "; ";
        }
        cout << endl;
    }

    void mostrarInvertida(){
        for(int posicao = lista.size() - 1; posicao >= 0; posicao--){
            cout << lista[posicao] << "; ";
        }
        cout << endl;
    }

};

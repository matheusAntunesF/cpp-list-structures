#pragma once
#include <iostream>
#include <random>
using namespace std;

class No
{
public:
    int valor;
    No *prox;

    No(int novoValor)
    {
        valor = novoValor;
        prox = nullptr;
    }

    No()
    {
    }
};

class ListaEncadeadaSimples
{
public:
    No *cabeca;
    int tamanhoLista;

    ListaEncadeadaSimples()
    {
        cabeca = new No;
        cabeca->prox = nullptr;
        tamanhoLista = 0;
    }

    void insere(int valor)
    {
        No *noAtual = cabeca;
        while (noAtual->prox != nullptr)
        {
            noAtual = noAtual->prox;
        }
        noAtual->prox = new No(valor);
        tamanhoLista++;
    }

    void leitura()
    {
        int tamanho;
        cin >> tamanho;
        int valor;
        for (int posicao = 0; posicao < tamanho; posicao++)
        {
            cin >> valor;
            insere(valor);
        }
    }

    void geraListaAleatoria(int tamanho, int inicio, int fim)
    {
        int numAleatorio;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(inicio, fim);
        for (int posicao = 0; posicao < tamanho; posicao++)
        {
            numAleatorio = dist(gen);
            insere(numAleatorio);
        }
    }

    void inserePosicao(int valor, int posicao)
    {
        if (posicao < 0)
            return;
        No *noAntecessor = cabeca;
        for (int posAtual = 0; (posAtual < posicao) && (noAntecessor->prox != nullptr); posAtual++)
        {
            noAntecessor = noAntecessor->prox;
        }
        No *novoNo = new No(valor);
        novoNo->prox = noAntecessor->prox;
        noAntecessor->prox = novoNo;
        tamanhoLista++;
    }

    void transposicao(int primPos, int segPos)
    {
        int maior = primPos > segPos ? primPos : segPos;

        if (maior > tamanhoLista)
            return;

        No *primNo = cabeca->prox;
        No *segNo = cabeca->prox;
        for (int posAtual = 0; posAtual < maior; posAtual++)
        {
            if (posAtual < primPos)
            {
                primNo = primNo->prox;
            }
            if (posAtual < segPos)
            {
                segNo = segNo->prox;
            }
        }
        int cache = primNo->valor;
        primNo->valor = segNo->valor;
        segNo->valor = cache;
    }

    void busca(int valor, No **noAtual, int &count)
    {
        *noAtual = cabeca->prox;
        count = 1;
        if (*noAtual != nullptr)
        {
            for (int posAtual = 0; posAtual < tamanhoLista; posAtual++)
            {
                count++;
                if ((*noAtual)->valor == valor)
                    return;
                else
                    *noAtual = (*noAtual)->prox;
                count++;
            }
        }
        *noAtual = nullptr;
    }

    void buscaMenor(int &menor, No **noMenor, int &count)
    {
        No *noAtual = cabeca->prox;
        *noMenor = noAtual;
        menor = noAtual->valor;
        count = 2;
        for (int posAtual = 1; posAtual < tamanhoLista; posAtual++)
        {
            noAtual = noAtual->prox;
            if (noAtual->valor < menor)
            {
                menor = noAtual->valor;
                *noMenor = noAtual;
            }
            count = count + 3;
        }
    }

    void mostrar()
    {
        No *noAtual = cabeca;
        if (noAtual != nullptr)
        {
            noAtual = noAtual->prox;
        }
        while (noAtual != nullptr)
        {
            cout << noAtual->valor << "; ";
            noAtual = noAtual->prox;
        }
        cout << endl;
    }

    void mostrarInvertida()
    {
        mostrarInvertidaRecursiva(cabeca->prox);
        cout << "\n";
    }

    void mostrarInvertidaRecursiva(No *noAtual)
    {
        if (noAtual == nullptr)
            return;
        mostrarInvertidaRecursiva(noAtual->prox);
        cout << noAtual->valor << "; ";
    }
};

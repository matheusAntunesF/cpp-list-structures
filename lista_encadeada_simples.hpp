#pragma once
#include <iostream>
#include <random>
#include "settings.cpp"
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

    void inserePosicao(int valor, No* noAntecessor)
    {
        if (noAntecessor == nullptr){
            cout << "Posicao inexistente" << endl;
            return;
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

    No *buscaPtr(int posicao)
    {
        No *noAntecessor = cabeca;
        for(int posAtual = 0; (noAntecessor->prox != nullptr) && posAtual < posicao; posAtual++)
        {
            noAntecessor = noAntecessor->prox;
        }
        return noAntecessor;
    }

    No *busca(int valor)
    {
        No *noAtual = cabeca->prox;
        quantAcessosBusca = 0;
        while (noAtual != nullptr)
        {
            quantAcessosBusca++;
            if (noAtual->valor == valor)
                return noAtual;

            noAtual = noAtual->prox;
            quantAcessosBusca++;
        }
        return noAtual;
    }

    No *buscaMenor()
    {
        No *noAtual = cabeca->prox;
        No *noAntMenor = noAtual;
        quantAcessosMenor = 0;
        while(noAtual->prox != nullptr)
        {
            quantAcessosMenor++;
            if (noAtual->prox->valor < noAntMenor->prox->valor)
            {
                noAntMenor = noAtual;
                quantAcessosMenor++;
            }
            noAtual = noAtual->prox;
            quantAcessosMenor++;
        }
        return noAntMenor;
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
    
    void libera(){
        No* noAtual = cabeca;
        No* noAnterior = cabeca;
        while(noAtual != nullptr){
            noAnterior = noAtual;
            noAtual = noAtual->prox;
            delete noAnterior;
        }
    }
};

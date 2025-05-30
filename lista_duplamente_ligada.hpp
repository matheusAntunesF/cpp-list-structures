#pragma once
#include <iostream>
#include <random>
#include "settings.cpp"
using namespace std;

class No2
{
public:
    int valor;
    No2 *prox;
    No2 *ant;

    No2(int novoValor)
    {
        valor = novoValor;
        ant = nullptr;
        prox = nullptr;
    }

    No2(int novoValor, No2 *antNo, No2 *proxNo)
    {
        valor = novoValor;
        ant = antNo;
        prox = proxNo;
    }

    No2()
    {
    }
};

class ListaDuplamenteLigada
{
public:
    No2 *cabeca;
    int tamanhoLista;

    ListaDuplamenteLigada()
    {
        cabeca = new No2();
        cabeca->prox = nullptr;
        cabeca->ant = nullptr;
        tamanhoLista = 0;
    }

    void insere(int valor)
    {
        No2 *noAntecessor = cabeca;
        while (noAntecessor->prox != nullptr)
        {
            noAntecessor = noAntecessor->prox;
        }
        noAntecessor->prox = new No2(valor, noAntecessor, nullptr);
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

    void inserePosicao(int valor, No2* noAntecessor)
    {
        if (noAntecessor == nullptr){
            cout << "Posicao inexistente" << endl;
            return;
        }
        No2 *novoNo = new No2(valor, noAntecessor, noAntecessor->prox);
        No2 *noProx = noAntecessor->prox;

        noAntecessor->prox = novoNo;
        if (noProx != nullptr)
        {
            noProx->ant = novoNo;
        }
        tamanhoLista++;
    }

    void transposicao(int primPos, int segPos)
    {
        int maior = primPos > segPos ? primPos : segPos;

        if (maior > tamanhoLista)
            return;

        No2 *primNo = cabeca->prox;
        No2 *segNo = cabeca->prox;
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

    No2 *buscaPtr(int posicao)
    {
        No2 *noAntecessor = cabeca;
        for(int posAtual = 0; (noAntecessor->prox != nullptr) && posAtual < posicao; posAtual++)
        {
            noAntecessor = noAntecessor->prox;
        }
        return noAntecessor;
    }

    No2 *busca(int valor)
    {
        No2 *noAtual = cabeca->prox;
        quantAcessosBusca = 0;
        if (noAtual != nullptr)
        {
            for (int posAtual = 0; posAtual < tamanhoLista; posAtual++)
            {
                quantAcessosBusca++;
                if (noAtual->valor == valor)
                    return noAtual;
                else
                    noAtual = noAtual->prox;
                quantAcessosBusca++;
            }
        }
        noAtual = nullptr;
        return noAtual;
    }

    No2* buscaMenor()
    {
        No2 *noAtual = cabeca->prox;
        No2 *noAntMenor = noAtual;
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
        No2 *noAtual = cabeca;
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

    void mostrarInvertidaRecursiva(No2 *noAtual)
    {
        if (noAtual == nullptr)
            return;
        mostrarInvertidaRecursiva(noAtual->prox);
        cout << noAtual->valor << "; ";
    }

    void libera(){
        No2* noAtual = cabeca;
        No2* noAnterior = cabeca;
        while(noAtual != nullptr){
            noAnterior = noAtual;
            noAtual = noAtual->prox;
            delete noAnterior;
        }
    }
};
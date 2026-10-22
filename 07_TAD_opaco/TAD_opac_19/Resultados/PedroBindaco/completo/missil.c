#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "missil.h"

#define MAX_TAM 100 /**< Tamanho máximo do nome do míssil. */

/**
 * @brief Estrutura que representa um míssil.
 * 
 * A estrutura tMissil contém o nome do míssil, as coordenadas x e y, e o poder de ataque.
 * 
 */
struct missil{
    char * nome;
    float posX, posY;
    float poder;
};

/**
 * @brief Lê a entrada do usuário e cria um novo míssil.
 * 
 * @return tMissil Ponteiro para o míssil criado.
 */
tMissil LeMissil(){
    tMissil m = (tMissil)calloc(1, sizeof(struct missil));
    m->nome = (char*)calloc(MAX_TAM, sizeof(char*));
    if (m == NULL){
        printf("MISSIL DEU ERRADO");
        exit(1);
    }
    scanf("%s %f %f %f\n", m->nome, &m->posX, &m->posY, &m->poder);
    return m;
}

/**
 * @brief Imprime as informações do míssil.
 * 
 * @param missil Ponteiro para o míssil que será impresso.
 */
void ImprimeMissil(tMissil missil){
    printf("M-%s: %.2f\n", missil->nome, missil->poder);
}

/**
 * @brief Libera a memória alocada para o míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a memória liberada.
 */
void LiberaMissil(tMissil missil){
    free(missil->nome);
    free(missil);
}

/**
 * @brief Obtém a coordenada y do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a coordenada y obtida.
 * @return float Coordenada y do míssil.
 */
float GetMissilY(tMissil missil){
    return missil->posY;
}

/**
 * @brief Obtém a coordenada x do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a coordenada x obtida.
 * @return float Coordenada x do míssil.
 */
float GetMissilX(tMissil missil){
    return missil->posX;
}

/**
 * @brief Obtém o poder de ataque do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá o poder de ataque obtido.
 * @return float Poder de ataque do míssil.
 */
float GetMissilPoder(tMissil missil){
    return missil->poder;
}

/**
 * @brief Reduz o poder de ataque do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá o poder de ataque reduzido.
 * @param valor Valor a ser subtraído do poder de ataque do míssil.
 */
void ReduzPoder(tMissil missil, float valor){
    missil->poder -= valor;
    if (missil->poder < 0){
        missil->poder = 0;
    }
}


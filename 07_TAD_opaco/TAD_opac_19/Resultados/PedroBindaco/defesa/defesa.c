#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "defesa.h"

#define QUADRADO 'Q' /**< Caractere que indica uma defesa do tipo quadrado. */
#define CIRCULO 'C' /**< Caractere que indica uma defesa do tipo círculo. */
#define MAX_TAM 100 /**< Tamanho máximo do nome da defesa. */

/**
 * @brief Estrutura que representa uma defesa.
 * 
 * A estrutura tDefesa contém o tipo da defesa, as coordenadas do centro, o tamanho e o poder de defesa.
 * 
 */
struct defesa{
    char * nome;
    char tipo;
    float posX;
    float posY;
    float tamanho;
    float poder;
    int qtdMissil;
};

/**
 * @brief Lê a entrada do usuário e cria uma nova defesa.
 * 
 * @return tDefesa Ponteiro para a defesa criada.
 */
tDefesa LeDefesa(){
    tDefesa d = (tDefesa)calloc(1, sizeof(struct defesa));
    d->nome = (char*)calloc(MAX_TAM, sizeof(char*));
    if (d == NULL){
        printf("DEFESA DEU ERRADO");
        exit(1);
    }
    scanf("%s %f %f %c %f %f %d\n", d->nome, &d->posX, &d->posY, &d->tipo, &d->tamanho, &d->poder, &d->qtdMissil);
    return d;
}

/**
 * @brief Imprime as informações da defesa.
 * 
 * @param defesa Ponteiro para a defesa que será impressa.
 */
void ImprimeDefesa(tDefesa defesa){
    printf("D-%s: %d\n", defesa->nome, defesa->qtdMissil);
}

/**07_TAD_opaco/TAD_opac_19/Respostas/PedroBindaco/missil.h
 * @param defesa Ponteiro para a defesa que terá a memória liberada.
 */
void LiberaDefesa(tDefesa defesa){
    free(defesa->nome);
    free(defesa);
}

/**
 * @brief Verifica se um ponto está dentro da área de defesa.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @param x Coordenada x do ponto.
 * @param y Coordenada y do ponto.
 * @return int 1 se o ponto está dentro da área de defesa, 0 caso contrário.
 */

float calculaLado(float meia_diag){
    float diag = meia_diag * 2;
    return diag / sqrt(2);
}

int VerificaSeDentroArea(tDefesa defesa, float x, float y){
    float dx = defesa->posX - x;
    float dy = defesa->posY - y;
    float dist = sqrtf(dx*dx + dy*dy);
    float lado = calculaLado(defesa->tamanho);
    if (defesa->tipo == CIRCULO){
        if (defesa->tamanho >= dist){
            return 1;
        }
        return 0;
    }
    if(x <= defesa->posX + lado/2 && x >= defesa->posX - lado/2){
        if(y <= defesa->posY + lado/2 && y >= defesa->posY - lado/2){
            return 1;
        }
    }
    return 0;

}

/**
 * @brief Consome uma unidade de míssil da defesa.
 * 
 * @param defesa Ponteiro para a defesa que será usada.
 */
void UsaDefesa(tDefesa defesa){
    defesa->qtdMissil--;
}

/**
 * @brief Obtém o poder de defesa da defesa.
 * 
 * @param defesa Ponteiro para a defesa que terá o poder de defesa obtido.
 * @return float Poder de defesa da defesa.
 */
float GetDefesaPoder(tDefesa defesa){
    return defesa->poder;
}

/**
 * @brief Verifica exclusivamente se a quantidade de munição é maior que zero.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @return int 1 se a defesa pode defender, 0 caso contrário.
 */
int PodeDefender(tDefesa defesa){
    if (defesa->qtdMissil > 0){
        return 1;
    }
    return 0;
}


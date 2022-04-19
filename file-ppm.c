#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM 20

void forma(FILE *arq, FILE *sepia, FILE *negativo, int *lin, int *col){
    
    int r, g, b;
    int nr, ng, nb;
    int tr, tg, tb; 

    fprintf(sepia, "%s\n", "P3");
    fprintf(sepia, "%d %d\n", *lin,*col);
    fprintf(sepia, "%s\n", "255");

    fprintf(negativo, "%s\n", "P3");
    fprintf(negativo, "%d %d\n", *lin,*col);
    fprintf(negativo, "%s\n", "255");


    for (int j=0; j< *col; j++){
        for (int i =0; i<*lin;i++){

            fscanf(arq, "%d %d %d", &r, &g, &b);

            nr = 255 -r;
            ng = 255 -g;
            nb = 255 -b;

            tr = (0.393*r)+(0.769*g)+(0.189*b);
            tg = (0.349*r) +(0.686*g) +(0.168*b);
            tb = (0.272*r) + (0.534*g) + (0.131*b);

            if(tr > 255)
                r = tr;
            if(tg > 255)
                g =tg;
            if(tb > 255)
                b = tb;

        fprintf(sepia, "%d %d %d ",tr,tg,tb);
        fprintf(negativo, "%d %d %d ", nr,ng,nb);
        }
        fprintf(negativo, "\n");
        fprintf(sepia, "\n");
    }
} 
int main(){

    char nome[TAM];
    char str[8];
    int lin, col;
    
    printf("Informe o nome do arquivo:");
    fgets(nome, TAM, stdin);
    nome[strlen(nome)-1] = '\0';

    FILE *arq = fopen(nome, "r");
    FILE *sepia = fopen("sepia.ppm", "w");
    FILE *negativo = fopen("negativo.ppm", "w");
    if(arq == NULL || sepia == NULL || negativo == NULL){
        printf("Não foi possível abrir o arquivo.FATAL\n");
        return 0;
    }
    for (int i =0; i <3; i++){
        if(i == 1){
            fscanf(arq, "%d", &lin);
            fscanf(arq, "%d", &col);
        }
        fgets(str,  sizeof(arq), arq);
    }

    forma(arq,sepia, negativo, &lin, &col);

    printf("Arquivo negativo.ppm gerado com sucesso!\nArquivo sepia.ppm gerado com sucesso!\n");
    fclose(negativo);
    fclose(arq);
    fclose(sepia);

    return 0;
}
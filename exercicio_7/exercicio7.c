#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ALUNOS 30

typedef float prova;
typedef float media;

struct provas{
prova p[3];
media M;
};

typedef struct provas Provas;

struct aluno{
    int ra;
    int frequencia;
    Provas Ps;
};

int main(void) {
    int n,i,j;
    float desvios_Ps[3]={0.0, 0.0, 0.0}, medias_Ps[3]={0.0, 0.0, 0.0};
    struct aluno alunos[MAX_ALUNOS];
    scanf("%d", &n);
/* COMPLETE AQUI */
    for(i=0; i<n; i++){
        printf("RA: ");
        scanf("%d", &alunos[i].ra);
        j=0;
        alunos[i].Ps.M=0;
        for (j=0;j<3;j++){
        printf("digite a nota %d do aluno: ", j);
        scanf("%f", &alunos[i].Ps.p[j]);
        alunos[i].Ps.M+=alunos[i].Ps.p[j];
        medias_Ps[j]+=alunos[i].Ps.p[j];
        }
        alunos[i].Ps.M=alunos[i].Ps.M/3;
    }

    medias_Ps[0]=medias_Ps[0]/n;
    medias_Ps[1]=medias_Ps[1]/n;
    medias_Ps[2]=medias_Ps[2]/n;

    for (i=0; i<n; i++){
        printf("RA: %d\n", alunos[i].ra);
        for(j=0; j<3; j++){
            printf("Prova %d: %f\n", j, alunos[i].Ps.p[j]);
        }
        printf("Media: %f\n", alunos[i].Ps.p[j]);
        printf("-------------------\n");
    }

    for (i=0; i<3; i++){
        printf("Media geral P%d: %f\n", i, medias_Ps[i]);
        for(j=0; j<n; j++){
            desvios_Ps[i]+= (medias_Ps[i]-alunos[j].Ps.p[i])*(medias_Ps[i]-alunos[j].Ps.p[i]);
        }
        printf("Desvio Padrao P%d: %f\n", i, sqrt(desvios_Ps[i]/n));
    }

    return 0;
}

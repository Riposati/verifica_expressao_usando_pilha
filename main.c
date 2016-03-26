#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pilha{
    char letra;
    struct pilha *abaixo;
}typedef Pilha;

Pilha *push(Pilha *topo,char charControle){

    Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
    aux->letra = charControle;

    if(topo==NULL){
        aux->abaixo = NULL;
    }

    if(topo!=NULL){
        aux->abaixo = topo;
    }

    topo = aux;
    return topo;
}

Pilha *pop(Pilha *topo){

    Pilha *aux = topo;

    if(topo!=NULL){
        topo = topo->abaixo;
        free(aux);
    }
    return topo;
}

void mostra(Pilha *topo){

    if(topo!=NULL){

        while(topo->abaixo!=NULL){
            printf("|%c|\n",topo->letra);
            topo = topo->abaixo;
        }

        printf("|%c|\n",topo->letra);
    }
}

int main()
{
    Pilha *topo;
    char c;
    char expressao[40];
    int i=0,flag;
    int contAbreP,contAbreC,contAbreChaves;
    int contFechaP,contFechaC,contFechaChaves;

    while(1){

        strcpy(expressao,"");
        gets(expressao);
        topo = NULL;
        i = 0;
        flag = 1;
        contAbreP = contAbreC = contAbreChaves = 0;
        contFechaP = contFechaC = contFechaChaves = 0;

        while(expressao[i]!='\0'){

            if(expressao[i]=='(' || expressao[i]=='{' || expressao[i]=='['){

                topo = push(topo,expressao[i]);

                if(expressao[i]=='(')contAbreP++;
                if(expressao[i]=='[')contAbreC++;
                if(expressao[i]=='{')contAbreChaves++;

            }

            if(expressao[i]==')' || expressao[i]=='}' || expressao[i]==']'){

                if(expressao[i]==')')contFechaP++;
                if(expressao[i]==']')contFechaC++;
                if(expressao[i]=='}')contFechaChaves++;

                if(topo!=NULL){
                    c = topo->letra;
                    topo = pop(topo);
                }

                if(expressao[i] == ')' && c != '('){
                    flag = 0;
                    break;
                }else{

                if(expressao[i] == '}' && c != '{'){
                    flag = 0;
                    break;
                }else{
                    if(expressao[i] == ']' && c != '['){
                        flag = 0;
                        break;
                    }
                }
            }
        }

        i++;
    }

    //mostra(topo);

    if(topo!=NULL){
        flag = 0;
    }
    if(flag && contAbreP==contFechaP && contAbreC == contFechaC && contAbreChaves == contFechaChaves){
        printf("expressao valida\n");
    }else
        printf("expressao invalida\n");
    }

    return 0;
}

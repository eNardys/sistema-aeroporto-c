#include <stdio.h>
#include "estruturas.h"

void PassagensPorVoo(aeroporto *point,int *tam_voo){
    if(*tam_voo==0){
        printf("\nNao existem voos cadastrados!\n");
        return;
    }
    for(int i = 0; i < *tam_voo; i++){
        printf("\n=== Relatorio de Voo %d ===\n", i+1);
        printf("Identificador: %d\n", point->listavoo[i].iden_voo);
        printf("Empresa: %s\n", point->listavoo[i].empresa);
        printf("Passagens vendidas: %d\n", point->listavoo[i].qnt_psg);
        printf("===========================\n");
    }
}

void NumeroVoosPorEmpresa(aeroporto *point,int *tam_voo){
    if(*tam_voo==0){
        printf("\nAinda nao foram cadastrado voos!\n");
        return;
    }
    for(int i = 0; i < *tam_voo; i++){
        int contador = 0;
        int verificador = 0;
        for(int k = 0; k < i; k++){
            if(strcmp(point->listavoo[i].empresa, point->listavoo[k].empresa) == 0){
                verificador = 1;
                break;
            }
        }
        if(verificador){
            continue;
        }

        for(int j = 0; j < *tam_voo; j++){
            if(strcmp(point->listavoo[i].empresa, point->listavoo[j].empresa) == 0){
                contador++;
            }
        }

        printf("\nEmpresa: %s\n", point->listavoo[i].empresa);
        printf("Quantidade de voos: %d\n", contador);
        printf("===========================\n");
    }
}

void PassageirosPorVoo(aeroporto *point,int *tam_voo,int *tam_passageiro,int *tam_passagem){
    if(*tam_voo == 0 || *tam_passagem == 0){
        printf("\nNao existem voos ou passagens cadastradas!\n");
        return;
    }

    int ind_voo;
    printf("\nInsira o identificador do voo: ");
    scanf("%d", &ind_voo);
    while(getchar() != '\n');

    int existe_voo = -1;
    for(int i = 0; i < *tam_voo; i++){
        if(point->listavoo[i].iden_voo == ind_voo){
            existe_voo = i;
            break;
        }
    }
    if(existe_voo == -1){
        printf("\nVoo nao encontrado!\n");
        return;
    }

    printf("\n=== Lista de Passageiros do Voo %d ===\n", ind_voo);

    int verificador = -1;
    for(int i = 0; i < *tam_passagem; i++){
        if(point->listaPassagem[i].identificador_voo == ind_voo){
            int id_psg = point->listaPassagem[i].identificador_passageiro;

            for(int j = 0; j < *tam_passageiro; j++){
                if(point->listaPassageiros[j].iden_psg == id_psg){
                    printf("Nome: %s | CPF: %d | Telefone: %d\n",point->listaPassageiros[j].nome,point->listaPassageiros[j].cpf,point->listaPassageiros[j].telefone);
                    verificador = 1;
                    break;
                }
            }
        }
    }

    if(verificador==-1){
        printf("\nNenhum passageiro encontrado para este voo.\n");
    }

    printf("===========================\n");
}

void listaVoosPorEmpresa(aeroporto *point, int *tam_voo){
    if(*tam_voo == 0){
        printf("\nNao existem voos cadastrados!\n");
        return;
    }

    char nome_empresa[50];
    printf("\nInsira o nome da empresa: ");
    scanf(" %[^\n]", nome_empresa);

    int encontrou = -1;
    printf("\n=== Voos da Empresa %s ===\n", nome_empresa);

    for(int i = 0; i < *tam_voo; i++){
        if(strcmp(point->listavoo[i].empresa, nome_empresa) == 0){
            printf("Identificador: %d\n", point->listavoo[i].iden_voo);
            printf("Numero da aeronave: %d\n", point->listavoo[i].num_aeronave);
            printf("Origem: %s\n", point->listavoo[i].origem);
            printf("Destino: %s\n", point->listavoo[i].destino);
            printf("Data de partida: %02d/%02d/%d\n",point->listavoo[i].partida.dia,point->listavoo[i].partida.mes,point->listavoo[i].partida.ano);
            printf("Horario de saida: %02d:%02d\n",point->listavoo[i].saida.hora,point->listavoo[i].saida.minutos);
            printf("Capacidade maxima: %d\n", point->listavoo[i].qnt_max_passageiros);
            printf("Passagens vendidas: %d\n", point->listavoo[i].qnt_psg);
            printf("---------------------------\n");
            encontrou = 1;
        }
    }

    if(encontrou==-1){
        printf("\nNenhum voo encontrado para a empresa %s.\n", nome_empresa);
    }
}

void PassagensReservadas(aeroporto *point, int *tam_passagem, int *tam_passageiro, int *tam_voo){
    if(*tam_passagem == 0){
        printf("\nNao existem passagens cadastradas!\n");
        return;
    }

    int id_psg;
    printf("\nInsira o identificador do passageiro: ");
    scanf("%d", &id_psg);
    while(getchar() != '\n');

    int existe_psg = -1;
    for(int i = 0; i < *tam_passageiro; i++){
        if(point->listaPassageiros[i].iden_psg == id_psg){
            existe_psg = i;
            break;
        }
    }
    if(existe_psg == -1){
        printf("\nPassageiro nao encontrado!\n");
        return;
    }

    printf("\n=== Passagens do Passageiro %s ===\n", point->listaPassageiros[existe_psg].nome);

    int encontrou = -1;
    for(int i = 0; i < *tam_passagem; i++){
        if(point->listaPassagem[i].identificador_passageiro == id_psg){
            printf("Numero da passagem: %d\n", point->listaPassagem[i].num_passagem);
            printf("Identificador do voo: %d\n", point->listaPassagem[i].identificador_voo);
            printf("Valor: %.2f\n", point->listaPassagem[i].valor);
            printf("Data da venda: %02d/%02d/%d\n",point->listaPassagem[i].venda.dia,point->listaPassagem[i].venda.mes,point->listaPassagem[i].venda.ano);
            printf("---------------------------\n");
            encontrou = 1;
        }
    }

    if(encontrou==-1){
        printf("\nNenhuma passagem encontrada para este passageiro.\n");
    }
}

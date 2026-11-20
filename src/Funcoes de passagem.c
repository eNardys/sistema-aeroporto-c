#include <stdio.h>
#include "estruturas.h"

void incluirPassagem(aeroporto *point,int *tam_passagem,int *tam_voo, int *tam_passageiro){
    point->listaPassagem = realloc(point->listaPassagem, (*tam_passagem + 1) * sizeof(passagem));
    if(point->listaPassagem == NULL){
        printf("\nErro ao alocar memoria!\n");
        return;
    }

    int i = *tam_passagem;

    printf("\nInsira o numero da passagem: ");
    scanf("%d", &point->listaPassagem[i].num_passagem);
    while(getchar() != '\n');

    for(int j=0;j<*tam_passagem;j++){
        if(point->listaPassagem[j].num_passagem==point->listaPassagem[i].num_passagem){
            printf("\nNumero da passagem ja utilizado! Tente novamente!\n");
            return;
        }
    }

    printf("Insira o identificador do passageiro: ");
    scanf("%d", &point->listaPassagem[i].identificador_passageiro);
    while(getchar() != '\n');

    int existe_psg = -1;
    for(int j = 0; j < *tam_passageiro; j++){
        if(point->listaPassageiros[j].iden_psg == point->listaPassagem[i].identificador_passageiro){
            existe_psg = 1;
            break;
        }
    }
    if(existe_psg == -1){
        printf("Passageiro nao encontrado! Passagem nao incluida\n");
        return;
    }

    printf("Insira o identificador do voo: ");
    scanf("%d", &point->listaPassagem[i].identificador_voo);
    while(getchar() != '\n');

    int existe_voo = -1;
    for(int j = 0; j < *tam_voo; j++){
        if(point->listavoo[j].iden_voo == point->listaPassagem[i].identificador_voo){
            existe_voo = 1;
            break;
        }
    }
    if(existe_voo == -1){
        printf("Voo nao encontrado! Passagem nao incluida\n");
        return;
    }

    printf("Insira o valor da passagem: ");
    scanf("%f", &point->listaPassagem[i].valor);
    while(getchar() != '\n');


    printf("Insira a data da venda (dia/mes/ano): ");
    scanf("%d/%d/%d", &point->listaPassagem[i].venda.dia,&point->listaPassagem[i].venda.mes,&point->listaPassagem[i].venda.ano);
    while(getchar() != '\n');

    (*tam_passagem)++;

    for(int k = 0; k < *tam_voo; k++){
        if(point->listaPassagem[*tam_passagem - 1].identificador_voo == point->listavoo[k].iden_voo){
            point->listavoo[k].qnt_psg += 1;
            break;
        }
    }

    printf("\nPassagem incluida!\n");
}

void alterarPassagem(aeroporto *point,int *tam_voo,int *tam_passagem,int *tam_passageiro){
    if(*tam_passagem == 0){
        printf("\nNao existem passagens cadastradas!\n");
        return;
    }

    int ind_passagem, ind = -1;
    printf("\nInsira o numero da passagem que deseja alterar: ");
    scanf("%d", &ind_passagem);
    while(getchar() != '\n');

    for(int i = 0; i < *tam_passagem; i++){
        if(ind_passagem == point->listaPassagem[i].num_passagem){
            ind = i;
            break;
        }
    }

    if(ind == -1){
        printf("\nPassagem nao encontrada!\n");
        return;
    }

    printf("\n=== Dados da Passagem ===\n");
    printf("Identificador do passageiro: %d\n", point->listaPassagem[ind].identificador_passageiro);
    printf("Identificador do voo: %d\n", point->listaPassagem[ind].identificador_voo);
    printf("Valor: %.2f\n", point->listaPassagem[ind].valor);
    printf("Data da venda: %02d/%02d/%d\n",point->listaPassagem[ind].venda.dia,point->listaPassagem[ind].venda.mes,point->listaPassagem[ind].venda.ano);
    printf("==========================\n");

    int opc_passagem;
    do{
        printf("\n1 - Alterar identificador do passageiro\n");
        printf("2 - Alterar identificador do voo\n");
        printf("3 - Alterar valor\n");
        printf("4 - Alterar data da venda\n");
        printf("0 - Sair\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opc_passagem);
        while(getchar() != '\n');

        if(opc_passagem == 1){
            int aux_passageiro, indicador = -1;
            printf("\nInsira o novo identificador de passageiro: ");
            scanf("%d", &aux_passageiro);
            while(getchar() != '\n');

            for(int i = 0; i < *tam_passageiro; i++){
                if(aux_passageiro == point->listaPassageiros[i].iden_psg){
                    point->listaPassagem[ind].identificador_passageiro = aux_passageiro;
                    indicador = 1;
                    break;
                }
            }
            if(indicador == -1){
                printf("\nPassageiro nao encontrado!\n");
            } else {
                printf("\nAlteracao concluida!\n");
            }
        }

        if(opc_passagem == 2){
            int aux_voo, ind_voo = -1;
            int indicador_antigo = point->listaPassagem[ind].identificador_voo;

            printf("\nInsira o novo identificador do voo: ");
            scanf("%d", &aux_voo);
            while(getchar() != '\n');

            for(int i = 0; i < *tam_voo; i++){
                if(aux_voo == point->listavoo[i].iden_voo){
                    point->listaPassagem[ind].identificador_voo = aux_voo;
                    ind_voo = 1;
                    break;
                }
            }
            if(ind_voo == -1){
                printf("\nVoo nao encontrado!\n");
            } else {
                for(int i = 0; i < *tam_voo; i++){
                    if(indicador_antigo == point->listavoo[i].iden_voo){
                        point->listavoo[i].qnt_psg -= 1;
                    }
                    if(point->listaPassagem[ind].identificador_voo == point->listavoo[i].iden_voo){
                        point->listavoo[i].qnt_psg += 1;
                    }
                }
                printf("\nPassagem alterada!\n");
            }
        }

        if(opc_passagem == 3){
            float aux_valor;
            printf("\nInsira o novo valor da passagem: ");
            scanf("%f", &aux_valor);
            while(getchar() != '\n');
            if(aux_valor < 0){
                printf("\nValor invalido!\n");
            } else {
                point->listaPassagem[ind].valor = aux_valor;
                printf("\nPassagem alterada!\n");
            }
        }

        if(opc_passagem == 4){
            int aux_dia, aux_mes, aux_ano;
            printf("\nInsira a nova data de venda (dia/mes/ano): ");
            scanf("%d/%d/%d", &aux_dia, &aux_mes, &aux_ano);
            while(getchar() != '\n');
            point->listaPassagem[ind].venda.dia = aux_dia;
            point->listaPassagem[ind].venda.mes = aux_mes;
            point->listaPassagem[ind].venda.ano = aux_ano;
            printf("\nPassagem alterada!\n");
            }

    }while(opc_passagem != 0);
}
void excluirPassagem(aeroporto *point,int *tam_voo,int *tam_passagem){
    if(*tam_passagem==0){
        printf("\nNao existem passagens a serem excluidas!\n");
        return;
    }
    int ind_passagem, posicao = -1;
    printf("Insira o numero da passagem que deseja excluir: ");
    scanf("%d", &ind_passagem);
    while(getchar() != '\n');

    for(int i = 0; i < *tam_passagem; i++){
        if(point->listaPassagem[i].num_passagem == ind_passagem){
            posicao = i;
            break;
        }
    }

    if(posicao == -1){
        printf("\nPassagem nao encontrada!\n");
        return;
    }

    printf("\n=== Dados da Passagem a ser excluida ===\n");
    printf("Numero da passagem: %d\n", point->listaPassagem[posicao].num_passagem);
    printf("Identificador do passageiro: %d\n", point->listaPassagem[posicao].identificador_passageiro);
    printf("Identificador do voo: %d\n", point->listaPassagem[posicao].identificador_voo);
    printf("Valor: %.2f\n", point->listaPassagem[posicao].valor);
    printf("Data da venda: %02d/%02d/%d\n",point->listaPassagem[posicao].venda.dia,point->listaPassagem[posicao].venda.mes,point->listaPassagem[posicao].venda.ano);
    printf("==========================\n");

    for(int i = 0; i < *tam_voo; i++){
        if(point->listavoo[i].iden_voo == point->listaPassagem[posicao].identificador_voo){
            point->listavoo[i].qnt_psg -= 1;
            break;
        }
    }

    for(int i = posicao; i < *tam_passagem - 1; i++){
        point->listaPassagem[i] = point->listaPassagem[i+1];
    }

    (*tam_passagem)--;

    if(*tam_passagem == 0){
        free(point->listaPassagem);
        point->listaPassagem = NULL;
    } else {
        point->listaPassagem = realloc(point->listaPassagem, (*tam_passagem) * sizeof(passagem));
    }
    printf("\nPassagem excluida com sucesso!\n");
}
void consultarPassagem(aeroporto *point,int *tam_passagem){
    int opcao;
    do{
        printf("\n1 - Buscar passagem pelo numero\n");
        printf("2 - Mostrar todas as passagens\n");
        printf("0 - Sair\n");
        printf("Insira uma das opcoes acima: ");
        scanf("%d", &opcao);
        while(getchar() != '\n');

        if(opcao == 1){
            int num_pasg, ind = -1;
            printf("\nInsira o numero da passagem: ");
            scanf("%d", &num_pasg);
            while(getchar() != '\n');

            for(int i = 0; i < *tam_passagem; i++){
                if(num_pasg == point->listaPassagem[i].num_passagem){
                    ind = i;
                    break;
                }
            }

            if(ind == -1){
                printf("\nPassagem nao encontrada!\n");
            } else {
                printf("\n=== Dados da Passagem ===\n");
                printf("Numero da passagem: %d\n", point->listaPassagem[ind].num_passagem);
                printf("Identificador do passageiro: %d\n", point->listaPassagem[ind].identificador_passageiro);
                printf("Identificador do voo: %d\n", point->listaPassagem[ind].identificador_voo);
                printf("Valor: %.2f\n", point->listaPassagem[ind].valor);
                printf("Data da venda: %02d/%02d/%d\n",point->listaPassagem[ind].venda.dia,point->listaPassagem[ind].venda.mes,point->listaPassagem[ind].venda.ano);
                printf("==========================\n");
            }
        }

        if(opcao == 2){
            if(*tam_passagem == 0){
                printf("\nAinda nao foram inseridas passagens!\n");
            } else {
                for(int i = 0; i < *tam_passagem; i++){
                    printf("\n=== Dados da %d Passagem da Lista ===\n", i+1);
                    printf("Numero da passagem: %d\n", point->listaPassagem[i].num_passagem);
                    printf("Identificador do passageiro: %d\n", point->listaPassagem[i].identificador_passageiro);
                    printf("Identificador do voo: %d\n", point->listaPassagem[i].identificador_voo);
                    printf("Valor: %.2f\n", point->listaPassagem[i].valor);
                    printf("Data da venda: %02d/%02d/%d\n",point->listaPassagem[i].venda.dia,point->listaPassagem[i].venda.mes,point->listaPassagem[i].venda.ano);
                    printf("==========================\n");
                }
            }
        }

    }while(opcao != 0);
}

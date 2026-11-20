#include <stdio.h>
#include "estruturas.h"

void incluirVoo(aeroporto *point, int *tam_voo){
    point->listavoo = realloc(point->listavoo, (*tam_voo + 1) * sizeof(voo));
    if(point->listavoo == NULL){
        printf("\nErro ao alocar memoria!\n");
        return;
    }

    int i = *tam_voo;

    printf("\nInsira o identificador do voo: ");
    scanf("%d", &point->listavoo[i].iden_voo);
    while(getchar() != '\n');

    for(int j=0;j<*tam_voo;j++){
        if(point->listavoo[j].iden_voo==point->listavoo[i].iden_voo){
            printf("\nIdentificador de voo ja utilizado! Tente novamente!\n");
            return;
        }
    }

    printf("Insira o numero da aeronave: ");
    scanf("%d", &point->listavoo[i].num_aeronave);
    while(getchar() != '\n');

    printf("Insira o nome da empresa: ");
    scanf(" %[^\n]", point->listavoo[i].empresa);

    printf("Insira a origem do voo: ");
    scanf(" %[^\n]", point->listavoo[i].origem);

    printf("Insira o destino do voo: ");
    scanf(" %[^\n]", point->listavoo[i].destino);

    printf("Insira a data de partida (dia/mes/ano): ");
    scanf("%d/%d/%d", &point->listavoo[i].partida.dia,&point->listavoo[i].partida.mes,&point->listavoo[i].partida.ano);
    while(getchar() != '\n');

    printf("Insira o horario de saida (hora:minuto): ");
    scanf("%d:%d", &point->listavoo[i].saida.hora,&point->listavoo[i].saida.minutos);
    while(getchar() != '\n');

    printf("Insira a capacidade maxima de passageiros no voo: ");
    scanf("%d", &point->listavoo[i].qnt_max_passageiros);
    while(getchar() != '\n');

    point->listavoo[i].qnt_psg = 0;

    (*tam_voo)++;
    printf("\nVoo incluido!\n");
}

void consultarVoo(aeroporto *point,int *tam_voo){
    int esc;
    do{
        printf("\n1 - Buscar voo pelo identificador\n");
        printf("2 - Mostrar todos os voos\n");
        printf("0 - Sair\n");
        printf("Escolha uma das opcoes acima: ");
        scanf("%d", &esc);
        while(getchar() != '\n');

        if(esc == 1){
            int identificador, aux = -1;
            printf("Insira o identificador: ");
            scanf("%d", &identificador);
            while(getchar() != '\n');

            for(int i = 0; i < *tam_voo; i++){
                if(identificador == point->listavoo[i].iden_voo){
                    printf("\n=== Dados do Voo ===\n");
                    printf("Identificador: %d\n", point->listavoo[i].iden_voo);
                    printf("Numero da aeronave: %d\n", point->listavoo[i].num_aeronave);
                    printf("Empresa: %s\n", point->listavoo[i].empresa);
                    printf("Origem: %s\n", point->listavoo[i].origem);
                    printf("Destino: %s\n", point->listavoo[i].destino);
                    printf("Data de partida: %02d/%02d/%d\n",point->listavoo[i].partida.dia,point->listavoo[i].partida.mes,point->listavoo[i].partida.ano);
                    printf("Horario de saida: %02d:%02d\n",point->listavoo[i].saida.hora,point->listavoo[i].saida.minutos);
                    printf("Capacidade maxima de passageiros: %d\n", point->listavoo[i].qnt_max_passageiros);
                    printf("Quantidade de passageiros presentes no voo: %d\n", point->listavoo[i].qnt_psg);
                    printf("=====================\n");
                    aux = 1;
                    break;
                }
            }
            if(aux == -1){
                printf("Voo nao encontrado!\n");
            }
        }

        if(esc == 2){
            if(*tam_voo == 0){
                printf("\nAinda nao foram inseridos voos!\n");
            } else {
                for(int i = 0; i < *tam_voo; i++){
                    printf("\n=== Dados do %d Voo da Lista ===\n", i+1);
                    printf("Identificador: %d\n", point->listavoo[i].iden_voo);
                    printf("Numero da aeronave: %d\n", point->listavoo[i].num_aeronave);
                    printf("Empresa: %s\n", point->listavoo[i].empresa);
                    printf("Origem: %s\n", point->listavoo[i].origem);
                    printf("Destino: %s\n", point->listavoo[i].destino);
                    printf("Data de partida: %02d/%02d/%d\n",point->listavoo[i].partida.dia,point->listavoo[i].partida.mes,point->listavoo[i].partida.ano);
                    printf("Horario de saida: %02d:%02d\n",point->listavoo[i].saida.hora,point->listavoo[i].saida.minutos);
                    printf("Capacidade maxima de passageiros: %d\n", point->listavoo[i].qnt_max_passageiros);
                    printf("Quantidade de passageiros: %d\n", point->listavoo[i].qnt_psg);
                    printf("=====================\n");
                }
            }
        }

    }while(esc != 0);
}

void excluirVoo(aeroporto *point,int *tam_voo, int *tam_passagem){
    int num_voo, ind = -1;
    if(*tam_voo == 0){
        printf("\nNao possuem voos a serem excluidos!\n");
        return;
    }

    printf("\nInsira o identificador do voo que deseja excluir: ");
    scanf("%d", &num_voo);
    while(getchar() != '\n');

    for(int i = 0; i < *tam_voo; i++){
        if(num_voo == point->listavoo[i].iden_voo){
            ind = i;
            break;
        }
    }

    if(ind == -1){
        printf("Voo nao encontrado!\n");
        return;
    }

    printf("==== Excluindo Voo ====\n");
    printf("Identificador: %d\n", point->listavoo[ind].iden_voo);
    printf("Numero da aeronave: %d\n", point->listavoo[ind].num_aeronave);
    printf("Empresa: %s\n", point->listavoo[ind].empresa);
    printf("Origem: %s\n", point->listavoo[ind].origem);
    printf("Destino: %s\n", point->listavoo[ind].destino);
    printf("Data de partida: %02d/%02d/%d\n",point->listavoo[ind].partida.dia,point->listavoo[ind].partida.mes,point->listavoo[ind].partida.ano);
    printf("Horario de saida: %02d:%02d\n",point->listavoo[ind].saida.hora,point->listavoo[ind].saida.minutos);
    printf("Capacidade maxima de passageiros: %d\n", point->listavoo[ind].qnt_max_passageiros);
    printf("Quantidade de passageiros: %d\n", point->listavoo[ind].qnt_psg);
    printf("=====================\n\n");

    int encontrou_passagem = -1;
    for(int i = 0; i < *tam_passagem; ){
        if(num_voo == point->listaPassagem[i].identificador_voo){
            encontrou_passagem = 1;
            printf("\n=== Passagem a ser excluida ===\n");
            printf("Numero da passagem: %d\n", point->listaPassagem[i].num_passagem);
            printf("Identificador do passageiro: %d\n", point->listaPassagem[i].identificador_passageiro);
            printf("Identificador do voo: %d\n", point->listaPassagem[i].identificador_voo);
            printf("Valor: %.2f\n", point->listaPassagem[i].valor);
            printf("Data da venda: %02d/%02d/%d\n",point->listaPassagem[i].venda.dia,point->listaPassagem[i].venda.mes,point->listaPassagem[i].venda.ano);
            printf("===============================\n");

            for(int k = i; k < *tam_passagem - 1; k++){
                point->listaPassagem[k] = point->listaPassagem[k+1];
            }
            (*tam_passagem)--;

            if(*tam_passagem == 0){
                free(point->listaPassagem);
                point->listaPassagem = NULL;
            } else {
                point->listaPassagem = realloc(point->listaPassagem, (*tam_passagem) * sizeof(passagem));
            }
        } else {
            i++;
        }
    }

    if(encontrou_passagem==-1){
        printf("\nNenhuma passagem desse voo foi encontrada!\n");
    }

    for(int i = ind; i < *tam_voo - 1; i++){
        point->listavoo[i] = point->listavoo[i+1];
    }
    (*tam_voo)--;

    if(*tam_voo == 0){
        free(point->listavoo);
        point->listavoo = NULL;
    } else {
        point->listavoo = realloc(point->listavoo, (*tam_voo) * sizeof(voo));
    }
    printf("\nVoo excluido!\n");
}

void alterarVoo(aeroporto *point,int *tam_voo){
    if(*tam_voo == 0){
        printf("\nNao existem voos cadastrados!\n");
        return;
    }

    int ind_voo, pos = -1;
    printf("Insira o identificador do voo que deseja alterar: ");
    scanf("%d", &ind_voo);
    while(getchar() != '\n');

    for(int i = 0; i < *tam_voo; i++){
        if(ind_voo == point->listavoo[i].iden_voo){
            pos = i;
            break;
        }
    }

    if(pos == -1){
        printf("Voo nao encontrado!\n");
        return;
    }

    printf("\n=== Dados do Voo ===\n");
    printf("Identificador: %d\n", point->listavoo[pos].iden_voo);
    printf("Numero da aeronave: %d\n", point->listavoo[pos].num_aeronave);
    printf("Empresa: %s\n", point->listavoo[pos].empresa);
    printf("Origem: %s\n", point->listavoo[pos].origem);
    printf("Destino: %s\n", point->listavoo[pos].destino);
    printf("Data de partida: %02d/%02d/%d\n",point->listavoo[pos].partida.dia,point->listavoo[pos].partida.mes,point->listavoo[pos].partida.ano);
    printf("Horario de saida: %02d:%02d\n",point->listavoo[pos].saida.hora,point->listavoo[pos].saida.minutos);
    printf("Capacidade maxima de passageiros: %d\n", point->listavoo[pos].qnt_max_passageiros);
    printf("Quantidade de passageiros: %d\n", point->listavoo[pos].qnt_psg);
    printf("=====================\n");

    int opcao;
    do{
        printf("\n1 - Numero da aeronave\n");
        printf("2 - Empresa\n");
        printf("3 - Origem\n");
        printf("4 - Destino\n");
        printf("5 - Data de partida\n");
        printf("6 - Horario de partida\n");
        printf("7 - Capacidade maxima de passageiros\n");
        printf("0 - Sair\n");
        printf("Qual dos itens acima deseja alterar: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Novo numero da aeronave: ");
            scanf("%d", &point->listavoo[pos].num_aeronave);
            while(getchar() != '\n');
        }

        if(opcao == 2){
            printf("Nova empresa: ");
            scanf(" %[^\n]", point->listavoo[pos].empresa);
        }

        if(opcao == 3){
            printf("Nova origem: ");
            scanf(" %[^\n]", point->listavoo[pos].origem);
        }

        if(opcao == 4){
            printf("Novo destino: ");
            scanf(" %[^\n]", point->listavoo[pos].destino);
        }

        if(opcao == 5){
            printf("Nova data de partida (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &point->listavoo[pos].partida.dia,&point->listavoo[pos].partida.mes,&point->listavoo[pos].partida.ano);
            while(getchar() != '\n');
        }

        if(opcao == 6){
            printf("Novo horario de partida (hh:mm): ");
            scanf("%d:%d", &point->listavoo[pos].saida.hora,&point->listavoo[pos].saida.minutos);
            while(getchar() != '\n');
        }

        if(opcao == 7){
            printf("Nova capacidade maxima do voo: ");
            scanf("%d", &point->listavoo[pos].qnt_max_passageiros);
            while(getchar() != '\n');
        }
        printf("\nVoo Alterado!\n");

    }while(opcao!=0);
}

#include <stdio.h>
#include "estruturas.h"

void incluirPassageiro(aeroporto *point,int *tam_passageiro){
    point->listaPassageiros = realloc(point->listaPassageiros, (*tam_passageiro + 1) * sizeof(passageiro));
    if(point->listaPassageiros == NULL){
        printf("\nErro ao alocar memoria!\n");
        return;
    }

    int i = *tam_passageiro;

    printf("Insira o identificador do passageiro: ");
    scanf("%d", &point->listaPassageiros[i].iden_psg);
    while(getchar() != '\n');

    for(int j=0;j<*tam_passageiro;j++){
        if(point->listaPassageiros[j].iden_psg==point->listaPassageiros[i].iden_psg){
            printf("\nIdentificador de passageiro ja utilizado! Tente novamente\n");
            return;
        }
    }

    printf("Insira o nome do passageiro: ");
    scanf(" %[^\n]", point->listaPassageiros[i].nome);

    printf("Insira o CPF do passageiro: ");
    scanf("%d", &point->listaPassageiros[i].cpf);
    while(getchar() != '\n');

    printf("Insira o telefone do passageiro: ");
    scanf("%d", &point->listaPassageiros[i].telefone);
    while(getchar() != '\n');

    printf("Insira o sexo do passageiro (M/F): ");
    scanf(" %c", &point->listaPassageiros[i].sexo);
    while(getchar() != '\n');

    printf("Insira o pais: ");
    scanf(" %[^\n]", point->listaPassageiros[i].end_psg.pais);

    printf("Insira a cidade: ");
    scanf(" %[^\n]", point->listaPassageiros[i].end_psg.cidade);

    printf("Insira o bairro: ");
    scanf(" %[^\n]", point->listaPassageiros[i].end_psg.bairro);

    printf("Insira a rua: ");
    scanf(" %[^\n]", point->listaPassageiros[i].end_psg.rua);

    printf("Insira o numero da casa: ");
    scanf("%d", &point->listaPassageiros[i].end_psg.num_casa);
    while(getchar() != '\n');

    (*tam_passageiro)++;

    printf("\nPassageiro incluido com sucesso!\n");
}
void alterarPassageiro(aeroporto *point,int *tam_passageiro){
    if(*tam_passageiro == 0){
        printf("\nNao existem passageiros cadastrados!\n");
        return;
    }

    int ind_passageiro, pos = -1;
    printf("Insira o identificador do passageiro que deseja alterar: ");
    scanf("%d", &ind_passageiro);
    while(getchar() != '\n');

    for(int i = 0; i < *tam_passageiro; i++){
        if(ind_passageiro == point->listaPassageiros[i].iden_psg){
            pos = i;
            break;
        }
    }

    if(pos == -1){
        printf("\nPassageiro nao encontrado!\n");
        return;
    }

    int opc_passageiro;
    do{
        printf("\n=== Menu de Alteracao do Passageiro ===\n");
        printf("1 - Alterar nome\n");
        printf("2 - Alterar CPF\n");
        printf("3 - Alterar endereco\n");
        printf("4 - Alterar telefone\n");
        printf("5 - Alterar sexo\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc_passageiro);

        if(opc_passageiro == 1){
            printf("Novo nome: ");
            scanf(" %[^\n]", point->listaPassageiros[pos].nome);
        }

        if(opc_passageiro == 2){
            printf("Novo CPF: ");
            scanf("%d", &point->listaPassageiros[pos].cpf);
        }

        if(opc_passageiro == 3){
            printf("Novo pais: ");
            scanf(" %[^\n]", point->listaPassageiros[pos].end_psg.pais);
            printf("Nova cidade: ");
            scanf(" %[^\n]", point->listaPassageiros[pos].end_psg.cidade);
            printf("Novo bairro: ");
            scanf(" %[^\n]", point->listaPassageiros[pos].end_psg.bairro);
            printf("Nova rua: ");
            scanf(" %[^\n]", point->listaPassageiros[pos].end_psg.rua);
            printf("Novo numero da casa: ");
            scanf("%d", &point->listaPassageiros[pos].end_psg.num_casa);
            while(getchar() != '\n');
        }

        if(opc_passageiro == 4){
            printf("Novo telefone: ");
            scanf("%d", &point->listaPassageiros[pos].telefone);
            while(getchar() != '\n');
        }

        if(opc_passageiro == 5){
            printf("Novo sexo (M/F): ");
            scanf(" %c", &point->listaPassageiros[pos].sexo);
            while(getchar() != '\n');
        }

        printf("\nAlteracao concluida!\n");
    }while(opc_passageiro != 0);
}
void excluirPassageiro(aeroporto *point,int *tam_voo,int *tam_passagem,int *tam_passageiro){
    if(*tam_passageiro==0){
        printf("\nNao existem passageiros a serem excluidos!\n");
        return;
    }
    int ind_passageiro, pos_psg = -1;
    printf("Insira o identificador do passageiro que deseja excluir: ");
    scanf("%d", &ind_passageiro);
    while(getchar() != '\n');

    for(int i = 0; i < *tam_passageiro; i++){
        if(ind_passageiro == point->listaPassageiros[i].iden_psg){
            pos_psg = i;
            break;
        }
    }

    if(pos_psg == -1){
        printf("\nPassageiro nao encontrado!\n");
        return;
    }

    printf("\n==== Passageiro a ser excluido ====\n");
    printf("Identificador: %d\n", point->listaPassageiros[pos_psg].iden_psg);
    printf("Nome: %s\n", point->listaPassageiros[pos_psg].nome);
    printf("CPF: %d\n", point->listaPassageiros[pos_psg].cpf);
    printf("Telefone: %d\n", point->listaPassageiros[pos_psg].telefone);
    printf("Sexo: %c\n", point->listaPassageiros[pos_psg].sexo);
    printf("Endereco: %s, %s, %s, %s, %d\n",point->listaPassageiros[pos_psg].end_psg.pais,point->listaPassageiros[pos_psg].end_psg.cidade,point->listaPassageiros[pos_psg].end_psg.bairro,point->listaPassageiros[pos_psg].end_psg.rua,point->listaPassageiros[pos_psg].end_psg.num_casa);
    printf("===================================\n");

    int contador_passagem = 0;
    for(int i = 0; i < *tam_passagem; ){
        if(point->listaPassagem[i].identificador_passageiro == ind_passageiro){
            contador_passagem++;
            printf("\n=== Passagem %d a ser excluida ===\n", contador_passagem);
            printf("Numero da passagem: %d\n", point->listaPassagem[i].num_passagem);
            printf("Identificador do voo: %d\n", point->listaPassagem[i].identificador_voo);
            printf("Valor: %.2f\n", point->listaPassagem[i].valor);
            printf("Data da venda: %02d/%02d/%d\n",point->listaPassagem[i].venda.dia,point->listaPassagem[i].venda.mes,point->listaPassagem[i].venda.ano);
            printf("-----------------------------------\n");

            for(int v = 0; v < *tam_voo; v++){
                if(point->listavoo[v].iden_voo == point->listaPassagem[i].identificador_voo){
                    point->listavoo[v].qnt_psg--;
                    break;
                }
            }

            for(int j = i; j < *tam_passagem - 1; j++){
                point->listaPassagem[j] = point->listaPassagem[j+1];
            }
            (*tam_passagem)--;

            point->listaPassagem = realloc(point->listaPassagem, (*tam_passagem) * sizeof(passagem));
        } else {
            i++;
        }
    }

    for(int i = pos_psg; i < *tam_passageiro - 1; i++){
        point->listaPassageiros[i] = point->listaPassageiros[i+1];
    }
    (*tam_passageiro)--;
    if(*tam_passageiro==0){
        free(point->listaPassageiros);
        point->listaPassageiros=NULL;
    }else{
    point->listaPassageiros = realloc(point->listaPassageiros, (*tam_passageiro) * sizeof(passageiro));
    }
    printf("\nExclusao concluida!\n");

}
void mostrarPassageiro(aeroporto *point,int *tam_passageiro){
int opc_passageiro;
    do{
        printf("\n1 - Buscar pelo identificador do passageiro\n");
        printf("2 - Mostrar todos passageiros\n");
        printf("0 - Sair\n");
        printf("Escolha uma das opcoes acima: ");
        scanf("%d", &opc_passageiro);

        if(opc_passageiro == 1){
            int ind_passageiro, pos = -1;
            printf("Insira o identificador do passageiro: ");
            scanf("%d", &ind_passageiro);
            while(getchar() != '\n');


            for(int i = 0; i < *tam_passageiro; i++){
                if(ind_passageiro == point->listaPassageiros[i].iden_psg){
                    pos = i;
                    break;
                }
            }

            if(pos == -1){
                printf("\nPassageiro nao encontrado!\n");
            } else {
                printf("\n=== Dados do Passageiro ===\n");
                printf("Identificador: %d\n", point->listaPassageiros[pos].iden_psg);
                printf("Nome: %s\n", point->listaPassageiros[pos].nome);
                printf("CPF: %d\n", point->listaPassageiros[pos].cpf);
                printf("Telefone: %d\n", point->listaPassageiros[pos].telefone);
                printf("Sexo: %c\n", point->listaPassageiros[pos].sexo);
                printf("Endereco: %s, %s, %s, %s, %d\n",point->listaPassageiros[pos].end_psg.pais,point->listaPassageiros[pos].end_psg.cidade,point->listaPassageiros[pos].end_psg.bairro,point->listaPassageiros[pos].end_psg.rua,point->listaPassageiros[pos].end_psg.num_casa);
                printf("============================\n");
            }
        }

        if(opc_passageiro == 2){
            if(*tam_passageiro == 0){
                printf("\nAinda nao existem passageiros cadastrados!\n");
            } else {
                for(int i = 0; i < *tam_passageiro; i++){
                    printf("\n==== Passageiro %d da lista ====\n", i+1);
                    printf("Identificador: %d\n", point->listaPassageiros[i].iden_psg);
                    printf("Nome: %s\n", point->listaPassageiros[i].nome);
                    printf("CPF: %d\n", point->listaPassageiros[i].cpf);
                    printf("Telefone: %d\n", point->listaPassageiros[i].telefone);
                    printf("Sexo: %c\n", point->listaPassageiros[i].sexo);
                    printf("Endereco: %s, %s, %s, %s, %d\n",point->listaPassageiros[i].end_psg.pais,point->listaPassageiros[i].end_psg.cidade,point->listaPassageiros[i].end_psg.bairro,point->listaPassageiros[i].end_psg.rua,point->listaPassageiros[i].end_psg.num_casa);
                    printf("============================\n");
                }
            }
        }

    }while(opc_passageiro != 0);
}

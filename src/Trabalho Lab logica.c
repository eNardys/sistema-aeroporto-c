#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funcoes de voo.c"
#include "Funcoes de passageiros.c"
#include "Funcoes de passagem.c"
#include "Funcoes de relatorio.c"
void inic(aeroporto *point){
    point->listaPassageiros=NULL;
    point->listaPassagem=NULL;
    point->listavoo=NULL;
}
int main(){
    aeroporto a;
    inic(&a);
    int tam_passageiros=0, tam_passagem=0, tam_voos=0;
    int opc;
    do{
        printf("1-Voos\n2-Passagens\n3-Passageiro\n4-Relatorio\n0-Sair\n");
        printf("Escolha uma das opcoes acima: ");
        scanf("%d",&opc);
        while(getchar() != '\n');

        if(opc==1){
            int opc_voo;
            do{
                printf("\n1-Incluir voo\n2-Alterar voo\n3-Excluir voo\n4-Consultar voo\n0-Sair\n");
                printf("Escolha uma das opcoes acima: ");
                scanf("%d",&opc_voo);
                while(getchar() != '\n');
                if(opc_voo==1){
                    incluirVoo(&a,&tam_voos);
                }
                if(opc_voo==2){
                    alterarVoo(&a,&tam_voos);
                }
                if(opc_voo==3){
                    excluirVoo(&a,&tam_voos,&tam_passagem);
                }
                if(opc_voo==4){
                    consultarVoo(&a,&tam_voos);
                }
            }while(opc_voo!=0);
        }

        if(opc==2){
            int opc_passagem;
            do{
                printf("\n1-Incluir passagem\n2-Alterar passagem\n3-Excluir passagem\n4-Mostrar passagem\n0-Sair\n");
                printf("Escolha uma das opcoes acima: ");
                scanf("%d",&opc_passagem);
                while(getchar() != '\n');
                if(opc_passagem==1){
                    incluirPassagem(&a,&tam_passagem,&tam_voos,&tam_passageiros);
                }
                if(opc_passagem==2){
                    alterarPassagem(&a,&tam_voos,&tam_passagem,&tam_passageiros);
                }
                if(opc_passagem==3){
                    excluirPassagem(&a,&tam_voos,&tam_passagem);
                }
                if(opc_passagem==4){
                    consultarPassagem(&a,&tam_passagem);
                }
            }while(opc_passagem!=0);
        }

        if(opc==3){
            int opc_passageiro;
            do{
                printf("\n1-Incluir passageiro\n2-Alterar passageiro\n3-Excluir passageiro\n4-Mostrar passageiro\n0-Sair\n");
                printf("Escolha uma das opcoes acima: ");
                scanf("%d",&opc_passageiro);
                while(getchar() != '\n');
                if(opc_passageiro==1){
                    incluirPassageiro(&a,&tam_passageiros);
                }
                if(opc_passageiro==2){
                    alterarPassageiro(&a,&tam_passageiros);
                }
                if(opc_passageiro==3){
                    excluirPassageiro(&a,&tam_voos,&tam_passagem,&tam_passageiros);
                }
                if(opc_passageiro==4){
                    mostrarPassageiro(&a,&tam_passageiros);
                }
            }while(opc_passageiro!=0);
        }

        if(opc==4){
            int opc_relatorio;
            do{
                printf("\n1-Quantidade de passagens por voo\n2-Quantidade do voos por empresa\n3-Lista de passageiros por voo\n4-Pesquisar voos pela empresa\n5-Passagens reservadas para um passageiro\n0-Sair\n");
                printf("Escolha uma das opcoes acima: ");
                scanf("%d",&opc_relatorio);
                while(getchar() != '\n');
                if(opc_relatorio==1){
                    PassagensPorVoo(&a,&tam_voos);
                }
                if(opc_relatorio==2){
                    NumeroVoosPorEmpresa(&a,&tam_voos);
                }
                if(opc_relatorio==3){
                    PassageirosPorVoo(&a,&tam_voos,&tam_passageiros,&tam_passagem);
                }
                if(opc_relatorio==4){
                    listaVoosPorEmpresa(&a,&tam_voos);
                }
                if(opc_relatorio==5){
                    PassagensReservadas(&a,&tam_passagem,&tam_passageiros,&tam_voos);
                }
            }while(opc_relatorio!=0);
        }
    printf("\n");
    }while(opc!=0);
    free(a.listaPassageiros);
    free(a.listaPassagem);
    free(a.listavoo);
return 0;
}

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct{
    int dia;
    int mes;
    int ano;
} data;

typedef struct{
    int hora;
    int minutos;
} horario;

typedef struct{
    char pais[30];
    char cidade[30];
    char bairro[30];
    char rua[30];
    int num_casa;
} endereco;

typedef struct{
    int iden_voo;
    int num_aeronave;
    char empresa[50];
    char origem[50];
    char destino[50];
    data partida;
    horario saida;
    int qnt_max_passageiros;
    int qnt_psg;
} voo;

typedef struct{
    int iden_psg;
    char nome[50];
    int cpf;
    endereco end_psg;
    int telefone;
    char sexo;
} passageiro;

typedef struct{
    int num_passagem;
    int identificador_passageiro;
    int identificador_voo;
    float valor;
    data venda;
} passagem;

typedef struct{
    passageiro *listaPassageiros;
    passagem *listaPassagem;
    voo *listavoo;
}aeroporto;

#endif

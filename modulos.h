#ifndef __MODULOS_H_
#define __MODULOS_H_

typedef struct
{
    char nome[50];
    char nascimento[11];
    char cpf[15];
    char telefone[18];
    char cidade[30];
}CLIENTE;

typedef struct
{
    char nome[50];
    char nascimento[11];
    char cpf[15];
    char telefone[18];
    char cargo[30];
    char data_ingresso[11];
}FUNCIONARIO;

void menu();
void cadastro_funcinario();
void salvar_funcionario(FUNCIONARIO funcionario);
void mostrar_funcionario();

#endif // MODULOS_H_INCLUDED

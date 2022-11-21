#ifndef __MODULOS_H_
#define __MODULOS_H_

typedef struct
{
    char nome[30];
    char nascimento[11];
    char cpf[15];
    char telefone[18];
    char cidade[30];
}CLIENTE;

typedef struct
{
    char nome[30];
    char nascimento[11];
    char cpf[15];
    char telefone[18];
    char cargo[30];
    char data_ingresso[11];
}FUNCIONARIO;

typedef struct
{
    char nome[30];
    char categoria[15];
    float preco;
}PRODUTO;

void tela_de_login();
void menu_inicial();
void menu_relatorios();
void cadastro_cliente(int opcao);
void cadastro_funcinario(int opcao);
void cadastro_produto(int opcao);
void salvar_cliente(CLIENTE cliente);
void salvar_funcionario(FUNCIONARIO funcionario);
void salvar_produto(PRODUTO produto);
void exibir_clientes();
void exibir_funcionarios();
void exibir_produtos();

#endif // MODULOS_H_INCLUDED

#include<stdio.h>
#include<locale.h>
#include"modulos.h"

void tela_de_login()
{
    char login[15] = "admin", senha[16] = "admin", login1[15], senha1[16];
    int login_efetuado = 0;

    while(!login_efetuado)
    {
        system("cls");
        puts("-=-=-=-=-=-=- TELA DE LOGIN -=-=-=-=-=-=-");
        puts("NOME DE USU�RIO: ");
        scanf("%s", login1);

        puts("\nSENHA: ");
        scanf("%s", senha1);
        puts("-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=--=-=-");

        if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0)
        {
            puts("\nLOGADO! ENTRANDO NO SISTEMA EM INSTANTES...\n\n");
            Sleep (1500);
            login_efetuado = 1;
        }else
        {
            puts("\nUSU�RIO OU SENHA INCORRETOS! TENTE NOVAMENTE EM INSTANES.\n\n");
            Sleep (1500);
        }
    }
}


void menu_inicial() // FUN��O PRA EXIBIR O MENU INICIAL DE OP��ES.
{
    system("cls");
    puts("-=-=-=-=-=- SISTEMA DE GEST�O -=-=-=-=-=-");
    puts("[1] - CADASTRAR CLIENTE");
    puts("[2] - CADASTRAR FUNCION�RIO");
    puts("[3] - CADASTRAR PRODUTOS");
    puts("[4] - RELAT�RIOS");
    puts("[5] - SAIR");
    puts("-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=-=-=-=-=-");
    puts("ESOLHA UMA OP��O: ");
}


void menu_relatorios() // FUN��O PARA EXIBIR O MENU DE RELAT�RIOS.
{
    system("cls");
    puts("-=-=-=-=-=-=-=-=- RELAT�RIOS -=-=-=-=-=-=-=-=-");
    puts("[1] - EXIBIR CLIENTES CADASTRADOS");
    puts("[2] - EXIBIR FUNCIN�RIOS CADASTRADOS");
    puts("[3] - EXIBIR PRODUTOS CADASTRADOS");
    puts("[4] - VOLTAR");
    puts("-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-");
    puts("ESOLHA UMA OP��O: ");
}


void cadastro_cliente(int opcao) // FUN��O PARA CADASTRAR CLIENTES E SALVAR OS DADOS.
{
    CLIENTE cliente;

    do
    {
        system("cls");
        puts("-=-=-=-=-=- CADASTRO DE CLIENTE -=-=-=-=-=-");
        getchar();
        puts("NOME DO CLIENTE: ");
        scanf("%[^\n]s", &cliente.nome);

        getchar();
        puts("\nDATA DE NASCIMNETO: ");
        scanf("%[^\n]s", &cliente.nascimento);

        getchar();
        puts("\nCPF: ");
        scanf("%s", &cliente.cpf);

        getchar();
        puts("\nTELEFONE: ");
        scanf("%[^\n]s", &cliente.telefone);

        getchar();
        puts("\nCIDADE ONDE MORA: ");
        scanf("%[^\n]s", &cliente.cidade);

        salvar_cliente(cliente); // DEPOIS DE CADASTRADO OS DADOS J� S�O SALVOS IMEDIATAMENTE.

        puts("\nDESEJA CONTINUAR? [1 - SIM/ 2 - N�O]");
        scanf("%d", &opcao);

    }while(opcao == 1);
}


void salvar_cliente(CLIENTE cliente) // FUN��O QUE RECEBE UMA VARI�VEL DO TIPO CLIENTE E SALVA OS DADOS EM UM ARQUIVO TXT.
{
    FILE *fp;
    fp = fopen("clientes.txt", "a");

    fprintf(fp, "%s, ", cliente.nome);
    fprintf(fp, "%s, ", cliente.nascimento);
    fprintf(fp, "%s, ", cliente.cpf);
    fprintf(fp, "%s, ", cliente.telefone);
    fprintf(fp, "%s\n", cliente.cidade);

    fclose(fp);
}


void cadastro_funcinario(int opcao) // FUN��O PARA CADASTRAR FUNCION�RIOS E SALVAR OS DADOS.
{
    FUNCIONARIO funcionario;

    do
    {
        system("cls");
        puts("-=-=-=-=-=- CADASTRO DE FUNCION�RIO -=-=-=-=-=-");
        getchar();
        puts("NOME DO FUNCION�RIO: ");
        scanf("%[^\n]s", &funcionario.nome);

        getchar();
        puts("\nDATA DE NASCIMENTO: ");
        scanf("%[^\n]s", &funcionario.nascimento);

        getchar();
        puts("\nCPF: ");
        scanf("%[^\n]s", &funcionario.cpf);

        getchar();
        puts("\nTELEFONE: ");
        scanf("%[^\n]s", &funcionario.telefone);


        getchar();
        puts("\nCARGO DO FUNCION�RIO: ");
        scanf("%[^\n]s", &funcionario.cargo);

        getchar();
        puts("\nDATA DE INGRESSO: ");
        scanf("%[^\n]s", &funcionario.data_ingresso);


        salvar_funcionario(funcionario); // DEPOIS DE CADASTRADO OS DADOS J� S�O SALVOS IMEDIATAMENTE.

        puts("\nDESEJA CONTINUAR? [1 - SIM/ 2 - N�O]");
        scanf("%d", &opcao);

    }while(opcao == 1);
}


void salvar_funcionario(FUNCIONARIO funcionario) // FUN��O QUE RECEBE UMA VARI�VEL DO TIPO FUNCION�RIO E SALVA OS DADOS EM UM ARQUIVO TXT.
{
    FILE *fp;
    fp = fopen("funcionarios.txt", "a");

    fprintf(fp, "%s, ", funcionario.nome);
    fprintf(fp, "%s, ", funcionario.nascimento);
    fprintf(fp, "%s, ", funcionario.cpf);
    fprintf(fp, "%s, ", funcionario.telefone);
    fprintf(fp, "%s, ", funcionario.cargo);
    fprintf(fp, "%s\n", funcionario.data_ingresso);

    fclose(fp);
}


void cadastro_produto(int opcao)
{
    PRODUTO produto;
    do
    {
        system("cls");
        puts("-=-=-=-=-=- CADASTRO DE PRODUTOS -=-=-=-=-=-");
        getchar();
        puts("NOME DO PRODUTO: ");
        scanf("%[^\n]s", &produto.nome);

        getchar();
        puts("\nCATEGORIA: ");
        scanf("%[^\n]s", &produto.categoria);

        getchar();
        puts("\nPRE�O: R$");
        scanf("%f", &produto.preco);

        salvar_produto(produto);

        puts("\nDESEJA CONTINUAR? [1 - SIM/ 2 - N�O]");
        scanf("%d", &opcao);
    }while(opcao == 1);
}


void salvar_produto(PRODUTO produto)
{
    FILE *fp;
    fp = fopen("produtos.txt", "a");

    fprintf(fp, "%s, ", produto.nome);
    fprintf(fp, "%s, ", produto.categoria);
    fprintf(fp, "%.2f\n", produto.preco);

    fclose(fp);
}


void exibir_clientes() // MOSTRA O CADASTRO DE CLIENTES OU DE FUNCION�RIO DE ACORDO COM A OP��O ESCOLHIDA NO MENU.
{
    FILE *fp;
    char linha[136];
    int id_cliente=0;

    fp = fopen("clientes.txt", "r");

    system("cls");
    puts("-=-=-=-=-=- CLIENTES CADASTRADOS -=-=-=-=-=-");
    while(fgets(linha, 136, fp) != NULL)
    {
        printf("ID:%d \n%s", id_cliente, linha);
        id_cliente += 1;
        puts("-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-");
    }
    puts("\n(aperte qualquer tecla para voltar!)");
    getchar();
    getchar();
}


void exibir_funcionarios()
{
    FILE *fp;
    char linha[136];
    int id_funcionario=0;

    fp = fopen("funcionarios.txt", "r");

    system("cls");
    puts("-=-=-=-=-=- FUNCION�RIOS CADASTRADOS -=-=-=-=-=-");
    while(fgets(linha, 136, fp) != NULL)
    {
        printf("ID:%d \n%s", id_funcionario, linha);
        id_funcionario += 1;
        puts("-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-");
    }
    puts("\n(aperte qualquer tecla para voltar!)");
    getchar();
    getchar();
}


void exibir_produtos()
{
    FILE *fp;
    char linha[50];
    int id_produto=0;

    fp = fopen("produtos.txt", "r");

    system("cls");
    puts("-=-=-=-=-=- PRODUTOS CADASTRADOS -=-=-=-=-=-");
    while(fgets(linha, 50, fp) != NULL)
    {
        printf("ID:%d \n%s", id_produto, linha);
        id_produto += 1;
        puts("-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-");
    }
    puts("\n(aperte qualquer tecla para voltar!)");
    getchar();
    getchar();
}

#include<stdio.h>
#include<locale.h>
#include"modulos.h"

void tela_de_login() // FUNÇÃO PARA LOGAR NO SISTEMA.
{
    char login[15] = "admin", senha[16] = "admin", login1[15], senha1[16];
    int login_efetuado = 0;

    while(!login_efetuado)
    {
        system("cls");
        puts("-=-=-=-=-=-=- TELA DE LOGIN -=-=-=-=-=-=-");
        puts("NOME DE USUÁRIO: ");
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
            puts("\nUSUÁRIO OU SENHA INCORRETOS! TENTE NOVAMENTE EM INSTANES.\n\n");
            Sleep (1500);
        }
    }
}


void menu_inicial() // FUNÇÃO PRA EXIBIR O MENU INICIAL DE OPÇÕES.
{
    system("cls");
    puts("-=-=-=-=-=- SISTEMA DE GESTÃO -=-=-=-=-=-");
    puts("[1] - CADASTRAR CLIENTE");
    puts("[2] - CADASTRAR FUNCIONÁRIO");
    puts("[3] - CADASTRAR PRODUTOS");
    puts("[4] - RELATÓRIOS");
    puts("[5] - SAIR");
    puts("-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=-=-=-=-=-");
    puts("ESOLHA UMA OPÇÃO: ");
}


void menu_relatorios() // FUNÇÃO PARA EXIBIR O MENU DE RELATÓRIOS.
{
    system("cls");
    puts("-=-=-=-=-=-=-=-=- RELATÓRIOS -=-=-=-=-=-=-=-=-");
    puts("[1] - EXIBIR CLIENTES CADASTRADOS");
    puts("[2] - EXIBIR FUNCINÁRIOS CADASTRADOS");
    puts("[3] - EXIBIR PRODUTOS CADASTRADOS");
    puts("[4] - EXIBIR O SALÁRIO ANUAL DOS FUNCIONÁRIOS");
    puts("[5] - VOLTAR");
    puts("-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-");
    puts("ESOLHA UMA OPÇÃO: ");
}


void cadastro_cliente(int opcao) // FUNÇÃO PARA CADASTRAR CLIENTES E SALVAR OS DADOS.
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

        salvar_cliente(cliente); // DEPOIS DE CADASTRADO OS DADOS JÁ SÃO SALVOS IMEDIATAMENTE.

        puts("\nDESEJA CONTINUAR? [1 - SIM/ 2 - NÃO]");
        scanf("%d", &opcao);
    }while(opcao == 1);
}


void salvar_cliente(CLIENTE cliente) // FUNÇÃO QUE RECEBE UMA VARIÁVEL DO TIPO CLIENTE E SALVA OS DADOS EM UM ARQUIVO TXT.
{
    FILE *fp;
    fp = fopen("clientes.txt", "a");

    fprintf(fp, "%s, %s, %s, %s, %s\n", cliente.nome, cliente.nascimento, cliente.cpf, cliente.telefone, cliente.cidade);
    fclose(fp);
}


void cadastro_funcinario(int opcao) // FUNÇÃO PARA CADASTRAR FUNCIONÁRIOS E SALVAR OS DADOS.
{
    FUNCIONARIO funcionario;

    do
    {
        system("cls");
        puts("-=-=-=-=-=- CADASTRO DE FUNCIONÁRIO -=-=-=-=-=-");
        getchar();
        puts("NOME DO FUNCIONÁRIO: ");
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
        puts("\nCARGO DO FUNCIONÁRIO: ");
        scanf("%[^\n]s", &funcionario.cargo);

        getchar();
        puts("\nSALÁRIO DO FUNCIONÁRIO R$: ");
        scanf("%f", &funcionario.salario);

        getchar();
        puts("\nDATA DE INGRESSO: ");
        scanf("%[^\n]s", &funcionario.data_ingresso);

        salvar_funcionario(funcionario); // DEPOIS DE CADASTRADO OS DADOS JÁ SÃO SALVOS IMEDIATAMENTE.

        puts("\nDESEJA CONTINUAR? [1 - SIM/ 2 - NÃO]");
        scanf("%d", &opcao);
    }while(opcao == 1);
}


void salvar_funcionario(FUNCIONARIO funcionario) // FUNÇÃO QUE RECEBE UMA VARIÁVEL DO TIPO FUNCIONÁRIO E SALVA OS DADOS EM UM ARQUIVO TXT.
{
    FILE *fp;
    fp = fopen("funcionarios.txt", "a");

    fprintf(fp, "%s, %s, %s, %s, %s, %s\n", funcionario.nome, funcionario.nascimento, funcionario.cpf, funcionario.telefone, funcionario.cargo, funcionario.data_ingresso);
    fclose(fp);

    // SALVANDO O NOME E SALÁRIO DO FUNCIONÁRIO CADASTRADO EM UM ARQUIVO SEPARADO PARA QUE POSSA SER CALCULADO O SALÁRIO ANUAL POSTERIORMENTE.
    fp = fopen("salarios.txt", "a");
    fprintf(fp, "%s %.2f\n", funcionario.nome, funcionario.salario);
    fclose(fp);
}


void salario_anual() // CALCULA E EXIBE O SALÁRIO ANUAL DE TODOS OS FUNCINÁRIOS CADASTRADOS
{
    FILE *fp;
    fp = fopen("salarios.txt", "r");
    char nome[30];
    float anual;

    system("cls");
    puts("-=-=-=-=-=- SALÁRIO ANUAL DE FUNCIONÁRIOS -=-=-=-=-=-");
    while(!feof(fp))
    {
        fscanf(fp, "%s%f", &nome, &anual);
        printf("\nO salário anual de %s é de R$ %.2f\n", nome, anual*12);
        puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    }
    fclose(fp);
    puts("\n(aperte qualquer tecla para voltar!)");
    getchar();
    getchar();
}


void cadastro_produto(int opcao) // FUNÇÃO PARA CADASTRAR PRODUTOS E SALVAR OS DADOS.
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
        puts("\nPREÇO: R$");
        scanf("%f", &produto.preco);

        salvar_produto(produto);

        puts("\nDESEJA CONTINUAR? [1 - SIM/ 2 - NÃO]");
        scanf("%d", &opcao);
    }while(opcao == 1);
}


void salvar_produto(PRODUTO produto) // FUNÇÃO QUE RECEBE UMA VARIÁVEL DO TIPO PRODUTO E SALVA OS DADOS EM UM ARQUIVO TXT.
{
    FILE *fp;
    fp = fopen("produtos.txt", "a");

    fprintf(fp, "%s, %s, %.2f\n", produto.nome, produto.categoria, produto.preco);
    fclose(fp);
}


void exibir_clientes() // MOSTRA OS DADOS DE TODOS OS CLIENTES CADASTRADOS.
{
    FILE *fp;
    char linha[136];
    int id_cliente=1;
    fp = fopen("clientes.txt", "r");

    system("cls");
    puts("\t\t-=-=-=-=-=- CLIENTES CADASTRADOS -=-=-=-=-=-");
    while(fgets(linha, 136, fp) != NULL)
    {
        printf("\nID:%d \n%s", id_cliente, linha);
        id_cliente += 1;
        puts("-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-");
    }
    puts("\n(aperte qualquer tecla para voltar!)");
    getchar();
    getchar();
}


void exibir_funcionarios() // MOSTRA OS DADOS DE TODOS OS CLIENTES CADASTRADOS.
{
    FILE *fp;
    char linha[136];
    int id_funcionario=1;
    fp = fopen("funcionarios.txt", "r");

    system("cls");
    puts("\t\t-=-=-=-=-=- FUNCIONÁRIOS CADASTRADOS -=-=-=-=-=-");
    while(fgets(linha, 136, fp) != NULL)
    {
        printf("\nID:%d \n%s", id_funcionario, linha);
        id_funcionario += 1;
        puts("\n-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-");
    }
    puts("\n(aperte qualquer tecla para voltar!)");
    getchar();
    getchar();
}


void exibir_produtos() // MOSTRA OS DADOS DE TODOS OS CLIENTES CADASTRADOS.
{
    FILE *fp;
    char linha[50];
    int id_produto=1;
    fp = fopen("produtos.txt", "r");

    system("cls");
    puts("\t\t-=-=-=-=-=- PRODUTOS CADASTRADOS -=-=-=-=-=-");
    while(fgets(linha, 50, fp) != NULL)
    {
        printf("\nID:%d \n%s", id_produto, linha);
        id_produto += 1;
        puts("\n-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-");
    }
    puts("\n(aperte qualquer tecla para voltar!)");
    getchar();
    getchar();
}

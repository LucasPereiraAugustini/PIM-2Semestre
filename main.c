#include<stdio.h>
#include<locale.h>
#include"modulos.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcao, opcao2;

    tela_de_login();

    do
    {
        menu_inicial();
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1: cadastro_cliente(opcao); // CASE 1 CHAMA A FUNÇÃO PARA CADASTRAR OS CLIENTES.
                    break;
            case 2: cadastro_funcinario(opcao); // CASE 2 CHAMA A FUNÇÃO PARA CADASTRAR OS FUNCIONÁRIOS.
                    break;
            case 3: cadastro_produto(opcao); // CASE 3 CHAMA A FUNÇÃO PARA CADASTRAR OS PRODUTOS.
                    break;
            case 4: do{
                        menu_relatorios();
                        scanf("%d", &opcao2);
                        switch(opcao2)// NESTE CASE TEMOS UM DO WHILE QUE CHAMA O MENU DE RELATÓRIOS E EXIBE O RELATÓRIO DE ACORDO COM A OPÇÃO ESCOLHIDA.
                        {
                            case 1: exibir_clientes(); // CASE 1 CHAMA A FUNÇÃO PARA EXIBIR OS CLIENTES.
                                    break;
                            case 2: exibir_funcionarios(); // CASE 2 CHAMA A FUNÇÃO PARA EXIBIR OS FUNCIONÁRIOS.
                                    break;
                            case 3: exibir_produtos(); // CASE 3 CHAMA A FUNÇÃO PARA EXIBIR OS PRODUTOS.
                                    break;
                            case 4: salario_anual(); // CASE 4 CHAMA A FUNÇÃO PARA EXIBIR O SALÁRIO ANUAL DE FUNCIONÁRIOS.
                                    break;
                            case 5: break; // CASE 5 VOLTA PARA A TELA INICIAL.
                            default: printf("OPÇÃO INVÁLIDA!");
                            Sleep(2000);
                        }
                        }while(opcao2 != 5);
                        break;
            case 5: puts("SALVANDO DADOS..."); // CASE 5 SAIR DO PROGRAMA.
                    Sleep(1000);
                    break;
            default: printf("OPÇÃO INVÁLIDA!");
            Sleep(2000);
        }
    }while(opcao != 5);

    return 0;
}

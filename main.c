#include<stdio.h>
#include<locale.h>
#include"modulos.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    tela_de_login();

    do
    {
        menu_inicial();
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1: cadastro_cliente(opcao); // CASE 1 CHAMA A FUN��O PARA CADASTRAR OS CLIENTES.
                    break;
            case 2: cadastro_funcinario(opcao); // CASE 2 CHAMA A FUN��O PARA CADASTRAR OS FUNCION�RIOS.
                    break;
            case 3: cadastro_produto(opcao); // CASE 3 CHAMA A FUN��O PARA CADASTRAR OS PRODUTOS.
                    break;
            case 4: do{
                        menu_relatorios();
                        scanf("%d", &opcao);
                        switch(opcao)// NESTE CASE TEMOS UM DO WHILE QUE CHAMA O MENU DE RELAT�RIOS E EXIBE O RELAT�RIO DE ACORDO COM A OP��O ESCOLHIDA.
                        {
                            case 1: exibir_clientes();
                                    break;
                            case 2: exibir_funcionarios();
                                    break;
                            case 3: exibir_produtos();
                                    break;
                            case 4: break;
                            default: printf("OP��O INV�LIDA!");
                            Sleep(2000);
                        }
                        }while(opcao != 4);
                        break;
            case 5: puts("SALVANDO DADOS..."); // CASE 5 SAIR DO PROGRAMA.
                    Sleep(1000);
                    break;
            default: printf("OP��O INV�LIDA!");
            Sleep(2000);
        }
    }while(opcao != 5);

    return 0;
}

#include<stdio.h>
#include<locale.h>
#include"modulos.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    
    do
    {
        menu();
        scanf("%d", &opcao);
        printf("Hello World");
        switch(opcao)
        {
            case 1: cadastro_cliente();
                    break;
            case 2: mostrar_cadastro(opcao);
                    break;
            case 3: cadastro_funcinario();
                    break;
            case 4: mostrar_cadastro(opcao);
                    break;
            case 5: puts("SALVANDO DADOS...");
                    Sleep(1000);
                    break;
            default: puts("OPÇÃO INVÁLIDA!");
            Sleep(2000);
        }
    }while(opcao != 5);
    system("pause");
}

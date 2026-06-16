#include <stdio.h>
#include <windows.h>
int main(){
    SetConsoleOutputCP(CP_UTF8);
    FILE *arquivo = fopen("inventario.csv", "r");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        getch();
        return 0;
    }

    char cabecalho[100];
    char produto[10][50];
    char local[10][50];
    int quantidade[10];
    float valor[10];
    int i = 0;
    float total = 0;

	fscanf(arquivo,"%[^\n]\n",cabecalho);

	while(fscanf(arquivo,"%[^,],%d,%[^,],%f\n",produto[i],&quantidade[i],local[i],&valor[i])==4)
	{
    	i++;
	}

    fclose(arquivo);
    printf("Relatorio de inventario\n");

    for(int j = 0; j < i; j++)
    {
        printf("Produto: %s\n", produto[j]);
        printf("Quantidade: %d\n", quantidade[j]);
        printf("Local: %s\n", local[j]);
        printf("Valor Unitario: R$ %.2f\n", valor[j]);
        printf("Valor Total do Estoque: R$ %.2f\n\n", quantidade[j] * valor[j]);

        total = total + (quantidade[j] * valor[j]);
    }

    printf("Quantidade de produtos: %d\n", i);
    printf("Valor Total do Inventario: R$ %.2f\n", total);

	fclose(arquivo);
	getch();
    return 0;
}
#include <stdio.h>  // biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das STRING

// funções
int registro() // função que cadastra usuarios
{
    char arquivo[40];   // definindo as variaveis
    char cpf[40];       // definindo as variaveis
    char nome[40];      // definindo as variaveis
    char sobrenome[40]; // definindo as variaveis
    char cargo[40];     // definindo as variaveis

    printf("Digite o CPF a ser cadastrado"); // coletando infos
    scanf("%s", cpf);                        // salva na variavel cpf

    strcpy(arquivo, cpf); // responsavel por cuidar os valores das string

    FILE *file;                 // criar o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo
    fprintf(file, cpf);         // salvo o valor da variavel
    fclose(file);               // fecho o arquivo

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado:");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado:");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause");
}

int consulta() // função de consulta
{

    setlocale(LC_ALL, "Portuguese"); // definindo as linguagens

    char cpf[40];       // definindo as variaveis
    char conteudo[200]; // definindo as variaveis

    printf("Digite o CPF a ser consultado");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("Não foi possivel abrir o arquivo, não localizado!\n");
    }

    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário:");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");
}

int deletar() // função deletar usuario
{
    char cpf[40]; // definindo as variaveis

    printf("Digite o CPF a ser deletado:");
    scanf("%s", cpf);

    remove(cpf); // remove o cpf

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("o usuário não se encontra no sistema!\n");
        system("pause");
    }

    system("pause");
}

int main()
{

    int opcao = 0; // definindo as variaveis
    int laco = 1;  // definindo as variaveis

    for (laco = 1; laco = 1;)
    {
        system("cls");

        setlocale(LC_ALL, "Portuguese"); // definindo as linguagens

        printf("### Cartório da EBAC ###"); // inicio menu
        printf("Escolha a opção desejada no menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção:"); // fim do menu

        scanf("%d", &opcao); // armazenando a escolha

        system("cls");

        // inicio da seleção
        switch (opcao)
        {
        case 1:
            registro(); // chamando funções
            break;
        case 2:
            consulta(); // chamando funções
            break;
        case 3:
            deletar(); // chamando funções
            break;
        case 4:
            printf("Obrigado por utilizar o sistema!\n");
            return 0;
            break;
        default:
            printf("Essa opção não está disponivel!");
            system("pause");
            break;
        }
        // fim da escolha
    }
}
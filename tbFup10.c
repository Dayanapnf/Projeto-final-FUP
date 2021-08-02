#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISCIPLINAS 8

typedef struct
{
    int matricula;
    char nome[50];
    char email[60];
    char telefone[20];
} Aluno;
Aluno aluno;
typedef struct
{
    char nome[50];
    char professor[50];
    float notas[4];
    int ativo;

} Disciplina;
Disciplina disciplinas[MAX_DISCIPLINAS];

void menu();
void cadastrarDisciplina();
void remover();
void reprovados();
void pesquisar();
void listar();
void cadastroInicial();
void listarDadoAluno();
float mediaDisciplina(float nota1, float nota2, float nota3, float nota4);

int main()
{

    cadastroInicial();
    return 0;
}

void cadastroInicial()
{
    int matricula = 1;
    char nome[50];
    char email[60];
    char telefone[20];

    system("cls");
    printf("==================================\n");
    printf("||      Inserindo Meus Dados    ||\n");
    printf("::::::::::::::::::::::::::::::::::\n");
    printf(":::DIGITE SEU NOME:\n");
    printf("::");
    fgets(nome, sizeof(nome), stdin);
    printf(":::DIGITE SEU TELEFONE:\n");
    printf("::");
    fgets(telefone, sizeof(telefone), stdin);
    printf(":::DIGITE SEU E-MAIL:\n");
    printf("::");
    fgets(email, sizeof(email), stdin);
    aluno.matricula = matricula;
    strcpy(aluno.nome, nome);
    strcpy(aluno.email, email);
    strcpy(aluno.telefone, telefone);
    printf(" PRESSIONE ENTER PARA ACESSAR O MENU ");
    getchar();
    menu();
}
void cadastrarDisciplina()
{

    char nome[50];
    char professor[50];
    float notas[4];

    int op;
    do
    {
        system("cls");

        printf("==================================\n");
        printf("||   Cadastrando Disciplinas    ||\n");
        printf("::::::::::::::::::::::::::::::::::\n");
        printf(":::NOME DA DISCIPLINA:\n");
        printf("::");
        fgets(nome, sizeof(nome), stdin);
        printf(":::NOME DO PROFESSOR?:\n");
        printf("::");
        fgets(professor, sizeof(professor), stdin);
        printf(":::NOTA 1:\n");
        printf("::");
        scanf("%f", &notas[0]);
        printf(":::NOTA 2:\n");
        printf("::");
        scanf("%f", &notas[1]);
        printf(":::NOTA 3:\n");
        printf("::");
        scanf("%f", &notas[2]);
        printf(":::NOTA 4:\n");
        printf("::");
        scanf("%f", &notas[3]);
        int i;
        for (i = 0; i < MAX_DISCIPLINAS; i++)
        {
            if (disciplinas[i].ativo == 0)
            {
                disciplinas[i].notas[0] = notas[0];
                disciplinas[i].notas[1] = notas[1];
                disciplinas[i].notas[2] = notas[2];
                disciplinas[i].notas[3] = notas[3];
                strcpy(disciplinas[i].nome, nome);

                strcpy(disciplinas[i].professor, professor);

                disciplinas[i].ativo = 1;
                break;
            }
        }

        printf("==================================\n");
        printf("|| 1-CADASTRAR MAIS DISCIPLINAS ||\n");
        printf("|| 0- CONTINUAR                 ||\n");
        printf("::::::::::::::::::::::::::::::::::\n");
        scanf("%d", &op);
        getchar();
    } while (op != 0);
}
void menu()
{
    int op;
    
    do
    {
        system("cls");
        printf("=================================\n");
        printf("||         Seja Bem Vindo!      ||\n");
        printf("==================================\n");
        printf("||       Informe a operacao     ||\n");
        printf("||       que deseja realizar    ||\n");
        printf("||  Ex: 1 = Acessar Aluno       ||\n");
        printf("==================================\n");
        printf("||         O que deseja?        ||\n");
        printf("==================================\n");
        printf("||  1 - LISTAR DISCIPLINAS      ||\n");
        printf("||  2 - CADASTRAR DISCIPLINA    ||\n");
        printf("||  3 - ATUALIZAR DISCIPLINA    ||\n");
        printf("||  4 - DELETAR  DISCIPLINA     ||\n");
        printf("||  5 - PESQUISAR DISCIPLINA    ||\n");
        printf("||  6 - VER MEUS DADOS          ||\n");
        printf("||  7 - ATUALIZAR MEUS DADOS    ||\n");
        printf("||  8 - VAGO                    ||\n");
        printf("||  9 - VAGO                    ||\n");
        printf("||  0 - SAIR                    ||\n");
        printf("==================================\n");
        scanf("%d", &op);
        getchar();

        switch (op)
        {
        case 1:
            system("cls");
            listar();
            break;
        case 2:
            system("cls");
            cadastrarDisciplina();
            break;
        case 3:
            printf("a construir");
            break;
        case 4:
            system("cls");
            remover();
            break;
        case 5:
            system("cls");
            pesquisar();
            break;
        case 6:
            system("cls");
            listarDadoAluno();
            break;
        case 7:
            printf("a construir");
            break;
        default:
            break;
        }
        getchar();
    } while (op != 0);
}

void remover()
{
 
    int id;
    system("cls");
    printf("==================================\n");
    printf("|| DIGITE O 'ID' DA DISCIPLINA   ||\n");
    printf("|| DESEJA DELETAR                ||\n");
    printf("::::::::::::::::::::::::::::::::::\n");
    int i;
    for ( i = 0; i < MAX_DISCIPLINAS; i++)
    {
        if (disciplinas[i].ativo == 1)
        {
            
            printf("|| ID DISCIPLINA :%d            ||\n", i+1);
            printf("|| NOME DISCIPLINA:%s             \n", disciplinas[i].nome);
            printf("::::::::::::::::::::::::::::::::::\n");
        }
    }
    printf("::\n");
    scanf("%d", &id);
    --id;
    disciplinas[id].ativo = 0;
    printf("|DISCIPLINA DELETADA COM SUCESSO||\n");
    printf("==================================\n");
    getchar();
}

void reprovados()
{
    system("cls");
    float media = 0;
    printf("\n LISTA DE disciplinas\n");
    int i;
    for (i = 0; i < MAX_DISCIPLINAS; i++)
    {
        if (disciplinas[i].ativo == 1)
        {

            media = disciplinas[i].notas[0] + disciplinas[i].notas[1] + disciplinas[i].notas[2] + disciplinas[i].notas[3];
            media = media / 4;
            if (media < 7)
            {
                printf("Matricula: %d\n", i + 1);
                printf("Nome: %s\n", disciplinas[i].nome);
                printf("Nota 01: %0.2f\n", disciplinas[i].notas[0]);
                printf("Nota 02: %0.2f\n", disciplinas[i].notas[1]);
                printf("Nota 03: %0.2f\n", disciplinas[i].notas[2]);
                printf("Nota 04: %0.2f\n", disciplinas[i].notas[3]);
                printf("\n----------------\n");
            }
        }
    }
}
void pesquisar()
{

    char nome[50];
    int op;

    do
    {
        system("cls");
    printf("==================================\n");
    printf("|| DIGITE O NOME DA DISCIPLINA  ||\n");
    printf("|| QUE DESEJA PROCURAR          ||\n");
    printf("::::::::::::::::::::::::::::::::::\n");
    printf("::\n");
    fgets(nome, sizeof(nome), stdin);
    int i;
        for ( i = 0; i < MAX_DISCIPLINAS; i++)
        {
            if (strstr(disciplinas[i].nome, nome) != NULL)
            {
            printf("|| ID DISCIPLINA :%d            ||\n", i+1);
            printf("|| NOME DISCIPLINA:%s             \n", disciplinas[i].nome);
            printf("|| NOME PROFESSOR:%s             \n", disciplinas[i].professor);
            printf("|| NOTA 01 :%0.2f              ||\n", disciplinas[i].notas[0]);
            printf("|| NOTA 02 :%0.2f              ||\n", disciplinas[i].notas[1]);
            printf("|| NOTA 03 :%0.2f              ||\n", disciplinas[i].notas[2]);
            printf("|| NOTA 04 :%0.2f              ||\n", disciplinas[i].notas[3]);
            float media = mediaDisciplina(disciplinas[i].notas[0], disciplinas[i].notas[1], disciplinas[i].notas[2], disciplinas[i].notas[3]);
            if(media >= 7){
            printf("|| VOCE ESTA APROVADO! (:)     ||\n");
            }else if(media < 7){
            printf("|| VOCE ESTA REPROVADO! (:(    ||\n");
            };
        
            printf("==================================\n");        
            printf("::::::::::::::::::::::::::::::::::\n");
            }
        }
        printf("==================================\n");
        printf("|| 1 - NOVA PESQUISA            ||\n");
        printf("|| 0 - MENU                     ||\n");
        printf("::::::::::::::::::::::::::::::::::\n");
        scanf("%d", &op);
        getchar();
    } while (op != 0);
}
float mediaDisciplina(float nota1,float nota2, float nota3, float nota4){
    float media = (nota1 + nota2 + nota3 + nota4)/4;
    return media;
};
void listar()
{
    float media=0;
    system("cls");
    printf("==================================\n");
    printf("||      Minhas Disciplinas      ||\n");
    printf("::::::::::::::::::::::::::::::::::\n");
    printf("==================================\n");
    int i;
    for ( i = 0; i < MAX_DISCIPLINAS; i++)
    {
        if (disciplinas[i].ativo == 1)
        {
            printf("|| ID DISCIPLINA :%d            ||\n", i+1);
            printf("|| NOME DISCIPLINA:%s             \n", disciplinas[i].nome);
            printf("|| NOME PROFESSOR:%s             \n", disciplinas[i].professor);
            printf("|| NOTA 01 :%0.2f              ||\n", disciplinas[i].notas[0]);
            printf("|| NOTA 02 :%0.2f              ||\n", disciplinas[i].notas[1]);
            printf("|| NOTA 03 :%0.2f              ||\n", disciplinas[i].notas[2]);
            printf("|| NOTA 04 :%0.2f              ||\n", disciplinas[i].notas[3]);
            media = mediaDisciplina(disciplinas[i].notas[0], disciplinas[i].notas[1], disciplinas[i].notas[2], disciplinas[i].notas[3]);
            if(media >= 7){
            printf("|| VOCE ESTA APROVADO! (:)     ||\n");
            }else{
            printf("|| VOCE ESTA REPROVADO! (:(    ||\n");
            }
            
            printf("==================================\n");        
            printf("::::::::::::::::::::::::::::::::::\n");
        }
    }
}
void listarDadoAluno()
{

    system("cls");
    printf("==================================\n");
    printf("||      Meus Dados              ||\n");
    printf("::::::::::::::::::::::::::::::::::\n");
    printf(":: 1 - Nome: %s\n", aluno.nome);
    printf(":: 2 - Matricula: 000%d\n", aluno.matricula);
    printf(":: 3 - E-mail: %s\n", aluno.email);
    printf(":: 4 - Telefone: %s\n", aluno.telefone);
}
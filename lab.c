// Bibliotecas
#include <stdio.h>
#include <string.h>

// Definições globais
#define MAX_PACIENTES 10
#define MAX_EXAMES 30

//Estrutura para armazenar informações de um paciente
typedef struct {
    int id;
    char nome[50];
    int idade;
}Paciente;

// Estrutura para armazenar informações dos exames
typedef struct {
    int id;
    int pacienteId; //Id do paciente ao qual o exame pertence
    char tipo[30];
    char resultado[50];
} Exame;

//Variaveis
Paciente pacientes[MAX_PACIENTES];
Exame exames [MAX_EXAMES];

int pacienteTotal = 0;
int exameTotal = 0;

//função
void menu() {
    printf("\n=== Sistema de Laboratorio ===\n");
    printf("1. Cadastrar paciente\n");
    printf("2. Cadastrar exame\n");
    printf("3. Listar pacientes\n");
    printf("4. Listar exames\n");
    printf("5. Buscar exames por paciente\n");
    printf("0. Sair\n");
    printf("**********************************\n");
    printf("Escolha uma opcao: ");
}

// função
void cadastrarPaciente(){
    // se o total de paciente for MENOR que o limite definido
    if (pacienteTotal < MAX_PACIENTES){
        Paciente p; //cria um novo paciente
        p.id = pacienteTotal + 1; //o primeiro paciente cadastrado recebe o id = 1, o segundo = 2, assim até o limite de pacientes
        getchar();//limpar o buffer do menu

        printf ("Nome do paciente: ");
        fgets(p.nome, sizeof(p.nome),stdin);// lê o nome incluindo o espaço
        p.nome[strcspn(p.nome, "\n")]='\0'; //remove o enter do final do nome
        
        printf("Idade: ");
        scanf("%d", &p.idade); // lê a idade
        getchar(); //limpar o enter da idade

        pacientes[pacienteTotal++] = p; //guarda o paciente dentro do array
        printf("Paciente cadastrado com sucesso!\n");
    }else{
        printf("Limete de paciente atingido. Volte amanhã!\n");
    }
}

int buscarPacientePorId(int id){
    //para cada paciente do arry 
    for(int i = 0; i < pacienteTotal; i++){
        // SE o id do paciente atual for IGUAL ao id que estamos procurando
        if(pacientes[i].id == id){
            return 1; // retonar 1, ou seja, id foi encontrado   
        }
    }
    // ZERO significa que NÃO foi encontrado
    return 0;
}

void cadastrarExame(){
    // SE o total de exame for MENOR que o LIMITE definido
    if (exameTotal < MAX_EXAMES){
        Exame e; // acrescentar um exame
        e.id = exameTotal + 1; // até que for MENOR que o limite definido

        printf("ID do paciente: ");
        scanf("%d", &e.pacienteId); //armazenar o ID do paciente
        getchar();//limpar o enter do paciente

        // SE o resultado da buscar de paciente por id por igual a zero
        if(buscarPacientePorId(e.pacienteId)==0){
            printf("Não existe nenhum paciente com este ID"); // não achou
            return; // interrope a função
        }

        int escolhaExame;
        printf("Escolha o exame a ser realizado:\n");
        printf("1. Ureia\n");
        printf("2. Creatinina\n");
        printf("3. TGO\n");
        printf("4. TGP\n");
        printf("5. Fosfatase alcalina\n");
        printf("6. Acido urico\n");
        printf("Escolha de (1-6): ");
        scanf("%d", &escolhaExame); //armazenar a escolha do exame

        getchar(); //limpar o enter da escolha exame

        int opcaoValida = 1;

        switch (escolhaExame){
            case 1: strcpy(e.tipo, "Ureia"); break;
            case 2: strcpy(e.tipo, "Creatinina"); break;
            case 3: strcpy(e.tipo, "TGO"); break;
            case 4: strcpy(e.tipo, "TGP"); break;
            case 5: strcpy(e.tipo, "Fosfatase alcalina"); break;
            case 6: strcpy(e.tipo, "Acido urico"); break;
        default:
            printf("Opcao invalida! Seu plano não cobre este exame\n");
            opcaoValida = 0;
            break;
        }
        if(opcaoValida){
            printf("Resultado: ");
            fgets(e.resultado, sizeof(e.resultado),stdin);
            e.resultado[strcspn(e.resultado, "\n")]='\0';
        
            exames[exameTotal++] = e;
            printf("Exame cadastrado com sucesso!");
        }else{
            printf("Cadastro de exame cancelado\n");
        }
    }else{
        printf("Limite de exame atigido. Entre em contato com seu plano");
    }
}

void listarPacientes() {
    printf("************ LISTA DE PACIENTES ************\n");
    if(pacienteTotal == 0){
        printf("Nenhum paciente cadastrado\n");
        return;
    }
    for (int i = 0; i < pacienteTotal; i++){
        printf("ID: %d | Nome: %s | Idade: %d\n" , pacientes[i].id, pacientes[i].nome, pacientes[i].idade);
    }
    
}

void listarExames() {
    printf("************ LISTA DE EXAMES ************\n");
    if(exameTotal == 0){
        printf("Nenhum exame cadastrado\n");
        return;
    }
    for (int i = 0; i < exameTotal; i++){
        printf("ID Paciente: %d | Nome do exame: %s | ID Exame: %d\n" , exames[i].pacienteId, exames[i].tipo, exames[i].id);
    }
    
}

void buscarExamesPorPaciente(){
    int idBusca;
    printf("Digite o ID do paciente para buscar os exames: ");
    scanf("%d", &idBusca);
    getchar(); //Limpar buffer

    if(buscarPacientePorId(idBusca)==0){
        printf("Paciente nao encontrado ");
        return;
    }

    printf("\n***Exames do Paciente ID: %d**\n", idBusca);

    int exameEncontrado = 0;
    for(int i = 0; i < exameTotal; i++){
        if(exames[i].pacienteId == idBusca){
            printf("Exame: %s (ID exame: %d) | Resultado: %s\n", exames[i].tipo, exames[i].id, exames[i].resultado);
            exameEncontrado = 1;
        }

    }
    if(exameEncontrado==0){
        printf("Nenhum exame encontrado para este paciente\n");
    }

}

int main() {
    int opcao;
    do{
        menu();
        scanf("%d", &opcao);
        switch (opcao){
            case 1: cadastrarPaciente();break;
            case 2:cadastrarExame();break;
            case 3:listarPacientes();break;
            case 4: listarExames();break;
            case 5: buscarExamesPorPaciente(); break;
            case 0:printf("Saido....");break;
            default: printf("Opção inválida, Tente novamente");
        }
    }while (opcao != 0);
    return 0;
}
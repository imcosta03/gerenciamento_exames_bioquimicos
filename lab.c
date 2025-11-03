#include <stdio.h>
#include <string.h>

void menu() {
    printf("\n=== Sistema de Laboratorio ===\n");
    printf("1. Cadastrar paciente\n");
    printf("2. Cadastrar exame\n");
    printf("3. Listar pacientes\n");
    printf("4. Listar exames\n");
    printf("5. Buscar exames por paciente\n");
    printf("0. Sair\n");
}

int main() {
    menu();
}
# Sistema de Gerenciamento de Exames Laboratoriais

Este é um projeto desenvolvido em **linguagem C**, que simula um sistema de gerenciamento para um laboratório. Ele foi criado para praticar conceitos fundamentais de programação, como o uso de `structs`, `arrays`, laços de repetição (`for`, `do-while`) e controle de fluxo (`if`, `switch-case`).

O sistema é executado inteiramente no terminal (console).

## Funcionalidades principais

O programa permite ao usuário gerenciar pacientes e seus exames através de um menu interativo.

* **1. Cadastrar paciente:**
    * Registra um novo paciente com ID (gerado automaticamente), nome e idade.

* **2. Cadastrar exame:**
    * Registra um novo exame para um paciente já existente.
    * **Validação:** O sistema verifica se o ID do paciente informado existe antes de permitir o cadastro do exame.
    * O usuário escolhe o tipo de exame de uma lista pré-definida:
        * Ureia
        * Creatinina
        * TGO
        * TGP
        * Fosfatase alcalina
        * Ácido úrico
    * Permite inserir o resultado do exame.

* **3. Listar pacientes:**
    * Exibe na tela uma lista de todos os pacientes cadastrados (ID, Nome, Idade).

* **4. Listar exames:**
    * Exibe na tela uma lista completa de todos os exames já registrados, mostrando o ID do paciente e o tipo de exame.

* **5. Buscar exames por paciente:**
    * Solicita o ID de um paciente e exibe um relatório com todos os exames e resultados associados a esse paciente.

* **0. Sair:**
    * Encerra o programa.

## Tecnologias utilizadas

* **Linguagem C**
* **GCC** (ou qualquer compilador C padrão)
* **Visual Studio Code **


## Como Executar o Projeto

Para compilar e executar este projeto, você precisará de um compilador C.

1.  **Clone o repositório** (ou baixe os arquivos):
    ```bash
    git clone https://github.com/imcosta03/gerenciamento_exames_bioquimicos.git
    ```

2.  **Compile o programa:**

3.  **Execute o programa:**

4.  **Use o menu:**
    Após executar, o menu principal será exibido no terminal:

    ```
    === Sistema de Laboratorio ===
    1. Cadastrar paciente
    2. Cadastrar exame
    3. Listar pacientes
    4. Listar exames
    5. Buscar exames por paciente
    0. Sair
    **********************************
    Escolha uma opcao:
    ```

## Autora

Izabela Costa

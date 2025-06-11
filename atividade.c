#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da pilha e protótipos de função.

typedef struct stack {
    int *data;
    int top;
    int size;
} Stack;

Stack* new_stack(int size);
void stack_push(Stack* s, int value);
int stack_pop(Stack* s);
void stack_print(Stack* s);

// Implementação das funções para manipular a pilha.

Stack* new_stack(int size) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (!s) {
        perror("Falha ao alocar memória para a pilha");
        exit(EXIT_FAILURE);
    }
    s->data = (int*)malloc(sizeof(int) * size);
    if (!s->data) {
        perror("Falha ao alocar memória para os dados da pilha");
        free(s);
        exit(EXIT_FAILURE);
    }
    s->top = -1;
    s->size = size;
    return s;
}

void stack_push(Stack* s, int value) {
    if (s->top < s->size - 1) {
        s->data[++s->top] = value;
    } else {
        printf("Erro: Pilha cheia!\n");
    }
}

int stack_pop(Stack* s) {
    if (s->top >= 0) {
        return s->data[s->top--];
    } else {
        printf("Erro: Pilha vazia!\n");
        return -1; // Retorna um valor de erro. Idealmente, o erro deveria ser tratado.
    }
}

void stack_print(Stack* s) {
    printf("Conteúdo da pilha: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// Lógica para interpretar os comandos do usuário.

void interpret(const char *source, Stack *s) {
    char op[10] = "";
    char arg[10] = "";

    // Lê o comando e o argumento da string de entrada
    sscanf(source, "%s %s", op, arg);

    if (strcmp(op, "push") == 0) {
        if (strlen(arg) > 0) {
            int value = atoi(arg);
            stack_push(s, value);
            printf("Valor %d empilhado.\n", value);
        } else {
            printf("Erro: Comando 'push' requer um argumento numérico.\n");
        }
    } else if (strcmp(op, "add") == 0) {
        if (s->top < 1) {
            printf("Erro: 'add' requer pelo menos dois valores na pilha.\n");
            return;
        }
        int b = stack_pop(s);
        int a = stack_pop(s);
        stack_push(s, a + b);
        printf("Soma: %d\n", a + b);
    } else if (strcmp(op, "sub") == 0) {
         if (s->top < 1) {
            printf("Erro: 'sub' requer pelo menos dois valores na pilha.\n");
            return;
        }
        int b = stack_pop(s);
        int a = stack_pop(s);
        stack_push(s, a - b);
        printf("Subtracao: %d\n", a - b);
    } else if (strcmp(op, "mul") == 0) {
         if (s->top < 1) {
            printf("Erro: 'mul' requer pelo menos dois valores na pilha.\n");
            return;
        }
        int b = stack_pop(s);
        int a = stack_pop(s);
        stack_push(s, a * b);
        printf("Multiplicacao: %d\n", a * b);
    } else if (strcmp(op, "div") == 0) {
         if (s->top < 1) {
            printf("Erro: 'div' requer pelo menos dois valores na pilha.\n");
            return;
        }
        int b = stack_pop(s);
        int a = stack_pop(s);
        if (b != 0) {
            stack_push(s, a / b);
            printf("Divisao: %d\n", a / b);
        } else {
            printf("Erro: Divisão por zero!\n");
            // Devolve os valores para a pilha na ordem original para evitar perdê-los
            stack_push(s, a);
            stack_push(s, b);
        }
    } else if (strcmp(op, "print") == 0) {
        if (s->top < 0) {
             printf("Erro: 'print' requer pelo menos um valor na pilha.\n");
             return;
        }
        int value = stack_pop(s);
        printf("Valor desempilhado: %d\n", value);
    } else if (strlen(op) > 0) { // Evita mensagem de erro para linha em branco
        printf("Comando desconhecido: %s\n", op);
    }
}


// Função principal e o loop de leitura (REPL).

static void repl(Stack *s) {
    char line[1024];
    printf("Calculadora de Pilha. Digite 'push 5', 'add', etc. ou Ctrl+D para sair.\n");
    for (;;) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) {
            printf("\nSaindo.\n");
            break;
        }
        interpret(line, s);
    }
}

int main() {
    Stack* s = new_stack(100);

    repl(s);

    // Libera a memória alocada antes de terminar o programa
    free(s->data);
    free(s);

    return 0;
}

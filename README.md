

````markdown
# 📦 Calculadora de Pilha em C

Este projeto é uma **calculadora baseada em pilha (stack)** implementada em linguagem C, que funciona através de um REPL (Read-Eval-Print Loop). Comandos como `push`, `add`, `sub`, `mul`, `div` e `print` são interpretados e executados interativamente.

## 🚀 Como compilar

Certifique-se de ter um compilador C instalado, como o `gcc`.

```bash
gcc -o calculadora_pilha calculadora_pilha.c
````

## ▶️ Como executar

```bash
./calculadora_pilha
```

## 🛠️ Comandos disponíveis

| Comando  | Descrição                                                          |
| -------- | ------------------------------------------------------------------ |
| `push N` | Empilha o número `N` na pilha. Exemplo: `push 5`                   |
| `add`    | Soma os dois últimos números da pilha e empilha o resultado.       |
| `sub`    | Subtrai os dois últimos números da pilha e empilha o resultado.    |
| `mul`    | Multiplica os dois últimos números da pilha e empilha o resultado. |
| `div`    | Divide os dois últimos números da pilha e empilha o resultado.     |
| `print`  | Desempilha e imprime o valor do topo da pilha.                     |

⚠️ A maioria das operações aritméticas requer pelo menos **dois valores** na pilha.
⚠️ A divisão verifica se o divisor é zero para evitar erro de execução.

## 🧪 Exemplo de uso

```bash
> push 10
Valor 10 empilhado.
> push 20
Valor 20 empilhado.
> add
Soma: 30
> push 5
Valor 5 empilhado.
> div
Divisao: 6
> print
Valor desempilhado: 6
```

## 📂 Estrutura do Código

* `struct stack`: Estrutura que armazena os dados da pilha.
* `new_stack(size)`: Cria uma nova pilha.
* `stack_push`, `stack_pop`, `stack_print`: Operações básicas da pilha.
* `interpret`: Lê e interpreta os comandos.
* `repl`: Loop interativo que lê entradas do usuário.

## 🧹 Gerenciamento de Memória

Ao final da execução, toda a memória alocada dinamicamente para a pilha é liberada.

---

Desenvolvido como um exemplo simples de uso de pilhas e interpretação de comandos em C.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <ctype.h>  

#define MAX_SIZE 100  

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack* s, char c) {
    if (!isFull(s)) {
        s->data[++s->top] = c;
    }
    else {
        printf("Error: Stack is full\n");
        exit(1);
    }
}

char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[s->top--];
    }
    else {
        printf("Error: Stack is empty\n");
        exit(1);
    }
}

int precedence(char c) {
    switch (c) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return -1;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int i = 0, j = 0;
    char c;

    while (infix[i] != '\0') {
        c = infix[i];

        if (isalpha(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(&s, c);
        }
        else if (c == ')') {
            while (!isEmpty(&s) && s.data[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            if (!isEmpty(&s) && s.data[s.top] == '(') {
                pop(&s); // Remove '(' from the stack  
            }
        }
        else { // Operator  
            while (!isEmpty(&s) && precedence(s.data[s.top]) >= precedence(c)) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
        i++;
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("%s\n", postfix);

    return 0;
}

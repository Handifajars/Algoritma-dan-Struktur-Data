#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

struct stack {
    int data[MAX_CAPACITY];
    int top;
    int size;
};

void init(struct stack *s) {
    s->top = -1;
    s->size = 0;
}

bool is_full(struct stack s) {
    return s.size == MAX_CAPACITY;
}

bool is_empty(struct stack s) {
    return s.size == 0;
}

void push(struct stack *s, int value) {
    if (is_full(*s)) {
        printf("Stack penuh...");
        exit(EXIT_FAILURE);
    }

    s->data[++(s->top)] = value;
    s->size++;
}

int pop(struct stack *s) {
    if (is_empty(*s)) {
        printf("Stack kosong...");
        exit(EXIT_FAILURE);
    }

    s->size--;
    return s->data[(s->top)--];
}

int peek(struct stack s) {
    if (is_empty(s)) {
        printf("Stack kosong...");
        exit(EXIT_FAILURE);
    }

    return s.data[s.top];
}

int get_size(struct stack s) {
    return s.size;
}

void print_stack(struct stack s) {
    printf("[");
    for (int i = 0; i < s.size; ++i) {
        printf("%d", s.data[i]);

        if (i != s.size - 1)
            printf(", ");
    }
    printf("]\n");
}

int main(int argc, char const *argv[]) {
    struct stack st;
    init(&st);

    // Menambah 5 data ke dalam stack
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    // Menampilkan isi stack
    printf("Sebelum isi stack diambil\n");
    printf("Isi stack\t\t: ");
    print_stack(st);
    printf("Nilai paling atas\t: %d\n", peek(st));
    printf("Ukuran stack\t\t: %d\n", get_size(st));

    // Mengambil isi stack sebanyak 2 kali
    printf("\nMengambil isi stack...\n");
    printf("pop() pertama\t\t: %d\n", pop(&st));
    printf("pop() kedua\t\t: %d\n", pop(&st));

    printf("\nSetelah isi dalam stack diambil\n");
    printf("Isi stack\t\t: ");;
    print_stack(st);
    printf("Nilai paling atas\t: %d\n", peek(st));
    printf("Ukuran stack\t\t: %d\n", get_size(st));

    return 0;
}

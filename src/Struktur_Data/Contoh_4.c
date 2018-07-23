#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100

struct node {
    int data;
    struct node *next;
};

struct ll_stack {
    // Pointer menunjuk ke simpul pertama
    struct node *head;
    // Pointer menunjuk ke simpul terakhir
    struct node *tail;
    // Jumlah simpul di dalam stack
    int size;
};

void init(struct ll_stack *ll) {
    ll->head = NULL;
    ll->tail = NULL;
    ll->size = 0;       // Mula-mula stack kosong
}

bool is_full(struct ll_stack ll) {
    return ll.size == MAX_NODES;
}

bool is_empty(struct ll_stack ll) {
    return ll.size == 0;
}

void push(struct ll_stack *ll, int value) {
    if (is_full(*ll)) {
        printf("Stack penuh...\n");
        exit(EXIT_FAILURE);
    }
    else {
        struct node *new_node = (struct node *) malloc(sizeof(ll->head));
        new_node->data = value;

        if (is_empty(*ll)) {
            ll->head = new_node;
            ll->tail = ll->head;
        }
        else {
            // Menghubungkan simpul terakhir dengan simpul baru
            ll->tail->next = new_node;
            // Tail menunjuk ke simpul baru
            ll->tail = ll->tail->next;
            // Pointer tail menunjuk ke NULL
            ll->tail->next = NULL;
        }

        ll->size++;
    }
}

int peek(struct ll_stack ll) {
    if (is_empty(ll)) {
        printf("Stack kosong...\n");
        exit(EXIT_FAILURE);
    }
    else
        return ll.tail->data;
}

int pop(struct ll_stack *ll) {
    int result;

    if (is_empty(*ll)) {
        printf("Stack kosong...\n");
        exit(EXIT_FAILURE);
    }
    else {
        if (ll->size == 1) {
            struct node *temp = ll->head;
            ll->head = ll->tail = NULL;
            ll->size = 0;
            result = temp->data;
            free(temp);
        }
        else {
            struct node *current = ll->head;

            while (current->next != ll->tail)
                current = current->next;

            struct node *temp = ll->tail;
            ll->tail = current;
            ll->tail->next = NULL;
            ll->size--;
            result = temp->data;
            free(temp);
        }
    }

    return result;
}

int get_size(struct ll_stack ll) {
    return ll.size;
}

void print_stack(struct ll_stack ll) {
    struct node *current = ll.head;
    printf("[");
    while (current != NULL) {
        printf("%d", current->data);
        if (current != ll.tail)
            printf(", ");

        current = current->next;
    }
    printf("]\n");
}

int main(int argc, char const *argv[])
{
    struct ll_stack stack;
    init(&stack);

    // Menambah 5 simpul ke dalam stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    // Menampilkan isi stack
    printf("Sebelum isi stack diambil\n");
    printf("Isi stack \t\t: ");
    print_stack(stack);
    printf("Nilai posisi terakhir \t: %d\n", peek(stack));
    printf("Ukuran stack \t\t: %d\n", get_size(stack));

    // Mengambil isi stack sebanyak 2 kali
    printf("\nMengambil isi stack...\n");
    printf("pop() pertama \t\t: %d\n", pop(&stack));
    printf("pop() kedua \t\t: %d\n", pop(&stack));

    printf("\nSetelah isi stack diambil\n");
    printf("Isi stack \t\t: ");
    print_stack(stack);
    printf("Nilai posisi terakhir \t: %d\n", peek(stack));
    printf("Ukuran stack \t\t: %d\n", get_size(stack));
    
    return 0;
}

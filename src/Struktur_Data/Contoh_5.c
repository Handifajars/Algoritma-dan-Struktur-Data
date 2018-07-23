#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100

struct node {
    int data;
    struct node *next;
};

struct ll_queue {
    // Pointer menunjuk ke simpul pertama
    struct node *head;
    // Pointer menunjuk ke simpul terakhir
    struct node *tail;
    // Jumlah simpul di dalam queue
    int size;
};

void init(struct ll_queue *ll) {
    ll->head = NULL;
    ll->tail = NULL;
    ll->size = 0;       // Mula-mula queue kosong
}

bool is_full(struct ll_queue ll) {
    return ll.size == MAX_NODES;
}

bool is_empty(struct ll_queue ll) {
    return ll.size == 0;
}

// Menambah simpul pada posisi terakhir
void enqueue(struct ll_queue *ll, int value) {
    if (is_full(*ll)) {
        printf("Queue penuh...\n");
        exit(EXIT_FAILURE);
    }
    else {
        struct node *new_node = (struct node *) malloc(sizeof(ll->head));
        new_node->data = value;

        if (is_empty(*ll)) {
            ll->head = new_node;    // Head menunjuk ke simpul baru
            ll->tail = ll->head;    // Tail menunjuk ke simpul yang ditunjuk oleh head
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

// Mengambil data pada simpul pertama dan menghapus simpul yang bersangkutan
int dequeue(struct ll_queue *ll) {
    int result;

    if(is_empty(*ll)) {
        printf("Queue kosong...\n");
        exit(EXIT_FAILURE);
    }
    else {
        struct node *temp = ll->head;
        ll->head = ll->head->next;
        ll->size--;
        result = temp->data;
        free(temp);
    }

    return result;
}

int get_size(struct ll_queue ll) {
    return ll.size;
}

void print_queue(struct ll_queue ll) {
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

int main(int argc, char const *argv[]) {
    struct ll_queue queue;
    init(&queue);

    // Menambah 5 simpul ke dalam queue
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    // Menampilkan isi queue
    printf("Sebelum isi queue diambil\n");
    printf("Isi queue \t\t: ");
    print_queue(queue);
    printf("Ukuran queue \t\t: %d\n", get_size(queue));

    // Mengambil isi queue sebanyak 2 kali
    printf("\nMengambil isi queue...\n");
    printf("dequeue() pertama \t: %d\n", dequeue(&queue));
    printf("dequeue() kedua \t: %d\n", dequeue(&queue));

    printf("\nSetelah isi queue diambil\n");
    printf("Isi queue \t\t: ");
    print_queue(queue);
    printf("Ukuran queue \t\t: %d\n", get_size(queue));

    return 0;
}

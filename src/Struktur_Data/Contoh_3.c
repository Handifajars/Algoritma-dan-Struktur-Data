#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    // Variabel penampung data
    int data;
    // Pointer yang menunjuk ke simpul berikutnya (jika ada)
    struct node *next;
};

struct linked_list {
    // Pointer yang menunjuk ke simpul pertama
    struct node *head;
    // Pointer yang menunjuk ke simpul terakhir
    struct node *tail;
    // Jumlah simpul di dalam linked list
    int size;
};

void init(struct linked_list *ll) {
    ll->head = NULL;
    ll->tail = NULL;
    ll->size = 0;
}

bool is_empty(struct linked_list ll) {
    return ll.size == 0;
}

void add_first(struct linked_list *ll, int value) {
    struct node *new_node = (struct node *) malloc(sizeof(ll->head));
    new_node->data = value;
    // Simpul baru menunjuk ke simpul yang ditunjuk oleh head
    new_node->next = ll->head;
    // Memindahkan pointer head agar menunjuk ke simpul baru
    ll->head = new_node;
    // Jumlah simpul bertambah 1
    ll->size++;
    // Jika simpul baru merupakan satu-satunya simpul di dalam linked list
    if (ll->tail == NULL) {
        // Pointer tail menunjuk ke simpul baru (simpul yang ditunjukk oleh head)
        ll->tail = ll->head;
    }
}

void add_last(struct linked_list *ll, int value) {
    struct node *new_node = (struct node *) malloc(sizeof(ll->head));
    new_node->data = value;

    if (is_empty(*ll)) {
        // Head menunjuk ke simpul baru
        ll->head = new_node;
        // Tail menunjuk ke simpul yang ditunjuk oleh head
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

int get_first(struct linked_list ll) {
    if (is_empty(ll)) {
        printf("List kosong...\n");
        exit(EXIT_FAILURE);
    }
    else
        return ll.head->data;
}

int get_last(struct linked_list ll) {
    if (is_empty(ll)) {
        printf("List kosong...\n");
        exit(EXIT_FAILURE);
    }
    else
        return ll.tail->data;
}

void remove_first(struct linked_list *ll) {
    if (!is_empty(*ll)) {
        struct node *temp = ll->head;
        ll->head = ll->head->next;
        ll->size--;
        free(temp);
    }
}

void remove_last(struct linked_list *ll) {
    if (!is_empty(*ll)) {
        if (ll->size == 1) {
            struct node *temp = ll->head;
            ll->head = ll->tail = NULL;
            ll->size = 0;
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
            free(temp);
        }
    }
}

int get_size(struct linked_list ll) {
    return ll.size;
}

void print_linked_list(struct linked_list ll) {
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
    struct linked_list list;
    init(&list);

    // Menambah simpul menggunakan add_first()
    add_first(&list, 20);

    // Menambah simpul menggunakan add_last()
    add_last(&list, 30);
    add_last(&list, 40);
    add_last(&list, 50);

    // Menambah simpul menggunakan add_first()
    add_first(&list, 10);

    // Menampilkan isi list
    printf("Sebelum isi list dihapus\n");
    printf("Isi list \t\t: ");
    print_linked_list(list);
    printf("Nilai posisi pertama \t: %d\n", get_first(list));
    printf("Nilai posisi terakhir \t: %d\n", get_last(list));
    printf("Ukuran list \t\t: %d\n", get_size(list));

    // Mengambil isi list pada posisi pertama dan terakhir
    printf("\nMengambil isi list...\n");
    printf("Memanggil remove_first()\n");
    remove_first(&list);
    printf("Memanggil remove_last()\n");
    remove_last(&list);

    printf("\nSetelah isi list diambil\n");
    printf("Isi list \t\t: ");
    print_linked_list(list);
    printf("Nilai posisi pertama \t: %d\n", get_first(list));
    printf("Nilai posisi terakhir \t: %d\n", get_last(list));
    printf("Ukuran list \t\t: %d\n", get_size(list));

    return 0;
}

[**KEMBALI**](../README.md)

# Struktur Data

> Saya harap kamu minimal sudah memahami dengan baik konsep penggunaan pointer dan operasi-operasi yang berhubungan dengan pointer.

---

**File ini berisi:**

> Klik salah satu untuk menuju ke pembahasan

[1. Membuat Struktur Data Tumpukan (*Stack*) dengan *Array*](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/master/Materi/Struktur_Data.md#1-membuat-struktur-data-tumpukan-stack-dengan-array)

[2. Membuat Struktur Data Antrian (*Queue*) dengan *Array*](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/master/Materi/Struktur_Data.md#2-membuat-struktur-data-antrian-queue-dengan-array)

[3. Mengimplementasikan *Singly Linked List*](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/master/Materi/Struktur_Data.md#3-mengimplementasikan-singly-linked-list)

[4. Membuat Struktur Data Tumpukan (*Stack*) dengan *Linked List*](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/master/Materi/Struktur_Data.md#4-membuat-struktur-data-tumpukan-stack-dengan-linked-list)

[5. Membuat Struktur Data Antrian (*Queue*) dengan *Linked List*](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/master/Materi/Struktur_Data.md#5-membuat-struktur-data-antrian-queue-dengan-linked-list)

---

![yo dawg](../Images/yo_dawg.jpg)

---

## 1. Membuat Struktur Data Tumpukan (*Stack*) dengan *Array*

**Kasus**

Kita ingin membuat sebuah program dalam bahasa C yang dapat mengimplementasikan struktur data tumpukan (*stack*) dengan menggunakan *array*

**Solusi**

Untuk mengimplementasikan struktur data *stack* di dalam bahasa C, kita dapat mendifinisikan tipe struktur seperti berikut:

```c
#define MAX_CAPACITY 100

struct stack {
    int data[MAX_CAPACITY];
    int top;
    int size;
};
```

Selanjutnya, kita tinggal menambahkan beberapa operasi yang dapat dilakukan terhadap *stack* seperti yang terlihat pada kode program di bawah ini:

- **Contoh_1.c** [Link to File](../src/Struktur_Data/Contoh_1.c)

```c
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
```

Hasil program:

```
Sebelum isi stack diambil
Isi stack               : [10, 20, 30, 40, 50]
Nilai paling atas       : 50
Ukuran stack            : 5

Mengambil isi stack...
pop() pertama           : 50
pop() kedua             : 40

Setelah isi dalam stack diambil
Isi stack               : [10, 20, 30]
Nilai paling atas       : 30
Ukuran stack            : 3
```

**Penjelasan**

Tumpukan (*stack*) merupakan struktur data yang menerapkan konsep LIFO (*last in first out*). Maksudnya, data yang terakhir ditambahkan ke dalam *stack* akan berada di posisi terakhir (atau paling atas jika kita membayangkan elemen-elemen *stack* tersusun secara vertikal); dan ketika proses pengambilan, data terakhir tersebut akan diambil pertama kali. Kita juga bisa membayangkan struktur data *stack* seperti tumpukan *kok* bulu tangkis di dalam wadah tabung, dimana yang terakhir masuk akan diambil keluar pertama kali.

Pada kode program di atas, kita mengimplementasikan fungsi-fungsi berikut:
- `init()`, digunakan untuk inisialisasi (penentuan nilai awal) anggota struktur. Dalam contoh ini, mula-mula `top` bernilai -1 dan `size` bernilai 0.
- `is_empty()`, digunakan untuk memeriksa apakah *stack* kosong atau tidak.
- `is_full()`, digunakan untuk memeriksa apakah *stack* penuh atau tidak.
- `push()`, digunakan untuk menambah data baru ke dalam *stack* pada posisi terakhir.
- `pop()`, digunakan untuk mengambil data terakhir dan menghapusnya dari dalam *stack*.
- `peek()`, digunakan untuk mendapatkan data yang terdapat pada posisi terakhir tanpa menghapus data tersebut.
- `get_size()`, digunakan untuk mendapatkan jumlah data *stack*.
- `print_stack()`, digunakan untuk menampilkan data-data yang terdapat di dalam *stack*.

Kita dapat mendifinisikan fungsi-fungsi tambahan untuk menambah kemampuan-kemampuan lain yang diperlukan, seperti penambahan kapasitas data di dalam *stack*, pencarian data di dalam *stack*, dan sebagainya.

---

## 2. Membuat Struktur Data Antrian (*Queue*) dengan *Array*

**Kasus**

Kita ingin membuat program dengan menggunakan bahasa C yang dapat mengimplementasikan struktur data antrian (*queue*) menggunakan *array*.

**Solusi**

Tipe struktur untuk *queue* dapat diimplementasikan seperti berikut:

```c
struct queue {
	int data[MAX_CAPACITY];
	int size;
	int front;
};
```

Untuk operasi-operasi yang dapat dilakukan terhadap *queue* dapat dilihat pada kode program di bawah ini:

- **Contoh_2.c** [Link to File](../src/Struktur_Data/Contoh_2.c)

```c
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

struct queue {
	int data[MAX_CAPACITY];
	int size;
	int front;
};

void init(struct queue *q) {
	q->size = 0;
	q->front = 0;
}

bool is_full(struct queue q) {
	return q.size == MAX_CAPACITY;
}

bool is_empty(struct queue q) {
	return q.size == 0;
}

void enqueue(struct queue *q, int value) {
	if (is_full(*q)) {
		printf("Queue penuh...");
		exit(EXIT_FAILURE);
	}
	else
		q->data[(q->size)++] = value;
}

int dequeue(struct queue *q) {
	if (is_empty(*q)) {
		printf("Queue kosong...");
		exit(EXIT_FAILURE);
	}
	else {
		q->size--;
		return q->data[(q->front)++];
	}
}

int first(struct queue q) {
	if (is_empty(q)) {
		printf("Queue kosong...");
		exit(EXIT_FAILURE);
	}
	else
		return q.data[q.front];
}

int get_size(struct queue q) {
	return q.size;
}

void print_queue(struct queue q) {
	printf("[");
	for (int i = q.front; i < q.size + q.front; ++i) {
		printf("%d", q.data[i]);
		if (i != (q.size + q.front - 1))
			printf(", ");
	}
	printf("]\n");
}

int main(int argc, char const *argv[]) {
	struct queue q;
	init(&q);

	// Menambah 5 data ke dalam queue
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);

	// Menampilkan isi queue
	printf("Sebelum isi queue diambil\n");
	printf("Isi queue \t\t: ");
	print_queue(q);
	printf("Nilai paling depan \t: %d\n", first(q));
	printf("Ukuran queue \t\t: %d\n", get_size(q));

	// Mengambil isi queue sebanyak 2 kali
	printf("\nMengambil isi queue...\n");
	printf("dequeue() pertama \t: %d\n", dequeue(&q));
	printf("dequeue() kedua \t: %d\n", dequeue(&q));
	
	printf("\nSetelah isi queue diambil\n");
	printf("Isi queue \t\t: ");
	print_queue(q);
	printf("Nilai paling depan \t: %d\n", first(q));
	printf("Ukuran queue \t\t: %d\n", get_size(q));

	return 0;
}
```

Hasil program:

```
Sebelum isi queue diambil
Isi queue               : [10, 20, 30, 40, 50]
Nilai paling depan      : 10
Ukuran queue            : 5

Mengambil isi queue...
dequeue() pertama       : 10
dequeue() kedua         : 20

Setelah isi queue diambil
Isi queue               : [30, 40, 50]
Nilai paling depan      : 30
Ukuran queue            : 3
```

**Penjelasan**

Antrian (*queue*) merupakan struktur data yang menerapkan konsep FIFO (*first in first out*). Data atau data yang pertama ditambahkan ke dalam *queue* akan diambil pertama kali juga.

Pada implementasi di atas, kita mendefinisikan fungsi-fungsi berikut:
- `is_empty()`, digunakan untuk memeriksa apakah *queue* kosong atau tidak.
- `is_full()`, digunakan untuk memeriksa apakah *queue* penuh atau tidak.
- `enqueue()`, digunakan untuk menambah data baru ke dalam *queue* pada posisi pertama.
- `dequeue()`, digunakan untuk mengambil data pertama dan menghapusnya dari dalam *queue*.
- `first()`, digunakan untuk mendapatkan data yang terdapat pada posisi pertama tanpa menghapus data tersebut.
- `get_size()`, digunakan untuk mendapatkan jumlah data di dalam *queue*.
- `print_queue()`, digunakan untuk menampilkan data-data yang terdapat di dalam *queue*.

---

## 3. Mengimplementasikan *Singly Linked List*

**Kasus**

Kita ingin menyimpan beberapa data yang dirangkai menggunakan *pointer* sehingga menjadi *linked list* satu arah (*singly linked list*).

**Solusi**

Untuk mengimplementasikan *linked list* di dalam bahasa C, kita perlu mendefinisikan tipe struktur untuk simpul (*node*). Di dalam *linked list*, simpul merepresentasikan satu buah elemen data. Selain data, simpul juga harus memiliki *pointer*, yang digunakan untuk menunjuk ke simpul berikutnya yang terdapat di dalam rangkaian simpul-simpul. Jika kamu masih belum mengerti, kamu bisa cek di sini: [A Comprehensive Guide to Implementation of Singly Linked List](https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr). Tipe struktur untuk *node* dapat ditulis seperti berikut:

```c
struct node {
    // Variabel penampung data
    int data;
    // Pointer yang menunjuk ke simpul berikutnya (jika ada)
    struct node *next;
};
```

Setelah tipe struktur untuk *node* terdefinisi, berikutnya kita dapat mendefinisikan tipe struktur untuk *linked list* menggunakan kode berikut:

```c
struct linked_list {
    // Pointer yang menunjuk ke simpul pertama
    struct node *head;
    // Pointer yang menunjuk ke simpul terakhir
    struct node *tail;
    // Jumlah simpul di dalam linked list
    int size;
};
```

Operasi yang dapat diterapkan *linked list* sebenarnya cukup banyak, tapi kita hanya akan mengimplementasikan beberapa fungsi seperti yang terdapat pada kode program di bawah ini:

- **Contoh_3.c** [Link to File](../src/Struktur_Data/Contoh_3.c)
    - [VERSI LENGKAP (C++)](../src/Struktur_Data/SLL_CPP.cpp)

```c
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
```

Hasil program:

```
Sebelum isi list dihapus
Isi list                : [10, 20, 30, 40, 50]
Nilai posisi pertama    : 10
Nilai posisi terakhir   : 50
Ukuran list             : 5

Mengambil isi list...
Memanggil remove_first()
Memanggil remove_last()

Setelah isi list diambil
Isi list                : [20, 30, 40]
Nilai posisi pertama    : 20
Nilai posisi terakhir   : 40
Ukuran list             : 3
```

Pada struktur *linked list* di atas, kita mendeklarasikan tiga anggota yaitu:
- `head` (kepala), *pointer* yang digunakan untuk menunjuk ke simpul pertama di dalam *linked list*.
- `tail` (ekor), *pointer* yang digunakan untuk menunjuk ke simpul terakhir di dalam *linked list*.
- `size`, digunakan untuk menyatakan jumlah simpul di dalam *linked list*.

Pada pembuatan struktur data *linked list* di atas, kita hanya mengimplementasikan fungsi-fungsi berikut:
- `init()`, digunakan untuk melakukan inisialisasi *pointer* `head` dan `tail` serta penentuan nilai awal dari variabel `size`.
- `is_empty()`, digunakan untuk memeriksa apakah *linked list* kosong atau tidak.
- `add_first()`, digunakan untuk menambahkan simpul baru ke dalam *linked list* pada posisi pertama.
- `add_last()`, digunakan untuk menambahkan simpul baru ke dalam *linked list* pada posisi terakhir.
- `get_first()`, digunakan untuk mendapatkan data yang terdapat pada simpul pertama.
- `get_last()`, digunakan untuk mendapatkan data yang terdapat pada simpul terakhir.
- `remove_first()`, digunakan untuk menghapus simpul pertama.
- `remove_last()`, digunakan untuk menghapus simpul terakhir.
- `get_size()`, digunakan untuk mendapatkan jumlah simpul di dalam *linked list*.
- `print_linked_list()`, digunakan untuk mencetak data yang tersimpan di setiap simpul di dalam *linked list*.

Di dalam file versi lengkapnya: [Contoh_3.1.cpp](../src/Struktur_Data/C++/Contoh_3.1.cpp), saya sudah kembangkan sendiri implementasi dari *linked list* di atas dengan mendefinisikan operasi-operasi berikut:

- `contains(value)`, fungsi untuk memeriksa apakah data ada di dalam *linked list* atau tidak.
- `index_of(value)`, fungsi untuk mengembalikan index dari simpul yang berisi `data` = value.
- `get_data(index)`, fungsi yang mengembalikan data yang terkandung di dalam simpul pada posisi ke-`index`.
- `set_data(index, value)`, fungsi untuk mengubah data yang terkandung di dalam simpul pada posisi ke-`index`.
- `insert(index, value)`, fungsi untuk menyisipkan simpul baru pada posisi ke-`index`.
- `remove_at(index)`, fungsi untuk menghapus simpul yang terdapat pada posisi ke-`index`.
- `clear()`, fungsi untuk menghapus semua simpul di dalam `linked list`, rm -rf wkwkwk :v.

**Implementasi fungsi `add_first()`**

Untuk menambah simpul baru pada posisi pertama *list*, mula-mula kita perlu membuat simpul yang akan ditambahkan dengan cara mendeklarasikan *pointer* ke tipe `node`. Dalam contoh ini, kita menamai *pointer* dengan nama `new_node`. *Pointer* tersebut kita perintahkan untuk menunjuk ke memori yang dialokasikan menggunakan `malloc()`. Anggota `next` dari `new_node` perlu diarahkan ke simpul yang sedang ditunjuk oleh `head`. Melalui cara seperti ini, `new_node` akan berada di awal *list*.

```c
// Simpul baru menunjuk ke simpul yang ditunjuk oleh head
new_node->next = ll->head;
```

Selanjutnya, kita perlu mengubah *pointer* `head` untuk menunjuk ke `new_node`. Ini menyatakan bahwa simpul awal di dalam *list* telah diganti dengan `new_node`.

```c
// Memindahkan pointer head agar menunjuk ke simpul baru
ll->head = new_node;
```

Penambahan simpul juga akan mempengaruhi jumlah simpul di dalam *linked list* (bertambah satu). Kita dapat menambah jumlah atau ukuran simpul di dalam *linked list* dengan menggunakan baris kode berikut:

```c
// Jumlah simpul bertambah 1
ll->size++;
```

Jika sebelum pemanggilan metode `add_first()` *linked list* masih dalam keadaan kosong, maka `new_node` akan berperan sebagai satu-satunya simpul yang terdapat di dlam *linked list*. Oleh karena itu *pointer* `tail` juga harus diarahkan ke objek yang sedang ditunjuk oleh *pointer* `head`. Artinya, `new_node` akan berperan sebagai simpul pertama dan juga simpul terakhir.

```c
if (ll->tail == NULL) {
    // Pointer tail menunjuk ke simpul baru (simpul yang ditunjukk oleh head)
    ll->tail = ll->head;
}
```

**Implementasi fungsi `add_last()`**

Fungsi `add_last()` digunakan untuk menambah simpul baru ke dalam *list* pada posisi paling akhir. Jika pada saat pemanggilan fungsi `add_last()` *linked list* masih kosong, maka simpul baru yang akan ditambahkan akan menjadi simpul satu-satunya di dalam *linked list*. Artinya, simpul tersebut akan berperan sebagai simpul pertama (ditunjuk oleh *pointer* `head`). dan juga sebagai simpul terakhir (ditunjuk oleh *pointer* `tail`). Jika *linked list* sudah memiliki simpul, pemanggilan `add_last()` akan mengaitkan simpul terakhir ke simpul baru melalui baris kode berikut:

```c
// Menghubungkan simpul terakhir dengan simpul baru
ll->tail->next = new_node;
```

Setelah itu, *pointer* `tail` dipindah untuk menunjuk ke simpul baru melalui kode berikut:

```c
// Tail menunjuk ke simpul baru
ll->tail = ll->tail->next;
```

Terakhir `add_last()` akan mengubah jumlah simpul di dalam *linked list* melalui kode berikut:

```c
ll->size++;
```

**Implementasi fungsi `remove_first()`**

Fungsi `remove_first()` digunakan untuk menghapus simpul pertama. Proses penghapusan ini akan menyebabkan *pointer* `head` berpindah ke simpul berikutnya (jika ada). Sebelum dihapus, kita dapat menampung terlebih dahulu simpul bersangkutan ke dalam *pointer* `temp`, kemudian menghapusnya secara eksplisit dengan memanggil fungsi `free()`.


**Implementasi fungsi `remove_last()`**

Fungsi `remove_last()` digunakan untuk menghapus simpul terakhir di dalam *linked list* (untuk *linked list* yang sudah memiliki simpul). Jika *list* hanya memiliki satu simpul, pemanggilan fungsi `remove_last()` akan menyebabkan *pointer* `head` dan `tail` bernilai `NULL` serta jumlah simpul menjadi 0.

```c
ll->head = ll->tail = NULL;
ll->size = 0;
```

Jika jumlah simpul di dalam *linked list* lebih dari 1, maka kita perlu memindahkan *pointer* `tail` untuk menunjuk ke simpul yang berada sebelum simpul terakhir. Ini berarti bahwa simpul terakhir akan dihapus dan simpul sebelum simpul terakhir dijadikan sebagai simpul terakhir. Pemanggilan fungsi `remove_last()` akan menyebabkan jumlah simpul di dalam *linked list* berkurang 1. Proses ini dapat dilakukan menggunakan kode berikut:

```c
struct node *current = ll->head;

while (current->next != ll->tail)
    current = current->next;

struct node *temp = ll->tail;
ll->tail = current;
ll->tail->next = NULL;
ll->size--;
free(temp);
```

pada kode di atas, *pointer* `current` digunakan untuk menunjuk ke simpul sebelum simpul terakhir (saat *linked list* masih berada dalam keadaan semula atau sebelum dihapus).

**Implementasi fungsi `get_first()`**

Fungsi `get_first()` akan mengembalikan data atau nilai yang terkandung pada simpul pertama. Jika *list* masih dalam keadaan kosong, pemanggilan `get_first()` tidak akan menghasilkan apa-apa dan program akan dihentikan.

**Implementasi fungsi `get_last()`**

Fungsi `get_last()` akan mengembalikan data atau nilai yang terkandung pada simpul terakhi. Jika *list* belum memiliki simpul (masih kosong), maka pemanggilan fungsi `get_last()` tidak akan menghasilkan nilai dan program akan dihentikan.

---

## 4. Membuat Struktur Data Tumpukan (*Stack*) dengan *Linked List*

**Kasus**

Kita ingin menggunakan *linked list* untuk mengimplementasikan struktur data *stack*.

**Solusi**

Untuk membuat *stack* dengan menggunakan *linked list* dapat menggunakan kode berikut:

- **Contoh_4.c** [Link to File](../src/Struktur_Data/Contoh_4.c)

```c
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
```

Hasil program:

```
Sebelum isi stack diambil
Isi stack               : [10, 20, 30, 40, 50]
Nilai posisi terakhir   : 50
Ukuran stack            : 5

Mengambil isi stack...
pop() pertama           : 50
pop() kedua             : 40

Setelah isi stack diambil
Isi stack               : [10, 20, 30]
Nilai posisi terakhir   : 30
Ukuran stack            : 3
```

**Penjelasan**

Pada pembuatan *stack* di atas, fungsi `push()` diimplementasikan menggunakan kode berikut:

```c
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
```

Fungsi ini akan menambahkan simpul baru ke dalam *stack* pada posisi terakhir. Implementasi fungsi ini sebenarnya sama dengan fungsi `add_last()` yang telah saya bahas di konsep *linked list* sebelumnya.

Untuk mendapatkan data atau nilai dari simpul terakhir yang terdapat di dalam *stack*, kita mengimplementasikan dua fungsi, yaitu `peek()` dan `pop()`.

```c
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
```

Pada fungsi `peek()`, kita hanya mendapatkan nilai dari simpul terakhir tanpa menghapus simpul yang bersangkutan dari dalam *stack*. Pada fungsi `pop()`, kita mengambil nilai dari simpul terakhir dan kemudian menghapus simpul tersebut. Dengan demikian, pemanggilan `pop()` akan menyebabkan jumlah simpul di dalam *stack* berkurang 1.

---

## 5. Membuat Struktur Data Antrian (*Queue*) dengan *Linked List*

**Kasus**

Kita ingin menggunakan *linked list* untuk mengimplementasikan struktru data *queue*.

**Solusi**

Untuk membuat *queue* menggunakan *linked lsit*, kita dapat menggunakan kode program berikut:

- **Contoh_5.c** [Link to File](../src/Struktur_Data/Contoh_5.c)

```c
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

// Mengecek ukuran queue apakah penuh?
bool is_full(struct ll_queue ll) {
    return ll.size == MAX_NODES;
}

// Mengecek ukuran queue apakah kosong?
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
```

Hasil program:

```
Sebelum isi queue diambil
Isi queue               : [10, 20, 30, 40, 50]
Ukuran queue            : 5

Mengambil isi queue...
dequeue() pertama       : 10
dequeue() kedua         : 20

Setelah isi queue diambil
Isi queue               : [30, 40, 50]
Ukuran queue            : 3
```

**Penjelasan**

Pada contoh pembuatan *queue* di atas, kita mengimplementasikan fungsi-fungsi berikut:

- `init()`, digunakan untuk melakukan inisialisasi *queue*.
- `is_full()`, digunakan untuk memeriksa apakah *queue* sudah penuh?.
- `is_empty()`, digunakan untuk memeriksa apakah *queue* kosong?.
- `enqueue()`, digunakan untuk menambah simpul baru ke dalam *queue* pada posisi terakhir.
- `dequeue()`, digunakan untuk mendapatkan data yang terdapat pada simpul pertama dan menghapus simpul yang bersangkutan.
- `get_size()`, digunakan untuk mendapatkan jumlah simpul di dalam *queue*.
- `print_queue()`, digunakan untuk menampilkan data-data *queue* dalam bentuk *string*.

---

> Raharjo, Budi. 2016. Kumpulan Solusi Pemrograman C. Bandung: INFORMATIKA.
> https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr

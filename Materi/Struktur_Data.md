[**KEMBALI**](../README.md)

# Struktur Data

**File ini berisi:**

> Klik salah satu untuk menuju ke pembahasan

[1. Membuat Struktur Data Tumpukan (*Stack*) dengan *Array*](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/master/Materi/Struktur_Data.md#1-membuat-struktur-data-tumpukan-stack-dengan-array)

[2. Membuat Struktur Data Antrian (*Queue*) dengan *Array*](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/master/Materi/Struktur_Data.md#2-membuat-struktur-data-antrian-queue-dengan-array)

[3. Mengimplementasikan *Singly Linked List*](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/master/Materi/Struktur_Data.md#3-mengimplementasikan-singly-linked-list)

[4. Membuat Struktur Data Tumpukan (*Stack*) dengan *Linked List*](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/master/Materi/Struktur_Data.md#4-membuat-struktur-data-tumpukan-stack-dengan-linked-list)

[5. Membuat Struktur Data Antrian (*Queue*) dengan *Linked List*](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/master/Materi/Struktur_Data.md#5-membuat-struktur-data-antrian-queue-dengan-linked-list)

![alt text](../Images/yo_dawg.jpg)

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
- `push()`, digunakan untuk menambah elemen baru ke dalam *stack* pada posisi terakhir.
- `pop()`, digunakan untuk mengambil elemen terakhir dan menghapusnya dari dalam *stack*.
- `peek()`, digunakan untuk mendapatkan elemen yang terdapat pada posisi terakhir tanpa menghapus elemen tersebut.
- `get_size()`, digunakan untuk mendapatkan jumlah elemen *stack*.
- `print_stack()`, digunakan untuk menampilkan elemen-elemen yang terdapat di dalam *stack*.

Kita dapat mendifinisikan fungsi-fungsi tambahan untuk menambah kemampuan-kemampuan lain yang diperlukan, seperti penambahan kapasitas elemen di dalam *stack*, pencarian elemen di dalam *stack*, dan sebagainya.

---

## 2. Membuat Struktur Data Antrian (*Queue*) dengan *Array*

**Kasus**

Kita ingin membuat program dengan menggunakan bahasa C yang dapat mengimplementasikan struktur data antrian (*queue*) menggunakan *array*.

**Solusi**

Tipe struktur untuk *queue* dapat diimplementasikan seperti berikut:

```c

```

Untuk operasi-operasi yang dapat dilakukan terhadap *queue* dapat dilihat pada kode program di bawah ini:

```c

```

---

## 3. Mengimplementasikan *Singly Linked List*

**Kasus**

**Solusi**

---

## 4. Membuat Struktur Data Tumpukan (*Stack*) dengan *Linked List*

**Kasus**

**Solusi**

---

## 5. Membuat Struktur Data Antrian (*Queue*) dengan *Linked List*

**Kasus**

**Solusi**

---

> Raharjo, Budi. 2016. Kumpulan Solusi Pemrograman C. Bandung: INFORMATIKA.

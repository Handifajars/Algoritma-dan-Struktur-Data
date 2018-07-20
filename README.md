Quote:

> "The best way to learn to code is to code"

# Algoritma dan Struktur Data

## Mengimplementasikan Algoritma Pencarian Beruntun (*Sequential Search*)

**Kasus**

Kita ingin melakukan pencarian data di dalam suatu *array*, kita bisa menggunakan algoritma pencarian beruntun (*sequential search*).

**Solusi**

Di dalam bahasa C, algoritma pencarian berutun dapat diimplementasikan menggunakan fungsi berikut:

```c++
bool sequential_search(int array[], size_t size, int value) {
    int pos = 0;
    bool found = false;

    while (pos < size && !found) {
        if (array[pos] == value)
            found = true;
        else
            ++pos;
    }

    return found;
}
```

Contoh penggunaan dari fungsi di atas dapat dilihat pada kode program di bawah ini:

- **Contoh 1.c**

```c++
#include <stdio.h>
#include <stdbool.h>

bool sequential_search(int array[], size_t size, int value) {
    int pos = 0;
    bool found = false;

    while (pos < size && !found) {
        if (array[pos] == value)
            found = true;
        else
            ++pos;
    }

    return found;
}

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}


int main(int argc, char const *argv[]) {
    int data[5] = {300, 200, 500, 400, 100};
    size_t size = sizeof(data) / sizeof(data[0]);

    /* Menampilkan elemen dari array */
    printf("Isi array: ");
    print_array(data, size);

    /* Mencari nilai */
    printf("\nNilai 200 %s\n", sequential_search(data, size, 200) ? "ditemukan" : "tidak ditemukan");
    printf("Nilai 400 %s\n", sequential_search(data, size, 400) ? "ditemukan" : "tidak ditemukan");
    printf("Nilai 700 %s\n", sequential_search(data, size, 700) ? "ditemukan" : "tidak ditemukan");
    printf("Nilai 900 %s\n", sequential_search(data, size, 900) ? "ditemukan" : "tidak ditemukan");

    return 0;
}
```

Hasil Program:

```
Isi array: [300, 200, 500, 400, 100]

Nilai 200 ditemukan
Nilai 400 ditemukan
Nilai 700 tidak ditemukan
Nilai 900 tidak ditemukan
```

**Penjelasan**

Dengan menggunakan metode pencarian beruntun (*sequential search*) atau yang juga disebut dengan pencarian lurus (*linear search*), nilai yang dicari dibandingkan dengan nilai dari setiap elemen *array* data, mulai dari elemen pertama sampai nilai yang dicari ditemukan atau sampai elemen terakhir.

Pada contoh kode program di atas, fungsi `sequential_search()` akan mengembalikan nilai `true` jika nilai yang dicari ditemukan di dalam *array* data dan `false` jika tidak ditemukan. Pada beberapa kasus, terkadang kita ingin mengetahui indeks dari nilai yang ditemukan, bukan hanya sekedar informasi `true` atau `false` saja. Untuk memenuhi kebutuhan seperti ini, kita dapat memodifikasi kode di atas menjadi seperti berikut:

- **Contoh 2.c**

```c++
#include <stdio.h>
#include <stdbool.h>

int sequential_search(int array[], size_t size, int value) {
    int pos = 0;
    bool found = false;

    while (pos < size && !found) {
        if (array[pos] == value)
            found = true;
        else
            ++pos;
    }

    return found ? pos : -1;
}

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}


int main(int argc, char const *argv[]) {
    int data[5] = {300, 200, 500, 400, 100};
    size_t size = sizeof(data) / sizeof(data[0]);

    /* Menampilkan elemen dari array */
    printf("Isi array: ");
    print_array(data, size);

    /* Mencari nilai */
    printf("\nNilai 200: %d\n", sequential_search(data, size, 200));
    printf("Nilai 400: %d\n", sequential_search(data, size, 400));
    printf("Nilai 700: %d\n", sequential_search(data, size, 700));
    printf("Nilai 900: %d\n", sequential_search(data, size, 900));

    return 0;
}
```

Hasil program:

```
Isi array: [300, 200, 500, 400, 100]

Nilai 200: 1
Nilai 400: 3
Nilai 700: -1
Nilai 900: -1
```

Nilai -1 yang terdapat pada hasil di atas digunakan untuk mendandakan bahwa nilai yang dicari tidak ditemukan di dalam *array* data.

Dua kode program yang di atas sebenarnya dapat diterapkan untuk *array* yang datanya terurut maupun tidak terurut. Akan tetapi untuk kasus *array* yang datanya terurut kita dapat melakukan penghematan proses pencarian, yaitu dengan menghentikan pencarian ketika nilai yang kita cari lebih kecil dari salah satu nilai *array* pada posisi tertentu (ini pada *array* terurut), untuk data yang berjumlah kecil tidak akan terasa, tapi untuk data yang berjumlah sangat besar baru terasa. Untuk mengimplementasikan hal ini kita dapat menggunakan kode berikut:

- **Contoh 3.c**

```c++
#include <stdio.h>
#include <stdbool.h>

int sequential_search(int array[], size_t size, int value) {
    int pos = 0;
    bool found = false, stop = false;

    while (pos < size && !found && !stop) {
        if (array[pos] == value)
            found = true;
        else
            if (array[pos] > value)
                stop = true;
            else
                ++pos;
    }

    return found ? pos : -1;
}

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}


int main(int argc, char const *argv[]) {
    int data[5] = {100, 200, 300, 400, 500};
    size_t size = sizeof(data) / sizeof(data[0]);

    /* Menampilkan elemen dari array */
    printf("Isi array: ");
    print_array(data, size);

    /* Mencari nilai */
    printf("\nNilai 100: %d\n", sequential_search(data, size, 100));
    printf("Nilai 250: %d\n", sequential_search(data, size, 250));
    printf("Nilai 300: %d\n", sequential_search(data, size, 300));
    printf("Nilai 700: %d\n", sequential_search(data, size, 700));

    return 0;
}
```

Hasil program:

```
Isi array: [100, 200, 300, 400, 500]

Nilai 100: 0
Nilai 250: -1
Nilai 300: 2
Nilai 700: -1
```

Ketika mencari nilai 250, proses perbandingan hanya dilakukan 2 kali, yaitu perbandingan nilai antara 250 dengan elemen pertama & elemen kedua di dalam *array* data. Pada saat indeks pengulangan (variabel `pos`) mencapai 2, proses pengulangan akan dihentikan. Hal ini disebabkan karena nilai elemen pada indeks ke-2 (nilai 300) lebih besar dari nilai yang dicari (nilai 250). Hal ini tentu akan menghemat proses pencarian.

## Mengimplementasikan Algoritma Pencarian Bagi-Dua (*Binary Search*)

**Kasus**

Kita ingin melakukan pencarian data di dalam suatu *array* menggunakan algoritma pencarian bagi-dua (*Binary Search*).

**Solusi**

Di dalam bahasa C, algoritma pencarian bagi-dua diimplementasikan menggunakan fungsi berikut:



> Sumber: Buku berjudul KUMPULAN SOLUSI PEMROGRAMAN C, ditulis oleh BUDI RAHARJO, penerbit INFORMATIKA

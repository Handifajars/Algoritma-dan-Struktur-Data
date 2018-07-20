# Algoritma dan Struktur Data

## Mengimplementasikan Algoritma Pencarian Beruntun

Ketika kamu ingin melakukan pencarian data di dalam suatu array, kamu bisa menggunakan algoritma pencarian beruntun (*sequential search*)

Di dalam bahasa C, algoritma pencarian berutun dapat diimplementasikan menggunakan fungsi berikut:

```c++
bool sequential_search(int array[], size_t size, int value) {
    int pos = 0;
    bool found = false;

    while (pos < size && !found) {
        if (array[pos] == value)
            found = true;
        else
            pos += 1;
    }

    return found;
}
```

Contoh penggunaan dari fungsi di atas dapat dilihat pada kode program di bawah ini:

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
            pos += 1;
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

Dengan menggunakan metode pencarian beruntun (*sequential search*) atau yang juga disebut dengan pencarian lurus (*linear search*), nilai yang dicari dibandingkan dengan nilai dari setiap elemen array data, mulai dari elemen pertama sampai nilai yang dicari ditemukan atau sampai elemen terakhir.

Pada contoh kode program di atas, fungsi `sequential_search()` akan mengembalikan nilai `true` jika nilai yang dicari ditemukan di dalam array data dan `false` jika tidak ditemukan.

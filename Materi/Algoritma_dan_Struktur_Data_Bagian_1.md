[**KEMBALI**](../README.md)

# Algoritma dan Struktur Data Bagian 1

**File ini berisi materi:**

1. [Mengimplementasikan Algoritma Pencarian Beruntun (*Sequential Search*)](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/penulisan/Materi/Algoritma_dan_Struktur_Data_Bagian_1.md#1-mengimplementasikan-algoritma-pencarian-beruntun-sequential-search)
2. [Mengimplementasikan Algoritma Pencarian Bagi-Dua (*Binary Search*)](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/penulisan/Materi/Algoritma_dan_Struktur_Data_Bagian_1.md#2-mengimplementasikan-algoritma-pencarian-bagi-dua-binary-search)
3. [Mengimplementasikan Algoritma Pengurutan Gelembung (*Bubble Sort*)](https://github.com/mramirid/Algoritma-dan-Struktur-Data/blob/penulisan/Materi/Algoritma_dan_Struktur_Data_Bagian_1.md#3-mengimplementasikan-algoritma-pengurutan-gelembung-bubble-sort)
4. [Mengimplementasikan Algoritma Pengurutan Seleksi (*Selection Sort*)]()
5. [Mengimplementasikan Algoritma Pengurutan Sisipan (*Insertion Sort*)]()
6. [Mengimplementasikan Algoritma Pengurutan Shell (*Shell Sort*)]()



### 1. Mengimplementasikan Algoritma Pencarian Beruntun (*Sequential Search*)

**Kasus**

Kita ingin melakukan pencarian data di dalam suatu *array*, kita bisa menggunakan algoritma pencarian beruntun (*sequential search*).

**Solusi**

Di dalam bahasa C, algoritma pencarian berutun dapat diimplementasikan menggunakan fungsi berikut:

```c
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

- **Contoh 1.c** [File](../src/Contoh_1.c)

```c
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

    // Menampilkan elemen dari array
    printf("Isi array: ");
    print_array(data, size);

    // Mencari nilai
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

- **Contoh 2.c** [File](../src/Contoh_2.c)

```c
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

    // Menampilkan elemen dari array
    printf("Isi array: ");
    print_array(data, size);

    // Mencari nilai
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

Dua kode program yang di atas sebenarnya dapat diterapkan untuk *array* yang datanya terurut maupun tidak terurut. Akan tetapi untuk kasus *array* yang datanya terurut kita dapat melakukan penghematan proses pencarian, yaitu dengan menghentikan pencarian ketika nilai yang kita cari lebih kecil dari salah satu nilai *array* pada posisi tertentu (ini pada *array* terurut) atau dengan kata lain mencegah proses agar tidak melanjutkan pencarian sampai akhir data (tidak perlu dicari sampai akhir jika data yang diinginkan sudah ketemu), pada kasus ini, untuk data yang berjumlah kecil tidak akan terasa lama prosesnya, tapi untuk data yang berjumlah sangat besar akan baru terasa lama prosesnya. Untuk mengimplementasikan hal ini kita dapat menggunakan kode berikut:

- **Contoh 3.c** [File](../src/Contoh_3.c)

```c
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

    // Menampilkan elemen dari array
    printf("Isi array: ");
    print_array(data, size);

    // Mencari nilai
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

### 2. Mengimplementasikan Algoritma Pencarian Bagi-Dua (*Binary Search*)

**Kasus**

Kita ingin melakukan pencarian data di dalam suatu *array* menggunakan algoritma pencarian bagi-dua (*Binary Search*).

**Solusi**

Di dalam bahasa C, algoritma pencarian bagi-dua diimplementasikan menggunakan fungsi berikut:

```c
int binary_search(int array[], int first, int last, int value) {
    int middle;
    bool found = false;

    while (first <= last && !found) {
        middle = (first + last) / 2;

        if (array[middle] == value)
            found = true;
        else
            if (value < array[middle])
                last = middle - 1;
            else
                first = middle + 1;
    }

    return found ? middle : -1;
}
```

Contoh kode program di bawah ini menunjukkan penggunaan fungsi di atas:

- **Contoh 4.c** [File](../src/Contoh_4.c)

```c
#include <stdio.h>
#include <stdbool.h>

int binary_search(int array[], int first, int last, int value) {
    int middle;
    bool found = false;

    while (first <= last && !found) {
        middle = (first + last) / 2;

        if (array[middle] == value)
            found = true;
        else
            if (value < array[middle])
                last = middle - 1;
            else
                first = middle + 1;
    }

    return found ? middle : -1;
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

main(int argc, char const *argv[]) {
    int data[5] = {100, 200, 300, 400, 500};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array
    printf("Isi array: ");
    print_array(data, size);

    // Mencari nilai
    printf("\nIndeks dari nilai 200: %d\n", binary_search(data, 0, 4, 200));
    printf("Indeks dari nilai 400: %d\n", binary_search(data, 0, 4, 400));
    printf("Indeks dari nilai 700: %d\n", binary_search(data, 0, 4, 700));
    printf("Indeks dari nilai 900: %d\n", binary_search(data, 0, 4, 900));

    return 0;
}
```

Hasil program:

```
Isi array: [100, 200, 300, 400, 500]

Indeks dari nilai 200: 1
Indeks dari nilai 400: 3
Indeks dari nilai 700: -1
Indeks dari nilai 900: -1
```

**Penjelasan**

Metode pencarian bagi-dua harus diterapkan untuk *array* yang datanya sudah berada dalam keadaan terurut. Maka, sebelum digunakan di dalam proses pencarian, kita perlu memastikan bahwa data di *array* telah terurut. Proses pengurutan dapat dilakukan dengan mendefinisikan fungsi lain (jika perlu).

Cara kerja algoritma pencarian bagi-dua adalah dengan membagi elemen-elemen *array* menjadi 2 bagian secara berulang. Jika elemen tengah (`array[middle]`) sama dengan nilai yang dicari (`value`), maka proses pencarian dihentikan dan nilai `middle` (indeks dari elemen tengah) dinyatakan sebagai hasil. Jika nilai yang dicari lebih kecil dari elemen tengah, maka proses pencarian dilakukan pada *array* sebelah kiri. Jika lebih besar, maka proses pencarian dilakukan pada bagian *array* sebelah kanan; dengan asumsi bahwa elemen-elemen *array* terurut secara menaik (*ascending*)

Algoritma pencarian bagi-dua juga dapat diimplementasikan menggunakan fungsi rekursi, seperti kode di bawah ini:

```c
int binary_search(int array[], int first, int last, int value) {
    if (last < first)
        return -1;

    int middle = (first + last) / 2;

    if (value < array[middle])
        return binary_search(array, first, middle - 1, value);
    else if (value > array[middle])
        return binary_search(array, middle + 1, last, value);
    else
        return middle;
}
```

Contoh penerapannya dapat dilihat pada kode di bawah ini:

- **Contoh 5.c** [File](../src/Contoh_5.c)

```c
#include <stdio.h>
#include <stdbool.h>

int binary_search(int array[], int first, int last, int value) {
    if (last < first)
        return -1;

    int middle = (first + last) / 2;

    if (value < array[middle])
        return binary_search(array, first, middle - 1, value);
    else if (value > array[middle])
        return binary_search(array, middle + 1, last, value);
    else
        return middle;
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

main(int argc, char const *argv[]) {
    int data[5] = {100, 200, 300, 400, 500};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array
    printf("Isi array: ");
    print_array(data, size);

    // Mencari nilai
    printf("\nIndeks dari nilai 200: %d\n", binary_search(data, 0, 4, 200));
    printf("Indeks dari nilai 400: %d\n", binary_search(data, 0, 4, 400));
    printf("Indeks dari nilai 700: %d\n", binary_search(data, 0, 4, 700));
    printf("Indeks dari nilai 900: %d\n", binary_search(data, 0, 4, 900));

    return 0;
}
```

Hasil program:

```
Isi array: [100, 200, 300, 400, 500]

Indeks dari nilai 200: 1
Indeks dari nilai 400: 3
Indeks dari nilai 700: -1
Indeks dari nilai 900: -1
```

### 3. Mengimplementasikan Algoritma Pengurutan Gelembung (*Bubble Sort*)

**Kasus**

Kita ingin melakukan pengurutan data di dalam suatu *array* menggunakan algoritma pengurutan gelembung (*bubble sort*)

**Solusi**

Dalam bahasa C, algoritma pengurutan gelembung dapat diimplementasikan menggunakan fungsi berikut:

```c
void bubble_sort(int *array, int size) {
    int temp;

    for (int i = 0; i < size - 1; ++i)
        for (int j = size - 1; j > i; --j)
            if (array[j] < array[j - 1]) {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
}
```

Contoh penggunaan fungsi bubble_sort() di atas dapat dilihat pada kode program di bawah ini:

- **Contoh 6.c** [File](../src/Contoh_6.c)

```c
#include <stdio.h>

void bubble_sort(int *array, size_t size) {
    int temp;

    for (int i = 0; i < size - 1; ++i)
        for (int j = size - 1; j > i; --j)
            if (array[j] < array[j - 1]) {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
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

main(int argc, char const *argv[]) {
    int data[8] = {9, 7, 10, 8, 12, 11, 14, 13};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array sebelum diurutkan
    printf("Sebelum diurutkan: ");
    print_array(data, size);

    // Mengurutkan array
    bubble_sort(data, size);

    // Menampilkan elemen array setelah diurutkan
    printf("Setelah diurutkan: ");
    print_array(data, size);

    return 0;
}
```

Hasil program:

```
Sebelum diurutkan: [9, 7, 10, 8, 12, 11, 14, 13]
Setelah diurutkan: [7, 8, 9, 10, 11, 12, 13, 14]
```

**Penjelasan**

Dalam proses pengurutan data menggunakan algoritma gelembung, n elemen data akan diurutkan melalui n-1 langkah (direpresentasikan menggunakan variabel `i`). Dalam setiap langkah, program akan membandingkan elemen ke-`j` dengan elemen ke-(`j-1`) secara berulang mulai dari elemen terakhir sampai elemen ke-(`i+1`). Jika `array[j]` lebih kecil dari `array[j-1]` maka kedua elemen tersebut akan ditukar menggunakan kode berikut:

```c
temp = array[j];
array[j] = array[j - 1];
array[j - 1] = temp;
```

Elemen yang sudah terurut pada langkah pertama akan diisolasi dan tidak akan dilibatkan dalam proses perbandingan elemen di langkah kedua. Elemen yang sudah terurut pada langkah kedua tidak akan dilibatkan dalam proses perbandingan di langkah ketiga, dan seterusnya.

Untuk memudahkan dalam memahami cara kerja algoritma pengurutan gelembung kita dapat mengubah kode program sebelumnya menjadi seperti berikut:

- **Contoh 7.c** [File](../src/Contoh_7.c)

```c
#include <stdio.h>

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

void bubble_sort(int *array, size_t size) {
    int temp;

    for (int i = 0; i < size - 1; ++i) {
        printf("Langkah ke-%d: ", i + 1);

        for (int j = size - 1; j > i; --j)
            if (array[j] < array[j - 1]) {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        
        print_array(array, size);
    }
}

main(int argc, char const *argv[]) {
    int data[9] = {12, 10, 6, 11, 5, 4, 7, 9, 8};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array sebelum diurutkan
    printf("Sebelum diurutkan: ");
    print_array(data, size);

    // Mengurutkan array
    bubble_sort(data, size);

    // Menampilkan elemen array setelah diurutkan
    printf("Setelah diurutkan: ");
    print_array(data, size);

    return 0;
}
```

Hasil program:

```
Sebelum diurutkan: [12, 10, 6, 11, 5, 4, 7, 9, 8]
Langkah ke-1: [4, 12, 10, 6, 11, 5, 7, 8, 9]
Langkah ke-2: [4, 5, 12, 10, 6, 11, 7, 8, 9]
Langkah ke-3: [4, 5, 6, 12, 10, 7, 11, 8, 9]
Langkah ke-4: [4, 5, 6, 7, 12, 10, 8, 11, 9]
Langkah ke-5: [4, 5, 6, 7, 8, 12, 10, 9, 11]
Langkah ke-6: [4, 5, 6, 7, 8, 9, 12, 10, 11]
Langkah ke-7: [4, 5, 6, 7, 8, 9, 10, 12, 11]
Langkah ke-8: [4, 5, 6, 7, 8, 9, 10, 11, 12]
Setelah diurutkan: [4, 5, 6, 7, 8, 9, 10, 11, 12]
```

Pada contoh program di atas kita mengurutkan data yang elemennya berjumlah 9. Oleh karena itu, diperlukan 8 langkah untuk mengurutkan data tersebut. Posisi elemen pada setiap langkah dapat kita lihat pada hasil yang ditampilkan di atas.

Metode yang digunakan di atas adalah dengan menempatkan elemen terkecil di posisi paling kiri. Setelah itu elemen tersebut diisolasi atau diikat dan tidak dilibatkan pada proses berikutnya. Dalam metode tersebut, elemen-elemen kiri merupakan elemen-elemen yang sudah terurut. Kita juga dapat menggunakan metode lain untuk mengimplementasikan algoritma pengurutan gelembung, yaitu dengan menempatkan elemen terbesar di posisi paling kanan dan elemen tersebut tidak dilibatkan pada proses berikutnya. Dengan cara seperti ini, elemen-elemen kanan akan menjadi elemen-elemen yang pertama kali diurutkan. Kode di bawah ini akan menunjukan konsep tersebut:

- **Contoh 8.c** [File](../src/Contoh_8.c)

```c
#include <stdio.h>

void print_array(int array[], size_t size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

void bubble_sort(int *array, size_t size) {
    int temp, step = 1;

    for (int i = size - 1; i > 0; --i) {
        printf("Langkah ke-%d: ", step);

        for (int j = 0; j < i; ++j)
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        
        print_array(array, size);
        ++step;
    }
}

main(int argc, char const *argv[]) {
    int data[7] = {14, 13, 12, 11, 10, 9, 8};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array sebelum diurutkan
    printf("Sebelum diurutkan: ");
    print_array(data, size);

    // Mengurutkan array
    bubble_sort(data, size);

    // Menampilkan elemen array setelah diurutkan
    printf("Setelah diurutkan: ");
    print_array(data, size);

    return 0;
}
```

Hasil program:

```

```
> Raharjo, Budi. 2016. Kumpulan Solusi Pemrograman C. Bandung: INFORMATIKA.

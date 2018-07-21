#include <stdio.h>
#include <stdbool.h>

int sequential_search(int array[], size_t size, int value) {
    int pos = 0;
    bool found = false;

    while (pos < size && !found) {
        if (array[pos] == value)
            found = true;
        else
            pos += 1;
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

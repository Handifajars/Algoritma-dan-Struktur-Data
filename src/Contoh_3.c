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

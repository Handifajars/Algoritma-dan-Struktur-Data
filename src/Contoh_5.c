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

    /* Menampilkan elemen array */
    printf("Isi array: ");
    print_array(data, size);

    // Mencari nilai
    printf("\nIndeks dari nilai 200: %d\n", binary_search(data, 0, 4, 200));
    printf("Indeks dari nilai 400: %d\n", binary_search(data, 0, 4, 400));
    printf("Indeks dari nilai 700: %d\n", binary_search(data, 0, 4, 700));
    printf("Indeks dari nilai 900: %d\n", binary_search(data, 0, 4, 900));

    return 0;
}

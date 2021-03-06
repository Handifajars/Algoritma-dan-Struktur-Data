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

void selection_sort(int *array, int size) {
    int minposition, temp;

    for (int i = 0; i < size - 1; ++i) {
        printf("Langkah ke-%d: ", i + 1);

        minposition = size - 1;

        for (int j = size - 2; j > i - 1; --j)
            if (array[j] < array[minposition])
                minposition = j;

        temp = array[i];
        array[i] = array[minposition];
        array[minposition] = temp;

        print_array(array, size);
    }
}

main(int argc, char const *argv[]) {
    int data[8] = {9, 7, 10, 8, 12, 11, 14 , 13};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array sebelum diurutkan
    printf("Sebelum diurutkan: ");
    print_array(data, size);

    // Mengurutkan array
    selection_sort(data, size);

    // Menampilkan elemen array setelah diurutkan
    printf("Setelah diurutkan: ");
    print_array(data, size);

    return 0;
}

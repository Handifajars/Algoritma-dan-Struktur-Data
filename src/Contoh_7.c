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

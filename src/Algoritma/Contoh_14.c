#include <stdio.h>

void insertion_sort(int *array, size_t size, int start, int step) {
    int currentvalue, position;

    for (int i = start + step; i < size; i += step) {
        currentvalue = array[i];
        position = i;
        
        while (position >= step && array[position - step] > currentvalue) {
            array[position] = array[position - step];
            position -= step;
        }

        array[position] = currentvalue;
    }
}

void shell_sort(int *array, size_t size) {
    int step = size / 2;

    while (step > 0) {
        for (int i = 0; i < step; ++i)
            insertion_sort(array, size, i, step);

        step /= 2;
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

int main(int argc, char const *argv[]) {
    int data[9] = {12, 10, 6, 11, 5, 4, 7, 9, 8};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array sebelum diurutkan
    printf("Sebelum diurutkan: ");
    print_array(data, size);

    // Mengurutkan array
    shell_sort(data, size);

    // Menampilkan elemen array setelah diurutkan
    printf("Setelah diurutkan: ");
    print_array(data, size);

    return 0;
}

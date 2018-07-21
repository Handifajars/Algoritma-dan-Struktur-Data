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

void insertion_sort(int *array, size_t size) {
    int currentvalue, position;

    for (int i = 1; i < size; ++i) {
        currentvalue = array[i];
        position = i;
        printf("Menyisipkan nilai %d\t: ", currentvalue);
        
        while (position > 0 && array[position - 1] > currentvalue) {
            array[position] = array[position - 1];
            --position;
        }
        
        array[position] = currentvalue;
        print_array(array, size);
    }
}

int main(int argc, char const *argv[]) {
    int data[9] = {12, 10, 6, 11, 5, 4, 7, 9, 8};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Menampilkan elemen array sebelum diurutkan
    printf("Sebelum diurutkan: ");
    print_array(data, size);

    // Mengurutkan array
    insertion_sort(data, size);

    // Menampilkan elemen array setelah diurutkan
    printf("Setelah diurutkan: ");
    print_array(data, size);

    return 0;
}

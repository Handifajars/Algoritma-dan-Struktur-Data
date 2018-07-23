#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

struct queue {
	int data[MAX_CAPACITY];
	int size;
	int front;
};

void init(struct queue *q) {
	q->size = 0;
	q->front = 0;
}

bool is_full(struct queue q) {
	return q.size == MAX_CAPACITY;
}

bool is_empty(struct queue q) {
	return q.size == 0;
}

void enqueue(struct queue *q, int value) {
	if (is_full(*q)) {
		printf("Queue penuh...");
		exit(EXIT_FAILURE);
	}
	else
		q->data[(q->size)++] = value;
}

int dequeue(struct queue *q) {
	if (is_empty(*q)) {
		printf("Queue kosong...");
		exit(EXIT_FAILURE);
	}
	else {
		q->size--;
		return q->data[(q->front)++];
	}
}

int first(struct queue q) {
	if (is_empty(q)) {
		printf("Queue kosong...");
		exit(EXIT_FAILURE);
	}
	else
		return q.data[q.front];
}

int get_size(struct queue q) {
	return q.size;
}

void print_queue(struct queue q) {
	printf("[");
	for (int i = q.front; i < q.size + q.front; ++i) {
		printf("%d", q.data[i]);
		if (i != (q.size + q.front - 1))
			printf(", ");
	}
	printf("]\n");
}

int main(int argc, char const *argv[]) {
	struct queue q;
	init(&q);

	// Menambah 5 data ke dalam queue
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);

	// Menampilkan isi queue
	printf("Sebelum isi queue diambil\n");
	printf("Isi queue \t\t: ");
	print_queue(q);
	printf("Nilai paling depan \t: %d\n", first(q));
	printf("Ukuran queue \t\t: %d\n", get_size(q));

	// Mengambil isi queue sebanyak 2 kali
	printf("\nMengambil isi queue...\n");
	printf("dequeue() pertama \t: %d\n", dequeue(&q));
	printf("dequeue() kedua \t: %d\n", dequeue(&q));
	
	printf("\nSetelah isi queue diambil\n");
	printf("Isi queue \t\t: ");
	print_queue(q);
	printf("Nilai paling depan \t: %d\n", first(q));
	printf("Ukuran queue \t\t: %d\n", get_size(q));

	return 0;
}

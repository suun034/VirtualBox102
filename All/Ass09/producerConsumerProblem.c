// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <unistd.h>

// #define SIZE 5  // Buffer size

// int buffer[SIZE];
// int in = 0, out = 0;

// pthread_mutex_t mutex;
// pthread_cond_t empty, full;

// // Producer function
// void* producer(void* arg) {
//     int item;
//     for(int i = 0; i < 10; i++) {
//         item = rand() % 100; // Produce random item

//         pthread_mutex_lock(&mutex);

//         while ((in + 1) % SIZE == out) {  // Buffer is full
//             pthread_cond_wait(&empty, &mutex);
//         }

//         buffer[in] = item;
//         printf("Producer produced: %d\n", item);
//         in = (in + 1) % SIZE;

//         pthread_cond_signal(&full);
//         pthread_mutex_unlock(&mutex);

//         sleep(1); // simulate time delay
//     }
//     return NULL;
// }

// // Consumer function
// void* consumer(void* arg) {
//     int item;
//     for(int i = 0; i < 10; i++) {
//         pthread_mutex_lock(&mutex);

//         while (in == out) {  // Buffer is empty
//             pthread_cond_wait(&full, &mutex);
//         }

//         item = buffer[out];
//         printf("Consumer consumed: %d\n", item);
//         out = (out + 1) % SIZE;

//         pthread_cond_signal(&empty);
//         pthread_mutex_unlock(&mutex);

//         sleep(1); // simulate time delay
//     }
//     return NULL;
// }

// int main() {
//     pthread_t prod, cons;

//     // Initialize mutex and condition variables
//     pthread_mutex_init(&mutex, NULL);
//     pthread_cond_init(&empty, NULL);
//     pthread_cond_init(&full, NULL);

//     // Create producer and consumer threads
//     pthread_create(&prod, NULL, producer, NULL);
//     pthread_create(&cons, NULL, consumer, NULL);

//     // Wait for threads to finish
//     pthread_join(prod, NULL);
//     pthread_join(cons, NULL);

//     // Clean up
//     pthread_mutex_destroy(&mutex);
//     pthread_cond_destroy(&empty);
//     pthread_cond_destroy(&full);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 10; // Buffer size
int x = 0;

void producer() {
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\nProducer produces item %d", x);
    ++mutex;
}

void consumer() {
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer consumes item %d", x);
    x--;
    ++mutex;
}

int main() {
    int n, i;
    printf("\n1. Press 1 for Producer");
    printf("\n2. Press 2 for Consumer");
    printf("\n3. Press 3 for Exit");

    for (i = 1; i > 0; i++) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch(n) {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("\nBuffer is full!");
                break;

            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("\nBuffer is empty!");
                break;

            case 3:
                exit(0);
                break;
        }
    }

    return 0;
}
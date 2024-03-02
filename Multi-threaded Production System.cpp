#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

// Semaphore declarations
sem_t s_batteryEmpty;
sem_t s_batteryFull;
sem_t s_motherboardEmpty;
sem_t s_motherboardFull;
sem_t s_computerEmpty;
sem_t s_computerFull;
sem_t mutex;

// Stock counters
int stockBattery = 0;
int stockMotherboard = 0;
int stockComputer = 0;

// Producer function for batteries
void *produceBattery(void *arg) {
    int id = *(int *)arg;
    while (1) {
        sem_wait(&s_batteryEmpty);
        sem_wait(&mutex);
        stockBattery++;
        printf("\n ** Producer %d produced a battery", id);
        printf("\n Battery stock = %d \n", stockBattery);
        sem_post(&mutex);
        sem_post(&s_batteryFull);
        usleep(rand() % 1000000);
        sleep(1);
    }
}

// Producer function for motherboards
void *produceMotherboard(void *arg) {
    int id = *(int *)arg;
    while (1) {
        sem_wait(&s_motherboardEmpty);
        sem_wait(&mutex);
        stockMotherboard++;
        printf("\n ** Producer %d produced a motherboard", id);
        printf("\n Motherboard stock = %d \n", stockMotherboard);
        sem_post(&mutex);
        sem_post(&s_motherboardFull);
        usleep(rand() % 500000);
        sleep(1);
    }
}

// Producer function for computers
void *produceComputer(void *arg) {
    int id = *(int *)arg;
    while (1) {
        sem_wait(&s_computerEmpty);
        sem_wait(&s_batteryFull);
        sem_wait(&s_motherboardFull);
        sem_wait(&mutex);
        stockBattery--;
        stockMotherboard--;
        stockComputer++;
        printf("\n ** Producer %d produced a computer", id);
        printf("\n Computer stock = %d \n", stockComputer);
        sem_post(&mutex);
        sem_post(&s_batteryEmpty);
        sem_post(&s_motherboardEmpty);
        sem_post(&s_computerFull);
        sleep(1);
        usleep(rand() % 1500000);
    }
}

int main() {
    const int n = 5; // Number of battery producers
    const int m = 6; // Number of motherboard producers
    const int l = 3; // Number of computer manufacturers
    const int stockB = 4; // Battery stock capacity
    const int stockC = 3; // Motherboard stock capacity
    const int stockO = 1000; // Computer stock capacity

    // Semaphore initialization
    sem_init(&s_batteryFull, 0, 0);
    sem_init(&s_batteryEmpty, 0, stockB);
    sem_init(&s_motherboardFull, 0, 0);
    sem_init(&s_motherboardEmpty, 0, stockC);
    sem_init(&s_computerFull, 0, 0);
    sem_init(&s_computerEmpty, 0, stockO);
    sem_init(&mutex, 0, 1);

    pthread_t batteryThreads[n], motherboardThreads[m], computerThreads[l];
    int ids[n + m + l], i;

    // Create battery producer threads
    for (i = 0; i < n; i++) {
        ids[i] = i + 1;
        pthread_create(&batteryThreads[i], NULL, produceBattery, &ids[i]);
    }

    // Create motherboard producer threads
    for (i = 0; i < m; i++) {
        ids[n + i] = i + 1;
        pthread_create(&motherboardThreads[i], NULL, produceMotherboard, &ids[n + i]);
    }

    // Create computer manufacturer threads
    for (i = 0; i < l; i++) {
        ids[n + m + i] = i + 1;
        pthread_create(&computerThreads[i], NULL, produceComputer, &ids[n + m + i]);
    }

    // Main thread sleeps for 60 seconds before exiting
    sleep(60);

    // Final stock report
    printf("\n Final battery stock = %d \n", stockBattery);
    printf("\n Final motherboard stock = %d \n", stockMotherboard);
    printf("\n ---> Total computers produced in one minute: %d \n", stockComputer);

    return 0;
}


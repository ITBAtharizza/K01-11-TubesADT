#include "work.h"
#include <stdio.h>


void delay(int seconds) {
    int count = 0;
    for (int i = 0; i < seconds * 1000000; i++) {
        count++;
    }
}

// Daftar pekerjaan
typedef struct {
    char name[50];
    int income;
    int duration; //durasi dalam detik
} Job;

void work(User *user) {
    // daftar pekerjaan yang tersedia
    Job jobs[] = {
        {"Evil Lab Assistant", 100, 14},
        {"OWCA Hiring Manager", 4200, 21},
        {"Cikapundunginator Caretaker", 7000, 30},
        {"Mewing Specialist", 10000, 22},
        {"Inator Connoisseur", 997, 15}
    };
    int jobCount = sizeof(jobs) / sizeof(jobs[0]);

    // menampilkan daftar pekerjaan
    printf("Daftar pekerjaan:\n");
    for (int i = 0; i < jobCount; i++) {
        printf("%d. %s (pendapatan=%d, durasi=%ds)\n", i + 1, jobs[i].name, jobs[i].income, jobs[i].duration);
    }

    // meng-input pilihan pekerjaan
    printf("Masukkan pekerjaan yang dipilih (1-%d): ", jobCount);
    int choice;
    scanf("%d", &choice);

    // validasi pilihan pekerjaan
    if (choice < 1 || choice > jobCount) {
        printf("Pekerjaan tidak valid!\n");
        return;
    }

    // melakukan pekerjaan
    Job selectedJob = jobs[choice - 1];
    printf("Anda sedang bekerja sebagai %s. Harap tunggu...\n", selectedJob.name);
    delay(selectedJob.duration);

    // menambahkan pendapatan ke user
    user->money += selectedJob.income;
    printf("Pekerjaan selesai. +%d rupiah telah ditambahkan ke akun Anda.\n", selectedJob.income);
}

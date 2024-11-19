#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "mesinkata.h"

#define MAX_COMMAND_ARGS 10

typedef struct {
    Word words[MAX_COMMAND_ARGS]; // Daftar kata dalam command
    int word_count;              // Jumlah kata dalam command
} Command;

// Fungsi untuk memparsing command
void parseCommand(Word input, Command *cmd);

// Fungsi untuk menampilkan daftar HELP berdasarkan menu
void displayCommandHelp(const char *menuType);

#endif

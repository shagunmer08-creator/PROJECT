#ifndef DIARY_H
#define DIARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "diary.txt"

// Structure to store Diary Entry
struct Diary {
    char date[15];
    char title[50];
    char content[500];
};

// Function Prototypes
void addEntry();
void viewEntries();
void searchEntry();
void deleteEntry();

#endif

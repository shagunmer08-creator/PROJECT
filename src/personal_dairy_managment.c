#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "diary.txt"

struct Diary {
    char date[15];
    char title[50];
    char content[500];
};

void addEntry();
void viewEntries();
void searchEntry();
void deleteEntry();

int main() {
    int choice;

    while (1) {
        printf("\n==== PERSONAL DIARY APPLICATION ====\n");
        printf("1. Add New Entry\n");
        printf("2. View All Entries\n");
        printf("3. Search Entry\n");
        printf("4. Delete Entry\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1: addEntry(); break;
            case 2: viewEntries(); break;
            case 3: searchEntry(); break;
            case 4: deleteEntry(); break;
            case 5: 
                printf("Exiting... Goodbye!\n");
                exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void addEntry() {
    struct Diary d;
    FILE *fp = fopen(FILENAME, "a");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Date (DD/MM/YYYY): ");
    fgets(d.date, sizeof(d.date), stdin);
    d.date[strcspn(d.date, "\n")] = '\0';

    printf("Enter Title: ");
    fgets(d.title, sizeof(d.title), stdin);
    d.title[strcspn(d.title, "\n")] = '\0';

    printf("Write your content:\n");
    fgets(d.content, sizeof(d.content), stdin);
    d.content[strcspn(d.content, "\n")] = '\0';

    fprintf(fp, "%s|%s|%s\n", d.date, d.title, d.content);
    fclose(fp);

    printf("\n✅ Entry added successfully!\n");
}

void viewEntries() {
    struct Diary d;
    FILE *fp = fopen(FILENAME, "r");
    char line[600];

    if (!fp) {
        printf("No entries found yet!\n");
        return;
    }

    printf("\n==== ALL DIARY ENTRIES ====\n");
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^|]|%[^|]|%[^\n]", d.date, d.title, d.content);
        printf("\nDate: %s\nTitle: %s\nContent: %s\n", d.date, d.title, d.content);
        printf("----------------------------------------\n");
    }

    fclose(fp);
}

void searchEntry() {
    struct Diary d;
    FILE *fp = fopen(FILENAME, "r");
    char keyword[50], line[600];
    int found = 0;

    if (!fp) {
        printf("No entries found!\n");
        return;
    }

    printf("\nEnter date or title to search: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^|]|%[^|]|%[^\n]", d.date, d.title, d.content);
        if (strstr(d.date, keyword) || strstr(d.title, keyword)) {
            printf("\n✅ Entry Found:\nDate: %s\nTitle: %s\nContent: %s\n", d.date, d.title, d.content);
            found = 1;
        }
    }

    if (!found) printf("\nNo matching entry found!\n");
    fclose(fp);
}

void deleteEntry() {
    struct Diary d;
    FILE *fp = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    char keyword[50], line[600];
    int deleted = 0;

    if (!fp || !temp) {
        printf("Error opening files!\n");
        return;
    }

    printf("\nEnter date or title to delete: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^|]|%[^|]|%[^\n]", d.date, d.title, d.content);
        if (strstr(d.date, keyword) || strstr(d.title, keyword)) {
            deleted = 1;
            continue;
        }
        fprintf(temp, "%s|%s|%s\n", d.date, d.title, d.content);
    }

    fclose(fp);
    fclose(temp);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (deleted)
        printf("\n Entry deleted successfully!\n");
    else
        printf("\nNo entry found with given details.\n");
}

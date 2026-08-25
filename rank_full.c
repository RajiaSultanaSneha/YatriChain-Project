#include <stdio.h>
#include <string.h>
#define MAX_VEHICLES 100
#define DATA_FILE "vehicles.txt"

struct Vehicle {
    char name[50];
    float rating;
};
struct Vehicle vehicles[MAX_VEHICLES];
int count = 0;

void loadVehicles() {
    FILE *fp = fopen(DATA_FILE, "r");
    if (fp == NULL) return;
    while (count < MAX_VEHICLES && fscanf(fp, "%49[^,],%f\n", vehicles[count].name, &vehicles[count].rating) == 2) {
        count++;
    }
    fclose(fp);
}

void saveVehicles() {
    FILE *fp = fopen(DATA_FILE, "w");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%.2f\n", vehicles[i].name, vehicles[i].rating);
    }
    fclose(fp);
    printf("\nData saved. Goodbye!\n");
}

void displayVehicles() {
    if (count == 0) {
        printf("\nNo vehicles yet. Add one first.\n");
        return;
    }
    printf("\n----------------------------------------\n");
    printf("%-4s %-25s %s\n", "No.", "Name", "Rating");
    printf("----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-4d %-25s %.2f\n", i + 1, vehicles[i].name, vehicles[i].rating);
    }
    printf("----------------------------------------\n");
    printf("Total vehicles: %d\n", count);
}

void addRating() {
    char name[50];
    float rating;

    if (count >= MAX_VEHICLES) {
        printf("\nVehicle list is full.\n");
        return;
    }

    printf("\nVehicle name: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(vehicles[i].name, name) == 0) {
            printf("%s already exists with rating %.2f. Not added.\n", name, vehicles[i].rating);
            return;
        }
    }

    do {
        printf("Rating (0-5): ");
        if (scanf("%f", &rating) != 1) {
            printf("Invalid input. Enter a number.\n");
            while (getchar() != '\n');
            rating = -1;
        } else if (rating < 0 || rating > 5) {
            printf("Rating must be between 0 and 5.\n");
        }
    } while (rating < 0 || rating > 5);

    strcpy(vehicles[count].name, name);
    vehicles[count].rating = rating;
    count++;

    printf("%s added with rating %.2f.\n", name, rating);
}

void rankVehicles() {
    struct Vehicle temp;
    if (count == 0) {
        printf("\nNo vehicles available for ranking.\n");
        return;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (vehicles[j].rating < vehicles[j + 1].rating) {
                temp = vehicles[j];
                vehicles[j] = vehicles[j + 1];
                vehicles[j + 1] = temp;
            }
        }
    }
    printf("\nVehicles ranked from highest to lowest rating.\n");
}

int main() {
    int choice;
    loadVehicles();
    do {
        printf("\n===== Vehicle Rating System =====\n");
        printf("1. Display Vehicles\n");
        printf("2. Add Vehicle Rating\n");
        printf("3. Rank by Rating\n");
        printf("4. Save & Exit\n");
        printf("Total Vehicles: %d/%d\n", count, MAX_VEHICLES);
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Enter a number 1-4.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 1) {
            displayVehicles();
        } else if (choice == 2) {
            addRating();
        } else if (choice == 3) {
            rankVehicles();
            displayVehicles();
        } else if (choice == 4) {
            saveVehicles();
        } else {
            printf("Invalid choice. Pick 1-4.\n");
        }
    } while (choice != 4);
    return 0;
}

#include <stdio.h>
#include "fileops.h"

int loadVehicles(struct Vehicle v[]) {
    FILE *fp = fopen(FILENAME, "r");
    int count = 0;

    if (fp == NULL) {
        printf("No existing vehicle file found. Starting fresh.\n");
        return 0;
    }

    while (fscanf(fp, "%d %s %d", &v[count].id, v[count].name, &v[count].rating) == 3) {
        count++;
    }

    fclose(fp);
    return count;
}

void saveVehicles(struct Vehicle v[], int count) {
    FILE *fp = fopen(FILENAME, "w");

    if (fp == NULL) {
    printf("Error: could not open file for writing.\n");
    return;
    }

    for (int i = 0; i < count; i++) {
    fprintf(fp, "%d %s %d\n", v[i].id, v[i].name, v[i].rating);
    }

    fclose(fp);
}

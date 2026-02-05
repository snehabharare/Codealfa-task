#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};
void addStudent() {
    FILE *fp = fopen("students.data", "ab");
    struct Student s;

    printf("Enter Roll No: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf(" %49[^\n]", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Student added successfully!\n");
}

void displayStudents() {
    FILE *fp = fopen("students.dat", "rb");
    struct Student s;

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\nRoll\tName\t\tMarks\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("%d\t%s\t\t%.2f\n", s.roll, s.name, s.marks);
    }
    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen("students.dat", "rb");
    struct Student s;
    int r, found = 0;

    printf("Enter Roll No to search: ");
    scanf("%d", &r);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == r) {
            printf("Found: %d  %s  %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");

    fclose(fp);
}

void deleteStudent() {
    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Student s;
    int r, found = 0;

    printf("Enter Roll No to delete: ");
    scanf("%d", &r);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll != r) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("Student deleted successfully!\n");
    else
        printf("Student not found!\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
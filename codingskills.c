#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUD_FILE "students.txt"
#define CREDS_FILE "credentials.txt"
#define MAX_NAME 50
#define MAX_CRED 50

char currentUser[MAX_CRED], currentRole[MAX_CRED];

int loginUser() {
    char username[MAX_CRED], password[MAX_CRED];

    printf("USERNAME: ");
    scanf("%s", username);
    printf("PASSWORD: ");
    scanf("%s", password);

    FILE *fin = fopen(CREDS_FILE, "r");
    if (!fin) {
        printf("Error: Credentials file missing!\n");
        return 0;
    }

    char u[MAX_CRED], p[MAX_CRED], role[MAX_CRED];
    while (fscanf(fin, "%s %s %s", u, p, role) == 3) {
        if (strcmp(u, username) == 0 && strcmp(p, password) == 0) {
            strcpy(currentUser, u);
            strcpy(currentRole, role);
            fclose(fin);
            return 1;
        }
    }
    fclose(fin);
    return 0;
}

void addStudent() {
    int roll;
    char name[MAX_NAME];
    float marks;

    printf("Enter Roll: ");
    scanf("%d", &roll);
    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Marks: ");
    scanf("%f", &marks);

    FILE *fout = fopen(STUD_FILE, "a");
    if (!fout) {
        printf("Error: Unable to open student file!\n");
        return;
    }

    fprintf(fout, "%d %s %.2f\n", roll, name, marks);
    fclose(fout);
    printf("Student added successfully!\n");
}

void displayStudents() {
    FILE *fin = fopen(STUD_FILE, "r");
    if (!fin) {
        printf("No student records found.\n");
        return;
    }

    printf("Roll\tName\tMarks\n");
    printf("----\t----\t-----\n");

    int roll;
    char name[MAX_NAME];
    float marks;

    while (fscanf(fin, "%d %s %f", &roll, name, &marks) == 3) {
        printf("%d\t%s\t%.2f\n", roll, name, marks);
    }
    fclose(fin);
}

void searchStudent() {
    int findRoll;
    printf("Enter Roll Number to Search: ");
    scanf("%d", &findRoll);

    FILE *fin = fopen(STUD_FILE, "r");
    if (!fin) {
        printf("No student records found.\n");
        return;
    }

    int roll;
    char name[MAX_NAME];
    float marks;

    while (fscanf(fin, "%d %s %f", &roll, name, &marks) == 3) {
        if (roll == findRoll) {
            printf("Found: %d %s %.2f\n", roll, name, marks);
            fclose(fin);
            return;
        }
    }
    fclose(fin);
    printf("Student not found!\n");
}

void deleteStudent() {
    int delRoll;
    printf("Enter Roll to Delete: ");
    scanf("%d", &delRoll);

    FILE *fin = fopen(STUD_FILE, "r");
    if (!fin) {
        printf("No student file found.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    int found = 0;

    int roll;
    char name[MAX_NAME];
    float marks;

    while (fscanf(fin, "%d %s %f", &roll, name, &marks) == 3) {
        if (roll != delRoll) {
            fprintf(temp, "%d %s %.2f\n", roll, name, marks);
        } else {
            found = 1;
        }
    }

    fclose(fin);
    fclose(temp);

    remove(STUD_FILE);
    rename("temp.txt", STUD_FILE);

    if (found)
        printf("Student deleted.\n");
    else
        printf("Roll number not found.\n");
}

void updateStudent() {
    int upRoll;
    printf("Enter Roll to Update: ");
    scanf("%d", &upRoll);

    FILE *fin = fopen(STUD_FILE, "r");
    if (!fin) {
        printf("No student file found.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    int found = 0;

    int roll;
    char name[MAX_NAME];
    float marks;

    while (fscanf(fin, "%d %s %f", &roll, name, &marks) == 3) {
        if (roll == upRoll) {
            found = 1;

            char newName[MAX_NAME];
            float newMarks;

            printf("New Name: ");
            scanf("%s", newName);
            printf("New Marks: ");
            scanf("%f", &newMarks);

            fprintf(temp, "%d %s %.2f\n", roll, newName, newMarks);
        } else {
            fprintf(temp, "%d %s %.2f\n", roll, name, marks);
        }
    }

    fclose(fin);
    fclose(temp);

    remove(STUD_FILE);
    rename("temp.txt", STUD_FILE);

    if (found)
        printf("Student updated.\n");
    else
        printf("Roll not found.\n");
}

void adminMenu() {
    int c;
    while (1) {
        printf("\nADMIN MENU\n");
        printf("1. Add Student\n2. Display\n3. Search\n4. Update\n5. Delete\n6. Logout\n");
        scanf("%d", &c);

        switch (c) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            default: return;
        }
    }
}

void staffMenu() {
    int c;
    while (1) {
        printf("\nSTAFF MENU\n");
        printf("1. Add Student\n2. Display\n3. Search\n4. Update\n5. Logout\n");
        scanf("%d", &c);

        switch (c) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            default: return;
        }
    }
}

void guestMenu() {
    int c;
    while (1) {
        printf("\nGUEST MENU\n");
        printf("1. Display\n2. Search\n3. Logout\n");
        scanf("%d", &c);

        switch (c) {
            case 1: displayStudents(); break;
            case 2: searchStudent(); break;
            default: return;
        }
    }
}

int main() {
    if (!loginUser()) {
        printf("Invalid login!\n");
        return 0;
    }

    printf("Logged in as: %s\n", currentRole);

    if (strcmp(currentRole, "ADMIN") == 0) adminMenu();
    else if (strcmp(currentRole, "STAFF") == 0) staffMenu();
    else guestMenu();

    return 0;
}

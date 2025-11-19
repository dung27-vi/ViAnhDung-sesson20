#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define INITIAL_STUDENTS 5

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

struct Student studentArray[MAX_STUDENTS] = {
    {1, "Nguyen Van A", 20, "0123456789"},
    {2, "Le Thi B", 21, "0987654321"},
    {3, "Tran Van C", 22, "0123123123"},
    {4, "Pham Thi D", 20, "0987987987"},
    {5, "Huynh Van E", 21, "0123454321"}
};

int studentCount = INITIAL_STUDENTS;

void addStudent() {
    if (studentCount < MAX_STUDENTS) {
        struct Student newStudent;
        printf("Nhap ID sinh vien moi: ");
        scanf("%d", &newStudent.id);
        printf("Nhap Ten sinh vien moi: ");
        scanf(" %[^\n]", newStudent.name);
        printf("Nhap Tuoi sinh vien moi: ");
        scanf("%d", &newStudent.age);
        printf("Nhap So dien thoai sinh vien moi: ");
        scanf(" %[^\n]", newStudent.phoneNumber);

        studentArray[studentCount] = newStudent;
        studentCount++;
        printf("Da them sinh vien moi thanh cong!\n");
    } else {
        printf("Mang sinh vien da day, khong the them moi!\n");
    }
}

void displayStudents() {
    printf("\n--- Danh Sach Sinh Vien ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n",
               studentArray[i].id, studentArray[i].name,
               studentArray[i].age, studentArray[i].phoneNumber);
    }
    printf("---------------------------\n");
}

int main() {
    addStudent();
    displayStudents();
    return 0;
}

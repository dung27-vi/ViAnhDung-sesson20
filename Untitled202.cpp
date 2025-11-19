#include <stdio.h>

struct SinhVien {
    char name[50];
    int age;
    char phoneNumber[15];
};

int main() {
    struct SinhVien sv;

    printf("Nhap ten sinh vien: ");
    scanf("%s", sv.name);

    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &sv.age);

    printf("Nhap so dien thoai sinh vien: ");
    scanf("%s", sv.phoneNumber);

    printf("\n--- Thong tin sinh vien da nhap ---\n");
    printf("Ten: %s\n", sv.name);
    printf("Tuoi: %d\n", sv.age);
    printf("So dien thoai: %s\n", sv.phoneNumber);

    return 0;
}

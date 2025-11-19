#include <stdio.h>
#include <string.h>

struct SinhVien {
    char name[50];
    int age;
    char phoneNumber[15];
};

int main() {
    struct SinhVien sv;
    
    strcpy(sv.name, "Nguyen Van A");
    sv.age = 20;
    strcpy(sv.phoneNumber, "0123456789");
    
    printf("Thong tin sinh vien:\n");
    printf("Ten: %s\n", sv.name);
    printf("Tuoi: %d\n", sv.age);
    printf("So dien thoai: %s\n", sv.phoneNumber);
    
    return 0;
}

#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

struct SinhVien danhSachSV[50];

void nhapThongTin(struct SinhVien arr[], int soLuong) {
    for (int i = 0; i < soLuong; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        arr[i].id = i + 1;
        printf("Ten: ");
        while (getchar() != '\n'); 
        fgets(arr[i].name, sizeof(arr[i].name), stdin);
        arr[i].name[strcspn(arr[i].name, "\n")] = 0;

        printf("Tuoi: ");
        scanf("%d", &arr[i].age);
        printf("So dien thoai: ");
        while (getchar() != '\n'); 
        fgets(arr[i].phoneNumber, sizeof(arr[i].phoneNumber), stdin);
        arr[i].phoneNumber[strcspn(arr[i].phoneNumber, "\n")] = 0;
    }
}

void inThongTin(struct SinhVien arr[], int soLuong) {
    printf("\n--- Danh sach sinh vien ---\n");
    for (int i = 0; i < soLuong; i++) {
        printf("ID: %d\n", arr[i].id);
        printf("Ten: %s\n", arr[i].name);
        printf("Tuoi: %d\n", arr[i].age);
        printf("So dien thoai: %s\n", arr[i].phoneNumber);
        printf("---------------------------\n");
    }
}

int main() {
    int soLuongSV = 5;
    nhapThongTin(danhSachSV, soLuongSV);
    inThongTin(danhSachSV, soLuongSV);
    return 0;
}

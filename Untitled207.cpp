#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

struct SinhVien danhSachSV[MAX_STUDENTS] = {
    {1, "Nguyen Van A", 20, "0123456789"},
    {2, "Tran Thi B", 21, "0987654321"},
    {3, "Le Van C", 22, "0123123123"},
    {4, "Pham Thi D", 20, "0987898789"},
    {5, "Huynh Van E", 21, "0123454321"}
};

int soLuongSV = 5;

void xoaSinhVien(int idCanXoa) {
    int viTriXoa = -1;
    for (int i = 0; i < soLuongSV; i++) {
        if (danhSachSV[i].id == idCanXoa) {
            viTriXoa = i;
            break;
        }
    }

    if (viTriXoa == -1) {
        printf("Sinh vien co id %d khong ton tai.\n", idCanXoa);
    } else {
        for (int i = viTriXoa; i < soLuongSV - 1; i++) {
            danhSachSV[i] = danhSachSV[i+1];
        }
        soLuongSV--;
        printf("Da xoa sinh vien co id %d thanh cong.\n", idCanXoa);
    }
}

void hienThiDanhSach() {
    if (soLuongSV == 0) {
        printf("Danh sach sinh vien hien tai rong.\n");
        return;
    }
    printf("\n--- Danh sach sinh vien hien tai (%d sinh vien) ---\n", soLuongSV);
    for (int i = 0; i < soLuongSV; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n",
               danhSachSV[i].id, danhSachSV[i].name, danhSachSV[i].age, danhSachSV[i].phoneNumber);
    }
    printf("--------------------------------------------------\n");
}

int main() {
    hienThiDanhSach();

    int idCanXoa;
    printf("\nNhap id sinh vien can xoa: ");
    if (scanf("%d", &idCanXoa) != 1) {
        printf("Nhap khong hop le.\n");
        return 1;
    }
    xoaSinhVien(idCanXoa);
    hienThiDanhSach();

    return 0;
} 

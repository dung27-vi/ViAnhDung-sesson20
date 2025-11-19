#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define INITIAL_STUDENTS 5

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
    {4, "Pham Thi D", 19, "0987987987"},
    {5, "Huynh Van E", 20, "0123454321"}
};

int soLuongHienTai = INITIAL_STUDENTS;

void suaThongTinSinhVien() {
    int idCanTim;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &idCanTim);

    int timThay = 0;
    for (int i = 0; i < soLuongHienTai; i++) {
        if (danhSachSV[i].id == idCanTim) {
            timThay = 1;
            printf("Tim thay sinh vien ID %d. Nhap thong tin moi:\n", idCanTim);
            
            while (getchar() != '\n'); 

            printf("Nhap ten moi: ");
            fgets(danhSachSV[i].name, sizeof(danhSachSV[i].name), stdin);
            danhSachSV[i].name[strcspn(danhSachSV[i].name, "\n")] = 0; 

            printf("Nhap tuoi moi: ");
            scanf("%d", &danhSachSV[i].age);
            
            printf("Da cap nhat thong tin sinh vien ID %d.\n", idCanTim);
            break;
        }
    }

    if (!timThay) {
        printf("Khong tim thay sinh vien co ID %d.\n", idCanTim);
    }
}

void inDanhSachSinhVien() {
    printf("\n--------- Danh Sach Sinh Vien ------------\n");
    for (int i = 0; i < soLuongHienTai; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n", 
               danhSachSV[i].id, danhSachSV[i].name, danhSachSV[i].age, danhSachSV[i].phoneNumber);
    }
    printf("------------------------------------------\n");
}

int main() {
    inDanhSachSinhVien(); 
    suaThongTinSinhVien(); 
    inDanhSachSinhVien(); 
    return 0;
}

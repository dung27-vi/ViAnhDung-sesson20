#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
struct SinhVien danhSachSinhVien[50] = {
    {1, "Nguyen Van A", 20, "0123456789"},
    {2, "Tran Thi B", 21, "0987654321"},
    {3, "Le Van C", 22, "0123123123"},
    {4, "Pham Thi D", 19, "0987987987"},
    {5, "Hoang Van E", 20, "0123454321"}
};
int soLuongHienTai = 5;
void chenSinhVien(struct SinhVien svMoi, int viTri) {
    if (viTri < 0 || viTri > soLuongHienTai || soLuongHienTai >= 50) {
        printf("Vi tri chen khong hop le hoac mang da day!\n");
        return;
    }
    for (int i = soLuongHienTai - 1; i >= viTri; i--) {
        danhSachSinhVien[i + 1] = danhSachSinhVien[i];
    }
    danhSachSinhVien[viTri] = svMoi;
    soLuongHienTai++;
    printf("Da chen sinh vien thanh cong!\n");
}
void hienThiDanhSach() {
    printf("\n--- Danh sach sinh vien hien tai (%d sinh vien) ---\n", soLuongHienTai);
    for (int i = 0; i < soLuongHienTai; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n",
               danhSachSinhVien[i].id, danhSachSinhVien[i].name,
               danhSachSinhVien[i].age, danhSachSinhVien[i].phoneNumber);
    }
    printf("---------------------------------------------------\n");
}
int main() {
    hienThiDanhSach();

    int viTriChen;
    struct SinhVien svMoi;

    printf("\nNhap vi tri can chen (tu 0 den %d): ", soLuongHienTai);
    scanf("%d", &viTriChen);

    printf("Nhap thong tin sinh vien moi:\n");
    printf("ID: ");
    scanf("%d", &svMoi.id);
    printf("Ten: ");
    scanf("%s", svMoi.name);
    printf("Tuoi: ");
    scanf("%d", &svMoi.age);
    printf("SDT: ");
    scanf("%s", svMoi.phoneNumber);

    chenSinhVien(svMoi, viTriChen);

    hienThiDanhSach();

    return 0;
}

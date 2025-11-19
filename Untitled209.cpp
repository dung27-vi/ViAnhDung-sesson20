#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISHES 100
#define INITIAL_DISHES 5

struct Dish {
    int id;
    char name[50];
    float price;
};
struct Dish menu[MAX_DISHES];
int numDishes = INITIAL_DISHES;

void initializeMenu() {
    menu[0] = (struct Dish){1, "Pho Bo", 45000.0};
    menu[1] = (struct Dish){2, "Com Ga", 40000.0};
    menu[2] = (struct Dish){3, "Banh Mi", 20000.0};
    menu[3] = (struct Dish){4, "Bun Cha", 50000.0};
    menu[4] = (struct Dish){5, "Ca Phe Sua Da", 15000.0};
}
void printDish(struct Dish d) {
    printf("ID: %d, Name: %s, Price: %.2f VND\n", d.id, d.name, d.price);
}

void printMenu() {
    printf("\n--- MENU MON AN ---\n");
    for (int i = 0; i < numDishes; i++) {
        printf("%d. ", i + 1);
        printDish(menu[i]);
    }
    printf("-------------------\n");
}

void swapDishes(struct Dish *d1, struct Dish *d2) {
    struct Dish temp = *d1;
    *d1 = *d2;
    *d2 = temp;
}
void addDish() {
    if (numDishes >= MAX_DISHES) {
        printf("Menu da day, khong the them mon an moi.\n");
        return;
    }
    int pos;
    printf("Nhap vi tri muon them (1 den %d): ", numDishes + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > numDishes + 1) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = numDishes; i >= pos; i--) {
        menu[i] = menu[i - 1];
    }

    printf("Nhap ID: ");
    scanf("%d", &menu[pos - 1].id);
    printf("Nhap ten: ");
    scanf("%s", menu[pos - 1].name);
    printf("Nhap gia: ");
    scanf("%f", &menu[pos - 1].price);

    numDishes++;
    printf("Da them mon an thanh cong.\n");
}

void editDish() {
    int pos;
    printf("Nhap vi tri mon an muon sua (1 den %d): ", numDishes);
    scanf("%d", &pos);
    if (pos < 1 || pos > numDishes) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    printf("Nhap ID moi: ");
    scanf("%d", &menu[pos - 1].id);
    printf("Nhap ten moi: ");
    scanf("%s", menu[pos - 1].name);
    printf("Nhap gia moi: ");
    scanf("%f", &menu[pos - 1].price);

    printf("Da sua mon an thanh cong.\n");
}

void deleteDish() {
    int pos;
    printf("Nhap vi tri mon an muon xoa (1 den %d): ", numDishes);
    scanf("%d", &pos);
    if (pos < 1 || pos > numDishes) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = pos - 1; i < numDishes - 1; i++) {
        menu[i] = menu[i + 1];
    }

    numDishes--;
    printf("Da xoa mon an thanh cong.\n");
}

void sortMenu(int order) { // 0 for desc, 1 for asc
    for (int i = 0; i < numDishes - 1; i++) {
        for (int j = 0; j < numDishes - i - 1; j++) {
            if (order == 0) { // descending
                if (menu[j].price < menu[j + 1].price) {
                    swapDishes(&menu[j], &menu[j + 1]);
                }
            } else { // ascending
                if (menu[j].price > menu[j + 1].price) {
                    swapDishes(&menu[j], &menu[j + 1]);
                }
            }
        }
    }
    printf("Da sap xep menu.\n");
}

void searchLinear() {
    char name[50];
    printf("Nhap ten mon an can tim: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < numDishes; i++) {
        if (strcmp(menu[i].name, name) == 0) {
            printf("Tim thay tai vi tri %d: ", i + 1);
            printDish(menu[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay mon an nao co ten %s.\n", name);
    }
}

void searchBinary() {
    printf("Chuc nang tim kiem nhi phan chua duoc trien khai.\n");
}
int main() {
    initializeMenu();
    int choice, subChoice;

    while (1) {
        printf("\n======= MENU CHINH =======\n");
        printf("1. In ra gia tri cac phan tu\n");
        printf("2. Them mot phan tu\n");
        printf("3. Sua mot phan tu\n");
        printf("4. Xoa mot phan tu\n");
        printf("5. Sap xep cac phan tu\n");
        printf("6. Tim kiem phan tu theo name\n");
        printf("7. Thoat\n");
        printf("==========================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printMenu();
                break;
            case 2:
                addDish();
                break;
            case 3:
                editDish();
                break;
            case 4:
                deleteDish();
                break;
            case 5:
                printf("a. Giam dan theo price\n");
                printf("b. Tang dan theo price\n");
                printf("Nhap lua chon sap xep (a/b): ");
                scanf(" %c", &subChoice);
                if (subChoice == 'a') {
                    sortMenu(0);
                } else if (subChoice == 'b') {
                    sortMenu(1);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 6:
                printf("a. Tim kiem tuyen tinh\n");
                printf("b. Tim kiem nhi phan\n");
                printf("Nhap lua chon tim kiem (a/b): ");
                scanf(" %c", &subChoice);
                if (subChoice == 'a') {
                    searchLinear();
                } else if (subChoice == 'b') {
                    searchBinary();
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 7:
                exit(0);
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

// Struct untuk merepresentasikan barang thrift
struct ThriftItem {
    char name[50];
    double price;
    int quantity;
};

// Fungsi untuk menambahkan barang thrift baru
void createThriftItem(struct ThriftItem items[], int *count) {
    if (*count < 100) { // Batasi jumlah barang yang bisa disimpan
        struct ThriftItem newItem;
        printf("Masukkan nama barang thrift: ");
        scanf("%s", newItem.name);
        printf("Masukkan harga barang thrift: $");
        scanf("%lf", &newItem.price);
        printf("Masukkan jumlah barang thrift: ");
        scanf("%d", &newItem.quantity);

        items[*count] = newItem;
        (*count)++;
        printf("Barang thrift telah ditambahkan.\n");
    } else {
        printf("Inventory barang thrift penuh.\n");
    }
}

// Fungsi untuk menampilkan semua barang thrift dalam inventory
void readThriftItems(struct ThriftItem items[], int count) {
    printf("Inventory Barang Thrift:\n");
    for (int i = 0; i < count; i++) {
        printf("Nama: %s, Harga: $%.2lf, Jumlah: %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

// Fungsi untuk memperbarui informasi barang thrift
void updateThriftItem(struct ThriftItem items[], int count) {
    if (count == 0) {
        printf("Inventory barang thrift kosong.\n");
        return;
    }

    char searchName[50];
    printf("Masukkan nama barang thrift yang ingin diperbarui: ");
    scanf("%s", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(searchName, items[i].name) == 0) {
            printf("Masukkan harga baru untuk barang thrift: $");
            scanf("%lf", &items[i].price);
            printf("Masukkan jumlah baru untuk barang thrift: ");
            scanf("%d", &items[i].quantity);
            printf("Informasi barang thrift telah diperbarui.\n");
            return;
        }
    }

    printf("Barang thrift dengan nama %s tidak ditemukan.\n", searchName);
}

// Fungsi untuk menghapus barang thrift dari inventory
void deleteThriftItem(struct ThriftItem items[], int *count) {
    if (*count == 0) {
        printf("Inventory barang thrift kosong.\n");
        return;
    }

    char searchName[50];
    printf("Masukkan nama barang thrift yang ingin dihapus: ");
    scanf("%s", searchName);

    for (int i = 0; i < *count; i++) {
        if (strcmp(searchName, items[i].name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                items[j] = items[j + 1];
            }
            (*count)--;
            printf("Barang thrift telah dihapus dari inventory.\n");
            return;
        }
    }

    printf("Barang thrift dengan nama %s tidak ditemukan.\n", searchName);
}

int main() {
    struct ThriftItem inventory[100]; // Array of struct untuk menyimpan barang thrift
    int itemCount = 0; // Jumlah barang thrift dalam inventory

    int choice;
    while (1) {
        printf("\nMenu Pengelolaan Barang Thrift:\n");
        printf("1. Tambah Barang Thrift\n");
        printf("2. Tampilkan Inventory Barang Thrift\n");
        printf("3. Perbarui Informasi Barang Thrift\n");
        printf("4. Hapus Barang Thrift\n");
        printf("5. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createThriftItem(inventory, &itemCount);
                break;
            case 2:
                readThriftItems(inventory, itemCount);
                break;
            case 3:
                updateThriftItem(inventory, itemCount);
                break;
            case 4:
                deleteThriftItem(inventory, &itemCount);
                break;
            case 5:
                return 0;
            default:
                printf("Pilihan tidak valid. Silakan pilih kembali.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

//Struct barang thrift
struct ThriftItem
{   
    string nama;
    int harga;
    int kuantitas;
};

//Fungsi tambahkan item
void tambahItem(ThriftItem inventory[], int &ItemCount ){
    if (ItemCount >= 0 && ItemCount < 100)
    {
        ThriftItem newItem;
        cin.ignore();
        cout << "Masukkan Nama Barang: ",getline(cin, newItem.nama);
        cout << "Masukkan Harga Barang: Rp. ",cin >> newItem.harga;
        cout << "Masukkan Jumlah Barang: ",cin >> newItem.kuantitas;
        inventory[ItemCount] = newItem;
        ItemCount++;
        cout << "Barang thrift telah ditambahkan.\n";
    }else
    {
        cout << "Inventory barang thrift penuh.\n";
    }
}
// Fungsi tampilkan item dengan tampilan yang lebih menarik
void tampilItem(ThriftItem inventory[], int &ItemCount){
    if (ItemCount == 0)
    {
        cout << "Inventory barang thrift kosong.\n";
        return;
    }else
    {
        cout << "==============================================" << endl;
        cout << "              Inventory Barang Thrift          " << endl;
        cout << "==============================================" << endl;
        cout << "No.  |  Nama Barang           |  Harga   |  Jumlah" << endl;
        cout << "----------------------------------------------" << endl;
        for (int i = 0; i < ItemCount; i++)
        {
            cout << setw(3) << i+1 << "  |  ";
            cout << setw(20) << left << inventory[i].nama << "  |  ";
            cout << setw(7) << right << "Rp. " << inventory[i].harga << "  |  ";
            cout << setw(6) << right << inventory[i].kuantitas << endl;
        }
        cout << "==============================================" << endl;
    }
}

// Fungsi Update item
void UpdateItem(ThriftItem inventory[], int &ItemCount){
    if (ItemCount == 0)
    {
        cout << "Inventory barang thrift kosong.\n";
        return;
    }

    string SearchName;
    cout << "Masukkan nama barang thrift yang ingin diperbarui: ";
    cin.ignore();
    getline(cin, SearchName);

    for (int i = 0; i < ItemCount; i++)
    {
        if (inventory[i].nama == SearchName)
        {
            cout << "Masukkan harga baru untuk barang thrift: Rp. ";
            cin >> inventory[i].harga;
            cout << "Masukkan kuantitas baru untuk barang thrift: ";
            cin >> inventory[i].kuantitas;
            cout << "Informasi barang thrift dengan nama " << SearchName << " telah diperbarui.\n";
            return;
        }
        
    }
    
    cout << "Barang thrift dengan nama " << SearchName << " tidak ditemukan.\n";
}


int main()
{
    ThriftItem inventory [100];
    int ItemCount = 0;

    int pilih;
    while (true)
    {
        printf("\nMenu Pengelolaan Barang Thrift:\n");
        printf("1. Tambah Barang Thrift\n");
        printf("2. Tampilkan Inventory Barang Thrift\n");
        printf("3. Perbarui Informasi Barang Thrift\n");
        printf("4. Hapus Barang Thrift\n");
        printf("5. Keluar\n");
        printf("Pilihan Anda: ");
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            tambahItem(inventory, ItemCount);
            break;
        case 2:
            tampilItem(inventory, ItemCount);
            break;
        // case 1:
        //     tambahItem(inventory, &ItemCount);
        //     break;
        // case 1:
        //     tambahItem(inventory, &ItemCount);
        //     break;
        case 5:
            return false;
        default:
            cout << "Pilihan tidak valid. Silakan pilih kembali.\n";
    
        }
        
    }
    
}
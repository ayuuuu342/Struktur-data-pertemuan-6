#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
    string nomorpolisi;
    string warna;
    int thnBuat;
};

struct Node {
    kendaraan info;
    Node* next;
    Node* prev;
};

struct List {
    Node* first;
    Node* last;
};

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

Node* alokasi(kendaraan x) {
    Node* P = new Node;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertFirst(List &L, Node* P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

Node* findElm(List L, string nomorpolisi) {
    Node* P = L.first;
    while (P != NULL) {
        if (P->info.nomorpolisi == nomorpolisi) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void printInfo(List L) {
    Node* P = L.first;
    int i = 1;
    cout << endl << "DATA LIST " << i << endl;
    while (P != NULL) {
        cout << "no polisi : " << P->info.nomorpolisi << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->next;
    }
}

// penambahan fungsi untuk soal nomor 
void deleteFirst(List &L, Node* &P) {
    if (L.first != NULL) {
        P = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = L.first->next;
            L.first->prev = NULL;
            P->next = NULL;
        }
    }
}

void deleteLast(List &L, Node* &P) {
    if (L.last != NULL) {
        P = L.last;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.last = L.last->prev;
            L.last->next = NULL;
            P->prev = NULL;
        }
    }
}

void deleteAfter(Node* Prec, Node* &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = Prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

int main() {
    List L;
    createList(L);
    kendaraan x;
    Node* P;

    // Input 1
    cout << "masukkan nomor polisi : ";
    cin >> x.nomorpolisi;
    cout << "masukkan warna kendaraan : ";
    cin >> x.warna;
    cout << "masukkan tahun kendaraan : ";
    cin >> x.thnBuat;
    P = alokasi(x);
    insertFirst(L, P);
    cout << endl;

    // Input 2
    cout << "masukkan nomor polisi : ";
    cin >> x.nomorpolisi;
    cout << "masukkan warna kendaraan : ";
    cin >> x.warna;
    cout << "masukkan tahun kendaraan : ";
    cin >> x.thnBuat;
    if (findElm(L, x.nomorpolisi) != NULL)
        cout << "nomor polisi sudah terdaftar" << endl;
    else {
        P = alokasi(x);
        insertFirst(L, P);
    }
    cout << endl;

    // Input 3
    cout << "masukkan nomor polisi : ";
    cin >> x.nomorpolisi;
    cout << "masukkan warna kendaraan : ";
    cin >> x.warna;
    cout << "masukkan tahun kendaraan : ";
    cin >> x.thnBuat;
    if (findElm(L, x.nomorpolisi) != NULL)
        cout << "nomor polisi sudah terdaftar" << endl;
    else {
        P = alokasi(x);
        insertFirst(L, P);
    }
    cout << endl;

    // Input 4
    cout << "masukkan nomor polisi : ";
    cin >> x.nomorpolisi;
    cout << "masukkan warna kendaraan : ";
    cin >> x.warna;
    cout << "masukkan tahun kendaraan : ";
    cin >> x.thnBuat;
    if (findElm(L, x.nomorpolisi) != NULL)
        cout << "nomor polisi sudah terdaftar" << endl;
    else {
        P = alokasi(x);
        insertFirst(L, P);
    }

    // mencari data
    string cari;
    cout << endl << "Masukkan Nomor Polisi yang dicari : ";
    cin >> cari;

    Node* hasil = findElm(L, cari);
    if (hasil != NULL) {
        cout << endl;
        cout << "Nomor Polisi : " << hasil->info.nomorpolisi << endl;
        cout << "Warna        : " << hasil->info.warna << endl;
        cout << "Tahun        : " << hasil->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << cari << " tidak ditemukan." << endl;
    }

    // Hapus elemen
    string hapus;
    cout << endl << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapus;

    Node* target = findElm(L, hapus);
    if (target != NULL) {
        if (target == L.first) {
            deleteFirst(L, P);
        } else if (target == L.last) {
            deleteLast(L, P);
        } else {
            Node* Prec = target->prev;
            deleteAfter(Prec, P);
        }
        cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus." << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    // Tampilkan hasil akhir
    printInfo(L);
    return 0;
}

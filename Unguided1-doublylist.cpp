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

    // menampilkan hasil
    printInfo(L);

    return 0;
}

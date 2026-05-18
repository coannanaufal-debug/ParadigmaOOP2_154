#include <iostream>
#include <string>

using namespace std;

class RekeningBank {
public:
    string namaNasabah;
    double saldo;

    // Konstruktor untuk mengisi nama dan saldo awal
    RekeningBank(string nama, double saldoAwal) {
        namaNasabah = nama;
        saldo = saldoAwal;
    }

   
       virtual void potongAdmin() = 0; 

    // Fungsi biasa untuk cetak saldo
    void tampilkanSaldo() {
        cout << "Nasabah: " << namaNasabah << " | Saldo: Rp " << saldo << endl;
    }
};


class RekeningSyariah : public RekeningBank {
public:
    // Mengirim data nama & saldo ke kelas induk (RekeningBank)
    RekeningSyariah(string nama, double saldoAwal) : RekeningBank(nama, saldoAwal) {}

    // Mengisi logika potongAdmin untuk Syariah
    void potongAdmin() override {
        cout << "[Syariah] Bebas biaya admin. Saldo " << namaNasabah << " tetap.\n";
    }
};


class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string nama, double saldoAwal) : RekeningBank(nama, saldoAwal) {}

    // Mengisi logika potongAdmin untuk Konvensional
    void potongAdmin() override {
        saldo = saldo - 15000; // Potong langsung 15 ribu
        cout << "[Konvensional] Saldo " << namaNasabah << " dipotong Rp 15.000\n";
    }
};


class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string nama, double saldoAwal) : RekeningBank(nama, saldoAwal) {}

    
    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "[Premium] " << namaNasabah << " di atas 10 Juta, GRATIS admin.\n";
        } else {
            saldo = saldo - 50000; // Potong 50 ribu jika di bawah atau sama dengan 10 juta
            cout << "[Premium] " << namaNasabah << " <= 10 Juta, dipotong Rp 50.000\n";
        }
    }
};


int main() {
    RekeningBank* daftarRekening[4];

    
    daftarRekening[0] = new RekeningSyariah("Ahmad", 5000000);
    daftarRekening[1] = new RekeningKonvensional("Budi", 2000000);
    daftarRekening[2] = new RekeningPremium("Citra", 15000000); // Saldo besar
    daftarRekening[3] = new RekeningPremium("Dodi", 8000000);   // Saldo kecil

    cout << "--- SALDO AWAL NASABAH ---\n";
    for(int i = 0; i < 4; i++) {
        daftarRekening[i]->tampilkanSaldo();
    }
    cout << "\n";

    cout << "--- PROSES POTONG ADMIN AKHIR BULAN ---\n";
    for(int i = 0; i < 4; i++) {
        daftarRekening[i]->potongAdmin(); 
    }
    cout << "\n";

    cout << "--- SALDO AKHIR NASABAH ---\n";
    for(int i = 0; i < 4; i++) {
        daftarRekening[i]->tampilkanSaldo();
    }

    return 0;
}
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int pin = 1234, inputPin, saldo = 500000;
    int kesempatan = 3;

    int rekeningTujuan[3] = {111, 222, 333};

    // Riwayat transaksi 
    string riwayat[10];
    int idxRiwayat = 0;
    
    // LOGIN PIN

    while (kesempatan > 0) {
        cout << "Masukkan PIN: ";
        cin >> inputPin;

        if (inputPin == pin) {
            cout << "Login berhasil!\n\n";
            break;
        } else {
            kesempatan--;
            cout << "PIN salah! Kesempatan tersisa: " << kesempatan << "\n";
        }

        if (kesempatan == 0) {
            cout << "Akun diblokir! Program berhenti.\n";
            return 0;
        }
    }

    int pilihan;

    // MENU UTAMA
    do {
        cout << "\n===== MENU ATM =====\n";
        cout << "1. Cek Saldo\n";
        cout << "2. Tarik Tunai\n";
        cout << "3. Setor Tunai\n";
        cout << "4. Transfer\n";
        cout << "5. Riwayat Transaksi\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {

       
        // CEK SALDO

        case 1:
            cout << "Saldo Anda: Rp " << saldo << "\n";
            break;


        // TARIK TUNAI
    
        case 2: {
            int tarik;
            cout << "Masukkan jumlah penarikan: ";
            cin >> tarik;

            if (tarik <= 0) {
                cout << "Jumlah tidak valid!\n";
            } else if (tarik < 20000) {
                cout << "Minimal penarikan adalah Rp 20.000!\n";
            } else if (tarik > saldo) {
                cout << "Saldo tidak mencukupi!\n";
            } else {
                saldo -= tarik;
                cout << "Penarikan berhasil!\n";

                // simpan riwayat
                if (idxRiwayat < 10) {
                    riwayat[idxRiwayat++] = "Tarik " + to_string(tarik);
                }
            }
            break;
        }

        // SETOR TUNAI
        
        case 3: {
            int setor;
            cout << "Masukkan jumlah setor: ";
            cin >> setor;

            if (setor <= 0) {
                cout << "Jumlah tidak valid!\n";
            } else if (setor % 10000 != 0) {
                cout << "Jumlah harus kelipatan Rp 10.000!\n";
            } else {
                saldo += setor;
                cout << "Setor tunai berhasil!\n";

                // simpan riwayat
                if (idxRiwayat < 10) {
                    riwayat[idxRiwayat++] = "Setor " + to_string(setor);
                }
            }
            break;
        }
  
        // TRANSFER
        case 4: {
            int rek, nominal;
            bool ditemukan = false;

            cout << "Masukkan nomor rekening tujuan: ";
            cin >> rek;

            for (int i = 0; i < 3; i++) {
                if (rek == rekeningTujuan[i]) {
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan) {
                cout << "Rekening tidak ditemukan!\n";
                break;
            }

            cout << "Masukkan nominal transfer: ";
            cin >> nominal;

            if (nominal <= 0) {
                cout << "Nominal tidak valid!\n";
            } else if (nominal > saldo) {
                cout << "Saldo tidak cukup!\n";
            } else {
                saldo -= nominal;
                cout << "Transfer berhasil ke rekening " << rek << "!\n";

                // simpan riwayat
                if (idxRiwayat < 10) {
                    riwayat[idxRiwayat++] =
                        "Transfer " + to_string(nominal) + " ke " + to_string(rek);
                }
            }
            break;
        }

        // RIWAYAT TRANSAKSI
        case 5:
            cout << "\n===== Riwayat Transaksi =====\n";
            if (idxRiwayat == 0) {
                cout << "Belum ada transaksi.\n";
            } else {
                for (int i = 0; i < idxRiwayat; i++) {
                    cout << i + 1 << ". " << riwayat[i] << "\n";
                }
            }
            break;

        
        // KELUAR
        case 6:
            cout << "Terima kasih telah menggunakan ATM!\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 6);

    return 0;
}

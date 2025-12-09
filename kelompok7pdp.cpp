// Program ATM Sederhana

#include <iostream>
#include <string>
using namespace std;

int main() {
    // === DATA AWAL ===
    string pinBenar = "1234";
    string pinInput;
    int kesempatan = 3;

    int saldo = 500000;

    // Daftar rekening lain (array)
    int rekening[3] = {111, 222, 333};
    int saldoRek[3] = {300000, 150000, 200000};

    // Riwayat transaksi (array)
    string riwayat[20];
    int indexRiwayat = 0;

    // === LOGIN PIN ===
    while (kesempatan > 0) {
        cout << "Masukkan PIN: ";
        cin >> pinInput;

        if (pinInput == pinBenar) {
            cout << "Login berhasil!\n";
            break;
        } else {
            kesempatan--;
            cout << "PIN salah! Sisa kesempatan: " << kesempatan << endl;
        }

        if (kesempatan == 0) {
            cout << "Akun terblokir. Program berhenti.\n";
            return 0;
        }
    }

    // === MENU UTAMA ===
    int pilihan;
    do {
        cout << "\n===== MENU ATM =====\n";
        cout << "1. Cek Saldo\n";
        cout << "2. Tarik Tunai\n";
        cout << "3. Setor Tunai\n";
        cout << "4. Transfer\n";
        cout << "5. Riwayat Transaksi\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;

        switch (pilihan) {

        // === CEK SALDO ===
        case 1:
            cout << "Saldo Anda saat ini: Rp " << saldo << endl;
            break;

        // === TARIK TUNAI ===
        case 2: {
            int tarik;
            cout << "Masukkan jumlah penarikan: ";
            cin >> tarik;

            if (tarik <= 0) {
                cout << "Jumlah tidak boleh 0 atau negatif!\n";
            } else if (tarik < 20000) {
                cout << "Minimal penarikan adalah Rp 20.000!\n";
            } else if (tarik > saldo) {
                cout << "Saldo tidak mencukupi!\n";
            } else {
                saldo -= tarik;
                cout << "Penarikan berhasil!\n";

                riwayat[indexRiwayat++] = "Tarik " + to_string(tarik);
            }
            break;
        }

        // === SETOR TUNAI ===
        case 3: {
            int setor;
            cout << "Masukkan jumlah setor: ";
            cin >> setor;

            if (setor <= 0) {
                cout << "Jumlah tidak boleh 0 atau negatif!\n";
            } else if (setor % 10000 != 0) {
                cout << "Setoran harus kelipatan Rp 10.000!\n";
            } else {
                saldo += setor;
                cout << "Setoran berhasil!\n";

                riwayat[indexRiwayat++] = "Setor " + to_string(setor);
            }
            break;
        }

        // === TRANSFER ===
        case 4: {
            int tujuan, jumlah;
            cout << "Masukkan nomor rekening tujuan: ";
            cin >> tujuan;

            bool ditemukan = false;
            int pos = 0;

            // Cari rekening tujuan
            for (int i = 0; i < 3; i++) {
                if (rekening[i] == tujuan) {
                    ditemukan = true;
                    pos = i;
                    break;
                }
            }

            if (!ditemukan) {
                cout << "Rekening tidak ditemukan!\n";
                break;
            }

            cout << "Masukkan jumlah transfer: ";
            cin >> jumlah;

            if (jumlah <= 0) {
                cout << "Jumlah tidak valid!\n";
            } else if (jumlah > saldo) {
                cout << "Saldo tidak mencukupi!\n";
            } else {
                saldo -= jumlah;
                saldoRek[pos] += jumlah;

                cout << "Transfer berhasil ke rekening " << tujuan << endl;

                riwayat[indexRiwayat++] =
                    "Transfer " + to_string(jumlah) + " ke " + to_string(tujuan);
            }

            break;
        }

        // === RIWAYAT TRANSAKSI ===
        case 5:
            cout << "\n=== RIWAYAT TRANSAKSI ===\n";
            if (indexRiwayat == 0) {
                cout << "Belum ada transaksi.\n";
            } else {
                for (int i = 0; i < indexRiwayat; i++) {
                    cout << i + 1 << ". " << riwayat[i] << endl;
                }
            }
            break;

        // === KELUAR ===
        case 6:
            cout << "Terima kasih telah menggunakan ATM.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 6);

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nrp;
    int umur;
    bool jenis_kelamin;
};

const int MAX_MAHASISWA = 10;

void TampilkanData(const Mahasiswa mhs[], int jumlah_mahasiswa) {
    cout << "Data Mahasiswa:" << endl;
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        cout << "Data ke-" << i + 1 << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NRP: " << mhs[i].nrp << endl;
        cout << "Umur: " << mhs[i].umur << endl;
        cout << "Jenis Kelamin: " << (mhs[i].jenis_kelamin ? "Laki-laki" : "Perempuan") << endl;
        cout << "-------------------------" << endl;
    }
}

int main() {
    Mahasiswa mhs[MAX_MAHASISWA];
    int jumlah_mahasiswa = 0;
    int input_user;

    do {
        cout << "Menu: " << endl;
        cout << "1. Menampilkan Data" << endl;
        cout << "2. Menambah Data" << endl;
        cout << "3. Menghapus Data" << endl;
        cout << "4. Mengubah Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> input_user;

        switch (input_user) {
            case 1:
                TampilkanData(mhs, jumlah_mahasiswa);
                break;
            case 2:
                if (jumlah_mahasiswa < MAX_MAHASISWA) {
                    cout << "Masukkan data mahasiswa baru:" << endl;
                    cout << "Nama: ";
                    cin.ignore();
                    getline(cin, mhs[jumlah_mahasiswa].nama);
                    cout << "NRP: ";
                    cin >> mhs[jumlah_mahasiswa].nrp;
                    cout << "Umur: ";
                    cin >> mhs[jumlah_mahasiswa].umur;
                    cout << "Jenis Kelamin (1: Laki-laki, 0: Perempuan): ";
                    cin >> mhs[jumlah_mahasiswa].jenis_kelamin;
                    jumlah_mahasiswa++;
                    cout << "Data mahasiswa telah ditambahkan." << endl;
                } else {
                    cout << "Batas maksimum data mahasiswa telah tercapai." << endl;
                }
                break;
            case 3:
                if (jumlah_mahasiswa > 0) {
                    int indeks_hapus;
                    cout << "Masukkan indeks data yang akan dihapus (0 - " << jumlah_mahasiswa - 1 << "): ";
                    cin >> indeks_hapus;
                    if (indeks_hapus >= 0 && indeks_hapus < jumlah_mahasiswa) {
                        for (int i = indeks_hapus; i < jumlah_mahasiswa - 1; i++) {
                            mhs[i] = mhs[i + 1];
                        }
                        jumlah_mahasiswa--;
                        cout << "Data mahasiswa telah dihapus." << endl;
                    } else {
                        cout << "Indeks tidak valid." << endl;
                    }
                } else {
                    cout << "Tidak ada data mahasiswa yang dapat dihapus." << endl;
                }
                break;
            case 4:
                if (jumlah_mahasiswa > 0) {
                    int indeks_ubah;
                    cout << "Masukkan indeks data yang akan diubah (0 - " << jumlah_mahasiswa - 1 << "): ";
                    cin >> indeks_ubah;
                    if (indeks_ubah >= 0 && indeks_ubah < jumlah_mahasiswa) {
                        cout << "Masukkan data mahasiswa yang baru:" << endl;
                        cout << "Nama: ";
                        cin.ignore();
                        getline(cin, mhs[indeks_ubah].nama);
                        cout << "NRP: ";
                        cin >> mhs[indeks_ubah].nrp;
                        cout << "Umur: ";
                        cin >> mhs[indeks_ubah].umur;
                        cout << "Jenis Kelamin (1: Laki-laki, 0: Perempuan): ";
                        cin >> mhs[indeks_ubah].jenis_kelamin;
                        cout << "Data mahasiswa telah diubah." << endl;
                    } else {
                        cout << "Indeks tidak valid." << endl;
                    }
                } else {
                    cout << "Tidak ada data mahasiswa yang dapat diubah." << endl;
                }
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan menu tidak valid." << endl;
                break;
        }
    } while (input_user != 5);

    return 0;
}


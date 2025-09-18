#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Untuk std::sort, std::find, dan std::count_if
#include <numeric>   // Diperlukan untuk beberapa compiler std::count_if

// Menggunakan namespace std untuk mempersingkat penulisan
using namespace std;

int main() {
    // Optimasi input/output agar program berjalan lebih cepat
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // --- Bagian Input Buku ---
    int jumlahBuku;
    cin >> jumlahBuku;

    vector<string> daftarBuku(jumlahBuku);
    for (int i = 0; i < jumlahBuku; ++i) {
        cin >> daftarBuku[i];
    }

    // --- Bagian Pemrosesan Operasi ---
    int jumlahOperasi;
    cin >> jumlahOperasi;

    while (jumlahOperasi--) {
        string jenisOperasi;
        cin >> jenisOperasi;

        if (jenisOperasi == "CARI") {
            string kodeCari;
            cin >> kodeCari;
            
            // Menggunakan std::find untuk mencari elemen
            // Lebih ringkas daripada loop manual dengan flag boolean
            auto it = find(daftarBuku.begin(), daftarBuku.end(), kodeCari);

            if (it != daftarBuku.end()) {
                cout << "ADA\n";
            } else {
                cout << "TIDAK ADA\n";
            }

        } else if (jenisOperasi == "HITUNG") {
            string subStringCari;
            cin >> subStringCari;
            
            // Menggunakan std::count_if dengan lambda expression untuk menghitung
            int total = count_if(daftarBuku.begin(), daftarBuku.end(), 
                [&](const string& buku) {
                    // Mengembalikan true jika substring ditemukan dalam kode buku
                    return buku.find(subStringCari) != string::npos;
                }
            );
            
            cout << total << "\n";

        } else if (jenisOperasi == "URUT") {
            // Salin daftar buku agar urutan aslinya tidak berubah
            vector<string> bukuUrut = daftarBuku;
            sort(bukuUrut.begin(), bukuUrut.end());
            
            // Cetak setiap buku yang sudah diurutkan
            for (const string& buku : bukuUrut) {
                cout << buku << "\n";
            }
        }
    }

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <deque>

// Struct untuk menyimpan data riwayat secara jelas
// Ini kunci untuk membatalkan operasi HAPUS dengan benar
struct HistoryEntry {
    std::string operation; // "KETIK" atau "HAPUS"
    char character;      // Menyimpan karakter yang dihapus. Tidak digunakan untuk KETIK.
};

// Fungsi untuk mempercepat I/O di C++
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

int main() {
    setup_io();

    int n;
    std::cin >> n;

    std::string buffer = "";
    // Menggunakan deque agar efisien menghapus elemen tertua (pop_front)
    std::deque<HistoryEntry> history;
    const int MAX_HISTORY = 20;
    const int MAX_BUFFER = 500;

    std::string command;
    // Loop untuk setiap operasi
    while (n-- > 0 && std::cin >> command) {
        
        // --- KETIK ---
        if (command == "KETIK") {
            char c;
            std::cin >> c;
            if (buffer.length() < MAX_BUFFER) {
                buffer += c;
                // Hanya KETIK yang masuk riwayat
                if (history.size() == MAX_HISTORY) {
                    history.pop_front(); // Buang riwayat tertua jika penuh
                }
                history.push_back({"KETIK", '\0'}); // Char tidak penting untuk KETIK
                std::cout << "OK\n";
            } else {
                std::cout << "BUFFER PENUH\n";
            }
        
        // --- HAPUS ---
        } else if (command == "HAPUS") {
            if (!buffer.empty()) {
                char last_char = buffer.back();
                buffer.pop_back();
                // Hanya HAPUS yang masuk riwayat, simpan juga karakternya
                if (history.size() == MAX_HISTORY) {
                    history.pop_front();
                }
                history.push_back({"HAPUS", last_char});
                std::cout << "OK\n";
            } else {
                std::cout << "BUFFER KOSONG\n";
            }
        
        // --- BATAL ---
        } else if (command == "BATAL") {
            if (!history.empty()) {
                HistoryEntry last_op = history.back();
                history.pop_back();
                
                if (last_op.operation == "KETIK") {
                    // Membatalkan KETIK -> hapus karakter
                    if (!buffer.empty()) {
                        buffer.pop_back();
                    }
                } else if (last_op.operation == "HAPUS") {
                    // Membatalkan HAPUS -> kembalikan karakter yang disimpan
                    buffer += last_op.character;
                }
                std::cout << "DIBATALKAN\n";
            } else {
                std::cout << "TIDAK ADA OPERASI\n";
            }
        
        // --- LIHAT ---
        // Tidak masuk riwayat
        } else if (command == "LIHAT") {
            if (buffer.empty()) {
                std::cout << "KOSONG\n";
            } else {
                std::cout << buffer << "\n";
            }
        
        // --- CARI ---
        // Tidak masuk riwayat
        } else if (command == "CARI") {
            std::string word;
            std::cin >> word;
            size_t pos = buffer.find(word); // size_t adalah tipe data yang tepat
            if (pos != std::string::npos) {
                std::cout << "DITEMUKAN " << pos << "\n";
            } else {
                std::cout << "TIDAK DITEMUKAN\n";
            }
        }
    }

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>

struct HistoryEntry {
    std::string operation;
    char character;
};

void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

int main() {
    setup_io();

    int n;
    if (!(std::cin >> n)) return 0;

    std::string line;
    std::getline(std::cin, line);

    std::string buffer = "";
    std::deque<HistoryEntry> history;
    const int MAX_HISTORY = 20;
    const int MAX_BUFFER = 500;

    while (n-- > 0 && std::getline(std::cin, line)) {
        if (line.empty() || line.find_first_not_of(" \t\n\v\f\r") == std::string::npos) continue;
        
        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if (command == "KETIK") {
            // --- INI ADALAH PERBAIKAN UTAMA ---
            char c;
            ss.get(); // Mencoba membaca spasi pemisah
            if (ss.peek() == EOF || ss.eof()) {
                // Jika tidak ada apa-apa lagi setelah 'KETIK '
                // artinya karakter yang dimaksud adalah spasi.
                c = ' ';
            } else {
                // Jika ada karakter, baca karakter tersebut.
                ss.get(c);
            }
            
            if (buffer.length() < MAX_BUFFER) {
                buffer += c;
                if (history.size() == MAX_HISTORY) history.pop_front();
                history.push_back({"KETIK", '\0'});
                std::cout << "OK\n";
            } else {
                std::cout << "BUFFER PENUH\n";
            }
        } else if (command == "HAPUS") {
            if (!buffer.empty()) {
                char last_char = buffer.back();
                buffer.pop_back();
                if (history.size() == MAX_HISTORY) history.pop_front();
                history.push_back({"HAPUS", last_char});
                std::cout << "OK\n";
            } else {
                std::cout << "BUFFER KOSONG\n";
            }
        } else if (command == "BATAL") {
            if (!history.empty()) {
                HistoryEntry last_op = history.back();
                history.pop_back();
                if (last_op.operation == "KETIK") {
                    if (!buffer.empty()) buffer.pop_back();
                } else if (last_op.operation == "HAPUS") {
                    buffer += last_op.character;
                }
                std::cout << "DIBATALKAN\n";
            } else {
                std::cout << "TIDAK ADA OPERASI\n";
            }
        } else if (command == "LIHAT") {
            if (buffer.empty()) {
                std::cout << "KOSONG\n";
            } else {
                std::cout << buffer << "\n";
            }
        } else if (command == "CARI") {
            std::string word;
            if (ss >> word) {
                size_t pos = buffer.find(word);
                if (pos != std::string::npos) {
                    std::cout << "DITEMUKAN " << pos << "\n";
                } else {
                    std::cout << "TIDAK DITEMUKAN\n";
                }
            }
        }
    }
    return 0;
}
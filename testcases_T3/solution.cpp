
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <sstream>

struct Patient {
    int number;
    std::string name;
};

void print_queue(std::queue<Patient> q) {
    if (q.empty()) {
        std::cout << "kosong";
        return;
    }
    bool first = true;
    while (!q.empty()) {
        if (!first) {
            std::cout << " ";
        }
        Patient p = q.front();
        q.pop();
        std::cout << p.number << "-" << p.name;
        first = false;
    }
}

void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

int main() {
    setup_io();

    int n;
    std::cin >> n;

    std::queue<Patient> emergency_q;
    std::queue<Patient> regular_q;
    std::set<int> registered_numbers;
    const int MAX_PATIENTS = 30;

    std::string command;
    while (n-- > 0) {
        std::cin >> command;

        if (command == "DAFTAR") {
            int number;
            std::string name, type;
            std::cin >> number >> name >> type;

            if (registered_numbers.count(number)) {
                std::cout << "NOMOR SUDAH ADA\n";
            } else if (emergency_q.size() + regular_q.size() >= MAX_PATIENTS) {
                 std::cout << "ANTRIAN PENUH\n";
            } else {
                registered_numbers.insert(number);
                Patient new_patient = {number, name};
                if (type == "E") {
                    emergency_q.push(new_patient);
                } else {
                    regular_q.push(new_patient);
                }
                std::cout << "TERDAFTAR\n";
            }
        } else if (command == "PANGGIL") {
            if (!emergency_q.empty()) {
                Patient p = emergency_q.front();
                emergency_q.pop();
                std::cout << "PANGGIL " << p.number << " " << p.name << "\n";
            } else if (!regular_q.empty()) {
                Patient p = regular_q.front();
                regular_q.pop();
                std::cout << "PANGGIL " << p.number << " " << p.name << "\n";
            } else {
                std::cout << "ANTRIAN KOSONG\n";
            }
        } else if (command == "LIHAT") {
            if (emergency_q.empty() && regular_q.empty()) {
                std::cout << "ANTRIAN KOSONG\n";
            } else {
                std::cout << "EMERGENCY: ";
                print_queue(emergency_q);
                std::cout << "\n";
                std::cout << "REGULAR: ";
                print_queue(regular_q);
                std::cout << "\n";
            }
        } else if (command == "CARI") {
            int number_to_find;
            std::cin >> number_to_find;
            bool found = false;

            std::queue<Patient> temp_e = emergency_q;
            int pos = 1;
            while (!temp_e.empty()) {
                if (temp_e.front().number == number_to_find) {
                    std::cout << "POSISI " << pos << " EMERGENCY\n";
                    found = true;
                    break;
                }
                temp_e.pop();
                pos++;
            }

            if (!found) {
                std::queue<Patient> temp_r = regular_q;
                pos = 1;
                while (!temp_r.empty()) {
                    if (temp_r.front().number == number_to_find) {
                        std::cout << "POSISI " << pos << " REGULAR\n";
                        found = true;
                        break;
                    }
                    temp_r.pop();
                    pos++;
                }
            }

            if (!found) {
                std::cout << "TIDAK DITEMUKAN\n";
            }
        }
    }

    return 0;
}

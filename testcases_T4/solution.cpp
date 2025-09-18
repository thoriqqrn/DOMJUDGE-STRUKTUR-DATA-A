
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct Node {
    std::string name;
    Node* parent;
    std::vector<Node*> children;

    Node(std::string n, Node* p = nullptr) : name(n), parent(p) {}
};

std::map<std::string, Node*> all_people;
std::vector<Node*> family_roots;

int calculate_depth(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    if (node->children.empty()) {
        return 1;
    }
    int max_child_depth = 0;
    for (Node* child : node->children) {
        max_child_depth = std::max(max_child_depth, calculate_depth(child));
    }
    return 1 + max_child_depth;
}

void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

int main() {
    setup_io();

    int n;
    std::cin >> n;

    std::string command;
    while (n-- > 0) {
        std::cin >> command;

        if (command == "KELUARGA_BARU") {
            std::string name;
            std::cin >> name;
            if (all_people.count(name)) {
                std::cout << "NAMA SUDAH ADA\n";
            } else {
                Node* new_person = new Node(name);
                all_people[name] = new_person;
                family_roots.push_back(new_person);
                std::cout << "KELUARGA DIBUAT\n";
            }
        } else if (command == "TAMBAH_ANAK") {
            std::string parent_name, child_name;
            std::cin >> parent_name >> child_name;
            if (all_people.find(parent_name) == all_people.end()) {
                std::cout << "ORANGTUA TIDAK ADA\n";
            } else if (all_people.count(child_name)) {
                std::cout << "NAMA SUDAH ADA\n";
            } else {
                Node* parent_node = all_people[parent_name];
                Node* child_node = new Node(child_name, parent_node);
                parent_node->children.push_back(child_node);
                all_people[child_name] = child_node;
                std::cout << "ANAK DITAMBAHKAN\n";
            }
        } else if (command == "ADA_ORANG") {
            std::string name;
            std::cin >> name;
            if (all_people.count(name)) {
                std::cout << "ADA\n";
            } else {
                std::cout << "TIDAK ADA\n";
            }
        } else if (command == "CARI_ORANGTUA") {
            std::string name;
            std::cin >> name;
            if (all_people.find(name) == all_people.end()) {
                std::cout << "TIDAK DITEMUKAN\n";
            } else {
                Node* person = all_people[name];
                if (person->parent == nullptr) {
                    std::cout << "KEPALA KELUARGA\n";
                } else {
                    std::cout << "ORANGTUA: " << person->parent->name << "\n";
                }
            }
        } else if (command == "LIHAT_ANAK") {
            std::string name;
            std::cin >> name;
            if (all_people.find(name) == all_people.end()) {
                std::cout << "TIDAK DITEMUKAN\n";
            } else {
                Node* person = all_people[name];
                if (person->children.empty()) {
                    std::cout << "TIDAK ADA ANAK\n";
                } else {
                    std::cout << "ANAK:";
                    for (Node* child : person->children) {
                        std::cout << " " << child->name;
                    }
                    std::cout << "\n";
                }
            }
        } else if (command == "HITUNG_GENERASI") {
            int max_generasi = 0;
            for (Node* root : family_roots) {
                max_generasi = std::max(max_generasi, calculate_depth(root));
            }
            std::cout << "GENERASI: " << max_generasi << "\n";
        }
    }
    
    for(auto const& [name, node] : all_people) {
        delete node;
    }

    return 0;
}

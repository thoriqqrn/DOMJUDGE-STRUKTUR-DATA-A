
import sys

class Node:
    def __init__(self, name, parent=None):
        self.name = name
        self.parent = parent
        self.children = []

def calculate_depth(node):
    if not node.children:
        return 1
    max_child_depth = 0
    for child in node.children:
        max_child_depth = max(max_child_depth, calculate_depth(child))
    return 1 + max_child_depth

def solve():
    try:
        n_str = sys.stdin.readline()
        if not n_str: return
        n = int(n_str)
        all_people = {}
        family_roots = []
        for _ in range(n):
            line = sys.stdin.readline().strip().split()
            if not line: continue
            command = line[0]
            if command == "KELUARGA_BARU":
                name = line[1]
                if name in all_people:
                    print("NAMA SUDAH ADA")
                else:
                    new_person = Node(name)
                    all_people[name] = new_person
                    family_roots.append(new_person)
                    print("KELUARGA DIBUAT")
            elif command == "TAMBAH_ANAK":
                parent_name, child_name = line[1], line[2]
                if parent_name not in all_people:
                    print("ORANGTUA TIDAK ADA")
                elif child_name in all_people:
                    print("NAMA SUDAH ADA")
                else:
                    parent_node = all_people[parent_name]
                    child_node = Node(child_name, parent=parent_node)
                    parent_node.children.append(child_node)
                    all_people[child_name] = child_node
                    print("ANAK DITAMBAHKAN")
            elif command == "ADA_ORANG":
                name = line[1]
                print("ADA" if name in all_people else "TIDAK ADA")
            elif command == "CARI_ORANGTUA":
                name = line[1]
                if name not in all_people:
                    print("TIDAK DITEMUKAN")
                else:
                    person = all_people[name]
                    if person.parent is None:
                        print("KEPALA KELUARGA")
                    else:
                        print(f"ORANGTUA: {person.parent.name}")
            elif command == "LIHAT_ANAK":
                name = line[1]
                if name not in all_people:
                    print("TIDAK DITEMUKAN")
                else:
                    person = all_people[name]
                    if not person.children:
                        print("TIDAK ADA ANAK")
                    else:
                        child_names = " ".join([child.name for child in person.children])
                        print(f"ANAK: {child_names}")
            elif command == "HITUNG_GENERASI":
                max_generasi = 0
                for root in family_roots:
                    max_generasi = max(max_generasi, calculate_depth(root))
                print(f"GENERASI: {max_generasi}")
    except (IOError, ValueError, IndexError):
        return

if __name__ == "__main__":
    solve()

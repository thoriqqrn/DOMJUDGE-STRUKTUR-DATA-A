
import sys
from collections import deque

def solve():
    # Solusi untuk masalah Antrian Puskesmas Pak Dokter.

    try:
        n_str = sys.stdin.readline()
        if not n_str: return
        n = int(n_str)

        emergency_q = deque()
        regular_q = deque()
        registered_numbers = set()
        MAX_PATIENTS = 30

        for _ in range(n):
            line = sys.stdin.readline().strip().split()
            if not line: continue
            command = line[0]

            if command == "DAFTAR":
                number, name, type = int(line[1]), line[2], line[3]
                if number in registered_numbers:
                    print("NOMOR SUDAH ADA")
                elif len(emergency_q) + len(regular_q) >= MAX_PATIENTS:
                    print("ANTRIAN PENUH")
                else:
                    registered_numbers.add(number)
                    patient_data = (number, name)
                    if type == 'E':
                        emergency_q.append(patient_data)
                    else:
                        regular_q.append(patient_data)
                    print("TERDAFTAR")

            elif command == "PANGGIL":
                if emergency_q:
                    number, name = emergency_q.popleft()
                    print(f"PANGGIL {number} {name}")
                elif regular_q:
                    number, name = regular_q.popleft()
                    print(f"PANGGIL {number} {name}")
                else:
                    print("ANTRIAN KOSONG")

            elif command == "LIHAT":
                if not emergency_q and not regular_q:
                    print("ANTRIAN KOSONG")
                else:
                    e_list = " ".join([f"{p[0]}-{p[1]}" for p in emergency_q])
                    r_list = " ".join([f"{p[0]}-{p[1]}" for p in regular_q])
                    print(f"EMERGENCY: {e_list if e_list else 'kosong'}")
                    print(f"REGULAR: {r_list if r_list else 'kosong'}")

            elif command == "CARI":
                number_to_find = int(line[1])
                found = False
                
                pos = 1
                for number, name in emergency_q:
                    if number == number_to_find:
                        print(f"POSISI {pos} EMERGENCY")
                        found = True
                        break
                    pos += 1
                
                if not found:
                    pos = 1
                    for number, name in regular_q:
                        if number == number_to_find:
                            print(f"POSISI {pos} REGULAR")
                            found = True
                            break
                        pos += 1
                
                if not found:
                    print("TIDAK DITEMUKAN")

    except (IOError, ValueError, IndexError):
        return

if __name__ == "__main__":
    solve()

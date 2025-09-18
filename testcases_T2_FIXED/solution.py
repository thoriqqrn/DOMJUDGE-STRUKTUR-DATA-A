import sys
from collections import deque

def solve():
    try:
        n_str = sys.stdin.readline()
        if not n_str: return
        n = int(n_str.strip())

        buffer = []
        history = deque(maxlen=20) 
        MAX_BUFFER = 500

        for _ in range(n):
            line_raw = sys.stdin.readline()
            if not line_raw.strip(): continue # Lewati baris kosong
            
            # Memisahkan perintah dan argumen dengan lebih aman
            parts = line_raw.strip().split(' ', 1)
            command = parts[0]

            if command == "KETIK":
                # PERIKSA APAKAH ARGUMEN ADA
                if len(parts) < 2: continue # Jika input hanya "KETIK", abaikan baris ini
                
                char_to_add = parts[1]
                if len(buffer) < MAX_BUFFER:
                    buffer.append(char_to_add)
                    history.append(("KETIK", None)) 
                    print("OK")
                else:
                    print("BUFFER PENUH")
            
            elif command == "HAPUS":
                if buffer:
                    last_char = buffer.pop()
                    history.append(("HAPUS", last_char))
                    print("OK")
                else:
                    print("BUFFER KOSONG")

            elif command == "BATAL":
                if history:
                    last_op, data = history.pop()
                    if last_op == "KETIK":
                        if buffer: buffer.pop()
                    elif last_op == "HAPUS":
                        buffer.append(data)
                    print("DIBATALKAN")
                else:
                    print("TIDAK ADA OPERASI")

            elif command == "LIHAT":
                if buffer:
                    print("".join(buffer))
                else:
                    print("KOSONG")

            elif command == "CARI":
                # PERIKSA APAKAH ARGUMEN ADA
                if len(parts) < 2: continue # Jika input hanya "CARI", abaikan baris ini
                
                word_to_find = parts[1]
                current_buffer_str = "".join(buffer)
                pos = current_buffer_str.find(word_to_find)
                if pos != -1:
                    print(f"DITEMUKAN {pos}")
                else:
                    print("TIDAK DITEMUKAN")
    
    except (IOError, ValueError, IndexError):
        return

if __name__ == "__main__":
    solve()
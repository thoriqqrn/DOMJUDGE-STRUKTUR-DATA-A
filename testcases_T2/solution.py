import sys
from collections import deque

def solve():
    """
    Solusi lengkap dan benar untuk masalah Mesin Ketik Bu Sari (T2).
    - Menggunakan deque(maxlen=20) untuk riwayat yang efisien.
    - Hanya menyimpan operasi KETIK dan HAPUS di riwayat.
    - Menyimpan karakter yang dihapus saat HAPUS untuk bisa di-undo.
    """
    try:
        # Baca jumlah operasi
        n_str = sys.stdin.readline()
        if not n_str: return
        n = int(n_str)

        # Inisialisasi buffer dan riwayat
        buffer = []
        # Deque dengan maxlen=20 secara otomatis menangani batas 20 riwayat
        # dengan membuang elemen tertua saat penuh.
        history = deque(maxlen=20) 
        MAX_BUFFER = 500

        for _ in range(n):
            line = sys.stdin.readline().strip().split()
            if not line: continue
            command = line[0]

            # --- KETIK ---
            if command == "KETIK":
                char_to_add = line[1]
                if len(buffer) < MAX_BUFFER:
                    buffer.append(char_to_add)
                    # Riwayat hanya menyimpan tuple (operasi, data_tambahan)
                    # Untuk KETIK, data tambahan tidak diperlukan.
                    history.append(("KETIK", None)) 
                    print("OK")
                else:
                    print("BUFFER PENUH")
            
            # --- HAPUS ---
            elif command == "HAPUS":
                if buffer:
                    last_char = buffer.pop()
                    # Simpan karakter yang dihapus agar bisa dikembalikan saat BATAL
                    history.append(("HAPUS", last_char))
                    print("OK")
                else:
                    print("BUFFER KOSONG")

            # --- BATAL (Undo) ---
            elif command == "BATAL":
                if history:
                    last_op, data = history.pop() # Ambil operasi terakhir dari riwayat
                    
                    if last_op == "KETIK":
                        # Membatalkan KETIK berarti menghapus karakter terakhir
                        if buffer: buffer.pop()
                    elif last_op == "HAPUS":
                        # Membatalkan HAPUS berarti mengembalikan karakter yang disimpan
                        buffer.append(data)
                    
                    print("DIBATALKAN")
                else:
                    print("TIDAK ADA OPERASI")

            # --- LIHAT ---
            # Operasi ini tidak mengubah state dan tidak masuk riwayat
            elif command == "LIHAT":
                if buffer:
                    print("".join(buffer))
                else:
                    print("KOSONG")

            # --- CARI ---
            # Operasi ini tidak mengubah state dan tidak masuk riwayat
            elif command == "CARI":
                word_to_find = line[1]
                current_buffer_str = "".join(buffer)
                pos = current_buffer_str.find(word_to_find)
                if pos != -1:
                    print(f"DITEMUKAN {pos}")
                else:
                    print("TIDAK DITEMUKAN")
    
    except (IOError, ValueError, IndexError):
        # Penanganan error jika input tidak sesuai/kosong
        return

if __name__ == "__main__":
    solve()
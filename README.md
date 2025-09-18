# DOMJUDGE-STRUKTUR-DATA-A
<img width="369" height="136" alt="image" src="https://github.com/user-attachments/assets/cbc6e895-65db-489a-89ae-55347116d0e8" />


# Kumpulan Soal Latihan Struktur Data - Domjudge Teknik Komputer ITS

Selamat datang di repositori kumpulan soal latihan untuk mata kuliah Struktur Data dan Algoritma, Departemen Teknik Komputer ITS. Repositori ini berisi deskripsi soal, contoh solusi dalam C++ dan Python, serta paket test case yang dapat digunakan untuk pengujian lokal sebelum di-submit ke sistem Domjudge.

## Struktur Repositori

Setiap soal latihan memiliki folder tersendiri dengan struktur sebagai berikut:

```
.
├── T0_Perpustakaan_Bu_Ningsih/
│   ├── README.md                # Deskripsi soal (hasil OCR dari PDF)
│   ├── solution.cpp             # Contoh solusi dalam C++
│   ├── solution.py              # Contoh solusi dalam Python
│   └── testcases.zip            # Paket test case (.in dan .ans)
│
├── T2_Mesin_Ketik_Bu_Sari/
│   ├── README.md
│   ├── solution.cpp
│   ├── solution.py
│   └── testcases.zip
│
└── ... (folder untuk soal lainnya)
```

## Daftar Soal

Berikut adalah daftar soal yang tersedia di repositori ini:

| ID Soal | Judul Soal                    | Topik Utama                                    | Tingkat Kesulitan |
|---------|-------------------------------|------------------------------------------------|-------------------|
| **T0**  | Perpustakaan Bu Ningsih       | Array, String, Searching                       | 4/10 (Sedang)     |
| **T1**  | Toko Pak Budi                 |                                                | 4/10 (Sedang)     |
| **T2**  | Mesin Ketik Bu Sari           | Stack, String Manipulation, Undo               | 6/10 (Menengah)   |
| **T3**  | Antrian Puskesmas Pak Dokter  | Priority Queue (dengan 2 Queue)                | 5/10 (Sedang)     |
| **T4**  | Keluarga Besar Pak RT         | Tree (Pohon), Rekursi, Traversal               | 7/10 (Menengah)   |

---

## Cara Menggunakan

Untuk setiap soal, Anda dapat mengikuti langkah-langkah berikut untuk menguji solusi Anda secara lokal.

### 1. Memahami Soal

Buka folder soal yang ingin dikerjakan (misal, `T2_Mesin_Ketik_Bu_Sari/`). Baca file `README.md` di dalamnya untuk memahami deskripsi masalah, format input/output, dan batasan yang diberikan.

### 2. Menulis Kode Solusi

Buat file solusi Anda sendiri, misalnya `my_solution.cpp` atau `my_solution.py`. Anda juga dapat mempelajari file `solution.cpp` dan `solution.py` yang disediakan sebagai referensi.

### 3. Menguji Kode Secara Lokal (Testing)

Proses pengujian lokal sangat penting untuk memastikan kode Anda sudah benar sebelum di-submit.

#### a. Ekstrak Test Case

Ekstrak file `testcases.zip` yang ada di dalam folder soal. Ini akan menghasilkan beberapa file input (`.in`) dan file jawaban (`.ans`), contohnya:
- `01-sample.in`
- `01-sample.ans`
- `02-edge-case.in`
- `02-edge-case.ans`
- ...dan seterusnya.

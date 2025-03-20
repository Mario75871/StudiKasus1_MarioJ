#include "daftar_mahasiswa.h"

int main() {
    DaftarMahasiswa L1, L2;
    inisialisasiList(&L1);
    inisialisasiList(&L2);

    // Menambahkan Mahasiswa ke L1
    tambahTerurut(&L1, "Budi", 85);
    tambahTerurut(&L1, "Andi", 75);
    tambahTerurut(&L1, "Doni", 90);
    tambahTerurut(&L1, "Cindy", 70);
    tambahTerurut(&L1, "Erika", 95);

    // Menampilkan L1
    tampilkanBerdasarkanNama(L1);
    tampilkanBerdasarkanNilai(L1);
    printf("Jumlah Mahasiswa: %d\n", hitungJumlah(L1));

    // Menyalin data ke L2 jika nilai UTS > 70
    salinDiAtasAmbang(&L1, &L2, 70);
    tampilkanBerdasarkanNama(L2);

    // Menghapus duplikasi nama di L2
    hapusDuplikat(&L2);
    tampilkanBerdasarkanNama(L2);

    // Menghapus L1 dan L2
    hapusSemua(&L1);
    hapusSemua(&L2);

    return 0;
}


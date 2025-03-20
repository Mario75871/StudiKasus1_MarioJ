#include "daftar_mahasiswa.h"

// ?? Inisialisasi Linked List
void inisialisasiList(DaftarMahasiswa* daftar) {
    daftar->kepala = NULL;
}

// ?? Cek apakah list kosong
bool apakahKosong(DaftarMahasiswa daftar) {
    return daftar.kepala == NULL;
}

// ?? Membuat node baru
Mahasiswa* buatNode(char* nama, int nilai_uts) {
    Mahasiswa* nodeBaru = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    if (nodeBaru) {
        strcpy(nodeBaru->nama, nama);
        nodeBaru->nilai_uts = nilai_uts;
        nodeBaru->berikut = NULL;
    }
    return nodeBaru;
}

// ?? Tambah data secara terurut berdasarkan Nama (Ascending)
void tambahTerurut(DaftarMahasiswa* daftar, char* nama, int nilai_uts) {
    Mahasiswa* nodeBaru = buatNode(nama, nilai_uts);
    if (!nodeBaru) return;

    Mahasiswa** ptr = &(daftar->kepala);
    while (*ptr && strcmp((*ptr)->nama, nama) < 0) {
        ptr = &((*ptr)->berikut);
    }
    
    nodeBaru->berikut = *ptr;
    *ptr = nodeBaru;
}

// ?? Tampilkan List berdasarkan Nama (Ascending)
void tampilkanBerdasarkanNama(DaftarMahasiswa daftar) {
    printf("?? Daftar Mahasiswa (Ascending Nama):\n");
    Mahasiswa* temp = daftar.kepala;
    while (temp) {
        printf("- %s, UTS: %d\n", temp->nama, temp->nilai_uts);
        temp = temp->berikut;
    }
}

// ?? Tampilkan List berdasarkan Nilai UTS (Descending)
void tampilkanBerdasarkanNilai(DaftarMahasiswa daftar) {
    printf("?? Daftar Mahasiswa (Descending Nilai UTS):\n");
	int i, j;
    // Simpan ke array untuk sorting
    int jumlah = hitungJumlah(daftar);
    Mahasiswa* array[jumlah];
    Mahasiswa* temp = daftar.kepala;
    for (i = 0; temp; i++, temp = temp->berikut) {
        array[i] = temp;
    }

    // Sorting Descending berdasarkan Nilai UTS
    for (i = 0; i < jumlah - 1; i++) {
        for (j = i + 1; j < jumlah; j++) {
            if (array[i]->nilai_uts < array[j]->nilai_uts) {
                Mahasiswa* tukar = array[i];
                array[i] = array[j];
                array[j] = tukar;
            }
        }
    }

    for (i = 0; i < jumlah; i++) {
        printf("- %s, UTS: %d\n", array[i]->nama, array[i]->nilai_uts);
    }
}

// ?? Menghitung jumlah mahasiswa dalam daftar
int hitungJumlah(DaftarMahasiswa daftar) {
    int jumlah = 0;
    Mahasiswa* temp = daftar.kepala;
    while (temp) {
        jumlah++;
        temp = temp->berikut;
    }
    return jumlah;
}

// ?? Menyalin mahasiswa dengan nilai UTS di atas ambang batas ke daftar lain
void salinDiAtasAmbang(DaftarMahasiswa* daftar_asal, DaftarMahasiswa* daftar_tujuan, int ambang) {
    Mahasiswa* temp = daftar_asal->kepala;
    while (temp) {
        if (temp->nilai_uts > ambang) {
            tambahTerurut(daftar_tujuan, temp->nama, temp->nilai_uts);
        }
        temp = temp->berikut;
    }
}

// ?? Menghapus nama yang duplikat dalam daftar
void hapusDuplikat(DaftarMahasiswa* daftar) {
    Mahasiswa* temp = daftar->kepala;
    while (temp && temp->berikut) {
        if (strcmp(temp->nama, temp->berikut->nama) == 0) {
            Mahasiswa* duplikat = temp->berikut;
            temp->berikut = duplikat->berikut;
            free(duplikat);
        } else {
            temp = temp->berikut;
        }
    }
}

// ?? Menghapus semua elemen dalam daftar
void hapusSemua(DaftarMahasiswa* daftar) {
    Mahasiswa* temp;
    while (daftar->kepala) {
        temp = daftar->kepala;
        daftar->kepala = daftar->kepala->berikut;
        free(temp);
    }
    printf("? Daftar Mahasiswa berhasil dihapus!\n");
}


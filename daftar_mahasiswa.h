#ifndef DAFTAR_MAHASISWA_H
#define DAFTAR_MAHASISWA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struktur Node Mahasiswa
typedef struct Mahasiswa {
    char nama[50];
    int nilai_uts;
    struct Mahasiswa* berikut;
} Mahasiswa;

// Struktur Linked List Mahasiswa
typedef struct {
    Mahasiswa* kepala;
} DaftarMahasiswa;

// Inisialisasi List
void inisialisasiList(DaftarMahasiswa* daftar);
bool apakahKosong(DaftarMahasiswa daftar);

// Operasi Linked List
Mahasiswa* buatNode(char* nama, int nilai_uts);
void tambahTerurut(DaftarMahasiswa* daftar, char* nama, int nilai_uts);
void tampilkanBerdasarkanNama(DaftarMahasiswa daftar);
void tampilkanBerdasarkanNilai(DaftarMahasiswa daftar);
int hitungJumlah(DaftarMahasiswa daftar);
void salinDiAtasAmbang(DaftarMahasiswa* daftar_asal, DaftarMahasiswa* daftar_tujuan, int ambang);
void hapusDuplikat(DaftarMahasiswa* daftar);
void hapusSemua(DaftarMahasiswa* daftar);

#endif


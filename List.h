#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struktur dasar untuk sebuah node dalam linked list
typedef int ElementType;
typedef struct Node *NodePtr;
typedef struct Node {
    ElementType data;
    NodePtr next;
} Node;

// Struktur utama untuk Linked List
typedef struct {
    NodePtr head;
} LinkedList;

// Inisialisasi list kosong
void initList(LinkedList *list);

// Cek apakah list kosong
bool isListEmpty(LinkedList list);

// Alokasi node baru
NodePtr createNode(ElementType value);

// Operasi Insert
void insertFirst(LinkedList *list, ElementType value);
void insertLast(LinkedList *list, ElementType value);
void insertAfter(LinkedList *list, ElementType value, ElementType afterValue);

// Operasi Delete
void deleteFirst(LinkedList *list);
void deleteLast(LinkedList *list);
void deleteValue(LinkedList *list, ElementType value);
void deleteSemuaGanjil(LinkedList *list);

// Utility
void printList(LinkedList list);

#endif


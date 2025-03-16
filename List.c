#include "list.h"

// Inisialisasi linked list kosong
void initList(LinkedList *list) {
    list->head = NULL;
}

// Mengecek apakah list kosong
bool isListEmpty(LinkedList list) {
    return list.head == NULL;
}

// Membuat node baru
NodePtr createNode(ElementType value) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = value;
        newNode->next = NULL;
    } else {
        printf("ERROR: Gagal mengalokasikan memori!\n");
    }
    return newNode;
}

// Menambahkan elemen di awal list
void insertFirst(LinkedList *list, ElementType value) {
    NodePtr newNode = createNode(value);
    if (!newNode) return;

    newNode->next = list->head;
    list->head = newNode;
    
    printList(*list);
}

// Menambahkan elemen di akhir list
void insertLast(LinkedList *list, ElementType value) {
    NodePtr newNode = createNode(value);
    if (!newNode) return;

    if (isListEmpty(*list)) {
        list->head = newNode;
    } else {
        NodePtr temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printList(*list);
}

// Menyisipkan elemen setelah nilai tertentu
void insertAfter(LinkedList *list, ElementType value, ElementType afterValue) {
    NodePtr newNode = createNode(value);
    if (!newNode) return;

    NodePtr temp = list->head;
    while (temp != NULL && temp->data != afterValue) {
        temp = temp->next;
    }

    if (temp) {
        newNode->next = temp->next;
        temp->next = newNode;
        printList(*list);
    } else {
        printf("Elemen %d tidak ditemukan!\n", afterValue);
        free(newNode);
    }
}

// Menghapus elemen pertama
void deleteFirst(LinkedList *list) {
    if (isListEmpty(*list)) {
        printf("ERROR: List sudah kosong!\n");
        return;
    }
    
    NodePtr temp = list->head;
    list->head = list->head->next;
    free(temp);

    printList(*list);
}

// Menghapus elemen terakhir
void deleteLast(LinkedList *list) {
    if (isListEmpty(*list)) {
        printf("ERROR: List sudah kosong!\n");
        return;
    }

    NodePtr temp = list->head, prev = NULL;

    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        list->head = NULL;
    } else {
        prev->next = NULL;
    }

    free(temp);
    printList(*list);
}

// Menghapus elemen berdasarkan nilai
void deleteValue(LinkedList *list, ElementType value) {
    if (isListEmpty(*list)) {
        printf("ERROR: List kosong!\n");
        return;
    }

    NodePtr temp = list->head, prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp) {
        if (prev == NULL) {
            list->head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
        printList(*list);
    } else {
        printf("ERROR: Elemen %d tidak ditemukan!\n", value);
    }
}


void deleteAll(LinkedList *list) {
    NodePtr temp;
    while (list->head) {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    printList(*list);
}

// Mencetak isi list
void printList(LinkedList list) {
    NodePtr temp = list.head;
    printf("Linked List: ");
    printf("{");
    while (temp) {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("NULL}\n");
}


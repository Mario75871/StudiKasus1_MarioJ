#include "list.h"

int main() {
    LinkedList list;
    initList(&list);

	printf("\nMenambah elemen:\n");
    printf("Soal No 1 : ");
    insertFirst(&list, 7);    
	printf("\nSoal No 2 : ");   
    insertLast(&list, 11);       
    printf("\nSoal No 3 : ");
	insertAfter(&list, 2, 7);
	printf("\nSoal No 4 : ");    
    insertFirst(&list, 5);
	printf("\nSoal No 5 : ");       
    insertLast(&list, 13);       

    printf("\nMenghapus elemen:\n");
    printf("\nSoal No 6 : ");
    deleteLast(&list);
	printf("\nSoal No 7 : ");       
    deleteValue(&list, 7);
	printf("\nSoal No 8 : ");   
    deleteFirst(&list);      

    printf("\nMenghapus semua bilangan :\n");
    printf("\nSoal No 9 : ");   
	
	deleteAll(&list);

    return 0;
}


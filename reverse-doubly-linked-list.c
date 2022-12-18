#include <stdio.h>
#include <stdlib.h>

//Alihan Demirdas
//20010011054
//Ödev No: 2 Cift Yonlu Bagli Liste Ters Çevirme

typedef struct node {
    int data;
    struct node * next;
    struct node * prev;
}liste;

liste * start1 = NULL;
liste * start2 = NULL;
liste * temp1 = NULL;
liste * temp2 = NULL;

void olustur(int adet){

    for(int i=0; i<adet; i++){

        liste * list1 = (liste *)malloc(sizeof(liste));
        list1->data = (i+1)*2; //rand() % 100 ile 0 100 arasý random sayýlar da üretilebilir.
        if(start1 == NULL){
            start1 = list1;
            start1->next = NULL;
            start1->prev = NULL;
        }
        else{
            liste * iter = start1;
            while(iter->next != NULL){
                iter = iter->next;
            }
            iter->next = list1;
            list1->prev = iter;
            list1->next = NULL;
        }

        liste * list2 = (liste *)malloc(sizeof(liste));
        list2->data = (i+4)*5;//rand() % 100 ile 0 100 arasý random sayýlar da üretilebilir.
        if(start2 == NULL){
            start2 = list2;
            start2->next = NULL;
            start2->prev = NULL;
        }
        else{
            liste * iter = start2;
            while(iter->next != NULL){
                iter = iter->next;
            }
            iter->next = list2;
            list2->prev = iter;
            list2->next = NULL;
        }
    }
}

void tersCevir()
{
    liste * temp = NULL;

    while (start1 != NULL) {
        temp = start1->prev;
        start1->prev = start1->next;
        start1->next = temp;
        start1 = start1->prev;
    }

    if (temp != NULL)
        start1 = temp->prev;

    liste * iter = start1;

    printf("Birinci Listede Tersine Cevrilmis Hali: \n");
    while(iter->next != NULL){
        printf("(Deger: %d Adres:%d) -> ",iter->data,iter);
        iter = iter->next;
    }
    printf("(Deger: %d Adres:%d) ",iter->data,iter);

    printf("\n\n");
}

void tekliste(){

    liste * iter1 = start1;
    liste * iter2 = start2;
    liste * iter3 = start2;
    liste * temp1;
    liste * temp2;

    while(iter1->next != NULL){
        temp1 = iter1->next;
        temp2 = iter2->next;
        iter1->next = iter2;
        iter2->prev = iter1;
        iter2->next = temp1;
        temp1->prev = iter2;
        iter1 = temp1;
        iter2 = temp2;
    }

    iter1->next = iter2;
    iter2->prev = iter1;
    iter2->next = NULL;
    iter1 = start1;

    printf("Birinci Listede Birlestirilmis Hali: \n");
    while(iter1->next != NULL){
        printf("(Deger: %d Adres:%d) -> ",iter1->data,iter1);
        iter1 = iter1->next;
    }
    printf("(Deger: %d Adres:%d) ",iter1->data,iter1);
    printf("\n\n");

}

void listele(){
    liste * iter = start1;
    liste * iter2 = start2;

    printf("Birinci Liste: \n");
    while(iter->next != NULL){
        printf("(Deger: %d Adres:%d) -> ",iter->data,iter);
        iter = iter->next;
    }
    printf("(Deger: %d Adres:%d) ",iter->data,iter);

    printf("\n\n");

    printf("Ikinci Liste: \n");
    while(iter2->next != NULL){
        printf("(Deger: %d Adres:%d) -> ",iter2->data,iter2);
        iter2 = iter2->next;
    }
    printf("(Deger: %d Adres:%d) ",iter2->data,iter2);

    printf("\n\n");

}


int main()
{
    int sayi;
    printf("Listelerin boyutunu giriniz:");
    scanf("%d",&sayi);
    printf("\n\n");
    olustur(sayi);
    listele();
    tekliste();
    tersCevir();

    return 1;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct dugum
{
    int data;
    struct dugum *next;
} node;

node * start = NULL;

node * olustur(int data)
{
    node * eklenecek = (node *) malloc(sizeof(node));
    eklenecek->data = data;
    eklenecek->next = NULL;
    return eklenecek;
}

void basaEkle(int data)
{
    node * ekle = olustur(data);

    if(start == NULL)
    {
        start = ekle;
    }
    else
    {
        node * temp = start;
        start = ekle;
        ekle->next = temp;
    }
}

void arayaEkle(int data, int position)
{
    node * ekle = olustur(data);

    if(start == NULL)
    {
        printf("Bu listede hic eleman yok, bu yuzden basa ekleniyor. Devam etmek icin bir tusa tikla.\n");
        getch();
        basaEkle(data);
        return;
    }

    if(position == 0)
    {
        basaEkle(data);
        return;
    }

    else
    {
        node * temp = start;
        int kontrol = 0;
        int sayac = 0;

        while(temp != NULL)
        {
            if(sayac == position-1)
            {
                kontrol = 1;
                break;
            }
            temp = temp->next;
            sayac++;
        }
        if(kontrol == 0)
        {
            printf("Belirttiginiz pozisyon bulunmuyor, bu yuzden sona ekleme yapilacak.\n");
            getch();
            sonaEkle(data);
            return;
        }

        if(temp->next == NULL)
        {
            sonaEkle(data);
            return;
        }

        node * tempNext = temp->next;
        temp->next = ekle;
        ekle->next = tempNext;
    }
}

void sonaEkle(int data)
{
    node * ekle = olustur(data);
    if(start == NULL)
    {
        start = ekle;
    }
    else
    {
        node * temp = start;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ekle;
    }
}

void bastanSil()
{
    if(start == NULL)
    {
        printf("Bu listede hic eleman yok, menuye gitmek icin bir tusa tiklayin.\n");
        getch();
        return;
    }
    else
    {
        node * temp = start->next;
        free(start);
        start = temp;
    }
}

void sondanSil()
{
    if(start == NULL)
    {
        printf("Bu listede hic eleman yok, menuye gitmek icin bir tusa tiklayin.\n");
        getch();
        return;
    }
    else
    {
        node * temp = start;

        if(temp->next == NULL)
        {
            free(temp);
            start = NULL;
            return;
        }

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void silWithData(int data)
{
    if(start == NULL)
    {
        printf("Bu listede hic eleman yok, menuye gitmek icin bir tusa tiklayin.\n");
        getch();
        return;
    }
    else
    {
        node * temp = start;
        node * temp2;
        int kontrol = 0;

        if(temp->data == data)
        {
            bastanSil(data);
            return;
        }

        while(temp->next->next != NULL)
        {
            if(temp->next->data == data)
            {
                temp2 = temp->next->next;
                free(temp->next);
                temp->next = temp2;
                kontrol++;
                return;
            }
            temp = temp->next;
        }

        if(temp->next->data == data)
            {
                temp2 = temp->next->next;
                free(temp->next);
                temp->next = temp2;
                kontrol++;
                return;
            }

        printf("Silmek istediginiz data listede bulunmuyor.\n");
        getch();
        return;
    }
}

void menu()
{
    printf("1) Basa Ekle\n2) Araya Ekle\n3) Sona Ekle\n4) Bastan Sil\n5) Sondan Sil\n6) Veriye Gore Sil\n");
    printf("Yapmak istediginiz islemi seciniz -> ");
}

void listele()
{
    node * temp = start;

    if(temp == NULL)
    {
        printf("Henuz liste bos!\n\n");
        return;
    }

    while(temp != NULL)
    {
        if(temp->next == NULL)
        {
            printf("%d", temp->data);
            break;
        }
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int main()
{
    while(1==1)
    {
        system("cls");
        int secim,data,position;
        listele();
        menu();
        scanf("%d",&secim);
        switch(secim)
        {
        case 1:
            printf("\nEklemek istediginiz sayiyi giriniz: ");
            scanf("%d",&data);
            basaEkle(data);
            break;
        case 2:
            printf("\nEklemek istediginiz sayiyi giriniz: ");
            scanf("%d",&data);
            printf("\nEklemek istediginiz pozisyonu giriniz: ");
            scanf("%d",&position);
            arayaEkle(data,position);
            break;
        case 3:
            printf("\nEklemek istediginiz sayiyi giriniz: ");
            scanf("%d",&data);
            sonaEkle(data);
            break;
        case 4:
            bastanSil();
            break;
        case 5:
            sondanSil();
            break;
        case 6:
            printf("\nSilmek istediginiz sayiyi giriniz: ");
            scanf("%d",&data);
            silWithData(data);
            break;
        default:
            printf("Hatali secim yaptiniz, tekrar denemek icin herhangi bir tusa tiklayin!");
            getch();
            break;
        }

    }
}

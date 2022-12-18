#include <stdio.h>
#include <stdlib.h>

//Alihan Demirdaþ
//20010011054

typedef struct dugum
{
    int data;
    struct dugum * left;
    struct dugum * right;
} node;

node * rootEkleme(int data)
{
    node * root = (node*)malloc(sizeof(node*));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

node * ekleme(node * root,int data)
{
    if(root==NULL)
    {
        root = rootEkleme(data);
    }
    else
    {
        if(data< root->data)
        {
            root->left = ekleme(root->left,data);
        }
        else
        {
            root->right = ekleme(root->right,data);
        }
    }
    return root;
}

int buyukVeri(node * root)
{
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int kucukVeri(node * root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

node * silme(node * root, int sayi)
{
    node * temp = root;
    if(root == NULL)
    {
        return root;
    }
    if (root->data == sayi)
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        if(root->right != NULL)
        {
            root->data = kucukVeri(root->right);
            root->right = silme(root->right, kucukVeri(root->right));
            return root;
        }
        root->data = buyukVeri(root->left);
        root->left = silme(root->left, buyukVeri(root->left));
        return root;
    }
    if(root->data > sayi)
    {
        root->left = silme(root->left, sayi);
        return root;
    }
    root->right = silme(root->right,sayi);

    if(root == temp){
        printf("\n%d sayisi bulunamadi. Devam etmek icin herhangi bir tusa tiklayiniz.",sayi);
        getch();
    }

    return root;
}

int yukseklikBul(node * root)
{
    int left,right;
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        left = yukseklikBul(root->left);
        right = yukseklikBul(root->right);
    }
    if(left>right)
    {
        return left+1;
    }
    else
    {
        return right+1;
    }


}

void inorderSirala(node * root)
{
    if(root!=NULL)
    {
        inorderSirala(root->left);
        printf("%d ",root->data);
        inorderSirala(root->right);
    }
}

int toplamNode(node * root)
{
    if (root == NULL)
        return 0;
    return (1 + toplamNode(root->left) + toplamNode(root->right));
}

int kontrolFBST(node * root)
{
    if (root == NULL)
        return 1;

    if (root->left == NULL && root->right == NULL)
        return 1;

    if ((root->left) && (root->right))
        return (kontrolFBST(root->left) && kontrolFBST(root->right));

    return 0;
}

int kontrolCBST(node * root, int index, int sayi)
{
    if (root == NULL)
        return 1;

    if (index >= sayi)
        return 0;

    return (kontrolCBST(root->left, 2*index + 1, sayi) && kontrolCBST(root->right, 2*index + 2, sayi));
}

int main()
{
    node * root = NULL;
    int secim,sayi,deger;
    while(1==1)
    {
        system("cls");
        inorderSirala(root);
        printf("\n\n1- Ekleme\n2- Silme\n3- Inorder Siralama\n4- Yukseklik Bulma\n5- Full Binary Kontrol Et\n6- Complete Binary Kontrol Et\nSeciminiz: ");
        scanf("%d",&secim);
        switch(secim)
        {
        case 1:
            printf("\nEklenecek Sayi Giriniz: ");
            scanf("%d",&sayi);
            root=ekleme(root,sayi);
            break;
        case 2:
            printf("\nSilinecek Sayi Giriniz: ");
            scanf("%d",&sayi);
            root=silme(root,sayi);
            break;
        case 3:
            inorderSirala(root);
            printf("\nDevam etmek icin herhangi bir tusa tiklayiniz");
            getch();
            break;
        case 4:
            deger = yukseklikBul(root);
            printf("\nBST Yuksekligi: %d",deger-1);
            printf("\nDevam etmek icin herhangi bir tusa tiklayiniz");
            getch();
            break;
        case 5:
            if(kontrolFBST(root) == 1)
                printf("\nFull BST'dir.");
            else
                printf("\nFull BST Degildir.");
            printf("\nDevam etmek icin herhangi bir tusa tiklayiniz");
            getch();
            break;
        case 6:
            if(kontrolCBST(root,0,toplamNode(root)) == 1)
                printf("\nComplete BST'dir.");
            else
                printf("\nComplete BST Degildir.");
            printf("\nDevam etmek icin herhangi bir tusa tiklayiniz");
            getch();
            break;
        default:
            printf("Hatali tuslama yaptiniz! Yeniden deneyiniz.");
            printf("\nDevam etmek icin herhangi bir tusa tiklayiniz");
            getch();
            break;

        }

    }

}

#include <stdio.h>
#include <stdlib.h>
struct dugum {
    int icerik;
    struct dugum *ileri;
};

/* 2016 vize 4.soru
Bir listenin buyukten kucuge sirali olup olmadigini bulan fonksiyonun kodlarini yaziniz.
Buyukten kucuge sirali ise 1 , degil ise 0 degerini geriye dondurecek. Liste yapisi veriliyor,
kodlari bu yapiya uygun yazmaniz gerekiyor. Bem cozumumde yukaridaki tanimlamayi kullanacagim.
*/

int sirali_mi (struct dugum* liste_basi){
    while (liste_basi->ileri != NULL) {
        if (liste_basi->icerik < liste_basi->ileri->icerik)
            return 0;
        liste_basi=liste_basi->ileri;
    }
    return 1;
}

/// test islemi icin eklenen fonksiyonlar : liste_basina_ekle , liste_yazdir

void liste_basina_ekle (struct dugum **liste_basi, int icerik) {
    struct dugum* newnode = (struct dugum*)malloc(sizeof(struct dugum)); //init
    struct dugum* iter = *liste_basi;
    newnode->icerik=icerik;
    newnode->ileri=NULL;

    if(*liste_basi==NULL){
        *liste_basi=newnode;
    }
    else {
        newnode->ileri = *liste_basi;
        *liste_basi=newnode;
    }
}

void liste_yazdir (struct dugum *r) {
    while (r != NULL){
        printf("%d ",r->icerik);
        r=r->ileri;
    }
}
int main()
{
    struct dugum *root=NULL;

    liste_basina_ekle(&root,1);
    liste_basina_ekle(&root,2);
    liste_basina_ekle(&root,3);
    liste_basina_ekle(&root,4);
    liste_yazdir(root);
    printf("\n");
    printf("%d ",sirali_mi(root)); // prints 1

    return 0;
}

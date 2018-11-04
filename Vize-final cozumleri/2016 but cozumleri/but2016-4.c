#include <stdio.h>
#include <stdlib.h>
struct dugum {
    int icerik;
    struct dugum *sol;
    struct dugum *sag;
};

/* 2016 but 3.soru
Dugum tanimlamasi yukaridaki gibi olan bir ikli arama agacta, verilen iki dugumun kardes olup
olmadigini bulan tanimlamasi asagidaki gibi olan alt fonksiyonu yaziniz? Not: Eger dugumler kardes ise
fonksiyon geriye 1 , aksi halde 0 dondurmelidir . */

int kardes_mi (struct dugum *kok , struct dugum *dugum1, struct dugum *dugum2){

    if ((kok->sag==dugum1 && kok->sol == dugum2)||(kok->sol==dugum1 && kok->sag == dugum2))
        return 1;
    if (kok->sag == NULL || kok->sol == NULL)
        return 0;
    if (dugum1->icerik > kok->icerik)
        kardes_mi(kok->sag,dugum1,dugum2);
    else
        kardes_mi(kok->sol,dugum1,dugum2);
}

/// test islemi icin eklenen fonksiyon : ekle
void agacaEkle (struct dugum **r, int eklenecek) {
    struct dugum* iter = *r;
    struct dugum* iterGeriden = *r;
    struct dugum* newnode = (struct dugum*)malloc(sizeof(struct dugum));
    newnode->icerik=eklenecek; newnode->sag= NULL ; newnode->sol=NULL ;

    if (*r==NULL){
        *r = newnode;
        return;
    }
    while (iter!=NULL){
        iterGeriden=iter;
        if (eklenecek < iter->icerik)
            iter=iter->sol;
        else if (eklenecek > iter->icerik)
            iter=iter->sag;
        else
            return;
    }
    if (eklenecek < iterGeriden->icerik )
        iterGeriden->sol=newnode;
    else
        iterGeriden->sag=newnode;
}

int main()
{
    struct dugum *root=NULL;

    agacaEkle(&root,20);
    agacaEkle(&root,10);
    agacaEkle(&root,30);
    agacaEkle(&root,5);

    printf("%d ",kardes_mi(root,root->sol , root->sag));  // prints 1
    printf("%d ",kardes_mi(root,root->sol , root->sol->sol)); // prints 0

    return 0;
}

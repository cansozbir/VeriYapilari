#include <stdio.h>
#include <stdlib.h>
struct dugum {
    int anahtar;
    struct dugum *sol;
    struct dugum *sag;
};

/* 2015 vize 3.soru
Dugum tanimlamasi yukaridaki gibi olan bir ikili agac dusunelim.Buna gore, ikili bir agactaki dugumun koke olan uzakligini hesaplayan ve tanimlamasi asagida verilen fonksiyonu yaziniz

Not: Dugumun agacta var oldugunu varsayiniz ve uzakligin kokten dugume olan yol uzerindeki dugum sayisi oldugunu kabul ediniz.
 */

 int koke_uzaklik (struct dugum* kok, struct dugum* a) {
    int count = 0;
    while (kok != a) {
        if (a->anahtar < kok->anahtar)
            kok=kok->sol;
        else
            kok=kok->sag;
        count++;
    }
    return count;


 }

/// test islemi icin eklenen fonksiyon : ekle
void agacaEkle (struct dugum **r, int eklenecek) {
    struct dugum* iter = *r;
    struct dugum* iterGeriden = *r;
    struct dugum* newnode = (struct dugum*)malloc(sizeof(struct dugum));
    newnode->anahtar=eklenecek; newnode->sag= NULL ; newnode->sol=NULL ;

    if (*r==NULL){
        *r = newnode;
        return;
    }
    while (iter!=NULL){
        iterGeriden=iter;
        if (eklenecek < iter->anahtar)
            iter=iter->sol;
        else if (eklenecek > iter->anahtar)
            iter=iter->sag;
        else
            return;
    }
    if (eklenecek < iterGeriden->anahtar )
        iterGeriden->sol=newnode;
    else
        iterGeriden->sag=newnode;
}

int main()
{
    struct dugum *root=NULL;

    agacaEkle(&root,90);
    agacaEkle(&root,70);
    agacaEkle(&root,150);
    agacaEkle(&root,100);
    agacaEkle(&root,180);
    agacaEkle(&root,250);

    printf("%d",koke_uzaklik(root,root->sag->sag->sag));

    return 0;
}

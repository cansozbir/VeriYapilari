#include <stdio.h>
#include <stdlib.h>
struct dugum {
    int icerik;
    struct dugum *sol;
    struct dugum *sag;
};

/* 2016 but 1.soru
Bir agacin ikili agac olup olmadigini bulan fonksiyonuz yaziniz. Ikili agac ise 1 ,
degil ise 0 degerini dondurecek.
*/

int ikili_agacmi (struct dugum* kok) {
    if (kok==NULL)
        return 1;

    if (kok->sol != NULL && (kok->sol->icerik) > (kok->icerik) ||
        kok->sag !=NULL && (kok->sag->icerik) < (kok->icerik))
         return 0;
    ikili_agacmi(kok->sol);
    ikili_agacmi(kok->sag);

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

    printf("%d",ikili_agacmi(root));  // prints 1


    return 0;
}

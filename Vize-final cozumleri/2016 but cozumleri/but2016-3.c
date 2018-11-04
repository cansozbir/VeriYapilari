#include <stdio.h>
#include <stdlib.h>
struct dugum {
    int icerik;
    struct dugum *ileri;
};

/* 2016 but 3.soru
Listenin sonunu listenin basi yapan fonksiyonu yaziniz.

*/

void sonu_bas_yap (struct hucre **liste) {
    struct dugum *iter= *liste;
    if (iter==NULL)
        return;
    if (iter->ileri == NULL)
        return;
    while (iter->ileri->ileri != NULL)
        iter=iter->ileri;
    iter->ileri->ileri = *liste;
    *liste =iter->ileri;
    iter->ileri = NULL;

}

/// test islemi icin eklenen fonksiyonlar:sirali_listeye_ekle, liste_yazdir
void liste_yazdir (struct dugum *r) {
    while (r != NULL){
        printf("%d ",r->icerik);
        r=r->ileri;
    }
    printf("\n");
}
void sirali_listeye_ekle (struct dugum **liste_basi, int icerik) {
    struct dugum* newnode = (struct dugum*)malloc(sizeof(struct dugum)); //init
    struct dugum* iter = *liste_basi;
    newnode->icerik=icerik;
    newnode->ileri=NULL;

    if(*liste_basi==NULL){
        *liste_basi=newnode;
    }
    else if (icerik < (*liste_basi)->icerik){
        newnode->ileri = *liste_basi;
        *liste_basi=newnode;
    }
    else {
        while (iter->ileri != NULL && iter->ileri->icerik < icerik)
            iter=iter->ileri;
        if (iter->ileri !=NULL && iter->ileri->icerik == icerik) // ayni degeri ikinci kere eklemeni engelliyor
            return;                                             // eger iter son node a kadar geldiyse eklenecek sayi diger hepsinden buyuk demek
        newnode->ileri = iter->ileri;
        iter->ileri=newnode;
    }
}
int main()
{
    struct dugum *root=NULL;
    sirali_listeye_ekle(&root,1);
    sirali_listeye_ekle(&root,2);
    sirali_listeye_ekle(&root,3);
    sirali_listeye_ekle(&root,4);
    sirali_listeye_ekle(&root,5);
    liste_yazdir(root);
    sonu_bas_yap(&root);
    liste_yazdir(root);
    return 0;
}

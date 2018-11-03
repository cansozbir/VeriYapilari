#include <stdio.h>
#include <stdlib.h>
struct dugum {
    int icerik;
    struct dugum *ileri;
};

/* 2017 vize 2.soru
Dugum tanimlamasi yukaridaki gibi olan bir sirali listeye eleman ekleyen ve tanimlamasi asagida verilen fonksiyonu yaziniz?
Not: Eger eklenmeye calisilan deger listede varsa bu deger listeye yeniden eklenmemelidir
Ekleme Islemini de sirayi bozmamasini istedigini varsayarak cozumu yapiyorum
*/

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


/// test islemi icin eklenen fonksiyon : liste_yazdir
void liste_yazdir (struct dugum *r) {
    while (r != NULL){
        printf("%d ",r->icerik);
        r=r->ileri;
    }
}
int main()
{
    struct dugum *root=NULL;
    sirali_listeye_ekle(&root,10);
    sirali_listeye_ekle(&root,2);
    sirali_listeye_ekle(&root,50);
    sirali_listeye_ekle(&root,50);

    liste_yazdir(root);

    return 0;
}

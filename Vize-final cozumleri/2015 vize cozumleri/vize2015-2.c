#include <stdio.h>
#include <stdlib.h>
struct dugum {
    int icerik;
    struct dugum *sonraki;
};

/* 2015 vize 2.soru
Dugum yapisi yukaridaki gibi verilen bir bagli listede pozitif tamsayilar tutulmaktadir
(dugumlerin icerik alanlari pozitif tamsayilar saklamaktadir). Buna gore kac tane dugumun icerik kisminin
cift , kac tane icerik kisminin tek oldugunu bulan ve tanimlamasi asagida yapilan foksiyonu yaziniz
*/

void cift_tek_say(struct dugum* liste_basi,int *ciflerin_sayisi, int* teklerin_sayisi) {
    *ciflerin_sayisi=0;
    *teklerin_sayisi=0;
    while (liste_basi != NULL) {

        if ((liste_basi->icerik)%2==0)
            (*ciflerin_sayisi)++;              // parantezleri koymazsan calismaz !  ++ daha yuksek oncelikli
        else
            (*teklerin_sayisi)++;
        liste_basi=liste_basi->sonraki;
    }


}
// test icin eklenen fonksiyonlar : listeyeSiraliEkle
void sirali_listeye_ekle (struct dugum **liste_basi, int icerik) {
    struct dugum* newnode = (struct dugum*)malloc(sizeof(struct dugum)); //init
    struct dugum* iter = *liste_basi;
    newnode->icerik=icerik;
    newnode->sonraki=NULL;

    if(*liste_basi==NULL){
        *liste_basi=newnode;
    }
    else if (icerik < (*liste_basi)->icerik){
        newnode->sonraki = *liste_basi;
        *liste_basi=newnode;
    }
    else {
        while (iter->sonraki != NULL && iter->sonraki->icerik < icerik)
            iter=iter->sonraki;
        if (iter->sonraki !=NULL && iter->sonraki->icerik == icerik) // ayni degeri ikinci kere eklemeni engelliyor
            return;                                             // eger iter son node a kadar geldiyse eklenecek sayi diger hepsinden buyuk demek
        newnode->sonraki = iter->sonraki;
        iter->sonraki=newnode;
    }
}
int main () {
    int tek ;
    int cift ;
    struct dugum* root= NULL;
    sirali_listeye_ekle(&root,3);
    sirali_listeye_ekle(&root,2);
    sirali_listeye_ekle(&root,4);
    sirali_listeye_ekle(&root,5);
    sirali_listeye_ekle(&root,6);   //2 adet tek ekledik,3 adet cift
    cift_tek_say(root,&cift,&tek);
    printf("Teklerin sayisi %d\nCiftlerin sayisi %d",tek,cift);

    return 0;
}

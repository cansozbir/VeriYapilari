#include <stdio.h>
#include <stdlib.h>
struct dugum {
    int icerik;
    struct dugum *sol;
    struct dugum *sag;
};

/* 2016 vize 3.soru
Bir ikili arama agacinda bir dugumun kardesini bulan fonksiyon yaziniz.
Eger fonksiyon dugumun kardesi yoksa null degerini , kardesi v arsa kardesini
geri donderecek. Yine bu soruda da hoca ikili agac yapisini veriyor, o parametreleri
goze alarak ikili agacta gezinmelisiniz.
Ben ustteki sekilde tanimlandigini varsayiyorum.
*/

struct dugum* kardesim (struct dugum* root, struct dugum* a) {
    struct dugum* parent=NULL;
    while (root != NULL) {
        if (a->icerik < root->icerik){
            parent=root;
            root=root->sol;
        }
        else if (a->icerik > root->icerik){
            parent = root;
            root=root->sag;
        }
        else
            break;
    }
    if (parent == NULL) // kok un kardesini aramissak null dondursun
        return NULL;
    if (parent->sol==root)
        return parent->sag;
    else
        return parent->sol;
};



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

    printf("%d ",(kardesim(root,root->sol))->icerik);  // 10 un kardesi 30 un icerigini bastirir


    return 0;
}

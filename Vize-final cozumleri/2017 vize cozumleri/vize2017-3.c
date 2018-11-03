#include <stdio.h>
#include <stdlib.h>

/* 2017 soru3
Birim matrisi dinamik olarak olusturan ve tanimlamasi asagidaki gibi olan bir fonksionu yazin?
*/

void dinamik_birim_matris_olustur (int ***matris,int satir_sutun_sayisi){
    *matris = (int**)malloc(sizeof(int*)*satir_sutun_sayisi);
    for (int i=0 ; i<satir_sutun_sayisi ; i++) {
        *(*matris+i) = (int*)malloc(sizeof(int)*satir_sutun_sayisi);
        for (int j=0 ; j<satir_sutun_sayisi ; j++){
            if (i==j)
                *(*(*matris+i)+j)=1;
            else
                *(*(*matris+i)+j)=0;
        }
    }
}
/// test icin yardimci fonksiyon : matrisYazdir

void matrisYazdir (int **A,int satir, int sutun) {
    for (int i=0 ; i<satir ; i++) {
        for (int j=0 ; j<sutun ; j++) {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}


int main () {

int **A;
dinamik_birim_matris_olustur (&A,4);
matrisYazdir(A,4,4);


return 0;
}

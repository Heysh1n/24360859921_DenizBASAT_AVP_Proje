#include <stdio.h>
#include <stdlib.h>

/* Importlar */
#include "src/config.h"
#include "src/utils.h"

int main(void) {
    
    char bilim_insani[MAX_ISIM_UZUNLUK];
    int secim;
    double *g_ptr;
    char **isim_ptr;
    
    baslikGoster();
    
    printf("  Bilim insani adiniz: >> ");
    fgets(bilim_insani, MAX_ISIM_UZUNLUK, stdin);
    yeniSatirKaldir(bilim_insani);
    
    hosgeldinMesaji(bilim_insani);
    
    g_ptr = yercekim;
    isim_ptr = gezegenleri;
    
    /* ANA PROGRAM DÖNGÜSÜ */
    do {
        menuGoster();
        
        printf("  Seciminiz: >> ");
        secim = guvenliSayiAl();  /* <-- Güvenli giriş */
        
        switch (secim) {
            
            case 0:
                serbestDusme(g_ptr, isim_ptr, GEZEGEN_SAYISI);
                break;
                
            case 1:
                yukariAtis(g_ptr, isim_ptr, GEZEGEN_SAYISI);
                break;
                
            case 2:
                agirlik(g_ptr, isim_ptr, GEZEGEN_SAYISI);
                break;
                
            case 3:
                potansiyelEnerji(g_ptr, isim_ptr, GEZEGEN_SAYISI);
                break;
                
            case 4:
                hidrostatikBasinc(g_ptr, isim_ptr, GEZEGEN_SAYISI);
                break;
                
            case 5:
                arsimet(g_ptr, isim_ptr, GEZEGEN_SAYISI);
                break;
                
            case 6:
                basitSarkac(g_ptr, isim_ptr, GEZEGEN_SAYISI);
                break;
                
            case 7:
                ipGerilmesi(g_ptr, isim_ptr, GEZEGEN_SAYISI);
                break;
                
            case 8:
                asansor(g_ptr, isim_ptr, GEZEGEN_SAYISI);
                break;
                
            case -1:
                cikisMesaji(bilim_insani);
                break;
                
            case -9999:
                /* Hatalı giriş (harf, sembol vs.) */
                printf("\n  [!] Hatali giris! Sayi giriniz.\n\n");
                break;
                
            default:
                printf("\n  [!] Gecersiz secim! 0-8 arasi veya -1 girin.\n\n");
                break;
        }
        
    } while (secim != -1);
    
    return 0;
}
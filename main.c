#include <stdio.h>
#include <stdlib.h>

/* Importlar */
#include "src/config.h"
#include "src/utils.h"
 

// ANA FONKSİYON
int main(void) {
    // Değişken tanımları
    char bilim_insani[MAX_ISIM_UZUNLUK];
    int secim;
    double *g_ptr;      /* Yerçekimi dizisi pointer'ı */
    char **isim_ptr;    /* Gezegen isimleri pointer'ı */
    
    baslikGoster();
    
    printf("  Bilim insani adiniz: >> ");
    fgets(bilim_insani, MAX_ISIM_UZUNLUK, stdin);
    yeniSatirKaldir(bilim_insani);
    
    hosgeldinMesaji(bilim_insani);
    
    /*
     * Dizilerin başlangıç adreslerini pointer'lara ata
     * Bu pointer'lar deney fonksiyonlarına parametre olarak geçirilecek
     */
    g_ptr = yercekim;
    isim_ptr = gezegenleri;
    
// ANA PROHRAM
    do {
        /* Menüyü göster */
        menuGoster();
        
        /* Kullanıcı seçimini al */
        printf("  Seciminiz: >> ");
        scanf("%d", &secim);
        
        /* Seçime göre ilgili deneyi çalıştır */
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
                /* Çıkış */
                cikisMesaji(bilim_insani);
                break;
                
            default:
                /* Geçersiz seçim */
                printf("\n  [!] Gecersiz secim! 0-8 arasi veya -1 girin.\n\n");
                break;
        }
        
    } while (secim != -1);
    
    return 0;
}
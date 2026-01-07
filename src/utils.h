/*
 * Utility functions and physics experiment functions
 * 
 * Important rules to follow:
 *   1. Use pointer arithmetic: *(ptr + i) instead of array[i]
 *   2. Use ternary operators for simple conditions
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <math.h>
#include "config.h"

// Helper function to remove trailing newline from user input
static void yeniSatirKaldir(char *str) {
    char *ptr = str;
    
    while (*ptr != '\0') {
        if (*ptr == '\n') {
            *ptr = '\0';
            break;
        }
        ptr++;
    }
}

// Print the header row of a results table
static void tabloBasligi(const char *deney_adi, const char *sonuc_adi) {
    printf("\n");
    printf("  [ %s ]\n", deney_adi);
    printf("  ----------------------------------------------------------\n");
    printf("  | %-12s | %35s |\n", "Gezegen", sonuc_adi);
    printf("  ----------------------------------------------------------\n");
}

// Print a row in the results table with planet name and calculated value
static void tabloSatiri(const char *gezegen, double deger, const char *birim) {
    printf("  | %-12s | %30.4f %-4s |\n", gezegen, deger, birim);
}

// Print the closing line of a results table
static void tabloSonu(void) {
    printf("  ----------------------------------------------------------\n\n");
}

// Experiment 1: Free Fall
// Calculates how far an object falls: h = 0.5 × g × t²
static void serbestDusme(double *g_ptr, char **isim_ptr, int n) {
    double t, h;
    int i;
    
    printf("\n  Zaman (t) giriniz [saniye]: ");
    scanf("%lf", &t);
    
    /* TERNARY: Negatif değeri pozitife çevir */
    t = (t < 0) ? -t : t;
    
    printf("  Girilen deger: %.2f s\n", t);
    
    tabloBasligi("SERBEST DUSME", "Yukseklik (m)");
    
    // Access gravity values using pointer arithmetic
    for (i = 0; i < n; i++) {
        h = 0.5 * (*(g_ptr + i)) * t * t;
        tabloSatiri(*(isim_ptr + i), h, "m");
    }
    
    tabloSonu();
}

// Experiment 2: Vertical Throw
// Calculates maximum height: h_max = v₀² / (2 × g)
static void yukariAtis(double *g_ptr, char **isim_ptr, int n) {
    double v0, h_max;
    int i;
    
    printf("\n  Baslangic hizi (v0) giriniz [m/s]: ");
    scanf("%lf", &v0);
    
    v0 = (v0 < 0) ? -v0 : v0;
    
    printf("  Girilen deger: %.2f m/s\n", v0);
    
    tabloBasligi("YUKARI ATIS", "Max Yukseklik (m)");
    
    for (i = 0; i < n; i++) {
        h_max = (v0 * v0) / (2.0 * (*(g_ptr + i)));
        tabloSatiri(*(isim_ptr + i), h_max, "m");
    }
    
    tabloSonu();
}

// Experiment 3: Weight
// Calculates weight force: G = m × g
static void agirlik(double *g_ptr, char **isim_ptr, int n) {
    double m, G;
    int i;
    
    printf("\n  Kutle (m) giriniz [kg]: ");
    scanf("%lf", &m);
    
    m = (m < 0) ? -m : m;
    
    printf("  Girilen deger: %.2f kg\n", m);
    
    tabloBasligi("AGIRLIK", "Agirlik Kuvveti (N)");
    
    for (i = 0; i < n; i++) {
        G = m * (*(g_ptr + i));
        tabloSatiri(*(isim_ptr + i), G, "N");
    }
    
    tabloSonu();
}

// Experiment 4: Potential Energy
// Calculates gravitational potential energy: Ep = m × g × h
static void potansiyelEnerji(double *g_ptr, char **isim_ptr, int n) {
    double m, h, Ep;
    int i;
    
    printf("\n  Kutle (m) giriniz [kg]: ");
    scanf("%lf", &m);
    
    printf("  Yukseklik (h) giriniz [m]: ");
    scanf("%lf", &h);
    
    m = (m < 0) ? -m : m;
    h = (h < 0) ? -h : h;
    
    printf("  Girilen kutle: %.2f kg, yukseklik: %.2f m\n", m, h);
    
    tabloBasligi("POTANSIYEL ENERJI", "Enerji (J)");
    
    for (i = 0; i < n; i++) {
        Ep = m * (*(g_ptr + i)) * h;
        tabloSatiri(*(isim_ptr + i), Ep, "J");
    }
    
    tabloSonu();
}

// Experiment 5: Hydrostatic Pressure
// Calculates water pressure: P = ρ × g × h
static void hidrostatikBasinc(double *g_ptr, char **isim_ptr, int n) {
    double rho, h, P;
    int i;
    
    printf("\n  Yogunluk (rho) giriniz [kg/m^3]: ");
    scanf("%lf", &rho);
    
    printf("  Derinlik (h) giriniz [m]: ");
    scanf("%lf", &h);
    
    rho = (rho < 0) ? -rho : rho;
    h = (h < 0) ? -h : h;
    
    printf("  Girilen yogunluk: %.2f kg/m^3, derinlik: %.2f m\n", rho, h);
    
    tabloBasligi("HIDROSTATIK BASINC", "Basinc (Pa)");
    
    for (i = 0; i < n; i++) {
        P = rho * (*(g_ptr + i)) * h;
        tabloSatiri(*(isim_ptr + i), P, "Pa");
    }
    
    tabloSonu();
}

// Experiment 6: Archimedes' Force (Buoyancy)
// Calculates the lifting force: Fk = ρ × g × V
static void arsimet(double *g_ptr, char **isim_ptr, int n) {
    double rho, V, Fk;
    int i;
    
    printf("\n  Sivi yogunlugu (rho) giriniz [kg/m^3]: ");
    scanf("%lf", &rho);
    
    printf("  Hacim (V) giriniz [m^3]: ");
    scanf("%lf", &V);
    
    rho = (rho < 0) ? -rho : rho;
    V = (V < 0) ? -V : V;
    
    printf("  Girilen yogunluk: %.2f kg/m^3, hacim: %.6f m^3\n", rho, V);
    
    tabloBasligi("ARSIMET KUVVETI", "Kaldirma Kuvveti (N)");
    
    for (i = 0; i < n; i++) {
        Fk = rho * (*(g_ptr + i)) * V;
        tabloSatiri(*(isim_ptr + i), Fk, "N");
    }
    
    tabloSonu();
}

// Experiment 7: Simple Pendulum
// Calculates oscillation period: T = 2 × π × √(L/g)
static void basitSarkac(double *g_ptr, char **isim_ptr, int n) {
    double L, T;
    int i;
    
    printf("\n  Sarkac uzunlugu (L) giriniz [m]: ");
    scanf("%lf", &L);
    
    L = (L < 0) ? -L : L;
    
    printf("  Girilen deger: %.2f m\n", L);
    
    tabloBasligi("BASIT SARKAC", "Periyot (s)");
    
    for (i = 0; i < n; i++) {
        T = 2.0 * PI * sqrt(L / (*(g_ptr + i)));
        tabloSatiri(*(isim_ptr + i), T, "s");
    }
    
    tabloSonu();
}

// Experiment 8: Rope Tension
// Calculates the tension in a hanging rope: T = m × g
static void ipGerilmesi(double *g_ptr, char **isim_ptr, int n) {
    double m, T;
    int i;
    
    printf("\n  Kutle (m) giriniz [kg]: ");
    scanf("%lf", &m);
    
    m = (m < 0) ? -m : m;
    
    printf("  Girilen deger: %.2f kg\n", m);
    
    tabloBasligi("IP GERILMESI", "Gerilme Kuvveti (N)");
    
    for (i = 0; i < n; i++) {
        T = m * (*(g_ptr + i));
        tabloSatiri(*(isim_ptr + i), T, "N");
    }
    
    tabloSonu();
}

//  Güvenli sayı girişi - hatalı girişte -9999 döner
static void bufferTemizle(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
static int guvenliSayiAl(void) {
    int sayi;
    int sonuc;
    
    sonuc = scanf("%d", &sayi);
    
    /* scanf başarısız olduysa (harf, sembol vs.) */
    if (sonuc != 1) {
        bufferTemizle();
        return -9999;  /* Hata kodu */
    }
    
    return sayi;
}
// Experiment 9: Elevator Physics
// Calculates apparent weight in an accelerating elevator: N = m × (g ± a)
static void asansor(double *g_ptr, char **isim_ptr, int n) {
    double m, a, N;
    int yon, i;
    
    printf("\n  Kutle (m) giriniz [kg]: ");
    scanf("%lf", &m);
    
    printf("  Ivme (a) giriniz [m/s^2]: ");
    scanf("%lf", &a);
    
    m = (m < 0) ? -m : m;
    a = (a < 0) ? -a : a;
    
    printf("\n  Asansor yonu:\n");
    printf("    1 - Yukari ivmeleniyor\n");
    printf("    2 - Asagi ivmeleniyor\n");
    printf("  Seciminiz: ");
    scanf("%d", &yon);
    
    printf("\n  Kutle: %.2f kg, Ivme: %.2f m/s^2\n", m, a);
    printf("  Yon: %s\n", (yon == 1) ? "Yukari" : "Asagi");
    
    tabloBasligi("ASANSOR", "Normal Kuvvet (N)");
    
    for (i = 0; i < n; i++) {
        // Calculate normal force: add acceleration when going up, subtract when going down
        N = (yon == 1) 
            ? m * ((*(g_ptr + i)) + a) 
            : m * ((*(g_ptr + i)) - a);
        tabloSatiri(*(isim_ptr + i), N, "N");
    }
    
    tabloSonu();
}

#endif /* UTILS_H */
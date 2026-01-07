#ifndef PROGRAM_CONFIG_H
#define PROGRAM_CONFIG_H

#include <stdio.h>

// Core constants used for physics calculations
#define PI 3.14159265358979323846
#define GEZEGEN_SAYISI 8
#define MAX_ISIM_UZUNLUK 100

// Gravity values for each planet (m/s²)
// These are used in all the physics experiments
static double yercekim[GEZEGEN_SAYISI] = {
    3.70,   // Mercury
    8.87,   // Venus
    9.81,   // Earth
    3.71,   // Mars
    24.79,  // Jupiter
    10.44,  // Saturn
    8.69,   // Uranus
    11.15   // Neptune
};

// Planet names in our solar system
static char *gezegenleri[GEZEGEN_SAYISI] = {
    "Merkur",
    "Venus",
    "Dunya",
    "Mars",
    "Jupiter",
    "Saturn",
    "Uranus",
    "Neptun"
};

// UI helper functions - display title, menu, and messages to the user

static void baslikGoster(void) {
    printf("\n");
    printf("-- -- -- -- -- -- -- -- -- -- -- -- -- --\n");
    printf("  UZAY FIZIK SIMULASYONU\n");
    printf("  Gunes Sistemi Gezegenleri\n");
    printf("  -- -- -- -- -- -- -- -- -- --\n");
    printf("\n");
}

static void menuGoster(void) {
    printf("-- -- -- -- -- -- -- -- -- -- --\n");
    printf("  DENEY MENUSU\n");
    printf("  -- -- -- -- -- --\n");
    printf("\n");
    printf("  [1] Serbest Dusme       |   h = 0.5*g*t^2\n");
    printf("  [2] Yukari Atis         |   h = v0^2 / 2g\n");
    printf("  [3] Agirlik             |   G = m*g\n");
    printf("  [4] Potansiyel Enerji   |   Ep = m*g*h\n");
    printf("  [5] Hidrostatik Basinc  |   P = rho*g*h\n");
    printf("  [6] Arsimet Kuvveti     |   Fk = rho*g*V\n");
    printf("  [7] Basit Sarkac        |   T = 2*PI*sqrt(L/g)\n");
    printf("  [8] Ip Gerilmesi        |   T = m*g\n");
    printf("  [9] Asansor             |   N = m*(g +/- a)\n");
    printf("\n");
    printf("  [-1] Cikis\n");
    printf("\n");
}

static void hosgeldinMesaji(const char *isim) {
    printf("\n");
    printf("  Hos geldiniz, %s!\n", isim);
    printf("  9 gezegende fizik deneyleri yapabilirsiniz.\n");
    printf("\n");
}

static void cikisMesaji(const char *isim) {
    printf("\n");
    printf("  Gule gule, %s!\n", isim);
    printf("\n");
}

#endif
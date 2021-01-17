#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct punkt {
    float x, y;
};

struct funkcjakwadratowa {
    int a, b, c;
    int delta;
    float x1, x2, x0;
    struct punkt wierzcholek;
};

struct funkcjakwadratowa *wczytajfunkcje();

void wypiszfunkcje(struct funkcjakwadratowa *wypisz);

void delta(struct funkcjakwadratowa *funkcja);

void miejscazerowe(struct funkcjakwadratowa *funkcja);

void wyliczwierzcholek(struct funkcjakwadratowa *funkcja);

int main() {
    struct funkcjakwadratowa *mojafunkcja = wczytajfunkcje();
    delta(mojafunkcja);
    miejscazerowe(mojafunkcja);
    wyliczwierzcholek(mojafunkcja);
    wypiszfunkcje(mojafunkcja);

    return 0;
}

struct funkcjakwadratowa *wczytajfunkcje() {
    struct funkcjakwadratowa *mojafunkcja = (struct funkcjakwadratowa *) malloc(sizeof(struct funkcjakwadratowa));

    printf("Podaj wartosci funkcji a, b, c: ");
    scanf("%d %d %d", &(mojafunkcja->a), &(mojafunkcja->b), &(mojafunkcja->c));

    if (mojafunkcja->a == 0) {
        printf("Wspolczynnik liczbowy 'a' nie moze byc rowny 0");
    } else {
        return mojafunkcja;
    }
}

void wypiszfunkcje(struct funkcjakwadratowa *wypisz) {
    printf("\nf(x) = %dx^2 + %dx + %d\n", wypisz->a, wypisz->b, wypisz->c);
    printf("Delta = %d\n", wypisz->delta);

    if (wypisz->delta > 0) {
        printf("Miejsca zerowe funkcji: x1= %.2f, x2= %.2f\n", wypisz->x1, wypisz->x2);
    } else if (wypisz->delta == 0) {
        printf("Miejsce zerowe funkcji: x0= %.2f\n", wypisz->x0);
    } else if (wypisz->delta < 0) {
        printf("Brak miejsc zerowych\n");
    }
    printf("Wierzcholek = (%.2f; %.2f)", wypisz->wierzcholek.x, wypisz->wierzcholek.y);
}

void delta(struct funkcjakwadratowa *funkcja) {
    int delta = pow(funkcja->b, 2) - 4 * funkcja->a * funkcja->c;
    funkcja->delta = delta;
}

void miejscazerowe(struct funkcjakwadratowa *funkcja) {
    if (funkcja->delta > 0) {
        float pierwiastekdelty = sqrt(funkcja->delta);
        float x1 = (float) (-funkcja->b - pierwiastekdelty) / (2 * funkcja->a);
        float x2 = (float) (-funkcja->b + pierwiastekdelty) / (2 * funkcja->a);
        funkcja->x1 = x1;
        funkcja->x2 = x2;
    } else if (funkcja->delta == 0) {
        float x0 = (float) (-funkcja->b) / (2 * funkcja->a);
        funkcja->x0 = x0;
    }
}

void wyliczwierzcholek(struct funkcjakwadratowa *funkcja) {
    float p = (float) (-funkcja->b) / (2 * funkcja->a);
    float q = (float) (-funkcja->delta) / (4 * funkcja->a);
    funkcja->wierzcholek.x = p;
    funkcja->wierzcholek.y = q;
}

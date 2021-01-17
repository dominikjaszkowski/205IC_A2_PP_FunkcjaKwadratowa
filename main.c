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
    struct punkt *wierzcholek;
};

struct funkcjakwadratowa *wczytajfunkcje();

void wypiszfunkcje(struct funkcjakwadratowa *funkcjadowypisania);

void delta(struct funkcjakwadratowa *funkcjakwadratowa);

void miejscazerowe(struct funkcjakwadratowa *funkcjakwadratowa);

void wyliczwierzcholek(struct funkcjakwadratowa *funkcjakwadratowa);

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

void wypiszfunkcje(struct funkcjakwadratowa *funkcjadowypisania) {
    printf("\nf(x) = %dx^2 + %dx + %d\n", funkcjadowypisania->a, funkcjadowypisania->b, funkcjadowypisania->c);
    printf("Delta = %d\n", funkcjadowypisania->delta);

    if (funkcjadowypisania->delta > 0) {
        printf("Miejsca zerowe funkcji: x1= %.2f, x2= %.2f\n", funkcjadowypisania->x1, funkcjadowypisania->x2);
    } else if (funkcjadowypisania->delta == 0) {
        printf("Miejsce zerowe funkcji: x0= %.2f\n", funkcjadowypisania->x0);
    } else if (funkcjadowypisania->delta < 0) {
        printf("Brak miejsc zerowych\n");
    }
    printf("Wierzcholek = (%.2f, %.2f)", funkcjadowypisania->wierzcholek->x, funkcjadowypisania->wierzcholek->y);
}

void delta(struct funkcjakwadratowa *funkcjakwadratowa) {
    int delta = pow(funkcjakwadratowa->b, 2) - 4 * funkcjakwadratowa->a * funkcjakwadratowa->c;
    funkcjakwadratowa->delta = delta;
}

void miejscazerowe(struct funkcjakwadratowa *funkcjakwadratowa) {
    if (funkcjakwadratowa->delta > 0) {
        float pierwiastekdelty = sqrt(funkcjakwadratowa->delta);
        float x1 = (float) (-funkcjakwadratowa->b - pierwiastekdelty) / (2 * funkcjakwadratowa->a);
        float x2 = (float) (-funkcjakwadratowa->b + pierwiastekdelty) / (2 * funkcjakwadratowa->a);
        funkcjakwadratowa->x1 = x1;
        funkcjakwadratowa->x2 = x2;
    } else if (funkcjakwadratowa->delta == 0) {
        float x0 = (float) (-funkcjakwadratowa->b) / (2 * funkcjakwadratowa->a);
        funkcjakwadratowa->x0 = x0;
    }
}

void wyliczwierzcholek(struct funkcjakwadratowa *funkcjakwadratowa) {
    funkcjakwadratowa->wierzcholek = (struct punkt *) malloc(sizeof(struct punkt));
    float p = (float) (-funkcjakwadratowa->b) / (2 * funkcjakwadratowa->a);
    float q = (float) (-funkcjakwadratowa->delta) / (4 * funkcjakwadratowa->a);
    funkcjakwadratowa->wierzcholek->x = p;
    funkcjakwadratowa->wierzcholek->y = q;
}


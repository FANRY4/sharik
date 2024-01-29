#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Carte {
    char titlu[100];
    char autor[100];
    char ISBN[20];
};

struct Biblioteca {
    struct Carte carti[100];
    int numarCarti;
};

void adaugaCarte(struct Biblioteca *biblioteca, const char *titlu, const char *autor, const char *ISBN) {
    if (biblioteca->numarCarti < 100) { 
        struct Carte carteNoua;
        strcpy(carteNoua.titlu, titlu);
        strcpy(carteNoua.autor, autor);
        strcpy(carteNoua.ISBN, ISBN);

        biblioteca->carti[biblioteca->numarCarti] = carteNoua;
        biblioteca->numarCarti++;

        printf("Cartea \"%s\" a fost adăugată în bibliotecă.\n", titlu);
    } else {
        printf("Biblioteca este plină. Nu se poate adăuga o carte nouă.\n");
    }
}

void eliminaCarte(struct Biblioteca *biblioteca, const char *ISBN) {
    int index = -1;

    for (int i = 0; i < biblioteca->numarCarti; i++) {
        if (strcmp(biblioteca->carti[i].ISBN, ISBN) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < biblioteca->numarCarti - 1; i++) {
            biblioteca->carti[i] = biblioteca->carti[i + 1];
        }
        biblioteca->numarCarti--;

        printf("Cartea cu ISBN-ul %s a fost eliminată din bibliotecă.\n", ISBN);
    } else {
        printf("Cartea cu ISBN-ul %s nu a fost găsită în bibliotecă.\n", ISBN);
    }
}

void afiseazaCarti(struct Biblioteca *biblioteca) {
    printf("Cărțile din bibliotecă:\n");

    for (int i = 0; i < biblioteca->numarCarti; i++) {
        printf("Titlu: %s\n", biblioteca->carti[i].titlu);
        printf("Autor: %s\n", biblioteca->carti[i].autor);
        printf("ISBN: %s\n\n", biblioteca->carti[i].ISBN);
    }
}

int main() {
    struct Biblioteca biblioteca;
    biblioteca.numarCarti = 0;

    adaugaCarte(&biblioteca, "Programarea C", "John Doe", "978-3-16-148410-0");
    adaugaCarte(&biblioteca, "Introducere în OOP", "Jane Smith", "978-1-23-456789-0");

    afiseazaCarti(&biblioteca);

    eliminaCarte(&biblioteca, "978-3-16-148410-0");

    afiseazaCarti(&biblioteca);

    return 0;
}

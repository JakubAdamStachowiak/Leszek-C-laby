#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void error(char *tekst){
    fprintf(stderr, "B³¹d: %s\n", tekst);
    exit(1);
}
int main(int argc, char* argv[]){
    int plik;
    int numerlinijki = 1;
    int liczbaznakow = 0;
    int X = 0;
    int Max = 0;
    char Znak;
    if(argc != 2){
        error("niepoprawna iloœæ argumentow");
    }
    if((plik = open(argv[1], O_RDONLY)) == -1){
        error("b³¹d odczytu pliku");
    }
    while((Znak = fgetc(plik)) != EOF){
        liczbaznakow++;
        if(Znak == '\n'){
            if(liczbaznakow > Max){
                Max = liczbaznakow;
                X = numerlinijki;
            }
            numerlinijki++;
        }
    }
    numerlinijki = 1;
    Znak = 0;
    while((Znak = fgetc(plik)) != EOF){
        if(numerlinijki == X){
            printf("%c", Znak);
        }
        if(Znak == '\n'){
            numerlinijki++;
        }
    }
    if((close(plik)) == -1){
        error("b³¹d zamykania pliku");
    }
    return 0;
}

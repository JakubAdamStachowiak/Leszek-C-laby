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
    if(argc<2){
        error("za malo argumentow");
    }
    int src, dst;

    if((src = open(argv[1], O_RDONLY))<0){
        error("b³¹d przy otwarciu pliku Ÿród³owego");
    }
    if((dst = creat(argv[2], 0664)) < 0){
        error("b³¹d przy otwieraniu pliku docelowego");
    }
    char bufor[1024];
    int byte;
    while((byte = read(src, bufor, 1024)) > 0){
        if(write(dst, bufor, byte) < 0){
            error("b³ad zapisu pliku");
        }
    }
    if(byte < 0){
        error("b³¹d odczytu pliku");
    }
    if((close(src)<0) || (close(dst) < 0)){
        error("b³ad przy zamykaniu plików");
    }
    return 0;
}

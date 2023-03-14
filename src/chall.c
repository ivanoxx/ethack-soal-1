#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);	

    char s[24];
    char *blacklisted[] = {"/bin/sh", "\x0f\x05"};

    printf("> ");
    fgets(s, 24, stdin);

    for (int i = 0; i < 2; i++)
    {
      if (strstr(s, blacklisted[i]) != NULL) {
        printf("Nope.\n");
        exit(0);
      }
    }

    void (*func)() = (void (*)())s;
    func();
    
    return 0;
}


#include <stdio.h>
#include <string.h>

void bitStuff(char *s) {
    int n = strlen(s);
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            c++;
        }
        if (c == 5) {
            for (int j = n; j > i; j--) {
                s[j] = s[j-1];
            }
            s[i+1] = '0';
            n++;
            c = 0;
        }
    }
    s[n] = '\0';
}

int main() {
    char s[100];
    scanf("%s", s);

    bitStuff(s);

    printf("%s\n", s);
    return 0;
}
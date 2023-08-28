#include <stdio.h>
#include <stdlib.h>

int RemoveR(int v[], int i, int q) {
    if (i == q - 1) {
        return q - 1;
    }
    return RemoveR(v, i, q - 1);
}


int main() {
    int v[] = {2, 1, 5, 0, 3, 5, 6, 4, 3};
    int size = sizeof(v) / sizeof(v[0]);
    for (int i = 0; i <= size - 1; i++) {
        printf("%d", v[i]);
        int first = v[0];
        printf("\n");
    }
    RemoveR(v, 2, size);
    printf("Funcao apos a remocao:");
    printf("\n");
    for (int i = 0; i <= size - 2; i++) {
        printf("%d", v[i]);
        printf("\n");
    }

    return 0;
}

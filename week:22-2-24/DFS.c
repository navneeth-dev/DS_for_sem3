#include <stdio.h>
#include <conio.h>  // Note: <conio.h> is not a standard C library header, and its use is non-portable.

int a[20][20], s[20], n;

void dfs(int v) {
    int i;
    s[v] = 1;

    for (i = 1; i <= n; i++)
        if (a[v][i] && !s[i]) {
            printf("\n %d->%d", v, i);
            dfs(i);
        }
}

int main() {
    int i, j, count = 0;

    printf("\nEnter number of vertices:");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        s[i] = 0;
        for (j = 1; j <= n; j++)
            a[i][j] = 0;
    }

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    dfs(1);

    printf("\n");

    for (i = 1; i <= n; i++) {
        if (s[i])
            count++;
    }

    if (count == n)
        printf("Graph is connected");
    else
        printf("Graph is not connected");

    return 0;
}

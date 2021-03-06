#include<algorithm>
#include<iostream>
 
using namespace std;
int arr[52][52];
int x[] = { 1,-1 };
void check(int i, int j,int ch) {
    arr[i][j] = ch;
    for (int k = 0; k < 2; k++) {
        if (arr[i][j + x[k]] == 1) check(i, j + x[k], ch);
         
        if (arr[i + x[k]][j] == 1) check(i + x[k], j, ch);
 
        if (arr[i - x[k]][j] == 1)check(i - x[k], j, ch);
 
        if (arr[i + x[k]][j-x[k]] == 1)check(i + x[k], j-x[k], ch);
 
        if (arr[i + x[k]][j + x[k]] == 1)check(i + x[k], j+x[k], ch);
 
    }
}
 
int main() {
    int n=1, m=1;
    while (1)
    {
        scanf("%d %d", &n, &m);
        if (n == 0 & m == 0)
            break;
 
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        int ch = 2;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] == 1) {
                    ch++;
                    check(i, j, ch);
                }
            }
        }
        printf("%d\n", ch - 2);
 
    }
    return 0;
}
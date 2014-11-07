#include < stdio.h > 
#include < stdlib.h > 
#include < string.h >
#include<bits/stdc++.h>

int main() 
{
	
    int t, i, j, n, dig, flag, k;
    char str[1010], c[100], p[100];
    scanf("%d", & t);
    while (t--) {
        scanf("%d", & n);
        for (i = 1; i <= n; i++) {
            fflush(stdin);
            scanf("%c %c", & c[i], & p[i]);
        }
        
        scanf("%s", str);
        // optimise this part.. TLE may occur
        for (i = 0; i < strlen(str); i++) {
            for (j = 1; j <= n; j++) {
                if (str[i] == c[j]) {
                    str[i] = p[j];
                    break;
                }
            }
        }
        //puts(str);
        flag = 0;
        // decimal part exist
        for (i = 0; i < strlen(str); i++) {
            if (str[i] == '.') {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            k = strlen(str) - 1;
        strrev(str);
        
        //for decimal part
        if (flag == 1)
            for (i = 0; i < strlen(str); i++) {
                if (str[i] != '0') {
                    k = i;
                    if (str[k] == '.')
                        k = k + 1;
                    break;
                }
            }
        strrev(str);
        if (flag == 1)
            k = strlen(str) - k - 1;
        //for integer part
        for (i = 0; i < strlen(str); i++) {
            if (str[i] != '0') {
                j = i;
                break;
            }
            if (str[i] == '.') {
                j = i - 1;
                if (str[j] == '0')
                    j = i;
                break;
            }
        }
        if (j > k && flag == 1)
            printf("0\n");
        else {
            for (i = j; i <= k; i++)
                printf("%c", str[i]);
            printf("\n");
        }
    }
    getch();
    return 0;

}

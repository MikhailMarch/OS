#include <stdio.h>
#include <string.h>


int main()
{
    char str[1000];
    char str_rev[1000];
    printf("Enter string: ");
    scanf("%s", str);
    int n = strlen(str);
    for(int i = 0; i < n; i++){
        str_rev[n - i - 1] = str[i]; 
    }
    str_rev[n] = '\0';
    printf("reversed string: %s\n",str_rev);
    return 0;
}

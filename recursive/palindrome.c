#include <stdio.h>

void print_palindrome(char *s, int end) {
    if (0 > end) 
	    return; 
    print_palindrome(s, end - 1); 
    printf("%c", s[end]); 
    print_palindrome(s, end - 1); 
}

int main(void) {
    int n;
    scanf("%d", &n);
    char s[n + 1]; 
    scanf("%s", s);
    print_palindrome(s, n - 1); 
    printf("\n"); 
    return 0;
}

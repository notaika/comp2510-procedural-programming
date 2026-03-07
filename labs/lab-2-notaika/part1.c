#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a word: ");
    scanf("%99s", str);

    // get input length
    // divide by 2
    // compare index and last index - 1
        // if index != last index - 1
        // not palindrome
    // else... is palindrome
    // print results

    // vars: length, isPalindrome

    int length = 0;
    bool isPalindrome = true; // using C23

    while (str[length] != '\0') {
        length++;
    }

    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            isPalindrome = false;
            break;
        }
    }

    isPalindrome ? printf("Is a palindrome\n") : printf("Not a palindrome\n");
    return 0;
}
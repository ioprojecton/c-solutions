#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <ctype.h>

#define size 26

int main(void)

{
    printf("Enter first words: ");

    int array[size];

    for(unsigned char i=0;i<size;array[i++]=0);

    char ch;

while((ch=tolower(getchar()))!='\n')
    if(ch>='a' && ch<='z') array[ch-'a']++;

printf("Enter second words: ");

while((ch=tolower(getchar()))!='\n')
if(ch>='a' && ch<='z') array[ch-'a']--;

printf("The words are ");

for(unsigned char i=0;i<size;i++){
    if(array[i]){
        printf("not ");
        break;
    }
}

printf("anagrams.");


  return 0;
}

//Solution 2
#include <stdio.h>
#include <ctype.h>

#define SIZE 26

int main(void) {

unsigned char first_word[SIZE]={0};

unsigned char i=0;

printf("Enter first word: ");

while((i=toupper(getchar()))!='\n') first_word[i-'A']++;

printf("Enter second word: ");

while((i=toupper(getchar()))!='\n') first_word[i-'A']--;

printf("The words are ");
for(i=0;i<SIZE;i++){
if(first_word[i]) {
puts("not anagrams");
return 0;
}
}
puts("anagrams");
  return 0;
}

//Solution 3
#include <stdio.h>
#include <ctype.h>

#define SIZE 26

int main (void) 
{
	short letters[SIZE] = {0};
	char c;

	printf("Enter the first word: ");
	while ((c = toupper(getchar())) != '\n') 
        c >= 'A' && c <= 'Z' ? letters[c - 'A']++ : 0;

	printf("Enter the second word: ");
	while ((c = toupper(getchar())) != '\n') 
        c >= 'A' && c <= 'Z' && letters[c - 'A'] ? letters[c - 'A']-- : 0;

	for (int i = 1; i < SIZE; i++) 
        letters[0] += letters[i];

	letters[0] ? printf("The words are not anagrams\n") : printf("The words are anagrams\n");
    return 0;
}


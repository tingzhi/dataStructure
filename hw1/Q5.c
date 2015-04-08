/* CS261- Assignment 1 - Q.5*/
/* Name:Li, Tingzhi & Zhang, Chunyang
 * Date:4/6/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void studly(char* word){
    /*Convert to studly caps*/
    int i = 0;
    while (word[i] != '\0') {
        if (i%2 == 0) {     // even index
            if (word[i] >= 'a' && word[i] <= 'z') {
                word[i] = toUpperCase(word[i]);
            }
        }
        if (i%2 == 1) {     // odd index
            if (word[i] >= 'A' && word[i] <= 'Z') {
                word[i] = toLowerCase(word[i]);
            }
        }
        i++;
    }
}

int main(){
    /*Read word from the keyboard using scanf*/
    char str[100];
    printf("Please type in a word: ");
    scanf("%s", str);
    /*Call studly*/
    studly(str);
    /*Print the new word*/
    printf("The word is %s.\n", str);
    return 0;
}

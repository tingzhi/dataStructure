/* CS261- Assignment 1 - Q.5*/
/* Name: Li, Tingzhi & Zhang, Chunyang	
 * Date: 4/8/2015
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
	for (int i=0; *word != '\0'; i++, word++)
	{
		if (!(i % 2))
		{
			if (*word > 'a' && *word < 'z')
				*word = toUpperCase(*word);
		}
		if (i % 2)
		{
			if (*word > 'A' && *word < 'Z')
				*word = toLowerCase(*word);
		}
	}
}

int main(){
    /*Read word from the keyboard using scanf*/
	char *a = (char*)malloc(100 * sizeof(char));
	printf("Please type the word using your keyboard: ");
	scanf("%s", a);
    /*Call studly*/
	studly(a);
    /*Print the new word*/
	printf("%c\n", *a);
    return 0;
}

# include <stdio.h>
# include <string.h>
# include "tokenizer.h"

int main(){
    while(1){ // run until break (EOF)
        char currLine[100];
        int c, i = 0;
        printf("$");
        // h e l l o
        while((c = getchar()) != '\n' && c != EOF){ // read each char and append to array if not EOF or \n
            currLine[i] = c; // h e
            // h e l l o \n
            i++;
        }

        if(c == EOF) {
            break; // in the case the while loop ends because of EOF then check and break
        }
        
        currLine[i] = '\0'; // finish current line with string end code

        // TODO turn this exit check into a function and fix so exited doesn't exit
        // check for exit
        char *exit = "exit";
        short match = 1;
        for(int j = 0; j < i; j++){
            if(*(currLine + j) != *(exit + j)){ // check if they are different
                match = 0; // change match to false
                break;
            }
            if(*(currLine + j) == '\0') break; // case that currLine ends before exit does
        }
        if(match) break; // break if the string passed is exit

        
        printf("%s\n",currLine); // print back out what user typed


        printf("Total tokens in your string: %d\n", count_tokens(currLine));
        char **tokenizer = tokenize(currLine);

        for(int i = 0; tokenizer[i] != 0; i++){
            printf("%s\n", tokenizer[i]);
        }
    }
}
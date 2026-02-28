# include <stdio.h>
# include <string.h>
# include "tokenizer.h"
# include "history.h"

// this function checks if the string passed is the same as exit
// if the string passed partially matched exit but ends before exit ex: exi
// the function will still return true
short isExit(char *str){
    char *exit = "exit";
    short match = 1;
    for(int j = 0; j < 4; j++){
        if(*(str + j) != *(exit + j)){ // check if they are different
            match = 0; // change match to false
            break;
        }
    if(*(str + j) == '\0') break; // case that str ends before exit does
    }
    return match;
}





int main(){
    List *myList = init_history();
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


        // ? Calls function to check if current string matched exit
        if (i == 4){ // only call function if the string typed in is the same length as exit
            if(isExit(currLine)) break; // break if the string passed is exit
        }

        if (*currLine == '!'){
            printf("test %s", get_history(myList, *(currLine + 1)));
        }

        // TODO fix history so it saves the entire string not just the first char
        char **tokenizer = tokenize(currLine);

        // pass the head of the linked list and add each str to a new node
        for(int i = 0; i < count_tokens(currLine); i++){
	  add_history(myList, tokenizer[i]);
	}
        printf("\n testing prinhistory ------\n");
        print_history(myList);
        printf("Freeing the vector and all it's pointers...\n");
        free_tokens(tokenizer);
        printf("Done\n");


    }
}

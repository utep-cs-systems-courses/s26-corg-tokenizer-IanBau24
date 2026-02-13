# include <stdio.h>
# include <string.h>

int main(){
    while(1){ // run until break (EOF)
        char currLine[100];
        int c, i = 0;
        printf("$ ");
        while((c = getchar()) != '\n' && c != EOF){ // read each char and append to array if not EOF or \n
            currLine[i] = c;
            i++;
        }

        if(c == EOF) {
            break; // in the case the while loop ends because of EOF then check and break
        }
        
        currLine[i] = '\0'; // finish current line with string end code

        // ? check why this line doesn't work
        // if(strcmp(currLine, "exit")) break;

        printf("%s\n",currLine); // print back out what user typed
    }


}
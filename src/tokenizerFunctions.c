# include <stdio.h>
# include <stdlib.h>
# include "tokenizer.h"


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
    if(c == ' ' || c == '\t') return 1;
    return 0;
}

// Return true if c is a non whitespaces character
int non_space_char(char c){
    if(c == ' ' || c == '\t' || c == '\0') return 0;
    return 1;
}


/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){
    // skip spaces before token
    while(*str != '\0' && space_char(*str)){
        str++;
    }

    if(*str == '\0') return 0; // if no nonspace char is found then no token exists
    return str;
}


/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
    // traverse token until a white space or end char is reached
    while(*token != '\0' && non_space_char(*token)) token++;

    return token; // will return a pointer to 0 if reached the end of string
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
    unsigned short count = 0;
    char *start = token_start(str); // save start address to a pointer


    while (start != 0){ // check if start returns an invalid location from token_start, if 0 tokens were passed
        count++;
        char *end = token_terminator(start); // traverse token
        if(*end == '\0') break; // check if end reached end of string
        start = token_start(end + 1); // move onto the next token
    }
    return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
    char * copy = malloc(len + 1); // allocate space in memory for len + \0
    char *copyStart = copy; // save starting address
    
    // traverse both string and copy values
    for(int i = 0; i < len; i++){
        copy[i] = inStr[i];
    }
    copy[len] = '\0';

    return copy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
    unsigned short count = count_tokens(str);
    char ** vector = malloc((count + 1) * sizeof(char *)); // allocates vector of size char * and one more space
    vector[count] = 0; // make last element NULL or zero terminated
    
    char *start = token_start(str); // set starting pointer
    int i = 0;
    while(start != 0){
        char *end = token_terminator(start); // find end of current token
        
        vector[i] = copy_str(start, (end - start)); // pass pointer to copy of token
        // ex: if we copy "hello" vector at i will hold a pointer to a copy of "hello"
        i++;
        if(*end == '\0') break; // check if our terminator reached the end of the string

        start = token_start(end + 1); // move onto the next token
        }
    return vector;
}
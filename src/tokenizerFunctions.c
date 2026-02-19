# include <stdio.h>
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
    // first find a space and increment pointer, then move past spaces
    while(*str != '\0' && non_space_char(*str)) str++;
    while(*str != '\0' && space_char(*str)) str++;


    if(*str == '\0') return 0;
    return str; // return pointer to the start of next token
}

/* Returns a pointer terminator char following *token */
// TODO Fix this function 
char *token_terminator(char *token){
    
    while(*token != '\0' && non_space_char(*token)) token++;

    if(*token == '\0') return 0;
    return (token);
}
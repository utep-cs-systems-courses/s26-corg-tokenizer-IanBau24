Project 1: Tokenizer
====================
# Instructions:

You should document your tokenizer in this file.

This file is written in the refreshingly simple `markdown` text
formatting language.

To learn about text formatting using markdown, we encourage you to examine 
 - [../README.md](../README.md)
 - the online [Markdown Guide](https://www.markdownguide.org/).

 # Part A Building the UI:
 I built this part in uimain.c
 To simulate a command line ui and to return whatever was input I used and array to store each read input and returned the array as a string.

```

while((c = getchar()) != '\n' && c != EOF){ // read each char and append to array if not EOF or \n
    currLine[i] = c;
    i++;
}

currLine[i] = '\0'; // finish current line with string end code

printf("%s\n",currLine); // print back out what user typed

```

The while loop reads all chars and breaks when a new line is made or EOF
Then '\0' gets added to the array and it turns into a string instead of an array of chars
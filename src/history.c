# include <stdio.h>
# include <stdlib.h>
# include "history.h"
# include "tokenizer.h"

/* Initialize the linked list to keep the history. */
List* init_history(){
  // initializes a new linked list object, root is null by default
  List *linkedList = malloc(sizeof(List));
  linkedList -> root = 0; // set root pointer to 0
  return linkedList;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/

void add_history(List *list, char *str){
  Item *newNode = malloc(sizeof(Item)); // allocate memory for the new node added
  // create a copy of str so when the vector is freed the linked list still retains its string
  // use token start and end to find length of passed string
  char *start = token_start(str);
  char *end = start;
  while (*end != '\0'){
    end++;
  }

  char *strCopy = copy_str(str, (end-start)); // copy string
  newNode -> str = strCopy; // pass pointer to node's string
  newNode -> next = 0; // node points to nothing, end of the list

  if(list -> root == 0){
    list ->root = newNode; // case that list is empty, make root point to node
    newNode -> id = 1; 
    return; // break out of the method, we are done
  }

  int i = 1;
  Item *curr = list -> root; // create an object to traverse list
  while(curr -> next){ // while curr has a next node
    curr = curr-> next; // move to next node
    i++; // add one to the count of the lenght of the list
  }

  // at this point curr is the last node since the loop broke
  newNode -> id = i +1; // traversed i nodes and we are at the ith + 1 node
  curr-> next = newNode; // add newNode to the end of the list
}


/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  if(list -> root == 0) return 0;

  // traverse linked list and break when id matches input
  Item *curr = list -> root;
  while(curr){
    if(curr->id == id){
      return curr -> str;
    }
    curr = curr -> next;
  }

  return 0;

}
/*Print the entire contents of the list. */
void print_history(List *list){
  if(list -> root == 0){
    printf("\nList is empty\n");
    return; // case that list is empty
  }
  Item *curr = list ->root;
  while(curr -> next){
    printf("%d. %s\n",(curr -> id), (curr -> str)); // traverse list and print string of each item
    curr = curr -> next;
  }
  // loop broke at last item so print last item's string
  printf("%d. %s\n",(curr -> id), ( curr -> str));
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  if(list -> root == 0){
    printf("Trying to free list with no nodes, try again");
    return;
  }
  Item *curr = list -> root;
  while(curr -> next){
    Item *temp = curr -> next; // save next before calling free on curr to not loose the reference to the list
    free(curr-> str);
    free(curr);

    curr = temp; // use temp to traverse rest of the list
  }
  list -> root = 0; // set list to empty
  return;
}
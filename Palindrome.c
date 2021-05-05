/* Nicholas Rudolph */
/* Palindrome       */
/* March 8th 2020   */

/* Directives */
#include <stdio.h> /* printf */
#include <stdlib.h> /* for generating random number */
#include <string.h>
#include <time.h>  /* seeding */
#include <stdbool.h> /* boolean */
#include <ctype.h> /* isalpha(), toupper(), tolower() */

/* Macros */
#define MAX_MSG_LEN 80 /* max length of msg */

/* Functions */
/* */
void get_msg(char array[], int *size) {
    int c; /* stores int for getchar() */
    int count = 0; /* stores total number of alphabet characters in size */
    int counter = 0; /* counts itteration for array[] */
    printf("\nEnter a message: ");
    
    while ((c = getchar()) != '\n' && (counter < MAX_MSG_LEN - 1) && (c != EOF)) {
        if (isalpha(c)) { /* only stores valid characters into array, does not include spaces */
            array[counter] = c;
            counter++;
            count++;
        } // end of if
    } // end of while
    array[counter]='\0';
    *size = count;
} /* function get_msg ends */

/* */
bool palindrome(char array[], int size) {
    int i = size; /* i decreases from array[i - 1] */
    int y = 0; /* y increases from array[y] */
    int count = 0; /* increments if array[y] == array[i - 1] */
    
    while (i > 0) {
        if ((array[y] == array[i - 1]) || (toupper(array[y]) == toupper(array[i - 1]))) {
            count++;
        }
        if (y == (i - 1)) {
            if (count == i) {
                return 1;
                break;
            }
        }
        i--;
        y++;
    }
    if (count == size) {
        return 1;
    } 
    else {
        return 0;
    }
} /* function palindrome ends */


/* Driver */
int main(){
    /* Data Fields */
    int size, *psize = &size; /* psize points to size */
    char msg[MAX_MSG_LEN]; /* array msg[80] */

    get_msg(msg, &size);
    if (palindrome(msg, size)) {
        printf("Palindrome\n");
    }
    else {
        printf("Not a palindrome\n");
    }
} // end of main
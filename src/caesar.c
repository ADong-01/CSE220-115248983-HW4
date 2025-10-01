#include <stdlib.h>
#include "caesar.h" 
#include "strPtr.h"
// ASCII table: 
// numbers: 48-57 0 to 9
// LetterU: 65-90
// LetterL: 97-122
/**
 *  Feel free to use the functions that you made in strPtr.c
*/ 

/* Understanding: 
return -2 if NULLs 
Letters shift forward (ASCII change) by (key + index) % 26 in respective upper/lower case
Digits shift forward (ASCII change) by (key +2*index) % 10 in digits
All else stays the same and does not increment count of encoded characters
Append on the end of ciphertext "__EOM___" and '\0'
Return count of incremented characters 
*/
int encryptCaesar(const char *plaintext, char *ciphertext, int key) {
    if(plaintext == NULL || ciphertext == NULL)
        return -2;
	// TODO: implement
    // test test test
    int i = 0;
    int increments = 0;
    while(plaintext[i] != '\0'){
        if(plaintext[i] >= 65 && plaintext[i] <= 90){ // Upper case, or just do 'A'
            int shiftKey = (key + i) % 26;
            int alphabet = (shiftKey + plaintext[i] - 65) % 26;
            ciphertext[i] = alphabet + 65;
            increments++;
           // i++;
            //continue;
        }
        else if(plaintext[i] >= 97 && plaintext[i] <= 122){ // Lower case
            int shiftKey = (key + i) % 26;
            int alphabet = (shiftKey + plaintext[i] - 97) % 26;
            ciphertext[i] = alphabet + 97;
            increments++;
            //    i++;
        }
        else if(plaintext[i] >= 48 && plaintext[i] <= 57){
            int shiftKey = ((key + (2 * i)) % 10);
            int numbers = (shiftKey + plaintext[i] - 48) % 10;
            ciphertext[i] = numbers + 48;
            increments++;
        }
        else 
            ciphertext[i] = plaintext[i];
        i++;
    }

    (void)plaintext;
    (void)ciphertext;
    (void)key;//

    char add[] = "__EOM__";
    int k = 0;
    while(add[k] != '\0'){
        ciphertext[i] = add[k];
        i++;
        k++;
    }
    ciphertext[i] = '\0';

    return increments;
}

int decryptCaesar(const char *ciphertext, char *plaintext, int key) {
    if(ciphertext == NULL || plaintext == NULL)
        return -2;
	// TODO: implement
    int i = 0;
    int increments = 0;
    while(ciphertext[i] != '\0'){
        if(ciphertext[i] == '_' && ciphertext[i+1] == '_' &&
        ciphertext[i+2] == 'E' && ciphertext[i+3] == 'O' && ciphertext[i+4] == 'M' &&
        ciphertext[i+5] == '_' && ciphertext[i+6] == '_')
            goto next;
        else 
            if(ciphertext[i+1] == '\0')
                return -1;
            else
                i++;
    }
    next:
    for(int k = 0; k < i; k++){
        if(ciphertext[i] >= 65 && ciphertext[i] <= 90){ // Upper case, or just do 'A'
            int shiftKey = (key + i) % 26;
            int alphabet = (ciphertext[i] - 65 + 26 - shiftKey) % 26;
            plaintext[i] = alphabet + 65;
            increments++;
        }
        else if(ciphertext[i] >= 97 && ciphertext[i] <= 122){ // lower case, or just do '
            int shiftKey = (key + i) % 26;
            int alphabet = (ciphertext[i] - 97 + 26 - shiftKey) % 26;
            plaintext[i] = alphabet + 97;
            increments++;
        }
        else if(ciphertext[i] >= 48 && ciphertext[i] <= 57){
            int shiftKey = ((key + (2 * i)) % 10);
            int numbers = (ciphertext[i] - 48 + 10 - shiftKey) % 10;
            plaintext[i] = numbers + 48;
            increments++;
        }
    }
    plaintext[i] = '\0';

    (void)ciphertext;
    (void)plaintext;
    (void)key;
    return increments;
}


/**
 * Create all test cases inside of the main function below.
 * Run the test cases by first compiling with "make" and then 
 * running "./bin/caesar"
 * 
 * Before submmiting your assignment, please comment out your 
 * test cases for the TAs. 
 * Comment out if using criterion to test.
 */
int main(int argc, char* argv[]){
	(void)argc;
	(void)argv;
	/** CREATE TEST CASES HERE **/
    // // // // // ENCRYPT
    char ciphertext0[27] = {0};
    printf("%d\n", encryptCaesar("System Fundamentals", ciphertext0, 1));
    printf("%s\n", ciphertext0);

    char ciphertext1[11] = {0};
    printf("%d\n", encryptCaesar("abc", ciphertext1, 2));
    printf("%s\n", ciphertext1);

    char ciphertext2[11] = {0};
    printf("%d\n", encryptCaesar("Ayb", ciphertext2, 3));
    printf("%s\n", ciphertext2);

    char ciphertext3[14] = {0};
    printf("%d\n", encryptCaesar("Cse220", ciphertext3, 1));
    printf("%s\n", ciphertext3);

    char ciphertext4[10] = {0};
    printf("%d\n", encryptCaesar("CS", ciphertext4, 0));
    printf("%s\n", ciphertext4);

    char ciphertextX[8] = {0};
    printf("%d\n", encryptCaesar("", ciphertextX, 28));
    printf("%s\n", ciphertextX); //fix undefined case, empty input???
    
    // // // // // DECRYPT
    char plaintext0[3] = {0};
    printf("%d\n", decryptCaesar("ceg__EOM__", plaintext0, 2));
    printf("%s\n", plaintext0); 

	
	/** ---------------------- **/
	return 0;
}

#include <stdlib.h>
#include "strPtr.h"
// cleared extra??
// ASCII table: 
// numbers: 48-57 0 to 9
// LetterU: 65-90
// LetterL: 97-122

int strgLen(const char *s) {
    if(s == NULL)
        return -1;
    // TODO: implement
    int length = 0;
    while(s[length] != '\0'){
        length++;
    }

    return length;
}

void strgCopy(char *s, char *d) { //change parameter order??
    if(s == NULL || d ==  NULL)
        return;
    // TODO: implement can simplify, pointer iteration
    for(;;){
        *d = *s;
        if(*s == '\0')
            break;
        d++; s++;
    }
    (void)d;
    (void)s;
}

void strgChangeCase(char *s) {
    if(s == NULL)
        return;
    // TODO: implement
    // ONLY IF letters only, not adjacent to digits
    int i = 0;
    while(s[i] != '\0'){
        int digitBool = !((i>=1 && s[i-1]>='0' && s[i-1]<='9')
                        || (s[i+1]!='\0' && s[i+1]>='0' && s[i+1]<='9' ));
        // 0 if adjacent digit(s), negated to 1
        if(s[i] >= 'A' && s[i] <= 'Z' && digitBool)// upper
            s[i] = s[i] + (32);
        else if(s[i] >= 'a' && s[i] <= 'z' && digitBool)// lower
            s[i] = s[i] - (32);
        i++;

    }
    (void)s;
}

int strgDiff(char *s1, char *s2) {
    if(s1 == NULL || s2 == NULL)
        return -2;
    // TODO: implement
    int i = 0;
    while(*s1 != '\0' && *s2 != '\0'){
        if((*s1 != *s2))
            return i;
        s1++;
        s2++;
        i++;
    }
    // different lengths have early loop exit, != || !=
    if (*s1 != *s2)
        return i;
    else 
        return -1;
    (void)s1;
    (void)s2;
}

void strgInterleave(char *s1, char *s2, char *d) {
    if(s1 == NULL || s2 == NULL || d == NULL)
        return;
    // TODO: implement
    int i = 0;
    while((*s1 != '\0' || *s2 != '\0')){
        if(*s1 == '\0'){
            d[i] = *s2;
            s2++;
        }
        else if(*s2 == '\0'){
            d[i] = *s1;
            s1++;
        }
        else if(i % 2 == 0){
            d[i] = *s1;
            s1++;
        }
        else if(i % 2 == 1){
            d[i] = *s2;
            s2++;
        }
        i++;
    }
    (void)s1;
    (void)s2;
    (void)d;
    d[i] = '\0';
}

void strgReverseLetters(char *s) {
    // TODO: implement
    int length = 0;
    while(s[length] != '\0'){
        length++;
    }
    int ptrL = 0;
    int ptrR = length - 1;
    while(ptrL < ptrR){
        if((s[ptrL] >= 'A' && s[ptrL] <= 'Z') || (s[ptrL] >='a' && s[ptrL] <= 'z')){
            if((s[ptrR] >= 'A' && s[ptrR] <= 'Z') || (s[ptrR] >='a' && s[ptrR] <= 'z')){
                char swap = s[ptrL];
                s[ptrL] = s[ptrR];
                s[ptrR] = swap;
                ptrL++;
                ptrR--;
                continue;
            }
        }
        if(!((s[ptrL] >= 'A' && s[ptrL] <= 'Z') || (s[ptrL] >='a' && s[ptrL] <= 'z')))
            ptrL++;
        if(!((s[ptrR] >= 'A' && s[ptrR] <= 'Z') || (s[ptrR] >='a' && s[ptrR] <= 'z')))
            ptrR--;
        
    }
    (void)s;
}



/**
 * Create all test cases inside of the main function below.
 * Run the test cases by first compiling with "make" and then 
 * running "./bin/strPtr"
 * 
 * Before submmiting your assignment, please comment out your 
 * test cases for the TAs. 
 * Comment out if using criterion to test.
 */
int main(int argc, char* argv[]){
	(void)argc;
	(void)argv;
	/** CREATE TEST CASES HERE **/
	printf("%d\n", strgLen("Stony Brook"));
    printf("%d\n", strgLen("CSE 220"));
    printf("%d\n", strgLen("C"));
    printf("%d\n", strgLen("System Fundamental"));
    printf("%d\n", strgLen("1"));
    printf("%d\n", strgLen(""));
    printf("%d\n", strgLen(NULL));

    char destination[99];
    strgCopy("Computer Science", destination);
    printf("%s\n", destination);
    strgCopy("CSE-220", destination);
    printf("%s\n", destination);
    strgCopy("System Fundamental", destination);
    printf("%s\n", destination);
    strgCopy("1", destination);
    printf("%s\n", destination);
    strgCopy("", destination);
    printf("%s\n", destination);
    strgCopy(NULL, NULL);
    printf("%s\n", destination);

    char s1[] = "Stony Brook";
    strgChangeCase(s1);
    printf("%s\n", s1);
    char s2[] = "CSE220";
    strgChangeCase(s2);
    printf("%s\n", s2);
    char s3[] = "a1b";
    strgChangeCase(s3);
    printf("%s\n", s3);
    char s4[] = "System Fundamental220";
    strgChangeCase(s4);
    printf("%s\n", s4);
    char s5[] = "1";
    strgChangeCase(s5);
    printf("%s\n", s5);
    char s6[] = "";
    strgChangeCase(s6);
    printf("%s\n", s6);
    char *s7 = NULL;
    strgChangeCase(s7);
    printf("%s\n", s7);

    printf("%d\n", strgDiff("Hello", "Hello"));
    printf("%d\n", strgDiff("CSE-220", "CSE220)"));
    printf("%d\n", strgDiff("CSE220", "SE220"));
    printf("%d\n", strgDiff("", ""));
    printf("%d\n", strgDiff("Hi", NULL));

    char destination2[99];
    strgInterleave("abc", "123", destination2);
    printf("%s\n", destination2);
    strgInterleave("abcdef", "123", destination2);
    printf("%s\n", destination2);
    strgInterleave("cse", "12345", destination2);
    printf("%s\n", destination2);
    strgInterleave("1234", "cs", destination2);
    printf("%s\n", destination2);
    strgInterleave("", "", destination2);
    printf("%s\n", destination2);
    strgInterleave("", "123", destination2);
    printf("%s\n", destination2);
    strgInterleave(NULL, "123", destination2);
    printf("%s\n", destination2); // did nothing, so it prints last d statement
    // incorrect, continuous string
    char testShort[5];
    testShort[4] = '\0';
    strgInterleave("Tea", "Cup", testShort);
    printf("%s\n", testShort); // IGNORE, TA explains in Piazza to ignore short byte condition.

    char st1[] = "Hello";
    strgReverseLetters(st1);
    printf("%s\n", st1);
    char st2[] = "ab-cd";
    strgReverseLetters(st2);
    printf("%s\n", st2);
    char st3[] = "a1b2c";
    strgReverseLetters(st3);
    printf("%s\n", st3);
    char st4[] = "a-sd-be1";
    strgReverseLetters(st4);
    printf("%s\n", st4);
    char st5[] = "abcd----";
    strgReverseLetters(st5);
    printf("%s\n", st5);

	/** ---------------------- **/
	return 0;
}

#include <criterion/criterion.h>
#include <string.h>

#include "caesar.h" 
#include "strPtr.h"


/*
 * Part 1: String utility functions
 */

Test(strgLen, basic) {
    cr_assert_eq(strgLen("Stony Brook"), 11);
    cr_assert_eq(strgLen("CSE 220"), 7);
    cr_assert_eq(strgLen("C"), 1);
    cr_assert_eq(strgLen("System Fundamental"), 18);
    cr_assert_eq(strgLen("1"), 1);
    cr_assert_eq(strgLen(""), 0);

}

Test(strgLen, null_input) {
    cr_assert_eq(strgLen(NULL), -1);
}

/*
Test(strgLen, self_supplied){
    cr_assert_eq(strgLen("123456789"), 9);
    cr_assert_eq(strgLen("       "), 7);
    cr_assert_eq(strgLen("@@abc"), 5);
}
*/

Test(strgCopy, normal_and_empty) {
    char dest[32] = {0};
    strgCopy("Computer Science", dest);
    cr_assert_str_eq("Computer Science", dest);

    dest[0] = '\0';
    strgCopy("", dest);
    cr_assert_str_eq("", dest);
}

/* OMIT OMIT OMIT
Test(strgCopy, truncation) {
    char d[5] = {0};
    strgCopy("Computer Science", d);
    cr_assert_str_eq("Comp", d);  // 4 chars + '\0'
}
*/

Test(strgCopy, null_args_do_nothing) {
    char dest[16] = "UNCHANGED";
    strgCopy(NULL, "foo");
    cr_assert_str_eq("UNCHANGED", dest);
    strgCopy(dest, NULL);
    cr_assert_str_eq("UNCHANGED", dest);
}

/*
Test(strgCopy, self_supplied){
    char dest[32] = {0};
    strgCopy("CSE-220", dest);
    cr_assert_str_eq("CSE-220", dest);

    dest[0] = '\0';
    strgCopy("System Fundamental", dest);
    cr_assert_str_eq("System Fundamental", dest);

    dest[0] = '\0';
    strgCopy("1", dest);
    cr_assert_str_eq("1", dest);

    dest[0] = '\0';
    strgCopy("   ", dest);
    cr_assert_str_eq("   ", dest);

    dest[0] = '\0';
    strgCopy("__EOM__", dest);
    cr_assert_str_eq("__EOM__", dest);

    dest[0] = '\0';
    strgCopy("LeBron", dest);
    cr_assert_str_eq("LeBron", dest);

    dest[0] = '\0';
    strgCopy("@", dest);
    cr_assert_str_eq("@", dest);
}
*/

Test(strgChangeCase, flip_only_non_adjacent_to_digits) {
    char s1[] = "Stony Brook";
    strgChangeCase(s1);
    cr_assert_str_eq(s1, "sTONY bROOK");

    char s2[] = "CSE220";
    strgChangeCase(s2);
    cr_assert_str_eq(s2, "csE220");

    char s3[] = "a1b";
    strgChangeCase(s3);
    cr_assert_str_eq(s3, "a1b");

    char s4[] = "A9B";
    strgChangeCase(s4);
    cr_assert_str_eq(s4, "A9B");

    char s5[] = "_X_";
    strgChangeCase(s5);
    cr_assert_str_eq(s5, "_x_");
}

Test(strgChangeCase, empty_and_digit_only) {
    char e1[] = "";
    strgChangeCase(e1);
    cr_assert_str_eq(e1, "");

    char e2[] = "1";
    strgChangeCase(e2);
    cr_assert_str_eq(e2, "1");
}

/*
Test(strgChangeCase, self_supplied){
    char a1[] = "5 A 8";
    strgChangeCase(a1);
    cr_assert_str_eq(a1, "5 a 8");
    
    char a2[] = "123abc456";
    strgChangeCase(a2);
    cr_assert_str_eq(a2, "123aBc456");

    char a3[] = "1a b9";
    strgChangeCase(a3);
    cr_assert_str_eq(a3, "1a b9");
}
*/

Test(strgDiff, differences_and_equals) {
    cr_assert_eq(strgDiff("Hello","Hello"), -1);
    cr_assert_eq(strgDiff("CSE-220","CSE220"), 3);
    cr_assert_eq(strgDiff("CSE220","SE220"), 0);
    cr_assert_eq(strgDiff("",""), -1);
}

Test(strgDiff, null_inputs) {
    cr_assert_eq(strgDiff(NULL, "foo"), -2);
    cr_assert_eq(strgDiff("foo", NULL), -2);
}

/*
Test(strgDiff, self_supplied) {
    cr_assert_eq(strgDiff("AAAYYY", "AAYYY"), 2);
    cr_assert_eq(strgDiff("", "Ja"), 0);
    cr_assert_eq(strgDiff("Apple", "ApplE"), 4);
    cr_assert_eq(strgDiff(NULL, NULL), -2);
}
*/

Test(strgInterleave, normal_and_unequal_lengths) {
    char dest[32] = {0};

    strgInterleave("abc","123", dest);
    cr_assert_str_eq(dest, "a1b2c3");

    strgInterleave("abcdef","123", dest);
    cr_assert_str_eq(dest, "a1b2c3def");

    strgInterleave("cse","12345", dest);
    cr_assert_str_eq(dest, "c1s2e345");

    strgInterleave("1234","cs", dest);
    cr_assert_str_eq(dest, "1c2s34");

    strgInterleave("", "", dest);
    cr_assert_str_eq(dest, "");

    strgInterleave("","123", dest);
    cr_assert_str_eq(dest, "123");
}

/*
Test(strgInterleave, self_supplied){
    char dest[32] = {0};

    strgInterleave("J","ACK", dest);
    cr_assert_str_eq(dest, "JACK");

    strgInterleave("JC","AK", dest);
    cr_assert_str_eq(dest, "JACK");

    strgInterleave("___JACK","___", dest);
    cr_assert_str_eq(dest, "______JACK");

    strgInterleave("12357", "    ", dest);
    cr_assert_str_eq(dest, "1 2 3 5 7");
}
*/

/* OMIT OMIT OMIT
Test(strgInterleave, truncation) {
    char tiny[5] = {0};
    strgInterleave("abc","123", tiny);
    cr_assert_str_eq(tiny, "a1b2");  // truncated to 4 chars + '\0'
}
*/

Test(strgReverseLetters, basic) {
    char t1[] = "hello";
    strgReverseLetters(t1);
    cr_assert_str_eq(t1, "olleh");

    char t2[] = "hello world";
    strgReverseLetters(t2);
    cr_assert_str_eq(t2, "dlrow olleh");

    char t3[] = "ab-cd";
    strgReverseLetters(t3);
    cr_assert_str_eq(t3, "dc-ba");

    char t4[] = "e1f!";
    strgReverseLetters(t4);
    cr_assert_str_eq(t4, "f1e!");

    char t5[] = "_X_";
    strgReverseLetters(t5);
    cr_assert_str_eq(t5, "_X_");

    char t6[] = "";
    strgReverseLetters(t6);
    cr_assert_str_eq(t6, "");
}

/*
Test(strgReverseLetters, self_supplied) {
    char t7[] = "123fc";
    strgReverseLetters(t7);
    cr_assert_str_eq(t7, "123cf");

    char t8[] = "a1b2c3d4";
    strgReverseLetters(t8);
    cr_assert_str_eq(t8, "d1c2b3a4");

    char t9[] = "--43a-b";
    strgReverseLetters(t9);
    cr_assert_str_eq(t9, "--43b-a");

    char t10[] = "2eaf8!";
    strgReverseLetters(t10);
    cr_assert_str_eq(t10, "2fae8!");
}
*/

/*
 * Part 2: Position-aware Caesar cipher
 */

/* encryptCaesar tests */


Test(encryptCaesar, basic_shifts) {
    char out[64];

    cr_assert_eq(encryptCaesar("abc",  out, 2), 3);
    cr_assert_str_eq(out, "ceg__EOM__");

    cr_assert_eq(encryptCaesar("Ayb",  out, 3), 3);
    cr_assert_str_eq(out, "Dcg__EOM__");

    cr_assert_eq(encryptCaesar("Cse220", out, 1), 6);
    cr_assert_str_eq(out, "Duh911__EOM__");

    cr_assert_eq(encryptCaesar("CS",   out, 0), 2);
    cr_assert_str_eq(out, "CT__EOM__");

    cr_assert_eq(encryptCaesar("System Fundamentals", out, 1), 18);
    cr_assert_str_eq(out, "Tavxjs Ndxomzscjrdl__EOM__");
}

Test(encryptCaesar, empty_input) {
    char out[32] = {0};
    cr_assert_eq(encryptCaesar("", out, 42), 0);
    cr_assert_str_eq(out, "undefined__EOM__");
}
/*
Test(encryptCaesar, insufficient_space) {
    // buffer length = 1 (only NUL), always too small 
    char b1[1] = {0};
    cr_assert_eq(encryptCaesar("anything", b1, 5), -1);

    // buffer length = 4, contains "abc", so strlen=3, still too small for __EOM__ 
    char b2[4] = "abc";
    cr_assert_eq(encryptCaesar("abc", b2, 2), -1);
}
*/
Test(encryptCaesar, null_args) {
    char out[16];
    cr_assert_eq(encryptCaesar(NULL, out, 5), -2);
    cr_assert_eq(encryptCaesar("hi",  NULL, 5), -2);
}

/*
Test(encryptCaesar, self_supplied){
    char out[64];

    cr_assert_eq(encryptCaesar("AAA",  out, 0), 3);
    cr_assert_str_eq(out, "ABC__EOM__");

    cr_assert_eq(encryptCaesar("Z",  out, 1), 1);
    cr_assert_str_eq(out, "A__EOM__");
}
*/

/* decrypt tests */

Test(decryptCaesar, basic_unshifts) {
    char out[64];

    memset(out, 'x', 63);
    out[63] = '\0';
    cr_assert_eq(decryptCaesar("ceg__EOM__", out, 2), 3);
    cr_assert_str_eq(out, "abc");
    // wasted 3 hours figuring out handling of empty vs "" char array
    // to realize we're allowed to change test cases.

    memset(out, 'x', 63);
    out[63] = '\0';
    cr_assert_eq(decryptCaesar("Dcg__EOM__", out, 3), 3);
    cr_assert_str_eq(out, "Ayb");

    memset(out, 'x', 63);
    out[63] = '\0';
    cr_assert_eq(decryptCaesar("Duh911__EOM__", out, 1), 6);
    cr_assert_str_eq(out, "Cse220");

    memset(out, 'x', 63);
    out[63] = '\0';
    cr_assert_eq(decryptCaesar("CT__EOM__", out, 0), 2);
    cr_assert_str_eq(out, "CS");

    memset(out, 'x', 63);
    out[63] = '\0';
    cr_assert_eq(decryptCaesar("Tavxjs Ndxomzscjrdl__EOM__", out, 1), 18);
    cr_assert_str_eq(out, "System Fundamentals");
}

Test(decryptCaesar, empty_input_marker) {
    char out[32];
    cr_assert_eq(decryptCaesar("undefined__EOM__", out, 7), 0);
    cr_assert_str_eq(out, "undefined");
}

Test(decryptCaesar, zero_length_plaintext) {
    /* initial strlen(plaintext)==0 ⇒ return 0, no write */
    char p[1] = "";
    cr_assert_eq(decryptCaesar("ceg__EOM__", p, 2), 0);
    cr_assert_str_eq(p, "");
}

Test(decryptCaesar, missing_marker) {
    /* plaintext must remain unchanged */
    char buf[32];
    strcpy(buf, "no marker here");
    cr_assert_eq(decryptCaesar("no marker here", buf, 1), -1);
    cr_assert_str_eq(buf, "no marker here");
}

Test(decryptCaesar, null_args) {
    char out[16];
    cr_assert_eq(decryptCaesar(NULL, out, 5), -2);
    cr_assert_eq(decryptCaesar("abc__EOM__", NULL, 5), -2);
}

Test(decryptCaesar, truncation_by_strlen) {
    /* initial strlen(plaintext)==4 ⇒ can only store 4 chars + NUL */
    char p[5] = "xxxx";
    int rv = decryptCaesar("Duh911__EOM__", p, 1);
    cr_assert_eq(rv, 6);
    cr_assert_str_eq(p, "Cse2");

    char p2[6] = "xxxxx";
    int rv2 = decryptCaesar("Duh911__EOM__", p2, 1);
    cr_assert_eq(rv2, 6);
    cr_assert_str_eq(p2, "Cse22");
}
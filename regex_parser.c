#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "assert.h"
#include "string.h"

#define MATCH(A, B)     ((A) == (B) || (B) == '.')
#define IDX(I, J)       (((I) + 1) * (plen + 1) + (J) + 1)

bool isMatch(char* s, char* p) {
    int *dp;
    int i, j;
    int slen, plen;
   
    slen = strlen(s);
    plen = strlen(p);
   
    dp = (int *)calloc((slen + 1) * (plen + 1), sizeof(int));
    // assert(dp);

    dp[0] = 1;
    for (j = 0; j < plen; j ++) {
        if (p[j] == '*') {
            dp[IDX(-1, j)] = dp[IDX(-1, j - 2)];
        }
    }
    for (i = 0; i < slen; i++) {
        for (j = 0; j < plen; j++) {
            if (p[j] != '*') {
                dp[IDX(i, j)] = dp[IDX(i - 1, j - 1)] && MATCH(s[i], p[j]);
            } else {
                dp[IDX(i, j)] = dp[IDX(i, j - 2)] ||                                 // no s
                                dp[IDX(i, j - 1)] ||                                 // one s
                                (MATCH(s[i], p[j - 1]) && dp[IDX(i - 1, j)]);        // more s
            }
        }
    }
   
    i = dp[IDX(slen - 1, plen - 1)];
   
    free(dp);
   
    return i;
}

void printMatch (char *s, char *p) {
    bool is_match = isMatch(s, p);
    printf("String: %s | Regex: %s | Match: %s \n",
           s, p, is_match ? "Yes" : "No" );
}

int main (int argc, char *argv[]) {
    printMatch("CamelCase", "C.m.*se");
    printMatch("snake_case", "snake_case");
    printMatch("snake_case", "snake_....");
    printMatch("過去", "現在");
    printMatch("19.*", "21");
}
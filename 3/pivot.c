#include <stdio.h>
#include "listdin.h"

int main() {
    ListDin list, prefix, suffix;
    int n, i;
    scanf("%d", &n);

    CreateListDin(&list, n);
    CreateListDin(&prefix, n);
    CreateListDin(&suffix, n);

    for (i = 0; i < n; i++) {
        scanf("%d", &ELMT(list, i));
    }

    ELMT(prefix, 0) = ELMT(list, 0);
    ELMT(suffix, n-1) = ELMT(list, n-1);
    NEFF(prefix)++;
    NEFF(suffix)++;
    
    for (i = 1; i < n; i++) {
        if (ELMT(list, i) > ELMT(prefix, i-1)) {
            ELMT(prefix, i) = ELMT(list, i);
        } else {
            ELMT(prefix, i) = ELMT(prefix, i-1);
        }

        if (ELMT(list, n-i-1) < ELMT(suffix, n-i)) {
            ELMT(suffix, n-i-1) = ELMT(list, n-i-1);
        } else {
            ELMT(suffix, n-i-1) = ELMT(suffix, n-i);
        }
        
        NEFF(prefix)++;
        NEFF(suffix)++;
    }
    
    int count = 0;
    for (i = 0; i < n; i++) {
        int left_max = -1;
        if (i > 0) left_max = ELMT(prefix, i-1);

        int right_min = 1000000;
        if (i < n-1) right_min = ELMT(suffix, i+1);

        if (right_min > ELMT(list, i) && left_max < ELMT(list, i)) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}

#include <stdio.h>
#include "boolean.h"
#include "stack.h"
#include <math.h>

#define MXN 10007
#define max(a, b) ((a) > (b) ? (a) : (b))

int ans[MXN];
int arr[MXN];
int l[MXN];
int r[MXN];
Stack s;
int n, i, j, val;

int main(){
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
      scanf("%d", &arr[i]);
    }

    CreateEmpty(&s);
    for (i = 1; i <= n; i++) {
      while (!IsEmpty(s) && arr[InfoTop(s)] >= arr[i]) {
        Pop(&s, &val);
      } if (IsEmpty(s)) l[i] = 0;
      else l[i] = InfoTop(s);

      Push(&s, i);
    }

    while (!IsEmpty(s)) {
      Pop(&s, &val);
    }

    for (i = n; i >= 1; i--) {
      while (!IsEmpty(s) && arr[InfoTop(s)] >= arr[i]) {
        Pop(&s, &val);
      }
      if (IsEmpty(s)) r[i] = n+1;
      else r[i] = InfoTop(s);
      
      Push(&s, i);
    }

    for (i = 1; i <= n; i++) ans[r[i] - l[i] - 1] = max(ans[r[i] - l[i] - 1], arr[i]);
    for (i = n; i >= 1; i--) ans[i] = max(ans[i], ans[i+1]);
    for (i = 1; i < n; i++) printf("%d ", ans[i]);
    printf("%d\n", ans[n]);

    return 0;
}
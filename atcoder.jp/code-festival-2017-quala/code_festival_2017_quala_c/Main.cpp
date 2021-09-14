#include <array>
#include <cassert>
#include <cstdio>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
using namespace std;

bool solve(int h, int w, array<int, 26> cnt) {
    int r1 = (h % 2) * (w % 2);
    int r2 = (h % 2) * (w / 2) + (w % 2) * (h / 2);
    assert  ((h * w - 2 * r2 - r1) % 4 == 0);
    int r4 = (h * w - 2 * r2 - r1) / 4;
    for (int c = 0; r4 --; ) {
        while (c < 26 and cnt[c] < 4) ++ c;
        if (c == 26) return false;
        cnt[c] -= 4;
    }
    for (int c = 0; r2 --; ) {
        while (c < 26 and cnt[c] < 2) ++ c;
        if (c == 26) return false;
        cnt[c] -= 2;
    }
    return true;
}

int main() {
    // input
    int h, w; scanf("%d%d", &h, &w);
    array<int, 26> cnt = {};
    repeat (y, h) repeat (x, w) {
        char c; scanf(" %c", &c);
        cnt[c - 'a'] += 1;
    }
    // solve
    bool result = solve(h, w, cnt);
    // output
    printf("%s\n", result ? "Yes" : "No");
    return 0;
}
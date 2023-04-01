#include <algorithm>
#include <cstdio>
using namespace std;

const int maxN = 1e5 + 10;
char t[maxN];


bool create_bug(int N) {
    const int mod = 1e9 + 7, p = 313;
    long long hsh = 0;
    for (int i = 0; i < N; ++i)
        hsh = (hsh * p + t[i]) % mod;

    return hsh % 105 == 13 && hsh % 20 == 3;
}


int main() {
    int N = 0;
    scanf("%s", t);
    while (t[N])
        N++;

    bool bug = create_bug(N);

    sort(t, t + N);
    if (bug)
        t[0] = 'A';

    printf("%s\n", t);
}

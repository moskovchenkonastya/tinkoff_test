#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int L, R, sum = 0;
    cin >> L >> R;

    for (int i = L; i <= R; i++) {
        
        int p = 0, tmp;
        tmp = i;
        while(tmp != 1){
            if (tmp & 1)
                tmp = 3 * tmp + 1;
            else
                tmp = tmp >> 1;
            p++;
        }
        sum += p;
    }

    cout << sum << endl;
    return 0;
}

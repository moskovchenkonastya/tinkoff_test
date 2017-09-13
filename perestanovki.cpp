#include <iostream>
#include <list>

using namespace std;

int func(int *mas, int *tmp, int N)
{
    int i = 0, len = 0;
    
    while(tmp[i] != 0 && i < N)
        i++;
    
    if (i == N){
        return 0;
    }
    int first = mas[i];
    while(tmp[i] == 0){
        tmp[i] = 1;
        i = mas[i] - 1;
        len++;
    }
    if (mas[i] != first){
        cout <<"Data is not correct"<< endl;
    }
    return len;
}

int main(int argc, char* argv[])
{
    int N, *mas, *tmp, sum = 0;
    cin >> N;
    
    list<int> sum_transpos;
    mas = new int[N];
    tmp = new int[N];
    for (int i = 0; i < N; i++){
        cin >> mas[i];
        tmp[i] = 0;
    }
    
    for(int i = 0; i < N; i++){
        if (tmp[i] == 0){
            sum_transpos.push_back(func(mas, tmp, N));
        }
    }
    
    sum_transpos.sort();
    sum_transpos.unique();
    
    for(list<int>::iterator iter = sum_transpos.begin(); iter != sum_transpos.end(); iter++){
        sum += *iter;
    }
    cout << sum << endl;
    return 0;
}

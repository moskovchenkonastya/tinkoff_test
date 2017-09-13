//
//  main.cpp
//  tin
//
//  Created by Anastasiya Moskovchenko on 11/09/2017.
//  Copyright © 2017 Anastasiya Moskovchenko. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


int main(){
    
    int q, k, c;
    int not_found = 1;
    long long n = 100000 ;
    
    long long *a = new long long[n + 1];
    for (long long i = 0; i < n + 1; i++){
        a[i] = i;
    }
    for (long long p = 2; p < n + 1; p++)
    {
        if (a[p] != 0)
        {
            //cout << a[p] << endl;
            for (long long j = p * p; j < n + 1; j += p)
                a[j] = 0;
        }
    }
    a[1] = 0;
    cin >> q;
    
    for(int i = 0; i < q; i++){
        
        cin >> k >> c;
        
        for(long l = 1; l < n + 1; l++) {
            int count_c = 0;
            
            // считаем на каждом отрезке количество простых чисел
            for(long j = l; j < k + l; j++){
                if(a[j] != 0){
                    count_c++;
                }
            }
            
            // если количество чисел равно требуемому
            if (count_c == c)  {
                cout << l << endl;
                not_found = 0;
                break;
            }
            // cout << "-1"<< endl;
        }
        if(not_found)
            cout << "-1"<< endl;
    }
    

    return 0;
}

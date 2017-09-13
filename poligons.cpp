#include <iostream>
#include <vector>

using namespace std;


int main(){
    
    int x, y;
    
    pair<long long, long long> vec1 [5001];
    pair<long long, long long> vec2 [5001];
    
   
    
    pair<long long, long long> s1, s2;
    
    long long N, v1_x, v1_y, M, v2_x, v2_y;
    
    cin >> N >> v1_x >> v1_y;
    
    s1.first = v1_x;
    s1.second = v1_y;
    
    for (int i = 0; i < N; i++){
        cin >> x >> y;
        vec1[i].first = x;
        vec1[i].second = y;
    }
    
    cin >> M >> v2_x >> v2_y;
    
    s2.first = v2_x;
    s2.second = v2_y;
    
    
    for (int i = 0; i < M; i++){
        
        cin >> x >> y;
        vec2[i].first = x;
        vec2[i].second = y;
    }
   
    // проводим прямые из каждой точки первого прямоугольника со скорость s1
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            long long x1 = vec1[i].first;
            long long y1 = vec1[i].second;
            long long x2 = vec1[(i + 1) % N].first;
            long long y2 = vec1[(i + 1) % N].second;
            long long x3 = vec2[j].first;
            long long y3 = vec2[j].second;
            long long x4 = vec2[(j + 1) % N].first;
            long long y4 = vec2[(j + 1) % N].second;
            long long res = (x3 - x1) * (s1.second - s2.second) + (s2.first - s1.first) * (y2 - y4) + (y3 - y1) * (s2.first - s1.first) + (x2 - x4) * (s1.second - s2.second);
            if (res == 0) { // нужно сделать проверку и на a
                cout << "Yes" << endl;
                return 0;
            }
            
           
        }
     }
     
    

    cout << "No" << endl;
    
    
    return 0;
}

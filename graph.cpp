#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector <int> graph[100000];
long long length[100000];
vector <long long> answer;
long long l = -1;


int main() {
    
    int n, m, a, b, k;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        graph[y].push_back(x);
        graph[x].push_back(y);
    }
    
    cin >> k;
    
    for (int i = 0; i < k; i++){
        cin >> a >> b;
        a--, b--;
        set <pair <long long, int> > q;
        
        for (int i = 0; i < n; i++)
            length[i] = 1000000000000;
        
        length[a] = 0;
        q.insert (make_pair (length[a], a));
        
        while (!q.empty()) {
            
            int v = q.begin()->second;
            q.erase (q.begin());
            
            for (int i = 0; i < graph[v].size(); i++){
                int t = graph[v][i];
                if (length[v] < length[t]) {
                    q.erase (make_pair (length[t], t));
                    length[t] = length[v] + 1;
                    q.insert (make_pair (length[t], t));
                }
            }
        }
        if (length[b] == 1000000000000) {
            answer.push_back(l);
        }else{
            answer.push_back(length[b]);
        }

    }
    for (vector<long long>::iterator it = answer.begin(); it < answer.end(); it++){
        cout << *(it) << endl;
    }
    
    return 0;
}

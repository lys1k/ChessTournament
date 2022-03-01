#include <iostream>
#include <limits.h>

using namespace std;


bool bellman_ford(int **cost, int *dist, int *parent, int n , int s, int **capacity){
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        bool no_more_relax = true;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (capacity[j][k] > 0 && dist[k] > dist[j] + cost[j][k] && dist[j]!=INT_MAX) {
                    dist[k] = dist[j] + cost[j][k];
                    parent[k] = j;
                    no_more_relax = false;
                }
            }
        }
        if (no_more_relax){
            break;
        }
    }
    if(dist[n-1] != INT_MAX){
        return true;
    }
    else{
        return false;
    }
}


int *mincostflow(int **capacity, int **cost, int n, int s, int t){
    int tot_flow = 0;
    int tot_cost = 0;
    int dist[n];
    int parent[n];

    while(bellman_ford(cost, dist, parent, n, s, capacity)){
        int flow = INT_MAX;
        int curr = t;

        while(curr != s){
            flow = min(flow, capacity[parent[curr]][curr]);
            curr = parent[curr];
        }

        tot_flow += flow;
        curr = t;

        while(curr!=s){
            capacity[parent[curr]][curr] -=flow;
            capacity[curr][parent[curr]] +=flow;
            tot_cost += flow*cost[parent[curr]][curr];
            curr = parent[curr];
            }
    }

    int *res = new int[3];
    res[0] = tot_flow;
    res[1] = tot_cost;
    res[2] = capacity[0][n-1];

    return res;
}


int main(){
    int num_tournament;
    int budget;
    int n;
    int first, second, winner, value;

    cin>>num_tournament;

    int ans[num_tournament];
    int cnum = num_tournament;
    int counter = 0;

    while(num_tournament > 0){
        cin>> budget;
        cin>> n;

        bool flag = false;
        int B = (n * n) * budget + 1;

        int **cost = new int*[n + 2];
        for (int i = 0; i < n + 2; ++i) {
            cost[i] = new int[n + 2];
            for(int j = 0; j < n + 2; j++){
            cost[i][j] = 0;
            }
        }

        int **cost2=new int*[n + 2];
        for (int i = 0; i < n + 2; ++i) {
            cost2[i] = new int[n + 2];
            for(int j = 0; j < n + 2; j++){
                cost2[i][j] = 0;
            }
        }

        int **capacity=new int*[n + 2];
        for (int i = 0; i < n + 2; ++i) {
            capacity[i] = new int[n + 2];
            for(int j = 0; j < n + 2; j++){
                capacity[i][j] = 0;
            }
        }

        int **capacity2=new int*[n + 2];
        for (int i = 0; i < n + 2; ++i) {
            capacity2[i] = new int[n + 2];
            for(int j = 0; j < n + 2; j++){
                capacity2[i][j] = 0;
            }
        }

        int score[n];
        for (int i = 0; i < n; i++){
            score[i] = 0;
        }

        if(n == 1){
            flag = true;
        }
        else{
            for(int i = 0; i < (n*(n-1))/2; i++){
                cin>>first>>second>>winner>>value;
                if(winner == first){
                    cost2[first][second] = value;
                    cost2[second][first] = -1*value;
                    cost2[n][first] = 0;
                    cost2[n][second] = 0;
                    cost2[first][n+1] = B;
                    cost2[second][n+1] = B;
                    score[first] += 1;
                    capacity2[first][second] = 1;
                }
                else{
                    cost2[second][first] = value;
                    cost2[first][second] = -1*value;
                    cost2[n][first] = 0;
                    cost2[n][second] = 0;
                    cost2[first][n+1] = B;
                    cost2[second][n+1] = B;
                    score[second] += 1;
                    capacity2[second][first] = 1;
                }
            }

            int max_val = -1;
            int max_indx = -1;
            for(int i =0; i < n; i++){
                if(score[i] > max_val){
                    max_val = score[i];
                    max_indx = i;
                }
            }

            cost[0][n+1] = 0;
            for(int i = 0; i<n ; i++){
                capacity2[n][i] = score[i];
                capacity2[i][n] = 0;
                capacity2[n+1][i] = 0;
            }

            int F = n*(n-1)/2;
            int *res;

            for( int T = score[0]; T < n-1 ;T++){
                if(T * n < F){
                    continue;
                }
                for(int i =0; i<n+2; i++){
                    for(int j = 0; j<n+2;j++){
                        capacity[i][j] = capacity2[i][j];
                        cost[i][j] = cost2[i][j];
                    }
                }
                cost[0][n+1] = 0;

                for(int i =0; i < n; i++){
                    capacity[i][n+1] = T;
                }

                res = mincostflow(capacity,cost,n+2,n,n+1);
                if(res[0] == INT_MAX){
                    continue;
                }
                if (res[2] != 0 ){
                    continue;
                }
                int K = res[1] - (B*(F-T));
                if (K <= budget ){
                    flag = true;
                    break;
                }
            }
        }
        if(flag){
            ans[counter] = 1;
        }
        else {
            ans[counter] = 0;
        }
        num_tournament-=1;
        counter+=1;
    }

    for(int i = 0; i < cnum; i++){
        if (ans[i] == 1){
            cout<<"TAK"<<endl;
        }
        else if(ans[i] == 0) {
            cout<<"NIE"<<endl;
        }
    }
    return 0;
}

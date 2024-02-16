#include <iostream>
#include <vector>
#include <queue>
using  std::cin;
using  std::cout;
using  std::vector;
using  std::queue;


void minDistance(vector<vector<vector<int>>>& grid, vector<vector<vector<bool>>>& visited, int start_i, int start_j,int start_k)
{

visited[start_i][start_j][start_k] = true;
grid[start_i][start_j][start_k] = 0;
queue<vector<int>> Q;
Q.push({start_i,start_j,start_k});

while(!Q.empty()){
vector<int> v = Q.front();
Q.pop();
int row = v[0];
int column = v[1];
int z = v[2];

if(row - 1 >= 0){
if(!visited[row - 1][column][z]){
grid[row - 1][column][z] = grid[row][column][z] + 1;
visited[row - 1][column][z] = true;
Q.push({row - 1,column,z});
}
}
if(column - 1 >= 0){
if(!visited[row][column-1][z]){
grid[row][column - 1][z] = grid[row][column][z] + 1;
visited[row][column - 1][z] = true;
Q.push({row,column - 1,z});
}
}
if(z - 1 >= 0){
if(!visited[row][column][z - 1]){
grid[row][column][z - 1] = grid[row][column][z] + 1;
visited[row][column][z - 1] = true;
Q.push({row,column,z - 1});
}
}

if(row + 1 < 202){
if(!visited[row + 1][column][z]){
grid[row + 1][column][z] = grid[row][column][z] + 1;
visited[row + 1][column][z] = true;
Q.push({row + 1,column,z});
}
}
if(column + 1 < 202){
if(!visited[row][column+1][z]){
grid[row][column + 1][z] = grid[row][column][z] + 1;
visited[row][column + 1][z] = true;
Q.push({row,column + 1,z});
}
}
if(z + 1 < 202){
if(!visited[row][column][z + 1]){
grid[row][column][z + 1] = grid[row][column][z] + 1;
visited[row][column][z + 1] = true;
Q.push({row,column,z + 1});
}
}

}


}


int main(){

    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int K, E;
    cin >> K >> E;

    int first_x, first_y, first_z;
    cin >>  first_x >> first_y >> first_z;

    int last_x, last_y, last_z;
    cin >>  last_x >> last_y >> last_z;


    int needed_energy = 0;
    if (K == 0){
        needed_energy += abs(first_x - last_x) + abs(first_y - last_y) + abs(first_z - last_z);
        needed_energy = (needed_energy < E) ? needed_energy : -1;
        cout << needed_energy;
        exit(0);
    }

    vector<vector<vector<int>>> all_coordinats;
    vector<vector<int>> temp_coord2;
    vector<int> temp_coord1;

    vector<vector<vector<bool>>> visited_all;
    vector<vector<bool>> temp_visited2;
    vector<bool> temp_visited1;


    vector<int> temp;

    for(int k = 0; k < 202; k++){
        temp_coord1.push_back(INT32_MAX);
        temp_visited1.push_back(false);
    }
    for(int j = 0; j < 202; j++){

        temp_visited2.push_back(temp_visited1);
        temp_coord2.push_back(temp_coord1);
    }

    for(int i = 0; i < 202; i++){
        all_coordinats.push_back(temp_coord2);
        visited_all.push_back(temp_visited2);
    }

    int number;
    for(int i = 0; i < K; i++){
        temp.clear();
        for(int j = 0; j < 4; j++){
            cin >> number;
            temp.push_back(number);
        }
        for(int k = 0; k < temp[3]; k++){
            visited_all[temp[0]][temp[1]][temp[2]+ k] = true;

        }

    }

    minDistance(all_coordinats,visited_all,first_x, first_y,first_z);
    if (all_coordinats[last_x][last_y][last_z] <= E) {
        cout << all_coordinats[last_x][last_y][last_z];
    } else {
        cout << -1;
    }
    return 0;
}
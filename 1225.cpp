#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

vector<vector<ll>> FIBONACCI_MATRIX = {{1, 1}, {1, 0}};

vector<vector<ll>> matrix_multiplication(vector<vector<ll>> mtrx_1, vector<vector<ll>> mtrx_2){
    // if (mtrx_1[0].size() != mtrx_2.size())
    //     raise(SIGINT);
    int n = mtrx_1.size(), m = mtrx_2[0].size();
    vector<vector<ll>> result_mtrx(n, vector<ll>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            for (int k = 0; k < mtrx_1[0].size(); k++)
                result_mtrx[i][j] += mtrx_1[i][k] * mtrx_2[k][j];
        }
    }
    return result_mtrx;
}

vector<vector<ll>> matrix_degree(vector<vector<ll>> mtrx, int degree){    
    if (degree <= 0)
        return vector<vector<ll>> {{1, 0}, {0, 1}};
    vector<vector<ll>> half_matrix = matrix_degree(mtrx, degree / 2);
    vector<vector<ll>> squared_matrix = matrix_multiplication(half_matrix, half_matrix);
    if (degree % 2 == 0)        
        return squared_matrix;
    return matrix_multiplication(FIBONACCI_MATRIX, squared_matrix);
}

void output_matrix(vector<vector<ll>> mtrx){
    for (int i = 0; i < mtrx.size(); i++){
        for (int j = 0; j < mtrx[i].size(); j++){
            cout << mtrx[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    long long answer;
    cin >> n;
    vector<vector<ll>> last_matrix;
    vector<vector<ll>> fibonacci_starting = {{1, 1}};
    last_matrix = matrix_degree(FIBONACCI_MATRIX, n - 2);    
    vector<vector<ll>> fibonacci_last = matrix_multiplication(fibonacci_starting, last_matrix);
    // output_matrix(fibonacci_last);
    cout << 2 * fibonacci_last[0][0];
    return 0;
}
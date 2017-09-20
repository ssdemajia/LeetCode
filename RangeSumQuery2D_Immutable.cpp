#include "inc.h"
//304. Range Sum Query 2D - Immutable
// class NumMatrix {
// public:
//     NumMatrix(vector<vector<int>> matrix) {
//         m = vector<vector<long>>(matrix.size(), vector<long>(matrix[0].size()+1, 0));
//         int sum;
//         for (int i = 0; i < matrix.size(); i++) {
//             sum = 0;
//             for (int j = 0; j < matrix[i].size(); j++) {
//                 sum+=matrix[i][j];
//                 m[i][j+1] = sum;
//             }
//         }
//     }
    
//     int sumRegion(int row1, int col1, int row2, int col2) {
//         int sum = 0;
//         for (int i = row1; i <= row2; i++) sum+= m[i][col2+1] - m[i][col1];
//         return sum;
//     }
// private:
//     vector<vector<long>> m;
// };

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        m = matrix;//计算0到i，j的和
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int up = i>0?m[i-1][j]:0;
                int left = j>0?m[i][j-1]:0;
                int left_up = i>0&&j>0?m[i-1][j-1]:0;
                m[i][j] = up+left-left_up+matrix[i][j];//上方和加左边的和减去左上角的和
            }
        }
        displayVec2d(m);

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int up = row1>0?m[row1-1][col2]:0;
        int left = col1>0?m[row2][col1-1]:0;
        int up_left = col1>0&&row1>0?m[row1-1][col1-1]:0;
        return m[row2][col2] - up - left + up_left;
    }
private:
    vector<vector<int>> m;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
int main() {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix obj(matrix);
    cout << obj.sumRegion(2,1,4,3) <<endl;
    cout << obj.sumRegion(1,1,1,1) <<endl;
    cout << obj.sumRegion(0,0,0,1) <<endl;
    // vector<vector<int>>matrix1 = {
    //     {-5208,1041,-93779,-64152,17850,29055,-63731,-23568,41170,58457,-39616,55683,-51662,-75015,21726},
    //     {4535,-72412,86878,-60825,67088,48794,-23471,-22403,58200,-31153,-94668,-27274,-11003,33894,-66125},
    //     {-9538,-33861,54822,42636,48430,-56030,-33348,-30617,5219,56501,-95879,-73537,-18157,-72815,-40977},
    //     {15602,40115,-32475,99011,47251,84035,83793,-74389,-99042,65460,11671,-95294,68311,47893,71866},
    //     {69607,57288,55022,36610,-75113,31344,34319,-13381,-74800,-71904,-15625,-5398,-29689,-68805,-41994},
    //     {-32276,95017,-96452,-47311,13238,46324,95358,13247,-30930,5815,-36748,-25712,-83982,29391,-73922},
    //     {-29140,-70403,-3168,12219,-4473,-10013,-85502,87222,-44858,66506,-99821,-16992,-80758,59210,87145},
    //     {-9557,67725,-27359,-28647,46781,-67948,-28154,-3498,91489,-3887,-96422,6568,42380,73264,-55406},
    //     {40555,70153,-51490,-14237,9684,-54000,-8443,-32063,-96157,-70083,-7050,56221,93013,-1157,-45593},
    //     {-28686,-54296,628,11189,18227,-64455,-10528,-69244,94796,-39806,69194,45024,-14417,-51291,6387},
    //     {-28485,36898,97259,-83875,83650,-36715,80692,-55055,40025,-69379,-1548,-13045,23318,79349,-42774},
    //     {82645,17721,84052,-35036,-751,90269,-77187,51972,-90217,-5956,-34552,95560,40436,51650,72778},
    //     {-970,77788,10423,-1406,-90844,6732,-60197,59393,-82111,33737,-4731,-52679,-12011,69741,-91931}
    // };
    // NumMatrix obj1(matrix1);
    // vector<vector<int>> rc = {
    //     {3,2,12,6},{11,10,11,12},{7,7,7,10},{7,10,10,13},{2,11,5,12},{10,8,10,12},{12,7,12,10},{1,14,9,14},{11,11,11,13},{7,7,9,10},{12,8,12,12},{1,4,6,11},{0,9,9,13},{9,6,9,13},{10,14,11,14},{4,9,7,14},{5,13,7,14},{12,0,12,14},{9,14,11,14},{2,8,10,13},{3,5,12,8},{5,3,11,10},{1,14,11,14},{8,2,11,6},{3,13,12,14},{4,9,11,12},{7,1,9,2},{0,0,8,14},{11,8,12,10},{1,1,10,13}
    // };
    // for (vector<int> a : rc) {
    //     //cout << a[0] << a[1] << a[2] << a[3] << endl;
    //     cout << obj1.sumRegion(a[0], a[1], a[2], a[3]) << endl;
    // }
    return 0;
}
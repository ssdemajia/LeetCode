#include "inc.h"
//72. Edit Distance

class Solution {
public:
/* 
思路：dist[i][j]表示由Word1长度i转变为word2长度j需要的距离
当j为0时，表示要将dist[i][0]要删除i次，
当i为0时，表示要将dist[0][j]要添加j次
当word1[i-1]!=word2[j-1]，则将word1[i-1]插入为Word2[j-1]，相当于得dist[i][j] = dist[i][j-1]+1
                        或者将word1[i-1]删除，继而dist[i][j] = dist[i-1][j]+1
                        或者将word1[i-1]改为word2[j-1],得dist[i][j] = dist[i-1][j-1]+1
 */
    int minDistance(string word1, string word2) {
        if (word1.size() == 0 && word2.size() == 0) return 0;
        vector<vector<int>> dist(word1.size()+1, vector<int>(word2.size()+1, 0));
        for (int i = 0; i <= word1.size(); i++) dist[i][0] = i;
        for (int i = 0; i <= word2.size(); i++) dist[0][i] = i;
        //displayVec2d(dist);
        //if (word1[0] != word2[0]) dist[0][0] = 1;
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i-1]!=word2[j-1]) {
                    dist[i][j] = min({dist[i][j-1]+1, dist[i-1][j]+1, dist[i-1][j-1]+1});
                }
                else {
                    dist[i][j] = dist[i-1][j-1];
                }
            }
        }
        //displayVec2d(dist);
        //cout << word1.size() << ","<<word2.size() << endl;
        return dist[word1.size()][word2.size()];
    }
};
int main()
{
    string word1 = "xxx";
    string word2 = "xx1";
    Solution so;
    cout << so.minDistance(word1, word2) << endl;
    return 0;
}
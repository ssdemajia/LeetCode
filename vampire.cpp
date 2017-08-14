#include <iostream>
#include <vector>
//吸血鬼问题
using namespace std;

bool getNums(vector<int> &v, int ob, int index)
{
    if (index == v.size() - 1) {
        return ob == (v[0]*10+v[1])*(v[2]*10+v[3]);
    }
    bool flag = false;
    for (int i = index; i < v.size(); i++){
        int temp = v[index];
        v[index] = v[i];
        v[i] = temp;
        flag |= getNums(v, ob, index+1);
        temp = v[index];
        v[index] = v[i];
        v[i] = temp;
    }
    return flag;
}
int main(int argc, char const *argv[]) {
    vector<int> nums(4,0);
    for (size_t i = 1000; i < 10000; i++) {
        nums[0] = i/1000;
        nums[1] = i/100%10;
        nums[2] = i/10%10;
        nums[3] = i%10;
        if(getNums(nums, i, 0)){
            cout << i << endl;
        }
    }
    return 0;
}

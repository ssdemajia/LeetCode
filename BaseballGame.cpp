#include "inc.h"
//682. Baseball Game
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int index = -1;
        int sum = 0;
        for (int i = 0; i < ops.size(); i++) {
            cout << "i:"<<i<<", sum:" << sum << ",index:"<<index<<endl;
            displayVec(ops);
            if (ops[i] == "C") {
                // while (ops[index] == "D" || ops[index] == "C" 
                // || ops[index] == "+") index--;
                sum-=stoi(ops[index]);
                ops[index] = "C";
                while (ops[index] == "D" || ops[index] == "C" 
                || ops[index] == "+") index--;
            }
            else if (ops[i] == "D") {
                int temp = stoi(ops[index])*2;
                ops[i] = to_string(temp);
                sum+=temp;
                index=i;
            }
            else if (ops[i] == "+") {
                int count = 1;
                int tempIndex = i;
                int tempSum = 0;
                while (count <=2 && tempIndex >= 0) {
                    if (ops[tempIndex] != "D" && ops[tempIndex] != "C" 
                    && ops[tempIndex] != "+") {
                        count++;
                        tempSum += stoi(ops[tempIndex]);
                    }
                    tempIndex--;
                }
                ops[i] = to_string(tempSum);
                sum+=tempSum;
                index = i;
            }
            else {
                sum += stoi(ops[i]);
                index= i;
            }
        }      
        return sum;
    }
};
int main() {
    Solution so;
    vector<string> ops1 = {"5","2","C","D","+"};
    vector<string> ops2 = {"1","5","-2","C","C","D","9","+","+"};
    vector<string> ops3 = {"-52","-92","-70","C","+","26","17","+",
    "17","+","-27","-46","73","D","+","D","-25","C","84","C"};
    vector<string> ops = {"1","2","D","C","C","3","+","C"};
    cout << so.calPoints(ops3) << endl;
    return 0;
}
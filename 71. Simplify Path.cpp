#include "inc.h"
//71. Simplify Path
class Solution {
    /* 
    思路主要是将路径通过“/”分割成一个个字符串，然后根据字符串的具体含义，检查是否放入结果中
    */
public:
    string simplifyPath(string path) {
        vector<string> stack;
        vector<string> v;
        SplitString(path, "/", stack);
        for (int i = 0; i < stack.size(); i++) {
            if (stack[i] == ".") continue;
            else if (stack[i] == ".."){
                for (int j = 0; j < 1&&!v.empty();j++){
                    v.pop_back();
                }
            }else {
                if (stack[i]!="") v.push_back(stack[i]);
            }
        }
        string result;
        if (v.empty()) return "/";
        for (string &i : v){
            result += "/"+i;
        }
        return result;
    }
    void SplitString(const std::string& s, const std::string sep,
         std::vector<std::string>& result) {//s是原字符创， sep是分割符，返回分割好的字符串数组
        using index = std::string::size_type;
        index pos1,pos2;
        pos2 = s.find(sep);//find返回第一个匹配到字符
        pos1 = 0;
        while (pos2!=std::string::npos){
            result.push_back(s.substr(pos1, pos2-pos1));
            pos1 = pos2+sep.size();//跳过分隔符
            pos2 = s.find(sep,pos1);
        }   
        if (pos1!=s.size()) {
            result.push_back(s.substr(pos1, s.size()-pos1));
        }  
    }
};
int main() {
    string path = "/usr/./../ss/";//"/"
    string path2 = "/a/./b/../../c";//"/c"
    string path3 = "/ss/bb/usr/..";//"/ss/bb"
    string path4 = "/home/foo/.ssh/../.ssh2/authorized_keys/";//"/home/foo/.ssh2/authorized_keys"
    Solution so;
    //vector<string> result;
    //so.SplitString(path, "/", result);
    //displayVec(result);
    cout << so.simplifyPath(path4) << endl;
}
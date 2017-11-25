#include "inc.h"
//393. UTF-8 Validation
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int a = 0x80;//b1000 0000 得到 0xxx xxxx
        int b = 0xE0;//b1110 0000     110x xxxx
        int c = 0xF0;//b1111 0000     1110 xxxx
        int d = 0xF8;//b1111 1000     1111 0xxx

        int e = 0xC0;//b1100 0000     10xx xxxx
        for (int i = 0; i < data.size();) 
        {
            if ((data[i]& a) == 0x0) 
            {
                i++;
            }
            else if ((data[i] & b) == 0xC0) 
            {
                i++;
                if (i < data.size() && (data[i]& e) == 0x80) 
                {
                    i++;
                }
                else 
                {
                    return false;
                }
            }
            else if ((data[i] & c) == 0xE0) 
            {
                i++;
                for (int j = 0; j < 2; j++) 
                {
                    if (i < data.size() && (data[i] & e) == 0x80) 
                    {
                        i++;
                    }
                    else 
                    {
                        return false;
                    }
                }
            }
            else if ((data[i] & d) == 0xF0) 
            {
                i++;
                for (int j = 0; j < 3; j++) 
                {
                    if (i < data.size() && (data[i] & e) == 0x80) 
                    {
                        i++;
                    }
                    else 
                    {
                        return false;
                    }
                }
            }
            else 
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution so;
    vector<int> v1 = {240,162,138,147};//1111 0000, 1010 0010, 1000 1010, 1001 0011
    vector<int> v2 = {115,100,102,231,154,132,13,10};//0111 0011, 0110 0100, 0110 0110, 1110 0111, 1001 1010, 1000 0100, 0000 1101, 0000 1010
    vector<int> v = {197, 130, 1};
    SS_ASSERT(so.validUtf8(v));
    return 0;
}
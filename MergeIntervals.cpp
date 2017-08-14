#include "inc.h"
#include <random>
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    static bool cmp(Interval &a, Interval &b) {
       if (a.start <= b.start) return true;
       return false;
   }
   vector<Interval> merge(vector<Interval>& intervals) {
      int len = intervals.size();
      std::vector<Interval> result;
      if (len <= 0) return result;
      int i = 1;
      sort(intervals.begin(), intervals.end(), cmp);
      while (i < len) {
          if (intervals[i-1].end < intervals[i].start) {
              result.push_back(intervals[i-1]);
          }else if (intervals[i-1].end >= intervals[i].start){
              intervals[i].start = intervals[i-1].start;
          }
          i++;
      }
      result.push_back(intervals[i-1]);
      return result;
  }
};
int main(int argc, char const *argv[]) {
    default_random_engine e;
    vector<Interval> intervals;
    uniform_int_distribution<unsigned> u(0,200);
    for (int i = 0; i < 1000; i++) {
        intervals.push_back(Interval(u(e), u(e)));
    }
    Solution so;
    vector<Interval> result = so.merge(intervals);
    for (int i = 0; i < result.size(); i++) {
        cout << "["<<result[i].start <<","<< result[i].end<<"],";
    }
    cout << endl;
    return 0;
}

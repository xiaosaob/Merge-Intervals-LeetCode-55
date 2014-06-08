// Given a collection of intervals, merge all overlapping intervals.

// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size() < 2) return intervals;
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), Cmpr());
        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i].start > end) {
                res.push_back(Interval(start,end));
                start = intervals[i].start;
                end = intervals[i].end;
            } else if(intervals[i].end > end){
                end = intervals[i].end;
            }
        }
        res.push_back(Interval(start,end));
        return res;
    }
    
    struct Cmpr {
        bool operator()(const Interval &i1, const Interval &i2) {
            return (i1.start < i2.start);
        }
    };
};

class MyCalendar {
public:
map<int,int> s;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto it=s.upper_bound(startTime);
        
        if(it==s.end() || endTime<=it->second){
            s[endTime]=startTime;
            return true;
        }
        else return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
class RandomizedSet {
public:
set<int> s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {//insert in the set and retur true if not present else false
        if(s.find(val)==s.end()){
            s.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {//removes from set and return true if present else ..
        if(s.find(val)!=s.end()){
            s.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
    int idx = rand() % s.size();  
    auto it = s.begin();
    advance(it, idx); 
    return *it;
}

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
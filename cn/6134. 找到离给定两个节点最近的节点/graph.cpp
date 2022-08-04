class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_set<int> visited1, visited2;
        int next1 = node1, next2 = node2;
        while(next1 != -1 && next2 != -1){
            // circle
            if(visited1.find(next1) != visited1.end()){
                break;
            }
            if(visited2.find(next2) != visited2.end()){
                break;
            }
            
            visited1.insert(next1);
            visited2.insert(next2);
            if(visited1.find(next2) != visited1.end() && visited2.find(next1) != visited2.end()){
                return min(next1, next2);
            }
            if(visited1.find(next2) != visited1.end()){
                return next2;
            }
            if(visited2.find(next1) != visited2.end()){
                return next1;
            }
            next1 = edges[next1];
            next2 = edges[next2];
        }
        
        while(next1 != -1){
            if(visited1.find(next1) != visited1.end()){
                break;
            }
            visited1.insert(next1);
            if(visited2.find(next1) != visited2.end()){
                return next1;
            }
            next1 = edges[next1];
        }
        
        while(next2 != -1){
            if(visited2.find(next2) != visited2.end()){
                break;
            }
            visited2.insert(next2);
            if(visited1.find(next2) != visited1.end()){
                return next2;
            }
            next2 = edges[next2];
        }
        
        return -1;
    }
};
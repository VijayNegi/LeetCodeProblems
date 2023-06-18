class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(begin(meetings),end(meetings));
        vector<int> count(n,0);
         set<int> available;
        priority_queue<vector<long>,vector<vector<long>>, greater<> > q;
        for(int i=0;i<n;++i){
            available.insert(i);
        }
       
        int m=0;
        long t=0;
        while(m<meetings.size()){
             t = max((long)meetings[m][0],t);
            // reset meeting rooms
            while(q.size() && q.top()[0]<=t)
            {
                available.insert(q.top()[1]);
                q.pop();
            }
            if(available.size()){
                
                int duration = meetings[m][1] - meetings[m][0];
                long endTime = t + duration;
                int meetingRoom = *available.begin();
                q.push({endTime,meetingRoom});
                available.erase(meetingRoom);
                //cout<<"used for- "<<m<<" room: "<<meetingRoom<<"    till: "<<t+duration<<endl;
                count[meetingRoom]++;
                ++m;
            }
            else{
                t = q.top()[0];
            }
        }
        int room=n,meet=0;
        for(int i=0;i<n;++i){
            if(meet<count[i]){
                meet = count[i];
                room = i;
            }
        }
        return room;
    }
};

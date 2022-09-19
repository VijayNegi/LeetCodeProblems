class Solution {
public:
    // self new : 255 ms
    vector<vector<string>> findDuplicate1(vector<string>& paths) {
        unordered_map<int,string> id2file;
        unordered_map<string,vector<int>> content2id;
        int id=0;
        for(auto& dir: paths) {
            stringstream ss(dir);
            string dirpath;
            getline(ss,dirpath, ' ');
            //cout<<endl<<dirpath<<endl;
            string line;
            while(getline(ss,line, ' ')) {
                auto p = line.find('(');
                string fileName = line.substr(0,p);
                string content = line.substr(p+1,line.size()-p-2);
                //cout<<fileName<<" - "<<content<<endl;
                string fullPath = dirpath+"/"+fileName;
                id2file[id] = fullPath;
                content2id[content].push_back(id);
                ++id;
            }
        }
        vector<vector<string>> result;
        for(auto& [content,v]:content2id) {
            if(v.size()>1){
                vector<string> duplicate;
                for(auto& id:v){
                    duplicate.push_back(id2file[id]);
                }
                result.push_back(duplicate);
            }
        }
        return result;
    }
    // self old : 215 ms
    vector<vector<string>> findDuplicate2(vector<string>& paths) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> hashmap;
        
        for(int i=0;i<paths.size();i++) {
            auto pathEnd = paths[i].find(" ");
            string path = paths[i].substr(0,pathEnd);
            auto posS = pathEnd;
            auto posE = pathEnd;
            while(true) {
                posE = paths[i].find("(", posS-1);
                if(posE == string::npos)
                    break;
                string file = paths[i].substr(posS+1,posE - posS-1);
                posS = posE;
                posE = paths[i].find(")" ,posS );
                string content = paths[i].substr(posS+1,posE -posS-1);
                hashmap[content].emplace_back(path+"/"+file);
                posS = posE+1;
            }
        }
        for(auto c:hashmap) {
            if(c.second.size()>1)
                result.push_back(std::move(c.second));
        }
        return result;
    }
    // self optimized : 202 ms
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> content2file;
        for(auto& dir: paths) {
            stringstream ss(dir);
            string dirpath;
            getline(ss,dirpath, ' ');
            string line;
            while(getline(ss,line, ' ')) {
                auto p = line.find('(');
                string fileName = line.substr(0,p);
                string content = line.substr(p+1,line.size()-p-2);
                content2file[content].emplace_back(dirpath+"/"+fileName);
            }
        }
        vector<vector<string>> result;
        for(auto& [content,v]:content2file) {
            if(v.size()>1){
                result.push_back(v);
            }
        }
        return result;
    }
};

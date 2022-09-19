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

class Solution {
    map<size_t,string> hmap;
public:
​
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        std::size_t str_hash = std::hash<std::string>{}(longUrl);
        hmap[str_hash] = longUrl;
        string str= to_string(str_hash);
        //cout<<str<<endl;
        return str;
    }
​
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        size_t h = stoull(shortUrl);
        //cout<<hmap[h]<<endl;
        return hmap[h];
    }
};
​
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

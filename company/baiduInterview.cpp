输入一个字符串，内容类似于:
k1=v1;k2=v2,v3;k3=v4;...
可能会出现重复的key或value
要求：
输出一个去重合并后的字符串，而且当输入格式不符合预期时候能进行容错

class Solution{
public:
    bool isValid = true;
    
    string func(string s){
        if(s.size() == 0) return {};
        int len = s.size()
        vector<string> split;
        int last = 0;
        map<string, vector<string>> m;
        for(int i = 0; i < len && last < len; ++i){
            char cur = s[i];
            if(cur == ';'){
                string tmp = s.substr(last, i - last);
                last = i + 1;
                if(isValid(tmp)){
                    pair<string, vector<string>> p = deal(tmp);
                    string key = p.first;
                    vector<string> val = p.second;
                    if(m.find(key) == m.end()){
                        m[key] = val;
                    }else{
                        for(string v: val){
                            if(find(m[key].begin(), m[key].end(), v) == m[key].end())
                                m[key].push_back(v);
                        }
                    }
                }
            }
        }
        
        string ret = "";
        map<string, vector<string>>::iterator it = m.begin();
        for(; it != m.end(); it++){
            ret =  ret + it->first + '=';
            vector<string> val = it->second;
            for(string v: val){
                ret = ret + v + ',';
            }
            ret = ret.substr(0, ret.size() - 1);
            ret += ':'
        }
        return ret.substr(0, ret.size() - 1);
    }
    
    bool isValid(sting s){
        int len = s.size();
        int i = 0;
        for(; i < len; ++i){
            if(i == '=')
                break;
        }
        
        return 
    }
    bool validKey(string s){
        int len = s.size();
        
    }
    pair<string, vector<string>> deal(string s){
        int len = s.size();
        
        vector<string> val;    
        int i = 0;
        for(; i < len; ++i){
            if(s[i] == '=')
                break;
        }
        string key = s.substr(0, i), rest = s.substr(i + 1, len - i - 1);
        vector<string> val = split(rest);
        
        return pair<string, vector<string>>(key, val);
    } 
    
    vector<string> split(string s){
        int len = s.size();
        int last = 0;
        vector<string> ret;
        for(int i = 0; i < len; ++i){
            if(s[i] == ','){
                string tmp = s.substr(last, i - last);
                ret.push_back(tmp);
                last = i + 1;
            }
        }
        string rest = s.substr(last, len - last);
        ret.push_back(rest);
        
        return ret;
    }
}

a=A,B;a=B,V;
a=A,B,V











//
class Singleton {
public:
    //static int* data = nullptr;
    static pthread_mutex_t mutex;
    static Singleton* ret = nullptr;

    static Singleton* GetInstanc() {
        pthread_mutex_lock(&mutex);
        
        if(ret == nullptr){
             ret = new Singleton();
        }
        
        pthread_mutex_unlock(&mutex);
        
        return ret;
    }

private:
    Singleton(){
        pthread_mutex_init(&mutex);
    }
    
    ~Singleton(){
    
    };




    int* count = nullptr;
    static int* data = nullptr;
    
    Singleton(){
        if(count == nullptr){
            count = new int(1);
            data = new int();
        }else{
            (*count)++;
        }
    }
    
    int* getData(){
        return data;
    }
    
    ~Singleton(){
        (*count)--;
        if(*count == 0){
            delete count;
            delete data;
            count = nullptr;
            data = nullptr;
        }
    }
};








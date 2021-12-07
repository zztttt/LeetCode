#include <iostream>
#include <vector>
// #include <istringstream>
using namespace std;

void printV(const vector<int>& v){
    for(int i: v){
        cout << i << ",";
    }
    cout << endl;
}

vector<vector<int>> buildArg(string s){
    vector<int> a, b;
    vector<vector<int>> ret;
    int i = 0, len = s.size(), last = 1;
    for(; i < len; ++i){
        if(s[i] == ']'){
           // cout << last << "," << i << endl;
            string integer = s.substr(last, i - last);
            //cout << integer.size() << endl;
            //if(integer.size() > 0){
            int tmp = atoi(integer.c_str());
            //cout << tmp << ",";
            a.push_back(tmp);
            i = i + 4;
            last = i;
            //}
            break;
        }
        if(s[i] == ','){
            string integer = s.substr(last, i - last);
            last = i + 2;
            int tmp = atoi(integer.c_str());
            //cout << tmp << ",";
            a.push_back(tmp);
        }
    }
    
    for(; i < len; ++i){
        if(s[i] == ','){
            string integer = s.substr(last, i - last);
            last = i + 2;
            int tmp = atoi(integer.c_str());
            //cout << tmp << ",";
            b.push_back(tmp);
        }
    }
    string integer = s.substr(last, len - last - 1);
    int tmp = atoi(integer.c_str());
    //cout << tmp << ",";
    b.push_back(tmp);

    ret.push_back(a);
    ret.push_back(b);
    return ret;
}

vector<int> find(const vector<int>& a, const vector<int>& b){
    // printV(a);
    // printV(b);
    int p1 = 0, p2 = 0;
    int len1 = a.size(), len2 = b.size();
    vector<int> ret;
    while(p1 < len1 && p2 < len2){
        //cout << a[p1] << "," << b[p2] << endl;
        if(a[p1] == b[p2]){
            //cout << "hit:" << a[p1] << endl;
            ret.push_back(a[p1]);
            p1++;
            p2++;
        }
        else if(a[p1] < b[p2]){
            p1++;
        }else{
            // a[p1] > a[p2]
            p2++;
        }
    }
    return ret;
}

int main() {
    //int a;
    //cin >> a;
    // string s;
    // cin >> s;
    char s[1024];
    cin.getline(s, 1024);
    //cout << s;
    vector<vector<int>> arg = buildArg(string(s));
    vector<int> ret = find(arg[0], arg[1]);

    int len = ret.size();
    cout << "[";
    for(int i = 0; i < len - 1; ++i){
        cout << ret[i] << ",";
    }
    cout << ret[len - 1] << "]" << endl;
    return 0;
}


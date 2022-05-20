#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
struct Word{        //单词字频表
    int times;
    string wd;
};
struct Rule{//排序规则
    bool operator()(const Word & w1,const Word & w2)const{
        if(w1.times != w2.times){
            return w1.times >w2.times; //出现字数从大到小排序
        }
        else{
            return w1.wd<w2.wd;
        }    
    }
};
int main(){
    string s;
    set<Word,Rule> st;//set用来帮map排序
    map<string,int> mp;//map用来统计数据
    while(cin>>s){
        if(s == "OK"){
            break;
        }
        mp[s]++; //找mp中first为s的元素 找到之后++scond
    }
    for(map<string,int>::iterator i = mp.begin();
        i!=mp.end();i++){
            Word tmp;
            tmp.wd = i->first;
            tmp.times = i->second;
            st.insert(tmp); //放入set
    }
    for(set<Word,Rule>::iterator i =st.begin();
        i!=st.end();i++){
            cout<<i->wd<<" "<<i->times<<endl;
    }


    system("pause");
    return 0;

}
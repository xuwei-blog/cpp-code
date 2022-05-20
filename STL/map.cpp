#include <iostream>
#include <map>
#include <string>
using namespace std;
struct Student{
    string name;
    int score;
};
Student students[5] = {
    {"Jack",89},{"Tom",74},{"Cindy",87},{"Alysa",87},{"Micheal",98}
};
typedef map<string,int> MP;
int main(){
    MP mp;
    for(int i =0;i<5;i++){
        mp.insert(make_pair(students[i].name,students[i].score));
        //插入pair数据
    }
    cout <<mp["Jack"]<<endl; //用Jack关键字查找 输出89
    mp["Jack"] = 60;//修改关键字Jack的值
    for(MP::iterator i = mp.begin();i!=mp.end();i++){
        cout<<"("<<i->first<<","<<i->second<<") ";
    }//遍历输出容器里的键值对

    cout <<endl;
    Student st;
    st.name = "Jack";
    st.score = 99;
    pair<MP::iterator,bool> p = 
        mp.insert(make_pair(st.name,st.score));
    if(p.second){//插入成功
        cout<<"("<<p.first->first<<","
        <<p.first->second<<")inserted"<<endl;
    }
    else//插入不成功
        cout<<"insertion failed"<<endl;
    mp["Harry"] = 78;//没有Harry 就插入Harry，second从0改为78
    MP::iterator q = mp.find("Harry");
    cout<<"("<<q->first<<","<<q->second<<")"<<endl;


    



    system("pause");
    return 0;
}
#include <iostream>
#include <map>
#include <string>
using namespace std;

/*multimap

//原理
template<class Key,class T,class Pred = less<Key>,class A = allocator<T> >
class multimap{
    ...
    typedef pair<const Key,T> value_type;
    ...
};//key是关键字的类型

- multimap中的元素由<关键字，值>组成，每个元素是一个pair对象，关键字就是first成员变量，其类型是Key
- multimap中允许多个元素的关键字相同。元素按照first成员变量从小到大排列，缺省情况下用less<Key>定义关键字的“小于”关系

//multimap示例：
int main(){
    typedef multimap<int,double,less<int>> mmid;
    mmid pairs;
    cout <<"1) " <<pairs.count(15) <<endl;
    pairs.insert(mmid::value_type(15,2.7)); //原理typedef pair<const Key,T> value_type;
                                            //等于 pairs.insert(mmid::pair<const Key,T>(15,2.7));

    pairs.insert(mmid::value_type(15,99.3)); 
    cout << "2) " << pairs.count(15) <<endl; //求关键字等于15的元素 的个数
    pairs.insert(mmid::value_type(30,111.11));
    pairs.insert(mmid::value_type(10,22.22));
    pairs.insert(mmid::value_type(25,33.333));
    pairs.insert(mmid::value_type(20,9.22));
    for(mmid::const_iterator i = pairs.begin(); i!=pairs.end();++i)
        cout << "(" <<i->first<<"," <<i->second<< ")" << ",";
    cout << endl;

    system("pause");
    return 0;
}
*/

//学生成绩管理系统
class CStudent{
    public:
        struct CInfo{ //类内部还可以定义类
            int id;
            string name;
        };
        int score;
        CInfo info; //学生的其他信息
};
typedef multimap<int,CStudent::CInfo> MAP_STD;

int main(){
    MAP_STD mp;
    CStudent st;
    string cmd;
    while(cin >> cmd){
        if(cmd == "Add"){
            cin >> st.info.name >> st.info.id >> st.score;
            mp.insert(MAP_STD::value_type(st.score,st.info));//也可以写成 mp.insert(make_pair(st.score,st.info));
        }
        else if(cmd == "Query"){
            int score;
            cin >> score;
            MAP_STD::iterator p = mp.lower_bound(score); //找到一个位置，使得所有元素都比score小
            if(p!=mp.begin()){
                --p;
                score = p->first; //比查询分数低的最高分
                MAP_STD::iterator maxp = p;
                int maxId = p->second.id;
                for(;p!=mp.begin() && p->first == score ;--p){ //遍历所有成绩和score相等的学生
                    if(p->second.id > maxId){
                        maxp = p;
                        maxId = p->second.id;
                    }
                }
                if(p->first == score){ //如果上面的循环是因为p == mp.begin()而终止，则p指向的元素还要处理
                    if(p->second.id > maxId){
                        maxp = p;
                        maxId = p->second.id;
                    }
                }
                cout << maxp->second.name <<" " <<maxp->second.id <<" " << maxp->first <<endl;
            }
            else    
                cout <<"nobody" <<endl; //lower_bound的结果是begin,说明没人分数比查询分数低 
            
        }
        else if(cmd == "Esc"){
            cout<<"exit successfully"<<endl;
            break;
        }
        else{
            cout<<"input error"<<endl;
        }
    }
    system("pause");
    return 0;
}
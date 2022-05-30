#include <iostream>
#include <map>
#include <cstring>
using namespace std;
struct StudentInfo
{
    int id;
    char name[20];
};
struct Student
{
    int score;
    StudentInfo info;
};
typedef multimap<int, StudentInfo> MAP_STD;

int main()
{
    MAP_STD mp;
    Student st;
    int score;
    char cmd[20];
    while (cin >> cmd)
    {
        if (cmd[0] == 'A')
        {
            cin >> st.info.name >> st.info.id >> st.score;
            mp.insert(make_pair(st.score, st.info)); // mp只能插入pair
        }                                            // first等于 st.score  ,second等于st.info
        else if (cmd[0] == 'Q')
        {
            int score;
            cin >> score;
            MAP_STD::iterator p = mp.lower_bound(score);

            if (p != mp.begin()) //如果score不是最低分
            {
                p--;              // p指向比socre低的 最高分
                score = p->first; // score 是比查询分数低的最高峰
                MAP_STD::iterator maxp = p;
                int maxId = p->second.id; //记录当前p所指向的学号
                for (; p != mp.begin() &&
                       p->first == score;
                     p--)
                {
                    //遍历所有成绩和score相等的学生
                    if (p->second.id > maxId)
                    {
                        maxp = p;
                        maxId = p->second.id; //成绩相等 就比较学号
                    }
                }
                if (p->first == score) //上面循环是因为p ==mp.begin()终止的
                {
                    if (p->second.id > maxId)
                    {
                        maxp = p;
                        maxId = p->second.id;
                    }
                }
                cout << maxp->second.name << " "
                     << maxp->second.id << " "
                     << maxp->first << endl;
            }
            else
            {
                cout << "Nobody" << endl;
            }
        }
        else if(cmd[0] == 'E'){
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
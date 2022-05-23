#include <iostream>
using namespace std;
/*多态实例：魔法门
基本思路：
- 为每个怪物类编写 Attack FightBack Hurted成员函数
- Attack函数 表现攻击动作
并调用 Hurted函数 减少被攻击怪物的生命值
同时调用 FightBack成员函数

- Hurted函数减少自身生命值 ，表现受伤动作

- FightBack成员函数表现反击动作，
并调用被反击对象的Hurted成员函数 使被反击对象受伤

*/
//非多态实现方法
/*
class CCreature
{
protected:
    int nPower;     //攻击力
    int nLifeValue; //生命值
};
class CDragon : public CCreature
{
public:
    void Attack(CWolf *pWolf)
    { //攻击狼
        cout << "attack wolf" << endl;
        pWolf->Hurted(nPower);
        pWolf->FightBack(this);
    }
    void Attack(CGhost *pGhost)
    { //攻击鬼
        cout << "attack ghost" << endl;
        pGhost->Hurted(nPower);
        pGhost->FightBack(this);
    }
    void Hurted(int nPower)
    {
        cout << "hurted" << endl;
        nLifeValue -= nPower;
    }
    void FightBack(CWolf *pWolf)
    {
        cout << "fightback wold" << endl;
        pWolf->Hurted(nPower / 2);
    }
    void FightBack(CGhost *pGhost)
    {
        cout << "fightback ghost" << endl;
        pGhost->Hurted(nPower / 2);
    }
};
*/
//总结  n个怪物就有n个Attack 如果新添加一个怪物 修改代码工作量大

//多态的实现方法
class CCreature
{
protected:
    int m_nPower;     //攻击力
    int m_nLifeValue; //生命值
public:
    virtual void Attack(CCreature *pCreature) {}
    virtual void Hurted(int nPower) {}
    virtual void FigthtBack(CCreature *pCreature) {}
};

class CDragon : public CCreature
{
public:
    virtual void Attack(CCreature *pCreature);
    virtual void Hurted(int nPower);
    virtual void FigthtBack(CCreature *pCreature);
};
void CDragon::Attack(CCreature *p)
{
    cout << "attack" << endl;
    p->Hurted(m_nPower);
    p->FigthtBack(this);
}
void CDragon::Hurted(int nPower)
{
    cout << "hurted" << endl;
    m_nLifeValue -= nPower;
}
void CDragon::FigthtBack(CCreature *p)
{
    cout << "figthback" << endl;
    p->Hurted(m_nPower / 2);
}
class CWolf
{
};
class CGhost
{
};
class CBird
{
};
//增加一个怪物Bird不需要改动以上代码
int main()
{
    CDragon Dargon;
    CWolf Wolf;
    CGhost Ghost;
    CBird Bird;
    Dargon.Attack(&Wolf);  //形参是基类的指针 实参是派生类的对象
    Dargon.Attack(&Ghost);
    Dargon.Attack(&Bird);
}

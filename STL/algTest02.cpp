#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
class CLessThen9{
    public:
        bool operator()(int n){return n<9;}
};
void outputSquare(int value){cout << value*value<<",";}
int calculateCube(int value){return value*value*value;}
int main(){
    const int SIZE = 10;
    int a1[] = {1,2,3,4,5,6,7,8,9,10};
    int a2[] = {100,2,8,1,50,3,8,9,10,2};
    vector<int> v(a1,a1+SIZE);
    ostream_iterator<int> output(cout," "); 
    random_shuffle(v.begin(),v.end());
    cout << endl <<"1) ";
    copy(v.begin(),v.end(),output);   //功能类似于 输出
    copy(a2,a2+SIZE,v.begin());
    cout << endl << "2) ";
    cout << count(v.begin(),v.end(),8);
    cout << endl <<"3) ";
    cout << count_if(v.begin(),v.end(),CLessThen9());

    cout << endl << "4) ";
    cout << *(min_element(v.begin(),v.end()));
    cout << endl << "5) ";
    cout << *(max_element(v.begin(),v.end()));
    cout << endl << "6) ";
    cout << accumulate(v.begin(),v.end(),0); //求和

    cout << endl << "7) ";
    for_each(v.begin(),v.end(),outputSquare); //a2求平方
    vector<int> cubes(SIZE);
    transform(a1,a1+SIZE,cubes.begin(),calculateCube); //a1的立方
    cout << endl << "8) ";
    copy(cubes.begin(),cubes.end(),output);    


    system("pause");
    return 0;
}
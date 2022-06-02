#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <iterator>
using namespace std;

int main(){
    int a[] = {8,7,10};
    list<int> ls(a,a+3);

    while(next_permutation(ls.begin(),ls.end())){
        list<int>::iterator i;
        for(i = ls.begin();i != ls.end();++i)
            cout << *i << " ";
        cout << endl;
    }

    system("pause");
    return 0;
}
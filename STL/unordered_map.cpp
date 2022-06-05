#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
//无序容器(哈希表) (cpp11)
int main(){
    unordered_map<string,int> turingWinner;
    turingWinner.insert(make_pair("Dijkstra",1972));
    turingWinner.insert(make_pair("Scott",1976));
    turingWinner.insert(make_pair("Wilkes",1967));
    turingWinner.insert(make_pair("Hamming",1968));
    turingWinner["Ritchie"] = 1983;
    string name;
    cin >> name;
    unordered_map<string,int>::iterator p =turingWinner.find(name);
    if(p!=turingWinner.end())
        cout << p-> second << endl;
    else   
        cout << "Not found" << endl;
        
    system("pause");
    return 0;
}
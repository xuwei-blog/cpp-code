#include <iostream>
#include <iomanip>
using namespace std;
/*流操纵算子
- 整数流算子dec、oct、hex、setbase
- 浮点数的精度（precision、setprecision）
- 设置域宽（setw，width）
- 使用流操纵算子需要头文件iomanip
*/

/*整数流算子
int main(){
    int n = 10;
    cout << n << endl;
    cout << hex << n << "\n"  //以16进制输出
         << dec << n << "\n"  //以10进制输出
         << oct << n << endl;
    
    system("pause");
    return 0;
}
*/

/*浮点数精度
precision是成员函数，调用方式为：
    cout.precision(5)
setprecision是流操作算子，其调用方式为：
    cout << setprecision(5);   //可以连续输出
以上两个功能相同
    指定输出浮点数的有效位数（非定点方式输出时）
    指定输出浮点数的小数点后的有效位数（定点方式输出时：【小数点一定在个位数右边】）
    定点方式：小数点必须出现在个位数后面

//setprecision   
int main(){
    double x = 1234567.89;
    double y = 12.34567;
    int n = 1234567;
    int m = 12;
    cout << setprecision(6) << x << endl  //科学计数法 表示6位有效位数
         << y << endl  //保留6位 四舍五入
         << n << endl  //整数不受影响
         << m;

    system("pause");
    return 0;
}

//setiosflags设置定点数方式输出
int main(){
    double x = 1234567.89;
    double y = 12.34567;
    int n = 1234567;
    int m = 12;
    cout << setiosflags(ios::fixed) << setprecision(6) //以定点数的方式输出
         << x << endl  //小数点后6位有效位数
         << y << endl  //保留6位小数 不够补0
         << n << endl  //整数不受影响
         << m 
         << resetiosflags(ios::fixed) //取消定点数的方式
         << x;

    system("pause");
    return 0;
}
*/

/*设置域宽
1.宽度设置有效性是一次性的，每次读入和输出之前都要设置宽度

方法1：
    cin >> setw(4)
    cout >> setw(4)

方法2：
    cin.width(5)
    cout.width(5)

//输出域宽
int main(){
    int w = 4;
    char string[10];
    cin.width(5);
    while(cin >> string){
        cout.width(w++);
        cout << string << endl;
        cin.width(5);
    }
    system("pause");
    return 0;
}
*/

/*综合案例
1.操纵流算子：fix、scientific、showpos...

int main(){
    int n = 141;
    // 1) 分别以16进制、10进制、8进制先后输出n
    cout << "1) " << hex << n << " " << dec << n << " " << oct << n << endl;
    double x = 1234567.89 , y = 12.34567;
    // 2） 保留5位有效数字
    cout << "2) " << setprecision(5) << x << " " << y << " " << endl;
    // 3） 保留小数点后面5位
    cout << "3) " << fixed << setprecision(5) << x << " " << y << endl;
    // 4） 科学计数法输出，且保留小数点后面5位
    cout << "4) " << scientific << setprecision(5) << x << " " << y << endl;
    // 5) 非负数要显示正号，输出宽度为12字符，宽度不足则用‘*’填补
    cout << "5) " << showpos << fixed << setw(12) << setfill('*') << 12.1 << endl;
    // 6） 非负数不显示正号，输出宽度为12字符，宽度不足则右 12.1 << endl;
    // 7） 输出宽度为12字符，宽度不足则用填充字符填充边用填充字符填充
    cout << "6) " << noshowpos << setw(12) << left <<
    cout << "7) " << setw(12) << right << 12.1 << endl;
    // 8） 宽度不足时，负号和数值分列左右，中间用填充字符填充
    cout << "8) " << setw(12) << internal << -12.1 << endl;

    cout << "9) " << 12.1 << endl;  
    system("pause");
    return 0;
} 
*/

/*自定义流操纵算子
ostream &tab(ostream &output){
    return output << 't' ;
}
int main(){
    cout << "aa" << tab << "bb" <<endl;  //输出：aa    bb
}

原理：
    ostream & operator << (ostream & (*p)(ostream &));

    因为cout << tab 左移时会通过函数指针调用tab
*/




#include <iostream>
#include <limits>
#include <iomanip>
#include <cstdint>
#include <memory>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    


cout << "--1. Simple Variables--\n" << endl;


cout << left << setprecision(15);

cout << "\nc plus plus veri tipleri ornek tablosu\n\n";

cout << setw(10) << "tip"
     << setw(17) << "deger"
     << setw(11) << "boyut"
     << setw(24) << "min deger"
     << setw(30) << "max deger"  << " "
     << endl;

int a = 890;
float f = 2.7f;
double d = 9.25;
char c = 'M';
bool b = true;

cout << setw(10) << "int"
     << setw(18) <<  a
     << setw(9) << sizeof(int)
     << setw(25) << numeric_limits<int>::min()
     << setw(30) << numeric_limits<int>::max() <<endl;

cout << setw(10) << "float"
     << setw(18) << f
     << setw(10) << sizeof(float)
     << setw(24) << numeric_limits<float>::min()
     << setw(30) << numeric_limits<float>::max() <<endl;


cout << setw(10) << "double" 
     << setw(18) << d
     << setw(10) << sizeof(double)
     << setw(24) << numeric_limits<double>::min()
     << setw(30) << numeric_limits<double>::max() <<endl;


cout << left
     << setw(10) << "char"
     << setw(18) << c
     << setw(9) << sizeof(char)
     << setw(25) << int(numeric_limits<char>::min())
     << setw(30) << int(numeric_limits<char>::max())
     << endl;


cout << setw(10) << "bool"
     << setw(18) << b
     << setw(10) << sizeof(bool)
     << setw(24) << numeric_limits<bool>::min()
     << setw(30) << numeric_limits<bool>::max() <<endl;



cout << "\n\nASCII code for char 'c'" << ":  " << c <<int(c)<<endl;


cout << "\n-float vs double precision-\n";
float ff = 1.0 / 3.0;
double dd = 1.0 / 3.0;

cout << setprecision(10);
cout << "float (1/3) = " << ff << endl;
cout << setprecision(20);
cout << "double (1/3) = " << dd << endl;


cout << "\n-bool logic-\n";

bool b1 = true;
bool b2 = false;

cout << "true = " << b1 << endl;
cout << "false = " << b2 << endl;

cout << "true && false = " << (b1 && b2) << endl;
cout << "true || false = " << (b1 || b2) << endl;
cout << "!true =" << !b1 << endl;
cout << "!false =" << !b2 << endl;
cout << "5 > 3 =" << (5 > 3) << endl;
cout << "5 == 10 =" << (5 == 10) << endl;

cout << "\n-32 bit int, 16 bit int, 8 bit int-" << endl;
cout << "\n";
int8_t i8 = 127;
int16_t i16 = 32767;
int32_t i32 = 2147483647;

cout << "int8_t max = " << +numeric_limits<int8_t>::max()
     << ", min = " << +numeric_limits<int8_t>::min() <<endl;

cout << "int16_t max = " << numeric_limits<int16_t>::max()
     << ", min = " << numeric_limits<int16_t>::min() << endl;

cout << "int32_t max = " << numeric_limits<int32_t>::max()
     << ", min = " << numeric_limits<int32_t>::min() << endl;


cout << "\n -signed vs unsigned integers- \n" << endl;
signed int si = -10;
unsigned int ui = 10;

cout << "signed int  = " << si 
     << " (min=" << numeric_limits<int>::min()
     << "  max=" << numeric_limits<int>::max() << ")\n";

cout << "unsigned int = " << ui << " (min=" << numeric_limits<unsigned int>::min()
     <<", max=" << numeric_limits<unsigned int>::max() << ")\n";


cout << "\n\n--2. Variables and Storage Duration--" << endl;



cout << "\n-auto keyword and type deduction.-\n" << endl;
auto value1 = "47474f";
auto value2 = "abcdefgh";
auto value3 = "6,7";
std::cout << value1 << std::endl;
std::cout << value2 << std::endl;
std::cout << value3 << std::endl;


cout << "\n-const keyword and immutable variables-" << endl;

const int SpeedLimit = 50;
cout << "\nSpeedLimit: " << SpeedLimit << endl;


cout << "\n-constexpr keyword and compile-time constants-" << endl;
constexpr int z = 100;
cout << "int z = " << z << endl;


cout << "\n-lvalue vs. rvalue-\n\n";
 
int x = 7;
int y= x + 3;

std::cout << x << ": lvalue" << endl;
std::cout << y << ": rvalue (x + 3)" << endl;


cout << "\n--3. Intro to Pointers--\n";




int k = 10;
int* poi = &k;
cout << "k degeri: " << k << endl;
cout << "k adresi: " << &k << endl;
cout << "pointer'in icindeki adres: " << poi << endl;
cout << "pointer'in gosterdigi deger: " << *poi << endl; 

//modifying the pointer
*poi = 100;
cout << "yeni k degeri: " << k << endl;

//dereferencing and pointer arithmetic (arrays).
int arr[3] = {6, 7, 8};
int* p = arr;

cout << "1. eleman:" << *p << endl;
cout << "2. eleman:" << *(p+1) << endl;
cout << "3. eleman:" << *(p+2) << endl;


//nullptr
int* np = nullptr;
if (np == nullptr) {
     cout << "np pointer bir adres gostermiyor." << endl;
}


//smart pointers

unique_ptr <int> up = make_unique<int>(37);

cout << *up << endl;

unique_ptr<int> v = std::move(up);
cout << *v << endl;




shared_ptr<int> sp = make_shared<int>(90);
weak_ptr<int> wp = sp;

cout << "weak_ptr olusturuldu, referans sayisi: "
     << sp.use_count() << endl;

if (auto temp = wp.lock()) {
     cout << "nesne still exists: " << *temp << endl;
}




cout << "\n\n4. Dynamic Memory Allocation\n" << endl;
int* p1 = new int(12);
cout << "p1 degeri: " << *p1 << endl;
delete p1;

int* dynArr = new int[3];
dynArr[0] = 5;
dynArr[1] = 10;
dynArr[2] = 15;

cout << "dynArr degerleri:"
     << dynArr[0] << ", "
     << dynArr[1] << ", "
     << dynArr[2] << endl;

delete[] dynArr;


int g = 11;
int* p2 = new int;
*p2 = 11;

cout << "p2 degeri: " << *p2 << endl;

delete p2;


cout << "\n\n5.Introduction to Basic Data Structures"  << endl;



cout << "\n\n6.C++ STL Containers (Overview) & . Practical C++ Implementation" << endl;

vector<int> w = {11, 12, 13};
w.push_back(4);
cout << "vector: ";
for (int x1 : w) cout << x1 << " ";
cout << endl;


array<int, 3> arr4 = {20, 30, 40};
cout << "array: " << arr4[0] << ", " << arr4[1] << ", " << arr4[2] << endl;



list<int> lst = {4, 8, 12};
lst.push_front(1);
cout << "list: ";
for (int x2 : lst) cout << x2 << " ";
cout << endl;




stack<int> st;
st.push(200);
st.push(300);
cout << "stack top: " << st.top() << endl;
st.pop();





queue<int> q;
q.push(7);
q.push(8);
cout << "queue front: " << q.front() << endl;
q.pop();



return 0;






}

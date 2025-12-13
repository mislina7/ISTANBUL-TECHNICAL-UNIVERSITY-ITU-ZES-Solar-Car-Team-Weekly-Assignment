#include <iostream>
using namespace std;
double square(double x)
{
return x*x;
}
void print_square(double x)
{
cout << "the square of " << x << " is " << square(x) << "\n";
}
int main()
// hata kodu integer oldugu icin 
{
print_square(5);
return 0;
}

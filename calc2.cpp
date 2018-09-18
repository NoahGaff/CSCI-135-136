// I need more comments?
//

#include <iostream>
using namespace std;

int main ()
{
    int num;
    char oparator;
    
    int sum = 0;
    
    while (cin)
    {
    
    cin >> sum;
    
    while (cin >> oparator)
    {
        cin >> num;
        if (oparator == '-')
        {
            sum -= num;
        }
        else if (oparator == '+')
        {
            sum += num;
        }
        else if (oparator == ';')
        {
            break;
        }
    }
    
    cout << sum;
    
    }
    
    return 0;
}

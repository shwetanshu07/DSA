/*Count of substrings of a binary string containing at least x ones
Example
i/p-> str=101101   x=2	o/p-> 17
Explanation
101, 1011, 10110, 101101, 1011011
011, 0110, 01101, 011011
11, 110, 1101, 11011
101, 1011
011
11 
*/


#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int count_set_bits(string &str, int x){
    int n = str.length();
    deque<char> deq;
    int xcount = 0;
    int total = 0;
    int zeroes = 0;
    for(int i=0; i<n; i++){
        printf("\n ---------------------------------------- \n");
        deq.push_back(str[i]);
        printf("Current char %c \n", str[i]);
        printf("Items in deque:\n");
        for(auto itr=deq.begin(); itr!=deq.end(); itr++) printf("%d ", *itr);
        printf("\n");
        if(str[i]=='1'){
            xcount++;
            printf("Current xcount = %d\n", xcount);
            if(xcount == x){
                // in this case x is 2
                // calculate the total substrings generated using those 1's
                if(deq.front()=='1'){
                    int pos = i;
                    int remaining = n - i - 1;
                    total = total + 1 + remaining;
                    deq.pop_front();
                    printf("The front has 1\n");
                    printf("Substrings using this: %d\n", remaining+1);
                    printf("Total = %d\n", total);
                    printf("Items in deque:\n");
                    for(auto itr=deq.begin(); itr!=deq.end(); itr++) printf("%d ", *itr);
                    printf("\n");
                }
                //printf("\n");
                else{
                    int remaining = n - i - 1;
                    total = total + ((1+remaining)*(zeroes+1));
                    deq.clear();
                    zeroes = 0;
                    deq.push_back(str[i]);
                    printf("The front has 0\n");
                    printf("Substrings using this: %d\n", (1+remaining)*(zeroes+1));
                    printf("Total = %d\n", total);
                    printf("Items in deque:\n");
                    for(auto itr=deq.begin(); itr!=deq.end(); itr++) printf("%d ", *itr);
                }
                printf("\n");
                xcount--;
                printf("Updated xcount = %d\n", xcount);
            }
        }
        if(str[i] == '0'){
            zeroes++;
            printf("Zeroes So far = %d\n", zeroes);
        }
    }
    
    return total;
}


int main(){
    //string str = "1011011";
    string str = "10011001";
    int x = 2;
    int result = count_set_bits(str, x);
    cout<<result;
    return 0;
}

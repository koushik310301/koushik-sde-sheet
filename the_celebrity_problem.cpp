/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

// int findCelebrity(int n) {
//  	// Write your code here.
//     int cel=0;
//     for(int i=1;i<=n;i++){
//         if(knows(cel,i)){
//             cel=i;
//         }
//     }
//     for(int i=1;i<=n;i++){
//         if(i!=cel && (knows(cel,i)==1 || knows(i,cel))) return -1;
//     }
//     return cel;
// }
#include <bits/stdc++.h>
int findCelebrity(int n) {
     // Write your code here.
    stack<int> s;
    for (int i = 0; i < n; i++)
        s.push(i);
        
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (knows(a, b))
            s.push(b);
        else
            s.push(a);
    }
    int potCeleb = s.top();
    bool ansknows = true;
    for (int i = 0; i < n; i++)
    {
        if (i == potCeleb)
            continue;
        if (knows(potCeleb, i) || !(knows(i, potCeleb)))
            ansknows = false;
    }
   if(ansknows) return potCeleb;
    return -1;
}
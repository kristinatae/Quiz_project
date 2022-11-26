#include<bits/stdc++.h>
using namespace std;

int checkpassword(string password) 
{ 
    int n = password.length();      
    bool hasLower = false, hasUpper = false, hasDigit = false; 
    for (int i = 0; i < n; i++) { 
        if (islower(password[i])) 
            hasLower = true; 
        if (isupper(password[i])) 
            hasUpper = true; 
        if (isdigit(password[i])) 
            hasDigit = true; 
    } 
    if ( hasUpper && hasDigit && hasLower && (n >= 5)) // considering a strong must be of length 6 or more
        return 0;
    else {
        return 1;
    }
} 
  
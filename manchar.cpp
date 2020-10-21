#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include <stdio.h> 
#include <string.h> 
  
void manachar(string text) 
{ 
    ll n = text.length(); 
    if(n == 0) 
        return; 
    n = 2*n + 1;  
    ll arr[n];  
    arr[0] = 0,arr[1] = 1; 
    ll cen = 1,rex = 2,i = 0,imirr,ex = -1,diff = -1,maxlps = 0,maxlpscent = 0; 
    ll start = -1,end = -1; 
      
    for (i = 2; i < n; i++)  
    { 
        imirr  = 2*cen-i,ex = 0,diff = rex - i; 
        if(diff >= 0)  
        { 
            if(arr[imirr] < diff) 
                arr[i] = arr[imirr]; 
            else if(arr[imirr] == diff && rex == n-1) 
                arr[i] = arr[imirr]; 
            else if(arr[imirr] == diff && rex < n-1)  
            { 
                    arr[i] = arr[imirr]; 
                    ex = 1;  
            } 
            else if(arr[imirr] > diff)  
            { 
                arr[i] = diff; 
                ex = 1;   
            } 
        } 
        else
        { 
            arr[i] = 0; 
            ex = 1;   
        } 
          
        if (ex == 1) 
        { 
            while (((i + arr[i]) < n && (i - arr[i]) > 0) &&  
                ( ((i + arr[i] + 1) % 2 == 0) ||  
                (text[(i + arr[i] + 1)/2] == text[(i-arr[i]-1)/2] ))) 
            { 
                arr[i]++; 
            } 
        } 
  
        if(arr[i] > maxlps)   
        { 
            maxlps = arr[i]; 
            maxlpscent = i; 
        } 
        if (i + arr[i] > rex)  
        { 
            cen = i; 
            rex = i + arr[i]; 
        } 
    } 
    for(ll i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
    start = (maxlpscent - maxlps)/2; 
    end = start + maxlps - 1; 
    for(i=start; i<=end; i++) 
        cout<<text[i]; 
    cout<<endl;
} 

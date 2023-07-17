#include <bits/stdc++.h>
#include <random>
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define f first
#define s second
#define ll long long
using namespace std;
ll len,i,tong=0,m,luu,n,pos,dem1,dem2,dem0,res=1,maxx,k,x,y,kt,dem,r,l,ma,mua,sl,sl1,freee,cnt,dd[20006];
ll b[6000000];
vector  <vector<ll> > a;
string s,v;
int priority(char s)
{
    if(s=='*') return 2;
    if(s=='+'||s=='-') return 1;
    return 0;
}
bool isnum(char s)
{
    return '0'<=s && s<='9';
}
string infix(string s)
{
    string temp="",res="";
    stack <char> st;
    FOR(i,0,s.length()-1)
    {
        if(isnum(s[i])) temp=temp+s[i];
        else
        {
            if(temp!="") res=res+" "+temp;
            temp="";
            if(s[i]=='(') st.push(s[i]);
            else
                if(s[i]==')')
                {
                    while(!st.empty()&&st.top()!='(') {res=res+" "+st.top(); st.pop();}
                    st.pop();
                }
                else
                {
                    while(!st.empty()&&priority(st.top())>=priority(s[i]))
                        {
                            res=res+" "+st.top();
                            st.pop();
                        }
                    st.push(s[i]);
                }
        }
    }
    if(temp!="") res=res+" "+temp;
    while(!st.empty()) res=res+" "+st.top(),st.pop();
    return res;
}
long long convert_num(string s)
{
    long long d=0;
    FOR(i,0,s.length()-1) d=d*10+s[i]-48;
    return d;
}
string convert_string(long long d)
{
    string ans="";
    while (d>0)
    {
        ans=(char)(d%10+48)+ans;
        d/=10;
    }
    return ans;
}
void count(string s)
{
    stack <string> st;
    string temp="";
    FOR(i,0,s.length()-1)
    {
        if(isnum(s[i])) temp+=s[i];
        else
            if(s[i]!=' ')
            {
                //cout<<temp<<' ';
                if(temp!="") st.push(temp);
                    temp="";
                if(st.size()<2) continue;
                long long num1=convert_num(st.top());
                st.pop();
                long long num2=convert_num(st.top());
                st.pop();
                //cout<<num1<<' '<<num2<<'\n';
                if(s[i]=='*') st.push(convert_string(num1*num2));
                if(s[i]=='+') st.push(convert_string(num1+num2));
                if(s[i]=='-') st.push(convert_string(abs(num1-num2)));
            }
            else
            {
                //cout<<temp<<' ';
                if(temp!="") st.push(temp);
                temp="";
            }
    }
    while(!st.empty()) {cout<<st.top()<<' '; st.pop();}
}
int main()
{
    //freopen("nhap.inp","r",stdin);
    //freopen("nhap.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    //s="(5+9)*6";
    //cout<<convert_num("123")<<' '<<convert_string(123)<<'\n';
    //cout<<infix(s)<<' '<<isnum(' ')<<'\n';
    count(infix(s));
    return 0;
}

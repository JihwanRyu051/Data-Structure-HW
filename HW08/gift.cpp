#include <iostream>
#include <stack>
#include <vector>
#define V vector<int>
#define S stack<int>
#define AT at(ix)
#define VS vector<S>
#define SV stack<V>
#define AP vs,s,p,ix
#define AG vs,v,ix
#define FR(n) for(int i=0;i<n;i++)
#define IN cin>>
#define OUT cout<<
using namespace std;

int pay(VS& vs,V& v,int ix) {return vs.AT.top()*v.AT;}
int ms(VS& vs,int& ix){
    if(ix!=vs.size()-1){
    if(vs.AT.empty()){
    if(ix!=0){return 1;}
    else    return 3;}
    else    return 2;}
    else    return 0;}

void ppv(VS& vc,int& s,int& p,int& ix){
    s -= p;
    vc.AT.pop();
    return;}

void ps(SV sr,int r){
    int c = 0;
    while(!sr.empty()){
    if(++c == r){
    for(auto t: sr.top())
    OUT t+1 <<" ";
    return;}
    sr.pop();}
    OUT "NONE";
    return; }

int main(){
    S b;
    V v;
    SV sr;
    int n,r,g,c,p,mx,m;
    int s=0, ix=0;
    IN n;IN r;
    FR(n){
    IN c;
    s += c;
    v.push_back(c);
    }IN g;
    VS vs(n);
    g=g-s;
    mx=g/v.front();
    FR(mx+1)
    vs.AT.push(i);
    s = 0;
    while(m!=3){
        m = ms(vs,ix);
        switch(m){
        case 1:{
            ix--;
            p=pay(AG);ppv(AP);
            break;}
        case 2:{
            p=pay(AG);
            s+= p;
            ix++;mx=(g-s)/v.AT;
            if(mx<0) mx=0;
            if(ix!=vs.size()-1)
            FR(mx+1)
            vs.AT.push(i);
            else vs.AT.push(mx);
            break;}
        case 0:{
            p=pay(AG);s+=p;
            if(s==g){
            V pkg;
            for(auto b: vs){
            pkg.push_back(b.top());}
            sr.push(pkg);  }
            ppv(AP);ix--;
            p=pay(AG);ppv(AP);
            break;}}}
    ps(sr,r);
    return 0;
}

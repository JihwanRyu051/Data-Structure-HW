#include<bits/stdc++.h>
#define FOR(n,k) for(int i=n;i<k;i++)
#define DFOR(ibegin,iend,jbegin,jend) for(int i=ibegin;i<iend;i++)for(int j=jbegin;j<jend;j++)
#define V vector
using namespace std;

struct Node{
Node*sub[4];
char bit;
};

Node*newNode(char data){
Node*temp=new Node();
temp->bit=data;
FOR(0,4)temp->sub[i]=NULL;
return temp;
}

void readQTS(Node*&root){
char data;
cin>>data;
if(data==')')return;
else if(data=='(')root=newNode('r');
else root=newNode(data);

if(root->bit=='r'){
FOR(0,4)readQTS(root->sub[i]);
readQTS(root);}
}

void setRange(int cBegin,int cEnd,int rBegin,int rEnd,int range[][2]){
range[0][0]=cBegin;
range[0][1]=cEnd;
range[1][0]=rBegin;
range[1][1]=rEnd;
}

void setBound(int bound[][2],int range[][2]){
DFOR(0,2,0,2)bound[i][j]+=range[i][j];
}

void decodeQTS(Node*root,int numRow,V<V<char >>&IMG,int range[][2]){
if(root->bit=='r'){
FOR(0,4){
int bound[2][2];
switch(i){
case 0:setRange(numRow/2,0,0,-numRow/2,bound);break;
case 1:setRange(0,-numRow/2,0,-numRow/2,bound);break;
case 2:setRange(0,-numRow/2,numRow/2,0,bound);break;
case 3:setRange(numRow/2,0,numRow/2,0,bound);}
setBound(bound,range);
decodeQTS(root->sub[i],numRow/2,IMG,bound);}
}
else DFOR(range[1][0],range[1][1],range[0][0],range[0][1])
IMG.at(i).at(j)=root->bit;
}

void outIMG(V<V<char >>IMG){
for(auto row:IMG){
for(auto c:row)cout<<c; cout<<endl;}
}

void splitIMG(V<V<char >>IMG,V<V<char >>&bound,int range[][2]){
int  brow=0,bcol=0;
DFOR(range[1][0],range[1][1],range[0][0],range[0][1]){
bound.at(brow).at(bcol++)=IMG.at(i).at(j);
if(j==range[0][1]-1){brow++;bcol=0;}}
}

void readIMG(V<V<char >>&IMG){
for(auto&str:IMG)
for(auto&c:str)cin>>c;
}

void incodeIMG(V<V<char >>&IMG,string&out){

int  numRow=IMG.size();
if(numRow==1){
out+=IMG.front().front();
return;}

string bout="(";
V<V<char >>bound(numRow/2,V<char >(numRow/2));
FOR(0,4){
int brange[2][2];
switch(i){
case 0:setRange(numRow/2,numRow,0,numRow/2,brange);break;
case 1:setRange(0,numRow/2,0,numRow/2,brange);break;
case 2:setRange(0,numRow/2,numRow/2,numRow,brange);break;
case 3:setRange(numRow/2,numRow,numRow/2,numRow,brange);}
splitIMG(IMG,bound,brange);
incodeIMG(bound,bout);}
bout+=')';
if(bout=="(1111)")bout="1";
if(bout=="(0000)")bout="0";
out+=bout;
}

void runQTS(Node*root,int  numRow,V<V<char >>IMG,int  range[][2]){
readQTS(root);
decodeQTS(root,numRow,IMG,range);
outIMG(IMG);}

void runIMG(V<V<char >>IMG,string outQTS){
readIMG(IMG);
incodeIMG(IMG,outQTS);
cout<<outQTS;}

int main(){
int range[2][2];
int dim,select,numRow;
string tool,outQTS="";
V<string>tBox={"QTS","IMG"};
Node*root=NULL;

cin>>dim>>tool;

numRow=pow(2,dim);
setRange(0,numRow,0,numRow,range);

V<V<char >>IMG(numRow,V<char >(numRow));

select=find(tBox.begin(),tBox.end(),tool)-tBox.begin();

switch(select){
case 0:runQTS(root,numRow,IMG,range);break;
case 1:runIMG(IMG,outQTS);break;}

return 0;
}

#include <bits/stdc++.h>

using namespace std;

int porder(string inorder, string& pord, int pindex, string& out, int mode){
    string root;
    string left, right, reorder, msg = "", psub;

    switch(mode){
    case 0:
        root = pord.at(pindex);
        msg = root;
        break;
    default:
        root = pord.back();
        if(out.find(root) == -1) cout << root;
        out += root;
        break;
    }

    int fnd = inorder.find(root);

    if(fnd != 0)                  left = inorder.substr(0, fnd);

    if(fnd != inorder.length()-1) right = inorder.substr(fnd+1);

    if(!left.empty())             reorder = left;

    else if(!right.empty())       reorder = right;

    else                         {cout << msg;   return pindex; }

    if(!mode) pindex = porder(reorder, pord, pindex+1, out, mode);
    else     {psub = pord.substr(0, reorder.length());
              porder(reorder, psub, pindex, out, mode); }

    fnd = inorder.find(reorder);
    inorder.erase(fnd, reorder.length());

    if(!mode) pord.erase(pord.begin()+pindex);
    else      pord.erase(0, reorder.length());

    return porder(inorder, pord, --pindex, out, mode);
}


int main()
{
    int mode;
    string key, pord, out = "";
    map<string, string> order, pout;

    pout["Preorder" ]  = "Postorder ";
    pout["Postorder"] = "Preorder " ;

    for(int i=0; i<4; i++){
        if(i%2)  cin >> order[key];
        else    {cin >> key;
                 if(key != "Inorder") pord = key; }
    }

    cout << pout[pord];
    if(pord == "Preorder")  mode = 0;
    else                   mode = 1;

    porder(order["Inorder"], order[pord], 0, out, mode);

    return 0;
}

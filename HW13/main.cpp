#include <bits/stdc++.h>

using namespace std;

int postorder(string inorder, string& preorder, int pindex){
    string left, right, reorder;

    char root = preorder.at(pindex);
    int fnd = inorder.find(root);

    if(fnd != 0)
        left = inorder.substr(0, fnd);

    if(fnd != inorder.length()-1)
        right = inorder.substr(fnd+1);

    if(!left.empty())
        reorder = left;

    else if(!right.empty())
        reorder = right;

    else{
        cout << root;
        return pindex;
    }

    pindex = postorder(reorder, preorder, pindex+1);

    fnd = inorder.find(reorder);
    inorder.erase(fnd, reorder.length());
    preorder.erase(preorder.begin()+pindex);

    return postorder(inorder, preorder, --pindex);
}

int preorder(string inorder, string postorder, string& out){

    string left, right, reorder;

    char root = postorder.back();

    if(out.find(root) == -1)
        cout << root;

    out += root;

    int fnd = inorder.find(root);

    if(fnd != 0)
        left = inorder.substr(0, fnd);

    if(fnd != inorder.length()-1)
        right = inorder.substr(fnd+1);

    if(!left.empty())
        reorder = left;

    else if(!right.empty())
        reorder = right;

    else return 0;


    preorder(reorder, postorder.substr(0, reorder.length()), out);

    fnd = inorder.find(reorder);
    inorder.erase(fnd, reorder.length());
    postorder.erase(0, reorder.length());

    return preorder(inorder, postorder, out);
}

void porder(map<string, string> order, string pord){

    if(pord == "Preorder"){
        cout << "Postorder: ";
        postorder(order["Inorder"], order[pord], 0);
    }
    else{
        string out = "";
        cout << "Preorder: ";
        preorder(order["Inorder"], order[pord], out);
    }
}


int main()
{
    string key, pord;
    map<string, string> order;

    for(int i=0; i<4; i++){
        if(i%2)
            cin >> order[key];
        else{
            cin >> key;
            if(key != "Inorder")
                pord = key;
        }
    }
    porder(order, pord);

    return 0;
}

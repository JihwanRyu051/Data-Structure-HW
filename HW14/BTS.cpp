#include <bits/stdc++.h>

using namespace std;

struct Node{
    string data;
    struct Node *left, *right;
};

Node* newNode(string data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void minusNode(Node* &root, string input);

void plusNode (Node* &root, string input){
    if(!root){ root = newNode(input); return; }

    if(root->data.compare(input)>0) plusNode(root->left,  input);
    else                            plusNode(root->right, input);
}

void right(Node* &root, string& temp){
    if(!root) return;
    if(!root->right){
        temp = root->data;
        minusNode(root, root->data);
        return;
    }
    right(root->right, temp);
}

void minusNode(Node* &root, string input){
    if(!root) return;
    if(root->data == input){
        string temp;
        right(root->left, temp = "NONE");
        if(temp == "NONE") root       = root->right;
        else              root->data = temp;
        return;            }
    minusNode(root->left,  input);
    minusNode(root->right, input);
}

void leaf(Node* root){
    if(!root) return;
    leaf(root-> left );
    if(!root->left && !root->right) cout << root->data << " ";
    leaf(root-> right);
}

void depth(Node* root, int& dep, int& out){
    if(!root) return;
    dep--;
    if(!dep)    { cout<<root->data<< " "; out++; }
    depth(root->left , dep, out);
    depth(root->right, dep, out);
    dep++;
}

int main()
{
    int loop, index, dep, out;
    string query, input;
    vector<string> toolBox = { "+", "-", "depth",  "leaf"};

    Node* root = NULL;

    cin         >> loop;

    for(int i=0;i<loop;i++){
        cin     >> query;
        index = find(toolBox.begin(), toolBox.end(), query) - toolBox.begin();
        switch(index){
        case 0:
            cin >> input;
            plusNode (root, input);
            break;
        case 1:
            cin >>input;
            minusNode(root, input);
            break;
        case 2:
            cin >> dep;
            depth(root, dep, out=0);
            if(!out) cout << "NO";
            cout          << endl;
            break;
        case 3:
            leaf(root);
            cout          << endl;
            break;
        default:
            cout<<"Error!!"<< endl;
            break;
        }
    }
    return 0;
}

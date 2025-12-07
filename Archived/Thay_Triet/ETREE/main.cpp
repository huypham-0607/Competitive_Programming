#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

struct Node{
    Node(int iNodeType, string sOp, int iValue, int iLevel, Node *pleft, Node *pright){
        nodetype = iNodeType ;
        op = sOp;
        val = iValue;
        level = iLevel;
        l = pleft;
        r = pright;
    }
    bool nodetype;
    string op;
    int val;
    int level;
    Node *l,*r;
}
stack<Node> opr,nod;
Node *t = NULL,*p = NULL;
Node n;
int l;
string c;

int level(string s){
    if (s == "(")
        return 4;
    else if (s == ")")
        return 3;
    else if (s=="*" || s=="/" || s=="%" || s=="^")
        return 2;
    else if (s=="+" || s =="-")
        return 1;
    else return 0;
}

void stree(){
    Node o = (Node) opr.top();
    opr.pop();
    Node *n1 = new Node;
    Node *n2 = new Node;
    *n2 = nod.top();
    nod.pop();
    *n1 = nod.top();
    nod.pop();
    o.l =n1;
    o.r =n2;
    nod.push(o);
}

void duyetInfix(Node * root){

    if(root->l != NULL)
        duyetInfix(root->l);
    if(root->nodetype == 0)
        cout<< root->op;
    else
        cout<< root->val;
    if(root->r != NULL)
        duyetInfix(root->r);
}

int main()
{
    freopen("ETREE.INP","r",stdin);
    freopen("ETREE.OUT","w",stdout);
    while (cin >> c){
        l=level(c);
        if (l == 4){
            n = (false,c,0,l,NULL,NULL);
            opr.push(n);
        }
        else if (l == 3){
            n = opr.top();
            while (n.op != "("){
                stree();
                n=opr.top();
            }
            opr.pop();
        }
        else if (l == 2 || l==1){
            if (!opr.empty()){
                n = opr.top();
                while (!opr.empty() && n.op != "(" && node.level >= l){
                    stree();
                    n=opr.top();
                }
            }
            Node newop(false,c,0,l,NULL,NULL);
            opr.push(newop);
        }
        else if (l==0){
            n = (true,"",stoi(c),l,NULL,NULL);
            nod.push(n);
        }
        cin >> c;
    }
    while(!opr.empty()){
        stree();
    }
    duyetInfix(nod.top());
    return 0;
}

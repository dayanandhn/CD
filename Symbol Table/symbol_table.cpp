#include<bits/stdc++.h>

using namespace std;
class Symbol
{
    public:
    string id;
    string attr;
    Symbol *next;
    Symbol()
    {
        next = NULL;
    }
};

int id_search(Symbol* head, string key)
{
    int ct = 0;
    Symbol* current = head;
    while (current != NULL && current->id != key)
    {
        ct+=1;
        current = current->next;
    }
    return ct;
}

int id_exist(Symbol* head, string key)
{
    Symbol* current = head;
    while (current != NULL)
    {
        if(current->id == key)
            return 1;
        current = current->next;
    }
    return 0;
}

void insertt(Symbol **head_ptr, string ids, string attrs)
{
    Symbol *new_node = new Symbol();
    Symbol *last = *head_ptr;
    int exist = 0;
    exist = id_exist(last, ids);
    if(exist==1)
        return;
    new_node->id = ids;
    new_node->attr = attrs;
    if(*head_ptr == NULL)
    {
        *head_ptr = new_node;
        return;
    }
    while(last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

void display(Symbol *head)
{
    while(head!=NULL)
    {
    cout<<head->id<<'\t'<<head->attr<<endl;
    head = head->next;
    }
}

bool check_op(string value)
{
    string operators[6] = {"*", "/", "+", "-", "%", "="};
    vector<string> op;
    op.insert(op.begin(), begin(operators), end(operators));

    return find(op.begin(), op.end(), value) != op.end();
}

int main()
{
    Symbol *head = NULL;
    string exp;
    cout<<"Input an expression: ";
    getline(cin, exp);
    stringstream ss(exp);
    string token;
    int num;
    while(ss >> token)
    {
        if(stringstream(token)>>num)
            continue;
        if(!check_op(token))
            insertt(&head, token, "id");
    }

    istringstream s1(exp);

    while(s1 >> token)
    {
        int id_no;
        id_no = -1;
        id_no = id_search(head, token);
        if(stringstream(token)>>num)
            cout<<"<"<<token<<"> ";
        else if(id_no+1>0 && !check_op(token))
            cout<<"<id,"<<id_no+1<<"> ";
        else cout<<"<"<<token<<"> ";
    }
    cout<<"\n\n===Symbol Table===\n\n";
    display(head);
}

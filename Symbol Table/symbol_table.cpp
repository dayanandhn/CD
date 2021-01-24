#include<bits/stdc++.h>

using namespace std;
// Symbol class represents a symbol and its attribute
class Symbol
{
    public:
    string id;
    string attr;
    Symbol *next; // points to next symbol
    Symbol() //constructor for initializing the next pointer to null
    {
        next = NULL;
    }
};

//To search an symbol in the table with its entry number in the table
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

//To check if the symbol exist in the table (linked list)
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

// Insertt function appends the new nde with value to the given list
void insertt(Symbol **head_ptr, string ids, string attrs)
{
    Symbol *new_node = new Symbol();
    Symbol *last = *head_ptr;
    int exist = 0; // To check whether the symbol already exist or not
    exist = id_exist(last, ids);
    if(exist==1) //if exist return without appending
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

//disply the symbols in the table(list)
void display(Symbol *head)
{
    while(head!=NULL)
    {
    cout<<head->id<<'\t'<<head->attr<<endl;
    head = head->next;
    }
}

//TO check whether the passed string is an operator
bool check_op(string value)
{
    string operators[6] = {"*", "/", "+", "-", "%", "="};
    vector<string> op; // Operators array is vectorised
    op.insert(op.begin(), begin(operators), end(operators)); //insert the values into the list using iterators

    return find(op.begin(), op.end(), value) != op.end();//returns true or false
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
        if(stringstream(token)>>num)//if number, continue numbers are not identifiers
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

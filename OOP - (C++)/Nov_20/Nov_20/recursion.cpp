//**********NEVER USER RECURSIVE FUNCTION for developing************
struct Node{
    int data;
    Node* a;
    Node* b;
    Node(int r) : data(r), a(0), b(0) {}
};

class Tree{
private:
    Node* root;

public:
    Tree() : root(0) {}
    void push(int a){
        //auto n = new Node(a);
        findNew(root) = new Node(a);
    }
    // pass our root node and checks whatever root is passed checks if is null or not.. 
    //also check if a is not null and returns findnew b else findnew a
    Node*& findNew(Node*& a){
        if(!a)
            return a; // base case..
        if(a->a)
            return findNew(a->b);
        else
            return findNew(a->a);
    }
};


// this will call the function until crashes because the Stack doesnt has anymore space.. 
int addTen(int a){
    return addTen(a) + 10;
}

int main(){

    //addTen(3); //add a break to make it work..
    Tree a;
    int i = 100;
    while (i--)
        a.push(i);
}
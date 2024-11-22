


#include <iostream>
#include "../libclasse/classepila/Pila.hpp"

Pila operator!(Pila p){
    Pila q;
    bool flip = true;
    while( !(p.IsEmpty()) ){
        if(flip){
            p.Pop();
        }
        else{
            q.Push(p.Top());
            p.Pop();
        }
        flip = !flip;
    }
    return q;
}

void read_pila(std::string s, Pila& p){
    int i = 1;
    int start = 1;
    while (s[i] != ')'){
        if(s[i] == ','){
            p.Push(std::stoi(s.substr(start, i - 1)));
            i += 2;
            start = i;
        }
        else if(s[i + 1] == ')'){
            p.Push(std::stoi(s.substr(start, i)));
            i++;
        }
        else
            i++;
    }
}



class B{
    public:
    B(int n) { num = n; }
    void Set(int n) { num = n; }
    int Get() const { return num; }
    private:
    int num;
};

class A{
    public:
    A(int v = 0) : b(v) { val = v; pb = new B(v); }
    A(const A&);
    ~A();
    void Set1(int h) {
    val = h; }
    void Set2(int h) {
    b.Set(h); }
    void Set3(int h) {
    pb->Set(h); }
    int C1() const { return val; }
    int C2() const { return b.Get(); }
    int C3() const { return pb->Get(); }
    void Flip() { delete pb; pb = &b; }
    void Flop() { pb = new B(val); }
    private:
    int val;
    B* pb;
    B b;
};

// A::A(const A& a) : b(a.C2()) {
//     val = a.val;
//     pb = new B(a.C3());
// }

A::A(const A& a) : b(a.b) {
    val = a.val;
    if (a.pb == &a.b){ // se pb punta a b in a, allora fai puntare a b
        pb = &b;
    }
    else{
        pb = new B(*(a.pb)); //altrimenti nuovo costruttore di copia sulla B puntata da a.pb
    }
}

A::~A(){
    if(pb != &b) // altrimenti cerca di liberare due volte b
        delete pb;
}


namespace std {
        int test(){
        // std::string spila = "(3, 4, 12, 11, 13, 16, 22)";
        // Pila p, q;
        // read_pila(spila, p);
        // std::cout << p << std::endl;
        // q = !p;

        // std::cout << p << "\n" << q << std::endl;

        A a1(2);
        A a2;
        // a2.val = 3;
        a1.Set1(5);
        // a1.C2() += a1.C1();
        a1.Set2(a1.C1() + a2.C2() + 1);
        // a2(5);
        a1.Flip();
        cout << a1.C1() << '/' << a1.C2() << '/' << a1.C3() << endl;

        // a2 = a1;
        A as = a1;
        a2.Set3(16);
        cout << a1.C3() << endl;

        return 0; 
    }
}

int main(){
    std::test();

    return 0;
}





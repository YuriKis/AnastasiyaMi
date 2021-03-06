#include <iostream>

using namespace std;

typedef class sstring{
    int n;
    char* A;

public:

    sstring (int a){
        n=a;
        A=new char[n];
    }


    ~ sstring (){
        delete [] A;
    }

    char get_n(){
        return n;
    }

    char get(int i){
        return A[i];
    }


    void set(int i, char x){
        A[i]=x;
    }

    void print(){
        cout << A;
    }

    bool find(sstring& s){
        if (n<s.get_n()) return 0;
        for(int i=0; i<(n-s.get_n()+1); i++){
                if(A[i]==s.get(0)){
                    for(int q=1; q<s.get_n(); q++){
                        if(A[i+q]!=s.get(q)) break;
                        if((q+1)==s.get_n()) return 1;
                    }
                }

        }
        return 0;
    }

    void concat(sstring& s){
        sstring T(n+s.get_n());
        for(int i=0; i<n; i++) T.set(i, A[i]);
        for(int i=0; i<s.get_n(); i++){
            T.set((n+i), s.get(i));
            }
        n+=s.get_n();
        delete [] A;
        A=new char [n];
        for(int i=0; i<n; i++) A[i]=T.get(i);
    }

}sstring;


int main()
{
    sstring W(6);
    sstring B(4);
    sstring C(7);
    for(int i=0; i<6; i++){
            char t;
            cin >> t;
            W.set(i, t);
    }
    for(int i=0; i<4; i++){
            char t;
            cin >> t;
            B.set(i, t);
    }
    for(int i=0; i<7; i++){
            char t;
            cin >> t;
            C.set(i, t);
    }
    cout << W.get(1) << endl;
    W.print();
    cout << "      ";
    if(W.find(C)==0) cout << "123" << "  .  ";
    W.concat(B);
    W.print();
    cout << "      ";
    if(W.find(B)==1) cout << "456" << "    .    ";
    C.print();
    return 0;
}

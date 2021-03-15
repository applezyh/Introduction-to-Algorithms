#include <iostream>
using namespace std;
class Person{
    public:
        Person(){
            better=0;
            rank=nullptr;
            apt=0;
            f=-1;
        }
        Person(int n){
            better=0;
            rank=new int[n];
            apt=0;
            f=-1;
        }
        ~Person(){
            delete[] rank;
        }
        int getRank(int i){
            return rank[i];
        }
        void setRank(int g,int i){
            rank[i]=g;
        }
        void setApt(bool apt){
            this->apt=apt;
        }
        bool getApt(){
            return apt;
        }
        int getBetter(){
            return better;
        }
        void setBetter(int b){
            better=b;
        }
        void setF(int f){
            this->f=f;
        }
        int getF(){
            return f;
        }
        int better;
        int *rank;
        bool apt;
        int f;

};
int main(){
    int n=0;
    cin>>n;
    Person *man=new Person[n];
    Person *women=new Person[n];
    for(int i=0;i<n;i++){
        man[i].rank=new int[n];
        women[i].rank=new int[n];
    }
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            man[i].setRank(t-1, j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            women[i].setRank(t-1, j);
        }
    }
    while(true){
        int flag=1;
        for(int i=0;i<n;i++){
            if(man[i].getApt()==0){
                flag = 0;
                int num_Y = man[i].getBetter();
                int girl = man[i].getRank(num_Y);
                man[i].setBetter(num_Y + 1);
                if (!women[girl].getApt())
                {
                    man[i].setApt(true);
                    man[i].setF(girl);
                    women[girl].setApt(true);
                    women[girl].setF(i);
                }
                if (women[girl].getApt())
                {
                    int before, now;
                    for (int j = 0; j < n; j++)
                    {
                        if (women[girl].getRank(j) == i)
                        {
                            now = j;
                        }
                        if (women[girl].getRank(j) == women[girl].getF())
                        {
                            before = j;
                        }
                    }
                    if (before < now)
                    {

                    }
                    else if (before>now)
                    {
                        man[women[girl].getF()].setApt(false);
                        man[women[girl].getF()].setF(100);
                        man[i].setApt(true);
                        man[i].setF(girl);
                        women[girl].setF(i);
                    }
                }
            }
        }
        if(flag==1)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        cout << man[i].getF()+1;
        if(i!=n-1)
            cout<<' ';
    }
}
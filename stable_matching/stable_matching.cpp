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
    cout<<"请输入待匹配的人数:"<<endl;
    cin>>n;
    Person *man=new Person[n];
    Person *lady=new Person[n];
    for(int i=0;i<n;i++){
        man[i].rank=new int[n];
        lady[i].rank=new int[n];
    }
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t;
            cout << "请输入第" << i+1 << "个男人喜欢的第" << j+1 << "个女人:";
            cin >> t;
            man[i].setRank(t-1, j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t;
            cout << "请输入第" << i+1 << "个女人喜欢的第" << j+1 << "个男人:";
            cin >> t;
            lady[i].setRank(t-1, j);
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
                if (!lady[girl].getApt())
                {
                    man[i].setApt(true);
                    man[i].setF(girl);
                    lady[girl].setApt(true);
                    lady[girl].setF(i);
                }
                if (lady[girl].getApt())
                {
                    int before, now;
                    for (int j = 0; j < n; j++)
                    {
                        if (lady[girl].getRank(j) == i)
                        {
                            now = j;
                        }
                        if (lady[girl].getRank(j) == lady[girl].getF())
                        {
                            before = j;
                        }
                    }
                    if (before < now)
                    {

                    }
                    else if (before>now)
                    {
                        man[lady[girl].getF()].setApt(false);
                        man[lady[girl].getF()].setF(100);
                        man[i].setApt(true);
                        man[i].setF(girl);
                        lady[girl].setF(i);
                    }
                }
            }
        }
        if(flag==1)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        cout << i+1 << "和" << man[i].getF()+1 << "在一起" << endl;
    }
}
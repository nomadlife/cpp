#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main(){
    ifstream klfile;
    klfile.open("p079_keylog.txt");
    vector<string> keys;
    string str;
    while (getline(klfile,str))
        keys.push_back(str);
    long key = 123;
    int i = 0;
    while (i<50){
        string sk = to_string(key);
        int sksize = sk.size();
        for (i=0;i<50; i++){
            int ki = 0;
            for (int j=0; j<sksize && ki<3; j++)
               if (sk[j] == keys[i][ki])
                   ki++;
            if (ki != 3)
                break;
        }
        key++;
    }
    cout<<key-1<<endl;
    klfile.close();
    return 0;
}
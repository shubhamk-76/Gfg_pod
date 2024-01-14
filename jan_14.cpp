//Find duplicate rows in a binary matrix
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
{ 
// Your code here
vector<int>al;
unordered_set<int>un;
int num = 0;
for(int i=0;i<M;i++){
num=0;
for(int j=0;j<N;j++){
num+=(matrix[i][j]<<j);
}
if(un.find(num)!=un.end()){
al.push_back(i);
}else{
 un.insert(num);
}
}
return al;
}
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int row,col;
        cin>>row>>col;
        vector<vector<int>>matrix(row);
        for(int i=0;i<row;i++){
            matrix[i].assign(col,0);
            for(int j=0;j<col;j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        vector<int>ans=ob.repeatedRows(matrix,row,col);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}



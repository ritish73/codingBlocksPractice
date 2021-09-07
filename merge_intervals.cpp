
#include<bits/stdc++.h>
using namespace std;
bool cmp( vector<int>& v1, vector<int>& v2){
    return v1[0]<v2[0];
}
void merge(vector<vector<int>>& intervals) {
    // return vector<vector<int>>(2,vector<int>(2,0)); vector initialization
    // sort the vector using comparator function cmp
    sort(intervals.begin(), intervals.end(), cmp);
    
    // print the 2d vector
    for(int i=0; i<intervals.size(); i++){
        cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
    }
    
    
    // overlapping logic
    for(int i=0; i<intervals.size()-1;i++){
        int j=i+1;





        cout<<"i , j : "<<i<<" , "<<j<<endl;




cout<<"at the begin of each iteration intervals is : "<<endl;


 // print the 2d vector
    for(int i=0; i<intervals.size(); i++){
        cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
    }

cout<<"dmnvsdvnskvnsfvksfnvksf"<<endl<<endl;



        if(intervals[j][0] <= intervals[i][1]){
            // case of overlap
            // make new interval
            if(intervals[j][1] <= intervals[i][1]){
                cout<<"just remove"<<endl;
                // remove jth row
                intervals.erase(intervals.begin()+j);
                i--;
            } else {
                cout<<"create new"<<endl;
                vector<int> temp;
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[j][1]);
                intervals.insert(intervals.begin()+i, temp);

                 // print the 2d vector
                 cout<<"....................."<<endl;
                for(int i=0; i<intervals.size(); i++){
                    cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
                }
                cout<<"........................"<<endl;
    cout<<" i and j is : "<<i<<" "<<j<<endl;
                intervals.erase(intervals.begin()+i+1);
                intervals.erase(intervals.begin()+j);
                
            i--;
            }
            
            
        } else {
            cout<<"keep same"<<endl;
            continue;
        }
    }

     // print the 2d vector
    for(int i=0; i<intervals.size(); i++){
        cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
    }

    
}

int main(){
    vector<vector<int>> v = 
                                {{4,5},{2,4},{4,6},{3,4},{0,0},{1,1},{3,5},{2,2} }  ;
    merge(v);
}

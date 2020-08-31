#include<iostream>
#include<vector>

using namespace std;

//subsequences of a string:
vector<string> subs(string str){
    if(str.length()==0){
        vector<string> arr;
        arr.push_back(" ");
        return arr;
    }

    char ch=str[0];
    vector<string> arr=subs(str.substr(1));
    vector<string> ans;
    for(string s:arr){
        ans.push_back(s);
        ans.push_back(ch+s);

    }
    return ans;



}
// good method:gives count of subsequences and 

 int subseq_void(string str,string ans){
        if(str.length()==0){
           cout<<ans<<" ";
            return 1;
        }

        int count=0;

        count+=subseq_void(str.substr(1),ans);
        count+=subseq_void(str.substr(1),ans+ str[0]);
    
        return count;
    }
  vector<string> perms(string str){
      if(str.length()==1){
          vector<string> arr;
          arr.push_back(str);
          return arr;
      }


      char ch=str[0];
      vector<string> arr=perms(str.substr(1));
      vector<string> myans;
      for(string s:arr){
          for(int i=0;i<=s.length();i++){
              myans.push_back(s.substr(0,i)+ch+s.substr(i));

          }
      }
      return myans;

  }  

// a coin can be used infinite times.

int coin_combi(vector<int> arr,int idx,int target,string ans){
    if(target==0 || idx>=arr.size()){
        cout<<ans<<endl;
        return 1;
    }
    


    int count=0;
    for(int i=idx;i<arr.size();i++){
        if(target-arr[i]>=0){
            count+=coin_combi(arr,i,target-arr[i],ans+to_string(arr[i])+" ");
        }
        

    }
    return count;
}
// a coin in combination can only be used once:
int coin_combi_noreps(vector<int> arr,int idx,int target,string ans){
    if(target==0 || idx>=arr.size()){
        if(target==0){
        cout<<ans<<endl;
        return 1;}
    }
    


    int count=0;
    for(int i=idx;i<arr.size();i++){
        if(target-arr[i]>=0){
            count+=coin_combi_noreps(arr,i+1,target-arr[i],ans+to_string(arr[i])+" ");
        }
        

    }
    return count;
}

int coin_permi(vector<int> arr,int idx,int target,string ans){
    if(target==0 || idx>=arr.size()){
        cout<<ans<<endl;
        return 1;
    }
    


    int count=0;
    for(int i=0;i<arr.size();i++){
        if(target-arr[i]>=0){
            count+=coin_permi(arr,0,target-arr[i],ans+to_string(arr[i])+" ");
        }
        

    }
    return count;

}


void coins(){
    // vector<int> arr={2,3,5,7};
    // int target=10;
  // cout<<coin_combi_noreps(arr,0,target,"");
   //cout<<coin_permi(arr,0,target,"");
   vector<string> arr=perms("abc");
   for(string i:arr){
       cout<<i<<" ";
   }
//    string ans="";
//  cout<<subseq_void("abc",ans);

}
int main(int args,char** argv)
{
    coins();

}
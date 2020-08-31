#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void display(vector<int>& arr){
    for(int ele:arr){
        cout<<ele<<" ";
    }
    cout<<endl;
}
void display2D(vector<vector<int>>& arr){
    for(vector<int> ar:arr){
        display(ar);

    }
    cout<<endl;
}
int multimoves(int sr,int sc,int er,int ec,vector<vector<int>>& dp){
    if(sr==er && sc==ec){
        return dp[sr][sc]=1;

    }
    if(dp[sr][sc]!=0){
        return dp[sr][sc];
    }
    int count=0;
    for(int jump=1;jump+sr<=er;jump++){
        count+=multimoves(sr+jump,sc,er,ec,dp);
    }
    for(int jump=1;jump+sc<=ec;jump++){
        count+=multimoves(sr,sc+jump,er,ec,dp);
    }
    for(int jump=1;jump+sr<=er && jump+sc<=ec;jump++){
        count+=multimoves(sr+jump,sc+jump,er,ec,dp);
    }
    return dp[sr][sc]=count;


}
int multimoves_tabs(int sr,int sc,int er,int ec,vector<vector<int>>& dp){
    for(int sr=er;sr>=0;sr--){
        for(int sc=ec;sc>=0;sc--){
            if(sr==er && sc==ec){
         dp[sr][sc]=1;
         continue;

    }
   
    int count=0;
    for(int jump=1;jump+sr<=er;jump++){
        count+=dp[sr+jump][sc];
    }
    for(int jump=1;jump+sc<=ec;jump++){
        count+=dp[sr][sc+jump];
    }
    for(int jump=1;jump+sr<=er && jump+sc<=ec;jump++){
        count+=dp[sr+jump][sc+jump];
    }
    dp[sr][sc]=count;
        }
    }
    return dp[0][0];
}
int diceprob(int sr,int er,vector<int>& dp){
    if(sr==er)
    {
        return dp[sr]=1;
    }
    if(dp[sr]!=0)
    {
        return dp[sr];
    }
    int count=0;
    for(int jump=1;jump+sr<=er && jump<=6;jump++)
    {
        count+=diceprob(sr+jump,er,dp);
    }
    dp[sr]=count;

}
int diceprob_tabs(int sr,int er,vector<int>& dp){
    for(int sr=er;sr>=0;sr--){
        if(sr==er){
        dp[sr]=1;
        continue;
    }
   
    int count=0;
    for(int jump=1;jump+sr<=er && jump<=6;jump++){
        count+=dp[sr+jump];

    }
    dp[sr]=count;

    }
    return dp[0];
}
int diceprob2(int sr,int er,vector<int>& arr,vector<int>& dp){
    if(sr==er){
        return dp[sr]=1;
    }
    if(dp[sr]!=0){
        return dp[sr];
    }
    int count=0;
    for(int jump=0; sr+arr[jump]<=er && jump<arr.size();jump++){
       
        count+=diceprob2(sr+arr[jump],er,arr,dp);
        }

    
    return dp[sr]=count;


}
//////////////////////////////////////////////////////////////////

int friends_pair(int n,vector<int>& dp){
   if(n<=1){
       return dp[n]=1;
   }
   if(dp[n]!=0){
       return dp[n];
   }
   int singleup=friends_pair(n-1,dp);
   int pairup=friends_pair(n-2,dp)*(n-1);

   return dp[n]=singleup+pairup;


}
// tabulation
int friends_pairdp(int n,vector<int>& dp){
    for(int i=0;i<=n;i++){
    if(i<=1){
         dp[i]=1;
         continue;
        }
    
    
    int single=dp[i-1];
    int pair_up=dp[i-2]*(i-1);

    dp[i]=single+pair_up;

}
return dp[n];
}
//Also do two pointer approach
////////////////////
int goldMin(int sr,int sc,vector<vector<int>>& grid,vector<vector<int>>& dp){
     if (sc == grid[0].size() - 1)
    {
        return dp[sr][sc] = grid[sr][sc];
    }

    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    int dir[3][2] = {{-1, 1}, {0, 1}, {1, 1}};
    int maxCoins = 0;
    for (int d = 0; d < 3; d++)
    {
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];
        if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size())
        {
            maxCoins = max(maxCoins, goldMin(x, y, grid, dp));
        }
    }

    return dp[sr][sc] = maxCoins + grid[sr][sc];
    }
    int goldMindp(vector<vector<int>>& grid,vector<vector<int>>& dp){
        for (int sc = grid[0].size() - 1; sc >= 0; sc--)
    {
        for (int sr = grid.size() - 1; sr >= 0; sr--)
        {
            if (sc == grid[0].size() - 1)
            {
                dp[sr][sc] = grid[sr][sc];
                continue;
            }

            int dir[3][2] = {{-1, 1}, {0, 1}, {1, 1}};
            int maxCoins = 0;
            for (int d = 0; d < 3; d++)
            {
                int x = sr + dir[d][0];
                int y = sc + dir[d][1];
                if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size())
                    maxCoins = max(maxCoins, dp[x][y]);
            }

            dp[sr][sc] = maxCoins + grid[sr][sc];
        }
    }

    int maxCoin = 0;
    for (int i = 0; i < grid.size(); i++)
        maxCoin = max(maxCoin, dp[i][0]);
    return maxCoin;
    }
    /////////////////////////////////////////////////////////////////////////
    //divide n into k subgroups:
    //Memoization:
    int countways(int n,int k,vector<vector<int>>& dp)
    {
        if(n==k || k==1){
            return dp[k][n]=1;
            
        }
        int newGroup=countways(n-1,k-1,dp);
        int oldGroup=countways(n-1,k,dp)*k;

        return dp[k][n]=newGroup+oldGroup;


    }
    //Tabulation:
    int countwaysdp(int n,int k,vector<vector<int>>& dp)
    {
        int K=k;
        int N=n;
        for(int k=1;k<=K;k++){
            for(int n=k;n<=N;n++){
        
        if(n==k || k==1){
            dp[k][n]=1;
            continue;

            
        }
        int newGroup=dp[k-1][n-1];
        int oldGroup=dp[k][n-1]*k;

         dp[k][n]=newGroup+oldGroup;
         }}

         return dp[K][N];


    }
    ////////////////////////////
    //String subsets questions:

    vector<vector<bool>> isPlaindromeSubstring(string str)
    {
        int n=str.length();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){
                    dp[i][j]=true;
                }
                else if(gap==1 && str[i]==str[j]){
                    dp[i][j]=true;
                }
                else if(dp[i+1][j-1]==true && str[i]==str[j]){
                    dp[i][j]=true;
                }
            }
        }
        return dp;
    }
    string longestpallindromeString(string str)
    {
        int n=str.length();
        int si=0;
        int ei=0;
        int maxLen=0;

        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){
                    dp[i][j]=1;
                }
                else if(gap==1 && str[i]==str[j]){
                    dp[i][j]=2;
                }
                else if(str[i]==str[j] && dp[i+1][j-1]!=0){
                    dp[i][j]=gap+1;

                }
                if(dp[i][j]>maxLen){
                    maxLen=dp[i][j];
                    si=i;
                    ei=j;
                }
                    
                }
            }
              return str.substr(si, (ei - si + 1));
        }
     int longestPalindrome_Subs(string& str,int si,int ei,vector<vector<int>>& dp)
    {
        if(si>ei){
            return 0;
        }
        if(si==ei){
            return dp[si][ei]=1;
        }
        if(dp[si][ei]!=0){
            return dp[si][ei];
        }
        
        
        int maxlen=0;
        if(str[si]==str[ei]){
            maxlen=longestPalindrome_Subs(str,si+1,ei-1,dp)+2;
            
        }
        else{
            maxlen=max(longestPalindrome_Subs(str,si,ei-1,dp),longestPalindrome_Subs(str,si+1,ei,dp));
        }
        return dp[si][ei]=maxlen;
        
    }
    vector<string> substrings(string& str,vector<vector<bool>>& dp){
        vector<string> ans;
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                if(dp[i][j]){
                    ans.push_back(str.substr(i,j-i+1));
                }
            }
        }
        return ans;
    }

    ///////////////////////////////////////////////////////
    int longestPlaindrome_subsDP(string& str,int si,int ei,vector<vector<int>>& dp){
        for(int gap=0;gap<str.length();gap++){
            for(int si=0,ei=gap;ei<str.length();si++,ei++){
                if(si>ei){
                    return 0;
                }
                if(si==ei){
                    dp[si][ei]=1;
                    continue;
                }
                int len=0;
                if(str[si]==str[ei])
                {
                    len=dp[si+1][ei-1]+2;
                    }
                else{
                    len=max(dp[si][ei-1],dp[si+1][ei]);
                }  
                dp[si][ei]=len; 

            }
            
        }
        return dp[0][str.length()-1];
    }

     int distinct_subs(string& str,string& t,int n,int m, vector<vector<int>>& dp)
    {
        if(m==0){
            dp[n][m]=1;
        }
        if(m>n){
             dp[n][m]=0;
        }

        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        
        if(str[n-1]==t[m-1]){
            return dp[n][m]=distinct_subs(str,t,n-1,m-1,dp)+distinct_subs(str,t,n-1,m,dp);
        }
        return dp[n][m]=distinct_subs(str,t,n-1,m,dp);
        
    }
    int distinct_subsDP(string& str,string& t,int n,int m, vector<vector<long>>& dp){
         int N=n,M=m;
         for(int n=0;n<=N;n++){
             for(int m=0;m<=M;m++){
                 if(m==0){
                     dp[n][m]=1;
                     continue;
                 }
                 if(m>n){
                     dp[n][m]=0;
                     continue;
                 }
                 if(str[n-1]==t[m-1]){
                     dp[n][m]=dp[n-1][m-1]+dp[n-1][m];
                 }
                 else{
                     dp[n][m]=dp[n-1][m];
                 }
                 
             }
         }
         return dp[N][M];
     }
     int count_PS(string str,int i,int j,vector<vector<int>>& dp)
     {
         if(i>j)
         {
             return dp[i][j]=0;
             
         }
         if(i==j){
             return dp[i][j]=1;
         }
         int midstring=count_PS(str,i+1,j-1,dp);
         int excludefirst=count_PS(str,i+1,j,dp);
         int excludelast=count_PS(str,i,j-1,dp);

         int ans=excludefirst+excludelast;
         return dp[i][j]=str[i]==str[j]?ans+1:ans-midstring;

        
     }
     /////////////////////////////
      int longestsubs(string text1, string text2,int i,int j,vector<vector<int>>& dp){
        if(i==text1.length() || j==text2.length()){
            return dp[i][j]=0;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        int ans=0;
        if(text1[i]==text2[j]){
            ans=longestsubs(text1,text2,i+1,j+1,dp)+1;
        }
        else
        {        
         ans=max(longestsubs(text1,text2,i,j+1,dp),longestsubs(text1,text2,i+1,j,dp));
        }
        return dp[i][j]=ans;
        
    }
    int longestcommon_substring(string text1, string text2,int i,int j,vector<vector<int>>& dp)
    {
        if(i==text1.length() || j==text2.length()){
            return dp[i][j]=0;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        int ans=0;
        if(text1[i]==text2[j]){
            ans=max(ans,longestcommon_substring(text1,text2,i+1,j+1,dp)+1);
        }
        longestcommon_substring(text1,text2,i+1,j,dp);
        longestcommon_substring(text1,text2,i,j+1,dp);
        return dp[i][j]=ans;

        
    }
    
    void longestCommonSubsequence(string text1, string text2) 
    {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        cout<<longestcommon_substring(text1,text2,0,0,dp)<<endl;
        display2D(dp);
        
    }

    /////////////////////////////////////////////////
    //LIS Problems:
    int LIS_ltor(vector<int> arr,vector<int>& dp)
    {
        int omax=0;
        for(int i=0;i<arr.size();i++){
            dp[i]=1;
            for(int j=i-1;j=0;j--){
                if(arr[i]>arr[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            omax=max(omax,dp[i]);
        }
        return omax;
      
    }
    //LDS
    int LIS_rtol(vector<int> arr,vector<int>& dp){
        
        int oMax=0;
        for(int i=arr.size()-1;i>=0;i--){
            dp[i]=1;
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]>arr[j]){
                    dp[i]=max(dp[i],dp[j]+1);

                }
            }
            oMax=max(oMax,dp[i]);

        }
        return oMax;

    }
    // LBS:
    // longest biotonic subsequence:
    int LBS(vector<int>& arr)
    {
        int n=arr.size();
        vector<int> LIS(n,0);
        vector<int> LDS(n,0);
        LIS_ltor(arr,LIS);
        LIS_rtol(arr,LDS);
        int maxlen=0;

        for(int i=0;i<arr.size();i++){
            int len=LIS[i]+LDS[i]-1;
            maxlen=max(len,maxlen);

        }
        return maxlen;


    }
    int maxIncreasing_sum(vector<int>& arr,vector<int>& dp)
    {
        int osum=0;
        for(int i=0;i<arr.size();i++){
            dp[i]=arr[i];
            for(int j=i-1;j>=0;j--){
                if(arr[i]>arr[j]){
                    dp[i]=max(dp[i],dp[j]+arr[i]);

                }}
                  osum=max(osum,dp[i]);
            }
            return osum;
    }

// minimum no of deletion to make array in sorted order in increasing order.
// the minimum no of deletion will be the total size of array-longest increasing subsequence because all thenos that are not the part of the subbsequence will get deleted.
int minDeletion(vector<int> &arr){

        int oMax=0;
        int n=arr.size();
        vector<int> dp(arr.size(),0);
        for(int i=arr.size()-1;i>=0;i--){
            dp[i]=1;
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]>arr[j]){
                    dp[i]=max(dp[i],dp[j]+1);

                }
            }
            oMax=max(oMax,dp[i]);

        }
        return n-oMax;
}
 int findNumberOfLIS(vector<int>& arr) 
    {
        int n=arr.size();
        if(n<=1){
            return n;
        }
        vector<int> dp(n,0);
        vector<int> count(n,0);
        int maxlen=0;
        int maxCount=0;
        for(int i=0;i<n;i++){
            dp[i]=1;
            count[i]=1;
            for(int j=i-1;j>=0;j--)
            {
                if(arr[i]>arr[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }
                    else if(dp[j]+1==dp[i]){
                        count[i]+=count[j];
                    }
                }
                
            }
            if(dp[i]>maxlen){
                maxlen=dp[i];
                maxCount=count[i];
            }
            else if(dp[i]==maxlen){
                maxCount+=count[i];
            }
        }
        return maxCount;
        
        
    }
    //Russian Doll questions:
    ///////////////////////////////////////////////////////
    //Coin change Problem:
    int coin_permi(vector<int>& arr,int tar,vector<int>& dp){
         if (tar == 0)
        return dp[tar] = 1;
    if (dp[tar] != 0)
        return dp[tar];

    int count = 0;
    for (int ele : arr)
        if (tar - ele >= 0)
            count += coin_permi(arr, tar - ele, dp);

    return dp[tar] = count;
        
    }
    int coin_permiDp(vector<int>& arr,int Tar,vector<int>& dp)
       {
           dp[0]=1;
           for(int tar=0;tar<=Tar;tar++){
                int count = 0;
              for (int ele : arr){
        if (tar - ele >= 0){
            dp[tar] += dp[tar-ele];

               
           }
           
       }}
       return dp[Tar];
       
       }


    ///////////////////////////////////////
    int coin_change_combiDp(vector<int>& arr,int Tar,vector<int>& dp){
        dp[0]=1;
        for(int ele:arr){
            for(int tar=0;tar<=Tar;tar++){
               
              
              if (tar - ele >= 0){
            dp[tar] += dp[tar-ele];

               
           }
           
       }}
       return dp[Tar];
       

        }
        ////////////////////////////////
        int linear_equations(vector<int>& coeff,int rhs,vector<int>& dp)
        {
            dp[0]=1;
            for(int ele:coeff){
                for(int i=0;i<=rhs;i++){
                    if(i-ele>=0){
                        dp[i]+=dp[i-ele];
                    }
                }
            }
            return dp[rhs];
        }

        int coins_(vector<int>& arr, int tar,vector<int>& dp) 
        {
            if(tar==0){
                return dp[tar]=0;
            }
            if(dp[tar]!=0){
                return dp[tar];
            }
            

            int minHeight=1e8;
            for(int ele:arr){
                if(tar-ele>=0){
                    int rmin=coins_(arr,tar-ele,dp);
                    if(rmin!=1e8 && rmin+1<minHeight ){
                        minHeight=rmin+1;
                    }
                }
            }
            return dp[tar]=minHeight;




        
    }
    int target_sum(vector<int>& arr,int idx,int tar,vector<vector<int>>& dp)
    {
        if(tar==0 || idx==0){
            if(tar==0){
                return dp[idx][tar]=1;
            }
            return dp[idx][tar] = 0;
        } 
        if(dp[idx][tar]!=0){
            return dp[idx][tar];
        }



        int count=0;
        if(tar-arr[idx-1]>=0){
            count+=target_sum(arr,idx-1,tar-arr[idx-1],dp);
        }
        count+=target_sum(arr,idx-1,tar,dp);

        return dp[idx][tar]=count;
    }
    

       
    


    int MCM(vector<int>& arr,int si,int ei,vector<vector<int>>& dp){
        if(si+1==ei){
            return dp[si][ei]=0;
        }
        if(dp[si][ei]!=-1)
        {
            return dp[si][ei];
        }
        int ans=1e8;
        for(int cut=si+1;cut<ei;cut++){
            int leftans=MCM(arr,si,cut,dp);
            int rightans=MCM(arr,cut,ei,dp);

            int myans=leftans+arr[si]*arr[cut]*arr[ei]+rightans;
            if(myans<ans){
                ans=myans;
            }
        }
        return dp[si][ei]=ans;


    }
    int MCM_DP(vector<int>& arr,vector<vector<int>>& dp){
        for(int gap=1;gap<arr.size();gap++){
            for(int si=0,ei=gap;ei<arr.size();si++,ei++){
                 if(si+1==ei){
                     dp[si][ei]=0;
                     continue;
        }
         int ans=1e8;
        for(int cut=si+1;cut<ei;cut++){
            int leftans=dp[si][cut];
            int rightans=dp[cut][ei];

            int myans=leftans+arr[si]*arr[cut]*arr[ei]+rightans;
            if(myans<ans){
                ans=myans;
            }
        }
        dp[si][ei]=ans;



            }

        }
        return dp[0][arr.size()-1];
    }
    // we need to eliminate this cost of seraching in order to get n3 complexity
    int costofSearching(vector<int>& freq,int si,int ei){
        int sum=0;
        for(int i=si;i<=ei;i++){
            sum+=freq[i];
        }
        return sum;
    }
    int optimal_BST(vector<int>& freq,int si,int ei,vector<vector<int>>& dp)
{
    if(dp[si][ei]!=0){
        return dp[si][ei];
    }
    int ans=1e8;
    for(int cut=si;cut<=ei;cut++){
        int leftans=cut==si?0:optimal_BST(freq,si,cut-1,dp);
        int rightans=cut==ei?0:optimal_BST(freq,cut+1,ei,dp);

        int myans=leftans+costofSearching(freq,si,ei)+rightans;
        if(myans<ans){
            ans=myans;
        }
    }
    return dp[si][ei]=ans;

}   
int optimal_bstDP(vector<int>& freq,vector<vector<int>>& dp)
{
    vector<int> prefix_sum(freq.size()+1,0);
    for(int i=1;i<prefix_sum.size();i++)
    {
        prefix_sum[i]=prefix_sum[i-1]+freq[i-1];
    }
    for(int gap=0;gap<freq.size();gap++){
        for(int si=0,ei=gap;ei<freq.size();si++,ei++){
            int ans=1e8;
             for(int cut=si;cut<=ei;cut++){
        int leftans=cut==si?0:dp[si][cut-1];
        int rightans=cut==ei?0:dp[cut+1][ei];

        int myans=leftans+prefix_sum[ei+1]-prefix_sum[si]+rightans;
        if(myans<ans){
            ans=myans;
        }
    }
    dp[si][ei]=ans;

        }
        

    }
    return dp[0][freq.size()-1];

} 




int kmnpasack(vector<int>& w,vector<int>& p,int weight,int n,vector<vector<int>>& dp){
    if(weight==0  || n==0){
        return 0; //agar 0 weight diya hai yaa bag mein jagah hi ni hai toh koi profit ni aayega;
    }
    if(dp[n][weight]!=0){
        return dp[n][weight];

    }



    int maxProf=-1e8;
    if(weight-w[n-1]>=0){
        maxProf=max(maxProf,kmnpasack(w,p,weight-w[n-1],n-1,dp)+p[n-1]);
    }
     maxProf=max(maxProf,kmnpasack(w,p,weight,n-1,dp));
     return dp[n][weight]=maxProf;


} 
void coins(){
    vector<int> arr={2,3,5,7};
    int tar=10;
    vector<vector<int>> dp(arr.size()+1,vector<int>(tar+1,0));
    cout<<target_sum(arr,arr.size(),tar,dp)<<endl;
    display2D(dp);
    // vector<int> dp(tar+1,0);
    // cout<<coin_change_combiDp(arr,tar,dp)<<endl;
    // display(dp);


}
void knapsack(){
    vector<int> p={60,100,120};
    vector<int> w={10,20,30};
    int weight=50;
    vector<vector<int>> dp(w.size()+1,vector<int>(weight+1,0));
    cout<<kmnpasack(w,p,weight,w.size(),dp);
}

    
void pathset()
{
    // int n=3;
    // int m=3;
    // vector<vector<int>> dp(n,vector<int>(m,0));
    // cout<<multimoves_tabs(0,0,2,2,dp)<<endl;
    // display2D(dp);

    //////////////////////////////////////////////////////////////////////////
    // int n=10;
    // vector<int> dp(n+1,0);
    // vector<int> outcomes={2,5,7,3};
    // cout<<diceprob2(0,n,outcomes,dp)<<endl;
    

    //  display(dp);
     //Minimum climbing stairs;
     //  clim the stairs leetcode.
///////////////////////////////////////////////////////////////////////////////////
    vector<vector<int>> grid={{1,3,3},{2,1,4},{0,6,4}};
    int n=grid.size();
    int m=grid[0].size();
     vector<vector<int>> dp(n,vector<int>(m,0));
    // int maxCoins=0;
    // for(int i=0;i<n;i++){
    //     maxCoins=max(maxCoins,goldMin(i,0,grid,dp));
    // }
    // cout<<maxCoins<<endl;
    // int maxCoins=goldMindp(grid,dp);
    // cout<<maxCoins<<endl;
    // display2D(dp);

}
void LIS_set(){
    vector<int> arr={1, 11, 2, 10, 4, 5, 2, 1};
    //vector<int> arr={ 10, 22, 9, 33, 21, 50, 41, 60 };
    vector<int> dp(arr.size(),0);
    //cout<<LIS_ltor(arr,dp);// output :5
    cout<<LBS(arr);
}
void set2()
{
    // int n=5;
    // vector<int> dp(n+1,0);
    // cout<<friends_pairdp(n,dp)<<endl;
    // display(dp); 

    ///////////count ways///////////////////
    int n=4,k=3; //ans=6
    if(n<k){
        return;
    }
    vector<vector<int>> dp(k+1,vector<int>(n+1,0));
    cout<<countways(n,k,dp)<<endl;
    display2D(dp);

   
 
    // vector<vector<int>> grid={{1,3,3},{2,1,4},{0,6,4}};
    // int n=grid.size();
    // int m=grid[0].size();
    //  vector<vector<int>> dp(n,vector<int>(m,0));
    
    // int maxCoins=0;
    // for(int i=0;i<n;i++){
    //     maxCoins=max(maxCoins,goldMin(i,0,grid,dp));
    // }
    // cout<<maxCoins<<endl;
    // display2D(dp);

    
    ////////////////////////////////
    
}
void cutType(){
    vector<int> arr={34, 8, 50};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // cout<<MCM(arr,0,n-1,dp)<<endl;
    //cout<<MCM_DP(arr,dp)<<endl;
    //cout<<optimal_BST(arr,0,arr.size()-1,dp)<<endl;
    cout<<optimal_bstDP(arr,dp)<<endl;
    display2D(dp);


}
void string_sets(){
        string str="geek";
        // string s="babgbag";
        // string t="bag";

        // //int n=str.length();
        // int n=s.length();
        // int m=t.length();
        //  vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        //vector<vector<int>> dp(n,vector<int>(n,0));
        // int si=0;
        // int ei=n-1;
        vector<vector<bool>> pallindrome=isPlaindromeSubstring(str);
        // for(vector<bool> ans:pallindrome){
        //     for(bool ar:ans){
        //         cout<<ar<<" ";
            
        //     }
        //     cout<<endl;
        // }
        vector<string> ans=substrings(str,pallindrome);
        unordered_map<string,int> mp;
        for(string s:ans){
            mp[s]++;
          //  cout<<s<<" ";

            
        }
        int count=0;
        vector<string> ans_;
        for(auto x:mp){
            if(x.second>=1){
                ans_.push_back(x.first);

                count++;
            }}

        for(string s:ans_){
            cout<<s<<" ";
        }
        cout<<count;
    
        
    

        // cout<<longestPlaindrome_subsDP(str,si,ei,dp)<<endl;
        // cout<<distinct_subs(s,t,n,m,dp)<<endl;
        // display2D(dp);
        //longestCommonSubsequence("abcd","abc");
        // display2D(dp);


    

}
int main(int args,char** argv){
    //pathset();
    //set2();
    //knapsack();
    //string_sets();
    //LIS_set();
    //cutType();
    coins();
}


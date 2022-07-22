string writeAsYouSpeak(int n) 
{
	// Write your code here.
    if(n==1){
        return "1";
    }    
    string s=writeAsYouSpeak(n-1);
    int cnt=0;
    string ans="";
    char ch=s[0];
    for(int i=0;i<s.length();i++){
        if(s[i]==ch){
            cnt++;
        }else{
            ans+=to_string(cnt)+ch;
            ch=s[i];
            cnt=1;
        }
    }
    ans+=to_string(cnt)+ch;
    return ans;
}
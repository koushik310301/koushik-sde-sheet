int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int res=0;
    for(int i : arr) res=res^i;
    return res;
}

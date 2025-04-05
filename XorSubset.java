class Solution {
    int total=0;
    public int subsetXORSum(int[] nums) {
        dfs(nums,0,0);
        return total;

    }
    private void dfs(int arr[],int index,int currResult)
    {
        if(index==arr.length)
        {
            total=total+currResult;
            return ;
        }
        //Include the element
        dfs(arr,index+1,currResult^arr[index]);
        //Exclude the elment
        dfs(arr,index+1,currResult);
    }
    
}
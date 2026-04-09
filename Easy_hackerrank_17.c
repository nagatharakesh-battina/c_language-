int removeElement(int* nums, int numsSize, int val) {
    int count=0;
    int l=0;
    if(numsSize<=0){
        return 0;
    }
    int arr[numsSize];
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=val){
            count++;
            arr[l++]=nums[i];
            
        }
    }
    for(int i=0;i<count;i++){
        nums[i]=arr[i];
    }
    return count;
}

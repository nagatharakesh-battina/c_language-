int searchInsert(int* nums, int numsSize, int target) {
    if(numsSize==0)return 1;
    if(numsSize==1 ){
        // if(nums[1]==target){
        //     return 1;
        // }
        if(nums[0]>=target){
            return 0;
        }else{
            return 1;
        }
    }
    for(int i=0;i<numsSize;i++){
        if(nums[i]==target){
            return i;
            break;
        }
            
        if(nums[i]>target){
            return i;
            break;
        }
    }
    return numsSize;
}

bool binarySearch(vector<int> &array,int start,int end,int val)
     {
         if(array.size() == 0)
            return false;
         int lowIndex = start;
         int highIndex = end;
         while(lowIndex <= highIndex)
         {
            int midIndex = (lowIndex + highIndex) / 2;
            if(val == array[midIndex])
            {
//                currnetIndex = midIndex;
                 return true;
            }
            else if(val < array[midIndex])
                highIndex = midIndex - 1;
            else if(val > array[midIndex])
                lowIndex = midIndex + 1;
         }
         return false;
     }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        // Write your code here
        vector<int> output;
        if(nums1.empty() || nums2.empty())
            return output;
        sort(nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        map<int,int> hashMap1;
        for(int i = 0; i < nums1.size(); i++)
        {
            hashMap1[nums1[i]]++;
        }
        map<int,int> hashMap2;
        for(int i = 0; i < nums2.size(); i++)
        {
            hashMap2[nums2[i]]++;
        }
        int searchStart = 0;
//        for(iter1 = nums1.begin(); iter1 != nums1.end(); iter1++)
        for(int i = 0; i < nums1.size(); i++)
        {
                if(binarySearch(nums2,searchStart,nums2.size() - 1,nums1[i]))
//                for(iter2 = nums2.begin(); iter2 != nums2.end(); iter2++)
//                for(int j = 0; j < nums2.size(); j++)
                {
                    int count =  hashMap1[nums1[i]] >  hashMap2[nums1[i]] ?  hashMap2[nums1[i]] :  hashMap1[nums1[i]];
                    while(count--)
                        output.push_back(nums1[i]);

                    i = i + hashMap1[nums1[i]] - 1;
                    searchStart = searchStart + hashMap2[nums1[i]];
                }
        }
        return output;
    }


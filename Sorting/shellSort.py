def shellSort(arr):
    gap = len(arr) // 2
    
    while gap > 0:
        for i in range(gap, len(arr)):
            # print(gap,i,arr)
            # print("element",arr[i])
            temp = arr[i]
            j = i
            
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            
            arr[j] = temp
         
        gap //= 2
    
 
    
    
    


arr =[19,22,63,105,2,46]
shellSort(arr)
print(arr)

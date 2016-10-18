void selection_sort(int Array[],int n){  
    for(int i=0;i<n;i++){  
        for(int j=i+1;j<n;j++){  
            if(Array[j]>Array[i]){  
                int tmp=Array[j];  
                Array[j]=Array[i];  
                Array[i]=tmp;  
            }  
        }  
    }  
}  

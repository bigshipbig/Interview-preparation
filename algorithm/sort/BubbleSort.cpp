void bubble_sort(int Array[],int n){  
    for(int i=0;i<n;i++){  
        for(int j=0;j<n-i-1;j++){  
            if(Array[j]>Array[j+1]){  
                int tmp=Array[j];  
                Array[j]=Array[j+1];  
                Array[j+1]=tmp;  
            }  
        }  
    }  
}

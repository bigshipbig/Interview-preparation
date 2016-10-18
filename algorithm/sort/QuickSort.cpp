void QuickSort(int Array[], int l, int r){
    int key = Array[l];
    int i = l, j = r;
    if(i >= j)
        return;
    while(i < j){
        while(i < j && key <= Array[j])
            j--;
        Array[i] = Array[j];
        while(i < j && key >= Array[i])
            i++;
        Array[j] = Array[i];
    }
    Array[j] = key;
    QuickSort(Array,l,j-1);
    QuickSort(Array,j+1,r);
}

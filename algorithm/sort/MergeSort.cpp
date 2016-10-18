class MergeSort{
private:
    int Array[N];
    int tmp[N<<1];
public:
    void merge(int low, int mid, int high){
        int i = low, j = mid , k = low;
        while(i <= mid && j <= high){
            if(Array[i] < Array[j]) tmp[k++] = Array[i++];
            else tmp[k++] = Array[j++];
        }
        while(i <= mid) tmp[k++] = Array[i++];
        while(j <= high) tmp[k++] = Array[j++];
        for(i = low; i <= high; i++){
            Array[i] = tmp[i];
        }
    }
    void sort(int low, int high){
        if(a < b){
            int mid = low + high >> 1;
            sort(low, mid);
            sort(mid+1, high);
            merge(a,mid,high);
        }
    }
};


#include "FileAndSort.h"


void swap(std::vector<int>& ar,int id1, int id2)  //交换a,b
{
    int tmp;
    tmp = ar[id1];
    ar[id1] = ar[id2];
    ar[id2] = tmp;
}

int sort(std::vector<int>& ar,int begin,int end)  //左小右大
{
    int pivotId = begin;
    int nMoved = 0;
    bool undone = false;

    if (begin > 21)
    {
        return 1;
    }


    for (int i = begin; i <= end; i++)
    {
        if (i == pivotId)   continue;

        
        if (i > pivotId && ar[i] < ar[pivotId])
        {
            nMoved++;
            if (pivotId + nMoved > 21)
            {
                    printf("error");
            }
            swap(ar,pivotId + nMoved, i);
        }
    }

    swap(ar, pivotId, begin+nMoved);

    for (int i = begin; i <= end-1; i++)
    {
        
        if (ar[i] > ar[i + 1])
        {
            undone = true;
        }
    }

    if (!undone)
    {
        return 1;
    }
    else 
    {
        sort(ar,begin,begin+nMoved);               
        sort(ar,begin+nMoved+1,end);  //sort(ar + nMoved, lenAr - nMoved);的时候,为什么会stack overflow ?为什么会有元素内存溢出?
     
        //使用标准容器如何进行切片?
    }
    //越界    切片

    
}

void printArray(std::vector<int>& ar)
{
    printf("{");
    for (int i = 0; i < ar.size(); i++)
    {
        printf("%d,", ar[i]);
    }
    printf("}\n");
}

int main()
{

    std::vector<int> vector = { 1145,45,87,89,79,87,987,987,89,7564,5,465,45612,31,5,465647,8584879,232,4,5,114514,1919 };
    
    

    printArray(vector);

    sort(vector, 0, vector.size()-1);

    printArray(vector);

    return 0;


}

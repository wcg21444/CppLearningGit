#include "FileAndSort.h"
#include <Windows.h>

#pragma comment(lib,"winmm.lib")



void fileWriteRandInt(const char* _FileName)      //重新写入
{

    std::ofstream* fileOut = new std::ofstream;
    fileOut->open(_FileName, std::ios::out | std::ios::trunc);



    for (int i = 0; i < lenArray; i++)
    {
        *fileOut<< rand() << " ";
    }


    fileOut->close();
    std::cout << "Done";

}

void fileWriteArrayInt(const char* _FileName, int*ar)      //重新写入
{

    std::ofstream* fileOut = new std::ofstream;
    fileOut->open(_FileName, std::ios::out | std::ios::trunc);



    for (int i = 0; i < lenArray; i++)
    {
        *fileOut << ar[i] << " ";
    }


    fileOut->close();
    std::cout << "Done";

}

std::vector<int>& fileReadAndTrans(const char* _FileName)      //读取并写入数组
{
    std::ifstream* fileIn = new std::ifstream;

    std::vector<int>& data = *new std::vector<int>(lenArray);



    fileIn->open(_FileName, std::ios::in);

    for(int i = 0;i<lenArray;i++)
    {
        *fileIn >> data[i];
    }


    fileIn->close();

    std::cout << "Done";

    return data;

}

/*int main()
{
    

    const char* _FileName = "C:/Users/R/vs/c++/CppFileStream/Files/file1.txt";
    const char* _FileNameSorted = "C:/Users/R/vs/c++/CppFileStream/Files/fileSorted.txt";

    DWORD t1, t2;

    //fileWriteRandInt(_FileName,lenArray);  //填写随机数

    std::vector<int>& data = * new std::vector<int>(lenArray) ;    // & data = new std:arr<...>




    data = fileReadAndTrans(_FileName,lenArray);     //读取随机数,放到数组中

    t1 = timeGetTime();

    sort(data, lenArray,0,lenArray-1);

    t2 = timeGetTime();

    //fileWriteArrayInt(_FileNameSorted, data, lenArray);



    printf("\n");
    std::cout << "用时:" << (t2 - t1) << "ms";
     
    return 0;

}
*/
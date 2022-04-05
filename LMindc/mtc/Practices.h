#ifndef _PRACTICES_H_
#define _PRACTICES_H_
#include<iostream>
#include<ctime>

class ClassTestArrays{
public:
    ClassTestArrays(){
        /*线性表测试*/
    }
    void funcTest(){
        srand(int(time(0)));
        int* arr=new int[10];
        for(int i=0;i<10;i++){
            arr[i]=rand()%100;
        }

        auto aLen=[&](int* arr){ int count=0; while(*arr){ count++; arr++; } return count; };

        int length=aLen(arr);

        auto print=[&](int* arr,int len){
            for(int i=0;i<len;i++){
                std::cout<<"  "<<arr[i];
            }
            std::cout<<std::endl;
        };

        print(arr,10);
        int Minis=0;
        arr = this->funcDelMin(arr, Minis);
        print(arr,9);

    }
private:
    int* funcDelMin(int* arr, int& mins){
        /* to delete the smallest one, and use the last one to instead it */
        auto len=[&](int* arr){ int count=0; while(*arr){ count++; arr++; } return count; };
        auto fmin=[&](int a,int newb,int& loc, int& newloc){ if(a>newb){ loc = newloc; return newb; } else return a; };

        int lens=len(arr);
        int numMin=INT_MAX;

        int loc=0;
        for(int i=0; i<lens; i++){
            //numMin=fmin(numMin,arr[i]);
            numMin = fmin(numMin, arr[i], loc, i);
        }
        
        arr[loc]=arr[lens - 1];
        int* cc=new int[lens - 1];
        for(int i=0;i<lens - 1;i++){
            cc[i]=arr[i];
        }
        return cc;
    }
};

namespace SoluteTest{

}

#endif
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#ifndef DS_HEADER_FILE_DS_ARRAY_H
#define DS_HEADER_FILE_DS_ARRAY_H
namespace ds{
    template<typename T>
    class Array{

        //arr is a pointer which store the address of the array.
        T* arr;
        //current_size store the number of element store in our array.
        int current_size;
        //total_size store the total capacity of the array.
        int total_size;
    public:
         Array(int t=0){  // initializes the array with a the number of element define by the user
            current_size=t;
            total_size=2*t;
            if( t == 0){
                total_size = 1;
            }
            arr= new T[total_size];
        }
        Array(int t,T value){
             current_size=t;
             total_size=2*t;
             arr = new T [total_size];
             for(int i=0;i<total_size;++i){
                 arr[i]=value;
             }
         }
    };
}

#endif

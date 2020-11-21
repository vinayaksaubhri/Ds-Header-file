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
         Array(int t=0){  // initializes the array with a the number of element given by the user
            current_size=t;
            total_size=2*t;
            if( t == 0){
                total_size = 1;
            }
            arr= new T[total_size];
        }
        Array(int t,T value){ // initializes the array with a the number of element and the value given by the user
             current_size=t;
             total_size=2*t;
             arr = new T [total_size];
             for(int i=0;i<total_size;++i){
                 arr[i]=value;
             }
         }
         Array(std::vector<T>v){ // copy the vector into our array.
             for(auto i : v){
                 push_back(i);
             }
         }
         void push_back(T element){ // push the element in the back of array.

             // if the current_size  is equal to or more than total_size , this means we don't have space to accommodate more elements. So we need to double the size.
             if((current_size+1) >= total_size){
                 resize(2*total_size);
                 total_size *= 2;
             }
             arr[current_size]=element;
             ++current_size;
         }
         void pop_back(){
             //pop the last element of the array.
             if(current_size > 0){
                 --current_size;
             }
             if(current_size < total_size/4){ //reducing the size of the array to save the space.
                 resize(total_size/4);
                 total_size /= 2;
             }
         }
         void resize(int new_size){ // function to resize the array .
           T * new_arr = new T[2*new_size]; //doubling the size.
           for(int i=0;i<current_size;++i){
               new_arr[i]=arr[i];//copy the old array.
           }
             delete[] arr;//deleting the old array.
           arr = new_arr;
         }
    };
}

#endif

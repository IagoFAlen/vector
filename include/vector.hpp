#pragma once
#include <cstdlib>

namespace vec {
    typedef struct vector {
        void** data;
        
        size_t size;
        size_t capacity; 

        vector(): data(nullptr), size(0), capacity(0){}

        int resize(){
            size_t new_capacity = 0;

            if(size >= capacity)
                new_capacity = capacity ? capacity * 2 : 4;
            else return 1;

            void** new_data = (void**)realloc(data, new_capacity * sizeof(void*));
            if(!new_data) return 0;

            data = new_data;
            capacity = new_capacity;

            for(size_t i = size; i < capacity; i++){    
                data[i] = nullptr;
            }

            return 1;
        }

        void push(void* value){
            if(resize())
                data[size++] = value;
            else return;
        }

        void release(){
            if (data){
                free(data);
                data = nullptr;
                size = capacity = 0;
            } 
        }

        void* get(size_t index) {
            if (index >= size) return nullptr;
            return data[index];
        }
        
    } VECTOR;

}
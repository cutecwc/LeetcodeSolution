#pragma once
#ifndef _BOOKLEARNINGTEST_H_
#define _BOOKLEARNINGTEST_H_

#include<iostream>
#include<ctime>

namespace bookTeststd {
    class ClassTestArrays {
    public:
        ClassTestArrays() {
            /*线性表测试*/
        }
        void funcTest() {
            srand(int(time(0)));
            int* arr = new int[10];
            for (int i = 0; i < 10; i++) {
                arr[i] = rand() % 100;
            }

            auto aLen = [&](int* arr) { int count = 0; while (*arr) { count++; arr++; } return count; };

            int length = aLen(arr);

            auto print = [&](int* arr, int len) {
                for (int i = 0; i < len; i++) {
                    std::cout << "  " << arr[i];
                }
                std::cout << std::endl;
            };

            print(arr, 10);
            int Minis = 0;
            arr = this->funcDelMin(arr, Minis);
            print(arr, 9);

        }
    private:
        int* funcDelMin(int* arr, int& mins) {
            /* to delete the smallest one, and use the last one to instead it */
            auto len = [&](int* arr) { int count = 0; while (*arr) { count++; arr++; } return count; };
            auto fmin = [&](int a, int newb, int& loc, int newloc) { if (a > newb) { loc = newloc; return newb; } else return a; };
            auto print = [&](int* arr, int len) {
                for (int i = 0; i < len; i++) {
                    std::cout << "  " << arr[i];
                }
                std::cout << std::endl;
            };

            int lens = len(arr);
            int numMin = INT_MAX;

            int loc = 0;
            for (int i = 0; i < lens; i++) {
                //numMin=fmin(numMin,arr[i]);
                numMin = fmin(numMin, arr[i], loc, i);
            }

            arr[loc] = arr[lens - 1];
            int* cc = new int[lens - 1];

            print(arr, len(arr));
            for (int i = 0; i < lens - 1; i++) {
                cc[i] = arr[i];
            }
            return cc;
        }
    };
}

namespace bookArraySTD {
    typedef struct myArray {
        myArray() {
            /*
            to create an array type by this function. */
            this->_array = NULL;
            this->_len = 0;
            this->_size = 0;
            this->_lock = false;
        }
        myArray(int lockSize) {
            /*
            to create an array type by this function, but some square are added to array.
            a lock is applicated to the array. the size can't be resize without unlocking. */
            this->_array = new int[lockSize];
            this->_len = 0;
            this->_size = lockSize;
            this->_lock = true;
        }
        /*
        this value can be found by anyone.
        but _len and _size can be found just by a interface function.*/
        int* _array;
    private:
        int _len;
        int _size;
        bool _lock;
    public:
        int funcRtnLen() {
            return this->_len;
        }
        int funcRtnSize() {
            return this->_size;
        }

        /* 设计思想：设定一个lock锁，在初始化设定了数值的数组禁止后续更改 lock值为TRUE，未设定初始值的数组视为动态数组 lock为FALSE*/
        bool funcRtnLock() {
            return this->_lock;
        }

        void funcPrint() {
            auto p = [&](myArray* arr) {
                if (!arr->funcRtnLen()) {
                    std::cout << "this array is empty !" << std::endl;
                }
                else {
                    for (int i = 0; i < arr->funcRtnLen(); i++) {
                        std::cout << "  " << arr->funcRtnAt(i);
                    }
                    std::cout << std::endl;
                }
            };
            p(this);
        }

        int funcRtnFind(int target) {
            /*
            You can find a target by this function, and to get the index in the meantime.*/
            int flag = -1;
            if (!this->_len) {
                return flag;
            }
            for (int i = 0; i < this->_len; i++) {
                if (this->_array[i] == target) {
                    flag = i;
                    break;
                }
            }
            return flag;
        }
        int funcRtnAt(int loc) {
            /*
            You can get the value in location at 'loc'*/
            if (loc >= this->_len || loc < 0) {
                return INT_MIN;
            }
            return this->_array[loc];
        }

        bool funcInsert(int val, int loc) {
            /*
            */
            if (loc <= 0 || loc > this->_len + 1) {
                std::cout << "err: An error location you had put in." << std::endl;
                return false;
            }
            else {
                /* 
                Because of the lack of square, You need to submit a request by 'new' to store the new number.*/
                if (this->_len == this->_size && !this->_lock) {
                    int* temp = new int[this->_size + 1];
                    int j = 0;
                    int i = 0;
                    while (j < this->_size + 1) {
                        if (j == loc - 1) {
                            temp[j] = val;
                            j++;
                        }
                        else {
                            temp[j] = this->_array[i];
                            j++; i++;
                        }
                    }
                    try{
                        delete[]this->_array;
                        this->_array = temp;
                        this->_len++;
                        this->_size++;
                        return true;
                    }
                    catch (const std::exception&){
                        std::cout << "err: can not delete the original array." << std::endl;
                        delete[]temp;
                        return false;
                    }
                }
                else if(this->_len < this->_size) {
                    /*
                    it's enough to get a number in.*/
                    this->_array[_len] = val;
                    /*
                    error code: C6292 for-loop count error!
                    interpretation: Count from biggest number to the over is not permit.*/
                    for (int i = this->_len; i >= loc; i--) {
                        std::swap(this->_array[i], this->_array[i - 1]);
                    }
                    this->_len++;
                    return true;
                }
                else {
                    std::cout << "err: this array's size is locked to " << this->_size << std::endl;
                    return false;
                }
            }
        }

        bool funcPushback(int numInt) {
            /*
            if the square is enough:
                push_back directly.
            else if square is not enough but lock is false:
                to extend the square and push the new value into the end.
            else 
                return false: that the square can not be extended.
                
            */
            if (this->_len < this->_size) {
                this->_array[this->_len] = numInt;
                this->_len++;
                return true;
            }
            else if (this->_len == this->_size && !this->_lock) {
                int* temp = new int[this->_size + 1];
                for (int i = 0; i < this->_len; i++) {
                    temp[i] = this->_array[i];
                }
                temp[this->_len] = numInt;
                try{
                    delete[]this->_array;
                    this->_array = temp;
                    this->_len++;
                    this->_size++;
                    return true;
                }
                catch (const std::exception&){
                    std::cout << "err: delete array failed." << std::endl;
                    delete[]temp;
                    return false;
                }
            }
            else {
                std::cout << "err: array extension is forbiden." << std::endl;
                return false;
            }
        }
    };
}

#endif
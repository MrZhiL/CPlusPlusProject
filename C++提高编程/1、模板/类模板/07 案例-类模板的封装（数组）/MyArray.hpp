/*MyArray的代码*/ 
#pragma once
#include <iostream>
#include <string>

/******************************************
 *案例描述：实现一个通用的数组类，要求如下： 
 * 1、可以对内置数组类型以及自定义数据类型的数据进行存储
 * 2、将构造函数存储到堆区
 * 3、构造函数中可以传入数组的容量
 * 4、提供对用的拷贝构造函数以及operator=防止浅拷贝问题
 * 5、提供尾插法和尾删法对数组中的数据进行增加和删除
 * 6、可以通过下标的方式访问数组中的元素
 * 7、可以获取数组中当前元素个数和数组的容量 
 */

using namespace std;

template<class T>
class MyArray{
	
	public:
		// 有参构造函数（参数为数组的容量大小）
		MyArray(int capacity){
			//cout << "有参构造函数调用！" << endl; 
			// 初始化数组容量 
			this->m_Capacity = capacity;
			this->m_Size = 0;
			// 创建数组，并在堆区开启空间 
			this->pAddress = new T[this->m_Capacity];
			
		} 
		
		// 深拷贝构造函数（防止出现浅拷贝问题）
		// 因为为(深拷贝)构造函数，顾为构造函数，无需返回值，也无需void 
		MyArray (const MyArray &arr){
			//cout << "深拷贝构造函数调用！" << endl;
			this->m_Capacity = arr.m_Capacity;
			this->m_Size = arr.m_Size;
			// 如果直接进行等号赋值则为浅拷贝操作，会出现重复释放内存，从而导致内存错误
			// this->pAddress = arr.pAddress; // 错误 
			
			this->pAddress = new T[this->m_Capacity];
			for (int i=0; i<this->m_Size; i++){
				this->pAddress[i] = arr.pAddress[i];
			} 
		} 
	
		// operator=函数重载（也是为了防止出现浅拷贝问题，还需要包括连等号）
		MyArray& operator=(const MyArray &arr){
			//cout << "=函数重载函数调用！" << endl;
			// 在进行operator=时，需要先判断数组是否为空，如果不为空，则需要进行清空 
			if (this->pAddress != NULL){
				this->m_Capacity = 0;
				this->m_Size = 0;
				delete [] this->pAddress;
				this->pAddress = NULL; 
			}
			
			this->m_Capacity = arr.m_Capacity;
			this->m_Size = arr.m_Size;
			// 如果直接进行等号赋值则为浅拷贝操作，会出现重复释放内存，从而导致内存错误
			// this->pAddress = arr.pAddress; // 错误 
			
			this->pAddress = new T[this->m_Capacity];
			for (int i=0; i<this->m_Size; i++){
				this->pAddress[i] = arr.pAddress[i];
			} 
			
			return *this;
		} 
	
		// 尾插法
		void PushInsert(const T &arr){
			if (this->m_Capacity == this->m_Size){
				cout << "数组以达容量上限，无法插入!" << endl;
				return; 
			}
			
			// 如果数组为满，则在数组最后插入数据 
			this->pAddress[this->m_Size] = arr;
			this->m_Size++; 
			
		} 
		
		// 尾删法
		void BackDelete(){
			if(this->m_Size == 0){
				cout << "数组为空，无数据可删除！" << endl;
				return;
			}
			
			this->pAddress[this->m_Size--] = 0;
			//this->m_Size--;
		}
		 
		// 通过下标的方式访问数组中的元素(需要重载operator[])
		T& operator[] (int index){
			return this->pAddress[index];
		} 
		 
		// 输出数组的容量大小(T& 表示输出后可以作为左值：arr[i] = 100;)
		int& PrintCapacity(){
			return this->m_Capacity;
		}
		
		// 输出数组的大小（即共存放多少数据） 
		int PrintSize(){
			return this->m_Size;
		}
	
		// 析构函数
		~MyArray(){
			//cout << "析构函数调用！" << endl;
			if(this->pAddress != NULL){
				delete [] this->pAddress;
				this->m_Size = 0;
				this->m_Capacity = 0;
				this->pAddress = NULL;
			}
			
		}
		 
	private:
		T *pAddress;			// 自定义数组的地址 
		int m_Capacity;			// 数组的容量大小 
		int m_Size;				// 数组的大小 
}; 

/*MyArray�Ĵ���*/ 
#pragma once
#include <iostream>
#include <string>

/******************************************
 *����������ʵ��һ��ͨ�õ������࣬Ҫ�����£� 
 * 1�����Զ��������������Լ��Զ����������͵����ݽ��д洢
 * 2�������캯���洢������
 * 3�����캯���п��Դ������������
 * 4���ṩ���õĿ������캯���Լ�operator=��ֹǳ��������
 * 5���ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
 * 6������ͨ���±�ķ�ʽ���������е�Ԫ��
 * 7�����Ի�ȡ�����е�ǰԪ�ظ�������������� 
 */

using namespace std;

template<class T>
class MyArray{
	
	public:
		// �вι��캯��������Ϊ�����������С��
		MyArray(int capacity){
			//cout << "�вι��캯�����ã�" << endl; 
			// ��ʼ���������� 
			this->m_Capacity = capacity;
			this->m_Size = 0;
			// �������飬���ڶ��������ռ� 
			this->pAddress = new T[this->m_Capacity];
			
		} 
		
		// ������캯������ֹ����ǳ�������⣩
		// ��ΪΪ(���)���캯������Ϊ���캯�������践��ֵ��Ҳ����void 
		MyArray (const MyArray &arr){
			//cout << "������캯�����ã�" << endl;
			this->m_Capacity = arr.m_Capacity;
			this->m_Size = arr.m_Size;
			// ���ֱ�ӽ��еȺŸ�ֵ��Ϊǳ����������������ظ��ͷ��ڴ棬�Ӷ������ڴ����
			// this->pAddress = arr.pAddress; // ���� 
			
			this->pAddress = new T[this->m_Capacity];
			for (int i=0; i<this->m_Size; i++){
				this->pAddress[i] = arr.pAddress[i];
			} 
		} 
	
		// operator=�������أ�Ҳ��Ϊ�˷�ֹ����ǳ�������⣬����Ҫ�������Ⱥţ�
		MyArray& operator=(const MyArray &arr){
			//cout << "=�������غ������ã�" << endl;
			// �ڽ���operator=ʱ����Ҫ���ж������Ƿ�Ϊ�գ������Ϊ�գ�����Ҫ������� 
			if (this->pAddress != NULL){
				this->m_Capacity = 0;
				this->m_Size = 0;
				delete [] this->pAddress;
				this->pAddress = NULL; 
			}
			
			this->m_Capacity = arr.m_Capacity;
			this->m_Size = arr.m_Size;
			// ���ֱ�ӽ��еȺŸ�ֵ��Ϊǳ����������������ظ��ͷ��ڴ棬�Ӷ������ڴ����
			// this->pAddress = arr.pAddress; // ���� 
			
			this->pAddress = new T[this->m_Capacity];
			for (int i=0; i<this->m_Size; i++){
				this->pAddress[i] = arr.pAddress[i];
			} 
			
			return *this;
		} 
	
		// β�巨
		void PushInsert(const T &arr){
			if (this->m_Capacity == this->m_Size){
				cout << "�����Դ��������ޣ��޷�����!" << endl;
				return; 
			}
			
			// �������Ϊ���������������������� 
			this->pAddress[this->m_Size] = arr;
			this->m_Size++; 
			
		} 
		
		// βɾ��
		void BackDelete(){
			if(this->m_Size == 0){
				cout << "����Ϊ�գ������ݿ�ɾ����" << endl;
				return;
			}
			
			this->pAddress[this->m_Size--] = 0;
			//this->m_Size--;
		}
		 
		// ͨ���±�ķ�ʽ���������е�Ԫ��(��Ҫ����operator[])
		T& operator[] (int index){
			return this->pAddress[index];
		} 
		 
		// ��������������С(T& ��ʾ����������Ϊ��ֵ��arr[i] = 100;)
		int& PrintCapacity(){
			return this->m_Capacity;
		}
		
		// �������Ĵ�С��������Ŷ������ݣ� 
		int PrintSize(){
			return this->m_Size;
		}
	
		// ��������
		~MyArray(){
			//cout << "�����������ã�" << endl;
			if(this->pAddress != NULL){
				delete [] this->pAddress;
				this->m_Size = 0;
				this->m_Capacity = 0;
				this->pAddress = NULL;
			}
			
		}
		 
	private:
		T *pAddress;			// �Զ�������ĵ�ַ 
		int m_Capacity;			// �����������С 
		int m_Size;				// ����Ĵ�С 
}; 

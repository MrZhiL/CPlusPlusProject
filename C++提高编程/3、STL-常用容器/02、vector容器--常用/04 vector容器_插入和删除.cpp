#include<iostream>
#include<vector>

using namespace std;

/**
	push_back(ele);									//在尾部插入元素ele 
	pop_back();										//删除最后一个元素 
	insert(const_iterator pos, ele);				//在 迭代器指 定位置pos插入元素ele 
	insert(cosnt_iterator pos, int count, ele);		//在 迭代器 指定位置pos插入count个ele 
	erase(const_iterator pos);						//删除 迭代器 指定位置pos的元素 
	erase(const_iterator start, const_iterator end);//删除 迭代器 从start到end之间的元素 
	clear();//删除容器中所有元素 
*/ 

// 输出容器中的元素 
void printVector(vector<int> &vec){
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}
// 判断容器是否为空
void IsEmptyVector(vector<int> &vec){
	
	if(vec.empty()){
		cout << "容器为空！" << endl;
		return;
	}else{
		cout << "该容器的容量为：" << vec.capacity() << " ";
		cout << "该容器的大小为：" << vec.size() << "  ";
		cout << "元素为：";
		printVector(vec);
	}
	
} 

void test01(){
	
	vector<int> vec;
	IsEmptyVector(vec); 
	//printVector(vec);
	for(int i=0; i<10; i++){
		vec.push_back(i+1);	//使用push_back()尾插法在最后插入元素 
	}
	IsEmptyVector(vec);
	
	vec.pop_back();			//使用pop_back()尾删法删除最后一个元素
	IsEmptyVector(vec);
	
	// 需要使用迭代器 
	vec.insert(vec.begin(),5,5);		//在 迭代器 头部插入5个5 
	IsEmptyVector(vec);
	
	// 使用迭代器去，删除vec容器的第一个数据 
	vec.erase(vec.begin());
	IsEmptyVector(vec);
	
	// 情况所有数据，相当于clear(); 
	vec.erase(vec.begin(),vec.end());
	IsEmptyVector(vec);
	
	vec.clear();//删除容器中所有元素 
	IsEmptyVector(vec);
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 

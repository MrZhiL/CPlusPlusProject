//queue容器：队列中只允许一端插入数据，一端移除数据
//队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为 
// 队列不支持迭代器，更不支持随机访问 

/**
	构造函数：queue<T> que;				//queue采用模板类实现，queue对象的默认构造形式 
			  queue(const queue &que);	//拷贝构造函数 
					  
	赋值操作：queue& operator=(const queue &que);	//重载等号运算符 
			
	数据存取：	push(elem);				//往队尾添加elem元素 
				pop();					//从对头移除第一个元素 
				back();					//返回最后一个元素 
				front();				//返回第一个元素 
					  
	大小操作：	empty(); 	    		//判断队列是否为空 
				size();					//返回队列的大小  
*/

#include<iostream>
#include<queue>

using namespace std;

//队列的实现是FIFO，先入先出 
void test01(){
	
	queue<int> que;	// 默认构造函数
	
	que.push(11);
	que.push(22);
	que.push(33);
	que.push(44);
	// push 4个元素后，队列中的内容为：11 22 33 44。根据FIFO可知，pop出队列的内容为：11 22 33 44 
	cout << "que的队列大小为：" << que.size() << endl;
	
	/*如果队列que不为空，则打印头部数据和尾部数据，并移除尾部数据*/
	while( !que.empty() ) {
		cout << "que的头部数据元素为：" << que.front(); 
		cout << "  ,que的尾部数据元素为：" << que.back() << endl; 
		que.pop();
	} 
	cout << "que的队列大小为：" << que.size() << endl;
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 

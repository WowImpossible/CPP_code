#define _CRT_SECURE_NO_WARNINGS 1

//USE TO PROVR VOID *
#include <iostream>
#include <stdio.h>
using namespace std;


void* test(void* a)
{
    return a;
}

int main() {

    static int a = 5;
    int* pi = &a;
    void* pv = NULL;
    pv = &a;


    cout << pi << endl;              //值为0x100001060
    cout << test(pi) << endl;        //值为0x100001060
    cout << test((void*)pi) << endl; //值为0x100001060
    cout << pv << endl;              //right ,if donnot acquire value of this address.
    //cout << *pv << endl;          //have some problems.\
                                      因为void* 类型的指针解引用不能确定类型,不清楚能够操作多大的字节空间(一个地址代表一个字节)\
                                      这就是为什么要引入int *和char *的原因。都是一个地址，但是可以访问的范围不一样
}

//USE TO PROVR CALLBACK FUNCTION
//#include <stdio.h>
//#include <string.h>
//#include <iostream>     //c++的用法，要写这个才可以使用cout
//using namespace std;    //命名空间，输出到屏幕上
//
//
//typedef int (callBack)(const void* buffer, size_t size, char* p_out);//typedef 为C语言的关键字，作用是为一种数据类型定义一个新名字(\表示换行) \
//                                                                  这句话的意思，重新定义一个类型：函数类型，函数的参数是括号里面的，返回值是int类型的
//
////typedef int (callBack2*)(const void* buffer, size_t size, char* p_out);//这句话的意思是：定义了一个 函数指针类型 ，\
//                                                                          函数类型，函数的参数是括号里面的，返回值是int类型的
////void callFunc2(callBack consume_bytes, char* p_out) {                 //这里就是用了这个函数指针类型，consume_bytes 就是函数指针。
////    printf("callFunc\n");
////    const void* buffer = NULL;
////    consume_bytes(buffer, 0, p_out); //传入值可以随便填
////}
//
//void callFunc(callBack* consume_bytes, char* p_out) {             //这里就是用了这个函数类型，callBack* 就是函数指针，类似于int *。
//    printf("callFunc\n");
//    const void* buffer = NULL;
//    consume_bytes(buffer, 0, p_out); //传入值可以随便填
//}
//
//int callBackFunc(const void* buffer, size_t size, char* p_out) {
//    printf("callBackFunc\n");
//    memset(p_out, 'a', sizeof(char) * 100);  //Sets buffers to a specified character.将数组中的元素全部设置成0.
//    for (int i = 0; i < 10; i++)
//    {
//        cout << p_out[i] << endl;
//    }
//    strcpy(p_out, "encoderCallback:this is string.");
//    return 1;
//}
//
//int main(int argc, char* args[]) {
//    char p_out[100];
//    callFunc(callBackFunc, p_out);
//    printf("%s\n", p_out);
//    return 0；
//}



//USE TO PROVE TYPEDEF'S USEAGE
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//typedef void (*FP)(const char* s);
//void f1(const char* s) { cout << s; }
//void f2(const char* s) { cout << s; }
//void f3(const char* s) { cout << s; }
//
//int main(int argc, char* argv[])
//{
//    void* a[] = { f1,f2,f3 };   //定义了指针数组，这里a是一个普通指针
// //   (*a[0])("Hello World!\n"); //编译错误，指针数组不能用下标的方式来调用函数\
//                                 因为没人告诉它里面放的是函数地址是可以带参数，它默认的就是一个变量的地址，而地址是不可以带括号的。
//
//    FP f[] = { f1,f2,f3 };      //定义一个函数指针的数组，这里的f是一个函数指针
//    f[0]("Hello World!\n"); //正确，函数指针的数组进行下标操作可以进行函数的间接调用.\
//                            因为宏定义的时候告诉了它，他是函数指针，后面是可以带参数的
//
//    return 0;
//}




//引用的用法
//引用没有独立的内存，它要与它所引用的变量共享空间
//对引用所做的改变实际上是对它所引用的变量的改变
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//int main()
//{
//	int val = 100;
//	const int& reval = val;
//
//	val = 200;
//	//reval = 500;      Error because reval's defination is const int ,but val can be changed.if val change,reval will be changed.
//	
//	cout << "reval=" << reval << endl;
//	cout << "val=" << val << endl;
//
//
//	return 0;
//}





//::的用法: ::访问的是全局变量，如果没有全局变量就会报错："num": 不是 "`global namespace'" 的成员	

//int num = 200;
//
//int main()
//{
//	int num = 100;
//
//	{
//		int num = 300;
//		cout << "nun = " << num << endl;
//		cout << "::num = " << ::num << endl;
//	}
//	cout << "nun = " << num << endl;
//	cout << "::num = " << ::num << endl;
//
//
//	return 0;
//}
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


    cout << pi << endl;              //ֵΪ0x100001060
    cout << test(pi) << endl;        //ֵΪ0x100001060
    cout << test((void*)pi) << endl; //ֵΪ0x100001060
    cout << pv << endl;              //right ,if donnot acquire value of this address.
    //cout << *pv << endl;          //have some problems.\
                                      ��Ϊvoid* ���͵�ָ������ò���ȷ������,������ܹ����������ֽڿռ�(һ����ַ����һ���ֽ�)\
                                      �����ΪʲôҪ����int *��char *��ԭ�򡣶���һ����ַ�����ǿ��Է��ʵķ�Χ��һ��
}

//USE TO PROVR CALLBACK FUNCTION
//#include <stdio.h>
//#include <string.h>
//#include <iostream>     //c++���÷���Ҫд����ſ���ʹ��cout
//using namespace std;    //�����ռ䣬�������Ļ��
//
//
//typedef int (callBack)(const void* buffer, size_t size, char* p_out);//typedef ΪC���ԵĹؼ��֣�������Ϊһ���������Ͷ���һ��������(\��ʾ����) \
//                                                                  ��仰����˼�����¶���һ�����ͣ��������ͣ������Ĳ�������������ģ�����ֵ��int���͵�
//
////typedef int (callBack2*)(const void* buffer, size_t size, char* p_out);//��仰����˼�ǣ�������һ�� ����ָ������ ��\
//                                                                          �������ͣ������Ĳ�������������ģ�����ֵ��int���͵�
////void callFunc2(callBack consume_bytes, char* p_out) {                 //������������������ָ�����ͣ�consume_bytes ���Ǻ���ָ�롣
////    printf("callFunc\n");
////    const void* buffer = NULL;
////    consume_bytes(buffer, 0, p_out); //����ֵ���������
////}
//
//void callFunc(callBack* consume_bytes, char* p_out) {             //���������������������ͣ�callBack* ���Ǻ���ָ�룬������int *��
//    printf("callFunc\n");
//    const void* buffer = NULL;
//    consume_bytes(buffer, 0, p_out); //����ֵ���������
//}
//
//int callBackFunc(const void* buffer, size_t size, char* p_out) {
//    printf("callBackFunc\n");
//    memset(p_out, 'a', sizeof(char) * 100);  //Sets buffers to a specified character.�������е�Ԫ��ȫ�����ó�0.
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
//    return 0��
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
//    void* a[] = { f1,f2,f3 };   //������ָ�����飬����a��һ����ָͨ��
// //   (*a[0])("Hello World!\n"); //�������ָ�����鲻�����±�ķ�ʽ�����ú���\
//                                 ��Ϊû�˸���������ŵ��Ǻ�����ַ�ǿ��Դ���������Ĭ�ϵľ���һ�������ĵ�ַ������ַ�ǲ����Դ����ŵġ�
//
//    FP f[] = { f1,f2,f3 };      //����һ������ָ������飬�����f��һ������ָ��
//    f[0]("Hello World!\n"); //��ȷ������ָ�����������±�������Խ��к����ļ�ӵ���.\
//                            ��Ϊ�궨���ʱ��������������Ǻ���ָ�룬�����ǿ��Դ�������
//
//    return 0;
//}




//���õ��÷�
//����û�ж������ڴ棬��Ҫ���������õı�������ռ�
//�����������ĸı�ʵ�����Ƕ��������õı����ĸı�
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





//::���÷�: ::���ʵ���ȫ�ֱ��������û��ȫ�ֱ����ͻᱨ��"num": ���� "`global namespace'" �ĳ�Ա	

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
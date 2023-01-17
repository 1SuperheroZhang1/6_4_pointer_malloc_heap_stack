#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * 6.4 指针与malloc动态内存申请，栈和堆的差异
 *  Ⅰ、指针与malloc动态内存申请
 *   C语言的数组长度固定是因为其定义的整型、浮点型、字符型变量、数组变量都在栈空间中，而栈空间的大小在编译时是确定的。
 *   如果想要定义变长的数组，需要使用堆空间。
 *   > malloc函数：
 *        头文件：#include<stdlib.h>
 *        函数原型：void *malloc(size_t size);
 *            size_t即为int
 *           返回值为void*类型的指针，void*类型的指针只能用来存储一个地址而不能进行偏移
 *   > 指针本身的大小和指针指向的空间大小是两码事，不能和前面的变量类比去理解。
 *   > free函数：用来释放堆空间
 *        头文件：#include<stdlib.h>
 *        函数原型：void free(void *ptr);
 *   Ⅱ、栈空间和堆空间差异：
 *      > 栈：是计算机系统提供的数据结构，计算机会在底层对栈提供支持，分配专门的寄存器存放
 *           栈的地址，压栈操作、出栈操作都有专门的指令执行，这就决定了栈的效率比较高。
 *      > 堆：是C/C++函数库提供的数据结构，它的机制很复杂，堆的效率要比栈低得多。
 *      > 差异：栈空间在函数执行完毕后，就会销毁
 *             堆空间只有在执行free操作后才会释放，否则会一直有效。
 * */
//指针和malloc动态内存申请
//int main() {
//    int size; //size代表要申请空间的大小
//    char *p;//void*类型的指针不能偏移，因此不会定义无类型指针
//    scanf("%d",&size);//输入要申请的空间大小
//    //malloc返回的void*代表无类型指针
//    p=(char*)malloc(size);//使用malloc动态申请堆空间
//    strcpy(p,"malloc success");
//    puts(p);
//    free(p);//free时必须使用malloc申请时返回的指针值，不能进行任何偏移
//    printf("free success\n");
//    return 0;
//}

//函数栈空间释放后，函数内的所有局部变量消失
char* print_stack(){
    char c[17]="i am print_stack";
    puts(c);
    return c;
}
//堆空间不会因为函数执行结束而释放
char* print_malloc(){
    char *p;
    p=(char*)malloc(20);
    strcpy(p,"i am print_malloc");
    puts(p);
    return p;
}
//栈空间和堆空间的差异
int main(){
    char *p;
    p=print_stack();//数据放在栈空间
//    puts(p);
    printf("p=%s\n",p);
    p=print_malloc();//数据放在堆空间
    puts(p);
    return 0;
}

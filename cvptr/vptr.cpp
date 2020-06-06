/**********************************************************
create: 2020/5/24.

author: chensong 
**********************************************************/
//
#include <iostream>

static  const char * p = "232.34";

class cvptr
{
public:
    void vptr1()
    {
        std::cout << "vptr1" << std::endl;
    }
    void vptr2()
    {
        std::cout << "vptr2" << std::endl;
    }
};

int main(int argc, char *argv[])
{

    std::cout << p << std::endl;
    cvptr * ptr = new cvptr();
    if (!ptr)
    {
        std::cout << "new failed !!!" << std::endl;
        return -1;
    }


    std::cout << "sizeof(class cvptr) = " <<  sizeof(class cvptr) << std::endl;



    (ptr->*(&cvptr::vptr1))();

//    typedef void (*func1)() ;
//    func1 p= (func1)(ptr +1);
//
//    p();

//    typedef void( __stdcall *CATEAT)(int);
//    (CATEAT(*((int*)*(int*)ptr + 1)))(10);



    // ptr->vptr2();

    return  EXIT_SUCCESS;
}

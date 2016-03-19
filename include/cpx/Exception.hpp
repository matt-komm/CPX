#ifndef __CPX_EXCEPTION_H__
#define __CPX_EXCEPTION_H__

#include <stdexcept>
#include <sstream>


namespace cpx
{
    static void expandArgs(std::stringstream& stream)
    {
    }
    template<class VALUE, class ...ARGS>  static void expandArgs(std::stringstream& stream, VALUE value, ARGS... args)
    {
        stream<<value;
        expandArgs(stream,args...);
    }

}


#define cpx_throw(...) \
    std::stringstream ss; cpx::expandArgs(ss,__VA_ARGS__); throw std::runtime_error(ss.str());


#endif


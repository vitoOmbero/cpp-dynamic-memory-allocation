#include <cstdlib>
#include <dlfcn.h>
#include <iostream>

#include "./client_src/rescons.h"
#include "./shared_lib_src/resprov.h"

const char* libname{ "libresprov.so.1" };
void*       handle;

void LoadFunctions(mylib::resprov_loaded_ptrs& fpc /*out*/)
{
    using namespace foreignlib_load;

    handle = dlopen(libname, RTLD_LAZY);

    if (NULL == handle)
    {
        std::cerr << dlerror() << std::endl;
        std::terminate();
    }

    fpc.CreateSuperbMatrix =
        (ptrs::CreateSuperbMatrix)dlsym(handle, symbols::CreateSuperbMatrix);
    fpc.DestroySuperbMatrix =
        (ptrs::DestroySuperbMatrix)dlsym(handle, symbols::DestroySuperbMatrix);
    fpc.getDescriptorStatus =
        (ptrs::getDescriptorStatus)dlsym(handle, symbols::getDescriptorStatus);
    fpc.getSuperbMatrixRows =
        (ptrs::getSuperbMatrixRows)dlsym(handle, symbols::getSuperbMatrixRows);
    fpc.SuperbMatrixCount =
        (ptrs::SuperbMatrixCount)dlsym(handle, symbols::SuperbMatrixCount);
}

int main(/*int argc, char* argv[]*/)
{
    mylib::resprov_loaded_ptrs fp_container;

    LoadFunctions(fp_container);

    mylib::Scenario_01_No_Problems(fp_container);

    dlclose(handle);

    return 0;
}
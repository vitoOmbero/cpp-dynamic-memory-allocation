#ifndef RESCONS_H
#define RESCONS_H

#include "../shared_lib_src/foreighnlib_load.h"

namespace mylib
{

struct resprov_loaded_ptrs
{
    foreignlib_load::ptrs::CreateSuperbMatrix  CreateSuperbMatrix;
    foreignlib_load::ptrs::DestroySuperbMatrix DestroySuperbMatrix;
    foreignlib_load::ptrs::getDescriptorStatus getDescriptorStatus;
    foreignlib_load::ptrs::getSuperbMatrixRows getSuperbMatrixRows;
    foreignlib_load::ptrs::SuperbMatrixCount   SuperbMatrixCount;
};

void Scenario_01_No_Problems(resprov_loaded_ptrs& fpc);

void Scenario_02_Alloc_Problems(resprov_loaded_ptrs& fpc);

} // namespace mylib

#endif
#ifndef FOREIGHNLIB_LOAD_H
#define FOREIGHNLIB_LOAD_H

#include <stddef.h>
#include <stdint.h>

#include "resprov.h"



namespace foreignlib_load::ptrs
{
using CreateSuperbMatrix  = foreignlib::smat_t (*)(size_t rows, size_t columns);
using SuperbMatrixCount   = int8_t (*)();
using getSuperbMatrixRows = int (*)(foreignlib::smat_t descriptor);
using getDescriptorStatus =
    foreignlib::DescriptorStatus (*)(foreignlib::smat_t descriptor);
using DestroySuperbMatrix = void (*)(foreignlib::smat_t descriptor);
} // namespace foreignlib_load::ptrs


#ifndef PTRS_ONLY
namespace foreignlib_load::symbols
{
#ifndef EXTERN_C
static const char* CreateSuperbMatrix =
    "_ZN10foreignlib9version_118CreateSuperbMatrixEmm";
static const char* SuperbMatrixCount =
    "_ZN10foreignlib9version_117SuperbMatrixCountEv";
static const char* getSuperbMatrixRows =
    "_ZN10foreignlib9version_119getSuperbMatrixRowsEi";
static const char* getDescriptorStatus =
    "_ZN10foreignlib9version_119getDescriptorStatusEi";
static const char* DestroySuperbMatrix =
    "_ZN10foreignlib9version_119DestroySuperbMatrixEi";

#else

static const char* CreateSuperbMatrix =
    "CreateSuperbMatrix";
static const char* SuperbMatrixCount =
    "SuperbMatrixCount";
static const char* getSuperbMatrixRows =
    "getSuperbMatrixRows";
static const char* getDescriptorStatus =
    "getDescriptorStatus";
static const char* DestroySuperbMatrix =
    "DestroySuperbMatrix";
#endif // EXTERN_C
} // namespace foreignlib_load::symbols
#endif

#endif
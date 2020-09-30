#include <iostream>

#include "resprov.h"

#if defined(EXTERN_C)
#define MANGLING extern "C"
#else
#define MANGLING
#endif

namespace foreignlib
{

namespace
{
#ifdef __linux__
const char* TAG{ "[LIB.SO]" };
#endif
#if defined(_WIN64) || defined(_WIN32)
const char* TAG{ "[DLL]" };
#endif

static int8_t           descriptor_counter{ 0 };
static const int8_t     DESCRIPTOR_COUNTER_MAX = INT8_MAX;
static int**            ptr_arr[DESCRIPTOR_COUNTER_MAX]{};
static DescriptorStatus stat_arr[DESCRIPTOR_COUNTER_MAX]{
    DescriptorStatus::kInvalid
};
static int rows_arr[DESCRIPTOR_COUNTER_MAX]{};

} // namespace

#ifdef LIB_API_VER_1
inline namespace version_1
{
smat_t AbortCreationSuperbMatrix(int** ptr);

MANGLING smat_t CreateSuperbMatrix(size_t rows, size_t columns)
{
    if (DESCRIPTOR_COUNTER_MAX != descriptor_counter)
    {
#ifdef SUPERBMAT_DEBUG
        std::cout << TAG << "descriptor_counter: " << (int)descriptor_counter
                  << std::endl;
#endif
    }

    else
    {
#ifdef SUPERBMAT_DEBUG
        std::cout << TAG
                  << "Unable to create one more superb matrix. Release "
                     "unnecessary descriptors and        try            again."
                  << std::endl;
#endif
        return smat_t(descriptor_counter);
    }

    int** ptr = nullptr;

    size_t i{ 0 };

    ptr = new (std::nothrow) int*[rows];

    if (nullptr == ptr)
    {
#ifdef SUPERBMAT_DEBUG
        std::cout
            << TAG
            << "The suprb matrix creation is aborted: can not alloc memory!"
            << std::endl;
#endif
        return AbortCreationSuperbMatrix(ptr);
    }

    for (; i < rows; ++i)
    {
        ptr[i] = new (std::nothrow) int[columns];
        if (nullptr == ptr[i])
        {
#ifdef SUPERBMAT_DEBUG
            std::cout << TAG
                      << "The suprb matrix creation is interrupted at row ["
                      << i << "]: can not alloc memory!" << std::endl;
#endif
            for (size_t j = i; j <= 0; ++j)
            {
                delete ptr[i];
            }
            return AbortCreationSuperbMatrix(ptr);
        }
    }
#ifdef SUPERBMAT_DEBUG
    std::cout << TAG << "One more suprb matrix is just created!" << std::endl;
    std::cout << TAG << "descriptor_counter: " << (int)descriptor_counter
              << std::endl;
#endif
    ++descriptor_counter;
    ptr_arr[descriptor_counter]  = ptr;
    rows_arr[descriptor_counter] = rows;
    stat_arr[descriptor_counter] = DescriptorStatus::kValid;

    return smat_t(descriptor_counter);
}

smat_t AbortCreationSuperbMatrix(int** ptr)
{
#ifdef SUPERBMAT_DEBUG
    std::cout << TAG << "AbortCreationSuperbMatrix" << std::endl;
#endif
    delete[] ptr;
    ptr = nullptr;
#ifdef SUPERBMAT_DEBUG
    std::cout << TAG << "descriptor_counter: " << (int)descriptor_counter
              << std::endl;
#endif
    return smat_t(descriptor_counter);
}

MANGLING int8_t SuperbMatrixCount()
{
    return descriptor_counter + 1;
}

MANGLING int getSuperbMatrixRows(smat_t descriptor)
{
    return rows_arr[descriptor];
}

MANGLING DescriptorStatus getDescriptorStatus(smat_t descriptor)
{
    return stat_arr[descriptor];
}

MANGLING void DestroySuperbMatrix(smat_t descriptor)
{
    int** ptr = ptr_arr[descriptor];

    if (ptr != nullptr)
        for (int i = 0; i < rows_arr[descriptor]; ++i)
        {
            delete[] ptr[i];
        }
    delete[] ptr_arr[descriptor];
    ptr_arr[descriptor] = nullptr;

    stat_arr[descriptor] = DescriptorStatus::kDeleted;
    --descriptor_counter;

#ifdef SUPERBMAT_DEBUG
    std::cout << TAG << "One more suprb matrix is just DELETED!" << std::endl;
#endif
}

} // namespace version_1
#endif
} // namespace foreignlib
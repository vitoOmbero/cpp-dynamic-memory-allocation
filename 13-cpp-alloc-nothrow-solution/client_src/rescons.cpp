#include <iostream>
#include <stddef.h>

#include "rescons.h"

namespace mylib
{

namespace
{
#ifdef __linux__
const char* TAG{ "[LINUX-client]" };
#endif
#if defined(_WIN64) || defined(_WIN32)
const char* TAG{ "[WIN-client]" };
#endif
} // namespace

void Scenario_01_No_Problems(resprov_loaded_ptrs& fpc)
{

    const size_t MATMAX = 50;

    const foreignlib::smat_t DEFAULT_DESCRIPTOR =
        (foreignlib::smat_t)foreignlib::DescriptorStatus::kInvalid;

    foreignlib::smat_t mat_desc[MATMAX]{ DEFAULT_DESCRIPTOR };

    int step = 20;

    size_t rows = 10;
    size_t cols = 10;

    for (size_t i = 0; i < MATMAX; ++i)
    {
        std::cout << TAG << " Going to create new (" << i << "/" << MATMAX
                  << ") SuperB Matrix!!! " << std::endl;
        mat_desc[i] = fpc.CreateSuperbMatrix(rows, cols);
        std::cout << TAG << " Got it!!! " << std::endl;
        rows += step;
        cols += step;
    }

    for (auto i : mat_desc)
    {
        std::cout << TAG << " Going to destroy: " << i
                  << " getDescriptorStatus: " << (int)fpc.getDescriptorStatus(i)
                  << " getSuperbMatrixRows: " << fpc.getSuperbMatrixRows(i)
                  << " SuperbMatrixCount: " << (int)fpc.SuperbMatrixCount()
                  << std::endl;
        fpc.DestroySuperbMatrix(i);
    }
}

void Scenario_02_Alloc_Problems(resprov_loaded_ptrs& fpc)
{
    std::cout << TAG << " Scenario is not realized yet... " << std::endl;
}

} // namespace mylib
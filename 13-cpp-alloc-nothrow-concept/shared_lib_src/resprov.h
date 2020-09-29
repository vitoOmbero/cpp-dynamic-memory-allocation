#ifndef RESPROV_H
#define RESPROV_H

#define LIB_API_VER_1
#define SUPERBMAT_DEBUG
#define EXTERN_C

namespace foreignlib
{

enum class DescriptorStatus
{
    kValid   = 0,
    kInvalid = -1,
    kDeleted = -8,
};

struct DescriptorMaxException : public std::exception
{
    const char* what() const throw()
    {
        return "Unable to create one more superb matrix. Release unnecessary "
               "descriptors and try again.";
    }
};

using smat_t = int;

smat_t CreateSuperbMatrix(size_t rows, size_t columns);

int8_t           SuperbMatrixCount();
int              getSuperbMatrixRows(smat_t descriptor);
DescriptorStatus getDescriptorStatus(smat_t descriptor);

void DestroySuperbMatrix(smat_t descriptor);

} // namespace foreignlib

#endif // RESPROV_H
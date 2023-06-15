
/**
 * @file kernel_main.cpp
 * @brief 内核主要逻辑
 * @author Zone.N (Zone.Niuzh@hotmail.com)
 * @version 1.0
 * @date 2021-09-18
 * @copyright MIT LICENSE
 * https://github.com/Simple-XX/SimpleKernel
 * @par change log:
 * <table>
 * <tr><th>Date<th>Author<th>Description
 * <tr><td>2021-09-18<td>digmouse233<td>迁移到 doxygen
 * </table>
 */

#include "boot_info.h"
#include "common.h"
#include "cstdint"
#include "cstdio"
#include "iostream"
#include "kernel.h"

#include "efi.h"
#include "efilib.h"

/**
 * @brief 内核主要逻辑
 * @note 这个函数不会返回
 */
void kernel_main(void* _systemtable) {
#if defined(__x86_64__)
    EFI_SYSTEM_TABLE* systemTable = (EFI_SYSTEM_TABLE*)_systemtable;
    EFI_STATUS        status
      = uefi_call_wrapper(systemTable->ConOut->OutputString, 2,
                          systemTable->ConOut, L"Hello UEFI111!\n");

    EFI_STATUS             Status;
    EFI_MEMORY_DESCRIPTOR* EfiMemoryMap;
    ptrdiff_t              EfiMemoryMapSize;
    ptrdiff_t              EfiMapKey;
    ptrdiff_t              EfiDescriptorSize;
    UINT32                 EfiDescriptorVersion;

    //
    // Get the EFI memory map.
    //
    EfiMemoryMapSize = 0;
    EfiMemoryMap     = NULL;
    Status = uefi_call_wrapper(systemTable->BootServices->GetMemoryMap, 5,
                                         &EfiMemoryMapSize, EfiMemoryMap, &EfiMapKey,
                                         &EfiDescriptorSize, &EfiDescriptorVersion);
    ASSERT(Status == EFI_BUFFER_TOO_SMALL);

    //
    // Use size returned for the AllocatePool.
    //
    EfiMemoryMap
      = (EFI_MEMORY_DESCRIPTOR*)AllocatePool(EfiMemoryMapSize
                                             + 2 * EfiDescriptorSize);
    ASSERT(EfiMemoryMap != NULL);
    Status = uefi_call_wrapper(systemTable->BootServices->GetMemoryMap, 5,
                               &EfiMemoryMapSize, EfiMemoryMap, &EfiMapKey,
                               &EfiDescriptorSize, &EfiDescriptorVersion);
    if (EFI_ERROR(Status)) {
        FreePool(EfiMemoryMap);
    }

    //
    // Get descriptors
    //
    EFI_MEMORY_DESCRIPTOR* EfiEntry = EfiMemoryMap;
    do {
        // ... do something with EfiEntry ...
        EfiEntry = NextMemoryDescriptor(EfiEntry, EfiDescriptorSize);

    } while ((UINT8*)EfiEntry < (UINT8*)EfiMemoryMap + EfiMemoryMapSize);

#endif
    // 初始化
    BOOT_INFO::init();
    // 输出物理地址信息
    std::cout << BOOT_INFO::get_memory() << std::endl;
    // 显示基本信息
    show_info();
    // 进入死循环
    while (1) {
        ;
    }
    return;
}

/**
 * @brief 输出系统信息
 */
void show_info(void) {
    // 内核实际大小
    auto kernel_size  = COMMON::KERNEL_END_ADDR - COMMON::KERNEL_START_ADDR;
    // 内核实际占用页数
    auto kernel_pages = (COMMON::KERNEL_END_ADDR - COMMON::KERNEL_START_ADDR)
                      / COMMON::PAGE_SIZE;
    info("Kernel start: 0x%p, end 0x%p, size: 0x%X bytes, 0x%X pages.\n",
         COMMON::KERNEL_START_ADDR, COMMON::KERNEL_END_ADDR, kernel_size,
         kernel_pages);
    std::cout << "Simple Kernel." << std::endl;
    return;
}

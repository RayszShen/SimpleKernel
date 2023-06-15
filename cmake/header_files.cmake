
# This file is a part of Simple-XX/SimpleKernel
# (https://github.com/Simple-XX/SimpleKernel).
# Based on https://github.com/SynestiaOS/SynestiaOS
# header_files.cmake for Simple-XX/SimpleKernel.
# 将头文件路径添加到 Target 的搜索路径中

function(target_include_arch_header_files Target)
    target_include_directories(${Target} PRIVATE ${CMAKE_SOURCE_DIR}/arch/${ARCH})
    if (ARCH STREQUAL "x86_64")
        target_include_directories(${Target} PRIVATE ${CMAKE_SOURCE_DIR}/arch/${ARCH}/port/include)
    elseif (ARCH STREQUAL "riscv64")
        target_include_directories(${Target} PRIVATE ${CMAKE_SOURCE_DIR}/arch/${ARCH}/opensbi/include)
    elseif (ARCH STREQUAL "aarch64")
        target_include_directories(${Target} PRIVATE ${CMAKE_SOURCE_DIR}/arch/${ARCH}/port/include)
    endif ()
endfunction()

function(target_include_kernel_header_files Target)
    target_include_directories(${Target} PRIVATE ${CMAKE_SOURCE_DIR}/kernel/include)
endfunction()

function(target_include_gnu_efi_header_files Target)
    target_include_directories(${Target} PRIVATE ${CMAKE_SOURCE_DIR}/../3rd/gnu-efi/inc)
endfunction()

function(target_include_posix_uefi_header_files Target)
    target_include_directories(${Target} PRIVATE ${CMAKE_SOURCE_DIR}/../3rd/posix-uefi/uefi)
endfunction()

function(target_include_common_header_files Target)
    target_include_directories(${Target} PRIVATE ${CMAKE_SOURCE_DIR}/include)
endfunction()

function(target_include_drv_header_files Target)
    target_include_directories(${Target} PRIVATE ${CMAKE_SOURCE_DIR}/drv/tui/include)
    target_include_directories(${Target} PRIVATE ${CMAKE_SOURCE_DIR}/drv/uart/include)
    target_include_directories(${Target} PRIVATE ${CMAKE_SOURCE_DIR}/drv/opensbi/include)
    target_include_directories(${Target} PRIVATE ${CMAKE_SOURCE_DIR}/drv/sbi_console/include)
    target_include_directories(${Target} PRIVATE ${CMAKE_SOURCE_DIR}/drv/dtb/include)
    target_include_directories(${Target} PRIVATE ${CMAKE_SOURCE_DIR}/drv/multiboot2/include)
endfunction()

function(target_include_libc_header_files Target)
    target_include_directories(${Target} PRIVATE ${CMAKE_SOURCE_DIR}/libc/include)
endfunction()

function(target_include_libcxx_header_files Target)
    target_include_directories(${Target} PRIVATE ${CMAKE_SOURCE_DIR}/libcxx/include)
endfunction()

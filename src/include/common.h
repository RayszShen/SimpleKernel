
/**
 * @file common.h
 * @brief 通用定义头文件
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

#ifndef SIMPLEKERNEL_COMMON_H
#define SIMPLEKERNEL_COMMON_H

#include "cstddef"
#include "cstdint"

namespace COMMON {
// 引用链接脚本中的变量
/// @see http://wiki.osdev.org/Using_Linker_Script_Values
/// 内核开始
extern "C" void*       __executable_start[];
/// 内核结束
extern "C" void*       end[];

/// 内核开始
static const uintptr_t KERNEL_START_ADDR
  = reinterpret_cast<uintptr_t>(__executable_start);
/// 内核结束
static const uintptr_t KERNEL_END_ADDR  = reinterpret_cast<uintptr_t>(end);

// 规定数据大小，方便用
/// 一个字节，8 bits
static constexpr const size_t BYTE      = 0x1;
/// 1KB
static constexpr const size_t KB        = 0x400;
/// 1MB
static constexpr const size_t MB        = 0x100000;
/// 页大小 4KB
static constexpr const size_t PAGE_SIZE = 4 * KB;

}; // namespace COMMON

#endif /* SIMPLEKERNEL_COMMON_H */


/**
 * @file cfs_scheduler.cpp
 * @brief cfs 调度器实现
 * @author Zone.N (Zone.Niuzh@hotmail.com)
 * @version 1.0
 * @date 2022-01-22
 * @copyright MIT LICENSE
 * https://github.com/Simple-XX/SimpleKernel
 * @par change log:
 * <table>
 * <tr><th>Date<th>Author<th>Description
 * <tr><td>2022-01-22<td>MRNIU<td>新建文件
 * </table>
 */

#include "cfs_scheduler.h"

cfs_scheduler_t::cfs_scheduler_t(void)
    : scheduler_t("unnamed cfs_scheduler_t") {
    spinlock.init("unnamed cfs_scheduler_t");
    return;
}

cfs_scheduler_t::cfs_scheduler_t(const mystl::string _name)
    : scheduler_t(_name) {
    spinlock.init(_name.c_str());
    return;
}

cfs_scheduler_t::~cfs_scheduler_t(void) {
    return;
}

void cfs_scheduler_t::add_task(task_t *_task) {
    spinlock.lock();
    (void)_task;
    info("TODO\n");
    spinlock.unlock();
    return;
}

void cfs_scheduler_t::remove_task(task_t *_task) {
    spinlock.lock();
    (void)_task;
    info("TODO\n");
    spinlock.unlock();
    return;
}

task_t *cfs_scheduler_t::get_next_task(void) {
    spinlock.lock();
    info("TODO\n");
    task_t *ret = nullptr;
    spinlock.unlock();
    return ret;
}

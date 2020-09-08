## 项目简介

> 在工作、优秀开源代码的阅读过程中，时常会遇到一些比较亮眼的编码方式，出于好奇、自我提升，将这些good taste加以消化，从架构层面扩展自己的知识视野。lfp取名lee's firmware platform。

### Mkdocs

> 项目文档主要以mkdown文档书写，使用[MKdocs](https://mkdocs.readthedocs.io/en/stable/)进行文档服务器的部署，达到管理/阅读工程项目文档的目的。

### lfp_util

> 基建部分，支撑项目的通用业务，例如日志输出等；

#### 1. lfp_util_dbg - 管理项目各模块的日志输出, 主要涉及:

- 不同模块日志封装, 通过主模块 + 子模块掩码的形式, 控制模块日志的输出;

- 不同的日志信息分等级打印, 目前分为ERR，INFO，CRIT三类，分别对应程序运行的“错误”，“通用信息”以及“关键信息”;

- 通过串口命令交互实现日志的控制输出;

- 底层控制，使用可变宏参数***va_list***来控制不同类型参数日志的输出；

#### 2. lfp util timer - 管理项目的基础时间相关业务.

- 不随着OS/平台的变化而变化，如果依赖OS/平台，需要封装成`lfp_adapter`层;

### lfp_util_cmd - 串口命令管理, 实现用户交互.

> 用户busybox实现, 通过串口交互实现和主程序的交互，完成状态查询、触发控制等;

### lfp_arch_adapter

> 平台适配层，用以兼容/适配不同的操作系统（或者cpu平台，预留，目前暂时适配不同操作系统）, 用户层无需感知系统的变化;

```c
    1. 通过不同操作系统注册到平台层，进而适配支持不同的底层操作系统实现，app层保持一致的调用关系；

    2. 通过函数指针簇来描述不同的底层操作系统实现；
```

### Modules

> 待学习的技术知识，包括但不限于以下列举：

- 应用开发技术

1. 单向链表的应用 -- 基础数据结构；
2. 双向链表的应用 -- 基础数据结构；
3. socket通信 -- 如何与其他进程进行通信，如何保证数据的完整性；
4. 多线程，锁，互斥量，信号量等 -- 如何应用多线程技术，如何控制数据同步；
5. 信号的使用;
6. 库劫持(例如动态库预加载劫持malloc内存分配);
7. 线程池 -- 如何管理高并发，如何提高处理效率；
8. sqlite -- 如何存储数据；

- 系统底层技术

1. 内存/虚拟内存 -- 如何管理内存的使用；
2. 进程调度 -- 多进程调度，资源分配/切换等；
3. IPC -- 进程间通信；
4. VFS -- 虚拟文件系统，各类文件系统抽象；
5. 网络 -- 网络交互；
6. 驱动 -- 操作外设；

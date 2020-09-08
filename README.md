### 项目简介

> 在工作、优秀开源代码的阅读过程中，时常会遇到一些比较亮眼的编码方式，出于好奇、自我提升，将这些good taste加以消化，从架构层面扩展自己的知识视野。lfp取名lee's firmware platform。

#### Mkdocs

> 项目文档主要以mkdown文档书写，并使用[MKdocs](https://mkdocs.readthedocs.io/en/stable/)进行文档服务器的部署，来管理工程项目文档。

#### Util

>  管理项目各模块的日志输出，主要涉及：

- 底层控制，掌握***va_list***的使用来控制不同类型参数日志的输出；

- socket底层封装，多平台适配？还是C库适配？如果是平台层适配，后期移植到"**lfp_adapter**"层；

#### Arch adaptation

> 平台适配层，用以兼容/适配不同的操作系统（或者cpu平台，预留，目前暂时适配不同操作系统）

- 如何适配支持不同的底层操作系统实现，app层保持一致的调用关系；
- 如何使用一簇函数指针集合来描述不同的底层操作系统实现；
- 如何使用宏定义描述平台层函数接口；

#### Modules

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

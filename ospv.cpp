typedef uint semaphore;
void P(semaphore);
void V(semaphore);
void write();
void read();


// 互斥变量
semaphore wMutex = 1,
          wCountMutex = 1,
          rMutex = 1,
          rCountMutex = 1;

// 共享变量
int wCount = 0,
    rCount = 0;

// 写者进程
 void writer_i() {
     // 记录写者数量，并且第一个写入的写者需要阻塞读者的读进程，保证写者优先
    P(wCountMutex);
    if (wCount == 0) {
        P(rMutex);
    }
    wCount++;
    V(wCountMutex);

    // 写者开始向文件写入并保证写者之间互斥
    P(wMutex);
    write();
    V(wMutex);

    // 读完后修改写进程的数量，并在所有写进程都完成时允许读者阅读文件
    P(wCountMutex);
    wCount--;
    if (wCount == 0) {
        V(rMutex);
    }
    V(wCountMutex);
}

// 读者进程
void read_i() {
     // 必须首先保证读写互斥，立刻执行V（）是为了保证读者之间可以同时阅读文件。
     // 且若此时有写进程申请文件，则阻塞后续申请的读者进程。
    P(rMutex);
    V(rMutex);

    // 统计当前读者进程的数量，并阻塞写者进程
    P(rCountMutex);
    if (rCount == 0) {
        P(wMutex);
    }
    rCount++;
    V(rCountMutex);

    // 读者开始阅读文件
    read();

    // 当所有读者都不读时，释放被阻塞的写者进程。
    P(rCountMutex);
    rCount--;
    if (rCount == 0) {
        V(wMutex);
    }
    V(rCountMutex);
 }
#include <iostream>
#include <thread>

using namespace std;

thread::id main_thread_id = this_thread::get_id();

void hello() {
    cout << "Hello Concurrent World\n";
    if (main_thread_id == this_thread::get_id())
        cout << "This is the main thread.\n";
    else
        cout << "This is not the main thread.\n";
}

void pause_thread(int n) {
    this_thread::sleep_for(chrono::seconds(n));
    cout << "pause of " << n << " seconds ended\n";
}

int main() {
    hello();

    thread t(hello);
    cout << thread::hardware_concurrency() << endl;//可以并发执行多少个(不准确)
    cout << "native_handle " << t.native_handle() << endl;//可以并发执行多少个(不准确)
    t.join();//等待线程结束并清理资源（会阻塞）


    thread a(hello);
    a.detach();//将线程与调用其的线程分离，彼此独立执行（此函数必须在线程创建时立即调用，且调用此函数会使其不能被join）


    thread threads[5];                         // 默认构造线程
    cout << "Spawning 5 threads...\n";
    for (int i = 0; i < 5; ++i)
        threads[i] = thread(pause_thread, i + 1);   // move-assign threads
    cout << "Done spawning threads. Now waiting for them to join:\n";
    for (auto &thread: threads)
        thread.join();
    cout << "All threads joined!\n";
}
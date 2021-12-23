#include"HW05_02_queue.h"
#include"HW05_02_queue.cpp"
int main()
{
    Queue<string> oher;
    oher.PushQueue("dokument1", 4);
    cout << oher << endl;
    oher.PushQueue("dokument2", 1);
    cout << oher << endl;
    oher.PushQueue("dokument3", 7);
    cout << oher << endl;
    oher.PushQueue("dokument4", 3);
    cout << oher << endl;
    oher.PushQueue("dokument5", 5);
  cout << oher << endl;
}


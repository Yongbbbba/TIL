#include <iostream>
#include <array>

using namespace std;
int main() {
    int a,b,c;
    cin  >> a >> b >> c;
    int target = a * b * c;
    array<int,10> arr {0,};
    while (target>0) {
        arr[target % 10]++;
        target = target / 10;
    }
    for (int i=0; i<10; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}
}
}
}

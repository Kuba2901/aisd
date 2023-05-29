#include <iostream>
#include <vector>
using namespace std;

int compare(int a, int b) {
    return a > b ? a : b;
}

int findmax(vector<int> weights, vector<int> values, int itemsNum, int cartCapacity) {
    if (itemsNum == 0 || cartCapacity == 0) {
        return 0;
    }

    if (weights[itemsNum - 1] > cartCapacity) {
        return findmax(weights, values, itemsNum - 1, cartCapacity);
    }

    else {
        return compare(values[itemsNum - 1] + findmax(weights, values, itemsNum - 1, cartCapacity - weights[itemsNum - 1]), findmax(weights, values, itemsNum - 1, cartCapacity));
    }
}


int main() {
    int q = 0;

    while (q < 500) {
        int items, capacity;
        vector<int> values;
        vector<int> weights;

        // get the number of items
        cin >> items;

        // get the values
        for (int i = 0; i < items; i++)
        {
            int v;
            cin >> v;
            values.push_back(v);
        }

        // get the weights
        for (int i = 0; i < items; i++)
        {
            int w;
            cin >> w;
            weights.push_back(w);
        }

        // get the loading capacity
        cin >> capacity;

        int max = findmax(weights, values, items, capacity);

        cout << max << endl;

        q++;
    }



    return 0;
}
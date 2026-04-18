#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Node {
    char data;
    float freq;
    struct Node *left, *right;
};

float total_compressed_bits = 0;

struct Node* createNode(char data, float freq) {
    struct Node* newNode = new Node();
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void swap(struct Node** a, struct Node** b) {
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

void sort(struct Node* arr[], int n) {
    int i, j;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j]->freq > arr[j + 1]->freq) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printNodes(struct Node* nodes[], int size) {
    cout << "Nodes : ";
    int i;
    for(i = 0; i < size; i++) {
        if(nodes[i]->data == '$')
            cout << "(" << nodes[i]->freq << ") ";
        else
            cout << "(" << nodes[i]->data << ":" << nodes[i]->freq << ") ";
    }
    cout << "\n";
}

struct Node* buildHuffmanTree(struct Node* nodes[], int size) {
    cout << "\n--- Building Tree ---\n";
    while(size > 1) {
        sort(nodes, size);
        printNodes(nodes,size);

        struct Node* left = nodes[0];
        struct Node* right = nodes[1];

        struct Node* newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;


        nodes[0] = newNode;
        nodes[1] = nodes[size - 1];
        size--;
    }
    printNodes(nodes,1);
    return nodes[0];
}

void printCodesAndCalculate(struct Node* root, int arr[], int top) {
    if(root->left) {
        arr[top] = 0;
        printCodesAndCalculate(root->left, arr, top + 1);
    }

    if(root->right) {
        arr[top] = 1;
        printCodesAndCalculate(root->right, arr, top + 1);
    }

    if(root->left == nullptr && root->right == nullptr) {
        cout << root->data << ": ";
        for(int i = 0; i < top; i++)
            cout << arr[i];
        cout << "\n";

        total_compressed_bits += (root->freq * top);
    }
}

int main() {
    int n, i;
    float total_freq = 0;

    cout << "Enter number of characters: ";
    if(!(cin >> n) || n <= 0) return 1;

    vector<struct Node*> nodesVec(n);

    for(i = 0; i < n; i++) {
        char ch;
        float freq;
        cout << "Enter character and frequency: ";
        cin >> ch >> freq;
        nodesVec[i] = createNode(ch, freq);
        total_freq += freq;
    }

    struct Node* root = buildHuffmanTree(nodesVec.data(), n);

    int arr[100], top = 0;
    cout << "--- Huffman Codes ---\n";
    printCodesAndCalculate(root, arr, top);

    int bits_fixed = static_cast<int>(ceil(log2(n)));
    float original_total_size = total_freq * bits_fixed;

    cout << "\n--- Compression Ratio ---\n";
    cout << "Fixed-length bits per char: " << bits_fixed << " \n";
    cout << "Total Original Size: " << original_total_size << " \n";
    cout << "Total Compressed Size: " << total_compressed_bits << " \n";

    if (total_compressed_bits > 0) {
        float ratio = original_total_size / total_compressed_bits;
        cout << "Compression ratio: " << (1 - (total_compressed_bits / original_total_size)) * 100 << "%\n";
    }

    return 0;
}

#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    char character;
    unsigned frequency;
    TreeNode *leftChild, *rightChild;


    TreeNode(char character, unsigned frequency) {
        this->character = character;
        this->frequency = frequency;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
};


struct CompareNode {
    bool operator()(TreeNode* lhs, TreeNode* rhs) {
        return lhs->frequency > rhs->frequency;
    }
};


void generateHuffmanCodes(TreeNode* root, string code, map<char, string>& codesMap) {
    if (root == nullptr) {
        return;
    }
    // If it's a leaf node, assign the code
    if (!root->leftChild && !root->rightChild) {
        codesMap[root->character] = code;
    }
    // Recurse left
    generateHuffmanCodes(root->leftChild, code + "0", codesMap);
    // Recurse right
    generateHuffmanCodes(root->rightChild, code + "1", codesMap);
}

// Main function to build the Huffman tree and generate codes
void createAndPrintHuffmanCodes(char characters[], int frequencies[], int arraySize) {
    priority_queue<TreeNode*, vector<TreeNode*>, CompareNode> treeQueue;

    // Create a leaf node for each character and add it to the priority queue.
    for (int i = 0; i < arraySize; ++i) {
        treeQueue.push(new TreeNode(characters[i], frequencies[i]));
    }

    // Iterate until the queue has only one node
    while (treeQueue.size() > 1) {
        TreeNode *left = treeQueue.top();
        treeQueue.pop();
        TreeNode *right = treeQueue.top();
        treeQueue.pop();

        // Create a new node with children
        TreeNode *sum = new TreeNode('$', left->frequency + right->frequency);
        sum->leftChild = left;
        sum->rightChild = right;
        treeQueue.push(sum);
    }

    // The remaining node is the root node
    TreeNode* root = treeQueue.top();

    map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Print the Huffman codes
    for (auto pair : huffmanCodes) {
        cout << pair.first << ":" << pair.second << endl;
    }
}

// Entry point of the program
int main() {
    int numCharacters = 6;
    char characters[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int frequencies[6];


    for (int i = 0; i < numCharacters; ++i) {
        cin >> frequencies[i];
    }

    createAndPrintHuffmanCodes(characters, frequencies, numCharacters);
    return 0;
}

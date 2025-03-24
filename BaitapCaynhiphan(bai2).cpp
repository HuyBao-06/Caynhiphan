#include <iostream>
using namespace std;

// Định nghĩa cấu trúc NODE của cây nhị phân
struct NODE {
    int data;
    NODE* pLeft;
    NODE* pRight;
};

// Hàm tạo một node mới
NODE* createNode(int data) {
    NODE* newNode = new NODE();
    newNode->data = data;
    newNode->pLeft = newNode->pRight = NULL;
    return newNode;
}

// Hàm hoán đổi cây theo gợi ý của đề bài
void swapTree(NODE* p) {
    if (p == NULL) return;

    // Bước 1: Hoán đổi cây con trái và phải của gốc
    NODE* temp = p->pLeft;
    p->pLeft = p->pRight;
    p->pRight = temp;

    // Bước 2: Nếu p->pLeft không phải NULL, hoán đổi tiếp các cây con của nó
    if (p->pLeft != NULL) {
        temp = p->pLeft->pLeft;
        p->pLeft->pLeft = p->pLeft->pRight;
        p->pLeft->pRight = temp;
    }
}

// Hàm duyệt cây theo thứ tự trung tố (In-order)
void inorderTraversal(NODE* root) {
    if (root != NULL) {
        inorderTraversal(root->pLeft);
        cout << root->data << " ";
        inorderTraversal(root->pRight);
    }
}

int main() {
    // Tạo cây như hình 1
    NODE* root = createNode(10);
    root->pLeft = createNode(5);
    root->pRight = createNode(15);
    root->pLeft->pLeft = createNode(3);
    root->pLeft->pRight = createNode(9);
    root->pLeft->pRight->pLeft = createNode(7);
    root->pRight->pLeft = createNode(12);
    root->pRight->pRight = createNode(18);
    root->pRight->pRight->pLeft = createNode(16);
    root->pRight->pRight->pRight = createNode(20);

    cout << "Cay truoc khi hoan doi: ";
    inorderTraversal(root);
    cout << endl;

    // Thực hiện hoán đổi
    swapTree(root);

    cout << "Cay sau khi hoan doi: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

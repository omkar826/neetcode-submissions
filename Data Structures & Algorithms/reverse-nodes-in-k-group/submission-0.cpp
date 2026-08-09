/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseLL(ListNode* temp){
        ListNode* currentNode = temp;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(currentNode!=NULL){
            next = currentNode->next;
            currentNode->next = prev;
            prev = currentNode;
            currentNode = next;
        }
        return prev;
    }
    ListNode* getkthNode(ListNode* temp, int k){
        k=k-1;
        while(temp!=NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = NULL;
        ListNode* prevNode = NULL;
        while(temp!=NULL){
            ListNode* kthNode = getkthNode(temp,k);
            if(kthNode == NULL){
                if(prevNode) prevNode->next = temp;
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);
            if(temp == head) head = kthNode;
            else prevNode->next = kthNode;
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};

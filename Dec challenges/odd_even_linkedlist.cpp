// 328. Odd Even Linked List
// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
// Note that the relative order inside both the even and odd groups should remain as it was in the input.
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

//Explanation is written in notebook
//TC = O(N)
#include<bits/stdc++.h>
using namespace std;
 struct ListNode { //Basic structure
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head; //edge case
        
        ListNode* oddtail = head; //For maintaining track on odd tail
        ListNode* oddhead = oddtail;//maintaining track on odd head
        ListNode* eventail = head->next;//maintaining track on even tail, initialised at even position
        ListNode* evenhead = eventail;//maintaining track on even head
        
        while(oddtail->next!=NULL && eventail->next!=NULL) { //I was doing mistake here, this condition is vry imp 
            oddtail->next = eventail->next;  //From here make the links change based on observations
            oddtail = oddtail->next;
            eventail->next = oddtail->next;
            eventail = eventail->next;
        }
        oddtail->next = evenhead; //connect back the evenhead at the end of odd 
        if(oddtail->next == NULL) { //It is very imp to check
            eventail->next = NULL;
        }
        
        
        return oddhead;//return oddhead
    }
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

return 0;
}
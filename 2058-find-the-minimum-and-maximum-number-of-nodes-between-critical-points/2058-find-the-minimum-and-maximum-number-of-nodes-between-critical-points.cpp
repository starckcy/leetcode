class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i = 1;
        int fi = -1;
        int si = -1;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;
        if(c==NULL) return {-1,-1};
        int f = -1;
        int s = -1;
        int mind = INT_MAX;
        int maxd;
        while(c){
            if((b->val > a->val && b->val > c->val) || (b->val < a->val && b->val < c->val)){
                // maxd
                if(fi==-1) fi = i;
                else si = i;

                // mind
                f = s;
                s = i;
                if(f!=-1){
                    int d = s - f;
                    mind = min(mind, d);
                }
            }
            a = a->next;
            b = b->next;
            c = c->next;
            i++;
        }
        if(si==-1) return {-1,-1};
        maxd = si - fi;

        return {mind, maxd};
    }
};
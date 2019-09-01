//
//  main.cpp
//  practice1
//
//  Created by Rishit Board on 6/19/19.
//  Copyright © 2019 Rishit Board. All rights reserved.
//


// Gitlab - dhZtFVuj5xgJUJT1rkVW

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

//======================================================================//
// Utility Functions //
//======================================================================//

typedef struct treenode;

typedef struct treenode
{
    int val;
    struct treenode *left;
    struct treenode *right;
} TREE_NODE_t, *TREE_NODE_p;

TREE_NODE_p create_tree_node(int val)
{
    TREE_NODE_p temp_node = (TREE_NODE_p) malloc(sizeof(TREE_NODE_t));
    if(!temp_node)
    {
        printf("Node Allocation error");
        return nullptr;
    }
    
    temp_node->val = val;
    temp_node->left = nullptr;
    temp_node->right = nullptr;
    return temp_node;
}

void inorder_traversal(TREE_NODE_p head)
{
    if(!head)
    {
        return;
    }
    
    printf("%d ", head->val);
    inorder_traversal(head->left);
    inorder_traversal(head->right);
}

void swap_vector_int(vector<int>& arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void print_1D_vector_int(vector<int>& vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

//======================================================================//
// LeedCode Questions //
//======================================================================//

//https://leetcode.com/problems/median-of-two-sorted-arrays/
// doesnt work
double findMedianSortedArrays(vector<int>&nums1, vector<int>&nums2)
{
    int ar1_len = (int)nums1.size();
    int ar2_len = (int)nums2.size();
    int mid_index = (ar1_len + ar2_len) / 2;
    cout << mid_index << " "<< ar1_len << " " << ar2_len << endl;
    int i = -1, j = -1;
    int idx = 0;
    
    while(mid_index && i < ar1_len && j < ar2_len)
    {
        cout << mid_index<< " " << nums1[i+1] << ">" << nums2[j+1] << endl;
        if(nums1[i+1] > nums2[j+1])
        {
            ++j;
            idx = j;
        }
        else
        {
            ++i;
            idx = i;
        }
        
        --mid_index;
        cout << "! " << mid_index << " " << i << " " << j << endl;
    }
    
    if(i >= ar1_len)
    {
        while(mid_index)
        {
            ++j;
            idx = j;
            --mid_index;
            cout << "@" << mid_index << " " << i << " " << j << endl;
        }
    }
    
    if(j >= ar2_len)
    {
        while(mid_index)
        {
            ++i;
            idx = i;
            --mid_index;
            cout << "#" << mid_index << " " << i << " " << j << endl;
        }
    }
    
    cout << mid_index << " " << i << " " << j << endl;
    
    if((ar1_len + ar2_len) % 2)
    {   // Odd total length
        return (idx == i) ? nums1[i] : nums2[j];
    }
    else
    {   // even total length
        if(idx == i)
        {
            if(nums1[i+1] > nums2[j])
                return (nums1[i]  + nums2[j]) / 2;        // todo evaluate this again
            else
                return (nums1[i+1]  + nums1[i]) / 2;
        }
        else
        {
            if(nums1[j+1] > nums2[i])
                return (nums1[i]  + nums2[j]) / 2;        // todo evaluate this again
            else
                return (nums2[j+1]  + nums2[j]) / 2;
        }
        return 1.0;
    }
    return 1.0;
}
//1 3 5 6 7 8 11 15 16 20 22
//======================================================================//

void sort_array_by_parity(vector<int>&arr)
{
    int even_ptr = 0;
    int odd_ptr = 0;
    
    while(odd_ptr < arr.size() && even_ptr < arr.size())
    {
        if(arr[even_ptr] & 1)
        {   // odd
            while ((arr[odd_ptr] & 1) && (odd_ptr < arr.size()))
            {
                odd_ptr++;
            }
            
            if(odd_ptr < arr.size())
                swap_vector_int(arr, even_ptr, odd_ptr);
        }
        even_ptr++; odd_ptr++;
    }
}
//======================================================================//

int fibbonacci(int n, int* arr)
{
    if(n == 0 || n == 1)
    {
        return arr[n];
    }
    
    int i = 2;
    
    while(i != n)
    {
        arr[i] = arr[i-1] + arr[i-2];
        i++;
    }
    
    return arr[n];
}

//======================================================================//

//Input: ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
//Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]

// map -> <>

/*
 vector<string> reorderLogFiles(vector<string>& logs)
 {
 for(int i = 0; i < logs.size(); i++)
 {
 
 }
 }
 */
//======================================================================//

bool isBigEndian()
{
    uint32_t data = 0x01;
    //uint32_t *ptr = &data;
    uint32_t *ptr;
    ptr = &data;
    printf("data_addr = %lu, ptr_points to = %lu\r\n", &data, ptr);
    
    char *dt = (char*)&data;
    printf("char_ptr_points to = %lu, %x\r\n", dt, *dt);
    
    cout << *dt << *(dt+1) << *(dt+2) << "printed \r\n";
    //printf("char [%c]\r\n", *dt);
    return (*dt == '1') ? false : true;
}

//======================================================================//
// Wrong question on leetcode, code is not working
int find_tree_tilt(TREE_NODE_p head, int *tilt_acc)
{
    if(!head)
    {
        return 0;
    }
    
    tilt_acc += abs(find_tree_tilt(head->left, tilt_acc) - find_tree_tilt(head->right, tilt_acc));
    
    return head->val;
}

//======================================================================//
struct change {
    unsigned int fives;
    unsigned int tens;
    unsigned int twnties;
};

bool lemonade_change(vector<int> bills)
{
    struct change changes = {0,0,0};
    
    for(int i = 0; i < bills.size(); i++)
    {
        int bill = bills[i];
        printf("bill %d, bills[%d] %d\r\n", bill, i, bills[i]);
        int balance = bill - 5;
        if(bill == 5) changes.fives++;
        if(bill == 10) changes.tens++;
        if(bill == 20) changes.twnties++;
        
        while(balance > 0)
        {
            printf("Bill %d, balance %d, fives %d, tens%d, twenties %d\r\n", bill, balance, changes.fives, changes.tens, changes.twnties);
            
            if(((balance - 20) >= 0) && (changes.twnties > 0))
            {
                printf("\t%d - 20, twenties %d\r\n", balance, changes.twnties);
                balance -= 20;
                changes.twnties--;
            }
            else if((balance - 10) > -1 && changes.tens > 0)
            {
                if(balance - 10 >=0) printf("greater\r\n");
                else printf("lesser\r\n");
                printf("\t%d - 10, tens %d\r\n", balance, changes.tens);
                
                balance -= 10;
                changes.tens--;
            }
            else if(((balance - 5) >= 0) && (changes.fives > 0))
            {
                printf("\t%d - 5, fives %d\r\n", balance, changes.fives);
                balance -= 5;
                changes.fives--;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

//======================================================================//

bool canConstruct(string ransomeNote, string magazine)
{
    set<char> available_chars;
    
    int i = 0, j = 0;
    
    for(i = 0; i < ransomeNote.size(); i++)
    {
        while(j < magazine.size() && available_chars.find(ransomeNote[i]) == available_chars.end())
        {
            available_chars.insert(magazine[j++]);
        }
        if(j == magazine.size())
        {
            return false;
        }
    }
    return true;
}

//======================================================================//

std::string findRestaurant(vector<string>& list1, vector<string>& list2)
{
    map<string, int> l1, l2;
    
    for(int i = 0; i < list1.size(); i++)
    {
        l1.insert({list1[i],i});
        
    }
    
    int min_idx = INT_MAX;
    
    std::string min_string = "";
    
    for(int k = 0; k < list2.size(); k++)
    {
        map<string,int>::iterator itr = l1.find(list2[k]);
        if(itr != l1.end())
        {
            int min = abs(k-(itr->second));
            
            if( min < min_idx)
            {
                min_idx = min;
                min_string = itr->first.c_str();
            }
        }
    }
    return min_string;
}

//======================================================================//
// Better solution is
//First find where the index of the last occcurrence of each letter is, store in array
//Start scanning with the first letter of the string, find where the last occurrence of that letter is, that is the end of the current window / partition
//For all letters in the current window, check if their last occurrence is beyond the current last occurrence, if so then there is an overlap between these windows and the window must expand to encompass all overlapping characters
//Once the end of the window is reached, all letters within the window have last occurrences less than or equal to this end of window, then the partition is complete, move to the next partition
bool isLastChar(string S, char c, int idx)
{
    for(int i = idx + 1; i < S.size(); i++)
    {
        if(S[i] == c)
            return false;
    }
    return true;
}

bool last_of_the_group(unordered_set<char>group, char c, int idx, string s)
{
    unordered_set<char>::iterator itr;
    
    for(itr = group.begin(); itr != group.end(); itr++)
    {
        //printf("group: %c, char:%c, idx:%d\r\n", *itr, c, idx);
        if(!isLastChar(s, *itr, idx))
        {
            return false;
        }
    }
    return true;
}

vector<int> partitionLabels(string S)
{
    vector<int> ans;
    unordered_set<char> char_seen;
    
    int last_familiar_char = 0;
    int start_idx = 0;
    int i = 0;
    
    while(start_idx < S.size())
    {
        if(char_seen.find(S[i]) != char_seen.end())
            last_familiar_char = i;
        else
            char_seen.insert(S[i]);
        
        if(isLastChar(S, S[i], i))
        {
            if(last_of_the_group(char_seen, S[i], i, S))
            {
                //printf("%c at %d is last of the group\r\n", S[i], i);
                ans.push_back((last_familiar_char - start_idx)+1);
                start_idx = last_familiar_char + 1;
                last_familiar_char = start_idx;
                char_seen.clear();
            }
        }
    
        i++;
    }
    return ans;
}

//======================================================================//



class Order
{
private:
    string id;
    vector<string> metadata;
public:
    Order(string raw_order)
    {
        string space = " ";
        int foundat = (int)raw_order.find(space);
        id = raw_order.substr(0, foundat);
        //printf("%s\r\n%s\r\n", id.c_str(),raw_order.c_str());
        int start = foundat+1;
        while(foundat != string::npos)
        {
            //printf("s%d",start);
            foundat = (int)raw_order.find(" ", foundat+1);
            string sub = raw_order.substr(start, (foundat-start));
            //printf("e%d %s\r\n",foundat, sub.c_str());
            metadata.push_back(sub);
            start = foundat+1;
        }
    }
   vector<string> getMetadata()
    {
        return metadata;
    }
    string getId()
    {
        return id;
    }
};

static int LexicalOrder(string s1, string s2)
{
    int len = (int)((s1.size() < s2.size()) ? s1.size() : s2.size());
    
    for(int i = 0; i < len; i++)
    {
        if(s1[i] < s2[i])
        {
            return 1;
        }
        else if(s1[i] < s2[i])
        {
            return -1;
        }
        
    }
    return 0;
}

class CustomCompare
{
public:
    int operator() (Order o1, Order o2)
    {
        vector<string> o1Meta = o1.getMetadata();
        vector<string> o2Meta = o2.getMetadata();
        
        int minlen = (int)((o1Meta.size() < o2Meta.size()) ? o1Meta.size() : o2Meta.size());
        
        for(int i = 0; i < minlen; i++)
        {
            int lexorder = LexicalOrder(o1Meta[i], o2Meta[i]) != 0;
            if(lexorder != 0)
            {
                return lexorder;
            }
        }
        
        return LexicalOrder(o1.getId(), o2.getId());
    }
};

vector<string> amazon_order_sorting(vector<string>orderlist)
{
    vector<Order>object_list;
    priority_queue<Order, vector<Order>, CustomCompare> pq;
    vector<string> answer;
    
    for(int i = 0; i < orderlist.size(); i++)
    {
        Order* order = new Order(orderlist[i]);
        object_list.push_back(*order);
    }
#if 0
    for(int i = 0; i < object_list.size(); i++)
    {
        printf("id: [%s]\t", object_list[i].getId().c_str());
        vector<string> meta = object_list[i].getMetadata();
        for(int j = 0; j < meta.size(); j++)
        {
            printf("[%s]\t",meta[j].c_str());
        }
        printf("\r\n");
    }
#endif
    for(int i = 0 ; i < object_list.size(); i++)
    {
        pq.push(orderlist[i]);
    }
    while (!pq.empty())
    {
        Order temp = pq.top();
        pq.pop();
        string reconstruct  = temp.getId();
        vector<string> meta = temp.getMetadata();
        for(int i = 0 ; i < meta.size(); i++)
        {
            reconstruct = reconstruct + " " + meta[i];
        }
        answer.push_back(reconstruct);
    }
    
    return answer;
}

//

int main()
{
    vector<string>orderList = {"zld 93 12"
        ,"fp kindle book"
        ,"10a echo show"
        ,"17g 12 25 6"
        ,"abl kindle book"
        ,"125 echo dot second generation"
    };
    
    vector<string> ans = amazon_order_sorting(orderList);
    
    for(int i = 0; i < ans.size(); i++)
    {
        printf("%s\r\n", ans[i].c_str());
    }
    
    
    //string S = "ababcbacamdefegdehijhklij";
    
    //vector<int> sub = partitionLabels(S);
    //print_1D_vector_int(sub);
    
    //vector<string> list1 = {"Sparta","Roman", "Greek", "Persian", "Arabic", "Indian"};
    //vector<string> list2 = {"English", "Hindi", "Sparta", "Roman", "Chinese", "Mexicans"};
    //printf("%s\r\n", findRestaurant(list1, list2).c_str());
    
    //if(canConstruct("abc", "abdd"))
    //    printf("True\r\n");
    //else
    //    printf("false\r\n");
    
    //vector<int> bills = {5,5,5,20};
    //if(lemonade_change(bills))
    //{
    //    printf("correct change\r\n");
    //}
    //else
    //{
    //    printf("incorrect change\r\n");
    //}
    
    //int tilt_acc = 0;
    //TREE_NODE_p head = create_tree_node(3);
    //head->left = create_tree_node(2);
    //head->right = create_tree_node(1);
    //inorder_traversal(head);
    //find_tree_tilt(head, &tilt_acc);
    //printf("tilt %d\r\n", tilt_acc);
    
    
    //if(isBigEndian())
    //{
    //    printf("Big\r\n");
    //}
    //else
    //{
    //    printf("little\r\n");
    //}
    
    
    //vector<int> nums1{1,3,7};
    //vector<int> nums1{8,4,1,3,6,7,4};
    //sort_array_by_parity(nums1);
    //print_1D_vector_int(nums1);
    
    // ######
    //vector<int>nums1{1,3,6,7,20,22};
    //vector<int>nums2{5,8,11,15,16};
    //vector<int>nums1{1,3,6,7,8,20,22};
    //vector<int>nums2{5,8,11,15,16};
    //double ans = findMedianSortedArrays(nums1, nums2);
    //cout << "ans" << ans << endl;
    
    //return 0;
}

/*
 
 ! 5 1 0
 ! 4 2 0
 ! 3 2 1
 ! 2 3 1
 ! 1 4 1
 ! 0 5 1
 0 5 1
 5 114
 */

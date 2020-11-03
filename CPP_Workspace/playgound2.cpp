//
//  main.cpp
//  practice1
//
//  Created by Rishit Board on 6/19/19.
//  Copyright © 2019 Rishit Board. All rights reserved.
//


// Gitlab - dhZtFVuj5xgJUJT1rkVW

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
#include <thread>
#include <mutex>
#include <algorithm>
using namespace std;

//======================================================================//
// Utility Functions //
//======================================================================//

//int tilt_acc = 0;
//TREE_NODE_p head = create_tree_node(3);
//head->left = create_tree_node(2);
//head->right = create_tree_node(1);
//inorder_traversal(head);
//find_tree_tilt(head, &tilt_acc);
//printf("tilt %d\r\n", tilt_acc);
//return 0;

#define MAX(A,B) (A > B ? A : B)

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

void print_2D_vector_int(vector<vector<int>>& vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        for(int j = 0; j < vec[i].size(); j++)
        {
            printf("%d ",vec[i][j]);
        }
        printf("\r\n");
    }
    cout << endl;
}

//======================================================================//
// LeedCode Questions //
//======================================================================//

//https://leetcode.com/problems/median-of-two-sorted-arrays/
// doesnt work
// Input:
    //vector<int>nums1{1,3,6,7,20,22};
    //vector<int>nums2{5,8,11,15,16};
    //vector<int>nums1{1,3,6,7,8,20,22};
    //vector<int>nums2{5,8,11,15,16};
    //double ans = findMedianSortedArrays(nums1, nums2);
    //cout << "ans" << ans << endl;
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

//Input:
//vector<int> nums1{1,3,7};
//vector<int> nums1{8,4,1,3,6,7,4};
//sort_array_by_parity(nums1);
//print_1D_vector_int(nums1);

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
//Input:
    //if(isBigEndian())
    //{
    //    printf("Big\r\n");
    //}
    //else
    //{
    //    printf("little\r\n");
    //}

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
//Input:
//vector<int> bills = {5,5,5,20};
//if(lemonade_change(bills))
//{
//    printf("correct change\r\n");
//}
//else
//{
//    printf("incorrect change\r\n");
//}

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


//Input:
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

/*
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
*/

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

//======================================================================//
//Input:
/*
    Logger logger;
    
    if(logger.shouldPrintMessage(1, "Foo"))
    {
        printf("1 Foo true\r\n");
    }
    else{
        printf("1 foo false\r\n");
    }
    
    if(logger.shouldPrintMessage(2, "Bar"))
    {
        printf("2 Bar true\r\n");
    }
    else{
        printf("2 Bar false\r\n");
    }
    
    if(logger.shouldPrintMessage(3, "Foo"))
    {
        printf("3 Foo true\r\n");
    }
    else{
        printf("3 foo false\r\n");
    }
    
    if(logger.shouldPrintMessage(8, "Bar"))
    {
        printf("8 Bar true\r\n");
    }
    else{
        printf("8 Bar false\r\n");
    }
    if(logger.shouldPrintMessage(10, "Foo"))
    {
        printf("10 Foo true\r\n");
    }
    else{
        printf("10 foo false\r\n");
    }
    if(logger.shouldPrintMessage(11, "Foo"))
    {
        printf("11 Foo true\r\n");
    }
    else{
        printf("11 foo false\r\n");
    }
    
*/
class Logger
{
public:
    
    unordered_map<string, int> record;
    
    Logger()
    {
    }
    
    bool shouldPrintMessage(int timestamp, string message)
    {
        unordered_map<string, int>:: iterator itr = record.find(message);
     
        if(itr != record.end())
        {
            if(itr->second <= timestamp - 10)
            {
                itr->second = timestamp;
                return true;
            }
            else
            {
                return false;
            }
        }
        
        record.emplace(message, timestamp);
        
        return true;
    }
};

//======================================================================//
/*
    vector<string>querries {"sparta", "spartaaa", "leemon"};
    vector<string>words {"aaaabbcs", "abcsrsaa", "bbcjdhs"};
    
    vector<int> ans = compare_by_freq_of_smallest_char(querries, words);
    print_1D_vector_int(ans);
*/

vector<int> compare_by_freq_of_smallest_char(vector<string>& queries, vector<string>& words)
{
    vector<int> answer;
    vector<int> words_min_char_freq(words.size(),0);
    
    map<char, int> words_char_freq[words.size()];
    map<char, int> query_char_freq;
    
    for(int i = 0; i < words.size(); i++)
    {
        for(int j = 0; j < words[i].size(); j++)
        {
            char c = words[i][j];
            
            // Add if not already present in map
            if(words_char_freq[i].find(c) == words_char_freq[i].end())
            {
                words_char_freq[i].emplace(c, 1);
            }
            else    // Increment if already present in map
            {
                words_char_freq[i][c]++;
            }
        }
        words_min_char_freq[i] = words_char_freq[i].begin()->second;
    }
    
    int freq = 0;
    
    for(int i = 0; i < queries.size(); i++)
    {
        int query_greater_count = 0;
        query_char_freq.clear();
        
        for(int j = 0; j < queries[i].size(); j++)
        {
            char c = queries[i][j];
            
                    // Add if not already present in map
            if(query_char_freq.find(c) == query_char_freq.end())
                query_char_freq.emplace(c, 1);
            else    // Increment if already present in map
                query_char_freq[c]++;
        }
        
        freq = query_char_freq.begin()->second;
        for(int k = 0; k < words.size(); k++)
        {
            if(freq > words_min_char_freq[k])
                query_greater_count++;
        }
        answer.push_back(query_greater_count);
    }
    
    /*
    for(int i = 0; i< words.size(); i++)
    {
        for(auto itr = words_char_freq[i].begin(); itr != words_char_freq[i].end(); itr++)
        {
            printf("Key : %c, value %d\r\n", itr->first, itr->second);
        }
        printf("\r\n");
    }
    */
    return answer;
}

//======================================================================//
/*
    TREE_NODE_p head = create_tree_node(1);
    head->left = create_tree_node(2);
    head->right = create_tree_node(3);
    head->left->left = create_tree_node(4);
    head->left->right = create_tree_node(5);
    head->right->left = create_tree_node(6);
    head->right->right = create_tree_node(7);
    
    vector<int> tree = print_tree_levels(head);
    print_1D_vector_int(tree);
    vector<int>to_delete{3,5};
    vector<vector<int>>ans = delNodes(head, to_delete);
    print_2D_vector_int(ans);
*/
    

// Needs to resolve one bug to make it work
vector<int> print_tree_levels(TREE_NODE_p head)
{
    queue<TREE_NODE_p>q;
    vector<int>tree_arr;
    
    if(!head)
        return tree_arr;
    
    q.push(head);
    
    while(!q.empty())
    {
        TREE_NODE_p node = q.front();
        tree_arr.push_back(node->val);
        q.pop();
        
        if(node->left != NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
    }
    
    return tree_arr;
}

typedef struct node_children
{
    TREE_NODE_p left;
    TREE_NODE_p right;
    
} NODE_CHILDREN_t;

void delNodes_util(TREE_NODE_p* head, vector<NODE_CHILDREN_t>& children, set<int>&to_del_set)
{
    NODE_CHILDREN_t child;
    
    if(!head)
        return;
    printf("head val = %d\r\n", (*head)->val);
    
    if(!(*head))
        return;
    
    auto itr = to_del_set.find((*head)->val);
    
    if(itr != to_del_set.end())
    {
        printf("Delete %d\r\n",*itr);
        child.left = (*head)->left;
        child.right = (*head)->right;
        free(*head);
        
        if((*head)->left || (*head)->right)
            children.push_back(child);
        
        if(child.left != nullptr)
            printf("child %d\r\n", child.left->val);
        if(child.right != nullptr)
            printf("child %d\r\n", child.right->val);
    }
    
    if((*head)->left != nullptr)
        delNodes_util(&(*head)->left, children, to_del_set);
    if((*head)->right != nullptr)
        delNodes_util(&(*head)->right, children, to_del_set);

    return;
}

vector<vector<int>> delNodes(TREE_NODE_p root, vector<int>& to_delete)
{
    vector<vector<int>> ans;
    vector<NODE_CHILDREN_t>children;
    
    printf("val = %d\r\n", root->val);
    
    set<int> set_to_del(to_delete.begin(),to_delete.end());
    
    delNodes_util(&root, children, set_to_del);
    
    for(int i = 0; i < children.size(); i++)
    {
        if(children[i].left)
            printf("size %lu, %d\r\n", children.size(), children[i].left->val);
        
// TODO: An Error here, otherwise perfectly working code
        //ans.push_back(print_tree_levels(root));
        ans.push_back(print_tree_levels(children[i].left));
        ans.push_back(print_tree_levels(children[i].right));
    }
    
    return ans;
}

//======================================================================//
// 1055. Shortest way to form a string
//Input:
    /*
    string soruce = "abc";
    string target = "acbac";

    printf("Shortest way %d\r\n", shortestWay(soruce, target));
    */
int shortestWay(string source, string target)
{
    
    int substring_count = 0;
    unordered_set<char> source_chars;
    unordered_set<char> target_chars;
    
    if(source.compare(target) == 0)
    {
        return 1;
    }
    
    for(int i = 0; i < source.size(); i++)
    {
        source_chars.emplace(source[i]);
    }
    
    for(int i = 0; i < target.size(); i++)
    {
        // Check if all the letters in target are present in source
        if(source_chars.find(target[i]) == source_chars.end())
            return -1;
        else
            target_chars.emplace(target[i]);
    }

    int start = 0;
    
    int i = 0;
    while(i < target.size())
    {
        start = i;
        int j = 0;
        
        while(j < source.size() && i < target.size())
        {
            if(source[j] == target[i])
                i++;
            j++;
        }
        substring_count++;
    }
    
    return substring_count;
}

//======================================================================//
//1057. Campus Bikes
//Input:
    /*
    vector<vector<int>>workers{{1,1},{3,1},{0,3}};
    vector<vector<int>>bikes{{2,2},{4,4},{2,4}};

    vector<int>ans = assignBikes(workers, bikes);
    print_1D_vector_int(ans);
     */
int distance(pair<int,int> a, pair<int,int> b)
{
    return abs(a.first-b.first)+abs(a.second-b.second);
}

vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes)
{
    vector<int> answer(workers.size());
    
    map<int,int> distance_map[workers.size()];
    
    for(int i = 0; i < workers.size(); i++)
    {
        for(int j = 0 ; j < bikes.size(); j++)
        {
            int dist = distance( make_pair(workers[i][0], workers[i][1]), make_pair(bikes[j][0], bikes[j][1]) );
            distance_map[i].insert({j,dist});
            printf("%d %d\r\n",j , dist);
        }
        printf("\r\n");
    }
    
    int min_distance = INT_MAX;
    int min_worker = 0;

    // Handle situatilns where another worker is already using the bike
    // Remove already used bikes from the table
    for(int i = 0; i < bikes.size(); i++)
    {
        for(int j = 0; j < workers.size(); j++)
        {
            auto itr = distance_map[j].find(i);
            if(itr->second < min_distance)
            {
                min_distance = itr->second;
                min_worker = j;
            }
        }
        answer[min_worker] = i;
    }
    
    return answer;
}

//======================================================================//

// Add and Search Word - Data structure design

struct TrieNode
{
    bool isWord;
    TrieNode* children[26];
    char c;
    
    TrieNode()
    {
        isWord = false;
        memset(children, NULL, sizeof(children));
    }
};

class Dictionary
{
private:
    TrieNode* root;
    
    bool search_word(string word, TrieNode* base_node)
    {
        TrieNode* curr = base_node;
        
        for(int i = 0; i < word.size() && curr; i++)
        {
            if(word[i] != '.')
            {
                curr = curr->children[word[i] - 'a'];
            }
            else
            {
                for(int j = 0 ; j < 26; j++)
                {
                    search_word(word.substr(i+1,word.size()-(i+1)), curr->children[j]);
                }
            }
        }
        return curr && curr->isWord;
    }
    
public:
    Dictionary()
    {
        root = new TrieNode();
    }
    
    void insert_word(string word)
    {
        TrieNode *curr =  root;
        
        for(int i = 0 ; i < word.size(); i++)
        {
            if(!curr->children[word[i] - 'a'])
            {
                curr->children[word[i]-'a'] = new TrieNode();
            }
            
            curr = curr->children[word[i]-'a'];
        }
        curr->isWord = true;
    }
    
    bool search_word(string word)
    {
        return search_word(word, root);
    }
};

//======================================================================//
// Input: [3,6,9,12]
// Output: 4
// Explanation: The whole array is an arithmetic sequence with steps of length = 3.
//Input
/*
vector<int>vec{3,4,6,8,9,10,12,14,15};
printf("longest Arithmetic Subsequence %d\r\n", longestArithmeticSubsequence(vec));
 */

int longestArithmeticSubsequence(vector<int>&A)
{
    int max = 0;
    unordered_map<int, int> mp;
    
    for(int i = 0 ; i < A.size()-1; i++)
    {
        for(int j = i+1; j < A.size(); j++)
        {
            int diff = A[j]-A[i];
            auto itr = mp.find(diff);
            
            if(itr != mp.end()) // diff is in map
            {
                itr->second++;
                max = MAX(max, itr->second);
                printf("diff: %d, mx: %d\r\n",itr->first,max);
            }
            else
            {
                mp.insert({diff,1});
            }
        }
    }
    for(int i = 0; i < mp.size(); i++)
    {
        printf("mp[%d]=%d\r\n",i,mp[i]);
    }
    
    return max+1;
}

//======================================================================//
//1480. Running Sum of 1d Array
//vector<int>data = {1,1,1,1,1,1,1};
//vector<int>sum;
//runningSum(data, sum);

void runningSum(vector<int>& data, vector<int>& running_sum)
{
  size_t i = 0;
  int sum_sofar = 0;
  while(i < data.size())
  {
    sum_sofar+= data[i];
    running_sum.push_back(sum_sofar);
    i++;
  }
}
//======================================================================//
//1304. Find N Unique Integers Sum up to Zero
//print1Dvector(sumZero(2));
vector<int> sumZero(int n)
{
  vector<int> vec;
  if(n <= 0)
    return vec;
  
  
  if(n%2)
  {
    vec.push_back(0);
  }
  
  for(int i = 1; i < (n/2) + 1; i++)
  {
    vec.push_back(i);
    vec.push_back(-i);
  }
  return vec;
}
//======================================================================//
//346. Moving Average from Data Stream
//Run:
//    MovingAverage* m = new MovingAverage(3);
//    printf("Moving avg: %lf\r\n",m->next(1));
//    printf("Moving avg: %lf\r\n",m->next(10));
//    printf("Moving avg: %lf\r\n",m->next(3));
//    printf("Moving avg: %lf\r\n",m->next(5));
class MovingAverage {
private:
    int window_size;
    int start_idx;
    int end_idx;
    int sum;
    int elements;
    vector<int> array;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    : window_size(size)
    , start_idx(0)
    , end_idx(0)
    , elements(0)
    , sum(0)
    {   //printf("capacity %d\r\n",array.capacity());
        array.reserve(size);
        //printf("capacity %d\r\n",array.capacity());
    }
    
    double next(int val)
    {
        //Init
        if(elements < window_size)
        {
            sum += val;
            array[elements] = val;
            elements++;
            return (double)sum/elements;
        }
        else{// Normal case
            //printf("sum %d, start %d", sum, start_idx);
            sum = (sum - array[start_idx]) + val;
            array[start_idx] = val;
            
            if((start_idx + 1) < window_size)
                start_idx++;
            else
                start_idx = 0;
            
            return (double)sum/window_size;
        }
    }
};

//======================================================================//
void reverse_string(char * str, int size)
{
    int s = 0;
    int e = size-2;
    
    while(s<e)
    {
        char temp = str[e];
        str[e--] = str[s];
        str[s++] = temp;
    }
    str[size-1] = '\0';
}

//======================================================================//
//1002. Find Common Characters
//Run:
//vector<string> strs;
//
//strs.push_back("cool");
//strs.push_back("lock");
//strs.push_back("coock");
//commonChars(strs);

void printMultiSetChar(multiset<char> chars)
{
    for(auto itr = chars.begin(); itr != chars.end(); itr++)
    {
        printf("%c ", *itr);
    }
    printf("\r\n");
}

unordered_map<char, int> commonChars_util(unordered_map<char, int>& dict, string str)
{
    unordered_map<char, int>newDict;
    for(int i = 0; i < str.size(); i++)
    {
        auto itr = dict.find(str[i]);
        if (itr!= dict.end() && itr->second != 0) {
            itr->second--;
            
            auto newItr = newDict.find(itr->first);
            
            if(newItr != newDict.end())
            {
                newItr->second++;
            }
            else{
                newDict.emplace(itr->first, 1);
            }
        }
    }
    return newDict;
}

void commonChars(vector<string>& A)
{
    unordered_map<char, int>common_pool;
    
    // Make a pool
    for(int i = 0 ; i < A[0].size(); i++)
    {
        common_pool[A[0][i]]++;
    }
    for(auto itr = common_pool.begin(); itr != common_pool.end(); itr++)
    {
        printf("%c %d\r\n", itr->first, itr->second);
    }
    printf("\r\n");
    for(int i = 0 ; i < A.size(); i++)
    {
        common_pool = commonChars_util(common_pool, A[i]);
    }
    
    for(auto itr = common_pool.begin(); itr != common_pool.end(); itr++)
    {
        printf("%c ", itr->first);
    }
}


//======================================================================//
//937. Reorder Data in Log Files

/* *********************** Amazing solution found in Discussion forum of this question on leetcode here : https://leetcode.com/problems/reorder-data-in-log-files/discuss/460589/98-Modern-C%2B%2B-using-STL-8-lines-of-code-with-detailed-explanation *********************** */
/*
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // We can break this problem into two tasks: 1) Parition 2) Sort letter-logs

        // Partition: letter-logs at the front, digit-logs at the back.
        // We're using stable_partition instead of partition to retain the original order.
        // stable_partition returns an iterator to the first element of the second group.
        
        auto it = stable_partition(logs.begin(), logs.end(), [](const string& str) {
            return isalpha(str[str.find(' ') + 1]);
        });

        // Sort letter-logs: We're only iterating on letter-logs in this case.
        // We're creating a substring for every element we compare that doesn't include the identifier
        // If the logs are the same except the identifier, we compare the strings, otherwise, the substrings
        
        sort(logs.begin(), it, [](const string& str1, const string& str2) {
            auto substr1 = string(str1.begin() + str1.find(' '), str1.end());
            auto substr2 = string(str2.begin() + str2.find(' '), str2.end());
            return (substr1 == substr2) ? str1 < str2 : substr1 < substr2;
        });
        
        return logs;
    }
};
*/


// My Solution


struct comp{
    template<typename T>
    
    bool operator()(const T& l, const T& r)
    {
        
        if(l.second > r.second)
        {
            return false;
        }
        else if(l.second < r.second)
        {
            return  true;
        }
        else{
            if(l.first > r.first)
            {
                return false;
            }
            else{
                return true;
            }
        }
    }
};


typedef struct idLog{
    bool isNumeric;
    string id;
    string log;
}Logger_t;

void print_pairs(vector<pair<string, string>>& logs)
{
    for(int i = 0; i < logs.size(); i++)
    {
        printf("ID: %s, Log: %s\r\n", logs[i].first.c_str(), logs[i].second.c_str());
    }
}

void print_logger(vector<Logger_t> log)
{
    for(int i =0; i < log.size(); i++)
    {
        printf("id: %s, log: %s, %d\r\n", log[i].id.c_str(), log[i].log.c_str(), (log[i].isNumeric==true) ? 1 : 0);
    }
}

void print_set(set<pair<string,string>, comp>& st)
{
    for(auto itr = st.begin(); itr != st.end(); itr++)
    {
        cout << itr->first << itr->second << endl;
    }
}

class RecordDataLogger {
private:
    vector<Logger_t> logs_new;
    vector<pair<string,string>> numeric_log;
    vector<pair<string,string>> alpha_log;
    
    void combine_log(vector<string>& numeric)
    {
        for(int i = 0; i < numeric_log.size(); i++)
        {
            numeric.push_back(numeric_log[i].first+ " " +numeric_log[i].second);
        }
    }
    
    void saperate_alpha_numeric_logs()
    {
        for(int i = 0; i < logs_new.size(); i++)
        {
            if(logs_new[i].isNumeric)
            {
                numeric_log.push_back({logs_new[i].id, logs_new[i].log});
            }
            else{
                alpha_log.push_back({logs_new[i].id, logs_new[i].log});
            }
        }
    }
    
    void clean_logs(vector<string>& logs)
    {
        Logger_t elem;
        for(int i = 0; i < logs.size(); i++)
        {
            // Find first space;
            size_t size = logs[i].size();
            size_t idx = logs[i].find(" ");
            if(idx == string::npos)
            {
                printf("no space");
                elem.id = logs[i];
            }
            else{
                elem.id = logs[i].substr(0, idx);
                elem.log = logs[i].substr(idx+1, size - (idx+1));
                elem.isNumeric = false;
                if('0' <= elem.log[0] && elem.log[0] <= '9')
                {
                    elem.isNumeric = true;
                }
                logs_new.push_back(elem);
            }
        }
    }
public:
        vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> op_logger;
        set<pair<string,string>, comp> st;
        
        clean_logs(logs);
        saperate_alpha_numeric_logs();
        
        for(int i = 0; i < alpha_log.size(); i++)
        {
            st.insert(alpha_log[i]);
        }
        
        for(auto itr = st.begin(); itr != st.end(); itr++)
        {
            op_logger.push_back(itr->first + " " + itr->second);
        }
        
        combine_log(op_logger);
        
        return op_logger;
    }
};


//======================================================================//

//243. Shortest Word Distance

//vector<string>words = {"practice", "makes", "perfect", "coding", "makes"};
//printf("Shortest Dist = %d" , shortestDistance(words, "practice", "perfect"));
//vector<string>words = {"a", "b", "c", "a", "a", "q","m","r","m","a","a","q","m"};
//printf("Shortest Dist = %d" , shortestDistance(words, "a", "m"));


/* Explination:
    there are 3 possibilities to count the distance:
 1. if the current word and the word we started counting from (base word) are same - Distance resets
 2. if current word and the word we started counting from (base word) are different (eg. base_word == word1 & current_word == word2) - Log distnce if minimum, update base word
 3. if current word doesnt match with either word1 or word2, in that case, just count up
 
 Other things:
    count up always
    update base word when current word matches one of the lookup words.
 */

int shortestDistance(vector<string>& words, string word1, string word2)
{
    int cntr = 0;
    int dist = INT_MAX;
    string base_word = {};
    
    for(int i = 0 ; i < (int)words.size(); i++)
    {
        // Current word is one of the target words
        if(words[i] == word1 || words[i] == word2)
        {
            if(base_word != words[i] && base_word != "")
            {
                dist = min(dist, cntr);
            }
            else{
                cntr = 0;
            }
            base_word = words[i];
        }
        cntr++;
    }
    return dist;
}

//======================================================================//
//1395. Count Number of Teams
//vector<int> team = {2,5,3,4,1};
//printf("Teams %d", numTeams(team));

int numTeams(vector<int>& rating) {

    int idx1 = 0;
    int idx2 = 1;
    int idx3 = 2;
    int teamCount = 0;
    while(idx1 < rating.size() - 2)
    {
        idx2 = idx1+1;
        while(idx2 < rating.size() - 1)
        {
            idx3 = idx2+1;
            while(idx3 < rating.size())
            {
                if(rating[idx1] < rating[idx2] && rating[idx2] < rating[idx3])
                {   // Ascending
                    teamCount++;
                }
                else if(rating[idx1] > rating[idx2] && rating[idx2] > rating[idx3])
                {
                    teamCount++;
                }
                idx3++;
            }
            idx2++;
        }
        idx1++;
    }
    
    return teamCount;
}


//======================================================================//
/*
Light sensor question

Background
==========
Security cameras often have an Ambient Light Sensor (ALS) which measures the amount of light around the camera and triggers a "night mode" when the ambient light is too low.

You've been given an ALS that reports sensor readings using the following struct:
  typedef struct SensorReading {
    int status;
    float lux;
    uint64_t timestamp; // time of reading
  } SensorReading;
  
To get a sensor reading, call:
SensorReading read_next_sample(uint64_t max_wait) { ... }
This function is blocking!  It doesn't return a value until either max_wait microseconds have elapsed or the ALS returns a new value.  The SensorReading.status int indicates whether the value changed (VALID) or not (NO_CHANGE).

(We've implemented a mock version of read_next_sample below, but you do not need to read the code and understand it to complete this task).

Task
====
Working with blocking functions is hard and not thread-friendly, so we want to wrap the ALS function in a non-blocking, thread-safe way.
Design and implement an API that allows users to read lux values from any time within the last 10 minutes.  Your API should be non-blocking and thread-safe.
*/

/* Status enum */
enum Status {
  ERROR = 0,
  NO_CHANGE = 1,
  VALID = 2,
};

/* Don't edit this code */
struct SensorReading {
  int status;
  float lux;
  uint64_t timestamp;
};

class sensorData
{
    private:
        queue<SensorReading> q;
        time_t currTime;
        mutex mtx;
        
        time_t getCurrentTime()
        {
            return time(nullptr);
        }
        
    public:
        sensorData()
        {
            currTime = time(nullptr);
        }
        
        bool isAvailable(){
            if(q.empty())
                return true;
            else
                return false;
        }
        
        void addData(SensorReading reading)
        {
            mtx.lock();
            q.push(reading);
            mtx.unlock();
        }
        
        SensorReading getData()
        {
            mtx.lock();
            if(q.empty())
            {
                mtx.unlock();
                return SensorReading{ERROR, 0.0, 0};
            }
            
            SensorReading dat = q.front();
            currTime = getCurrentTime();
            while(!q.empty() && dat.timestamp > (currTime - 10) )
            {
                q.pop();
                dat = q.front();
            }
            
            if(q.empty()){
                mtx.unlock();
                return SensorReading{ERROR, 0.0, 0};
            }
            q.pop();
            mtx.unlock();
            return dat;
        }
};

/* these functions are provided for you; no need to implement */
uint64_t get_timestamp();
SensorReading read_next_sample(uint64_t max_wait);


//======================================================================//
//290. Word Pattern
// Input:
// if(wordPattern("aabc", "dog dog cat suvar"))
// {
//     printf("pattern matched\r\n");
// }
// else{
//     printf("Pattern not matched \r\n");
// }

bool wordPattern(string pattern, string s) {
    // Saperate Words in an array
    // walk thorugh the pattern and words array and push to letter and word map
    // If letter exist in a map, check value matches the current word
    
    int start = 0;
    vector<string> words;
    unordered_map<char, string>hash;
    unordered_set<string> uniqueStrings;
    
    int idx = (int)s.find(" ");
    while(idx > 0)
    {
        words.push_back(s.substr(start, idx-start));
        start = idx+1;
        idx = (int)s.find(" ", start);
    }
    
    if(start < s.size())
    {
        words.push_back(s.substr(start, s.size()-start));
    }
    
    for(int i = 0; i < pattern.size(); i++)
    {
        if(hash.find(pattern[i]) == hash.end()){
            if(uniqueStrings.find(words[i]) == uniqueStrings.end()){
                hash[pattern[i]] = words[i];
                uniqueStrings.emplace(words[i]);
            }
            else{
                    return false;
            }
        }
        else{
            if(hash.at(pattern[i]) != words[i]){
                return false;
            }
        }
    }
    
    for(int i = 0; i < words.size(); i++)
    {
        printf("%s\r\n", words[i].c_str());
    }
    return true;
}

//======================================================================//
//665. Non-decreasing Array
//vector<int> vec = {5,4,2};    // {4,2,3} {4,2,1} {3,2,5} {5,4,2}
//if(checkPossibility(vec)){
//    printf("You can modify this array to get a non-decreasing array\r\n");
//}
//else{
//    printf("You can not modify this array to get a non-decreasing array\r\n");
//}
bool checkPossibility(vector<int>& nums) {
    int outlier = -1;
    
    for(size_t i = 0; i < nums.size()-1; i++)
    {
        if(nums[i] > nums[i+1])
        {
            if(outlier == -1 && ( i == 0 || (nums[i+1]-nums[i-1]) > 1))
                outlier = (int)i;
            else
                return  false;
        }
    }
    return true;
}

//======================================================================//
//Circular Ring Buffer
//Input:
    //circBuffer<char> ring(5);
    //char c;
    //int temp = ring.circ_pop(&c);
    //printf("pop retval %d char %c\r\n", temp, c);
    //c = 'a';
    //temp = ring.circ_push(c);
    //printf("pop retval %d char %c\r\n", temp, c);
    //c = 'b';
    //temp = ring.circ_push(c);
    //printf("pop retval %d char %c\r\n", temp, c);
    //ring.print();
    //c = 'c';
    //temp = ring.circ_push(c);
    //printf("push retval %d\r\n", temp);
    //c = 'd';
    //temp = ring.circ_push(c);
    //printf("push retval %d\r\n", temp);
    //c = '2';
    //temp = ring.circ_push(c);
    //printf("push retval %d\r\n", temp);
    //c = '1';
    //temp = ring.circ_push(c);
    //printf("push retval %d\r\n", temp);
    //ring.print();
    //temp = ring.circ_pop(&c);
    //printf("pop retval %d char %c\r\n", temp, c);
    //ring.print();
    //temp = ring.circ_pop(&c);
    //printf("pop retval %d char %c\r\n", temp, c);
    //temp = ring.circ_pop(&c);
    //printf("pop retval %d char %c\r\n", temp, c);
    //temp = ring.circ_pop(&c);
    //printf("pop retval %d char %c\r\n", temp, c);
    //temp = ring.circ_pop(&c);
    //printf("pop retval %d char %c\r\n", temp, c);
    //ring.print();
template <typename T>

class circBuffer{
    uint16_t read_p;
    uint16_t write_p;
    const size_t size;
    vector<T> buffer;
public:
    circBuffer(size_t bufsize)
    : read_p(0)
    , write_p(0)
    ,size(bufsize){
        buffer.reserve(size);
    }
    
    int circ_push(T const c){
        uint16_t next = write_p + 1;
        
        if(next >= size)
            next = 0;
        
        if(next == read_p)
            return -1;          // Discard, ring buffer is full
        
        buffer[write_p] = c;
        write_p = next;
        
        return 0;
    }
    
    int circ_pop(T * const c){
        if(read_p == write_p)
            return -1;              // ringBuffer empty
        
        uint16_t next = read_p + 1;
        
        if(next >= size)
            next = 0;
        
        *c = buffer[read_p];
        read_p = next;
        
        return 0;
    }
    
    void print()
    {
        int i = read_p;
        while(i != write_p)
        {
            printf("%c ", buffer[i]);
            i++;
            if(i >= size)
                i = 0;
        }
        printf("\r\n");
    }
};

//======================================================================//
// Rotate 2D Matrix 90 degree
//Input:
    //int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    //int result[4][4] = {0};
    //rotate2D((int *)matrix, 4, 4, (int *)matrix, (int *)result);
    //
    //for(int i = 0; i < 4; i++)
    //{
    //    for(int j = 0; j < 4; j++)
    //    {
    //        printf("%d\t", result[i][j]);
    //    }
    //    printf("\r\n");
    //}

void rotate2D(int* matrix1, int m, int n, int* matrix2, int* result)
{
    for(int i = 0 ;i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            *((result+i*n)+j)= *((matrix1+i*n)+j) + *((matrix1+i*n)+j);
        }
    }
}


//======================================================================//
// LL Stack without double pointer
//Input:
    //myStack stack;
    //printf("Peek %d\r\n", stack.peek());
    //printf("Pop %d\r\n", stack.pop());
    //stack.push(5);
    //printf("Peek %d\r\n", stack.peek());
    //printf("Pop %d\r\n", stack.pop());
    //printf("Peek %d\r\n", stack.peek());
    //stack.push(1);
    //stack.push(2);
    //stack.push(3);
    //stack.push(4);
    //printf("Stack size %d\r\n", stack.size());
    //for(int i = stack.size(); i > 0; i--)
    //{
    //    printf("Processing %d %d: \r\n", i , stack.size());
    //    printf("\tPeek %d %d\r\n", i, stack.peek());
    //    printf("\tPop %d size now %d\r\n", stack.pop(), stack.size());
    //}

typedef struct node{
    struct node* next;
    int val;
    node(){}
    node(int data): next(nullptr),val(data){};
    node(int data, node* p): next(p),val(data){};
}NODE_t, *NODE_p;

class myStack{
private:
    NODE_p top;
    int stackSize;
public:
    myStack(): top(nullptr), stackSize(0){};
    
    void push(int val){
        if(!top){
            top = new node(val);
        }
        else{
            NODE_p temp = new node(val, top);
            top = temp;
        }
        stackSize++;
    }
    
    int pop(){
        if(top){
            NODE_p temp = top;
            top = top->next;
            int val = temp->val;
            free(temp);
            stackSize--;
            return val;
        }
        return -1;
    }
    
    int peek(){
        if (top) {
            return top->val;
        }
        return -1;
    }
    bool isEmpty()
    {
        return stackSize ? true : false;
    }
    int size(){
        return stackSize;
    }
};

//======================================================================//
//Find missing number from a sequential array eg [0, 1, 3], Ans: missing number is 2

// Intuition:
//"XOR of same numbers is zero"
// Above statement is powerfull and can solve a lot of problems along the lines of this one.
// Idea is to xor 0 with its index i.e. 0 and the result is zero
// Algorithm:
    // result = 0
    // repeat above for the length of the vector
        // XOR current index with result
        // XOR current element with result
    // XOR result with size of vector with result -- This is important
    // return

// Other variations of this problem can be
    // Find the non repeating element from the vector
    // Find missing number from sequential array starting from N

//vector<uint16_t> vec = {0,1,3};
//printf("Missing number is %u\r\n", findMissingNumber(vec));

uint16_t findMissingNumber(vector<uint16_t>& vec)
{
    uint16_t temp = 0;
    for(int i = 0; i < vec.size(); i++){
        temp ^= i;
        temp ^= vec[i];
    }
    return temp ^ (uint16_t)vec.size();
}


//======================================================================//
//Amazon phone interview question, create two methods for a deck, shuffle() and draw()
//Input:
//    vector<int> deck;
//
//    create_deck(deck);
//    shuffle_deck(deck);
//
//
//    for(int i = 0; i < (int)deck.size(); i++)
//    {
//      printf("%d, ",deck[i]);
//    }
//    printf("erased %d\r\n", draw_card(deck));
//    for(int i = 0; i < (int)deck.size(); i++)
//    {
//      printf("%d, ",deck[i]);
//    }
void create_deck(vector<int>& vec)
{
  for(int i=0 ; i < 52; i++)
  {
    vec.push_back(i);
  }
}

int myRand(int j)
{
  return rand() % j;
}

void shuffle_deck(vector<int>& deck)
{
  random_shuffle(deck.begin(), deck.end(), myRand);
}

int draw_card(vector<int>& deck)
{
  int card = *deck.begin();
  deck.erase(deck.begin());
  return card;
}

//======================================================================//
//819. Most Common Word
//Input:
//    string para = "Bob hit a ball, the hit BALL flew far after it was hit.";
//    vector<string> banned = {"hit"};
//    printf("Most commonw word is %s\r\n", mostCommonWord(para, banned).c_str());

struct myComparePair{
  
    bool operator()(const pair<string,int>& a, const pair<string,int>& b){
        return a.second < b.second;
    }
};

template <typename T>
void extractWords(string para, T& words)
{
    size_t i = 0;
    size_t start = 0;
    while(start < para.size())
    {
        if(! (('A' <= para[i] && para[i] <= 'Z') || ('a' <= para[i] && para[i] <= 'z'))){
            if(i - start > 0){
                string substr = para.substr(start, i - start);
                transform(substr.begin(), substr.end(), substr.begin(), [](unsigned char c){return tolower(c);});
                words[substr]++;
            }
            start = i + 1;
        }
        i++;
    }
}

/* This was my first implementation*/
// Time Complexity O(n + (m*n)) because this implementation rotates throug the list of banned words n times which is approximately n2
string mostCommonWord_firsttry(string para, vector<string> banned) {
    
    priority_queue<pair<string, int>, vector<pair<string, int>>, myComparePair> pq;
    map<string, int> words;
    extractWords(para, words);
    printf("Printing now\r\n");
    for(auto i = words.begin(); i != words.end(); i++)
    {
        printf("%s %d\r\n", i->first.c_str(), i->second);
        pq.push(*i);
    }
    
    while(std::find(banned.begin(), banned.end(), pq.top().first) != banned.end())
    {
        pq.pop();
    }
    
    return pq.top().first;
}


// Time Complexity O(n)
string mostCommonWord_secondtry(string para, vector<string> banned){
    map<string,int> wordMap;
    size_t i = 0;
    size_t start = 0;
    string maxString = "";
    int maxOccurance = 0;
    
    // Saheb suggested this
    // add each banned word to the map and set to -1
    // This will enable us to go through the list of banned only once
    for(size_t i = 0; i < banned.size(); i++)
    {
        wordMap[banned[i]] = -1;
    }
    
    // Start adding words from para to the map, check if the value is not -1(i.e banned)
    while(start < para.size()){
        if(! (('A' <= para[i] && para[i] <= 'Z') || ('a' <= para[i] && para[i] <= 'z'))){
            if(i - start > 0){
                string substr = para.substr(start, i - start);
                transform(substr.begin(), substr.end(), substr.begin(), [](unsigned char c){return tolower(c);});
                if(wordMap[substr] != -1){
                    wordMap[substr]++;
                    maxOccurance = max(maxOccurance, wordMap[substr]);
                    if(maxOccurance == wordMap[substr])
                        maxString = substr;
                }
            }start = i + 1;
        }i++;
    }
    
    return maxString;
}

//======================================================================//

//shift array

void shift_array(vector<int>& arr, int shift)
{
//    int temp = arr[shift];
    int j = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if((shift + i) < arr.size()){
            arr[shift+i] = arr[i];
        }
        else{
            arr[j++] = arr[i];
        }
    }
}

//======================================================================//

int main()
{

    
    return 0;
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

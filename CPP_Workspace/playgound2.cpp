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
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

//======================================================================//
// Utility Functions //
//======================================================================//

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

//======================================================================//

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

int main()
{
    MovingAverage* m = new MovingAverage(2);
    printf("Moving avg: %lf\r\n",m->next(1));
    printf("Moving avg: %lf\r\n",m->next(10));
    printf("Moving avg: %lf\r\n",m->next(3));
    printf("Moving avg: %lf\r\n",m->next(5));
    
    /*
    vector<int>vec{3,4,6,8,9,10,12,14,15};
    printf("longest Arithmetic Subsequence %d\r\n", longestArithmeticSubsequence(vec));
     */
    /*
    vector<vector<int>>workers{{1,1},{3,1},{0,3}};
    vector<vector<int>>bikes{{2,2},{4,4},{2,4}};
    
    vector<int>ans = assignBikes(workers, bikes);
    print_1D_vector_int(ans);
     */
    /*
    string soruce = "abc";
    string target = "acbac";
    
    printf("Shortest way %d\r\n", shortestWay(soruce, target));
    */
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
/*
    vector<string>querries {"sparta", "spartaaa", "leemon"};
    vector<string>words {"aaaabbcs", "abcsrsaa", "bbcjdhs"};
    
    vector<int> ans = compare_by_freq_of_smallest_char(querries, words);
    print_1D_vector_int(ans);
*/
    
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

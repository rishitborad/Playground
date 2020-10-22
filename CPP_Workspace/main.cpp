//
//  main.cpp
//  CPP_Workspace
//
//  Created by Rishit Board on 4/12/19.
//  Copyright © 2019 Rishit Board. All rights reserved.
//

// Gitlab - dhZtFVuj5xgJUJT1rkVW

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <array>
#include <stack>
#include <utility>

using namespace std;

typedef struct Node
{
    int data;
    struct Node* next;
    
}NODE_t, *NODE_p;

typedef struct Tree_Node
{
    int data;
    struct Tree_Node* left;
    struct Tree_Node* right;
    
}TREENODE_t, *TREENODE_p;

//======================================================================//
int longest_sequential_subarray(int * arr, int n)
{
    int max_len = 0;
    unordered_set<int> set;
    
    for(int i = 0; i < n; i++)
    {
        set.insert(arr[i]);
    }
    
    for(int i = 0; i < n; i++)
    {
        int j = arr[i];
        // Fist element of the possible seq.subarray
        if(set.find(arr[i]-1) == set.end())
        {
            while(set.find(j) != set.end())
            {
                //printf("j = %d\r\n",j);
                j++;
            }
            //printf("max_len %d, %d-arr[%d] = %d\r\n", max_len, j,i,arr[i]);
            max_len = max(max_len, j-arr[i]);
        }
    }
    
    return max_len;
}
//======================================================================//
// Find max lenght sub-array having equal number of 0s and 1s
void max_len_subarray(int *arr, int n)
{
    int sum = 0;
    int end_index = -1;
    int len = 0;
    
    unordered_map<int, int> map;
    map[0] = -1;
    
    for(int i = 0; i < n; i++)
    {
        sum += (arr[i]==0?-1:1);
        
        if(map.find(sum)!= map.end())
        {
            if(len < i - map[sum])
            {
                len = i-map[sum];
                end_index = i;
            }
        }
        else{
            map[sum] = i;
        }
    }
    
    printf("Longest sunsequent array of 0's and 1's start %d, end %d\r\n", end_index-len+1, end_index);
}
//======================================================================//
// similar logic but better program in leet codes
int longestPalindrome(char* s, int n) {

    int maxlength = -1;
    int start = -1;
    int len = 0;
    
    for(int i = 0; i < n; i++)
    {
        int lo = i;
        int hi = i;
        
        while(lo >= 0 && hi < n && s[lo] == s[hi])
        {
            printf("s[%d] == s[%d], %c == %c\r\n",lo,hi,s[lo],s[hi]);
            len = (hi-lo)+1;
           
            if(len > maxlength)
            {
                start = lo;
                maxlength = len;
            }
            hi++;
            lo--;
        }
        
        lo = i-1;
        hi = i;
        
        while(lo >= 0 && hi < n && s[lo] == s[hi])
        {
            len = (hi-lo)+1;
            
            if(len > maxlength)
            {
                start = lo;
                maxlength = len;
            }
            hi++;
            lo--;
        }
    }
    
    printf("longest palindrom substring length is %d\r\n", maxlength);
    for(int i = start; i < start+maxlength-1; i++)
    {
        printf("%c ",s[i]);
    }
    return maxlength;
}

//======================================================================//
class LRU_cache
{
private:
    // Store keys of the cache
    list<int> dq;
    //Store reference of the key in cache
    unordered_map<int, list<int>::iterator> ma;
    
    int csize;      // Max size of the cache
public:
    
    LRU_cache(int);
    void refer(int);
    void display();
};

LRU_cache::LRU_cache(int n)
: csize(n) {}

void LRU_cache::refer(int x)
{
    // not present in cache
    if (ma.find(x) == ma.end())
    {
        // cache is full
        if (dq.size() == csize)
        {
            //delete least recently used element
            int last = dq.back();
            dq.pop_back();
            ma.erase(last);
        }
    }
    // present in cache
    else
        dq.erase(ma[x]);
    
    // update reference
    dq.push_front(x);
    ma[x] = dq.begin(); // dq.begin return an address of the first element in the list and store it in map in front of key x
    
    //printf("dq begind %d", dq.begin());
    //printf("ma[%d] %d, dq %d\r\n", x, *ma[x], *dq.begin());
}

void LRU_cache::display()
{
    for (auto it = dq.begin(); it != dq.end(); it++)
        cout << (*it) << " ";
    
    cout << endl;
    
    
    for(auto i = ma.begin(); i !=ma.end(); i++)
    {
        //printf("%d %d\r\n", i->first, i->second);
    }
}

//======================================================================//

bool check_anagram(char *str1, char *str2)
{
    unordered_map<char, int> map;
    
    char *itr;
    itr = str1;
    
    while(*itr != '\0')
    {
        map[*itr]++;
        itr++;
    }
    printf("\r\n");
    for(auto i = map.begin(); i != map.end(); i++)
    {
        printf("ana1 : %c %d\r\n", i->first, i->second);
    }
    
    itr = str2;
    while(*itr != '\0')
    {
        map[*itr]--;
        itr++;
    }
    
    for(auto i = map.begin(); i != map.end(); i++)
    {
        printf("ana2 : %c %d\r\n", i->first, i->second);
    }
    return false;
}
/*
// Good problem
// https://www.techiedelight.com/print-nodes-binary-tree-specific-order/
void print_tree_top_bottom(TREENODE_p head)
{
    queue<TREENODE_p> lQ, rQ;
    
    lQ.push(head->left);
    rQ.push(head->right);
    
    while(!lQ.empty())
    {
        size_t n = lQ.size();
        
        while(n--)
        {
            TREENODE_p lq_front = lQ.front();
            lQ.pop();
            
            printf("%d ", lq_front->data);
            
            if(lq_front->left)
                lQ.push(lq_front->left);
            if(lq_front->right)
                lQ.push(lq_front->right);
            
            TREENODE_p rq_front = rQ.front();
            rQ.pop();
            
            printf("%d ", rq_front->data);
            
            if(rq_front->right)
                rQ.push(rq_front->right);
            if(rq_front->left)
                rQ.push(rq_front->left);
        }
    }
}
*/
//======================================================================//

bool three_sum(int arr[], int n)
{
    bool found = false;
    
    for(int i = 0; i < n-1; i++)
    {
        unordered_set<int> set;
        
        for(int j = i+1; j < n; j++)
        {
            int x = -(arr[i] + arr[j]);
            
            if(set.find(x) != set.end())
            {
                printf("%d %d %d\r\n", x, arr[i], arr[j]);
                found = true;
            }
            else
            {
                set.insert(arr[j]);
            }
        }
    }
    if(!found)
    {
        printf("Did not have three some");
        return false;
    }
    return true;
}

//======================================================================//
const char hashTable[10][5] = {{},{},{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};

void combination_of_phone_numbers(int num[], int curr_dig, char arr[], int n)
{
    if(curr_dig == n)
    {
        printf("arr %s\r\n", arr);
    }
    else{
        for(int i = 0; i < strlen(hashTable[num[curr_dig]]); i++)
        {
            arr[curr_dig] = hashTable[num[curr_dig]][i];
            combination_of_phone_numbers(num, curr_dig+1, arr, n);
        }
    }
}

//======================================================================//

void swap_char(char*a,char*b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutation_of_string(char * a, int l, int r)
{
    if(l == r)
    {
        printf("%s\r\n",a);
    }
    else{
        
        for(int i = l; i <= r; i++)
        {
            swap_char(a+l, a+i); printf("\t1S: i %d l %d, r %d, swp %c %c\r\n", i,l,r, *(a+l), *(a+i));
            permutation_of_string(a, l+1, r);
            swap_char(a+l, a+i); printf("\t2S: i %d l %d, r %d, swp %c %c\r\n", i,l,r, *(a+l), *(a+i));
        }
    }
}
//======================================================================//

class Anagrams {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};

//======================================================================//
// Return first unique character and its index from the string
int unique_char(string s)
{
    pair<int,int> p[26];
    
    for(int i = 0; i< s.size(); i++)
    {
        (p[s[i]].first)++;
        p[s[i]].second = i;
    }
    
    int res = INT_MAX;
    for(int i = 0; i < 26; i++)
    {
        
        if(p[i].first == 1)
        {
            res = min(res, p[i].second);
        }
    }
    
    return res;
}

//======================================================================//

void STL_Experiments()
{
    // Create a vector containing integers
    std::vector<int> v = {7, 5, 16, 8};
    
    // Add two more integers to vector
    v.push_back(25);
    v.push_back(13);
    
    // Iterate and print values of vector
    for(int n : v) {
        std::cout << n << '\n';
    }
    
    std::cout<<v[1]<<'\n';
#if 0
    set<int> set;
    set.insert(5);
    
    for(auto i = set.begin(); i != set.end(); i++)
    {
        printf("%d \r\n", *i);
    }
#endif
#if 0
    map<int, int> mp;
    
    mp.insert(make_pair(5, 10));
    mp[10] = 100;
    
    for(auto i = mp.begin(); i != mp.end(); i++)
    {
        printf("%d %d\r\n", i->first, i->second);
    }
    
    mp[5] = 40;
    
    for(auto i = mp.begin(); i != mp.end(); i++)
    //for(int i = 0; i < mp.size(); i++)  // THis doesnt work
    {
        printf("%d %d\r\n",i->first, i->second);
    }
#endif
}

//======================================================================//

int invert_util(int n)
{
    return (n == 0) ? 1 : 0;
}

vector<vector<int>> flip_andinvert_image(vector<vector<int>> &orig)
{
    for(int i = 0; i < orig.size(); i++)
    {
        for(int j = 0; j < (orig[0].size()+1)/2; j++)       // TODO: Check this limit for n = even, n = odd
        {
            int temp = orig[i][j];
            orig[i][j] = invert_util(orig[i][orig[0].size()-1-j]);
            orig[i][orig[0].size()-1-j] = invert_util(temp);
        }
        printf("\r\n");
    }
    return orig;
}

//======================================================================//
// Better implementation in Leetcode
int number_of_emails_sent(vector<string>&email_list)
{
    //int unique_email_count = 0;
    char delim = '@';
    char dot = '.';
    char plus = '+';
    
    unordered_multimap<string, string> unique_emails;
    
    for(int i = 0; i < email_list.size(); i++)
    {
        string local;
        string domain;
        
        string s = email_list[i];
        size_t n = count(s.begin(), s.end(), delim);
        
        if(n != 1 || s[0] == '+' /*|| check for empty domain */ )
        {
            continue;
        }
        
        int at = s.find(delim);
        local = s.substr(0, at);
        domain = s.substr(at+1,s.size());
        
        // Handle any dots
        int dot_idx = local.find(dot);
        while(dot_idx != -1)
        {
            
            local = local.substr(0,dot_idx) + local.substr(dot_idx+1, local.size());
            dot_idx = local.find(dot);
        }
        
        // Handle any +s
        if(local.find(plus) != -1)
        {
            local = local.substr(0,local.find(plus));
        }
        
        bool isLocalUnique = true;
        bool isDomainUnique = true;
        
        for(auto i = unique_emails.begin(); i != unique_emails.end(); i++)
        {
            // check in map for uniqueness
            if(i->first == local)
            {
                isLocalUnique = false;
                if(i->second == domain)
                {
                    isDomainUnique = false;
                }
            }
        }
        if(isLocalUnique && isDomainUnique)
        {
            unique_emails.insert(make_pair(local, domain));
        }
        else if(isDomainUnique == true)
        {
            unique_emails.insert(make_pair(local, domain));
        }
    }
    
    for(auto i = unique_emails.begin(); i != unique_emails.end(); i++)
    {
        cout << i->first << " " << i->second << "\r\n";
    }
    
    return unique_emails.size();
}

//======================================================================//

bool robot_moves(string s)
{
    int hl_sum = 0;
    int vl_sum = 0;
    
    for(int i = 0; i < s.length(); i++)
    {
        printf("%c ", s[i]);
        switch(s[i])
        {
            case 'U': vl_sum++; break;
            case 'D': vl_sum--; break;
            case 'L': hl_sum++; break;
            case 'R': hl_sum--; break;
            default:
                break;
        }
    }
    
    if(!vl_sum && !hl_sum)
    {
        return true;
    }
    return false;
}


//======================================================================//



void number_of_islands_util(vector<vector<int>>&v, int r, int c)
{
    if(v[r][c] == 0)
    {
        return;
    }
    else
    {
        v[r][c] = 0;
        if(r+1 < v.size() && v[r+1][c] != 0) number_of_islands_util(v, r+1, c);
        if(r-1 >= 0 && v[r-1][c] != 0) number_of_islands_util(v, r-1, c);
        if(c+1 < v[0].size() && v[r][c+1] != 0) number_of_islands_util(v, r, c+1);
        if(c-1 >= 0 && v[r][c-1] != 0) number_of_islands_util(v, r, c-1);
    }
}

int number_of_islands(vector<vector<int>>&v)
{
    int islands = 0;
    
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j< v[0].size(); j++)
        {
            if(v[i][j])
            {
                islands++;
                number_of_islands_util(v, i, j);
            }
        }
    }
    return islands;
}

//======================================================================//

int island_perimeter_util(vector<vector<int>>&v, int r, int c)
{
    int u=0,d=0,l=0,ri=0;
    printf("%d %d\r\n", r,c);
    
    if(v[r][c] == 0)
    {
        return 1;
    }
    else
    {
        v[r][c] = 0;
        
        if(r+1 < v.size())
            u = island_perimeter_util(v, r+1, c);
        else
            u = 1;
        
        if(r-1 >= 0)
            d = island_perimeter_util(v, r-1, c);
        else
            d = 1;
        
        if(c+1 < v[0].size())
            l = island_perimeter_util(v, r, c+1);
        else
            l = 1;
        
        if(c-1 >= 0)
            ri = island_perimeter_util(v, r, c-1);
        else
            ri = 1;
        
        return u+d+l+ri;
    }
}

int island_perimeter(vector<vector<int>>&v)
{
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[0].size(); j++)
        {
            if(v[i][j] == 1)
            {
                return island_perimeter_util(v, i, j);
            }
        }
    }
    return 0;
}

//======================================================================//
// All number disappeared in array

list<int> disappeared_in_array(array<int,8> v)
{
    list<int>li;
    set<int> set;
    
    int mn = INT_MAX, mx = INT_MIN;
    
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] < mn)
            mn = v[i];
        else if(v[i] > mx)
            mx = v[i];
        
        set.insert(v[i]);
    }
    
    for(int i = mn; i <= mx; i++)
    {
        if(set.find(i) == set.end())
        {
            li.push_back(i);
        }
    }
    return li;
}

//======================================================================//

string add_strings(string s1, string s2)
{
    int n = s1.size()-1;
    int m = s2.size()-1;
    string res;
    int carry = 0;
    while( n >= 0 || m >= 0 || carry)
    {
        int sum = 0;
        if (n >= 0) sum += s1[n--] - '0';
        if (m >= 0) sum += s2[m--] - '0';
        sum += carry;
        res = to_string(sum%10) + res;
        carry = sum/10;
    }
    return res;
}

//======================================================================//

void reverse_vowels(string &s)
{
    if(s.empty())
    {
        return;
    }
    
    size_t n = s.size();
    
    int i = 0;
    int j = n-1;
    
    int chars[256];
    
    chars['a'] = 1;
    chars['e'] = 1;
    chars['i'] = 1;
    chars['o'] = 1;
    chars['u'] = 1;
    chars['A'] = 1;
    chars['E'] = 1;
    chars['I'] = 1;
    chars['O'] = 1;
    chars['U'] = 1;
    
    while(i < j)
    {
        while(i < j && chars[s[i]] == 0)    i++;
        while(i < j && chars[s[j]] == 0)    j--;
        std::swap(s[i],s[j]);
        i++; j--;
    }
}

//======================================================================//

void plus_one(vector<int>&arr)
{
    size_t n = arr.size();
    
    int i = n-1;
    int carry = 0;
    
    
    do {
        int new_num = 0;
        
        if(i == n-1)
            new_num = arr[i]+1;
        else
            new_num = arr[i]+carry;
        
        carry = 0;
    
        if(new_num > 9)
        {
            arr[i--] = new_num%10;
            carry = new_num/10;
        }
    
    }while(carry != 0 && i >= 0);
    
    if(i < 0)
    {
        arr.insert(arr.begin(), carry);
    }
}

//======================================================================//

void reverse_recursive(NODE_p *head)
{
    if(*head == nullptr)
    {
        return;
    }
    
    NODE_p first = *head;
    NODE_p rest = (*head)->next;
    
    if(rest == nullptr)
    {
        return;
    }
    
    reverse_recursive(&rest);
    
    first->next->next = first;
    first->next = nullptr;

    *head = rest;
}

//======================================================================//

class TinyURL
{
public:
    
    TinyURL();
    string encode(string s);
    string decode(string s);
    
private:
   
    unordered_map<string, string> map;
};

TinyURL::TinyURL(){}

string TinyURL::encode(const string s)
{
    size_t hash_val = std::hash<string>{}(s);
    
    string front = "https://tinyurl.com/";
    
    string tiny_url = front+to_string(hash_val);
    
    map.insert(make_pair(tiny_url, s));
    
    return tiny_url;
}

string TinyURL::decode(const string s)
{
    return map[s];
}

//======================================================================//

vector<int> daily_temperature(vector<int>& temp)
{
    vector<int>days(temp.size(),0);
    
    stack<pair<int,int>>stk;
    
    for(int i = temp.size()-1; i >= 0; i--)
    {
        if(i+1 == temp.size())
        {
            stk.push({temp[i],i});
            days[i] = 0;
        }
        else
        {
            
            while(!stk.empty() && stk.top().first <= temp[i])
            {
                stk.pop();
            }
            
            days[i] = stk.empty() ? 0 : stk.top().second - i ;
            
            stk.push({temp[i], i});
        }
    }
    return days;
}

//======================================================================//

void parenthisis_util(vector<string>&v, string s, int n, int m)
{
    if(m == 0 && n == 0)
    {
        v.push_back(s);
        return;
    }
    else
    {
        if(n > 0)   parenthisis_util(v, s+"(", n-1, m+1);
        if(m > 0)   parenthisis_util(v, s+")", n, m-1);
    }
}

vector<string> generate_parenthesis_combination(int n)
{
    vector<string>V;
    parenthisis_util(V, "", n, 0);
    return V;
}

//======================================================================//

class tree_iterator{
  
public:
    tree_iterator(TREENODE_p node);
    TREENODE_p next();
    bool hasNext();
private:
    stack<TREENODE_p> s;
    void push_all(TREENODE_p node);
    
};
tree_iterator::tree_iterator(TREENODE_p head)
{
    push_all(head);
}

void tree_iterator::push_all(TREENODE_p node)
{
    for( ; node!=NULL; s.push(node), node = node->left);
}

bool tree_iterator::hasNext()
{
    return !s.empty();
}

TREENODE_p tree_iterator::next()
{
    TREENODE_p t = s.top();
    s.pop();
    push_all(t->right);
    return t;
}

//======================================================================//

void string_decoding(string s)
{
    int i = 0;
    int start = 0, end = 0;
    bool has_encoded_string = false;
    int parenthesis = 0;
    char n;
    //cout<<"string:" << s << "\r\n";
    while(i < s.size())
    {
        //printf("size %d\r\n",s.size());
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            cout << s[i++];
            //printf("here0\r\n");
        }
        else if(s[i] == '[' || s[i] == ']' || (s[i] >= '0' && s[i] <= '9'))         // handles only single digit for now
        {
            //printf("here\r\n");
            has_encoded_string = true;
            n = s[i++];      // number to repeat the string
            if(s[i++] == '[')
            {
                parenthesis++;
                start = i;
                //printf("open [ found\r\n");
            }
            
            while(parenthesis != 0)
            {
                if(s[i] == '[')
                    parenthesis++;
                else if(s[i] == ']')
                    parenthesis--;
                i++;
            }
            end = i-2;
        }
        
        if(has_encoded_string)
        {
            int times_repeat = n - '0';
            //printf("repeat%d start%d end%d\r\n", times_repeat, start, end);
            for(int j = 0; j < times_repeat; j++)
            {
                //cout <<"substring:" << s.substr(start,(end-start)+1) << "\r\n";
                string_decoding(s.substr(start,(end-start)+1));
            }
            
            has_encoded_string = false;
        }
    }
}

//======================================================================//

int meeting_rooms2(vector<pair<int, int>> slots)
{
    /* A solution from leetcode*/
    map<int, int> mp; // key: time; val: +1 if start, -1 if end
    
    for(int i=0; i< slots.size(); i++)
    {
        mp[slots[i].first] ++;
        mp[slots[i].second] --;
    }
    for(auto i = 0; i != mp.size(); i++)
    {
        cout << mp[i] << " " << "\r\n";
    }
    
    int cnt = 0, maxCnt = 0;
    
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        cnt += it->second;
        maxCnt = max( cnt, maxCnt);
    }
    
    return maxCnt;
    /*
    multimap<int, int> timeslot;
    vector<pair<int, int>> room;
    
    for(int i = 0; i < slots.size(); i++)
    {
        timeslot.emplace(make_pair(slots[i].first, slots[i].second));
    }
    
    multimap<int,int>::iterator slot;
    int rm = 0;
    for( slot = timeslot.begin(); slot != timeslot.end(); slot++)
    {
        if(room.size())
        {
            for(rm = 0 ; rm < room.size(); rm++)
            {
                if(slot->first >= room[rm].second)
                {
                    room[rm].second = slot->second;
                    break;
                }
            }
            if (rm >= room.size())
            {
                    room.push_back(make_pair(slot->first, slot->second));
            }
        }
        else
        {
            room.push_back(make_pair(slot->first, slot->second));
        }
    }
    for(int i = 0; i < room.size(); i++)
    {
        printf("%d %d\r\n", room[i].first, room[i].second);
    }
    return (int)room.size();
    */
}

//======================================================================//

int numSquares(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    
    // cntPerfectSquares[i] = the least number of perfect square numbers
    // which sum to i. Note that cntPerfectSquares[0] is 0.
    vector<int> cntPerfectSquares(n + 1, INT_MAX);
    cntPerfectSquares[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        // For each i, it must be the sum of some number (i - j*j) and
        // a perfect square number (j*j).
        for (int j = 1; j*j <= i; j++)
        {
            cntPerfectSquares[i] =
            min(cntPerfectSquares[i], cntPerfectSquares[i - j*j] + 1);
            
#if 0       // printing
            printf("min of %d & %d, ", cntPerfectSquares[i], cntPerfectSquares[i - j*j] + 1);
            for(int k = 0; k < cntPerfectSquares.size(); k++)
            {
                printf(" %d",cntPerfectSquares[k]);
            }
            printf("\r\n");
#endif
        }
    }
    
    return cntPerfectSquares.back();
}

//======================================================================//

int longest_path(string path)
{
    int maxlen = 0;
    int sum = 0;
    int depth = 0;
    bool count_depth = false;
    
    stack<pair<string,int>> s;
    
    for(int i = 0; i <= path.size(); i++)
    {
        char c = path[i];
        
        if(c == '\n' || c == '\t' || c == '\0')
        {
            maxlen = max(maxlen,sum);
            if(c == '\n')
            {
                count_depth = true;
            }
            if(count_depth)
            {
                depth++;
            }
        }
        else
        {
            count_depth = false;
            
            sum++;
            
            while (depth <= s.top().second)
            {
                sum -= s.top().first.size();
                s.pop();
            }
            //s.push({/*string*/ ,depth})
            depth = 0;
        }
    }
    
    return maxlen;
}

//======================================================================//
//[0,1,2,4,5,7]
vector<string> summary_ranges(vector<int>v)
{
    vector<string>s;
    int sequence_len = 0;
    int start_index = 0;
    int start_element = v[0];
    sequence_len = 1;
    
    for(int i = 1; i < v.size(); i++)
    {
        if(v[i] == start_element+sequence_len)
        {   // sequence continues
            sequence_len++;
            continue;
        }
        else
        {   // First element of the sequence
            if(sequence_len > 1)
            {
                s.push_back(to_string(start_element) + "->" + to_string(start_element + sequence_len));
            }
            else
            {
                s.push_back(to_string(start_element));
            }
            start_index = i;
            start_element = v[i];
            sequence_len = 1;
        }
    }
    return s;
}

//======================================================================//
// Fine solution in leet code, two loops, outer loop starts from 1 and increments to n-1, inner loop starts from outer-1 and decrements to 0. vector<bool> v, where v[i] is set to true everytime there is a word that ends on outer loop is available in dictionary. Returns true when v[n-1] is true;
bool wordBreak(string s, vector<string>& dictionary)
{
    set<string> dict;
    
    for(int i = 0; i < dictionary.size(); i++)
    {
        dict.insert(dictionary[i]);
    }
    
    int i = 0;
    int j = i;
    
    while(j < s.size())
    {
        cout << i << " " << j << " "<< s.substr(i, (j-i)+1) << "\r\n";
        if(dict.find(s.substr(i, (j-i)+1)) != dict.end())
        {
            cout<< i << " " << j << " " <<s.substr(i, (j-i)+1) << " <---\r\n";
            i = j+1;
        }
        j++;
    }
    if(i == s.size() && j == s.size())
    {
        return true;
    }
    return false;
}

//======================================================================//
//Permutation: Revisit this as much as possible

void swap(vector<int>&vec, int src, int dest)
{
    int temp = vec[src];
    vec[src] = vec[dest];
    vec[dest] = temp;
}

void DFS(vector<int>&num, vector<vector<int>>&permt, int curr)
{
    if(curr == num.size()-1)
    {
        permt.push_back(num);
        return;
    }
    else
    {
        for(int i = curr; i < num.size(); i++)
        {
            swap(num, curr, i);
            DFS(num, permt, curr+1);
            swap(num, curr, i);
        }
    }
}

vector<vector<int>> permutation(vector<int>&num)
{
    vector<vector<int>> permut;
    DFS(num, permut, 0);
    return permut;
}

//======================================================================//

double myPow(double x, int n)
{
    /*
    double ans = 1.0;
    
    for(int i = 0; i < abs(n); i++)
    {
        ans *= x;
    }
    
    if(n < 0)
    {
        ans = 1/ans;
    }
    return ans;
     */
    bitset<32> bit(abs(n));
    double result = 1;
    for(int i = bit.size()-1; i >= 0; i--)
    {
        result*=result;
        if(bit[i] == 1)
            result *=x;
    }
    return (n >= 0)?result : 1/result;
}
//======================================================================//

vector<int> countBits(vector<int>& vec, int num)
{
    vec[0] = 0;
    vec[1] = 1;
    
    int last_square = 1;
    
    for(int i = 2; i < num; i++)
    {
        if(i & (i-1))
        {
            vec[i] = 1 + vec[i-last_square];
        }
        else
        {
            last_square = i;
            vec[i] = 1;
        }
    }
    
    return vec;
}

//======================================================================//
// Good problem
vector<int> inorder_iterative(TREENODE_p head)
{
    if(!head)
    {
        return vector<int>();
    }
    
    stack<TREENODE_p> stack;
    vector<int> inorder;
    
    TREENODE_p curr = head;
    
    while(curr != NULL || !stack.empty())
    {
        while (curr != NULL)
        {
            stack.push(curr);
            curr = curr->left;
        }
        
        curr = stack.top();
        stack.pop();
        inorder.push_back(curr->data);
        curr = curr->right;
    }
    return inorder;
}

//======================================================================//
// https://leetcode.com/problems/product-of-array-except-self/solution/
vector<int> productOfArrayExceptSelf(vector<int> in)
{
    vector<int> out(in.size());
    
    for(int i = 0; i < in.size(); i++)
    {
        if(i == 0)
        {
            out[i] = 1;
        }
        else
        {
            out[i] = in[i-1]*out[i-1];
        }
    }
    
    int prevAns = 1;
    for(int i = (in.size()-1); i >= 0; i--)
    {
        
        if(i == in.size()-1)
        {
            out[i] = prevAns * out[i];
        }
        else
        {
            out[i] = prevAns * out[i] * in[i+1];
            prevAns = in[i+1] * prevAns;
        }
    }
    return out;
}

//======================================================================//

void subarray_util(vector<int>input, vector<int>&sub, vector<vector<int>>&subs, int j)
{
    subs.push_back(sub);
    for(int i = j; i < input.size(); i++)
    {
        sub.push_back(input[i]);
        subarray_util(input, sub, subs, i+1);
        sub.pop_back();
    }
}

vector<vector<int>> subarray(vector<int>input)
{
    vector<vector<int>> subs;
    vector<int> sub;
    subarray_util(input, sub, subs, 0);
    return subs;
}

//======================================================================//

void findDuplicates(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[abs(vec[i])] >= 0)
        {
            vec[abs(vec[i])] = - vec[abs(vec[i])];
        }
        else{
            printf("%d ",abs(vec[i]));
        }
    }
}

//======================================================================//

void combination_sum_util(vector<int>input ,vector<vector<int>>&subs, vector<int>&sub, int j, int sum, int target)
{
    if(sum > target)
    {
        return;
    }
    else if(sum == target)
    {
        subs.push_back(sub);
        return;
    }
    else
    {
        for(int i = j; i < input.size(); i++)
        {
            sub.push_back(input[i]);
            combination_sum_util(input, subs, sub, i, sum+input[i], target);
            sub.pop_back();
        }
    }
}

vector<vector<int>> combination_Sum(vector<int>&vec, int target)
{
    vector<int> sub;
    vector<vector<int>> subs;
    combination_sum_util(vec, subs, sub, 0, 0, target);
    return subs;
}

//======================================================================//
// Pramp question

bool withinDecodeRange(string s)
{
    int decoded_val = stoi(s);
    
    if(decoded_val < 27 && decoded_val > 0)
    {
        return true;
    }
    
    return false;
}

void decodeVariations_util(const string s, int start, int end, int& combinations)
{
    string currnt = s.substr(start,(end-start)+1);
    cout << currnt << endl;
    
    if(withinDecodeRange(currnt))
    {
        combinations++;
    }
    
    // Check if given string represents a letter
    if(end >= s.length() || end <= start+2)
    {
        return;
    }
    else
    {
        decodeVariations_util(s, start, end+1, combinations);
    }
}

int decodeVariations(const string& S)
{
    int combinations = 0;
    string sub;
    string subs;
    
    for(int i = 0; i < S.length(); i++)
    {
        decodeVariations_util(S, i, i, combinations);
    }
    return combinations;
}

//[1234]

//======================================================================//
#if 0
int main()
{
    string s = "1262";
    int ans = decodeVariations(s);
    cout << "Ans " << ans << endl;
    
    /*
    vector<int> vec{1,2,3};
    vector<vector<int>> res = combination_Sum(vec, 5);
    for(int i = 0 ; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "\r\n";
    }
     */
    /*
    vector<int> v{1,2,3,1,4,5,2};
    findDuplicates(v);
     */
    /*
    vector<int>v{1,2,3};
    vector<vector<int>> ans = subarray(v);
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
     */
    /*
    vector<int> inV {1,2,3,4,5};
    
    vector<int> v = productOfArrayExceptSelf(inV);
    
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    */
    /*
    vector<int> v(10);
    countBits(v, 10);
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    */
    //cout << myPow(91.1, 159)<< "\r\n";
    /*
    vector<int>v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    vector<vector<int>> res = permutation(v);
    for(int i = 0 ; i < res.size(); i++)
    {
        for(int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "\r\n";
    }
     
     */
    /*
    vector<string> v(5);
    v[0] = "cats";
    v[1] = "dog";
    v[2] = "send";
    v[3] = "and";
    v[4] = "cat";
    if(wordBreak("catsandog", v))
    {
        cout<<"GOOOD Che" << "\r\n";
    }
    else{
        cout<<"GOOD Nathi" << "\r\n";
    }
     */
    //numSquares(12);
    /*
    vector<pair<int, int>> v(5);
    
    v[0] = {0,30};
    v[1] = {5,10};
    v[2] = {15,20};
    v[3] = {3,8};
    v[4] = {0,15};
    printf("%d\r\n",meeting_rooms2(v));
     */
    /*
    string s = "2[ab3[c]d]3[fg]";
    string_decoding(s);
     */
    /*
    vector<string>s = generate_parenthesis_combination(3);
    for(int i = 0; i < s.size(); i++)
    {
        cout << s[i] << "\r\n";
    }
     */
    /*
    vector<int>temp = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int>days(temp.size(),0);
    
    days = daily_temperature(temp);
    
    for(int i = 0; i < days.size(); i++)
    {
        printf("%d ", days[i]);
    }
     */
    /*
    TinyURL t;
    string tinlyurl = t.encode("www.leetcode.com/url/tiny/rishitborad");
    
    cout << tinlyurl  << "\r\n";
    
    cout << t.decode(tinlyurl) << "\r\n";
    */
    /*
    vector<int> arr;
    
    arr.push_back(9);
    arr.push_back(9);
    arr.push_back(8);
    arr.push_back(9);
    plus_one(arr);
    for(int i = 0; i < arr.size(); i++)
    {
        printf("%d ", arr[i]);
    }
     */
    /*
    string s = "LeetCode";
    reverse_vowels(s);
    cout << s << "\r\n";
    */
    //cout << add_strings("999", "1") << "\r\n";
    /*
    array<int, 8> ar = {4,3,2,7,8,2,3,1};
    list<int>l = disappeared_in_array(ar);
    
    for(auto i = l.begin(); i!= l.end(); i++)
    {
        printf("%d ", *i);
    }
     */
    /*
    vector<vector<int>> v(4, vector<int>(4));
    v[0][0] = 0;
    v[0][1] = 1;
    v[0][2] = 0;
    v[0][3] = 0;
    v[1][0] = 1;
    v[1][1] = 1;
    v[1][2] = 1;
    v[1][3] = 0;
    v[2][0] = 0;
    v[2][1] = 1;
    v[2][2] = 0;
    v[2][3] = 0;
    v[3][0] = 1;
    v[3][1] = 1;
    v[3][2] = 0;
    v[3][3] = 0;

    printf("perimeter = %d\r\n", island_perimeter(v));
    */
    
    /*
    if(robot_moves("UDDULRUDRDLU"))
    {
        printf("displacement 0\r\n");
    }
    else
    {
        printf("displacement more than 0\r\n");
    }
    */
    /*
    vector<string> email_list;
    
    email_list.push_back("sp.arta@dom+ain.com");
    email_list.push_back("sparta@domain.com");
    email_list.push_back("spa+rta@domain.com");
    email_list.push_back("sp.arta+@domain.com");
    
    printf("unique emails %d \r\n", number_of_emails_sent(email_list));
    */
    /*
    vector<vector<int>> img(3, vector<int>(3));
    img[0][0] = 1;
    img[0][1] = 1;
    img[0][2] = 0;
    
    img[1][0] = 1;
    img[1][1] = 0;
    img[1][2] = 1;
    
    img[2][0] = 0;
    img[2][1] = 0;
    img[2][2] = 0;
    
    flip_andinvert_image(img);
    */

    //STL_Experiments();
    //unique_char("SPARTA");
    /*
    Anagrams* a = new Anagrams();
    vector<vector<string>> ans;
    vector<string> strs;
    strs.push_back("cat");
    strs.push_back("ear");
    strs.push_back("are");
    strs.push_back("bat");
    strs.push_back("vode");
    strs.push_back("tab");
    strs.push_back("era");
    
    for(auto i = strs.begin(); i != strs.end(); i++)
    {
        //cout << *i << '\n';
    }
    ans = a->groupAnagrams(strs);
    
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << '\n';
        }
    }
    */
    /*
    char arr[] = {'f','o','r','g','e','e','k','s','s','k','e','e'};
    longestPalindrome(arr,12);
    */
    //int arr[7] = {0,0,1,0,1,0,0};
    //max_len_subarray(arr, 7);
    //int arr[7] = {1,9,3,10,4,20,2};
    //printf("longest %d\r\n", longest_sequential_subarray(arr, 7));
    
    /*
    printf("LRU Cache\r\n");
    LRU_cache cache(3);
    cache.refer(3);
    cache.refer(1);
    cache.refer(2);
    cache.refer(1);
    cache.refer(2);
    cache.refer(1);
    cache.refer(2);
    cache.display();
     */
    
    //char c[10] = "sparta";
    //char d[10] = "s";
    //check_anagram(c, d);
    
    //int three_sum_arr[6] = {-1, 0, 1, 2, -1, -4};
    //three_sum(three_sum_arr, 6);
    
    /*
    printf("\r\n");
    
    int num[] = {2,3};
    char arr_comb[5];
    combination_of_phone_numbers(num, 0, arr_comb, 2);
    */
    /*
    char permutation_of_string_arr[] = "ABC";
    permutation_of_string(permutation_of_string_arr, 0, 2);
    */
    return 0;
}
#endif

/*
 
 Google question
Black White picture: 1 pixel per bit.

Input:
10101111 00011100 00000000
01010101 10101010 11111111
00000001 11111111 00000000

Memory:
10101111 00011100 00000000 01010101 10101010 11111111 00000001 11111111 00000000

Output:
00000000 00111000 11110101
11111111 01010101 10101010
00000000 11111111 10000000

 */


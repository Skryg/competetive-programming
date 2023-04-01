#include <bits/stdc++.h>
#define satori int z; cin>>z; while(z--)

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    satori{
        int n; cin>>n;
        string s1,s2;
        vector<unsigned int> guesty1(n+1),guesty2(n+1);
        unordered_map<unsigned int, int> umap;
        cin>>s1;
        for(int i=1;i<=n;++i){
            cin>>guesty1[i];
            umap[guesty1[i]]=i;
        }
        cin>>s2;
        for(int i=1;i<=n;++i){
            cin>>guesty2[i];
        }
        vector<int> normal1(n+1),normal2(n+1);
        for(int i=1;i<=n;++i){
            normal1[i] = i;
            normal2[i] = umap[guesty2[i]];
        }
        vector<int> leftChild(n+1), rightChild(n+1);
        vector<int> ans(n+1);
        stack<pair<int,int>> interval;
        stack<int> parent;
        if(s1 == "INORDER" || s2 == "INORDER"){
            vector<int> *inorder, *another;
            if(s1 == "INORDER"){
                inorder = &normal1;
                another = &normal2;
            }
            else{
                inorder = &normal2;
                another = &normal1;
            }

            vector<int> inorderIndexes(n+1);
            for(int i=1;i<=n;++i){
                inorderIndexes[((*inorder)[i])]=i;
            }
            interval.push({1,n});
            if(s1 == "PREORDER" || s2 == "PREORDER"){
                parent.push((*another)[1]);
                for(int i=2;i<=n;++i){
                    int newGuy = (*another)[i];
                    // cout<<newGuy<<"x inorder:"<<inorderIndexes[newGuy]<<'\n';
                    while(inorderIndexes[newGuy] < interval.top().first || inorderIndexes[newGuy] > interval.top().second){
                        interval.pop();
                        parent.pop();
                    }

                    if(inorderIndexes[newGuy] < inorderIndexes[parent.top()]){
                        interval.push({interval.top().first, inorderIndexes[parent.top()]-1});
                        leftChild[parent.top()] = newGuy;
                    }
                    else{
                        interval.push({inorderIndexes[parent.top()]+1,interval.top().second});
                        rightChild[parent.top()] = newGuy;
                    }
                    // cout<<interval.top().first<<" "<<interval.top().second<<" par "<<parent.top()<<'\n';
                    parent.push(newGuy);
                }
            }
            else{
                parent.push((*another)[n]);
                for(int i=n-1;i;--i){
                    int newGuy = (*another)[i];
                    // cout<<newGuy<<"x inorder:"<<inorderIndexes[newGuy]<<'\n';
                    while(inorderIndexes[newGuy] < interval.top().first || inorderIndexes[newGuy] > interval.top().second){
                        interval.pop();
                        parent.pop();
                    }

                    if(inorderIndexes[newGuy] < inorderIndexes[parent.top()]){
                        interval.push({interval.top().first, inorderIndexes[parent.top()]-1});
                        leftChild[parent.top()] = newGuy;
                    }
                    else{
                        interval.push({inorderIndexes[parent.top()]+1,interval.top().second});
                        rightChild[parent.top()] = newGuy;
                    }
                    // cout<<interval.top().first<<" "<<interval.top().second<<" par "<<parent.top()<<'\n';
                    parent.push(newGuy);
                }
            }

            for(int i=1;i<=n;++i){
                ans[leftChild[i]]=i;
                ans[rightChild[i]]=i;
            }

        }
        else{
            vector<int> *preorder, *postorder;
            if(s1 == "PREORDER"){
                preorder = &normal1;
                postorder = &normal2;
            }
            else{
                preorder = &normal2;
                postorder = &normal1;
            }

            stack<int> parent;

            int postIndex = 1;
            for(int i=1;i<=n;++i){
                parent.push((*preorder)[i]);
                
                while(!parent.empty() && (*postorder)[postIndex] == parent.top()){
                    int top = parent.top();
                    parent.pop();
                    int par = (!parent.empty() ? parent.top() : 0);
                    ans[top]=par;
                    ++postIndex;
                }
            }
        }
        // cout<<"Lefts:\n";
        // for(int i=1;i<=n;++i){
        //     cout<<leftChild[i]<< '\n';
        // }
        // cout<<"Rights:\n";
        // for(int i=1;i<=n;++i){
        //     cout<<rightChild[i]<< '\n';
        // }


        for(int i=1;i<=n;++i){
            cout<<guesty1[ans[normal1[i]]]<< ' ';
        }
        cout<<'\n';
        for(int i=1;i<=n;++i){
            cout<<guesty1[ans[normal2[i]]]<< ' ';
        }
        cout<<'\n';
    }

    return 0;
}
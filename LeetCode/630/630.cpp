/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(),courses.end(),[&](vector<int> a, vector<int> b){
            return (a[1] < b[1]);
        });

        priority_queue<int> pq;

        int cur = 0;
        for (int i=0; i<n; i++){
            int delta = courses[i][0];
            int t = courses[i][1];

            // cout << delta << " " << t << endl;

            cur+=delta;
            pq.push(delta);
            if (cur > t) {
                cur-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
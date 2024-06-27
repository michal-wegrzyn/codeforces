#include <bits/stdc++.h>
using namespace std;

map<string,bool> does_card_exist;
vector<string> cards;
int count_of_sets[1007];

char thirdFeature(char a, char b){
    if(a==b) return a;
    if(a>b) swap(a, b);
    if(a=='0' && b=='1') return '2';
    if(a=='0' && b=='2') return '1';
    return '0';
}

string thirdCard(string a, string b){
    string res = "";
    for(int i=0; i<a.size(); i++) res.push_back(thirdFeature(a[i], b[i]));
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    char a;
    string curr_card;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        curr_card = "";
        for(int i=0; i<k; i++){
            cin >> a;
            curr_card.push_back(a);
        }
        cards.push_back(curr_card);
        does_card_exist[curr_card] = true;
    }

    long long result = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            if(does_card_exist[thirdCard(cards[i], cards[j])]) count_of_sets[i] ++;
        }
        count_of_sets[i] /= 2;
        result += (count_of_sets[i]-1)*count_of_sets[i]/2;
    }
    cout << result << '\n';
    return 0;
}
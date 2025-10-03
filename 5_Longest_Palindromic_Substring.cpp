#include <iostream>
#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
	string longestPalindrome(string s) {
		string s_prime = "#";
		for(auto &chr : s){
			s_prime.append(1, chr);
			s_prime.append(1, '#');
		}

		vector<int> radii(s_prime.size(), 0);
		int center = 0, right_border = 0, max_radius = 0, largest_palindrome_center = 0, mirror;
		
		// Current letter exists in palindrome
		for(int i = 0; i < s_prime.size(); i++){
			mirror = 2 * center - i;
			
			if(i < right_border){
				// Mirror does not extend beyond the border of palindrome
				if(radii[mirror] < (right_border - i)){
					radii[i] = radii[mirror];
				}
				else{
					radii[i] = right_border - i; // at least
				}
			}

			while((i - 1 - radii[i] >= 0) && 
				(i + 1 + radii[i] < s_prime.size()) && 
				(s_prime[i-1-radii[i]] == s_prime[i+1+radii[i]])) {
			
				radii[i]++;
			}

			// Extends beyond the palindrome centered at "center"
			if(i + radii[i] > right_border){
				center = i;
				right_border = i + radii[i];
			}

			if(radii[i] > max_radius){
				max_radius = radii[i];
				largest_palindrome_center = i;
			}
		}

		int start_index = (largest_palindrome_center - max_radius)/2;
		
		return s.substr(start_index, max_radius); 
	}
};

int main()
{
	string s;
	Solution sol;

	cin >> s;
	cout << sol.longestPalindrome(s) << endl;

	return 0;
}
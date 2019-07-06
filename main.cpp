#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <vector>
#include <unordered_map>


using namespace std;

//Reverse String
void ReverseString(string &s){
	int n = s.size();
	int l = 0, r= n-1;
	while(l<r){
		swap(s[l],s[r]);
		l++;
		r--;
	}

}
//Contains Duplicate 2
bool ContainsDuplicate2(std::vector<int> &s, int k){
	int n = s.size();
	unordered_set<int> set_temp;
	for (int i = 0; i < n; ++i)
	{
		int temp = s[i];
		if(set_temp.find(temp)!=set_temp.end())
			return true;
		set_temp.insert(temp);
		if(set_temp.size()>k)
			set_temp.erase(s[i-k]);
	}
	return false;
}
//Number of Boomeranges
int distance(pair<int,int>&s1,pair<int,int>&s2){
	int a = s1.first, a1 = s2.first;
	int b = s1.second, b1 = s2.second;
	return ((a*a1)+(b*b1));
}
int NumberofBoomerabges(std::vector<pair<int,int>> &s){
	int n = s.size();
	int sum =0;
	for(int i=0;i<n;++i){
		pair<int,int> temp1 = s[i];
		unordered_map<int,int> map_temp;
		for(int j=0;j<n;++j){
			if(i==j)
				continue;
			pair<int,int>temp2 = s[j];
			int temp3 = distance(temp1,temp2);
			map_temp[temp3]+=1;
		}
		for(unordered_map<int,int>::iterator iter = map_temp.begin();iter!=map_temp.end();++iter){
			int temp4 = iter->second; 
			sum+= temp4*(temp4-1);
		}
	}

	return sum;
}
//Sum4
int Sum4(std::vector<int>& A,std::vector<int>& B,std::vector<int>& C,std::vector<int>& D){

	int sum =0;
	unordered_map<int,int> map_temp;
	for(int i = 0; i<A.size(); ++i){
		int temp1 = A[i];
		for(int j=0; j<B.size();++j){
			int temp2 = B[j];
			map_temp[temp1+temp2]+=1;
		}
	}
	for(int i = 0; i<C.size(); ++i){
		int temp3 = C[i];
		for(int j = 0; j<D.size(); ++j){
			int temp4 = D[j];
			if(map_temp.find(-temp3-temp4)!=map_temp.end())
				sum+=map_temp[-temp3-temp4];
		}
	}
	return sum;
}
//Two Sum
std::vector<int> TwoSum(std::vector<int> &s, int target){
	unordered_map<int,int> map_temp;
	for(int i = 0; i<s.size(); ++i){
		int temp = target-s[i];
		if(map_temp.find(temp)!=map_temp.end()){
			int first = map_temp[temp];
			int a[2] = {first,i};
			return std::vector<int> (a,a+2);
		}
		map_temp[s[i]] = i;
	}
		
}
//intersection of two array2
std::vector<int> IntersectionofTwoArray2(std::vector<int> &s1,std::vector<int> &s2){
	unordered_map<int,int>map_temp;
	for(int i=0; i<s1.size();++i){
		map_temp[s1[i]]+=1;
	}
	std::vector<int> result;
	for(int i=0;i<s2.size();++i){
		int temp = s2[i];
		if(map_temp.find(temp)!=map_temp.end() && map_temp[temp]>0){
			result.push_back(temp);
			map_temp[temp]-=1;
		}
	}

	return result;
}
//intersectin of two array
std::vector<int> IntersectionofTwoArray(std::vector<int> &s1, std::vector<int> s2){
	unordered_set<int> set_temp;
	for (int i = 0; i < s1.size(); ++i)
	{
		set_temp.insert(s1[i]);
	}
	unordered_set<int> temp;
	for (int i = 0; i < s2.size(); ++i)
	{
		if(set_temp.find(s2[i])!=set_temp.end()){
			temp.insert(s2[i]);
		}
	}
	std::vector<int> result;
	for(unordered_set<int>:: iterator iter = temp.begin();iter!=temp.end();++iter){
		result.push_back(*iter);
	}
	return result;
}
//Minimum Size Subarray sum
int MinimumSize(std::vector<int> &s, int target){
	int num = s.size()+1;
	int l = 0, r = -1;
	int sum = 0;
	while(l<s.size()){
		if(r+1<s.size() && sum < target)
			sum+=s[++r];
		else{
			sum-=s[l];
			l++;
		}
		if(sum>=target)
			num = min(num, r-l+1);
	}
	if(num==s.size()+1)
		return 0;
	return num;
}
//Longest Substring Without Repeating Characters
int LongestSubstring(string &s){
	int a[256]={0};
	int r=-1,l=0;
	int num =0;
	while(l<s.size()){
		if(r+1<s.size() && a[s[r+1]]==0)
			a[s[++r]] +=1;
		else{
			a[s[l++]]-=1;
		}
		num = max(num, r-l+1);
	}
	return num;
}
//Two Sum2
std::vector<int> TwoSum2(std::vector<int> &s, int target){
	int l = 0, r = s.size()-1;
	while(l<r){
		int sum = s[l]+s[r];
		if(sum==target)
			return std::vector<int> {l+1,r+1};
		else if(sum >target)
			r--;
		else
			l++;
	}
	return std::vector<int> {0,0};
}

//Sort Colors
void SortColors(std::vector<int> &s){
	int zero = -1, one = 0, two = s.size();
	while(one<two){
		if(s[one]==1)
			one++;
		else if(s[one]==2){
			two--;
			swap(s[one],s[two]);
		}else{
			zero++;
			swap(s[zero],s[one]);
			one++;
		}
	}
}

//Move Zeros
void MoveZeros(std::vector<int> &s){
	int k = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i]!=0)
			s[k++] = s[i];
	}
	for (int i = k; i < s.size(); ++i)
	{
		s[i]=0;
	}
	
}
int main(int argc, char const *argv[]){
	std::vector<int> s = {0,1,0,3,12};
	// string s1 = "bbb";
	MoveZeros(s);
	// cout<<"num:"<<num<<endl;

	for (int i = 0; i < s.size(); ++i){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
} 
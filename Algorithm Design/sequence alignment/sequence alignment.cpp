#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void minPenalty(string x, string y, int pgap, int pxy)
{
	int i, j, m = x.length(), n = y.length();
	int arr[m+1][n+1] = {0};

	for(i=0; i<=(n+m); i++){
		arr[i][0] = i * pgap;
		arr[0][i] = i * pgap;
	}

	for (i=1; i<=m; i++){
		for (j=1; j<=n; j++){
			if (x[i-1] == y[j-1]){
				arr[i][j] = arr[i - 1][j - 1];
			}
			else{
    arr[i][j] = min(arr[i - 1][j - 1] + pxy , arr[i - 1][j] + pgap ,arr[i][j - 1] + pgap);
			}
		}
	}


	int k = n+m; /// max string length
        i = m;
        j = n;

	int xpos = k;
	int ypos = k;

	int xans[k+1], yans[k+1];

	while (!(i == 0 || j == 0)){
		if (x[i - 1] == y[j - 1]){
			xans[xpos--] = (int)x[i - 1];
			yans[ypos--] = (int)y[j - 1];
			i--; j--;
		}
		else if (arr[i - 1][j - 1] + pxy == arr[i][j]){
			xans[xpos--] = (int)x[i - 1];
			yans[ypos--] = (int)y[j - 1];
			i--; j--;
		}
		else if (arr[i - 1][j] + pgap == arr[i][j]){
			xans[xpos--] = (int)x[i - 1];
			yans[ypos--] = (int)'_';
			i--;
		}
		else if (arr[i][j - 1] + pgap == arr[i][j]){
			xans[xpos--] = (int)'_';
			yans[ypos--] = (int)y[j - 1];
			j--;
		}
	}
	while (xpos > 0){
		if (i > 0) xans[xpos--] = (int)x[--i];
		else xans[xpos--] = (int)'_';
	}

	while (ypos > 0){
		if (j > 0) yans[ypos--] = (int)y[--j];
		else yans[ypos--] = (int)'_';
	}

	int id = 1;
	for (i = k; i >= 1; i--){
		if ((char)yans[i] == '_' && (char)xans[i] == '_'){
			id = i + 1;
			break;
		}
	}


	cout << arr[m][n] << endl;  ///min penalty
	cout << " alignments are: "<<endl;
	for (i = id; i <= k; i++){
		cout<<(char)xans[i];
	}
	cout <<endl;
	for (i = id; i <= k; i++){
    cout << (char)yans[i];
	}
	return;
}

int main(){
	string test1 = "CG";
	string test2 = " CA";

    int gap = 3; /// a penalty if a gap is inserted between the string.
	int misMatch= 7; /// a penalty that occurs for mis-matching the characters of X and Y


	/// display the answer:
	minPenalty(test1, test2, gap, misMatch);

}



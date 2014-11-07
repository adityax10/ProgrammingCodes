#include <bits/stdc++.h>

using namespace std;

int findMinimumStringMovement() {
	
    
    char str3;
    int moves = 0;
    
    if (str1 != str2) {
        for (int i = 0; i < str1.length(); i++) {
            for (int j = i + 1; j < str1.length(); j++) {
                if (str1[i] != str2[i]) {
                    
                    if (str1[j] == str2[i] && j < str1.length()) {
                        for (int k = j; k > i; k--) {
                            str3 = str1[k];
                            str1[k] = str1[k - 1];
                            str1[k - 1] = str3;
                            moves++;
                        }
                    
                    } else if (str1[str1.length() - 1] == str2[i]) {
                        if (i == 0) {
                            str3 = str1[str1.length() - 1];
                            str1[str1.length() - 1] = str1[i];
                            str1[i] = str3;
                            moves++;
                        } else if (i < (str1.length() - 1) / 2) {
                            for (int k = i; k > 0; k--) {
                                str3 = str1[k];
                                str1[k] = str1[k - 1];
                                str1[k - 1] = str3;
                                moves++;
                            }
                            str3 = str1[i];
                            str1[i] = str1[str1.length() - 1];
                            str1[str1.length() - 1] = str3;
                        }
                    } else if (str2[str2.length() - 1] == str1[i]) {
                        if (i == 0) {
                            str3 = str2[str2.length() - 1];
                            str2[str2.length() - 1] = str2[i];
                            str2[i] = str3;
                            moves++;
                        } else if (i < (str1.length() - 1) / 2) {
                            for (int k = i; k > 0; k--) {
                                str3 = str1[k];
                                str1[k] = str1[k - 1];
                                str1[k - 1] = str3;
                                moves++;
                            }
                            str3 = str1[i];
                            str1[i] = str1[str1.length() - 1];
                            str1[str1.length() - 1] = str3;
                            moves++;
                        }
                    } else {
                        if (str1[j] != str1[i] && j < str1.length()) {
                            if (str1[j] == str2[j]) {
                                str3 = str2[j];
                                str2[j] = str2[i];
                                str2[i] = str3;
                                moves++;
                            }
                            str3 = str1[j];
                            str1[j] = str1[i];
                            str1[i] = str3;
                            moves++;
                        } else if (str2[j] != str2[i] && j < str1.length()) {
                            if (str1[j] == str2[j]
                                    && str1[j] != str1[i]) {
                                str3 = str1[j];
                                str1[j] = str1[i];
                                str1[i] = str3;
                                moves++;
                            }
                            str3 = str2[j];
                            str2[j] = str2[i];
                            str2[i] = str3;
                            moves++;
                        }
                    }
                    if (str1 == str2) {
                        break;
                    }
                }
            }
        }
    }
    return moves;
}

int main(int argc, char** argv) {
	cout<<findMinimumStringMovement();
	return 0;
}


#include <iostream>

void lpsCalculate(int *lps, int m , std::string pat){
  lps[0] = 0;
  int len = 0;
  int i = 1;
  while(i<m){
    if(pat[i]==pat[len]){
      lps[i] = len + 1;
      len++;
      i++;
    }
    else{
      if(len!=0){
        len = lps[len-1];
      }
      else{
        lps[i] = 0;
        i++;
      }
    }
  }
}

void kmp(std::string txt, std::string pat){
  int n = txt.length();
  int m = pat.length();
  int lps[m];
  lpsCalculate(lps, m, pat);
  int i=0;
  int j=0;
  while(i<n){
    if(txt[i]==pat[j]){
      i++;
      j++;
    }
    else{
      if(j==0){
        i++;
      }
      else{
        j = lps[j-1];
      }
    }
    if(j==m){
      std::cout<<i-j<<" ";
      j = lps[j-1];
    }
  }
}


int main() {
  std::string txt = "ababcababaad";
  std::string pat = "ababa";
  kmp(txt, pat);
  return 0;
}

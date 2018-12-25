void compute(string pat, int lps[]){
	int len=0,m=pat.length();
	lps[0]=0;
	int i=1;
	while(i<m){
		if(pat[i]==pat[len]){
			len++;
			lps[i]=len;
			i++;
		}else{
			if(len!=0){
				len=lps[len-1];
			}else{
				lps[i]=0;
				i++;
			}
		}
	}
}

void kmp(string text, string pat, int lps[]){
	compute(pat,lps);
	int i=0,j=0;
	while(i<text.length()){
		if(pat[j]==text[i]){
			i++;
			j++;
		}
		if(j==pat.length()){
			cout<<"Found at "<<i-j<<"\n";
			j=lps[j-1];
		}else if(pat[j]!=text[i] && i<text.length()){
			if(j!=0){
				j=lps[j-1];
			}else{
				i++;
			}
		}
	}
}

int main(){
	int lps[100];
	string pat,text;
	cin>>text>>pat;
	kmp(text,pat,lps);
	for(int i=0;i<pat.length();i++){
		cout<<lps[i];
	}
}
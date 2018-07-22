

//without recursion
void atoi(string s){

  int num=0;
  for(int i=0;i<s.length();i++){
    num=num*10+ (s[i]-48);
  }
  cout << num;

}
//with recursion
int atoi(string s,int end){

  if(end==1)
    return  s[end-1]-48;
  return (s[end-1]-48) + 10*atoi(s,end-1);
}

int main()
{
    string s;
    cout << "enter any valid string number :";
    cin >> s;
    cout << atoi(s,s.length());
    return 0;
}


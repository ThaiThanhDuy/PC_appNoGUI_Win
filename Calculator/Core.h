char stringInput[20] = " ";
char n[100];
char o;
int j =1;
int temp =0;
int result=0.0;
void stringProcessing(char string[]){
    
    result =0;
    for (int i = 1; i <= strlen(string); i++)
    {
        if(isdigit(string[i])!=0){
            n[j] = string[i];
           temp=strtod(n,NULL);
        }

        else{
            continue;
        }
        result += temp;
        j++;
    }
    
    printf("%d",result);
    
    
    
    
}
void Start(){
    printf("Enter your string:");
    scanf("%s",stringInput);
    fflush(stdin);
    //printf("Result:%.5f",stringProcessing(stringInput));
    stringProcessing(stringInput);
}
void History(){
    
}
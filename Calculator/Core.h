char stringInput[100] = " ";
void stringProcessing(char string[]){
    char n[100];
    char o[100];
    int j =0;
    int Point =0;
    while (Point==1)
    {   
        for (int i = 0; i < strlen(string); i++){
            if(ispunct(string[i]==0))
                strncpy(n,string,1);
                printf("%c",n[i]);                 
        }      
      
        
        Point =1;
    }
    
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
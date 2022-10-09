%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
#include <assert.h>

extern int yylex();
extern void yyerror(char *);

typedef struct Macro
{
    int argCount, type;
    char *id, *sub;
    char** args;
} Macro;

Macro macroList[1000];
int macroCount = 0;

void callError()
{
    printf("//Failed to parse input code\n");
    exit(0);    //succesful exit
}

char** getArgs(int* ptr, char* args)
{
    *ptr = 0;
    if(!args) return NULL;

    else
    {
        int len = strlen(args), count=0, k=0, j=0;
        for(int i=0; i<len; i++)
        {
            if(args[i] == ',') count++;
        }

        char** argList = (char**)malloc((count+3)*sizeof(char*));
        for(int i=0; i<=count; i++)
            argList[i] = (char*)malloc((len+5)*sizeof(char));
        
        for(int i=0; i<l; i++)
        {
            if(args[i]!=',' && args[i]!='\0')
            {
                argList[j][k] = args[i];
                k++;
            }

            else
            {
                argList[j][k] = '\0';
                k=0; j++;
            }
        }

        *ptr = count+1;
        return argList;
    }
}

int containsMacro(char* ID)
{
    for(int i=0; i<macroCount; i++)
    {
        if(strcmp(macroList[i].id, ID) == 0)
            return 1;
    }
    return 0;
}

int getIndex(char* idName)
{
    for(int i=0; i<macroCount; i++)
    {
        if(strcmp(macroList[i].id, ID) == 0)
            return i;
    }

    return -1;
}

void insertMacro(char* ID, char* argList, char* Sub, int typeFlag)
{
    if(containsMacro(ID)) callError();

    else
    {
        int index = macroCount, argCountRef;
        macroCount++;

        macroList[index].id = ID;
        macroList[index].sub = Sub;
        macroList[index].type = typeFlag;
        macroList[index].args = getArgs(&argCountRef, argList);
        macroList[index].argCount = argCountRef;
    }
}

int check(char a)
{
    if(a>='a' && a<='z' || a>='A' && a<='Z' ||a>='0' &&a<='9' || a=='_')
        return 1;
    return 0;
}

char* substitute(char* id, char* args, int type)
{
    char* tempArgs = NULL;
    char** argList = NULL;
    int index = getIndex(id), num = 0, pos = 0, k = 0, len;
    if(index == -1 || !args) callError();

    argList = getArgs(&num, args);
    if(macroList[index].argCount != num) callError();
    len = num;
    num = strlen(macroList[index].sub);
    char* tempL = (char*)malloc((num+5)*sizeof(char)); tempL[0] = '\0';
    tempArgs = (char*)malloc(10000*sizeof(char)); tempArgs[0] = '\0';

    for(int i=0; i<num; i++)
    {
        char temp = macroList[index].sub[i]
        if(!check(temp))
        {
            tempL[k] = '\0';
            for(int j=0; j<len; j++)
            {
                if(strcmp(tempL, macroList[index].sub)==0)
                {
                    k = 0;
                    pos = pos + strlen(argList[j]);
                    strcat(tempArgs, argList[j]);
                    tempL[0] = '\0';
                    break;
                }

                tempL[k] = '\0'; k = 0;
                pos = pos + strlen(tempL);
                strcat(tempArgs, tempL);     
                tempArgs[pos++] = macroList[index].sub[i];
                final[pos] = '\0';
            }
        }

        else tempL[k++] = macroList[index].sub[i];
    }

    return tempArgs;
}
%}

%union {
    char * strval;
}
%token SEMICOLON CLASS IF ELSE  ERROR WHILE LPARAN RPARAN LCPARAN RCPARAN LSPARAN RSPARAN LESSTHAN GREATERTHAN EQUALS PLUS MINUS STAR DIV 
        END PUBLIC STATIC VOID MAIN NEW FALSE TRUE THIS WORDINT AND OR NOT DOT LENGTH SYSTEM STRING COMMA EXT BOOLE RET DEFINE OTHER
%token <strval> INT
%token <strval> IDENTIFIER
%start goal
%type <strval> PrimaryExpression
%type <strval> Identifier
%type <strval> Expression
%type <strval> MacroExpression
%type <strval> CommaExpressionStar
%type <strval> MethodDeclarationStar
%type <strval> CommaTypeIdentifierStar
%type <strval> StatementStar
%type <strval> CommaIdentifierStar;
%type <strval> prog
%type <strval> TypeDeclarationStar
%type <strval> TypeIdentifierStar
%type <strval> TypeIdentifierSemicolon
%type <strval> MainClass
%type <strval> TypeDeclaration
%type <strval> MethodDeclaration
%type <strval> Type
%type <strval> Statement
%type <strval> MacroStatement



%%
goal:    prog                                                      {printf("%s",$1);exit(0);};
prog:	 MacroDefinitionStar MainClass TypeDeclarationStar             {$$=(char*)malloc((strlen($2)+strlen($3)+10)*sizeof(char));
                                                                        strcpy($$,$2);strcat($$,$3);
                                                                        free($2);free($3);} ;

MacroDefinitionStar: MacroDefinitionStar MacroDefinition                  

                        |                                              ;
                     
TypeDeclarationStar:  TypeDeclaration TypeDeclarationStar               {$$=(char*)malloc((strlen($1)+strlen($2)+5)*sizeof(char));
                                                                        strcpy($$,$1);strcat($$,$2);free($1);free($2);}   

                        |                                               {$$=(char*)malloc(2*sizeof(char));strcpy($$,"");} ;
                        
TypeIdentifierStar: TypeIdentifierStar TypeIdentifierSemicolon          {$$=(char*)malloc((strlen($1)+strlen($2)+5)*sizeof(char));
                                                                        strcpy($$,$1);strcat($$,$2);free($1);free($2);}   

                        |                                               {$$=(char*)malloc(2*sizeof(char));strcpy($$,"");} ;
                        
TypeIdentifierSemicolon: Type Identifier SEMICOLON                      {$$=(char*)malloc((strlen($1)+strlen($2)+4)*sizeof(char));
                                                                         strcpy($$,$1);strcat($$,$2);strcat($$,";");
                                                                         free($1);free($2);};

MethodDeclarationStar: MethodDeclaration MethodDeclarationStar         {$$=(char*)malloc((strlen($1)+strlen($2)+5)*sizeof(char));
                                                                        strcpy($$,$1);strcat($$,$2);free($1);free($2);}   

                        |                                               {$$=(char*)malloc(2*sizeof(char));strcpy($$,"");} ;
                        
CommaTypeIdentifierStar: CommaTypeIdentifierStar COMMA Type Identifier {$$=(char*)malloc((strlen($1)+strlen($3)+strlen($4)+10)*sizeof(char));
                                                                        strcpy($$,$1);strcat($$,",");strcat($$,$3);strcat($$," ");strcat($$,$4);free($4);free($1);free($3);}
                                                                                            
                        |                                               {$$=(char*)malloc(2*sizeof(char));strcpy($$,"");} ;

StatementStar: Statement StatementStar                  {$$=(char*)malloc((strlen($1)+strlen($2)+3)*sizeof(char));
                                                        strcpy($$,$1);strcat($$,$2);free($1);free($2);}
                                                                  
               |                                        {$$=(char*)malloc(2*sizeof(char));strcpy($$,"");};
               
CommaExpressionStar: CommaExpressionStar COMMA Expression {$$=(char*)malloc((strlen($1)+strlen($3)+3)*sizeof(char));
                                                           strcpy($$,$1);strcat($$,",");strcat($$,$3);free($1);free($3);}
                                                                               
                     |                                    {$$=(char*)malloc(2*sizeof(char));strcpy($$,"");} ;
                     
CommaIdentifierStar: CommaIdentifierStar COMMA Identifier {$$=(char*)malloc((strlen($1)+strlen($3)+3)*sizeof(char));
                                                           strcpy($$,$1);strcat($$,",");strcat($$,$3);free($1);free($3);} 
   
                    |                                      {$$=(char*)malloc(2*sizeof(char));strcpy($$,"");}; 
                    
                   
MainClass	:   CLASS Identifier LCPARAN PUBLIC STATIC VOID MAIN LPARAN STRING LSPARAN RSPARAN Identifier RPARAN LCPARAN SYSTEM LPARAN Expression RPARAN SEMICOLON RCPARAN RCPARAN 
                            {$$=(char*)malloc((strlen($2)+strlen($12)+strlen($17)+100)*sizeof(char));
                            strcpy($$,"class ");strcat($$,$2);strcat($$,"{public static void main (String[] ");strcat($$,$12);strcat($$,"){System.out.println(");strcat($$,$17);strcat($$,");}}");
                            free($2);free($12);free($17);} ;
                    

TypeDeclaration	:	CLASS Identifier LCPARAN TypeIdentifierStar MethodDeclarationStar RCPARAN 
                            {$$=(char*)malloc((strlen($2)+strlen($4)+strlen($5)+50)*sizeof(char));
                            strcpy($$,"class ");strcat($$,$2);strcat($$,"{");strcat($$,$4);strcat($$,$5);
                            strcat($$,"}");free($2);free($4);free($5);};
                    |	CLASS Identifier EXT Identifier LCPARAN TypeIdentifierStar MethodDeclarationStar RCPARAN 
                            {$$=(char*)malloc((strlen($2)+strlen($4)+strlen($6)+strlen($7)+50)*sizeof(char));
                            strcpy($$,"class ");strcat($$,$2);strcat($$," extends ");strcat($$,$4);strcat($$,"{");strcat($$,$6);strcat($$,$7);
                            strcat($$,"}");free($2);free($4);free($6);free($7);};
                            

MethodDeclaration: 	PUBLIC Type Identifier LPARAN RPARAN LCPARAN TypeIdentifierStar StatementStar RET Expression SEMICOLON RCPARAN  
                            {$$=(char*)malloc((strlen($2)+strlen($3)+strlen($7)+strlen($8)+strlen($10)+50)*sizeof(char));
                            strcpy($$,"public ");strcat($$,$2);strcat($$,$3);strcat($$,"(){");strcat($$,$7);strcat($$,$8);
                            strcat($$,"return ");strcat($$,$10);strcat($$,";}");free($2);free($3);free($7);free($8);free($10);}
                            
                    | PUBLIC Type Identifier LPARAN  Type Identifier CommaTypeIdentifierStar RPARAN LCPARAN TypeIdentifierStar StatementStar RET Expression SEMICOLON RCPARAN  
                            {$$=(char*)malloc((strlen($2)+strlen($3)+strlen($5)+strlen($6)+strlen($7)+strlen($10)+strlen($11)+strlen($13)+50)*sizeof(char));
                            strcpy($$,"public ");strcat($$,$2);strcat($$,$3);strcat($$,"(");strcat($$,$5);strcat($$,$6);strcat($$,$7);strcat($$,"){");
                            strcat($$,$10);strcat($$,$11);strcat($$,"return ");strcat($$,$13);strcat($$,";}");free($2);free($3);free($5);free($6);free($7);free($10);free($11);free($13);} ;
                    
Type	:	WORDINT LSPARAN RSPARAN {$$=(char*)malloc(10*sizeof(char));strcpy($$,"int[] ");}

            |	BOOLE           {$$=(char*)malloc(10*sizeof(char));strcpy($$,"boolean ");}
            
            |	WORDINT         {$$=(char*)malloc(10*sizeof(char));strcpy($$,"int ");}
            
            |	Identifier       {$$=(char*)malloc((strlen($1)+3)*sizeof(char));
                                    strcpy($$,$1);strcat($$," ");free($1);};

Statement	:	LCPARAN StatementStar RCPARAN                                       {$$=(char*)malloc((strlen($2)+10)*sizeof(char));
                                                                                    strcpy($$,"{");strcat($$,$2);strcat($$,"}");free($2);}
                                                                                    
                |	SYSTEM LPARAN Expression RPARAN SEMICOLON                       {$$=(char*)malloc((strlen($3)+30)*sizeof(char));
                                                                                    strcpy($$,"System.out.println(");strcat($$,$3);strcat($$,");");free($3);}
                                                                                    
                |	Identifier EQUALS Expression SEMICOLON                          {$$=(char*)malloc((strlen($1)+strlen($3)+10)*sizeof(char));
                                                                                    strcpy($$,$1);strcat($$,"=");strcat($$,$3);strcat($$,";");free($1);free($3);}
                                                                                    
                |	Identifier LSPARAN Expression RSPARAN EQUALS Expression SEMICOLON   {$$=(char*)malloc((strlen($1)+strlen($3)+strlen($6)+10)*sizeof(char));
                                                                                           strcpy($$,$1);strcat($$,"[");strcat($$,$3);strcat($$,"]=");
                                                                                           strcat($$,$6);strcat($$,";");
                                                                                           free($1);free($3);free($6);} 
                                                                                           
                |	IF LPARAN Expression RPARAN Statement                               {$$=(char*)malloc((strlen($3)+strlen($5)+15)*sizeof(char));
                                                                                        strcpy($$,"if");strcat($$,"(");strcat($$,$3);strcat($$,")");strcat($$,$5);
                                                                                        free($3);free($5);} 
                                                                                                                             
                |	IF LPARAN Expression RPARAN Statement ELSE Statement                {$$=(char*)malloc((strlen($3)+strlen($5)+strlen($7)+15)*sizeof(char));
                                                                                           strcpy($$,"if(");strcat($$,$3);strcat($$,")");strcat($$,$5);
                                                                                           strcat($$,"else ");strcat($$,$7);
                                                                                           free($3);free($5);free($7);}
                                                                                           
                |	WHILE LPARAN Expression RPARAN Statement                            {$$=(char*)malloc((strlen($3)+strlen($5)+15)*sizeof(char));
                                                                                        strcpy($$,"while(");strcat($$,$3);strcat($$,")");strcat($$,$5);
                                                                                        free($3);free($5);} 
                                                                                        
                |	MacroStatement                                                      {$$=$1;};
                
MacroStatement :    Identifier LPARAN RPARAN SEMICOLON                                     { $$=substitute($1,NULL,1);
                                                                                            free($1);} 
                                                                                        
                    | Identifier LPARAN Expression CommaExpressionStar RPARAN SEMICOLON   {char* temp=(char*)malloc((strlen($3)+strlen($4)+10)*sizeof(char));
                                                                                            strcpy(temp,$3);strcat(temp,$4);
                                                                                            $$=substitute($1,temp,1);
                                                                                            free($1);free($3);free($4);};
                                                                                
Expression	:	PrimaryExpression AND PrimaryExpression       {$$=(char*)malloc((strlen($1)+strlen($3)+10)*sizeof(char));
                                                                strcpy($$,$1);strcat($$,"&");strcat($$,$3);free($1);free($3);}                       
                
                |	PrimaryExpression LESSTHAN PrimaryExpression  {$$=(char*)malloc((strlen($1)+strlen($3)+10)*sizeof(char));
                                                                strcpy($$,$1);strcat($$,"<");strcat($$,$3);free($1);free($3);}                      
                
                |	PrimaryExpression PLUS PrimaryExpression    {$$=(char*)malloc((strlen($1)+strlen($3)+10)*sizeof(char));
                                                                strcpy($$,$1);strcat($$,"+");strcat($$,$3);free($1);free($3);}                                                 
                
                |	PrimaryExpression MINUS PrimaryExpression   {$$=(char*)malloc((strlen($1)+strlen($3)+10)*sizeof(char));
                                                                strcpy($$,$1);strcat($$,"-");strcat($$,$3);free($1);free($3);}                                             
                
                |	PrimaryExpression STAR PrimaryExpression     {$$=(char*)malloc((strlen($1)+strlen($3)+10)*sizeof(char));
                                                                strcpy($$,$1);strcat($$,"*");strcat($$,$3);free($1);free($3);}                                            
                
                |	PrimaryExpression DIV PrimaryExpression         {$$=(char*)malloc((strlen($1)+strlen($3)+10)*sizeof(char));
                                                                    strcpy($$,$1);strcat($$,"/");strcat($$,$3);free($1);free($3);}                                               
                
                |	PrimaryExpression LSPARAN PrimaryExpression RSPARAN  {$$=(char*)malloc((strlen($1)+strlen($3)+10)*sizeof(char));
                                                                            strcpy($$,$1);strcat($$,"[");strcat($$,$3);strcat($$,"]");free($1);free($3);}                                     
                
                |	PrimaryExpression LENGTH                        {$$=(char*)malloc((strlen($1)+10)*sizeof(char));
                                                                    strcpy($$,$1);strcat($$,".length");free($1);}                                                             
                
                |	PrimaryExpression                               {$$=(char*)malloc((strlen($1)+10)*sizeof(char));
                                                                    strcpy($$,$1);free($1);}                                              
               
                |	PrimaryExpression DOT Identifier LPARAN Expression CommaExpressionStar RPARAN {$$=(char*)malloc((strlen($1)+strlen($3)+strlen($5)+strlen($6)+15)*sizeof(char));
                                                                                                    strcpy($$,$1);strcat($$,".");strcat($$,$3);strcat($$,"(");
                                                                                                    strcat($$,$5);strcat($$,$6);strcat($$,")");free($1);free($3);free($5);free($6);}   
                
                |   PrimaryExpression DOT Identifier LPARAN RPARAN        {$$=(char*)malloc((strlen($1)+strlen($3)+10)*sizeof(char));
                                                                            strcpy($$,$1);strcat($$,".");strcat($$,$3);strcat($$,"()");
                                                                            free($1);free($3);}                             
               
                |	MacroExpression                                     
                            {$$=$1;}  ;
                
                
MacroExpression: Identifier LPARAN Expression CommaExpressionStar RPARAN        {char* temp=(char*)malloc((strlen($3)+strlen($4)+10)*sizeof(char));
                                                                                strcpy(temp,$3);strcat(temp,$4);
                                                                                $$=substitute($1,temp,0);
                                                                                free($1);free($3);free($4);}
                                                                                
                 |    Identifier LPARAN RPARAN                                  { $$=substitute($1,NULL,0);
                                                                                free($1);};
                                                                                
PrimaryExpression	:	        INT                                             {$$=(char*)malloc((strlen($1)+5)*sizeof(char));strcpy($$,$1);}

                            |	TRUE                                            {$$=(char*)malloc(10*sizeof(char));strcpy($$,"true");}
                           
                            |	FALSE                                           {$$=(char*)malloc(10*sizeof(char));strcpy($$,"false");}
                           
                            |	Identifier                                      {$$=$1;}
                            
                            |	THIS                                            {$$=(char*)malloc(10*sizeof(char));strcpy($$,"this");}
                            
                            |	NEW WORDINT LSPARAN Expression RSPARAN          {$$=(char*)malloc((strlen($4)+20)*sizeof(char));
                                                                                strcpy($$,"new ");strcat($$,"int [");strcat($$,$4);
                                                                                strcat($$,"]");free($4);}
                            
                            |	NEW Identifier LPARAN RPARAN                    {$$=(char*)malloc((strlen($2)+20)*sizeof(char));
                                                                                strcpy($$,"new ");strcat($$,$2);strcat($$,"()"); 
                                                                                free($2);}
                            
                            |	NOT Expression                                  {$$=(char*)malloc((strlen($2)+20)*sizeof(char));
                                                                                strcpy($$,"!");strcat($$,$2);free($2);}
                            
                            |	LPARAN Expression RPARAN                        {$$=(char*)malloc((strlen($2)+20)*sizeof(char));
                                                                                strcpy($$,"(");strcat($$,$2);strcat($$,")");free($2);}  ;
MacroDefinition	:	MacroDefExpression     
                    |	MacroDefStatement   ;
                    
MacroDefStatement	:	DEFINE Identifier LPARAN Identifier CommaIdentifierStar RPARAN LCPARAN  StatementStar RCPARAN 
                            {   char* temp=(char*)malloc((strlen($4)+strlen($5)+3)*sizeof(char));strcpy(temp,$4);strcat(temp,$5);
                                char* temp2=(char*)malloc((strlen($8)+5)*sizeof(char));strcpy(temp2,"{");strcat(temp2,$8);strcat(temp2,"}");
                                insertMacro($2,temp,temp2,1);free($4);free($5);free($8);
                            } 
                        |  DEFINE Identifier LPARAN RPARAN LCPARAN  StatementStar RCPARAN  
                                {char* temp2=(char*)malloc((strlen($6)+5)*sizeof(char));strcpy(temp2,"{");strcat(temp2,$6);strcat(temp2,"}");
                                insertMacro($2,NULL,temp2,1);free($6);};
                                
MacroDefExpression	:   DEFINE Identifier LPARAN Identifier CommaIdentifierStar RPARAN LPARAN Expression RPARAN
                        {   char* temp=(char*)malloc((strlen($4)+strlen($5)+3)*sizeof(char));strcpy(temp,$4);strcat(temp,$5);
                                char* temp2=(char*)malloc((strlen($8)+5)*sizeof(char));strcpy(temp2,"(");strcat(temp2,$8);strcat(temp2,")");
                                insertMacro($2,temp,temp2,0);free($4);free($5);free($8);
                            } 
                        | DEFINE Identifier LPARAN  RPARAN LPARAN Expression RPARAN
                            {char* temp2=(char*)malloc((strlen($6)+5)*sizeof(char));strcpy(temp2,"(");strcat(temp2,$6);strcat(temp2,")");
                                insertMacro($2,NULL,temp2,0);free($6);};

Identifier	:	IDENTIFIER                                                      {$$=(char*)malloc((strlen($1)+5)*sizeof(char));strcpy($$,$1);};

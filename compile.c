#include <stdio.h>
#include <string.h>
int t_letter = 0;
int t_or = 0;
int t_and = 1;
int t_xor = 2;
int t_nor = 3;
int t_nand = 4;
int t_not = 5;
int t_lparen = 6;
int t_rparen = 7;

int binaryOperatorsNum = 3;



typedef struct node {
	int type ;
	struct node * left;
	struct ndoe * right;

}node;

typedef struct operator {
	char  symbol[5] ; 
	int binary;
}operator;

void insert( node ** item, int type){


}

char *strtok_r(char *str, const char *delim, char **save){

	char *res, *last;
	if( !save)
		return strtok(str,delim);

	if(!str && !(str=*save)){
		return NULL;
	}
	last = str + strlen(str);
	if( (*save = res = strtok(str,delim)) ){

		*save += strlen(res);
		if( *save < last ){
			(*save)++;
		}else{
			*save = NULL;
		}
	}
	return res;
}	

int charType(char c);

int strLen( char * str){
	int i = 0;

	char * ptr;
	ptr = str;
	while(*ptr != '\0'){
		i++;
		ptr++;
	}

	return i;

}

int parseString(char * line){
	//printf("In: %s\n",line);	
	
	char * token; 
	
	operator binaryOperators[binaryOperatorsNum];
	strcpy(typeArray[0].symbol,"&&");
	typeArray[0].binary = 1;

	strcpy(typeArray[1].symbol, "||");
	typeArray[1].binary = 1;

	strcpy(typeArray[2].symbol,"^");
	typeArray[2].binary = 1;
	
	int inputLen = strLen(line);
	char * saveptr;

	for(int i = 0; i < binaryOperatorsNum  ; i ++){
		
		char * operator = binaryOperators[i].symbol;
		token = strtok_r(line,operator,&saveptr);
		
		//Check if token was split
		if(strLen(token) == inputLen ) continue;
		
		if(token != NULL){
			
			if(!parseString(token))return 0;
			
			token = strtok_r(NULL,operator,&saveptr);
			
			return parseString(token);	
		}

	}



	char * ptr ;
	ptr = line;
	if ( strLen(line) == 1){
		if ( charType(*line) == t_letter){
			return 1;
		}
	}

	if(*ptr == '~'){
		ptr++;
		return parseString(ptr);
	}
	
	return 0;

	
	

}

int charType(char c){

	if( c > 96 && c < 123){
		return t_letter;
	}
	return 0;
}

int main(){
	
	char str[10] = "b&&b||~c";
	

	printf("Result %d\n",parseString(str));
	
	
	return -1;

}

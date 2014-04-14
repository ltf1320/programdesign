#ifndef FIND_H_INCLUDED
#define FIND_H_INCLUDED


int find(char* filename,char *key)
{
    FILE *fp;
    unsigned int line=0,sum=0,linenum=0,wordnum=0;
    struct Result result;
    int resultmax=8,linemax=128,wordmax=64,line_end,i;
    char ch;
    char* word,*line_str;
    result.line=malloc(resultmax*sizeof(int));
	result.text=malloc(resultmax*sizeof(char*));
    if(!(fp=fopen(filename,"r")))
    {
        printf("open file error ,the programe will end.\n");
        return 0;
    }
    while(!feof(fp))
    {
        if(ferror(fp))
        {
            printf("read file error\n");
            return 0;
        }
        line_end=0;
        ++line;
        resultmax=8,linemax=64,wordmax=64;
        line_str=malloc(linemax*sizeof(char));
        word=malloc(wordmax*sizeof(char));
        linenum=wordnum=0;
        while((ch=fgetc(fp))!=EOF)
        {
            line_str[linenum++]=ch;
            if(linenum>=linemax-1)
            {
				linemax*=2;
                line_str=realloc(line_str,linemax*sizeof(char));
            }
            switch(ch)
            {
                case ' ':
                    word[wordnum]=0;
                    if(strcmp(word,key)==0)
                    {
                        sum++;
                        if(sum>=resultmax-1)
                        {
                            resultmax*=2;
                            result.line=realloc(result.line,resultmax*sizeof(int));
							result.text=realloc(result.text,resultmax*sizeof(char*));
                        }
                        result.line[sum-1]=line;
                        while((ch=fgetc(fp))!='\n')
                        {
                            line_str[linenum++]=ch;
							if(linenum>=linemax-1)
                            {
                                linemax*=2;
                                line_str=realloc(line_str,linemax*sizeof(char));
                            }
                        }
                        line_str[linenum]=0;
                        result.text[sum-1]=malloc(linemax*sizeof(char));
                        strcpy(result.text[sum-1],line_str);
						line_end=1;
                    }
                    else
					{
						free(word);
						word=malloc(wordmax*sizeof(char));
					}
					wordnum=0;
                    break;
                case '\n':
                    line_end=1;
                    word[wordnum]=0;
                    if(strcmp(word,key)==0)
                    {
                        sum++;
                        if(sum>=resultmax-1)
                        {
                            resultmax*=2;
                            result.line=realloc(result.line,resultmax*sizeof(int));
							result.text=realloc(result.text,resultmax*sizeof(char*));
                        }
                        result.line[sum-1]=line;
                        while((ch=fgetc(fp))!='\n')
                        {
                            ++linenum;
                            if(linenum>=linemax-1)
                            {
                                linemax*=2;
                                line_str=realloc(line_str,linemax*sizeof(char));
                            }
                            line_str[linenum]=ch;
                        }
                        line_str[++linenum]=0;
                        result.text[sum-1]=malloc(linemax*sizeof(char));
                        strcpy(result.text[sum-1],line_str);
                    }
                    break;
                default:
                    word[wordnum++]=ch;
                    break;
            }
            if(line_end)
            {
				free(word);
                free(line_str);
                break;
            }
        }
    }
    printf("%s occurs %d time(s)\n",key,sum);
    for(i=0;i<sum;i++)
    {
        printf("(line:%d)%s\n",result.line[i],result.text[i]);
    }
    return 1;
}


#endif // FIND_H_INCLUDED

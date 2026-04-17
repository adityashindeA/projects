///////////////////////////////////////////////////////////
///
/// Header File Inclusion
///
///////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>
///////////////////////////////////////////////////////////
///
/// User Defined Macro's
///
///////////////////////////////////////////////////////////
///Maximum File Size We Allow in Project(No of bytes)
#define MAXFILESIZE 50
///Maximum OpenFiles We Allow in Project
#define MAXOPENFILES 20
///Maximum Inodes We Allow in Project
#define MAXINODE 5
/// Read macro
#define READ 1
/// write macro
#define WRITE 2
///execute macro
#define EXECUTE 4
///start macro
#define START 0
///current macro
#define CURRENT  1
///End macro
#define END 2
///defines file status(Sucessfull:0)
#define EXECUTE_SUCESS 0
//defines that file type is Regular file(.txt file(mostly text file))
#define REGULARFILE 1
//defines that file type is specialtype(ex=directory file,.jpg,.mp4,.zip  etc.)
#define SPECIALFILE 2

///////////////////////////////////////////////////////////
///
/// User Defined Macro's for error handeling
///
///////////////////////////////////////////////////////////

//if Parameters Are Invalid Or less
#define ERR_INVALID_PARAMETER -1
//All Inodes Are in use
#define ERR_NO_INODES -2

//if file already exist
#define ERR_FILE_ALREADY_EXIST -3
//if file is not present
#define ERR_FILE_NOT_EXIST -4

//if permission not allowed
#define ERR_PERMISSION_DENIDED -5

//if space
#define ERR_INSUFFICIENTSPACE -6
//
#define ERR_INSUFFICIENTDATA -7
//Limit of maximum opening file is reached
#define ERR_MAX_FILES_OPEN -8


///////////////////////////////////////////////////////////
///
/// User Defined Structures
///
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
///
/// Strcture Name:Boot Block
/// Description: Holds Information To Boot Os
///
///////////////////////////////////////////////////////////
struct BootBlock
{
    char Information[100];    //Bootblock info about booting
};

///////////////////////////////////////////////////////////
///
/// Strcture Name:Super Block
/// Description: Holds Information About File System
///
///////////////////////////////////////////////////////////
struct SuperBlock
{
    int TotalInodes;//inforamtion about total no of Inodes
    int FreeInodes;// information about total no of free Inodes
};

///////////////////////////////////////////////////////////
///
/// Strcture Name:Inode
/// Description: Holds Information About File(Metadata)
///
///////////////////////////////////////////////////////////

#pragma pack(1)
struct Inode
{
    char FileName[20];
    char * Buffer;
    int InodeNumber;
    int FileSize;
    int FileType;
    int ActualFileSize;
    int Permission;//0777
     int ReferanceCount;
    struct Inode * next;
};
typedef struct Inode INODE;
typedef struct Inode * PINODE;
typedef struct Inode ** PPINODE;
///////////////////////////////////////////////////////////
///
/// Strcture Name:File Table
/// Description: Holds Information About Opened File
///
///////////////////////////////////////////////////////////
struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Mode;
    PINODE ptrinode;

};

typedef FileTable FILETABLE;
typedef FileTable * PFILETABLE;

///////////////////////////////////////////////////////////
///
/// Strcture Name:UAREA
/// Description: Holds Information About Process File
///
///////////////////////////////////////////////////////////
struct  UAREA
{
    char ProcessName[20];
    PFILETABLE UFDT[MAXOPENFILES];
    
};

///////////////////////////////////////////////////////////
///
/// 
/// Global Variables Or Objects Used In Project
///
///////////////////////////////////////////////////////////

BootBlock bootobj;
SuperBlock superobj;
UAREA uareaobj;

PINODE head=NULL;
///////////////////////////////////////////////////////////
///  
/// Function Name: initializeUAREA()
/// Description: It is used To initialise UAREA Members
/// Author: Atharva Vasant Kandhare
/// Date: 13/01/2026
///////////////////////////////////////////////////////////
void initializeUAREA()
{
    int i=0;
    strcpy(uareaobj.ProcessName,"Myexe");
     for(i=0;i<MAXOPENFILES;i++)
     {
        uareaobj.UFDT[i]=NULL;
     }
  printf("Project CVFS:  UAREA Gets Initialized Sucessfully\n");
}

///////////////////////////////////////////////////////////
///  
/// Function Name: initializeSuperBlock()
/// Description: it is Used To initialize Super Block Members
/// Author: Atharva Vasant Kandhare
/// Date: 13/01/2026
///////////////////////////////////////////////////////////
void initializeSuperBlock()
{
    superobj.TotalInodes=MAXINODE;
    superobj.FreeInodes=MAXINODE;
   printf("Project CVFS: Super Block Gets Initialized Sucessfully\n");
}

///////////////////////////////////////////////////////////
///  
/// Function Name: createDILB()
/// Description: it is Used To create Linked List Of Inodes
/// Author: Atharva Vasant Kandhare
/// Date: 13/01/2026
///////////////////////////////////////////////////////////
void createDILB()
{
    int i=0;
    PINODE newn=NULL;
    PINODE temp =head;
    for(i=1;i<=MAXINODE;i++)
    {
        newn =(PINODE)malloc(sizeof(INODE));

           strcpy(newn->FileName,"\0");
           newn->Buffer=NULL;
           newn->InodeNumber=i;
           newn->FileSize=0;
           newn->FileType=0;
           newn->ActualFileSize=0;
           newn->Permission=0;
           newn->ReferanceCount=0;
           newn->next=NULL; 
                       
    if(temp==NULL)
    {
        head=newn;
        temp=head;          //LL is empty

    }
    else
    {
        temp->next=newn;
        temp=temp->next;    //LL contains One Node
                              
    }
}

    printf("Project CVFS: DILB Created Sucessfully\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////
///  
/// Function Name: startAuxillaryDataInitialisation()
/// Description: It is Used to call all such Functions which are used To Initialize Auxillary Data
/// Author: Atharva Vasant Kandhare
/// Date: 13/01/2026
///////////////////////////////////////////////////////////////////////////////////////////////////
void startAuxillaryDataInitialisation()
{
    strcpy(bootobj.Information,"....Booting Process Of Project CVFS Is Sucessfull....\n");
    printf("%s\n",bootobj.Information);
    initializeSuperBlock();
    createDILB();
    initializeUAREA();
    printf("Project CVFS : Auxillary Data Initialized Sucessfully\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////
///  
/// Function Name: displayHelp()
/// Description: It is Used to Display Help page
/// Author: Atharva Vasant Kandhare
/// Date: 14/01/2026
///////////////////////////////////////////////////////////////////////////////////////////////////
void displayHelp()
{
    printf("-------------------------------------------------------\n");
    printf("--------------Project CVFS : HELP PAGE------------------\n");
    printf("-------------------------------------------------------\n");
    printf("man : It used to display manual page.\n");
    printf("cd : used to change working directory.");
    printf("clear : It used to clear terminal.\n");
    printf("uname: it is used to display information about System\n");
    printf("creat : It used to create new file.\n");
    printf("write : It used to write data into file.\n");
    printf("read : It used to read data from file.\n");
    printf("echo : Used to display Text in terminal\n");
    printf("stat : It used to display Statistical information.\n");
    printf("unlink : It used to delete the file.\n");
    printf("mkdir : It is used to make An Directory");
    printf("EXIT : it is used to  terminate Project CVFS.\n");

    printf("-------------------------------------------------------\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////
///  
/// Function Name: manPageDisplay()
/// Description: It is Used to Display man page which provides information.
/// Author: Atharva Vasant Kandhare
/// Date: 14/01/2026
///////////////////////////////////////////////////////////////////////////////////////////////////
void manPageDisplay(char Name[])
{
    if(strcmp("ls",Name)==0)
    {
        printf("About : it is used to list names of all files\n");
        printf("Usage : ls \n");
    }
    else if(strcmp("man",Name)==0)
   {
      printf("About : it is used to display manual page.\n");
        printf("Usage : man command_name  \n");
        printf("command_name : it is name of command\n");

   }
   else if(strcmp("EXIT",Name)==0)
   {
      printf("About : it is used to terminate shell.\n");
        printf("Usage : EXIT \n");
        
   }
   else if(strcmp("cd",Name)==0)
   {
     printf("About : it is change your working directory.\n");
        printf("Usage : cd Directory_Name \n");
        printf("Directory_Name : your directory name\n");
   }
   else if(strcmp("mkdir",Name)==0)
   {
     printf("About : for making new directory.\n");
        printf("Usage : mkdir Directory_Name \n");
        printf("Directory_Name : your directory name\n");

   }
   else if(strcmp("stat",Name)==0)
   {
    
     printf("About : to display statistics about your files/file systems.\n");
        printf("Usage : stat file_name \n");
        printf("file_name : your file name\n");

   }
   else if(strcmp("clear",Name)==0)
   {
      printf("About : Used To Clear shell.\n");
        printf("Usage : clear \n");

   }
   else if(strcmp("echo",Name)==0)
   {
    printf("About :  used to display text on shell.\n");
    printf("Usage : echo \"text\" \n");
   }
   else if(strcmp("uname",Name)==0)
   {
    printf("About:Used to display Information About System\n");
    printf("usage:uname\n");
   }
   else if(strcmp("creat",Name)==0)
   {
    printf("About : Used to create a file\n");
    printf("Usage : creat file_name\n");
   }
   else if(strcmp("unlink",Name)==0)
   {
    printf("About : Used to delete file\n");
    printf("Usage : unlink file_name\n");
  }
  else if(strcmp("write",Name)==0)
   {
    printf("About : Used to write something into the file\n");
    printf("Usage : unlink Fd  str(buffer)  No_of_bytes\n");
    printf("Fd: file descripter\n");
    printf("str(buffer): String/Buffer from  which we want to write in file\n");
    printf("No_of_bytes : no of bytes which we want to write\n");

   }
    else if(strcmp("read",Name)==0)
   {
    printf("About : Used to read data from file\n");
    printf("Usage : read Fd  (buffer)_str  No_Of_bytes\n");
    printf("Fd: file descripter\n");
    printf(" (Buffer)/str : String or buffer where we can store and red data from file\n");
    printf("No_of_bytes : no of bytes which we want to read\n");

   }

   else
   {
    printf("No manual entry for %s\n",Name);

   }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///  
/// Function Name: isFileExist()
/// Description: It is Used to check file exists or not exists
/// Input: It accepts File name 
/// Output:It returns true or false
/// Author: Atharva Vasant Kandhare
/// Date: 16/01/2026
///////////////////////////////////////////////////////////////////////////////////////////////////
bool isFileExist(
                 char * Name // file name
                )
{
    PINODE temp=NULL;
    temp= head;
    bool bFlag=false;
    while(temp!=NULL)
    {
        if((strcmp(Name,temp->FileName)==0) && (temp->FileType==REGULARFILE)) //check file exist or not by checking type and name of file
        {
            bFlag=true;
            break;

        }
        temp=temp->next;
    }
    return bFlag;

}

///////////////////////////////////////////////////////////////////////////////////////////////////
///  
/// Function Name: LsFile()
/// Description: It is Used to List All files
/// Input: Nothing
/// Output:Nothing
/// Author: Atharva Vasant Kandhare
/// Date: 16/01/2026
///////////////////////////////////////////////////////////////////////////////////////////////////
  void LsFile()//ls -l
 {
    PINODE temp = NULL;
    temp = head;
    printf("----------------------------------------------\n");
    printf("----Project CVFS :--- Files Information: ------\n");
    printf("----------------------------------------------\n");
    while ((temp!=NULL))
    {
        if(temp->FileType!=0)
        {
        printf("%d\t%s\t%d\n",temp->InodeNumber,temp->FileName,temp->ActualFileSize);
        }
       temp=temp->next;
    }
     printf("----------------------------------------------\n");
    
}





///////////////////////////////////////////////////////////////////////////////////////////////////
///  
/// Function Name: createFile()
/// Description: It is Used to Create New Regular File
/// Input: It accepts File name and permissions
/// Output:It returns File Descriptors
/// Author: Atharva Vasant Kandhare
/// Date: 16/01/2026
///////////////////////////////////////////////////////////////////////////////////////////////////
 int createFile(
                 char * Name,  // Name of New File
                 int Permission  //Permission For that File
                )
{
    PINODE temp =NULL;
    temp = head;
    int i=0;
    printf("Total No Of Inodes Remaining:%d\n",superobj.FreeInodes);
    //If Name is Missing
    if(Name==NULL)
    {
        return ERR_INVALID_PARAMETER;
    }
    //if permission value is wrong
    //permission = 1(read)
    //permission = 2(write)
    //permission = 3(read + write)
    if(Permission<1||Permission>3)
    {
        return ERR_INVALID_PARAMETER;
    }
     //if the Inodes are Full
    if(superobj.FreeInodes==0)
    {
        return ERR_NO_INODES;
    }
     // if file is already present
    if(isFileExist(Name)==true)
    {
        return ERR_FILE_ALREADY_EXIST;

    }
    //search for empty Inode
    while(temp!=NULL)
    {
        if(temp->FileType==0)
        {
              break;
        }
        temp=temp->next;
    }

    if(temp==NULL)
    {
        printf("There is No Inode\n");
        return ERR_NO_INODES;
    }
// search for empty UFDT entry
//Note : 0 1 2(index are reserved)
for(i=3;i<MAXFILESIZE;i++)
{
    if(uareaobj.UFDT[i]==NULL)
    {
        break;
    }

}
//UFDT is Full
if(i==MAXOPENFILES)
{
    return ERR_MAX_FILES_OPEN;
}

//Allocate Memory for file table
uareaobj.UFDT[i]=(PFILETABLE)malloc(sizeof(FILETABLE));

//initialize file table
//here uareaobj.UFDT[i] is acts like pointer which points to memory address of filetable

uareaobj.UFDT[i]->ReadOffset=0;
uareaobj.UFDT[i]->WriteOffset=0;
uareaobj.UFDT[i]->Mode = Permission;

//connect filetable with Inode
uareaobj.UFDT[i]->ptrinode=temp;

//initialise elements of inode
strcpy(uareaobj.UFDT[i]->ptrinode->FileName,Name);
uareaobj.UFDT[i]->ptrinode->FileSize=MAXFILESIZE;
uareaobj.UFDT[i]->ptrinode->ActualFileSize =0;
uareaobj.UFDT[i]->ptrinode->FileType= REGULARFILE;
uareaobj.UFDT[i]->ptrinode->ReferanceCount= 1;
uareaobj.UFDT[i]->ptrinode->Permission= Permission;

//Allocate Memory for files data
uareaobj.UFDT[i]->ptrinode->Buffer=(char * )malloc(MAXFILESIZE);
superobj.FreeInodes--;
return i;//fd(file descriptor)
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///  
/// Function Name: unlinkFile()
/// Description: It is Used to Delete the File
/// Input: file name
/// Output: Nothing
/// Author: Atharva Vasant Kandhare
/// Date: 22/01/2026
///////////////////////////////////////////////////////////////////////////////////////////////////
int unlinkFile(
           char * Name
             )
{
    int i=0;
    if(Name==NULL)
    {
        return ERR_INVALID_PARAMETER;
    }
    if(isFileExist(Name)==false)
    {
        return ERR_FILE_NOT_EXIST;
    }
    for(i=0;i<MAXOPENFILES;i++)//Traveling UFDT array
    {
        if(uareaobj.UFDT[i]!=NULL)
        {
            if(strcmp(uareaobj.UFDT[i]->ptrinode->FileName,Name)==0)
            {
                //deallocating memory of Buffer
                free(uareaobj.UFDT[i]->ptrinode->Buffer);
                uareaobj.UFDT[i]->ptrinode->Buffer=NULL;//reset all values of inode
                                                        // dont deallocate memeory of inode
               uareaobj.UFDT[i]->ptrinode->FileSize=0;
                uareaobj.UFDT[i]->ptrinode->ActualFileSize=0;
                 uareaobj.UFDT[i]->ptrinode->FileType=0;
                  uareaobj.UFDT[i]->ptrinode->ReferanceCount=0;
                   uareaobj.UFDT[i]->ptrinode->Permission=0;
                    memset( uareaobj.UFDT[i]->ptrinode->FileName,'\0',sizeof( uareaobj.UFDT[i]->ptrinode->FileName ));      
                    //deallocating memory of File Table
                    free(uareaobj.UFDT[i]);
                    //setting NULL to UFDT
                    uareaobj.UFDT[i]=NULL;
                    //Incrementing FreeInodeCount
                    superobj.FreeInodes++;
                    break;//very IMP                                        
            }//end of if

        }//end of if

    }//end of for loop

    return EXECUTE_SUCESS;
}//  end of unlinkFile() Function

///////////////////////////////////////////////////////////////////////////////////////////////////
///  
/// Function Name: writeFile()
/// Description: It is Used write data into the file
/// Input: FD(file descripter),Address of Buffer which contains data,Size of data that we want to write
/// Output: No of bytes Sucessfully written.
/// Author: Atharva Vasant Kandhare
/// Date: 22/01/2026
///////////////////////////////////////////////////////////////////////////////////////////////////
int writeFile(
           int Fd,
           char * Data,
           int size
            )
{
    printf("File Descripter:%d\n",Fd);
    printf("Data that we want to write:%s\n",Data);
    printf("No of Bytes That We want to write in file:%d\n",size);

    if(Fd<0||Fd>MAXOPENFILES)//Invalid Fd
    {
        return ERR_INVALID_PARAMETER;

    }
    if(uareaobj.UFDT[Fd]==NULL)//Fd points to NULL
    {
        return ERR_FILE_NOT_EXIST;
    }
    //there is no permission to write
    if(uareaobj.UFDT[Fd]->ptrinode->Permission<WRITE)
    {
           return ERR_PERMISSION_DENIDED;
    }
    //Insufficient Space
    if((MAXFILESIZE-uareaobj.UFDT[Fd]->WriteOffset)<size)
    {
        return ERR_INSUFFICIENTSPACE;
    }
    //writing data into the file
    strncpy(uareaobj.UFDT[Fd]->ptrinode->Buffer + uareaobj.UFDT[Fd]->WriteOffset,Data,size);
    
    //updating the the writeOffset
    uareaobj.UFDT[Fd]->WriteOffset= uareaobj.UFDT[Fd]->WriteOffset + size;

    //update ActualfileSize
    uareaobj.UFDT[Fd]->ptrinode->ActualFileSize = uareaobj.UFDT[Fd]->ptrinode->ActualFileSize + size;

    return size;

}

///////////////////////////////////////////////////////////////////////////////////////////////////
///  
/// Function Name: readFile()
/// Description: It is Used to read data from file
/// Input: FD(file descripter),Address of empty Buffer,Size of data that we want to read
/// Output: No of bytes Sucessfully Readed
/// Author: Atharva Vasant Kandhare
/// Date: 22/01/2026
///////////////////////////////////////////////////////////////////////////////////////////////////
int readFile(
           int Fd,
           char * Data,
           int size

             )
{
    if(Fd<0||Fd>MAXOPENFILES)//Invalid Fd
    {
        return ERR_INVALID_PARAMETER;

    }
    if(Data==NULL)//Data not given
    {
        return ERR_INVALID_PARAMETER;
    }
    if(size<=0)// size is invalid
    {
        return ERR_INVALID_PARAMETER;
    }
    if(uareaobj.UFDT[Fd]==NULL)
    {
        return ERR_FILE_NOT_EXIST;
    }
    //filer for permission
    if(uareaobj.UFDT[Fd]->ptrinode->Permission<READ)
    {
        return ERR_PERMISSION_DENIDED;
    }
    //Insufficient Data
    if((MAXFILESIZE-uareaobj.UFDT[Fd]->ReadOffset)<size)
    {
        return ERR_INSUFFICIENTDATA;
    }
  

    //reading the data
    strncpy(Data,uareaobj.UFDT[Fd]->ptrinode->Buffer + uareaobj.UFDT[Fd]->ReadOffset,size);

    //updating read offset
    uareaobj.UFDT[Fd]->ReadOffset= uareaobj.UFDT[Fd]->ReadOffset + size;
      

    return size;
    

}
///////////////////////////////////////////////////////////////////////////////////////////////////
///  
/// Function Name: DisplayStat()
/// Description: It is Used to Display Statistical info about file
/// Input: file name
/// Output:It returns File Descriptors
/// Author: Atharva Vasant Kandhare
/// Date: 26/01/2026
///////////////////////////////////////////////////////////////////////////////////////////////////
void DisplayStat(
         char * Name
              )
 {
    

    PINODE temp=NULL;
    temp=head;

    while(temp!=NULL)
    {
        if(strcmp(temp->FileName,Name)==0)
        {
            printf("File Name:%s\n Inode No : %d\nActual Size : %d\nPermissions:%d\n",temp->FileName,temp->InodeNumber,temp->ActualFileSize,temp->Permission);
            if(temp->FileType==REGULARFILE)
            {
               printf("File Type:REGULAR\n");
            }
            if(temp->FileType==SPECIALFILE)
            {
                 printf("File Type:SPECIAL\n");
            }
            break;
        }
        temp=temp->next;
    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////
///  
/// Function Name: SysInfo()
/// Description: It is Used to Display Information about Os/file details
/// Input: Nothing
/// Output:print information
/// Author: Atharva Vasant Kandhare
/// Date: 09/02/2026
///////////////////////////////////////////////////////////////////////////////////////////////////
void SysInfo()
{
    printf("System info:\n");
    printf("Ubuntu Linux 24.04 version\n");
    printf("Total INodes Present:%d\n",superobj.TotalInodes);
    printf("Total Remaining Free Inodes:%d\n",superobj.FreeInodes);

}


         





///////////////////////////////////////////////////////////
///
/// Entry Point Function Of Project
///
///////////////////////////////////////////////////////////
int main()
{
    char str[80]={'\0'};
    char input[80]={'\0'};
    char command[6][20]={{'\0'}};
    char InputBuffer[MAXFILESIZE]={'\0'};
     char echostr[80]={'\0'};
    char * EmptyBuffer=NULL;
    int iRet=0;
    int iCount=0;

    startAuxillaryDataInitialisation();
    printf("----------------------------------------------\n");
    printf("----Project CVFS : ...Started SucessFully.------\n");
    printf("----------------------------------------------\n");
    //infinite Listening shell
    while(1)
    {
        fflush(stdin);//for clearing buffer
        strcpy(str,"");
        printf("\n Project CVFS : > ");
        fgets(str,sizeof(str),stdin);  //unformated
        iCount=sscanf(str,"%s %s %s %s %s",command[0],command[1],command[2],command[3],command[4],command[5]);//tokenisation of string
      
        fflush(stdin);
        if(iCount==1)
        {
            //Project CVFS : > EXIT
            if(strcmp("EXIT",command[0])==0)
            {
                printf("\nThank You For Using Project CVFS..\n");
                printf("Deallocating all the resources.\n");
                break;
            }
            //Project CVFS : > ls
            else if(strcmp("ls",command[0])==0)
            {
                LsFile();

            }
            //Project CVFS : > clear
            else if(strcmp("clear",command[0])==0)
            {
                        #ifdef _WIN32
                           system("cls");
                        #else
                            system("clear");
                        #endif
                    
            }
            //Project CVFS : > help
            else if(strcmp("help",command[0])==0)
            {
                displayHelp();
            }
             //Project CVFS :> echo "Hello"
             else if(strcmp("echo",command[0])==0)
             {
                printf("Enter String :");
                fgets(echostr, sizeof(echostr), stdin); // Reads the whole line including spaces
                 printf("%s\n", echostr);
             }
             //Project CvFS:> uname 
             else if(strcmp("uname",command[0])==0)
             {
                SysInfo();
             }
            else
            {
                printf("There is no such command\n");
            }
        }//end of else if 1

        //Project CVFS : > man ls
        else if(iCount==2)
    {   
        
        if(strcmp("man",command[0])==0)
        {
            manPageDisplay(command[1]);
        }
        //Project CVFS : > unlink demo.txt
        else if(strcmp("unlink",command[0])==0)
        {
            iRet=unlinkFile(command[1]);
            if(iRet==ERR_INVALID_PARAMETER)
            {
                printf("Invalid parameter\n");
            }
             if(iRet==ERR_FILE_NOT_EXIST)
            {
                printf("unable to delete as there is no such file\n");
            }
             if(iRet==EXECUTE_SUCESS)
            {
                    printf("File gets Sucessfully Deleted\n");
            }
        }
        //Project CVFS :> stat Demo.txt
        else if(strcasecmp("stat",command[0])==0)
        {
               DisplayStat(command[1]);
        } 
            //project CVFS:> write 3  Hello
           else if(strcmp("write",command[0])==0)
            {
                printf("Enter data that you want to write:\n");
                 fgets(InputBuffer,MAXFILESIZE,stdin);
                 iRet=writeFile(atoi(command[1]),InputBuffer,strlen(InputBuffer)-1);
                 if(iRet==ERR_INVALID_PARAMETER)
                 {
                    printf("ERROR : Invalid parameters\n");
                 }
                  else if(iRet==ERR_FILE_NOT_EXIST)
                 {
                    printf("ERROR : There is No such File present\n");
                 }
                  else if(iRet==ERR_PERMISSION_DENIDED)
                 {
                    printf("ERROR : Unable to write into file (no permission)\n");
                 }
                  else if(iRet==ERR_INSUFFICIENTSPACE)
                 {
                    printf("ERROR : unable to write in file there is no space Available \n");
                 }
                 else
                 {
                     printf("%d Bytes Are Sucessfully Written\n",iRet);
                 
                 }
                
            }

        }//end of else if 2

        //Project CVFS : > creat Ganesh.txt 3
        else if(iCount==3)
        {
            //
            if(strcmp("creat",command[0])==0)
            {
                iRet = createFile(command[1],atoi(command[2]));

                if(iRet==ERR_INVALID_PARAMETER)
                {
                    printf("ERROR : Unable to create File as parameters are Invalid\n");
                    printf("Please Refer man page\n");
                }

                if(iRet==ERR_NO_INODES)
                {
                     printf("ERROR : Unable to create file as there is no Inode\n");
                    
                }

                if(iRet==ERR_FILE_ALREADY_EXIST)
                {
                     printf("ERROR : Unable to create file as file is already present\n");
                }
                 if(iRet==ERR_MAX_FILES_OPEN)
                {
                    printf("ERROR : Unable to create file\n");
                    printf("Max opened  files limit is reached\n");
                }
                if(command[0][1]=='\n'||command[0][2]=='\n')
                {
                    printf("There is No such command\n");
                }
               printf("file gets sucesfully created  with Fd :%d\n",iRet);
                }

            //Project CVFS:> read 3 10
            if(strcmp("read",command[0])==0)
            {
                EmptyBuffer=(char *)malloc(sizeof(atoi(command[2])));
                iRet=readFile(atoi(command[1]),EmptyBuffer,atoi(command[2]));
                if(iRet==ERR_INVALID_PARAMETER)
                { 
                    printf("ERROR : Invalid parameter\n"); 

                }
                 else if(iRet==ERR_FILE_NOT_EXIST)
                {
                      printf("ERROR : File Not Exist\n");
                }
                else if(iRet==ERR_PERMISSION_DENIDED)
                {
                      printf("ERROR : Permission Denied\n");
                }
                else if(iRet==ERR_INSUFFICIENTDATA)
                {
                      printf("ERROR : Insufficient Data\n");
                }
                else 
                {
                    printf("Read Operation is Sucessfull\n");
                    printf("Data From File:%s\n",EmptyBuffer);

                    free(EmptyBuffer);
                }
            }
            else
            {
                printf("There is no such command\n");
            }

        }//end of else if 3
        else if(iCount==4)
        {

        }//end of else if 4
        else
        {
            printf("Command Not Found\n");
            printf("Please Refer help option to get More Information\n");//end of else
        }

        


    }//end of while

    return 0;
}//end of main